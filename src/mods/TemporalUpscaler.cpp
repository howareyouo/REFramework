#include <algorithm>
#include <cmath>
#include <utility>

#include <d3d12.h>
#include <wrl.h>

#include <utility/Module.hpp>
#include <PDPerfPlugin.h>

#include <sdk/Renderer.hpp>
#include <sdk/SceneManager.hpp>
#include <sdk/Memory.hpp>

#if TDB_VER >= 82
#include "sdk/regenny/re9/via/Window.hpp"
#include "sdk/regenny/re9/via/SceneView.hpp"
#elif TDB_VER <= 49
#include "sdk/regenny/re7/via/Window.hpp"
#include "sdk/regenny/re7/via/SceneView.hpp"
#elif TDB_VER < 69
#include "sdk/regenny/re3/via/Window.hpp"
#include "sdk/regenny/re3/via/SceneView.hpp"
#elif TDB_VER == 69
#include "sdk/regenny/re8/via/Window.hpp"
#include "sdk/regenny/re8/via/SceneView.hpp"
#elif TDB_VER == 70
#include "sdk/regenny/re2_tdb70/via/Window.hpp"
#include "sdk/regenny/re2_tdb70/via/SceneView.hpp"
#elif TDB_VER >= 71
#ifdef RE4
#include "sdk/regenny/re4/via/Window.hpp"
#include "sdk/regenny/re4/via/SceneView.hpp"
#elif defined(SF6)
#include "sdk/regenny/sf6/via/Window.hpp"
#include "sdk/regenny/sf6/via/SceneView.hpp"
#else
#include "sdk/regenny/re8/via/Window.hpp"
#include "sdk/regenny/re8/via/SceneView.hpp"
#endif
#endif

#include "TemporalUpscaler.hpp"

namespace {
// Engine reflection handles, resolved once, lazily.
//
// The lookups go through the engine's type database by string and are an order of
// magnitude more expensive than normal code, so they are resolved in exactly one place
// instead of being repeated as function-local statics in every callback.
struct Reflection {
    sdk::RETypeDefinition* renderer{};
    sdk::RETypeDefinition* render_config{};
    sdk::RETypeDefinition* camera{};

    sdk::REMethodDefinition* renderer_get_render_config{};
    sdk::REMethodDefinition* render_config_get_aa{};
    sdk::REMethodDefinition* render_config_set_aa{};
    sdk::REMethodDefinition* render_config_get_iqr{};
    sdk::REMethodDefinition* render_config_set_iqr{};
    sdk::REMethodDefinition* camera_get_near{};
    sdk::REMethodDefinition* camera_get_far{};
    sdk::REMethodDefinition* camera_get_projection{};

    ::REType* scene_layer_type{};
    ::REType* prepare_output_type{};
    ::REType* output_layer_type{};

    VariableDescriptor* scene_info_desc{};
    VariableDescriptor* depth_distortion_desc{};
    VariableDescriptor* filter_desc{};
    VariableDescriptor* z_prepass_desc{};
    VariableDescriptor* depth_stencil_desc{};
    VariableDescriptor* velocity_target_desc{};
};

const Reflection& reflection() {
    // Resolved on first use; function-local statics make this thread-safe.
    static const Reflection api = [] {
        Reflection api{};

        api.renderer = sdk::find_type_definition("via.render.Renderer");
        api.render_config = sdk::find_type_definition("via.render.RenderConfig");
        api.camera = sdk::find_type_definition("via.Camera");

        if (api.renderer != nullptr) {
            api.renderer_get_render_config = api.renderer->get_method("get_RenderConfig");
        }

        if (api.render_config != nullptr) {
            api.render_config_get_aa = api.render_config->get_method("get_AntiAliasing");
            api.render_config_set_aa = api.render_config->get_method("set_AntiAliasing");
            api.render_config_get_iqr = api.render_config->get_method("get_ImageQualityRate");
            api.render_config_set_iqr = api.render_config->get_method("set_ImageQualityRate");
        }

        if (api.camera != nullptr) {
            api.camera_get_near = api.camera->get_method("get_NearClipPlane");
            api.camera_get_far = api.camera->get_method("get_FarClipPlane");
            api.camera_get_projection = api.camera->get_method("get_ProjectionMatrix");
        }

        if (const auto scene_layer = sdk::find_type_definition("via.render.layer.Scene"); scene_layer != nullptr) {
            api.scene_layer_type = scene_layer->get_type();
            api.scene_info_desc = utility::re_type::get_field_desc(api.scene_layer_type, "SceneInfo");
            api.depth_distortion_desc = utility::re_type::get_field_desc(api.scene_layer_type, "DepthDistortionSceneInfo");
            api.filter_desc = utility::re_type::get_field_desc(api.scene_layer_type, "FilterSceneInfo");
            api.z_prepass_desc = utility::re_type::get_field_desc(api.scene_layer_type, "ZPrepassSceneInfo");
            api.depth_stencil_desc = utility::re_type::get_field_desc(api.scene_layer_type, "DepthStencilTex");
            api.velocity_target_desc = utility::re_type::get_field_desc(api.scene_layer_type, "VelocityTarget");
        }

        if (const auto prepare_output = sdk::find_type_definition("via.render.layer.PrepareOutput"); prepare_output != nullptr) {
            api.prepare_output_type = prepare_output->get_type();
        }

        if (const auto output = sdk::find_type_definition("via.render.layer.Output"); output != nullptr) {
            api.output_layer_type = output->get_type();
        }

        return api;
    }();

    return api;
}

// RAII bookkeeping for the backbuffer's D3D12 resource state.
//
// Transitions are always recorded from the *actual* last-known state rather than a
// hardcoded source state, so a dropped barrier (fence-wait timeout -> closed command
// list) self-heals within one frame instead of desyncing the state machine for good.
class BackbufferState {
public:
    BackbufferState(d3d12::CommandContext& copier, ID3D12Resource* backbuffer, D3D12_RESOURCE_STATES& tracked)
        : m_copier{copier}, m_backbuffer{backbuffer}, m_tracked{tracked} {
    }

    ~BackbufferState() {
        // Defensive only: every path below already ends in PRESENT, but this guarantees
        // the tracked state can never be left dangling.
        restore(D3D12_RESOURCE_STATE_PRESENT);
    }

    BackbufferState(const BackbufferState&) = delete;
    BackbufferState& operator=(const BackbufferState&) = delete;

    void to(D3D12_RESOURCE_STATES state) {
        m_copier.transition(m_backbuffer, m_tracked, state);
        m_tracked = state;
    }

    void restore(D3D12_RESOURCE_STATES state) {
        if (m_tracked != state) {
            to(state);
        }
    }

private:
    d3d12::CommandContext& m_copier;
    ID3D12Resource* m_backbuffer;
    D3D12_RESOURCE_STATES& m_tracked;
};
} // namespace

std::shared_ptr<TemporalUpscaler>& TemporalUpscaler::get() {
    static std::shared_ptr instance = std::make_shared<TemporalUpscaler>();
    return instance;
}

std::optional<std::string> TemporalUpscaler::on_initialize() {
    // D3D12 only — there is no D3D11 path in this module.
    if (!g_framework->is_dx12()) {
        spdlog::info("[TemporalUpscaler] Not a DirectX 12 title, TemporalUpscaler will not work");
        return Mod::on_initialize();
    }

    m_backend_loaded = GetModuleHandleA("PDPerfPlugin.dll") != nullptr ||
                       utility::load_module_from_current_directory(L"PDPerfPlugin.dll") != nullptr;

    if (!m_backend_loaded) {
        spdlog::info("[TemporalUpscaler] Could not load PDPerfPlugin.dll, TemporalUpscaler will not work");
        return Mod::on_initialize();
    }

    for (auto type = 0; type <= (int)PDUpscaleType::XESS; ++type) {
        const auto name = GetUpscaleMethodName(type);

        if (name == nullptr) {
            continue;
        }

        if (!IsUpscaleMethodAvailable(type)) {
            spdlog::info("[TemporalUpscaler] Upscale method {} ({}) is not available", type, name);
            continue;
        }

        spdlog::info("[TemporalUpscaler] Upscale method {} ({}) is available", type, name);
        m_methods.emplace_back(name, (PDUpscaleType)type);
    }

    if (m_methods.empty()) {
        spdlog::info("[TemporalUpscaler] No upscale methods are available, TemporalUpscaler will not work");
        m_backend_loaded = false;
        return Mod::on_initialize();
    }

    // ImGui needs stable char* labels, so build them once the list is final. m_methods is
    // never modified afterwards, so the c_str() pointers stay valid for the session.
    m_combo_labels.reserve(m_methods.size());

    for (const auto& method : m_methods) {
        m_combo_labels.push_back(method.first.c_str());
    }

    m_available_upscale_type = 0;
    m_upscale_type = m_methods.front().second;

    return Mod::on_initialize();
}

void TemporalUpscaler::on_config_load(const utility::Config& cfg) {
    config_load_options(cfg, m_options);
}

void TemporalUpscaler::on_config_save(utility::Config& cfg) {
    config_save_options(cfg, m_options);
}

void TemporalUpscaler::on_draw_ui() {
    if (!ImGui::CollapsingHeader(this->get_name().data())) {
        return;
    }

#if TDB_VER < 67
    ImGui::TextWrapped("TemporalUpscaler is not yet supported on this version of the engine.");
    ImGui::TextWrapped("Supported: RE2/RE3/RE7 (RT latest, not beta builds), RE4, RE8, SF6, DMC5 (partial)");
    return;
#else
    if (!m_backend_loaded) {
        ImGui::TextWrapped("Backend is not loaded, TemporalUpscaler will not work.");
        ImGui::TextWrapped("Make sure you've downloaded UpscalerBasePlugin (PDPerfPlugin.dll)");
        ImGui::TextWrapped("And the corresponding DLLs for your preferred upscaler(s) (DLSS/FSR2/XeSS)");
        return;
    }

    // The toggle is the only option visible while the upscaler is off, and enabling it
    // hands control to apply_setting_changes() below.
    if (m_enabled->draw("Enabled")) {
        apply_setting_changes();
    }

    // Nothing below may run while !ready(): the options stay hidden until the upscaler is
    // actually live, and ready() is false for the frames a reinit is pending on.
    if (!ready()) {
        return;
    }

    // Every option below that invalidates the plugin's feature requests a reinit; they are
    // applied in one place at the end instead of at each call site.
    bool needs_reinit = false;

    if (m_use_native_resolution->draw("Use Native Res (DLAA)")) {
        // The render size depends on the mode, so re-query it and the motion scale.
        invalidate_render_size();
        update_motion_scale();
    }

    needs_reinit |= m_sharpness->draw("Sharpness");
    m_sharpness_amount->draw("Sharpness Amount");

    const auto w = (float)get_render_width();
    const auto h = (float)get_render_height();

    if (ImGui::Combo("Upscale Type", (int*)&m_available_upscale_type, m_combo_labels.data(), (int)m_combo_labels.size())) {
        m_available_upscale_type = (uint32_t)std::min<size_t>(m_available_upscale_type, m_methods.size() - 1);
        m_upscale_type = m_methods[m_available_upscale_type].second;
        needs_reinit = true;
    }

    needs_reinit |= m_upscale_quality->draw("Quality Level");

    // The plugin feature is recreated on toggle: switching between the direct and the
    // copied output path live was observed to leave the plugin's cached destination state
    // polluted (blurry/jagged output).
    needs_reinit |= m_direct_output->draw("Direct Output (skip fullscreen copy)");

    ImGui::SetNextItemOpen(true, ImGuiCond_Once);

    if (ImGui::TreeNode("Debug Options")) {
        ImGui::Checkbox("Upscale", &m_upscale);
        ImGui::Checkbox("Jitter", &m_jitter);

        if (ImGui::Checkbox("Allow Engine TAA", &m_allow_taa)) {
            // Don't wait for the next throttled render-config sample to apply.
            m_render_config_cached = false;
        }

        ImGui::SliderInt("Displayed Scene", &m_displayed_scene, 0, 1);
        ImGui::DragFloat("Jitter Scale X", &m_jitter_scale[0], 0.01f, -5.0f, 5.0f);
        ImGui::DragFloat("Jitter Scale Y", &m_jitter_scale[1], 0.01f, -5.0f, 5.0f);

        if (ImGui::DragFloat("MotionScale X", &m_motion_scale[0], 0.01f, -w, w) ||
            ImGui::DragFloat("MotionScale Y", &m_motion_scale[1], 0.01f, -h, h)) {
            SetMotionScaleX(VIEW_ID, m_motion_scale[0]);
            SetMotionScaleY(VIEW_ID, m_motion_scale[1]);
        }

        ImGui::Text("OptimalBias: %f", GetOptimalMipmapBias(VIEW_ID));

        ImGui::TreePop();
    }

    if (needs_reinit) {
        m_wants_reinitialize = true;
    }
#endif
}

void TemporalUpscaler::apply_setting_changes() {
    if (!activated()) {
        // Disabled: give the plugin's features back and restore the engine's original
        // anti-aliasing, instead of leaving everything resident but unused.
        release_upscale_features();
        restore_engine_aa();
        return;
    }

    // Enabled (again): the D3D12 inputs, the layer pointers and the render size may all be
    // stale from the disabled period, during which every per-frame callback was skipped.
    // Force a full re-init so all of it is re-resolved.
    m_wants_reinitialize = true;
}

void TemporalUpscaler::restore_engine_aa() {
    if (!m_taa_disabled) {
        return;
    }

    m_taa_disabled = false;

    const auto& refl = reflection();

    if (refl.renderer == nullptr || refl.renderer_get_render_config == nullptr || refl.render_config_set_aa == nullptr) {
        return;
    }

    auto context = sdk::get_thread_context();
    auto renderer = refl.renderer->get_instance();
    auto render_config = refl.renderer_get_render_config->call<::REManagedObject*>(context, renderer);

    if (render_config != nullptr) {
        refl.render_config_set_aa->call<void*>(context, render_config, m_original_antialiasing);
        spdlog::info("[TemporalUpscaler] TAA restored to {}", (int)m_original_antialiasing);
    }
}

void TemporalUpscaler::on_early_present() {
    m_rendering.store(true, std::memory_order_relaxed);

    if (!m_backend_loaded) {
        return;
    }

    if (!ensure_first_frame()) {
        return;
    }

    if (m_wants_reinitialize) {
        // release_upscale_features() zeroes the cached render size, and on_view_get_size()
        // (render thread) refresh()es it from GetRenderWidth() whenever it reads zero — which
        // mid-teardown is the *previous* feature's size, latched for good. Carry the last
        // known size across the teardown so that window never opens; init_upscale_features()
        // publishes the new feature's size once it exists.
        const auto saved_w = m_cached_render_size[0].load(std::memory_order_relaxed);
        const auto saved_h = m_cached_render_size[1].load(std::memory_order_relaxed);

        release_upscale_features();
        m_wants_reinitialize = false;

        m_cached_render_size[0].store(saved_w, std::memory_order_relaxed);
        m_cached_render_size[1].store(saved_h, std::memory_order_relaxed);

        if (init_upscale_features()) {
            return;
        }

        // Reinit failed: ready() must not stay true with a dead backend, or the engine is
        // left stuck at the spoofed low resolution. Drop back into the throttled
        // first-frame retry path instead.
        spdlog::error("[TemporalUpscaler] Reinit failed, scheduling retry");
        m_initialized = false;
        m_first_frame_finished = false;
        m_set_view.store(false, std::memory_order_relaxed);
        return;
    }

    if (!ready() || !m_upscale) {
        return;
    }

    auto& state = m_view;

    if (state.scene_layer == nullptr) {
        return;
    }

    // Cached so that a per-frame GetRenderWidth/Height (a cross-DLL call into the plugin)
    // is only paid after invalidate_render_size() zeroes it.
    if (m_cached_render_size[0].load(std::memory_order_relaxed) == 0) {
        refresh_cached_render_size();
    }

    auto& hook = g_framework->get_d3d12_hook();
    auto swapchain = hook->get_swap_chain();

    if (swapchain == nullptr) {
        warn_missing_input(WARN_BACKBUFFER);
        return;
    }

    // Cached backbuffer fetch — replaces a per-frame GetBuffer + GetDesc round-trip.
    const auto bb_index = swapchain->GetCurrentBackBufferIndex();
    auto backbuffer = get_backbuffer_d3d12(bb_index);

    if (backbuffer == nullptr) {
        warn_missing_input(WARN_BACKBUFFER);
        return;
    }

    auto& copier = m_copiers[bb_index % m_copiers.size()];

    // Bounded wait: INFINITE would deadlock the present thread forever on a GPU hang or
    // device removal. On timeout we only skip this frame's reclaim — the next wait()
    // retries, because waiting_for_fence stays set.
    copier.wait(COMMAND_CONTEXT_WAIT_MS);

    if (state.depth == nullptr) {
        warn_missing_input(WARN_DEPTH);
    } else if (state.motion_vectors == nullptr) {
        warn_missing_input(WARN_MOTION_VECTORS);
    } else if (state.color == nullptr) {
        warn_missing_input(WARN_COLOR);
    } else {
        UpscaleParams params{};
        params.id = (int)VIEW_ID;
        params.execute = true;
        params.reset = false;
        params.color = state.color.Get();
        params.motionVector = state.motion_vectors.Get();
        params.depth = state.depth.Get();
        params.mask = nullptr;
        params.destination = nullptr;
        params.motionScaleX = m_motion_scale[0];
        params.motionScaleY = m_motion_scale[1];
        params.renderSizeX = (float)m_cached_render_size[0].load(std::memory_order_relaxed);
        params.renderSizeY = (float)m_cached_render_size[1].load(std::memory_order_relaxed);
        params.jitterOffsetX = state.jitter_offset[0];
        params.jitterOffsetY = state.jitter_offset[1];
        params.sharpness = m_sharpness_amount->value();
        params.nearPlane = m_nearz;
        params.farPlane = m_farz;
        params.verticalFOV = m_fov;

        // Hand the backbuffer to the plugin so it writes straight into it, skipping the
        // fullscreen CopyResource. Force-disabled while an interposed frame-generation
        // swapchain is active: the interposer owns the swapchain there and external writes
        // are unverified.
        const bool direct_output = m_direct_output->value() && !hook->is_framegen_swapchain();

        BackbufferState bb{copier, backbuffer, m_bb_output_state};

        if (direct_output) {
            params.destination = backbuffer;

            // Get the backbuffer into UAV and submit that barrier *before* the plugin
            // writes into it. The submit closes the command list, so it has to retire
            // before the post-barrier below can be recorded.
            bb.to(D3D12_RESOURCE_STATE_UNORDERED_ACCESS);
            copier.execute();
            copier.wait(COMMAND_CONTEXT_WAIT_MS);
        } else {
            // Undo whatever a previously dropped direct-output barrier left behind, so the
            // copy path always starts from the canonical PRESENT.
            bb.restore(D3D12_RESOURCE_STATE_PRESENT);
        }

        EvaluateUpscaler(&params);

        if (direct_output) {
            bb.to(D3D12_RESOURCE_STATE_PRESENT);
        } else {
            copier.copy(m_upscaled_texture, backbuffer, D3D12_RESOURCE_STATE_UNORDERED_ACCESS, D3D12_RESOURCE_STATE_PRESENT);
        }

        if (!m_logged_first_evaluate) {
            spdlog::info("[TemporalUpscaler] Successfully rendered with TemporalUpscaler");
            m_logged_first_evaluate = true;
        }
    }

    copier.execute();
}

bool TemporalUpscaler::ensure_first_frame() {
    if (m_first_frame_finished) {
        return true;
    }

    // First-frame init can fail transiently during startup (swapchain or backbuffer not
    // ready yet), so retry on a throttle rather than permanently disabling the module: a
    // permanent disable leaves the engine's spoofed SceneView size inconsistent with
    // reality, misaligning the UI.
    const bool first_attempt = m_first_frame_retry_count == 0;
    ++m_first_frame_retry_count;

    if (!first_attempt && (m_first_frame_retry_count % FIRST_FRAME_RETRY_INTERVAL) != 0) {
        return false;
    }

    if (on_first_frame()) {
        // Reset the failure timer so a later reinit failure gets a fresh give-up budget.
        m_first_frame_failure_start = {};
        return true;
    }

    m_initialized = false;

    // Lift the resolution spoof immediately so the engine renders at its real size while
    // we retry, instead of being fed the dead backend's cached render size.
    m_set_view.store(false, std::memory_order_relaxed);
    invalidate_render_size();

    // Give up after a wall-clock budget, not a frame count: at low fps (loading screens) a
    // frame-based threshold can stretch the retry phase to many minutes.
    const auto now = std::chrono::steady_clock::now();

    if (m_first_frame_failure_start == std::chrono::steady_clock::time_point{}) {
        m_first_frame_failure_start = now;
    }

    if ((now - m_first_frame_failure_start) >= FIRST_FRAME_RETRY_TIMEOUT) {
        spdlog::error("[TemporalUpscaler] First frame init kept failing for {}s, giving up",
            std::chrono::duration_cast<std::chrono::seconds>(FIRST_FRAME_RETRY_TIMEOUT).count());
        m_backend_loaded = false;
    }

    return false;
}

bool TemporalUpscaler::on_first_frame() {
    spdlog::info("[TemporalUpscaler] Initializing first frame...");

    // Plugin-global setup runs once per session. The retry path can call this many times,
    // but SetupDirectX/InitLogDelegate are not safe to repeat, so only
    // init_upscale_features() below is retried.
    if (!m_directx_setup_done) {
        InitLogDelegate([](char* msg, int size) {
            spdlog::info("[TemporalUpscaler] {}", msg);
        });

        if (!SetupDirectX(g_framework->get_d3d12_hook()->get_command_queue(), PDGraphicsAPI::D3D12)) {
            // Return without setting the guard so the throttled retry path re-attempts
            // SetupDirectX as well.
            spdlog::error("[TemporalUpscaler] SetupDirectX failed");
            return false;
        }

        m_directx_setup_done = true;
    }

    if (!init_upscale_features()) {
        return false;
    }

    m_initialized = true;
    m_first_frame_finished = true;

    return true;
}

bool TemporalUpscaler::init_upscale_features() {
    spdlog::info("[TemporalUpscaler] Initializing upscale features...");

    auto& hook = g_framework->get_d3d12_hook();
    auto swapchain = hook->get_swap_chain();

    if (swapchain == nullptr) {
        spdlog::error("[TemporalUpscaler] No swapchain available (D3D12)");
        return false;
    }

    // Fills the backbuffer cache (and m_backbuffer_size) if not yet populated.
    auto backbuffer = get_backbuffer_d3d12(swapchain->GetCurrentBackBufferIndex());

    if (backbuffer == nullptr) {
        spdlog::error("[TemporalUpscaler] Failed to get backbuffer (D3D12)");
        return false;
    }

    const auto bb_desc = backbuffer->GetDesc();
    m_bb_output_state = D3D12_RESOURCE_STATE_PRESENT;

    for (auto& copier : m_copiers) {
        copier.setup();
    }

    // The upscaler needs the depth, motion vectors and color of the view in one feature.
    InitParams params{};
    params.id = (int)VIEW_ID;
    params.upscaleMethod = m_upscale_type;
    params.qualityLevel = m_upscale_quality->value();
    params.displaySizeX = (int)bb_desc.Width;
    params.displaySizeY = (int)bb_desc.Height;
    params.format = (int)bb_desc.Format;
    params.isContentHDR = false;
    params.depthInverted = true;
    params.YAxisInverted = false;
    params.motionVetorsJittered = false;
    params.enableSharpening = m_sharpness->value();
    params.enableAutoExposure = false;

    m_upscaled_texture = (ID3D12Resource*)InitUpscaler(&params);

    if (m_upscaled_texture == nullptr) {
        spdlog::error("[TemporalUpscaler] InitUpscaler failed");
        return false;
    }

    update_motion_scale();

    // Publish the render size of the feature that was just created. GetRenderWidth() only
    // becomes valid once InitUpscaler() has run, and the lazy refresh in on_view_get_size()
    // runs on the render thread: it can sample the previous feature mid-teardown and latch
    // the *previous* quality's size, which is then never re-queried. The module would keep
    // feeding the plugin a render size that does not match the new feature, DLSS answers
    // NVSDK_NGX_Result_FAIL_InvalidParameter and writes nothing, and the copy path blits that
    // blank output over the backbuffer — the black screen seen after a quality change.
    // Re-publishing here (after InitUpscaler, so GetRenderWidth() reflects the new feature)
    // keeps the module and the feature in agreement.
    refresh_cached_render_size();

    const auto desc = m_upscaled_texture->GetDesc();
    spdlog::info("[TemporalUpscaler] Upscaled texture size: {}x{}", desc.Width, desc.Height);
    spdlog::info("[TemporalUpscaler] Wanted render resolution: {}x{}", GetRenderWidth(VIEW_ID), GetRenderHeight(VIEW_ID));
    spdlog::info("[TemporalUpscaler] Created upscaled texture(s)");

    return true;
}

void TemporalUpscaler::release_upscale_features() {
    for (auto& copier : m_copiers) {
        copier.wait(COMMAND_CONTEXT_WAIT_MS);
        copier.reset();
    }

    if (m_upscaled_texture != nullptr) {
        ReleaseUpscaleFeature(VIEW_ID);
        m_upscaled_texture = nullptr;
    }

    // Always, even when the features had already been released: everything cached below
    // belongs to the swapchain/scene layer tree we are dropping.
    invalidate_caches();
}

void TemporalUpscaler::invalidate_caches() {
    // Render size and motion scale are derived from the plugin and the scene view size.
    invalidate_render_size();

    // Engine-side state that has to be re-queried: the camera parameters, the render config
    // assertion and the layer pointers may all be stale, and the D3D12 inputs and their
    // copies definitely are.
    m_camera_params_cached = false;
    m_render_config_cached = false;
    m_cached_root_layer = nullptr;
    m_layer_rescan_counter = 0;
    m_valid_scene_layers.clear();
    m_view.reset();

    // ResizeBuffers/device reset recreates the swapchain buffers, so the cached pointers
    // would dangle.
    for (auto& backbuffer : m_backbuffers) {
        backbuffer.Reset();
    }
}

void TemporalUpscaler::on_post_present() {
    m_rendering.store(false, std::memory_order_relaxed);
}

void TemporalUpscaler::on_device_reset() {
    release_upscale_features(); // also invalidates every cache above
    m_wants_reinitialize = true;
}

void TemporalUpscaler::on_view_get_size(REManagedObject* scene_view, float* result) {
    // Don't spoof the resolution when the upscaler is switched off by the user. m_enabled is
    // checked separately from ready() because ready() is also false during reinit frames
    // (m_wants_reinitialize), and the spoof must stay in place during those to avoid a
    // one-frame resolution mismatch. Checking ready() alone also failed to stop spoofing
    // when the user toggled m_enabled off, because m_rendering was already set to true in
    // on_early_present and m_set_view stayed true from the last enabled frame — leaving the
    // engine stuck at the low resolution.
    if (!m_enabled->value()) {
        m_set_view.store(false, std::memory_order_relaxed);
        return;
    }

    if (!ready() && (!m_rendering.load(std::memory_order_relaxed) || !m_set_view.load(std::memory_order_relaxed))) {
        m_set_view.store(false, std::memory_order_relaxed);
        return;
    }

    // Spoof the size to the upscaler's render size. The cache keeps GetRenderWidth/Height
    // (each a cross-DLL call into PDPerfPlugin) off this path.
    if (m_cached_render_size[0].load(std::memory_order_relaxed) == 0 || m_cached_render_size[1].load(std::memory_order_relaxed) == 0) {
        refresh_cached_render_size();
    }

    result[0] = (float)m_cached_render_size[0].load(std::memory_order_relaxed);
    result[1] = (float)m_cached_render_size[1].load(std::memory_order_relaxed);

    m_set_view.store(true, std::memory_order_relaxed);
}

void TemporalUpscaler::on_scene_layer_update(sdk::renderer::layer::Scene* layer, void* render_context) {
    if (!ready()) {
        return;
    }

    // Pointer compare first: is_fully_rendered() costs 3-5 engine calls per layer, and
    // m_view.scene_layer was already picked from the fully rendered set, so any other layer
    // is rejected without touching the engine.
    if (layer != m_view.scene_layer.get()) {
        return;
    }

    auto& state = m_view;
    const auto& refl = reflection();

    // get_field<T>(obj, "name") would do a string concat + hashmap lookup under a
    // shared_lock on every call, so the descriptors are cached and get_field<T>(obj, desc)
    // is called instead.
    const std::array<sdk::renderer::SceneInfo*, SLOT_COUNT> scene_infos{
        utility::re_managed_object::get_field<sdk::renderer::SceneInfo*>((::REManagedObject*)layer, refl.scene_info_desc),
        utility::re_managed_object::get_field<sdk::renderer::SceneInfo*>((::REManagedObject*)layer, refl.depth_distortion_desc),
        utility::re_managed_object::get_field<sdk::renderer::SceneInfo*>((::REManagedObject*)layer, refl.filter_desc),
        utility::re_managed_object::get_field<sdk::renderer::SceneInfo*>((::REManagedObject*)layer, refl.z_prepass_desc),
    };

    const auto w = (float)m_cached_render_size[0].load(std::memory_order_relaxed);
    const auto h = (float)m_cached_render_size[1].load(std::memory_order_relaxed);

    float x = 0.0f;
    float y = 0.0f;

    if (m_jitter) {
        // This callback can fire before on_early_present has filled the cache ({0,0}).
        // Dividing by zero would inject NaN/inf jitter into the engine's matrices and
        // poison the upscaler's input for that frame. Skipping the whole block is safe: the
        // matrix save below is only a next-frame cache and refreshes next frame.
        if (w <= 0.0f || h <= 0.0f) {
            return;
        }

        // GetJitterPhaseCount crosses a DLL boundary into PDPerfPlugin, so it is only
        // called when jitter is actually enabled.
        const auto phase = GetJitterPhaseCount(VIEW_ID);

        ++state.jitter_index;
        GetJitterOffset(&x, &y, state.jitter_index, phase);

        state.jitter_offset[0] = -x;
        state.jitter_offset[1] = -y;

        // from FSR2 code
        x = m_jitter_scale[0] * (x / w);
        y = m_jitter_scale[1] * (y / h);
    } else {
        state.jitter_offset[0] = 0.0f;
        state.jitter_offset[1] = 0.0f;
    }

    for (size_t i = 0; i < scene_infos.size(); ++i) {
        auto* scene_info = scene_infos[i];

        if (scene_info == nullptr) {
            continue;
        }

        if (!m_jitter) {
            // Still remember the current matrices for the next frame, but skip the two 4x4
            // matrix inversions that exist only to apply jitter.
            state.old_projection_matrix[i] = scene_info->projection_matrix;
            state.old_view_matrix[i] = scene_info->view_matrix;
            continue;
        }

        state.old_projection_matrix[i][2][0] += x;
        state.old_projection_matrix[i][2][1] += y;

        scene_info->old_view_projection_matrix = state.old_projection_matrix[i] * state.old_view_matrix[i];

        state.old_projection_matrix[i] = scene_info->projection_matrix;
        state.old_view_matrix[i] = scene_info->view_matrix;

        scene_info->projection_matrix[2][0] += x;
        scene_info->projection_matrix[2][1] += y;
        scene_info->inverse_projection_matrix = glm::inverse(scene_info->projection_matrix);

        scene_info->view_projection_matrix = scene_info->projection_matrix * scene_info->view_matrix;
        scene_info->inverse_view_projection_matrix = glm::inverse(scene_info->view_projection_matrix);
    }
}

void TemporalUpscaler::on_overlay_layer_draw(sdk::renderer::layer::Overlay* layer, void* render_context) {
    if (!ready()) {
        return;
    }

    auto context = (sdk::renderer::RenderContext*)render_context;
    auto scene_layer = (sdk::renderer::layer::Scene*)layer->get_parent();

    if (scene_layer == nullptr || m_view.scene_layer.get() != scene_layer) {
        return;
    }

    auto& state = m_view;
    const auto& refl = reflection();

    auto depth = utility::re_managed_object::get_field<::sdk::renderer::Texture*>((::REManagedObject*)scene_layer, refl.depth_stencil_desc);

    if (depth != nullptr && state.depth_copy != nullptr) {
        context->copy_texture(state.depth_copy, depth);
    }

    auto motion_vectors_state = utility::re_managed_object::get_field<::sdk::renderer::TargetState*>((::REManagedObject*)scene_layer, refl.velocity_target_desc);

    if (motion_vectors_state != nullptr && state.motion_vectors_copy != nullptr) {
        if (auto rtv = motion_vectors_state->get_rtv(0); rtv != nullptr) {
            if (auto motion_vectors = rtv->get_texture_d3d12(); motion_vectors != nullptr) {
                context->copy_texture(state.motion_vectors_copy, motion_vectors);
            }
        }
    }
}

void TemporalUpscaler::on_prepare_output_layer_draw(sdk::renderer::layer::PrepareOutput* layer, void* render_context) {
    if (!ready()) {
        return;
    }

    auto context = (sdk::renderer::RenderContext*)render_context;
    auto scene_layer = (sdk::renderer::layer::Scene*)layer->get_parent();

    if (scene_layer == nullptr || m_view.scene_layer.get() != scene_layer) {
        return;
    }

    const auto output_state = layer->get_output_state();

    if (output_state == nullptr) {
        return;
    }

    const auto rtv = output_state->get_rtv(0);

    if (rtv == nullptr) {
        return;
    }

    const auto tex = rtv->get_texture_d3d12();

    if (tex == nullptr) {
        return;
    }

    auto& state = m_view;

    if (state.color_copy != nullptr) {
        context->copy_texture(state.color_copy, tex);
    }
}

void TemporalUpscaler::on_pre_application_entry(void* entry, const char* name, size_t hash) {
    if (!ready()) {
        return;
    }

    if (hash == "EndRendering"_fnv) {
        // The scene layer subtree is re-resolved every frame (only the D3D12 inputs are
        // cached), and the frame is skipped entirely when there is nothing to upscale.
        if (!resolve_scene_layer()) {
            return;
        }

        // Camera near/far/FOV and the render config are independent, so they are sampled at
        // separate intervals: the camera block needs fresh-ish values (zoom), while the
        // render config (AA mode, image quality) is a set-and-forget assertion that the game
        // almost never changes mid-session.
        const bool need_camera_update = !m_camera_params_cached || (m_frame_counter % CAMERA_SAMPLE_INTERVAL) == 0;
        const bool need_render_config_update = !m_render_config_cached || (m_frame_counter % RENDER_CONFIG_SAMPLE_INTERVAL) == 0;
        ++m_frame_counter;

        if (need_camera_update) {
            update_camera_params();
        }

        if (need_render_config_update) {
            sync_render_config();
        }
    }
}

bool TemporalUpscaler::resolve_scene_layer() {
    auto& state = m_view;

    // Only the root layer is cached (it is owned by the renderer singleton and persists for
    // the game's lifetime), re-resolved periodically rather than paying a
    // get_native_singleton hashmap + shared_lock + vtable call every frame.
    auto* root_layer = m_cached_root_layer;

    if (root_layer == nullptr || (m_layer_rescan_counter++ % LAYER_RESCAN_INTERVAL) == 0) {
        root_layer = sdk::renderer::get_root_layer();
        m_cached_root_layer = root_layer;
    }

    if (root_layer == nullptr) {
        spdlog::error("[TemporalUpscaler] Failed to get root layer");
        state.scene_layer.reset();
        return false;
    }

    const auto& refl = reflection();

    if (refl.output_layer_type == nullptr) {
        return false;
    }

    // The Output layer is resolved through a cached REType* (a cheap pointer walk), but the
    // scene layers below it are re-scanned EVERY frame: the engine can destroy and recreate
    // that subtree between frames (scene transitions, loading) without the Output layer
    // pointer changing, so caching a Scene* across frames is a use-after-free hazard. The
    // scan is allocation-free (m_valid_scene_layers is reused, and cleared by the engine
    // helper) and the resulting Scene* is pinned into an intrusive_ptr below.
    auto [output_parent, output_layer] = root_layer->find_layer_recursive(refl.output_layer_type);

    auto* current_output_layer = (output_layer != nullptr && *output_layer != nullptr) ? *output_layer : nullptr;

    if (current_output_layer == nullptr) {
        m_valid_scene_layers.clear();
        state.scene_layer.reset();
        return false;
    }

    current_output_layer->find_fully_rendered_scene_layers(m_valid_scene_layers);

    if (m_valid_scene_layers.empty()) {
        state.scene_layer.reset();
        return false;
    }

    // Displayed scene: 0 = the first fully rendered layer, 1 = the second (only when the
    // engine actually gave us more than one).
    const auto index = std::min<size_t>((size_t)std::max(m_displayed_scene, 0), m_valid_scene_layers.size() - 1);
    auto* selected = m_valid_scene_layers[index];

    if (state.scene_layer.get() != selected) {
        state.scene_layer = selected;
        // The D3D12 resources belong to the previous layer.
        state.reset_inputs();
    }

    ensure_d3d12_inputs();

    return true;
}

void TemporalUpscaler::ensure_d3d12_inputs() {
    auto& state = m_view;

    if (state.depth != nullptr && state.motion_vectors != nullptr && state.color != nullptr) {
        return;
    }

    const auto& refl = reflection();

    auto prepareoutput_layer = refl.prepare_output_type != nullptr
        ? (sdk::renderer::layer::PrepareOutput**)state.scene_layer->find_layer(refl.prepare_output_type)
        : nullptr;

    if (prepareoutput_layer == nullptr) {
        state.reset_inputs();
        return;
    }

    state.depth = state.scene_layer->get_depth_stencil_d3d12();
    state.motion_vectors = state.scene_layer->get_motion_vectors_d3d12();

    if (*prepareoutput_layer != nullptr) {
        const auto output_state = (*prepareoutput_layer)->get_output_state();

        if (output_state != nullptr) {
            state.color = output_state->get_native_resource_d3d12();
        } else {
            state.color.Reset();
        }
    } else {
        state.color.Reset();
    }
}

void TemporalUpscaler::update_camera_params() {
    const auto& refl = reflection();
    auto camera = sdk::get_primary_camera();

    if (camera == nullptr || refl.camera_get_near == nullptr || refl.camera_get_far == nullptr ||
        refl.camera_get_projection == nullptr) {
        m_camera_params_cached = false;
        return;
    }

    auto context = sdk::get_thread_context();
    m_nearz = refl.camera_get_near->call<float>(context, camera);
    m_farz = refl.camera_get_far->call<float>(context, camera);

    Matrix4x4f projection_matrix{};
    refl.camera_get_projection->call<void>(&projection_matrix, context, camera);
    m_fov = 2.0f * std::atan(1.0f / projection_matrix[1][1]);

    m_camera_params_cached = true;
}

void TemporalUpscaler::sync_render_config() {
    const auto& refl = reflection();

    if (refl.renderer == nullptr || refl.renderer_get_render_config == nullptr ||
        refl.render_config_get_aa == nullptr || refl.render_config_set_aa == nullptr) {
        return;
    }

    auto context = sdk::get_thread_context();
    auto renderer = refl.renderer->get_instance();
    auto render_config = refl.renderer_get_render_config->call<::REManagedObject*>(context, renderer);

    const auto antialiasing = refl.render_config_get_aa->call<via::render::RenderConfig::AntiAliasingType>(context, render_config);

    // Remember the mode we are about to override, so it can be restored when the upscaler
    // is disabled.
    if (!m_taa_disabled &&
        (antialiasing == via::render::RenderConfig::AntiAliasingType::TAA ||
         antialiasing == via::render::RenderConfig::AntiAliasingType::FXAA_TAA)) {
        m_original_antialiasing = antialiasing;
    }

    if (!m_allow_taa) {
        // The engine's own TAA cannot be used together with the upscaler.
        if (antialiasing == via::render::RenderConfig::AntiAliasingType::TAA ||
            antialiasing == via::render::RenderConfig::AntiAliasingType::FXAA_TAA) {
            refl.render_config_set_aa->call<void*>(context, render_config, via::render::RenderConfig::AntiAliasingType::NONE);
            m_taa_disabled = true;
            spdlog::info("[TemporalUpscaler] TAA disabled");
        }
    } else if (antialiasing == via::render::RenderConfig::AntiAliasingType::NONE) {
        refl.render_config_set_aa->call<void*>(context, render_config, via::render::RenderConfig::AntiAliasingType::TAA);
    }

    // The image quality rate has to be forced to 1.0, otherwise the motion and depth
    // buffers become misaligned with the color buffer.
    if (refl.render_config_get_iqr != nullptr) {
        const auto image_quality_rate = refl.render_config_get_iqr->call<float>(context, render_config);

        if (image_quality_rate != 1.0f) {
            refl.render_config_set_iqr->call<void*>(context, render_config, 1.0f);
            spdlog::info("[TemporalUpscaler] Image quality rate set to 1.0");
        }
    }

    m_render_config_cached = true;
}

ID3D12Resource* TemporalUpscaler::get_backbuffer_d3d12(uint32_t index) {
    if (index >= m_backbuffers.size()) {
        return nullptr;
    }

    auto& backbuffer = m_backbuffers[index];

    if (backbuffer == nullptr) {
        auto& hook = g_framework->get_d3d12_hook();
        auto swapchain = hook->get_swap_chain();

        if (swapchain == nullptr || FAILED(swapchain->GetBuffer(index, IID_PPV_ARGS(&backbuffer)))) {
            backbuffer.Reset();
            return nullptr;
        }

        const auto desc = backbuffer->GetDesc();
        m_backbuffer_size[0].store((uint32_t)desc.Width, std::memory_order_relaxed);
        m_backbuffer_size[1].store((uint32_t)desc.Height, std::memory_order_relaxed);
    }

    return backbuffer.Get();
}

uint32_t TemporalUpscaler::get_render_width() const {
    if (m_use_native_resolution->value()) {
        // 1 is subtracted from the native resolution because the game then creates a
        // separate color buffer we can use; without it that buffer stays null.
        return m_backbuffer_size[0].load(std::memory_order_relaxed) - 1;
    }

    return GetRenderWidth(VIEW_ID);
}

uint32_t TemporalUpscaler::get_render_height() const {
    if (m_use_native_resolution->value()) {
        return m_backbuffer_size[1].load(std::memory_order_relaxed) - 1;
    }

    return GetRenderHeight(VIEW_ID);
}

void TemporalUpscaler::update_motion_scale() {
#if TDB_VER > 67
    m_motion_scale[0] = (float)get_render_width() / 2.0f;
    m_motion_scale[1] = -1.0f * ((float)get_render_height() / 2.0f);
#else
    // I have no idea. Would need to take a look at the texture in RenderDoc.
    // Might need a shader to fix this?
    m_motion_scale[0] = 0.01f;
    m_motion_scale[1] = -1.0f * ((float)get_render_height() / 2.0f);
#endif

    SetMotionScaleX(VIEW_ID, m_motion_scale[0]);
    SetMotionScaleY(VIEW_ID, m_motion_scale[1]);
}

void TemporalUpscaler::invalidate_render_size() {
    m_cached_render_size[0].store(0, std::memory_order_relaxed);
    m_cached_render_size[1].store(0, std::memory_order_relaxed);
}

void TemporalUpscaler::refresh_cached_render_size() {
    m_cached_render_size[0].store(get_render_width(), std::memory_order_relaxed);
    m_cached_render_size[1].store(get_render_height(), std::memory_order_relaxed);
}

void TemporalUpscaler::warn_missing_input(WarnSource source) {
    static constexpr const char* messages[WARN_COUNT]{
        "Failed to get backbuffer (D3D12)",
        "Failed to get depth stencil (D3D12)",
        "Failed to get motion vectors (D3D12)",
        "Failed to get color buffer (D3D12)",
    };

    // One error per source every WARN_INTERVAL frames, so a permanently missing input
    // cannot flood the log while the others still get reported.
    if ((m_missing_input_warn_counters[source]++ % WARN_INTERVAL) == 0) {
        spdlog::error("[TemporalUpscaler] {}", messages[source]);
    }
}

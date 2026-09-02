#include <d3d11.h>
#include <d3d12.h>
#include <wrl.h>

#include <utility/Module.hpp>
#include <utility/Scan.hpp>
#include <utility/ScopeGuard.hpp>
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

std::shared_ptr<TemporalUpscaler>& TemporalUpscaler::get() {
    static std::shared_ptr instance = std::make_shared<TemporalUpscaler>();
    return instance;
}

std::optional<std::string> TemporalUpscaler::on_initialize() {
    m_backend_loaded = GetModuleHandleA("PDPerfPlugin.dll") != nullptr ||
                       utility::load_module_from_current_directory(L"PDPerfPlugin.dll") != nullptr;

    if (!m_backend_loaded) {
        spdlog::info("[TemporalUpscaler] Could not load PDPerfPlugin.dll, TemporalUpscaler will not work");
    } else {
        for (auto i = 0; i <= TemporalUpscaler::PDUpscaleType::XESS; ++i) {
            const auto is_available = IsUpscaleMethodAvailable(i);
            const auto upscale_name = GetUpscaleMethodName(i);

            if (upscale_name == nullptr) {
                continue;
            }

            if (is_available) {
                m_available_upscale_methods[upscale_name] = i;
                m_available_upscale_method_names.push_back(upscale_name);
                m_imgui_combo_names.push_back(upscale_name);
                spdlog::info("[TemporalUpscaler] Upscale method {} is available", i, upscale_name);
            } else {
                spdlog::info("[TemporalUpscaler] Upscale method {} is not available", i, upscale_name);
            }
        }

        if (m_available_upscale_methods.empty()) {
            spdlog::info("[TemporalUpscaler] No upscale methods are available, TemporalUpscaler will not work");
            m_backend_loaded = false;
        } else {
            m_upscale_type = (PDUpscaleType)m_available_upscale_methods[m_available_upscale_method_names[m_available_upscale_type]];
        }
    }

    return Mod::on_initialize();
}

void TemporalUpscaler::on_config_load(const utility::Config& cfg) {
    config_load_options(cfg, m_options);

    if (!ready()) {
        return;
    }
}

void TemporalUpscaler::on_config_save(utility::Config& cfg) {
    config_save_options(cfg, m_options);

    if (!ready()) {
        return;
    }
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

    //ImGui::Checkbox("Enabled", &m_enabled);
    if (m_enabled->draw("Enabled")) {
        if (m_enabled->value()) {
            // When the user re-enables the upscaler, D3D12 resources (depth, MV,
            // color) and scene layer pointers may be stale from the disabled
            // period (on_pre_application_entry was skipped, so scene layers were
            // not resolved). Force a reinit to re-resolve everything.
            m_wants_reinitialize = true;
        } else {
            // Restore the engine's original anti-aliasing mode when the upscaler
            // is disabled. on_pre_application_entry(EndRendering) is gated by
            // ready() and won't run while disabled, so we restore here.
            if (m_taa_disabled) {
                static auto renderer_t = sdk::find_type_definition("via.render.Renderer");
                static auto render_config_t = sdk::find_type_definition("via.render.RenderConfig");
                static auto get_render_config_method = renderer_t->get_method("get_RenderConfig");
                static auto set_antialiasing_method = render_config_t->get_method("set_AntiAliasing");

                auto context = sdk::get_thread_context();
                auto renderer = renderer_t->get_instance();
                auto render_config = get_render_config_method->call<::REManagedObject*>(context, renderer);

                if (render_config != nullptr) {
                    set_antialiasing_method->call<void*>(context, render_config, m_original_antialiasing);
                    spdlog::info("[TemporalUpscaler] TAA restored to {}", (int)m_original_antialiasing);
                }

                m_taa_disabled = false;
            }
        }
    }

    if (!ready()) {
        return;
    }
    
    //if (ImGui::Checkbox("Use Native Res (DLAA)", &m_use_native_resolution)) {
    if (m_use_native_resolution->draw("Use Native Res (DLAA)")) {
        // P5: Invalidate cached render size so it's re-queried with the new mode
        m_cached_render_size[0].store(0, std::memory_order_relaxed);
        m_cached_render_size[1].store(0, std::memory_order_relaxed);
        update_motion_scale();
    }

    //if (ImGui::Checkbox("Sharpness", &m_sharpness)) {
    if (m_sharpness->draw("Sharpness")) {
        m_wants_reinitialize = true;
    }

    //ImGui::DragFloat("Sharpness Amount", &m_sharpness_amount, 0.01f, 0.0f, 5.0f);
    m_sharpness_amount->draw("Sharpness Amount");

    const auto w = (float)get_render_width();
    const auto h = (float)get_render_height();
    
    if (ImGui::Combo("Upscale Type", (int*)&m_available_upscale_type, m_imgui_combo_names.data(), m_imgui_combo_names.size())) {
        if (m_available_upscale_type >= m_available_upscale_method_names.size()) {
            m_available_upscale_type = 0;
            m_upscale_type = (PDUpscaleType)m_available_upscale_methods[m_available_upscale_method_names[0]];
        } else {
            m_upscale_type = (PDUpscaleType)m_available_upscale_methods[m_available_upscale_method_names[m_available_upscale_type]];
        }

        // P2: Use reinitialize flag instead of blocking sleep — the actual
        // release/reinit will happen in the next on_early_present frame
        m_wants_reinitialize = true;
    }

    /*if (ImGui::Combo("Quality Level", (int*)&m_upscale_quality, "Performance\0Balanced\0Quality\0UltraPerformance\0")) {
        m_wants_reinitialize = true;
    }*/

    if (m_upscale_quality->draw("Quality Level")) {
        m_wants_reinitialize = true;
    }

    // Batch2 (experimental): recreate the plugin feature on toggle so its
    // internal pipeline is rebuilt cleanly for the selected output path —
    // switching between direct and copied output live was observed to leave
    // the plugin's cached destination state polluted (blurry/jagged output).
    if (m_direct_output->draw("Direct Output (skip fullscreen copy)")) {
        m_wants_reinitialize = true;
    }

    ImGui::SetNextItemOpen(true, ImGuiCond_Once);

    if (ImGui::TreeNode("Debug Options")) {
        ImGui::Checkbox("Upscale", &m_upscale);
        ImGui::Checkbox("Jitter", &m_jitter);
        ImGui::Checkbox("Allow Engine TAA", &m_allow_taa);

        ImGui::SliderInt("Displayed Scene", &m_displayed_scene, 0, 1);
        ImGui::DragFloat("Jitter Scale X", &m_jitter_scale[0], 0.01f, -5.0f, 5.0f);
        ImGui::DragFloat("Jitter Scale Y", &m_jitter_scale[1], 0.01f, -5.0f, 5.0f);

        if (ImGui::DragFloat("MotionScale X", &m_motion_scale[0], 0.01f, -w, w) ||
            ImGui::DragFloat("MotionScale Y", &m_motion_scale[1], 0.01f, -h, h)) 
        {
            SetMotionScaleX(get_evaluate_id(0), (float)m_motion_scale[0]);
            SetMotionScaleY(get_evaluate_id(0), (float)m_motion_scale[1]);
        }

        ImGui::Text("OptimalBias: %f", GetOptimalMipmapBias(get_evaluate_id(0)));

        ImGui::TreePop();
    }
#endif
}

void TemporalUpscaler::on_early_present() {
    m_rendering.store(true, std::memory_order_relaxed);

    if (!m_backend_loaded) {
        return;
    }

    if (!m_first_frame_finished) {
        if (!on_first_frame()) {
            m_backend_loaded = false;
            m_initialized = false;
            return;
        }
    }

    if (m_wants_reinitialize) {
        release_upscale_features();
        init_upscale_features();
        m_wants_reinitialize = false;
        return;
    }

    if (!ready() || !m_upscale) {
        return;
    }

    if (m_eye_states[0].scene_layer == nullptr) {
        return;
    }

    // P4: Cache render size — only re-query PDPerfPlugin when reinit flag is set
    if (m_wants_reinitialize || m_cached_render_size[0].load(std::memory_order_relaxed) == 0) {
        m_cached_render_size[0].store(get_render_width(), std::memory_order_relaxed);
        m_cached_render_size[1].store(get_render_height(), std::memory_order_relaxed);
    }

    if (m_is_d3d12) {
        auto& hook = g_framework->get_d3d12_hook();
        auto swapchain = hook->get_swap_chain();
        ComPtr<ID3D12Resource> backbuffer{};

        if (FAILED(swapchain->GetBuffer(swapchain->GetCurrentBackBufferIndex(), IID_PPV_ARGS(&backbuffer)))) {
            spdlog::error("[TemporalUpscaler] Failed to get backbuffer (D3D12)");
            return;
        }

        // P5: Removed unused device variable (was fetched but never referenced).
        auto bb_desc = backbuffer->GetDesc();

        m_backbuffer_size[0].store(bb_desc.Width, std::memory_order_relaxed);
        m_backbuffer_size[1].store(bb_desc.Height, std::memory_order_relaxed);

        auto& copier = m_copiers[swapchain->GetCurrentBackBufferIndex() % m_copiers.size()];
        // Batch1: bounded wait — INFINITE would deadlock the present thread forever
        // on a GPU hang or device removal; timing out just skips one frame's reclaim
        // and the next wait() retries (waiting_for_fence stays set).
        copier.wait(2000);

        // P3: Original code iterated m_eye_states with a for-loop but unconditionally
        // broke after i==0 (if (i > 0) break). The loop was dead code — only eye 0
        // was ever processed. Directly accessing m_eye_states[0] eliminates the
        // loop overhead, the i>0 branch, and the redundant if (i==0) guards.
        auto& state = m_eye_states[0];

        if (state.depth == nullptr) {
            spdlog::error("[TemporalUpscaler] Failed to get depth stencil (D3D12)");
        } else if (state.motion_vectors == nullptr) {
            spdlog::error("[TemporalUpscaler] Failed to get motion vectors (D3D12)");
        } else if (state.color == nullptr) {
            spdlog::error("[TemporalUpscaler] Failed to get color buffer (D3D12)");
        } else {
            const auto evaluate_id = get_evaluate_id(0);
            const auto evaluate_index = evaluate_id - 1;

            UpscaleParams params{};
            params.id = (int)evaluate_id;
            params.execute = true;
            params.reset = false;
            params.color = state.color.Get();
            params.motionVector = state.motion_vectors.Get();
            params.depth = state.depth.Get();
            params.mask = nullptr;
            params.destination = nullptr;
            params.motionScaleX = m_motion_scale[0];
            params.motionScaleY = m_motion_scale[1];
            params.renderSizeX = m_cached_render_size[0].load(std::memory_order_relaxed);
            params.renderSizeY = m_cached_render_size[1].load(std::memory_order_relaxed);
            params.jitterOffsetX = m_jitter_offsets[evaluate_index][0];
            params.jitterOffsetY = m_jitter_offsets[evaluate_index][1];
            params.sharpness = m_sharpness_amount->value();
            params.nearPlane = m_nearz;
            params.farPlane = m_farz;
            params.verticalFOV = m_fov;

            // Batch2 (experimental): hand the backbuffer to the plugin so DLSS
            // writes straight into it, skipping the fullscreen CopyResource.
            // Force-disabled while a frame-generation interposed swapchain is
            // active — the interposer owns the swapchain there and external
            // writes are unverified.
            const bool direct_output = m_direct_output->value() && !hook->is_framegen_swapchain();

            if (direct_output) {
                params.destination = backbuffer.Get();

                // Transition from the ACTUAL last-known state (not a hardcoded
                // PRESENT): if a previous frame's post-barrier was dropped
                // (fence-wait timeout -> closed list), the buffer is still in
                // UAV and this becomes a no-op, letting the state machine
                // self-heal within one frame instead of freezing forever.
                copier.transition(backbuffer.Get(), m_bb_output_state, D3D12_RESOURCE_STATE_UNORDERED_ACCESS);
                m_bb_output_state = D3D12_RESOURCE_STATE_UNORDERED_ACCESS;
                copier.execute();

                // Reopen the (now closed) command list once the tiny barrier
                // submission has retired, so the post-transition below can be
                // recorded. Fast path: returns immediately when already signaled.
                copier.wait(2000);
            }

            EvaluateUpscaler(&params);

            if (direct_output) {
                copier.transition(backbuffer.Get(), m_bb_output_state, D3D12_RESOURCE_STATE_PRESENT);
                m_bb_output_state = D3D12_RESOURCE_STATE_PRESENT;
            } else {
                // Restore any stale state left by a dropped direct-output
                // barrier before copying, so the copy path always starts from
                // the canonical PRESENT.
                if (m_bb_output_state != D3D12_RESOURCE_STATE_PRESENT) {
                    copier.transition(backbuffer.Get(), m_bb_output_state, D3D12_RESOURCE_STATE_PRESENT);
                    m_bb_output_state = D3D12_RESOURCE_STATE_PRESENT;
                }

                copier.copy((ID3D12Resource*)m_upscaled_textures[evaluate_index], backbuffer.Get(), D3D12_RESOURCE_STATE_UNORDERED_ACCESS, D3D12_RESOURCE_STATE_PRESENT);
            }
        }

        copier.execute();

        static bool once = true;

        if (once) {
            spdlog::info("Successfully rendered with TemporalUpscaler");
            once = false;
        }
    } else {
        // P3: D3D11 path — TemporalUpscaler only does upscaling on D3D12.
        // The original code obtained swapchain/device/context/backbuffer but
        // never used them (no EvaluateUpscaler call, no copy). All of that was
        // wasted COM reference counting. Just return.
    }
}

bool TemporalUpscaler::on_first_frame() {
    spdlog::info("[TemporalUpscaler] Initializing first frame...");

    m_first_frame_finished = true;
    m_is_d3d12 = g_framework->is_dx12();

    InitLogDelegate([](char* msg, int size) {
        spdlog::info("[TemporalUpscaler] {}", msg);
    });

    if (m_is_d3d12) {
        auto& hook = g_framework->get_d3d12_hook();
        SetupDirectX(hook->get_command_queue(), PDGraphicsAPI::D3D12);
    } else {
        auto& hook = g_framework->get_d3d11_hook();
        SetupDirectX(hook->get_device(), PDGraphicsAPI::D3D11);
    }

    if (!init_upscale_features()) {
        return false;
    }

    m_initialized = true;

    return true;
}

bool TemporalUpscaler::init_upscale_features() {
    spdlog::info("[TemporalUpscaler] Initializing upscale features...");

    uint32_t out_w = 0;
    uint32_t out_h = 0;
    uint32_t out_format = 0;

    if (m_is_d3d12) {
        auto& hook = g_framework->get_d3d12_hook();

        auto swapchain = hook->get_swap_chain();
        ComPtr<ID3D12Resource> backbuffer{};

        if (FAILED(swapchain->GetBuffer(swapchain->GetCurrentBackBufferIndex(), IID_PPV_ARGS(&backbuffer)))) {
            spdlog::error("[TemporalUpscaler] Failed to get backbuffer (D3D12)");
            return false;
        }

        // Get bb desc
        const auto bb_desc = backbuffer->GetDesc();

        m_backbuffer_size[0].store(bb_desc.Width, std::memory_order_relaxed);
        m_backbuffer_size[1].store(bb_desc.Height, std::memory_order_relaxed);
        m_bb_output_state = D3D12_RESOURCE_STATE_PRESENT;

        out_w = bb_desc.Width;
        out_h = bb_desc.Height;
        out_format = bb_desc.Format;

        for (auto& copier : m_copiers) {
            copier.setup();
        }
    } else {
        auto& hook = g_framework->get_d3d11_hook();

        auto swapchain = hook->get_swap_chain();
        auto device = hook->get_device();

        // Get the context.
        ComPtr<ID3D11DeviceContext> context{};
        device->GetImmediateContext(&context);

        // Get the back buffer.
        ComPtr<ID3D11Texture2D> backbuffer{};
        swapchain->GetBuffer(0, IID_PPV_ARGS(&backbuffer));

        if (backbuffer == nullptr) {
            spdlog::error("[TemporalUpscaler] Failed to get backbuffer (D3D11)");
            return false;
        }

        // Get bb desc
        D3D11_TEXTURE2D_DESC bb_desc{};
        backbuffer->GetDesc(&bb_desc);

        out_w = bb_desc.Width;
        out_h = bb_desc.Height;
        out_format = bb_desc.Format;
    }

    // Left eye.
    InitParams params{};
    params.id = get_evaluate_id(0);
    params.upscaleMethod = m_upscale_type;
    params.qualityLevel = m_upscale_quality->value();
    params.displaySizeX = out_w;
    params.displaySizeY = out_h;
    params.format = out_format;
    params.isContentHDR = false;
    params.depthInverted = true;
    params.YAxisInverted = false;
    params.motionVetorsJittered = false;
    params.enableSharpening = m_sharpness->value();
    params.enableAutoExposure = false;
    m_upscaled_textures[0] = InitUpscaler(&params);

    update_motion_scale();

    if (m_is_d3d12) {
        const auto desc = ((ID3D12Resource*)m_upscaled_textures[0])->GetDesc();

        spdlog::info("[TemporalUpscaler] Upscaled texture size: {}x{}", desc.Width, desc.Height);
    } else {
        ComPtr<ID3D11Texture2D> texture = (ID3D11Texture2D*)m_upscaled_textures[0];
        D3D11_TEXTURE2D_DESC desc{};
        texture->GetDesc(&desc);

        spdlog::info("[TemporalUpscaler] Upscaled texture size: {}x{}", desc.Width, desc.Height);
    }

    spdlog::info("[TemporalUpscaler] Wanted render resolution: {}x{}", GetRenderWidth(get_evaluate_id(0)), GetRenderHeight(get_evaluate_id(0)));
    spdlog::info("[TemporalUpscaler] Created upscaled texture(s)");

    return true;
}

void TemporalUpscaler::release_upscale_features() {
    if (m_upscaled_textures[0] == nullptr && m_upscaled_textures[1] == nullptr) {
        return;
    }

    // P3: Single-pass copier cleanup — wait then reset in one loop instead of two.
    for (auto& copier : m_copiers) {
        copier.wait(2000);
        copier.reset();
    }

    if (m_upscaled_textures[0] != nullptr) {
        ReleaseUpscaleFeature(get_evaluate_id(0));
        m_upscaled_textures[0] = nullptr;
    }

    if (m_upscaled_textures[1] != nullptr) {
        ReleaseUpscaleFeature(get_evaluate_id(1));
        m_upscaled_textures[1] = nullptr;
    }

    m_wants_reinitialize = true;
    m_camera_params_cached = false; // Force camera re-query after reinit
    m_output_layer = nullptr; // Force Output layer re-resolve after reinit
    m_cached_render_size[0].store(0, std::memory_order_relaxed); // Force render size re-query after reinit
    m_cached_render_size[1].store(0, std::memory_order_relaxed);
    
    for (auto& state : m_eye_states) {
        state.color.Reset();
        state.depth.Reset();
        state.motion_vectors.Reset();
        state.scene_layer = nullptr;

        state.color_copy.reset();
        state.depth_copy.reset();
        state.motion_vectors_copy.reset();
    }

    m_big_motion_vectors.Reset();
    m_big_depth.Reset();
    m_big_color.Reset();
}

void TemporalUpscaler::on_post_present() {
    m_rendering.store(false, std::memory_order_relaxed);

    if (!ready()) {
        return;
    }
}

void TemporalUpscaler::on_device_reset() {
    release_upscale_features();
    m_wants_reinitialize = true;
    // P6: Invalidate cached root layer — engine may rebuild the render pipeline
    m_cached_root_layer = nullptr;
    m_layer_rescan_counter = 0;
}

void TemporalUpscaler::on_view_get_size(REManagedObject* scene_view, float* result) {
    // Don't spoof resolution when the upscaler is disabled by the user.
    // We check m_enabled separately from ready() because ready() also returns
    // false during reinit frames (m_wants_reinitialize), and we must keep
    // spoofing during those frames to avoid a one-frame resolution mismatch.
    // The original condition (!ready() && (!m_rendering || !m_set_view))
    // correctly handled reinit frames (m_rendering is false at this point in
    // the frame, set by on_post_present), but failed to stop spoofing when the
    // user toggled m_enabled off, because m_rendering was set to true in
    // on_early_present before the ready() check, and m_set_view stayed true
    // from the last enabled frame — leaving the engine stuck at low resolution.
    if (!m_enabled->value()) {
        m_set_view.store(false, std::memory_order_relaxed);
        return;
    }

    if (!ready() && (!m_rendering.load(std::memory_order_relaxed) || !m_set_view.load(std::memory_order_relaxed))) {
        m_set_view.store(false, std::memory_order_relaxed);
        return;
    }

    // spoof the size to the HMD's size

    // P5: Use cached render size to avoid calling GetRenderWidth/Height
    // (each crosses a DLL boundary into PDPerfPlugin). The cache is refreshed
    // in on_early_present; when m_use_native_resolution is toggled, the cache
    // is invalidated there via m_cached_render_size=={0,0} check.
    if (m_cached_render_size[0].load(std::memory_order_relaxed) == 0 || m_cached_render_size[1].load(std::memory_order_relaxed) == 0) {
        m_cached_render_size[0].store(get_render_width(), std::memory_order_relaxed);
        m_cached_render_size[1].store(get_render_height(), std::memory_order_relaxed);
    }

    result[0] = (float)m_cached_render_size[0].load(std::memory_order_relaxed);
    result[1] = (float)m_cached_render_size[1].load(std::memory_order_relaxed);

    m_set_view.store(true, std::memory_order_relaxed);
}

void TemporalUpscaler::on_scene_layer_update(sdk::renderer::layer::Scene* layer, void* render_context) {
    if (!ready()) {
        return;
    }

    // P10: Fast reject non-target layers with a pointer compare before calling
    // expensive engine functions. is_fully_rendered() calls is_enabled() +
    // get_mirror() + has_main_camera() (3-5 engine function calls per layer).
    // Since m_eye_states[0].scene_layer was set by find_fully_rendered_scene_layers()
    // in on_pre_application_entry(EndRendering), any layer that isn't ours is
    // rejected by the pointer compare alone — no engine calls needed.
    if (layer != m_eye_states[0].scene_layer) {
        return;
    }

    // P5: Cache VariableDescriptor* to bypass per-frame hashmap + shared_lock.
    // get_field<T>(obj, string_view) internally calls get_field_desc which does
    // a string concat + unordered_map lookup under a shared_lock every call.
    // By caching the descriptor, we call get_field<T>(obj, desc) directly,
    // which just invokes desc->function — zero hashmap, zero locking.
    static auto scene_t = sdk::find_type_definition("via.render.layer.Scene")->get_type();
    static auto scene_info_desc = utility::re_type::get_field_desc(scene_t, "SceneInfo");
    static auto depth_distortion_desc = utility::re_type::get_field_desc(scene_t, "DepthDistortionSceneInfo");
    static auto filter_desc = utility::re_type::get_field_desc(scene_t, "FilterSceneInfo");
    static auto z_prepass_desc = utility::re_type::get_field_desc(scene_t, "ZPrepassSceneInfo");

    auto scene_info = utility::re_managed_object::get_field<sdk::renderer::SceneInfo*>((::REManagedObject*)layer, scene_info_desc);
    auto depth_distortion_scene_info = utility::re_managed_object::get_field<sdk::renderer::SceneInfo*>((::REManagedObject*)layer, depth_distortion_desc);
    auto filter_scene_info = utility::re_managed_object::get_field<sdk::renderer::SceneInfo*>((::REManagedObject*)layer, filter_desc);
    // P4: Skip jitter_disable_scene_info and jitter_disable_post_scene_info
    // — their names indicate they are explicitly for passes that should NOT be jittered.
    // Injecting jitter into them causes unnecessary matrix inversions and may produce
    // visual artifacts in those passes. Also avoids two get_field hashmap lookups per frame.
    auto z_prepass_scene_info = utility::re_managed_object::get_field<sdk::renderer::SceneInfo*>((::REManagedObject*)layer, z_prepass_desc);

    const auto evaluate_id = get_evaluate_id(0);
    const auto evaluate_index = evaluate_id - 1;

    // P5: Use cached render size instead of calling GetRenderWidth/Height every frame
    // (each call crosses a DLL boundary into PDPerfPlugin)
    const auto w = (float)m_cached_render_size[0].load(std::memory_order_relaxed);
    const auto h = (float)m_cached_render_size[1].load(std::memory_order_relaxed);

    float x = 0.0f;
    float y = 0.0f;

    if (m_jitter) {
        // Batch1 guard: on early frames this callback can fire before
        // on_early_present has filled the cache ({0,0}). Dividing by zero would
        // produce NaN/inf jitter injected into the engine's matrices, poisoning
        // DLSS input for that frame. Skipping the whole block is safe — the
        // matrix save below is purely a next-frame cache and refreshes next frame.
        if (w <= 0.0f || h <= 0.0f) {
            return;
        }

        // Batch1: GetJitterPhaseCount crosses a DLL boundary into PDPerfPlugin —
        // only call it when jitter is actually enabled (was previously unconditional).
        const auto phase = GetJitterPhaseCount(evaluate_id);

        m_jitter_indices[evaluate_index]++;
        GetJitterOffset(&x, &y, m_jitter_indices[evaluate_index], phase);

        m_jitter_offsets[evaluate_index][0] = -x;
        m_jitter_offsets[evaluate_index][1] = -y;

        // from FSR2 code
        x = m_jitter_scale[0] * (x / w);
        y = m_jitter_scale[1] * (y / h);
    } else {
        m_jitter_offsets[evaluate_index][0] = 0.0f;
        m_jitter_offsets[evaluate_index][1] = 0.0f;
    }

    auto add_jitter = [&](int32_t i, sdk::renderer::SceneInfo* scene_info) {
        if (scene_info == nullptr) {
            return;
        }

        this->m_old_projection_matrix[evaluate_index][i][2][0] += x;
        this->m_old_projection_matrix[evaluate_index][i][2][1] += y;

        scene_info->old_view_projection_matrix = this->m_old_projection_matrix[evaluate_index][i] * this->m_old_view_matrix[evaluate_index][i];

        this->m_old_projection_matrix[evaluate_index][i] = scene_info->projection_matrix;
        this->m_old_view_matrix[evaluate_index][i] = scene_info->view_matrix;

        scene_info->projection_matrix[2][0] += x;
        scene_info->projection_matrix[2][1] += y;
        scene_info->inverse_projection_matrix = glm::inverse(scene_info->projection_matrix);

        scene_info->view_projection_matrix = scene_info->projection_matrix * scene_info->view_matrix;
        scene_info->inverse_view_projection_matrix = glm::inverse(scene_info->view_projection_matrix);
    };

    // P5: When jitter is disabled, add_jitter would only update old matrices
    // with zero jitter — but still computes two 4x4 matrix inversions per call.
    // Skip entirely when m_jitter is false to save 8 matrix inversions per frame.
    if (m_jitter) {
        add_jitter(0, scene_info);
        add_jitter(1, depth_distortion_scene_info);
        add_jitter(2, filter_scene_info);
        add_jitter(3, z_prepass_scene_info);
    } else {
        // Still save current matrices for next frame, but skip the expensive inversions
        auto update_old_matrices = [&](int32_t i, sdk::renderer::SceneInfo* si) {
            if (si == nullptr) {
                return;
            }
            this->m_old_projection_matrix[evaluate_index][i] = si->projection_matrix;
            this->m_old_view_matrix[evaluate_index][i] = si->view_matrix;
        };
        update_old_matrices(0, scene_info);
        update_old_matrices(1, depth_distortion_scene_info);
        update_old_matrices(2, filter_scene_info);
        update_old_matrices(3, z_prepass_scene_info);
    }
}

void TemporalUpscaler::on_overlay_layer_draw(sdk::renderer::layer::Overlay* layer, void* render_context) {
    if (!ready() || !m_is_d3d12) {
        return;
    }

    auto context = (sdk::renderer::RenderContext*)render_context;
    auto scene_layer = (sdk::renderer::layer::Scene*)layer->get_parent();

    if (scene_layer == nullptr) {
        return;
    }

    // P3: Direct access m_eye_states[0] — the loop over m_eye_states was always
    // a single-iteration walk in non-VR mode (eye_states[1].scene_layer is nullptr).
    // Using continue+break is equivalent to a single if-check on eye_states[0].
    auto& state = m_eye_states[0];

    if (state.scene_layer != scene_layer) {
        return;
    }

    // P5: Cache VariableDescriptor* — get_depth_stencil() and get_motion_vectors_state()
    // each call get_field<T>(obj, string_view) which does a hashmap + shared_lock per call.
    static auto scene_t = sdk::find_type_definition("via.render.layer.Scene")->get_type();
    static auto depth_stencil_desc = utility::re_type::get_field_desc(scene_t, "DepthStencilTex");
    static auto velocity_target_desc = utility::re_type::get_field_desc(scene_t, "VelocityTarget");

    auto depth = utility::re_managed_object::get_field<::sdk::renderer::Texture*>((::REManagedObject*)scene_layer, depth_stencil_desc);

    if (depth != nullptr && state.depth_copy != nullptr) {
        context->copy_texture(state.depth_copy, depth);
    }

    auto motion_vectors_state = utility::re_managed_object::get_field<::sdk::renderer::TargetState*>((::REManagedObject*)scene_layer, velocity_target_desc);

    if (motion_vectors_state != nullptr && state.motion_vectors_copy != nullptr) {
        auto rtv = motion_vectors_state->get_rtv(0);

        if (rtv != nullptr) {
            if (auto motion_vectors = rtv->get_texture_d3d12(); motion_vectors != nullptr) {
                context->copy_texture(state.motion_vectors_copy, motion_vectors);
            }
        }
    }
}

void TemporalUpscaler::on_prepare_output_layer_draw(sdk::renderer::layer::PrepareOutput* layer, void* render_context) {
    if (!ready() || !m_is_d3d12) {
        return;
    }

    auto context = (sdk::renderer::RenderContext*)render_context;
    auto scene_layer = (sdk::renderer::layer::Scene*)layer->get_parent();

    if (scene_layer == nullptr) {
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

    // P3: Direct access m_eye_states[0] — see on_overlay_layer_draw for rationale.
    auto& state = m_eye_states[0];

    if (state.scene_layer != scene_layer) {
        return;
    }

    if (state.color_copy != nullptr) {
        context->copy_texture(state.color_copy, tex);
    }
}

bool TemporalUpscaler::on_pre_output_layer_draw(sdk::renderer::layer::Output* layer, void* render_context) {
    return true;
}

void TemporalUpscaler::on_output_layer_draw(sdk::renderer::layer::Output* layer, void* render_context) {
}

bool TemporalUpscaler::on_pre_output_layer_update(sdk::renderer::layer::Output* layer, void* render_context) {
    return true;
}

void TemporalUpscaler::on_pre_application_entry(void* entry, const char* name, size_t hash) {
    if (hash == "BeginRendering"_fnv) {
        finish_release_resources();
    }

    if (!ready()) {
        return;
    }

    if (hash == "BeginRendering"_fnv) {
        //update_extra_scene_layer();
    }

    if (hash == "EndRendering"_fnv) {
        fix_output_layer();
        m_output_layer_fixed_this_frame = true;

        // P6: Cache root layer to avoid per-frame get_native_singleton
        // (hashmap lookup + shared_lock + vtable call). Re-resolve every 60 frames
        // (same cadence as P4 scene layer rescan). find_layer_recursive still runs
        // per-frame (cheap pointer arithmetic) for a fresh output layer pointer.
        // The root layer is owned by the renderer singleton and persists for the
        // game's lifetime; only child layers get destroyed/recreated on scene changes.
        auto* root_layer = m_cached_root_layer;
        if (root_layer == nullptr || (m_layer_rescan_counter++ % 60 == 0)) {
            root_layer = sdk::renderer::get_root_layer();
            m_cached_root_layer = root_layer;
        }

        if (root_layer != nullptr) {
    // Resolve the Output layer via find_layer_recursive (cached REType*, cheap
    // pointer walk) from the persistent root layer, then re-scan scene layers
    // EVERY frame. The engine can destroy/recreate the scene layer tree between
    // frames (scene transitions, loading) without changing the Output layer
    // pointer, so caching a Scene* across frames is a use-after-free hazard
    // (this exact pattern was reverted once in bab6cd9a). find_fully_rendered_
    // scene_layers allocates a small vector per frame, which is cheap next to
    // the per-frame D3D12 work; the resulting Scene* is pinned into an
    // intrusive_ptr below, and D3D12 resources are still only re-fetched when
    // the selected scene layer actually changes.
    static auto output_layer_type = sdk::find_type_definition("via.render.layer.Output")->get_type();
    auto [output_parent, output_layer] = root_layer->find_layer_recursive(output_layer_type);

    auto* current_output_layer = (output_layer != nullptr && *output_layer != nullptr) ? *output_layer : nullptr;

    std::vector<sdk::renderer::layer::Scene*> valid_scene_layers;

    if (current_output_layer != nullptr) {
        m_output_layer = (decltype(m_output_layer))current_output_layer;
        valid_scene_layers = current_output_layer->find_fully_rendered_scene_layers();
    }

            if (valid_scene_layers.empty()) {
                m_eye_states[0].scene_layer = nullptr;
                m_eye_states[1].scene_layer = nullptr;
                return;
            }

            // Track if the scene layer changed so we know whether to re-fetch D3D12 resources
            auto* prev_scene_layer = m_eye_states[0].scene_layer.get();

            if (valid_scene_layers.size() > 1) {
                if (m_displayed_scene == 0) {
                    m_eye_states[0].scene_layer = valid_scene_layers[0];
                } else {
                    m_eye_states[0].scene_layer = valid_scene_layers[1];
                }

                m_eye_states[1].scene_layer = nullptr;
            } else {
                m_eye_states[0].scene_layer = valid_scene_layers[0];
                m_eye_states[1].scene_layer = nullptr;
            }

            // If scene layer changed, force D3D12 resource re-fetch
            bool scene_layer_changed = (prev_scene_layer != m_eye_states[0].scene_layer.get());
            if (scene_layer_changed) {
                m_eye_states[0].depth.Reset();
                m_eye_states[0].motion_vectors.Reset();
                m_eye_states[0].color.Reset();
            }

            if (m_output_layer == nullptr) {
                spdlog::error("[TemporalUpscaler] Failed to find output layer");
            }
        } else {
            spdlog::error("[TemporalUpscaler] Failed to get root layer");
            m_eye_states[0].scene_layer = nullptr;
            m_eye_states[1].scene_layer = nullptr;
            m_output_layer = nullptr;
            return;
        }

        // P4: Direct access m_eye_states[0] — eye[1] is always nullptr in non-VR.
        // Also skip the D3D11 branch entirely (already short-circuited above).
        auto& state = m_eye_states[0];

        if (state.scene_layer == nullptr) {
            state.depth.Reset();
            state.motion_vectors.Reset();
            state.color.Reset();
        } else {
            // P0: Cache D3D12 resources — only re-fetch when resources are missing
            // (scene layer changed or device reset triggers Reset() on these ComPtrs).
            if (state.depth == nullptr || state.motion_vectors == nullptr || state.color == nullptr) {
                static auto potype = sdk::find_type_definition("via.render.layer.PrepareOutput")->get_type();
                auto prepareoutput_layer = (sdk::renderer::layer::PrepareOutput**)state.scene_layer->find_layer(potype);

                if (prepareoutput_layer == nullptr) {
                    state.depth.Reset();
                    state.motion_vectors.Reset();
                    state.color.Reset();
                } else {
                    auto new_depth = state.scene_layer->get_depth_stencil_d3d12();
                    auto new_motion_vectors = state.scene_layer->get_motion_vectors_d3d12();

                    state.depth = new_depth;
                    state.motion_vectors = new_motion_vectors;

                    if (*prepareoutput_layer != nullptr) {
                        const auto current_target_state = (*prepareoutput_layer)->get_output_state();

                        if (current_target_state != nullptr) {
                            const auto new_color = current_target_state->get_native_resource_d3d12();
                            state.color = new_color;
                        } else {
                            state.color.Reset();
                        }
                    } else {
                        state.color.Reset();
                    }
                }
            }
        }

        // m_eye_states[1] is always nullptr in non-VR — skip entirely.
        m_eye_states[1].depth.Reset();
        m_eye_states[1].motion_vectors.Reset();
        m_eye_states[1].color.Reset();

        // P1: Throttle camera/render-config queries to every N frames
        bool need_camera_update = !m_camera_params_cached || (m_frame_counter % CAMERA_SAMPLE_INTERVAL == 0);
        m_frame_counter++;

        if (need_camera_update) {
            m_camera_params_cached = true;

            auto camera = sdk::get_primary_camera();

            if (camera == nullptr) {
                m_camera_params_cached = false;
                return;
            }

            static auto via_camera = sdk::find_type_definition("via.Camera");
            static auto get_near_clip_plane_method = via_camera->get_method("get_NearClipPlane");
            static auto get_far_clip_plane_method = via_camera->get_method("get_FarClipPlane");
            static auto get_projection_matrix_method = via_camera->get_method("get_ProjectionMatrix");

            auto context = sdk::get_thread_context();
            m_nearz = get_near_clip_plane_method->call<float>(context, camera);
            m_farz = get_far_clip_plane_method->call<float>(context, camera);

            Matrix4x4f projection_matrix{};
            get_projection_matrix_method->call<void>(&projection_matrix, context, camera);
            m_fov = 2.0f * std::atan(1.0f / projection_matrix[1][1]);

            static auto renderer_t = sdk::find_type_definition("via.render.Renderer");
            static auto render_config_t = sdk::find_type_definition("via.render.RenderConfig");
            static auto get_render_config_method = renderer_t->get_method("get_RenderConfig");

            static auto get_antialiasing_method = render_config_t->get_method("get_AntiAliasing");
            static auto set_antialiasing_method = render_config_t->get_method("set_AntiAliasing");

            static auto get_image_quality_rate_method = render_config_t->get_method("get_ImageQualityRate");
            static auto set_image_quality_rate_method = render_config_t->get_method("set_ImageQualityRate");

            auto renderer = renderer_t->get_instance();
            auto render_config = get_render_config_method->call<::REManagedObject*>(context, renderer);
            const auto antialiasing = get_antialiasing_method->call<via::render::RenderConfig::AntiAliasingType>(context, render_config);

            // Save the original AA mode before we override it, so we can restore
            // it when the upscaler is disabled.
            if (!m_taa_disabled && (antialiasing == via::render::RenderConfig::AntiAliasingType::TAA || antialiasing == via::render::RenderConfig::AntiAliasingType::FXAA_TAA)) {
                m_original_antialiasing = antialiasing;
            }

            // Disable TAA
            switch (antialiasing) {
                case via::render::RenderConfig::AntiAliasingType::TAA: [[fallthrough]];
                case via::render::RenderConfig::AntiAliasingType::FXAA_TAA:
                    if (!m_allow_taa) {
                        set_antialiasing_method->call<void*>(context, render_config, via::render::RenderConfig::AntiAliasingType::NONE);
                        m_taa_disabled = true;
                        spdlog::info("[TemporalUpscaler] TAA disabled");
                    }

                    break;
                case via::render::RenderConfig::AntiAliasingType::NONE:
                    if (m_allow_taa) {
                        set_antialiasing_method->call<void*>(context, render_config, via::render::RenderConfig::AntiAliasingType::TAA);
                    }

                    break;
                default:
                    break;
            }

            // It's necessary to force the image quality to 1.0 otherwise
            // the motion & depth buffers become misaligned with the color buffer
            if (get_image_quality_rate_method != nullptr) {
                const auto image_quality_rate = get_image_quality_rate_method->call<float>(context, render_config);

                if (image_quality_rate != 1.0f) {
                    set_image_quality_rate_method->call<void*>(context, render_config, 1.0f);
                    spdlog::info("[TemporalUpscaler] Image quality rate set to 1.0");
                }
            }
        }
    }
}

void TemporalUpscaler::on_application_entry(void* entry, const char* name, size_t hash) {
    if (!ready()) {
        return;
    }

    if (hash == "EndRendering"_fnv) {
        // P2: Skip if fix_output_layer already ran in the pre-entry phase this frame
        if (!m_output_layer_fixed_this_frame) {
            fix_output_layer();
        }
        m_output_layer_fixed_this_frame = false;
    }
}

void TemporalUpscaler::fix_output_layer() {
    if (m_last_output_layer != nullptr && m_cloned_output_layer != nullptr && m_original_output_layer != nullptr) {
        const auto current_state = *(sdk::renderer::TargetState**)((uintptr_t)m_last_output_layer + 0x88);

        if (current_state != m_last_output_state) {
            spdlog::info("[TemporalUpscaler] Output layer state changed!");

            if (m_last_output_layer != m_original_output_layer) {
                *(sdk::renderer::TargetState**)((uintptr_t)m_original_output_layer + 0x88) = m_last_output_state;
            } else {
                *(sdk::renderer::TargetState**)((uintptr_t)m_cloned_output_layer + 0x88) = m_last_output_state;
            }

            m_last_output_state = current_state;
        }
    }
}

void TemporalUpscaler::update_extra_scene_layer() {
    return;
}

uint32_t TemporalUpscaler::get_render_width() const {
    if (m_use_native_resolution->value()) {
        // we subtract 1 from the native res because
        // the game will create a separate color buffer we can use
        // otherwise it will be null.
        return m_backbuffer_size[0].load(std::memory_order_relaxed) - 1;
    }

    return GetRenderWidth(get_evaluate_id(0));
}

uint32_t TemporalUpscaler::get_render_height() const {
    if (m_use_native_resolution->value()) {
        return m_backbuffer_size[1].load(std::memory_order_relaxed) - 1;
    }
    
    return GetRenderHeight(get_evaluate_id(0));
}

void TemporalUpscaler::on_render_resource_release(sdk::renderer::RenderResource* resource) {
    if (resource == nullptr) {
        return;
    }

    {
        std::scoped_lock _{m_queued_release_resources_mutex};
        m_queued_release_resources.push_back(resource);
    }
    m_has_queued_release_resources.store(true, std::memory_order_release);

    //if (resource->m_ref_count == 1) {
    //    m_queued_release_resources.push_back(resource);
    /*} else {
        const auto original = m_render_resource_release_hook->get_original<decltype(render_resource_release_hook)>();
        original(resource);
    }*/
}

void TemporalUpscaler::finish_release_resources() {
    if (!m_hooked_resource_release) {
        return;
    }

    // P5: Lock-free fast path — most frames have no queued resources.
    // Avoids acquiring the recursive_mutex on every BeginRendering entry.
    if (!m_has_queued_release_resources.load(std::memory_order_acquire)) {
        return;
    }

    std::scoped_lock _{m_queued_release_resources_mutex};

    if (!m_queued_release_resources.empty()) {
        const auto original = m_render_resource_release_hook->get_original<decltype(render_resource_release_hook)>();

        for (auto resource : m_queued_release_resources) {
            original(resource);
        }

        m_queued_release_resources.clear();
    }

    m_has_queued_release_resources.store(false, std::memory_order_release);
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

    SetMotionScaleX(get_evaluate_id(0), (float)m_motion_scale[0]);
    SetMotionScaleY(get_evaluate_id(0), (float)m_motion_scale[1]);
}

void TemporalUpscaler::render_resource_release_hook(sdk::renderer::RenderResource* resource) {
    TemporalUpscaler::get()->on_render_resource_release(resource);
}
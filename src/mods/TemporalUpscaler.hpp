#pragma once

#include <array>
#include <atomic>
#include <chrono>
#include <string>
#include <utility>
#include <vector>

#include <sdk/intrusive_ptr.hpp>

#include "utility/d3d12/CommandContext.hpp"
#include "Mod.hpp"

namespace sdk {
namespace renderer {
class RenderLayer;

namespace layer {
class Scene;
}
}
}

// Upscales the game's render output through PDPerfPlugin.dll (UpscalerBasePlugin) with
// DLSS / FSR2 / XeSS.
//
// Scope of this module:
//   * DirectX 12 only. There is no D3D11 path: the D3D11 branch never produced output,
//     it only queried the backbuffer description for a log line.
//   * A single view. There is no VR here, so the plugin's evaluate id and every piece
//     of per-view state are single values (VIEW_ID / m_view) instead of arrays indexed
//     by a computed eye index.
class TemporalUpscaler : public Mod {
public:
    static std::shared_ptr<TemporalUpscaler>& get();

    std::string_view get_name() const { return "TemporalUpscaler"; }

    std::optional<std::string> on_initialize() override;

    void on_config_load(const utility::Config& cfg) override;
    void on_config_save(utility::Config& cfg) override;

    void on_draw_ui() override;
    void on_early_present() override; // early because it needs to run before VR.
    void on_post_present() override;
    void on_device_reset() override;

    void on_pre_application_entry(void* entry, const char* name, size_t hash) override;

    void on_view_get_size(REManagedObject* scene_view, float* result) override;

    void on_scene_layer_update(sdk::renderer::layer::Scene* scene_layer, void* render_context) override;

    void on_overlay_layer_draw(sdk::renderer::layer::Overlay* overlay_layer, void* render_context) override;

    void on_prepare_output_layer_draw(sdk::renderer::layer::PrepareOutput* layer, void* render_context) override;

    bool ready() const {
        return m_initialized && m_backend_loaded && m_enabled->value() && !m_wants_reinitialize;
    }

    bool activated() const {
        return m_initialized && m_backend_loaded && m_enabled->value();
    }

    // Graphics API ids expected by PDPerfPlugin. Only D3D12 is ever used here; D3D11 is
    // spelled out to keep the value of D3D12 correct.
    enum PDGraphicsAPI {
        D3D11 = 0,
        D3D12 = 1,
    };

    enum PDUpscaleType {
        DLSS,
        FSR2,
        XESS
    };

    enum PDPerfQualityLevel {
        Performance,
        Balanced,
        Quality,
        UltraPerformance
    };

private:
    template <typename T> using ComPtr = Microsoft::WRL::ComPtr<T>;

    // The single view this module upscales. VIEW_ID is the id the plugin keys its own
    // state (jitter phase, motion scale, upscaled texture) by.
    static constexpr uint32_t VIEW_ID{1};

    static constexpr auto FIRST_FRAME_RETRY_TIMEOUT{std::chrono::seconds{5}};
    static constexpr uint32_t FIRST_FRAME_RETRY_INTERVAL{60};
    static constexpr uint32_t CAMERA_SAMPLE_INTERVAL{15};
    static constexpr uint32_t RENDER_CONFIG_SAMPLE_INTERVAL{120};
    static constexpr uint32_t LAYER_RESCAN_INTERVAL{60};
    static constexpr uint32_t WARN_INTERVAL{600};
    static constexpr uint32_t COMMAND_CONTEXT_WAIT_MS{2000};

    // SceneInfo objects that receive jitter. The enumerators are used directly as indices
    // into ViewState's old_*_matrix arrays, so they also define their size.
    //
    // jitter_disable_scene_info and jitter_disable_post_scene_info are deliberately NOT
    // included: those passes must not be jittered, and injecting jitter into them costs
    // extra matrix inversions and can produce artifacts.
    enum SceneInfoSlot : size_t {
        SLOT_SCENE_INFO = 0,
        SLOT_DEPTH_DISTORTION,
        SLOT_FILTER,
        SLOT_Z_PREPASS,
        SLOT_COUNT
    };

    // Everything belonging to the view being upscaled.
    struct ViewState {
        ViewState() {
            // glm matrices are not initialized by their default constructor, and the first
            // jittered frame adds to the old matrices before it overwrites them, so start
            // them at identity instead of reading uninitialized memory once.
            old_projection_matrix.fill(Matrix4x4f{1.0f});
            old_view_matrix.fill(Matrix4x4f{1.0f});
        }

        sdk::intrusive_ptr<sdk::renderer::layer::Scene> scene_layer{};

        // D3D12 resources of the current scene layer, re-fetched only when missing.
        ComPtr<ID3D12Resource> motion_vectors{};
        ComPtr<ID3D12Resource> depth{};
        ComPtr<ID3D12Resource> color{};

        // Engine-owned copies of those inputs, created by the engine's render context.
        sdk::intrusive_ptr<sdk::renderer::Texture> color_copy{};
        sdk::intrusive_ptr<sdk::renderer::Texture> motion_vectors_copy{};
        sdk::intrusive_ptr<sdk::renderer::Texture> depth_copy{};

        uint32_t jitter_index{};
        std::array<float, 2> jitter_offset{0.0f, 0.0f}; // last offset handed to the plugin

        std::array<Matrix4x4f, SLOT_COUNT> old_projection_matrix{};
        std::array<Matrix4x4f, SLOT_COUNT> old_view_matrix{};

        // Drops the cached D3D12 inputs so the next frame re-fetches them.
        void reset_inputs() {
            motion_vectors.Reset();
            depth.Reset();
            color.Reset();
        }

        void reset() {
            reset_inputs();
            scene_layer.reset();
            color_copy.reset();
            motion_vectors_copy.reset();
            depth_copy.reset();
        }
    };

    // Warnings for missing upscaler inputs, indexed by WarnSource.
    enum WarnSource : size_t { WARN_BACKBUFFER = 0, WARN_DEPTH, WARN_MOTION_VECTORS, WARN_COLOR, WARN_COUNT };
    void warn_missing_input(WarnSource source);

    // Frame flow.
    bool on_first_frame();
    // Returns true once the first frame has been initialized, retrying on a throttle and
    // giving up after FIRST_FRAME_RETRY_TIMEOUT of wall-clock failures.
    bool ensure_first_frame();
    bool init_upscale_features();
    void release_upscale_features();

    // Per-frame queries, all from on_pre_application_entry(EndRendering).
    // Re-resolves the fully rendered scene layer and its D3D12 inputs. Returns false when
    // the engine has no usable layer this frame, in which case the caller must skip the
    // rest of the frame's work.
    bool resolve_scene_layer();
    void ensure_d3d12_inputs();
    void update_camera_params();
    void sync_render_config();

    // Caches.
    // Single invalidation point for everything that survives across frames. Must be
    // called after anything that can change the swapchain, the render size, the layer
    // tree or the upscaler's inputs.
    void invalidate_caches();
    void invalidate_render_size();
    void refresh_cached_render_size();
    // Cached swapchain backbuffer for the given index, filling the cache (and
    // m_backbuffer_size) on first access.
    ID3D12Resource* get_backbuffer_d3d12(uint32_t index);
    uint32_t get_render_width() const;
    uint32_t get_render_height() const;
    void update_motion_scale();

    // UI.
    // Applies whatever the user changed in on_draw_ui, in one place.
    void apply_setting_changes();
    void restore_engine_aa();

    bool m_initialized{false};
    bool m_backend_loaded{false};
    // SetupDirectX/InitLogDelegate are once-per-session plugin-global setup; the retry
    // path can invoke on_first_frame many times, so they are guarded by this flag. Set
    // only after SetupDirectX succeeds, so a failed setup is itself retried.
    bool m_directx_setup_done{false};
    bool m_first_frame_finished{false};
    uint32_t m_first_frame_retry_count{0};
    // Time-based give-up budget for first-frame/reinit retries: frame counts do not map to
    // wall time (loading screens can run at single-digit fps). Default-constructed (epoch)
    // means "no failure in progress"; reset on every successful init so a later reinit
    // failure gets a fresh budget.
    std::chrono::steady_clock::time_point m_first_frame_failure_start{};

    bool m_upscale{true};
    bool m_jitter{true};
    bool m_allow_taa{false}; // the engine's own TAA can't be used together with the upscaler
    bool m_taa_disabled{false};
    via::render::RenderConfig::AntiAliasingType m_original_antialiasing{via::render::RenderConfig::AntiAliasingType::NONE};
    bool m_wants_reinitialize{false};
    bool m_logged_first_evaluate{false};

    // Written by the present thread (on_early_present/on_post_present) and read/written by
    // the render thread (on_view_get_size). relaxed ordering suffices: nothing is
    // published through these flags, only their own values are consumed.
    std::atomic<bool> m_rendering{false};
    std::atomic<bool> m_set_view{false};
    // Render size, cached to avoid per-call PDPerfPlugin queries. Zero means "re-query".
    std::array<std::atomic<uint32_t>, 2> m_cached_render_size{};
    std::array<std::atomic<uint32_t>, 2> m_backbuffer_size{};

    std::array<uint32_t, WARN_COUNT> m_missing_input_warn_counters{};

    uint32_t m_frame_counter{0};
    bool m_camera_params_cached{false};
    bool m_render_config_cached{false};
    sdk::renderer::RenderLayer* m_cached_root_layer{nullptr};
    uint32_t m_layer_rescan_counter{0};

    // Available upscalers in plugin-enum order; m_available_upscale_type is the index the
    // UI combo shows. m_combo_labels holds ImGui-facing c_str() pointers and is built once
    // after m_methods is final (it is never modified afterwards, so they stay valid).
    std::vector<std::pair<std::string, PDUpscaleType>> m_methods{};
    std::vector<const char*> m_combo_labels{};
    uint32_t m_available_upscale_type{0};
    PDUpscaleType m_upscale_type{PDUpscaleType::FSR2};

    // Tracks the resource state the backbuffer was last left in, so a dropped barrier
    // (fence-wait timeout -> closed command list) cannot permanently desync the state
    // machine: the next frame always transitions from the real state and self-heals.
    D3D12_RESOURCE_STATES m_bb_output_state{D3D12_RESOURCE_STATE_PRESENT};

    // Owned by PDPerfPlugin, never Release()d — which is why this is a raw pointer.
    ID3D12Resource* m_upscaled_texture{nullptr};

    ViewState m_view{};

    // Reused buffer for the per-frame find_fully_rendered_scene_layers scan (avoids a
    // vector allocation every frame on the render thread).
    std::vector<sdk::renderer::layer::Scene*> m_valid_scene_layers{};

    int32_t m_displayed_scene{0}; // 0 = first fully rendered scene layer, 1 = second

    float m_nearz{0.0f};
    float m_farz{0.0f};
    float m_fov{90.0f};

    float m_jitter_scale[2]{2.0f, -2.0f};
    float m_motion_scale[2]{-1.0f, 1.0f};

    std::array<d3d12::CommandContext, 3> m_copiers{};

    // Cached swapchain backbuffers, indexed by GetCurrentBackBufferIndex(). Swapchain
    // buffers are stable until ResizeBuffers, which always routes through REFramework's
    // on_resize_buffers -> on_reset -> on_device_reset, where this cache is invalidated.
    // 16 covers DXGI's maximum BufferCount.
    std::array<ComPtr<ID3D12Resource>, 16> m_backbuffers{};

    const ModToggle::Ptr m_enabled{
        ModToggle::create(generate_name("Enabled"), true)
    };

    const ModToggle::Ptr m_sharpness{
        ModToggle::create(generate_name("SharpnessEnable"), true)
    };

    const ModSlider::Ptr m_sharpness_amount{
        ModSlider::create(generate_name("SharpnessAmount"), 0.0f, 5.0f, 0.0f)
    };

    const ModToggle::Ptr m_use_native_resolution{
        ModToggle::create(generate_name("UseNativeResolution"), false)
    };

    const ModCombo::Ptr m_upscale_quality{ 
        ModCombo::create(generate_name("UpscaleQuality"),
        {
            "Performance",
            "Balanced",
            "Quality",
            "Ultra Performance"
        }, (int32_t)PDPerfQualityLevel::Balanced) 
    };

    // Hands the swapchain backbuffer to the plugin as its destination, skipping the
    // fullscreen CopyResource. Default OFF — see on_early_present for the safety guards.
    const ModToggle::Ptr m_direct_output{
        ModToggle::create(generate_name("DirectOutput"), false)
    };

    ValueList m_options{
        *m_enabled,
        *m_sharpness,
        *m_sharpness_amount,
        *m_use_native_resolution,
        *m_upscale_quality,
        *m_direct_output
    };
};

#pragma once

#include <array>
#include <atomic>
#include <chrono>
#include <utility/FunctionHook.hpp>
#include <sdk/intrusive_ptr.hpp>

#include "utility/d3d12/CommandContext.hpp"
#include "utility/d3d12/TextureContext.hpp"
#include "Mod.hpp"

namespace sdk {
namespace renderer {
class RenderLayer;

namespace layer {
class Scene;
}
}
}

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
    void on_application_entry(void* entry, const char* name, size_t hash) override;

    void on_view_get_size(REManagedObject* scene_view, float* result) override;

    void on_scene_layer_update(sdk::renderer::layer::Scene* scene_layer, void* render_context) override;
    
    void on_overlay_layer_draw(sdk::renderer::layer::Overlay* overlay_layer, void* render_context) override;
    
    void on_prepare_output_layer_draw(sdk::renderer::layer::PrepareOutput* layer, void* render_context) override;

    bool on_pre_output_layer_draw(sdk::renderer::layer::Output* layer, void* render_context) override;
    bool on_pre_output_layer_update(sdk::renderer::layer::Output* layer, void* render_context) override;
    void on_output_layer_draw(sdk::renderer::layer::Output* layer, void* render_context) override;

    bool ready() const {
        return m_initialized && m_backend_loaded && m_enabled->value() && !m_wants_reinitialize;
    }

    bool activated() const {
        return m_initialized && m_backend_loaded && m_enabled->value();
    }

    uint32_t get_evaluate_id(uint32_t counter) const {
        return (counter % 2) + 1;
    }

    template<typename T>
    T* get_upscaled_texture(int32_t index) {
        if (index < 0 || index >= m_upscaled_textures.size()) {
            return nullptr;
        }

        return (T*)m_upscaled_textures[index];
    }

    enum PDGraphicsAPI {
        D3D11,
        D3D12,
        VULKAN
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

    bool on_first_frame();
    bool init_upscale_features();
    void release_upscale_features();
    void fix_output_layer();
    void update_extra_scene_layer();
    uint32_t get_render_width() const;
    uint32_t get_render_height() const;
    void update_motion_scale();
    // Returns the cached swapchain backbuffer for the given index, filling the
    // cache (and m_backbuffer_size) on first access. Avoids a per-frame
    // GetBuffer COM round-trip on the present thread.
    ID3D12Resource* get_backbuffer_d3d12(uint32_t index);

    void on_render_resource_release(sdk::renderer::RenderResource* resource);
    void finish_release_resources();
    static void render_resource_release_hook(sdk::renderer::RenderResource* resource);
    std::unique_ptr<FunctionHook> m_render_resource_release_hook{};
    std::vector<sdk::renderer::RenderResource*> m_queued_release_resources{};
    std::recursive_mutex m_queued_release_resources_mutex{};
    std::atomic<bool> m_has_queued_release_resources{false}; // P5: lock-free fast path for finish_release_resources

    bool m_first_frame_finished{false};
    uint32_t m_first_frame_retry_count{0}; // throttled retry counter for first-frame/reinit failures
    // Time-based give-up budget for first-frame/reinit retries (frame counts
    // don't map to wall time — loading screens can run at single-digit fps).
    // Default-constructed (epoch) means "no failure in progress"; reset on
    // every successful init so a later reinit failure gets a fresh budget.
    // 5s is generous: transient startup failures (swapchain/backbuffer not
    // ready) resolve within the first few frames, so anything longer is a
    // permanent problem and just spams SetupDirectX retries + logs.
    static constexpr auto FIRST_FRAME_RETRY_TIMEOUT{std::chrono::seconds{5}};
    std::chrono::steady_clock::time_point m_first_frame_failure_start{};
    // Per-message throttles for the per-frame "missing backbuffer/depth/MV/color"
    // error logs — one counter each so a frequently-failing input can't starve
    // the other messages. Indexed by WarnSource.
    enum WarnSource : size_t { WARN_BACKBUFFER = 0, WARN_DEPTH, WARN_MOTION_VECTORS, WARN_COLOR, WARN_COUNT };
    std::array<uint32_t, WARN_COUNT> m_missing_input_warn_counters{};
    bool m_initialized{false};
    bool m_is_d3d12{false};
    // SetupDirectX/InitLogDelegate are once-per-session plugin-global setup
    // (the original code ran on_first_frame exactly once, and even device
    // resets never re-called SetupDirectX). The retry path can invoke
    // on_first_frame many times, so these are guarded by this flag and only
    // init_upscale_features() is retried. Set only after SetupDirectX
    // succeeds, so a failed setup is itself retried.
    bool m_directx_setup_done{false};
    bool m_backend_loaded{false};
    bool m_backbuffer_inconsistency{false};
    bool m_upscale{true};
    // Batch1: written by the present thread (on_early_present/on_post_present),
    // read/written by the render thread (on_view_get_size) — plain bools were
    // a cross-thread data race (UB). relaxed ordering suffices: no other data
    // is published through these flags, only their own values are consumed.
    std::atomic<bool> m_rendering{false};
    std::atomic<bool> m_set_view{false};
    bool m_jitter{true};
    bool m_allow_taa{false}; // the engine has its own TAA implementation, it can't be used with the upscaler
    bool m_taa_disabled{false}; // true after we've set AntiAliasing to NONE
    via::render::RenderConfig::AntiAliasingType m_original_antialiasing{via::render::RenderConfig::AntiAliasingType::NONE};
    bool m_wants_reinitialize{false};
    bool m_made_extra_scene_layer{false};
    bool m_hooked_resource_release{false};

    // P0: cache for Output layer to avoid per-frame recursive traversal
    // Scene layers are still re-resolved every frame (engine can destroy/recreate them)
    uint32_t m_frame_counter{0};

    // P1: throttle camera/render-config queries. Reflection calls through the
    // engine's type system are an order of magnitude more expensive than normal
    // calls, so both are sampled at separate intervals: camera near/far/FOV
    // rarely change (only on zoom), and the render-config AA/image-quality
    // assertion almost never needs re-applying mid-session.
    static constexpr uint32_t CAMERA_SAMPLE_INTERVAL{15};
    static constexpr uint32_t RENDER_CONFIG_SAMPLE_INTERVAL{120};
    bool m_camera_params_cached{false};
    bool m_render_config_cached{false};

    // P2: dedup fix_output_layer
    bool m_output_layer_fixed_this_frame{false};

    // P6: cache root layer to avoid per-frame get_native_singleton
    // (hashmap lookup + shared_lock + vtable call). Re-resolve every 60 frames.
    // Only the root layer (owned by the persistent renderer singleton) is cached;
    // the Output layer and scene layers are re-resolved every frame because the
    // engine can destroy/recreate them between frames.
    sdk::renderer::RenderLayer* m_cached_root_layer{nullptr};
    uint32_t m_layer_rescan_counter{0};

    // P4: cache render size to avoid per-frame PDPerfPlugin DLL calls.
    // Batch1: written by present thread, read/written by render thread — atomic.
    std::array<std::atomic<uint32_t>, 2> m_cached_render_size{};

    std::unordered_map<std::string, size_t> m_available_upscale_methods{};
    std::vector<std::string> m_available_upscale_method_names{};
    std::vector<const char*> m_imgui_combo_names{};
    std::array<uint32_t, 2> m_jitter_indices{0, 0};

    uint32_t m_available_upscale_type{0};
    PDUpscaleType m_upscale_type{PDUpscaleType::FSR2};

    uint32_t m_backbuffer_inconsistency_start{};
    // Batch1: written by present thread, read by UI/render threads — atomic.
    std::array<std::atomic<uint32_t>, 2> m_backbuffer_size{};

    // Batch2: tracks the resource state we last left the backbuffer in, so a
    // dropped post-barrier (e.g. after a fence-wait timeout closed the command
    // list) can't permanently desync the barrier state machine — the next
    // frame always transitions from the real state and self-heals.
    D3D12_RESOURCE_STATES m_bb_output_state{D3D12_RESOURCE_STATE_PRESENT};

    std::array<void*, 2> m_upscaled_textures{nullptr, nullptr};

    sdk::renderer::layer::Scene* m_cloned_scene_layer{nullptr};
    sdk::renderer::layer::Output* m_output_layer{nullptr};
    sdk::renderer::layer::Output* m_original_output_layer{nullptr};
    sdk::renderer::layer::Output* m_cloned_output_layer{nullptr};
    sdk::renderer::layer::Output* m_last_output_layer{nullptr};
    sdk::renderer::TargetState* m_last_output_state{nullptr};
    sdk::renderer::ConstantBuffer* m_original_scene_info_buffer{};
    sdk::renderer::ConstantBuffer* m_cloned_scene_info_buffer{};

    sdk::renderer::TargetState* m_new_target_state{nullptr};


    struct EyeState {
        sdk::intrusive_ptr<sdk::renderer::layer::Scene> scene_layer{};
        ComPtr<ID3D12Resource> motion_vectors{};
        ComPtr<ID3D12Resource> depth{};
        ComPtr<ID3D12Resource> color{};

        sdk::intrusive_ptr<sdk::renderer::Texture> color_copy{};
        sdk::intrusive_ptr<sdk::renderer::Texture> motion_vectors_copy{};
        sdk::intrusive_ptr<sdk::renderer::Texture> depth_copy{};
    };

    std::array<EyeState, 2> m_eye_states{};

    // Reused buffer for the per-frame find_fully_rendered_scene_layers scan
    // (avoids a vector allocation every frame on the render thread).
    std::vector<sdk::renderer::layer::Scene*> m_valid_scene_layers{};

    // 3 giant textures to encapsulate the motion vectors, depth, and color buffers
    // because the upscaler needs them all in one texture
    // well... it doesn't necessarily need them
    // but it causes some insane lag if using multiple features to evaluate multiple textures
    // so this is the best solution for now
    ComPtr<ID3D12Resource> m_big_motion_vectors{};
    ComPtr<ID3D12Resource> m_big_depth{};
    ComPtr<ID3D12Resource> m_big_color{};

    ComPtr<ID3D12Resource> m_blank_big_motion_vectors{};
    ComPtr<ID3D12Resource> m_blank_big_depth{};
    ComPtr<ID3D12Resource> m_blank_big_color{};

    int32_t m_displayed_scene{0}; // 0 = original, 1 = cloned

    float m_nearz{0.0f};
    float m_farz{0.0f};
    float m_fov{90.0f};

    float m_jitter_offsets[2][2]{0.0f, 0.0f};
    float m_jitter_scale[2]{2.0f, -2.0f};
    float m_motion_scale[2]{-1.0f, 1.0f};
    float m_jitter_evaluate_scale{1.0f};

    std::array<d3d12::CommandContext, 3> m_copiers{};
    ComPtr<ID3D12Resource> m_old_backbuffer{};

    // Cached swapchain backbuffers, indexed by GetCurrentBackBufferIndex().
    // Swapchain buffers are stable until ResizeBuffers, which always routes
    // through REFramework's on_resize_buffers -> on_reset -> on_device_reset,
    // where this cache is invalidated. 16 covers DXGI's maximum BufferCount.
    std::array<ComPtr<ID3D12Resource>, 16> m_backbuffers{};

    std::array<std::array<Matrix4x4f, 6>, 2> m_old_projection_matrix{};
    std::array<std::array<Matrix4x4f, 6>, 2> m_old_view_matrix{};

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

    // Batch2 (experimental): pass the swapchain backbuffer as the upscaler's
    // destination, eliminating the fullscreen CopyResource. Default OFF —
    // see on_early_present for the safety guards.
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
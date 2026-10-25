#pragma once

#include <atomic>
#include <chrono>
#include <unordered_map>

#include <sdk/intrusive_ptr.hpp>
#include <sdk/ManagedObject.hpp>
#include <sdk/renderer/PipelineState.hpp>

#include "Mod.hpp"

class REManagedObject;
class REComponent;

class Graphics : public Mod {
public:
    static std::shared_ptr<Graphics>& get();

public:
    std::optional<std::string> on_initialize() override;

    std::string_view get_name() const override { return "Graphics"; };

    void on_lua_state_created(sol::state& lua) override;
    void on_config_load(const utility::Config& cfg) override;
    void on_config_save(utility::Config& cfg) override;

    void on_frame() override;
    void on_draw_ui() override;
    void on_present() override;

    void on_pre_application_entry(void* entry, const char* name, size_t hash) override;
    void on_application_entry(void* entry, const char* name, size_t hash) override;

    bool on_pre_gui_draw_element(REComponent* gui_element, void* primitive_context) override;
    void on_view_get_size(REManagedObject* scene_view, float* result) override;

    void on_scene_layer_update(sdk::renderer::layer::Scene* layer, void* render_context) override;

    bool is_ultrawide_fix_enabled() const {
        return m_ultrawide_fix->value();
    }


private:
    void fix_ui_element(REComponent* gui_element);
    void do_scope_tweaks(sdk::renderer::layer::Scene* layer);
    void do_ultrawide_fix();
    void do_ultrawide_fov_restore(bool force = false);
    void set_ultrawide_fov(bool enable);

    void setup_path_trace_hook();
    void setup_shader_interception_hook();
    void setup_rt_component();
    void apply_ray_tracing_tweaks();

    static void* rt_draw_hook(REComponent* rt, void* draw_context, void* r8, void* r9);
    static void* rt_draw_impl_hook(void* rt_impl, void* draw_context, void* r8, void* r9, void* unk);
    static sdk::renderer::PipelineState* find_pipeline_state_hook(void* shader_resource, uint32_t murmur_hash, void* unk);

    static std::string make_replacement_shader();

    enum ShaderDispatchMode {
        Dispatch,
        Dispatch32BitConstant,
        DispatchRay
    };

    static const inline std::array<const char*, 3> s_shader_dispatch_modes {
        "Dispatch",
        "Dispatch32BitConstant",
        "DispatchRay"
    };

    struct ReplacementShader {
        std::string shader{};

        uint32_t hash{ 0 };
        ShaderDispatchMode dispatch_mode{ Dispatch };

        uint32_t thread_group_x{ 2560 };
        uint32_t thread_group_y{ 1440 };
        uint32_t thread_group_z{ 1 };
        uint32_t constant{0};

        bool valid_hash{false};
    };

    struct InterceptedShader {
        std::array<ReplacementShader, 8> replacement_shaders{};

        std::string name{};

        uint32_t hash{ 0 };

        std::string replace_with_name{};

        uint32_t replace_with_hash{ 0 };
    };

    std::array<InterceptedShader, 8> m_intercepted_shaders{};
    bool is_intercepted(uint32_t hash);
    InterceptedShader* get_intercepted(uint32_t hash);

    bool m_disable_path_space{false};

    std::unique_ptr<FunctionHook> m_rt_draw_hook{};
    std::unique_ptr<FunctionHook> m_rt_draw_impl_hook{};
    std::unique_ptr<FunctionHook> m_find_pipeline_state_hook{};
    bool m_attempted_path_trace_hook{ false };
    bool m_attempted_shader_interception_hook{ false };

    std::optional<size_t> m_rt_type_offset{};
    sdk::intrusive_ptr<sdk::ManagedObject> m_rt_component{};
    sdk::intrusive_ptr<sdk::ManagedObject> m_rt_cloned_component{};
    sdk::intrusive_ptr<sdk::ManagedObject> m_rt_recreated_component{};
    void* m_pt_pipeline_resource{nullptr};
    void* m_dxr_shader_resource{nullptr};

    struct {
        void* impl;
        void* context;
        void* r8;
        void* r9;
        void* unk;
    } m_rt_draw_args{};

    bool m_within_rt_draw{ false };
    bool m_cloning_dispatch{false};

    std::recursive_mutex m_fov_mutex{};
    std::unordered_map<::REManagedObject*, float> m_fov_map{};
    std::unordered_map<::REManagedObject*, bool> m_vertical_fov_map{};

    struct {
        std::shared_mutex time_mtx{};
        std::chrono::steady_clock::time_point last_inventory_open{};
    } m_re4;
    
    const ModToggle::Ptr m_ultrawide_fix{ make_option<ModToggle>("UltrawideFix", false) };
    const ModToggle::Ptr m_ultrawide_vertical_fov{ make_option<ModToggle>("UltrawideFixVerticalFOV_V2", false) };

    // There is a trend with newer games where there actually is Ultrawide support, so we don't want to actually touch the FOV by default
    // And sometimes messing with the FOV causes permanent issues with the UI, so don't touch it by default
    const ModToggle::Ptr m_ultrawide_custom_fov{make_option<ModToggle>("UltrawideCustomFOV", false)};

    const ModToggle::Ptr m_ultrawide_constrain_ui{make_option<ModToggle>("UltrawideConstrainUI", false)};
    const ModToggle::Ptr m_ultrawide_constrain_child_ui{make_option<ModToggle>("UltrawideConstrainChildUI", false)};
    const ModSlider::Ptr m_ultrawide_fov_multiplier{ make_option<ModSlider>("UltrawideFOVMultiplier_V2", 0.01f, 3.0f, 1.0f) };
    const ModToggle::Ptr m_disable_gui{ make_option<ModToggle>("DisableGUI", false) };
    const ModToggle::Ptr m_force_render_res_to_window{ make_option<ModToggle>("ForceRenderResToWindow", false) };
    const ModKey::Ptr m_disable_gui_key{ make_option<ModKey>("DisableGUIKey") };

    const ModToggle::Ptr m_shader_playground { make_option<ModToggle>("ShaderPlayground", false) };
    const ModToggle::Ptr m_ray_tracing_tweaks { make_option<ModToggle>("RayTracingTweaks", false) };

    /*enum class RayTraceType : uint8_t {
        Disabled = 0,
        AmbientOcclusion = 1,
        Hybrid = 2,
        Pure = 3,
        PathSpaceFilter = 4,
        ScreenSpacePhotonMapping = 5,
        Debug = 6,
        ASVGF = 7,
    };*/

    // We will replace this dynamically with reflected data upon loading
    static inline std::vector<std::string> s_ray_trace_type {
        "Disabled",
        "Ambient Occlusion",
        "Hybrid Path Tracing",
        "Pure Path Tracing",
        "Path Space Filter",
        "Screen Space Photon Mapping",
        "Debug",
        "A S V G F",
    };

    static std::string_view get_ray_trace_type_name(uint8_t type);
    static bool is_pt_type(uint8_t type);
    static bool is_pure_pt_type(uint8_t type);

    static const inline std::vector<std::string> s_bounce_count {
        "0",
        "1",
        "2",
        "3",
        "7"
    };

    static const inline std::vector<std::string> s_samples_per_pixel {
        "1",
        "2",
        "4"
    };

    const ModCombo::Ptr m_ray_trace_type{ make_option<ModCombo>("RayTraceType", s_ray_trace_type) };
    const ModToggle::Ptr m_ray_trace_disable_raster_shadows{ make_option<ModToggle>("RayTraceDisableRasterShadowsWithPT", true) };
    const ModToggle::Ptr m_ray_trace_always_recreate_rt_component{ make_option<ModToggle>("RayTraceAlwaysRecreateRTComponent", false) };
    bool m_was_shadows_disabled{ false };
    const ModCombo::Ptr m_ray_trace_clone_type_true{ make_option<ModCombo>("RayTraceTrueCloneType", s_ray_trace_type) };
    const ModCombo::Ptr m_ray_trace_clone_type_pre{ make_option<ModCombo>("RayTraceCloneTypePre", s_ray_trace_type) };
    const ModCombo::Ptr m_ray_trace_clone_type_post{ make_option<ModCombo>("RayTraceCloneTypePost", s_ray_trace_type) };

    const ModCombo::Ptr m_bounce_count{ make_option<ModCombo>("BounceCount", s_bounce_count, 1) };
    const ModCombo::Ptr m_samples_per_pixel{ make_option<ModCombo>("SamplesPerPixel", s_samples_per_pixel, 1) };

    const ModToggle::Ptr m_scope_tweaks{ make_option<ModToggle>("ScopeTweaks", false) };
    const ModToggle::Ptr m_scope_interlaced_rendering{ make_option<ModToggle>("ScopeInterlacedRendering", false) };
    const ModSlider::Ptr m_scope_image_quality{ make_option<ModSlider>("ScopeImageQuality", 0.01f, 2.0f, 1.0f) };

    // Atomics so the present thread can write them without holding a mutex
    // while the game thread reads them in on_view_get_size / ultrawide fix paths.
    std::atomic<uint32_t> m_backbuffer_width{0};
    std::atomic<uint32_t> m_backbuffer_height{0};
};

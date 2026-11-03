#pragma once

#include "Mod.hpp"

// Single source of truth for the per-callback dispatch lists below.
// One entry per Mod game callback: name, return type, argument list, and a
// unique probe tag. Each probe is a tiny subclass overriding exactly one
// callback; it is only instantiated at startup to locate that callback's
// vtable slot (the single slot where the probe differs from the base Mod), so
// its body never actually runs. The resulting list holds only the mods that
// override the callback, so every hook iterates the same way whether it fires
// thousands of times per frame (update_transform) or a handful (the rest).
//
// Each probe body must be UNIQUE and non-trivial: an empty `{}` body compiles
// to the same code as the base Mod's empty override, and MSVC's /OPT:ICF would
// then fold them onto one address, hiding the differing vtable slot. The tag
// argument gives every probe a distinct body so the slot is always locatable.
#define REF_GAME_CALLBACK_LIST(X) \
    X(pre_update_transform, void, (RETransform*), 1) \
    X(update_transform, void, (RETransform*), 2) \
    X(pre_update_camera_controller, void, (RopewayPlayerCameraController*), 3) \
    X(update_camera_controller, void, (RopewayPlayerCameraController*), 4) \
    X(pre_update_camera_controller2, void, (RopewayPlayerCameraController*), 5) \
    X(update_camera_controller2, void, (RopewayPlayerCameraController*), 6) \
    X(pre_gui_draw_element, bool, (REComponent*, void*), 7) \
    X(gui_draw_element, void, (REComponent*, void*), 8) \
    X(pre_update_before_lock_scene, void, (void*), 9) \
    X(update_before_lock_scene, void, (void*), 10) \
    X(pre_lightshaft_draw, void, (void*, void*), 11) \
    X(lightshaft_draw, void, (void*, void*), 12) \
    X(pre_view_get_size, void, (REManagedObject*, float*), 13) \
    X(view_get_size, void, (REManagedObject*, float*), 14) \
    X(pre_camera_get_projection_matrix, void, (REManagedObject*, Matrix4x4f*), 15) \
    X(camera_get_projection_matrix, void, (REManagedObject*, Matrix4x4f*), 16) \
    X(pre_camera_get_view_matrix, void, (REManagedObject*, Matrix4x4f*), 17) \
    X(camera_get_view_matrix, void, (REManagedObject*, Matrix4x4f*), 18) \
    X(pre_application_entry, void, (void*, const char*, size_t), 19) \
    X(application_entry, void, (void*, const char*, size_t), 20) \
    X(pre_scene_layer_update, bool, (sdk::renderer::layer::Scene*, void*), 21) \
    X(scene_layer_update, void, (sdk::renderer::layer::Scene*, void*), 22) \
    X(pre_scene_layer_draw, bool, (sdk::renderer::layer::Scene*, void*), 23) \
    X(scene_layer_draw, void, (sdk::renderer::layer::Scene*, void*), 24) \
    X(pre_post_effect_layer_update, bool, (sdk::renderer::layer::PostEffect*, void*), 25) \
    X(post_effect_layer_update, void, (sdk::renderer::layer::PostEffect*, void*), 26) \
    X(pre_post_effect_layer_draw, bool, (sdk::renderer::layer::PostEffect*, void*), 27) \
    X(post_effect_layer_draw, void, (sdk::renderer::layer::PostEffect*, void*), 28) \
    X(pre_overlay_layer_update, bool, (sdk::renderer::layer::Overlay*, void*), 29) \
    X(overlay_layer_update, void, (sdk::renderer::layer::Overlay*, void*), 30) \
    X(pre_overlay_layer_draw, bool, (sdk::renderer::layer::Overlay*, void*), 31) \
    X(overlay_layer_draw, void, (sdk::renderer::layer::Overlay*, void*), 32) \
    X(pre_prepare_output_layer_update, bool, (sdk::renderer::layer::PrepareOutput*, void*), 33) \
    X(prepare_output_layer_update, void, (sdk::renderer::layer::PrepareOutput*, void*), 34) \
    X(pre_prepare_output_layer_draw, bool, (sdk::renderer::layer::PrepareOutput*, void*), 35) \
    X(prepare_output_layer_draw, void, (sdk::renderer::layer::PrepareOutput*, void*), 36) \
    X(pre_output_layer_update, bool, (sdk::renderer::layer::Output*, void*), 37) \
    X(output_layer_update, void, (sdk::renderer::layer::Output*, void*), 38) \
    X(pre_output_layer_draw, bool, (sdk::renderer::layer::Output*, void*), 39) \
    X(output_layer_draw, void, (sdk::renderer::layer::Output*, void*), 40)

class Mods {
public:
    Mods();
    virtual ~Mods() {}

    std::optional<std::string> on_initialize() const;
    std::optional<std::string> on_initialize_d3d_thread() const;

    void on_pre_imgui_frame() const;
    void on_frame() const;
    void on_present() const;
    void on_post_frame() const;
    void on_draw_ui() const;
    void on_device_reset() const;

    const auto& get_mods() const {
        return m_mods;
    }

    // Per-callback dispatch lists: only mods that actually override each hot
    // callback (determined once at startup by comparing vtable slots against
    // the base Mod implementation). The update_transform hooks iterate these
    // instead of all mods, eliminating empty virtual dispatch on the hottest
    // per-frame callback.
    struct Dispatch {
#define REF_DISPATCH_MEMBER(name, ret, args, tag) std::vector<Mod*> name{};
        REF_GAME_CALLBACK_LIST(REF_DISPATCH_MEMBER)
#undef REF_DISPATCH_MEMBER
    };

    const Dispatch& dispatch() const {
        return m_dispatch;
    }

private:
    void build_dispatch_lists();

    std::vector<std::shared_ptr<Mod>> m_mods;
    Dispatch m_dispatch{};
};
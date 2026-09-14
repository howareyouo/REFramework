#pragma once

#include "Mod.hpp"
#include "utility/FunctionHook.hpp"

#include <sdk/Renderer.hpp>

class Hooks : public Mod {
public:
    static std::shared_ptr<Hooks>& get();

public:
    Hooks();

    std::string_view get_name() const override { return "Hooks"; };
    std::optional<std::string> on_initialize() override;

    void ignore_application_entry(size_t hash) {
        std::unique_lock _{m_application_entry_data_mutex};
        m_ignored_application_entries.insert(hash);
    }

    void ignore_application_entry(std::string_view name) {
        ignore_application_entry(utility::hash(name));
    }

    // One installed game-function hook. `Fn` is the hooked function type; the
    // trampoline (the callable original) is fetched once when the hook is
    // created and cached here, so a hooked call is a plain indirect call rather
    // than a FunctionHook::get_original() query on every invocation.
    template <typename Fn>
    struct GameHook {
        bool create(Address target, Fn* destination) {
            handle = std::make_unique<FunctionHook>(target, destination);

            if (!handle->create()) {
                return false;
            }

            original = handle->get_original<Fn>();
            return true;
        }

        std::unique_ptr<FunctionHook> handle{};
        Fn* original{};
    };

    template<typename T = sdk::renderer::RenderLayer>
    struct RenderLayerHook {
        RenderLayerHook() = delete;
        RenderLayerHook(std::string_view name)
            : name{name}
        {

        }

        static void draw(T* layer, void* render_context);
        static void update(T* layer, void* render_context);

        bool hook_draw(Address target) {
            return draw_hook.create(target, &RenderLayerHook<T>::draw);
        }

        bool hook_update(Address target) {
            return update_hook.create(target, &RenderLayerHook<T>::update);
        }

        // The layer Update vtable function really takes only the layer, but the
        // hook body is declared with the (layer, render_context) shape used by
        // the mod callbacks and the extra argument is simply ignored by the game.
        GameHook<void(T*, void*)> draw_hook{};
        GameHook<void(T*, void*)> update_hook{};
        std::string name{};
    };

protected:
    static void* update_transform_hook(RETransform* t, uint8_t a2, uint32_t a3);
    static void* update_camera_controller_hook(void* ctx, RopewayPlayerCameraController* camera_controller);
    static void* update_camera_controller2_hook(void* ctx, RopewayPlayerCameraController* camera_controller);
    static void* gui_draw_hook(REComponent* gui_element, void* primitive_context);
    static void update_before_lock_scene_hook(void* ctx);
    static void global_application_entry_hook(void* entry, const char* name, size_t hash, void* original);
    static float* view_get_size_hook(REManagedObject* scene_view, float* result);
    static Matrix4x4f* camera_get_projection_matrix_hook(REManagedObject* camera, Matrix4x4f* result);
    static Matrix4x4f* camera_get_view_matrix_hook(REManagedObject* camera, Matrix4x4f* result);

private:
    std::optional<std::string> hook_update_transform();
    std::optional<std::string> hook_update_camera_controller();
    std::optional<std::string> hook_update_camera_controller2();
    std::optional<std::string> hook_gui_draw();
    std::optional<std::string> hook_update_before_lock_scene();
    std::optional<std::string> hook_view_get_size();
    std::optional<std::string> hook_camera_get_projection_matrix();
    std::optional<std::string> hook_camera_get_view_matrix();
    std::optional<std::string> hook_all_application_entries();

    template <typename T>
    std::optional<std::string> hook_render_layer(RenderLayerHook<T>& hook);

    std::optional<std::string> hook_render_layers();

    #define HOOK_LAMBDA(func) [&]() -> std::optional<std::string> { return this->func(); }

    std::vector<std::function<std::optional<std::string>()>> m_hook_list{
        HOOK_LAMBDA(hook_all_application_entries),
        HOOK_LAMBDA(hook_render_layers),
        HOOK_LAMBDA(hook_update_transform),
        HOOK_LAMBDA(hook_update_camera_controller),
        HOOK_LAMBDA(hook_update_camera_controller2),
        HOOK_LAMBDA(hook_gui_draw),
#ifndef RE7
#ifndef MHRISE
        HOOK_LAMBDA(hook_update_before_lock_scene),
#endif
#endif
        HOOK_LAMBDA(hook_view_get_size),
        HOOK_LAMBDA(hook_camera_get_projection_matrix),
        HOOK_LAMBDA(hook_camera_get_view_matrix),
    };

protected:
    GameHook<void*(RETransform*, uint8_t, uint32_t)> m_update_transform;
    GameHook<void*(void*, RopewayPlayerCameraController*)> m_update_camera_controller;
    GameHook<void*(void*, RopewayPlayerCameraController*)> m_update_camera_controller2;
    GameHook<void*(REComponent*, void*)> m_gui_draw;
    GameHook<void(void*)> m_update_before_lock_scene;
    GameHook<float*(REManagedObject*, float*)> m_view_get_size;
    GameHook<Matrix4x4f*(REManagedObject*, Matrix4x4f*)> m_camera_get_projection_matrix;
    GameHook<Matrix4x4f*(REManagedObject*, Matrix4x4f*)> m_camera_get_view_matrix;

    struct {
        RenderLayerHook<sdk::renderer::layer::Overlay> overlay{"via.render.layer.Overlay"};
        RenderLayerHook<sdk::renderer::layer::PostEffect> post_effect{"via.render.layer.PostEffect"};
        RenderLayerHook<sdk::renderer::layer::Scene> scene{"via.render.layer.Scene"};
        RenderLayerHook<sdk::renderer::layer::PrepareOutput> prepare_output{"via.render.layer.PrepareOutput"};
        RenderLayerHook<sdk::renderer::layer::Output> output{"via.render.layer.Output"};
    } m_layer_hooks;

    std::unordered_set<size_t> m_ignored_application_entries{};

    std::shared_mutex m_application_entry_data_mutex{};
};

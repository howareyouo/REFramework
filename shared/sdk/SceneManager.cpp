#include <spdlog/spdlog.h>

#include "RETypeDB.hpp"
#include "SceneManager.hpp"

namespace sdk {
void* get_scene_manager() {
    static auto scene_manager_type = sdk::find_type_definition("via.SceneManager");

    if (scene_manager_type == nullptr) {
        spdlog::error("Cannot find via.SceneManager");
        return nullptr;
    }

    return scene_manager_type->get_instance();
}

REManagedObject* get_main_view() {
    return sdk::call_method<::REManagedObject*>("via.SceneManager", "get_MainView", sdk::get_thread_context(), get_scene_manager());
}

REManagedObject* get_current_scene() {
    return sdk::call_method<::REManagedObject*>("via.SceneManager", "get_CurrentScene", sdk::get_thread_context(), get_scene_manager());
}

RECamera* get_primary_camera() {
    auto main_view = get_main_view();

    if (main_view == nullptr) {
        return nullptr;
    }

    return sdk::call_method<::RECamera*>("via.SceneView", "get_PrimaryCamera", sdk::get_thread_context(), main_view);
}

void set_timescale(REManagedObject* scene, float timescale) {
    const auto scene_type = utility::re_managed_object::get_type_definition(scene);
    const auto set_timescale_method = scene_type->get_method("set_TimeScale");

    set_timescale_method->call(sdk::get_thread_context(), scene, timescale);
}

void set_timescale(float timescale) {
    auto scene = sdk::get_current_scene();

    if (scene == nullptr) {
        return;
    }

    set_timescale(scene, timescale);
}

float get_timescale(REManagedObject* scene) {
    const auto scene_type = utility::re_managed_object::get_type_definition(scene);
    const auto set_timescale_method = scene_type->get_method("get_TimeScale");

    return set_timescale_method->call<float>(sdk::get_thread_context(), scene);
}

float get_timescale() {
    auto scene = sdk::get_current_scene();

    if (scene == nullptr) {
        return 1.0f;
    }

    return sdk::get_timescale(scene);
}
} // namespace sdk
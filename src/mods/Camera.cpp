#include <sdk/SceneManager.hpp>
#include <sdk/RETypeDB.hpp>

#include "Camera.hpp"

using namespace utility;


void Camera::on_config_load(const Config& cfg) {
    config_load_options(cfg, m_options);
}

void Camera::on_config_save(Config& cfg) {
    config_save_options(cfg, m_options);
}

void Camera::on_draw_ui() {
    ImGui::SetNextItemOpen(false, ImGuiCond_::ImGuiCond_FirstUseEver);
    if (!ImGui::CollapsingHeader(get_name().data())) {
        return;
    }

    ImGui::TextWrapped("Make sure to tick \"Enabled\" for any of the below settings to take effect.");

    if (m_enabled->draw("Enabled") && !m_enabled->value()) {
        on_disabled();
    }

    if (m_disable_vignette->draw("Disable Vignette") && !m_disable_vignette->value()) {
        set_vignette_type(via::render::ToneMapping::Vignetting::Enable);
    }

    // RE8 and above have vignetting brightness
    m_vignette_brightness->draw("Vignette Brightness");


    ImGui::Separator();
    ImGui::TextWrapped("These below settings are separate and do not require \"Enabled\" to be ticked.");

    m_use_custom_global_fov->draw("Use Custom Global FOV");
    m_global_fov->draw("Global FOV");
}

void Camera::on_update_transform(RETransform* transform) {
}

void Camera::on_pre_application_entry(void* entry, const char* name, size_t hash) {
    if (hash == "BeginRendering"_fnv && m_use_custom_global_fov->value()) {
        auto camera = sdk::get_primary_camera();

        if (camera != nullptr) {
            static auto set_fov = sdk::find_method_definition("via.Camera", "set_FOV");

            if (set_fov != nullptr) {
                set_fov->call<void*>(sdk::get_thread_context(), camera, m_global_fov->value());
            }
        }
    }
}

void Camera::on_application_entry(void* entry, const char* name, size_t hash) {
    if (!m_enabled->value() || hash != "LockScene"_fnv) {
        return;
    }

    const auto valid_camera = reset_ptr(m_camera, sdk::get_primary_camera(),
        [&] {
            m_tone_map = nullptr;
        });

    if (valid_camera) {
        if (const auto owner = m_camera->ownerGameObject; owner != nullptr && owner->transform != nullptr) {
            update_vignetting();
        }
    }
}

void Camera::update_vignetting() noexcept {
    // Cache off "RenderToneMapping" once (if camera ptr changes, this will be cached again).
    if (m_tone_map == nullptr) {
        m_tone_map = re_component::find<REComponent>(m_camera, "via.render.ToneMapping");
    }

    if (m_disable_vignette->value()) {
        set_vignette_type(via::render::ToneMapping::Vignetting::Disable);
    }
    else {
        set_vignette_brightness(m_vignette_brightness->value());
    }
}


void Camera::on_disabled() noexcept {
    set_vignette_type(via::render::ToneMapping::Vignetting::Enable);
    set_vignette_brightness(m_vignette_brightness->default_value());

}

void Camera::set_vignette_type(via::render::ToneMapping::Vignetting value) noexcept {
    if (m_tone_map == nullptr) {
        return;
    }

    static auto set_vignetting_method = sdk::find_method_definition("via.render.ToneMapping", "setVignetting");

    if (set_vignetting_method != nullptr) {
        set_vignetting_method->call<void*>(sdk::get_thread_context(), m_tone_map, value);
    }
}

void Camera::set_vignette_brightness(float value) noexcept {
    if (m_tone_map == nullptr) {
        return;
    }

    static auto set_vignetting_brightness_method = sdk::find_method_definition("via.render.ToneMapping", "set_VignettingBrightness");

    if (set_vignetting_brightness_method != nullptr) {
        set_vignetting_brightness_method->call<void*>(sdk::get_thread_context(), m_tone_map, value);
    } else {
        // Not a TDB method.
        utility::re_managed_object::call_method((::REManagedObject*)m_tone_map, "setVignettingBrightness", (double)value);
    }
}

void Camera::set_fov(float fov, float aiming_fov) noexcept {
}
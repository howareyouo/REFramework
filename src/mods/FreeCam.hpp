#pragma once

#include "Mod.hpp"

#include "sdk/ReClass.hpp"
#include "sdk/helpers/NativeObject.hpp"

class FreeCam : public Mod {
public:
    FreeCam() = default;

    std::string_view get_name() const override { return "FreeCam"; }

    void on_config_load(const utility::Config& cfg) override;
    void on_config_save(utility::Config& cfg) override;

    void on_frame() override;
    void on_draw_ui() override;
    void on_update_transform(RETransform* transform) override;
    void on_pre_application_entry(void* entry, const char* name, size_t hash) override;

private:
    bool update_pointers();

    const ModToggle::Ptr m_enabled{              make_option<ModToggle>("Enabled", false) };
    const ModToggle::Ptr m_lock_camera{          make_option<ModToggle>("LockPosition", false) };
    const ModToggle::Ptr m_disable_movement{     make_option<ModToggle>("DisableMovement", false) };
    const ModKey::Ptr m_toggle_key{              make_option<ModKey>("ToggleKey_V2") };
    const ModKey::Ptr m_lock_camera_key{         make_option<ModKey>("LockKey_V2") };
    const ModKey::Ptr m_move_up_key{             make_option<ModKey>("MoveUpKey_V2", VK_SPACE) };
    const ModKey::Ptr m_move_down_key{           make_option<ModKey>("MoveDownKey_V2", VK_LCONTROL) };
    const ModKey::Ptr m_disable_movement_key{    make_option<ModKey>("DisableMoveKey_V2") };
    const ModKey::Ptr m_speed_modifier_fast_key{ make_option<ModKey>("SpeedModifierFast_V2", VK_LSHIFT)};
    const ModKey::Ptr m_speed_modifier_slow_key{ make_option<ModKey>("SpeedModifierSlow_V2", VK_LMENU)};

    const ModSlider::Ptr m_speed{ make_option<ModSlider>("Speed", 0.0f, 1.0f, 0.1f) };
    const ModSlider::Ptr m_speed_modifier{ make_option<ModSlider>("SpeedModifier", 1.f, 50.f, 4.f) };

    const ModSlider::Ptr m_rotation_speed{ make_option<ModSlider>("RotationSpeed", 0.0f, 1.0f, 0.1f) };



    sdk::helpers::NativeObject m_via_hid_gamepad{ "via.hid.GamePad" };
    sdk::helpers::NativeObject m_application{ "via.Application" };

    Matrix4x4f m_last_camera_matrix{ glm::identity<Matrix4x4f>() };

    bool m_first_time{ true };
    bool m_was_disabled{ false };

    Vector3f m_custom_angles{};
    float m_twist{0.0f};

    RECamera* m_camera{nullptr};

    struct {
        bool attempted_hook{false};
        std::optional<size_t> get_past_move_frame_move_dir_vec_id{};
        std::optional<size_t> update_id{};
        std::optional<size_t> late_update_id{};
    } m_player_body_updater_hook{};

    struct {
        bool attempted_hook{false};
        std::optional<size_t> change_motion_internal_id{};
    } m_player_motion_controller_hook{};

    REManagedObject* m_re4_body{nullptr};
};
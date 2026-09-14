#include <sdk/Application.hpp>
#include "sdk/REMath.hpp"
#include "sdk/SceneManager.hpp"

#include "HookManager.hpp"

#include "FreeCam.hpp"

using namespace utility;

#if defined(RE2) || defined(RE3) || defined(RE8) || defined(RE4)
#define MOVEMENT_DISABLE_FEATURE
#endif

void FreeCam::on_config_load(const Config& cfg) {
    config_load_options(cfg, m_options);
}

void FreeCam::on_config_save(Config& cfg) {
    config_save_options(cfg, m_options);
}

void FreeCam::on_frame() {
    if (m_toggle_key->is_key_down_once()) {
        m_enabled->toggle();
        m_first_time = true;
    }

    if (m_lock_camera_key->is_key_down_once()) {
        m_lock_camera->toggle();
    }

    if (m_disable_movement_key->is_key_down_once()) {
        m_disable_movement->toggle();
    }
}

void FreeCam::on_draw_ui() {
    ImGui::SetNextItemOpen(false, ImGuiCond_::ImGuiCond_FirstUseEver);

    if (!ImGui::CollapsingHeader(get_name().data())) {
        return;
    }

    if (m_enabled->draw("Enabled")) {
        m_first_time = true;
    }

    ImGui::SameLine();
    m_lock_camera->draw("Lock Position");

#ifdef MOVEMENT_DISABLE_FEATURE
    m_disable_movement->draw("Disable Character Movement");
#endif

    m_toggle_key->draw("Toggle Key");
    m_move_up_key->draw("Move camera up Key");
    m_move_down_key->draw("Move camera down Key");
    m_lock_camera_key->draw("Lock Position Toggle Key");
#ifdef MOVEMENT_DISABLE_FEATURE
    m_disable_movement_key->draw("Disable Movement Toggle Key");
#endif
    m_speed_modifier_fast_key->draw("Speed modifier Fast key");
    m_speed_modifier_slow_key->draw("Speed modifier Slow key");

    m_rotation_speed->draw("Rotation Speed");

    m_speed->draw("Speed");
    m_speed_modifier->draw("Speed Modifier");
}

// True only for the primary camera's own transform. Every other transform is one
// we must not touch, so the per-frame hot path bails out here.
bool FreeCam::is_camera_transform(const RETransform* transform) const noexcept {
    const auto camera = m_camera;

    return camera != nullptr
        && camera->ownerGameObject != nullptr
        && transform == camera->ownerGameObject->transform;
}

void FreeCam::on_update_transform(RETransform* transform) {
    if (!m_enabled->value() && !m_first_time) {
        m_was_disabled = false;
        return;
    }

#ifdef RE8
    // The player transform is a different transform than the camera's, so it is
    // handled before the camera check. The props manager is needed to find the player.
    if (!update_props_manager() || !update_pointers()) {
        m_was_disabled = false;
        return;
    }

    update_player_transform(transform);

    if (!is_camera_transform(transform)) {
        return;
    }
#else
    // Bail out of every non-camera transform before resolving pointers.
    if (!is_camera_transform(transform)) {
        return;
    }

    if (!update_pointers()) {
        spdlog::error("FreeCam: Failed to update pointers");
        m_was_disabled = false;
        return;
    }
#endif

    update_camera(transform);
}

void FreeCam::update_camera(RETransform* transform) {
#if defined(RE2) || defined(RE3)
    static const auto get_player_condition = sdk::find_method_definition(game_namespace("SurvivorManager"), "get_Player");
    static const auto get_action_orderer = sdk::find_method_definition(game_namespace("survivor.SurvivorCondition"), "get_ActionOrderer");

    const auto condition = get_player_condition->call<RopewaySurvivorPlayerCondition*>(sdk::get_thread_context(), m_survivor_manager);
    const auto orderer = condition != nullptr ? get_action_orderer->call<RopewaySurvivorActionOrderer*>(sdk::get_thread_context(), condition) : nullptr;
#endif

    if (m_first_time) {
#ifdef RE8
        if (const auto player = m_props_manager->player; player != nullptr && m_was_disabled) {
            player->shouldUpdate = true;
            m_was_disabled = false;
        }
#endif

#if defined(RE2) || defined(RE3)
        if (orderer != nullptr) {
            orderer->enabled = true;
        }
#endif

        // Seed the camera matrix from the camera's first joint when it has one.
        if (const auto joint = re_transform::get_joint(*transform, 0); joint != nullptr) {
            m_last_camera_matrix = Matrix4x4f{ sdk::get_joint_rotation(joint) };
            m_last_camera_matrix[3] = sdk::get_joint_position(joint);
        } else {
            m_last_camera_matrix = transform->worldTransform;
        }

        m_first_time = false;
        m_custom_angles = math::euler_angles(glm::extractMatrixRotation(m_last_camera_matrix));
        m_twist = 0.0f;
        math::fix_angles(m_custom_angles);

        return;
    }

#if defined(RE2) || defined(RE3)
    if (orderer != nullptr) {
        orderer->enabled = !m_disable_movement->value();
    }
#endif

#if TDB_VER < 81
    const auto joint = re_transform::get_joint(*transform, 0);
#endif

    update_camera_pose(transform);

    transform->worldTransform = m_last_camera_matrix;
    transform->position = m_last_camera_matrix[3];

    // The camera joint fights the matrix we just wrote on older TDB versions.
#if TDB_VER < 81
    if (joint != nullptr) {
        joint->posOffset = Vector4f{};
        *(Vector4f*)&joint->anglesOffset = Vector4f{0.0f, 0.0f, 0.0f, 1.0f};
    }
#endif
}

void FreeCam::update_camera_pose(RETransform* transform) {
    if (m_lock_camera->value()) {
        return;
    }

#if TDB_VER > 49
    auto timescale = sdk::get_timescale() * sdk::Application::get_global_speed();

    if (timescale == 0.0f) {
        timescale = std::numeric_limits<float>::epsilon();
    }

    const auto timescale_mult = 1.0f / timescale;
    const auto delta = re_component::get_delta_time(transform);
#else
    // RE7 doesn't have a timescale.
    const auto timescale_mult = 1.0f;
    const auto delta = sdk::call_native_func_easy<float>(m_application.object, m_application.t, "get_DeltaTime");
#endif

    const auto input = sample_input(delta, timescale_mult);

    math::fix_angles(m_custom_angles);

    auto new_rotation = glm::quat{ m_custom_angles };
    new_rotation = glm::rotate(new_rotation, m_twist, glm::vec3{ 0.0f, 0.0f, 1.0f });

    const auto dir_speed = m_speed->value() * input.speed_multiplier;
    const auto new_pos = m_last_camera_matrix[3] + new_rotation * input.dir * (dir_speed * delta * timescale_mult);

    // Remember the rotation so a locked camera has something to hold onto.
    m_last_camera_matrix = glm::mat4{ new_rotation };
    m_last_camera_matrix[3] = new_pos;
}

void FreeCam::sample_gamepad(Vector4f& dir, float rotation_speed, float delta, float timescale_mult) {
    const auto pad = sdk::call_native_func_easy<REManagedObject*>(m_via_hid_gamepad.object, m_via_hid_gamepad.t, "get_LastInputDevice");

    if (pad == nullptr) {
        return;
    }

    using Button = via::hid::GamePadButton;

    static const auto gamepad_device_t = sdk::find_type_definition("via.hid.GamePadDevice");
    static const auto is_down = gamepad_device_t != nullptr ? gamepad_device_t->get_method("isDown(via.hid.GamePadButton)") : nullptr;

    // via.vec2 is not actually 8 bytes, so read the fields as Vector3f to avoid stack corruption.
    const auto axis_l_field = re_managed_object::get_field<Vector3f*>(pad, "AxisL");
    const auto axis_r_field = re_managed_object::get_field<Vector3f*>(pad, "AxisR");
    const auto axis_l = axis_l_field != nullptr ? *axis_l_field : Vector3f{};
    const auto axis_r = axis_r_field != nullptr ? *axis_r_field : Vector3f{};
    const auto axis_r_len = glm::length(axis_r);

    bool using_up_down_modifier = false;
    bool using_twist_modifier = false;

    if (is_down != nullptr) {
        const auto tc = sdk::get_thread_context();
        const auto down = [&](Button button) { return is_down->call_safe<bool>(tc, pad, button); };

        if (down(Button::LUp))        dir.y = 1.0f;
        else if (down(Button::LDown)) dir.y = -1.0f;

        if (down(Button::LLeft))       dir.x -= 1.0f;
        else if (down(Button::LRight)) dir.x += 1.0f;

        if (down(Button::LTrigBottom) && axis_r_len > 0.0f) { // left trigger + right stick moves up/down instead of looking
            dir.y += axis_r.y;
            using_up_down_modifier = true;
        }

        if (down(Button::RTrigBottom) && axis_r_len > 0.0f) { // right trigger + right stick twists (rolls) the camera
            m_twist += axis_r.x * rotation_speed * delta * timescale_mult;
            using_twist_modifier = true;
        }
    }

    if (!using_up_down_modifier && !using_twist_modifier) {
        m_custom_angles[0] += axis_r.y * rotation_speed * delta * timescale_mult;
        m_custom_angles[1] -= axis_r.x * rotation_speed * delta * timescale_mult;
    }

    if (glm::length(axis_l) > 0.0f) {
        dir += Vector4f{ axis_l.x, 0.0f, axis_l.y * -1.0f, 0.0f };
    }
}

FreeCam::FrameInput FreeCam::sample_input(float delta, float timescale_mult) {
    FrameInput input{};

    const auto rotation_speed = m_rotation_speed->value();
    sample_gamepad(input.dir, rotation_speed, delta, timescale_mult);

    // VkKeyScan packs shift-state in the high byte (and returns -1 on failure);
    // only the low byte is the virtual-key code used to index the 256-entry state.
    static const auto w_key = VkKeyScan('w') & 0xFF;
    static const auto a_key = VkKeyScan('a') & 0xFF;
    static const auto s_key = VkKeyScan('s') & 0xFF;
    static const auto d_key = VkKeyScan('d') & 0xFF;

    const auto& keys = g_framework->get_keyboard_state();

    if (keys[w_key] || keys[VK_UP])    input.dir.z -= 1.0f;
    if (keys[s_key] || keys[VK_DOWN])  input.dir.z += 1.0f;
    if (keys[a_key] || keys[VK_LEFT])  input.dir.x -= 1.0f;
    if (keys[d_key] || keys[VK_RIGHT]) input.dir.x += 1.0f;

    // ModKey guards unbound / out-of-range keys, so binding a key is all it takes.
    if (m_move_up_key->is_key_down())        input.dir.y = 1.0f;
    else if (m_move_down_key->is_key_down()) input.dir.y = -1.0f;

    const auto speed_modifier = m_speed_modifier->value();
    if (m_speed_modifier_fast_key->is_key_down())      input.speed_multiplier = speed_modifier;
    else if (m_speed_modifier_slow_key->is_key_down()) input.speed_multiplier = 1.0f / speed_modifier;

    if (!g_framework->is_ui_focused()) {
        const auto& mouse_delta = g_framework->get_mouse_delta();
        // Scaled down heavily: 1.0 is far too fast for keyboard + mouse.
        const auto rotation_speed_kbm = rotation_speed * 0.05f;

        if (keys[VK_RBUTTON]) {
            m_twist -= mouse_delta[0] * rotation_speed_kbm * delta * timescale_mult;
        } else {
            m_custom_angles[0] -= mouse_delta[1] * rotation_speed_kbm * delta * timescale_mult;
            m_custom_angles[1] -= mouse_delta[0] * rotation_speed_kbm * delta * timescale_mult;
        }
    }

    return input;
}

void FreeCam::on_pre_application_entry(void* entry, const char* name, size_t hash) {
    if (hash != "LockScene"_fnv) {
        return;
    }

    if (!m_enabled->value()) {
        m_camera = nullptr;
#ifdef RE4
        m_re4_body = nullptr;
#endif
        return;
    }

    m_camera = sdk::get_primary_camera();

#ifdef RE4
    update_re4_body();
#endif
}

#ifdef RE8
bool FreeCam::update_props_manager() {
    if (m_props_manager == nullptr) {
        m_props_manager = reframework::get_globals()->get<AppPropsManager>(game_namespace("PropsManager"));
        return false;
    }

    return true;
}

void FreeCam::update_player_transform(RETransform* transform) {
    const auto player = m_props_manager->player;

    if (player == nullptr || player->transform == nullptr || player->transform != transform) {
        return;
    }

    if (m_disable_movement->value() || m_was_disabled) {
        player->shouldUpdate = !m_disable_movement->value();
        m_was_disabled = !player->shouldUpdate;
    }
}
#endif

#ifdef RE4
void FreeCam::update_re4_body() {
    if (!m_disable_movement->value()) {
        return;
    }

    m_re4_body = nullptr;

    const auto character_manager = sdk::get_managed_singleton<::REManagedObject>(game_namespace("CharacterManager"));
    const auto player_context = character_manager != nullptr ? sdk::call_object_func_easy<::REManagedObject*>(character_manager, "getPlayerContextRef") : nullptr;
    m_re4_body = player_context != nullptr ? sdk::call_object_func_easy<::REManagedObject*>(player_context, "get_BodyGameObject") : nullptr;

    if (m_re4_body != nullptr) {
        setup_re4_hooks();
    }
}

void FreeCam::setup_re4_hooks() {
    // Skip the original when the hooked component's game object is the player's body.
    const auto make_skip_hook = [this](size_t comp_arg_index) -> HookManager::PreHookFn {
        return [this, comp_arg_index](std::vector<uintptr_t>& args, std::vector<sdk::RETypeDefinition*>&, uintptr_t) -> HookManager::PreHookResult {
            if (!m_enabled->value() || !m_disable_movement->value()) {
                return HookManager::PreHookResult::CALL_ORIGINAL;
            }

            const auto owner = re_component::get_game_object((REComponent*)args[comp_arg_index]);

            return owner == m_re4_body ? HookManager::PreHookResult::SKIP_ORIGINAL : HookManager::PreHookResult::CALL_ORIGINAL;
        };
    };

    const auto add_skip_hook = [&](sdk::RETypeDefinition* t, std::string_view method, size_t comp_arg_index) -> std::optional<size_t> {
        const auto fn = t != nullptr ? t->get_method(method) : nullptr;

        if (fn == nullptr) {
            return std::nullopt;
        }

        return g_hookman.add(fn, make_skip_hook(comp_arg_index), [](uintptr_t&, sdk::RETypeDefinition*, uintptr_t) {});
    };

    auto& body_updater = m_player_body_updater_hook;

    if (!body_updater.attempted_hook) {
        body_updater.attempted_hook = true;

        const auto t = sdk::find_type_definition(game_namespace("PlayerBodyUpdater"));

        body_updater.update_id = add_skip_hook(t, "update", 1);
        body_updater.late_update_id = add_skip_hook(t, "lateUpdate", 1);
        // Value types push their arguments to the right, so the component is in args[2].
        body_updater.get_past_move_frame_move_dir_vec_id = add_skip_hook(t, "getPastFrameMoveDirVec", 2);
    }

    auto& motion_controller = m_player_motion_controller_hook;

    if (!motion_controller.attempted_hook) {
        motion_controller.attempted_hook = true;
        motion_controller.change_motion_internal_id = add_skip_hook(sdk::find_type_definition(game_namespace("MotionController")), "changeMotionInternal", 1);
    }
}
#endif

bool FreeCam::update_pointers() {
#if defined(RE2) || defined(RE3)
    if (m_survivor_manager == nullptr) {
        m_survivor_manager = reframework::get_globals()->get<RopewaySurvivorManager>(game_namespace("SurvivorManager"));
        return false;
    }
#endif

    // Should work for all games.
    return m_via_hid_gamepad.update() && m_application.update();
}

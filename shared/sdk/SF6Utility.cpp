#include "RETypeDB.hpp"
#include "SystemArray.hpp"

#include "SF6Utility.hpp"

namespace sdk {
namespace sf6 {
static ::REManagedObject* get_backing_field(::REManagedObject* obj, std::string_view name) {
    if (obj == nullptr) {
        return nullptr;
    }

    const auto field = sdk::get_object_field<::REManagedObject*>(obj, name);

    return field != nullptr ? *field : nullptr;
}

REManagedObject* get_gui_manager() {
    return sdk::get_managed_singleton<REManagedObject>("app.GuiManager");
}

REManagedObject* get_gui_hud_manager() {
    return get_backing_field(get_gui_manager(), "<Hud>k__BackingField");
}

REManagedObject* get_hud_manager_base(HUD_GROUP_TYPE t) {
    const auto gui_hud_manager = get_gui_hud_manager();

    if (gui_hud_manager == nullptr) {
        return nullptr;
    }

    if (t == HUD_GROUP_TYPE::BATTLE) {
        auto hud_manager_list = sdk::get_object_field<sdk::SystemArray*>(gui_hud_manager, "mHudManagerList");

        if (hud_manager_list == nullptr || *hud_manager_list == nullptr) {
            return nullptr;
        }

        static const auto battle_hud_manager_t = sdk::find_type_definition("app.BattleHudManager");

        if (battle_hud_manager_t == nullptr) {
            return nullptr;
        }

        for (::REManagedObject* it : **hud_manager_list) {
            if (it != nullptr && utility::re_managed_object::get_type_definition(it) == battle_hud_manager_t) {
                return it;
            }
        }
    }

    return sdk::call_object_func_easy<::REManagedObject*>(gui_hud_manager, "GetHudManagerBase", (uint32_t)t);
}

::REManagedObject* get_battle_desc() {
    return get_backing_field(get_hud_manager_base(HUD_GROUP_TYPE::BATTLE), "<BattleDesc>k__BackingField");
}

::REManagedObject* get_battle_rule(::REManagedObject* battle_desc) {
    return get_backing_field(battle_desc, "Rule");
}

REManagedObject* get_network_manager() {
    return sdk::get_managed_singleton<REManagedObject>("app.network.NetworkManager");
}

REManagedObject* get_network_session_manager() {
    return get_backing_field(get_network_manager(), "<Session>k__BackingField");
}

REManagedObject* get_network_fg_battle() {
    return get_backing_field(get_network_session_manager(), "<FGBattle>k__BackingField");
}

REManagedObject* get_network_battle_rule() {
    return get_backing_field(get_network_fg_battle(), "<BattleRule>k__BackingField");
}

std::optional<uint8_t*> get_network_game_mode() {
    const auto network_battle_rule = get_network_battle_rule();

    if (network_battle_rule == nullptr) {
        return std::nullopt;
    }

    const auto game_mode = sdk::get_object_field<uint8_t>(network_battle_rule, "GameMode");

    if (game_mode == nullptr) {
        return std::nullopt;
    }

    return game_mode;
}

std::optional<uint8_t*> get_game_mode() {
    const auto battle_desc = get_battle_desc();

    if (battle_desc == nullptr) {
        return std::nullopt;
    }

    const auto battle_rule = get_battle_rule(battle_desc);

    if (battle_rule == nullptr) {
        return std::nullopt;
    }

    const auto game_mode = sdk::get_object_field<uint8_t>(battle_rule, "GameMode");

    if (game_mode == nullptr) {
        return std::nullopt;
    }

    return game_mode;
}

void set_game_mode(EGameMode mode) {
    const auto game_mode = get_game_mode();

    if (game_mode.has_value()) {
        **game_mode = (uint8_t)mode;
    }
}

void set_network_game_mode(EGameMode mode) {
    const auto network_game_mode = get_network_game_mode();

    if (network_game_mode.has_value()) {
        **network_game_mode = (uint8_t)mode;
    }
}

bool is_online_match() {
    const auto network_game_mode = get_network_game_mode();

    if (network_game_mode.has_value()) {
        switch ((EGameMode)**network_game_mode) {
            case EGameMode::RANKED_MATCH:
            case EGameMode::PLAYER_MATCH:
            case EGameMode::CABINET_MATCH:
            case EGameMode::CUSTOM_ROOM_MATCH:
            case EGameMode::ONLINE_TRAINING:
                return true;

            default:
                break;
        }
    }

    const auto game_mode = get_game_mode();

    if (game_mode.has_value()) {
        switch ((EGameMode)**game_mode) {
            case EGameMode::RANKED_MATCH:
            case EGameMode::PLAYER_MATCH:
            case EGameMode::CABINET_MATCH:
            case EGameMode::CUSTOM_ROOM_MATCH:
            case EGameMode::ONLINE_TRAINING:
                return true;

            default:
                break;
        }
    }

    return false;
}
}
}
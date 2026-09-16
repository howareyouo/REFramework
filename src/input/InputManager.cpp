#include "InputManager.hpp"
#include "REFramework.hpp"
#include "WindowsMessageHook.hpp"
#include "mods/REFrameworkConfig.hpp"
#include "Mods.hpp"
#include <imgui.h>
#include <spdlog/spdlog.h>
#include <Dbt.h>

extern "C" {
    extern GUID XUSB_INTERFACE_CLASS_GUID;
}

// https://github.com/PGGB/DeviceStutterFix
static bool is_device_controller(PDEV_BROADCAST_HDR hdr, WPARAM w_param) {
    if (hdr->dbch_devicetype == DBT_DEVTYP_DEVICEINTERFACE) {
        const auto d_interface = (PDEV_BROADCAST_DEVICEINTERFACE)hdr;
        if (d_interface->dbcc_classguid == XUSB_INTERFACE_CLASS_GUID) {
            spdlog::info("Event {:x}: Relevant device detected", w_param);
            return true;
        }
    }
    spdlog::info("Event {:x}: No relevant device detected", w_param);
    return false;
}

InputManager::InputManager(REFramework& fw) : m_framework(fw) {}

void InputManager::consume_input() {
    m_framework.m_mouse_delta[0] = m_framework.m_accumulated_mouse_delta[0];
    m_framework.m_mouse_delta[1] = m_framework.m_accumulated_mouse_delta[1];
    m_framework.m_accumulated_mouse_delta[0] = 0.0f;
    m_framework.m_accumulated_mouse_delta[1] = 0.0f;
}

bool InputManager::set_key_state(UINT vk, bool down) {
    if (vk >= m_framework.m_last_keys.size()) {
        return false;
    }
    m_framework.m_last_keys[vk] = down;
    return true;
}

bool InputManager::should_block_message(UINT message, WPARAM w_param, bool is_mouse_moving) const {
    const auto& io = ImGui::GetIO();

    if (message == WM_INPUT && GET_RAWINPUT_CODE_WPARAM(w_param) == RIM_INPUTSINK) {
        return true;
    }

    switch (message) {
        case WM_DEVICECHANGE:
        case WM_SHOWWINDOW:
        case WM_ACTIVATE:
        case WM_ACTIVATEAPP:
        case WM_CLOSE:
        case WM_DPICHANGED:
        case WM_SIZING:
        case WM_MOUSEACTIVATE:
            return false;
        default:
            break;
    }

    if (m_framework.is_ui_focused()) {
        return io.WantCaptureMouse || io.WantCaptureKeyboard || io.WantTextInput;
    }

    return !is_mouse_moving &&
           (io.WantCaptureMouse || io.WantCaptureKeyboard || io.WantTextInput);
}

bool InputManager::on_message(HWND wnd, UINT message, WPARAM w_param, LPARAM l_param) {
    m_framework.on_message_received();

    if (!m_framework.is_initialized()) {
        return true;
    }

    bool is_mouse_moving = false;
    bool handled = false;

    switch (message) {
    case WM_LBUTTONDOWN:  handled = on_mouse_button(true, VK_LBUTTON); break;
    case WM_LBUTTONUP:    handled = on_mouse_button(false, VK_LBUTTON); break;
    case WM_RBUTTONDOWN:  handled = on_mouse_button(true, VK_RBUTTON); break;
    case WM_RBUTTONUP:    handled = on_mouse_button(false, VK_RBUTTON); break;
    case WM_MBUTTONDOWN:  handled = on_mouse_button(true, VK_MBUTTON); break;
    case WM_MBUTTONUP:    handled = on_mouse_button(false, VK_MBUTTON); break;

    case WM_KEYDOWN:
    case WM_SYSKEYDOWN:
        handled = on_key_down(wnd, w_param);
        break;

    case WM_KEYUP:
    case WM_SYSKEYUP:
        handled = on_key_up(wnd, w_param);
        break;

    case WM_KILLFOCUS:
        std::fill(std::begin(m_framework.m_last_keys), std::end(m_framework.m_last_keys), false);
        break;

    case WM_INPUT:
        handled = on_raw_input(wnd, w_param, l_param);
        is_mouse_moving = (m_framework.m_accumulated_mouse_delta[0] != 0.0f || m_framework.m_accumulated_mouse_delta[1] != 0.0f);
        break;

    case WM_DEVICECHANGE:
        handled = on_device_change(w_param, l_param);
        break;

    case RE_TOGGLE_CURSOR:
        handled = on_toggle_cursor(w_param, l_param);
        break;

    default:
        break;
    }

    ImGui_ImplWin32_WndProcHandler(wnd, message, w_param, l_param);

    {
        const auto& io = ImGui::GetIO();
        if (m_framework.is_drawing_ui() && !m_framework.is_ui_passthrough() &&
            should_block_message(message, w_param, is_mouse_moving)) {
            return false;
        }
    }

    bool any_false = false;
    if (m_framework.is_game_data_initialized()) {
        for (auto& mod : m_framework.get_mods()->get_mods()) {
            if (!mod->on_message(wnd, message, w_param, l_param)) {
                any_false = true;
            }
        }
    }

    return !any_false;
}

bool InputManager::on_mouse_button(bool down, UINT vk) {
    set_key_state(vk, down);
    return true;
}

bool InputManager::on_key_down(HWND wnd, WPARAM w_param) {
    if (w_param >= m_framework.m_last_keys.size()) {
        return true;
    }

    const auto menu_key = REFrameworkConfig::get()->get_menu_key()->value();
    const bool was_down = m_framework.m_last_keys[(UINT)w_param] != 0;

    set_key_state((UINT)w_param, true);

    if ((UINT)w_param == menu_key && !was_down) {
        m_framework.set_draw_ui(!m_framework.is_drawing_ui());
    }
    return true;
}

bool InputManager::on_key_up(HWND wnd, WPARAM w_param) {
    set_key_state((UINT)w_param, false);
    return true;
}

bool InputManager::on_raw_input(HWND wnd, WPARAM w_param, LPARAM l_param) {
    if (GET_RAWINPUT_CODE_WPARAM(w_param) == RIM_INPUT) {
        uint32_t size = sizeof(RAWINPUT);
        RAWINPUT raw{};
        GetRawInputData((HRAWINPUT)l_param, RID_INPUT, nullptr, &size, sizeof(RAWINPUTHEADER));
        GetRawInputData((HRAWINPUT)l_param, RID_INPUT, &raw, &size, sizeof(RAWINPUTHEADER));

        if (raw.header.dwType == RIM_TYPEMOUSE) {
            m_framework.m_accumulated_mouse_delta[0] += (float)raw.data.mouse.lLastX;
            m_framework.m_accumulated_mouse_delta[1] += (float)raw.data.mouse.lLastY;
        }
    }
    return true;
}

bool InputManager::on_device_change(WPARAM w_param, LPARAM l_param) {
    switch (w_param) {
    case DBT_DEVICEARRIVAL:
    case DBT_DEVICEREMOVECOMPLETE:
        return is_device_controller((PDEV_BROADCAST_HDR)l_param, w_param);
    default:
        spdlog::info("Event {:x}: skipping", w_param);
        return false;
    }
}

bool InputManager::on_toggle_cursor(WPARAM w_param, LPARAM l_param) {
    const auto is_internal_message = l_param != 0;
    const auto return_value = is_internal_message || !m_framework.is_drawing_ui();
    if (!is_internal_message) {
        // m_cursor_state is kept in REFramework for draw_ui consumption
        m_framework.m_cursor_state = (bool)w_param;
        m_framework.m_cursor_state_changed = true;
    }
    return return_value;
}

void InputManager::on_direct_input_keys(const std::array<uint8_t, 256>& keys) {
    (void)keys;
}

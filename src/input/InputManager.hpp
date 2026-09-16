#pragma once

#include <array>
#include <cstdint>
#include <windows.h>

class REFramework;

class InputManager {
public:
    explicit InputManager(REFramework& fw);

    // Main WndProc dispatcher. Returns false if the message should be blocked.
    bool on_message(HWND wnd, UINT message, WPARAM w_param, LPARAM l_param);

    void consume_input();

    // DirectInput fallback (currently unused)
    void on_direct_input_keys(const std::array<uint8_t, 256>& keys);

private:
    bool on_mouse_button(bool down, UINT vk);
    bool on_key_down(HWND wnd, WPARAM w_param);
    bool on_key_up(HWND wnd, WPARAM w_param);
    bool on_raw_input(HWND wnd, WPARAM w_param, LPARAM l_param);
    bool on_device_change(WPARAM w_param, LPARAM l_param);
    bool on_toggle_cursor(WPARAM w_param, LPARAM l_param);

    bool set_key_state(UINT vk, bool down);
    bool should_block_message(UINT message, WPARAM w_param, bool is_mouse_moving) const;

    REFramework& m_framework;
};

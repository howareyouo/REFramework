#include "D3DHookMonitor.hpp"
#include "REFramework.hpp"
#include "D3D11Hook.hpp"
#include "D3D12Hook.hpp"
#include "WindowsMessageHook.hpp"
#include <spdlog/spdlog.h>

D3DHookMonitor::D3DHookMonitor(REFramework& framework) : m_framework(framework) {
    const auto now = std::chrono::steady_clock::now();
    m_last_present_time.store(now);
    m_last_message_time.store(now);
    m_last_sendmessage_time.store(now);
    m_state_entered = now;
}

void D3DHookMonitor::reset_chance_times() {
    const auto now = std::chrono::steady_clock::now();
    m_last_present_time.store(now + PRESENT_TIMEOUT);
    m_last_chance_time.store(now + CHANCE_TIMEOUT);
    m_has_last_chance.store(true);
}

void D3DHookMonitor::on_present_received() {
    m_last_present_time.store(std::chrono::steady_clock::now());
}

void D3DHookMonitor::on_message_received() {
    m_last_message_time.store(std::chrono::steady_clock::now());
}

void D3DHookMonitor::transition(State new_state) {
    m_state.store(new_state);
    m_state_entered = std::chrono::steady_clock::now();
}

bool D3DHookMonitor::is_present_recent() const {
    const auto now = std::chrono::steady_clock::now();
    return (now - m_last_present_time.load()) <= PRESENT_TIMEOUT;
}

bool D3DHookMonitor::is_message_recent() const {
    const auto now = std::chrono::steady_clock::now();
    return (now - m_last_message_time.load()) <= MESSAGE_TIMEOUT;
}

void D3DHookMonitor::request_rehook() {
    spdlog::info("Sending rehook request for D3D");

    // hook_d3d12 always gets called first.
    if (m_framework.is_dx11()) {
        m_framework.hook_d3d11();
    } else {
        m_framework.hook_d3d12();
    }

    const auto now = std::chrono::steady_clock::now();
    const auto future5 = now + PRESENT_TIMEOUT;
    const auto future1 = now + CHANCE_TIMEOUT;
    m_last_present_time.store(future5);
    m_last_message_time.store(future5);
    m_last_sendmessage_time.store(future1);
    m_has_last_chance.store(true);
}

void D3DHookMonitor::check_message_hook() {
    const auto now = std::chrono::steady_clock::now();

    auto wnd = m_framework.get_window();
    if (wnd == 0) return;

    auto hook = m_framework.get_windows_message_hook();
    if (hook != nullptr && hook->is_hook_intact()) {
        spdlog::info("Windows message hook is still intact, ignoring...");
        m_last_message_time.store(now);
        m_last_sendmessage_time.store(now);
        m_sent_message.store(false);
        return;
    }

    if (!m_sent_message.load()) {
        spdlog::info("Sending initial message hook test");
        auto proc = (WNDPROC)GetWindowLongPtr(wnd, GWLP_WNDPROC);
        if (proc != nullptr) {
            CallWindowProc(proc, wnd, WM_NULL, 0, 0);
            spdlog::info("Hook test message sent");
        }
        m_last_sendmessage_time.store(std::chrono::steady_clock::now());
        m_sent_message.store(true);
    } else if (now - m_last_sendmessage_time.load() > SENDMESSAGE_TIMEOUT) {
        spdlog::info("Sending reinitialization request for message hook");
        m_framework.request_message_hook_reinit();
        const auto future5 = now + MESSAGE_TIMEOUT;
        m_last_message_time.store(future5);
        m_last_present_time.store(future5);
        m_sent_message.store(false);
    }
}

void D3DHookMonitor::tick() {
    if (m_framework.get_do_not_hook_d3d_count() > 0) {
        reset_chance_times();
        return;
    }

    if (!m_mutex.try_lock()) {
        reset_chance_times();
        return;
    }
    std::lock_guard _{m_mutex, std::adopt_lock};

    const auto now = std::chrono::steady_clock::now();

    auto& d3d11 = m_framework.get_d3d11_hook();
    auto& d3d12 = m_framework.get_d3d12_hook();

    const bool hooks_unusable =
        (m_framework.is_dx11() && (d3d11 == nullptr || !d3d11->is_inside_present()))
        || (m_framework.is_dx12() && (d3d12 == nullptr || !d3d12->is_inside_present()));

    if (!hooks_unusable) {
        return;
    }

    // --- D3D rehook logic ------------------------------------------------
    if (now - m_last_present_time.load() > PRESENT_TIMEOUT) {
        if (m_has_last_chance.load()) {
            m_has_last_chance.store(false);
            m_last_chance_time.store(now);
            spdlog::info("Last chance encountered for hooking");
        }

        if (!m_has_last_chance.load() && now - m_last_chance_time.load() > CHANCE_TIMEOUT) {
            request_rehook();
        }
    } else {
        m_last_chance_time.store(now);
        m_has_last_chance.store(true);
    }

    // --- Windows message hook liveness check ------------------------------
    if (m_framework.is_initialized() && m_framework.get_window() != 0 && now - m_last_message_time.load() > MESSAGE_TIMEOUT) {
        check_message_hook();
    } else {
        m_sent_message.store(false);
    }
}

#pragma once

#include <atomic>
#include <chrono>
#include <memory>
#include <shared_mutex>

class REFramework;

class D3DHookMonitor {
public:
    explicit D3DHookMonitor(REFramework& framework);

    // Called periodically (e.g. every 500ms) from the monitor thread.
    void tick();

    // Resets all timeout bookkeeping to "healthy" state.
    void reset_chance_times();

    // Notified by the present path to keep hooks alive.
    void on_present_received();
    void on_message_received();

private:
    enum class State {
        Healthy,
        PresentMissed,   // >5s without present
        LastChance,      // gave 1s grace
        NeedsRehook
    };

    void transition(State new_state);
    bool is_present_recent() const;
    bool is_message_recent() const;
    void request_rehook();
    void check_message_hook();

    REFramework& m_framework;

    std::atomic<State> m_state{State::Healthy};
    std::chrono::steady_clock::time_point m_state_entered{std::chrono::steady_clock::now()};

    std::atomic<std::chrono::steady_clock::time_point> m_last_present_time{std::chrono::steady_clock::now()};
    std::atomic<std::chrono::steady_clock::time_point> m_last_message_time{std::chrono::steady_clock::now()};
    std::atomic<std::chrono::steady_clock::time_point> m_last_chance_time{std::chrono::steady_clock::now()};
    std::atomic<std::chrono::steady_clock::time_point> m_last_sendmessage_time{std::chrono::steady_clock::now()};
    std::atomic<bool> m_has_last_chance{true};
    std::atomic<bool> m_sent_message{false};

    static constexpr auto PRESENT_TIMEOUT     = std::chrono::seconds{5};
    static constexpr auto CHANCE_TIMEOUT      = std::chrono::seconds{1};
    static constexpr auto MESSAGE_TIMEOUT       = std::chrono::seconds{5};
    static constexpr auto SENDMESSAGE_TIMEOUT   = std::chrono::seconds{1};
};

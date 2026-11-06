#pragma once

#include <atomic>
#include <condition_variable>
#include <cstdint>
#include <deque>
#include <memory>
#include <mutex>
#include <string>
#include <thread>

class ScriptRunner;

// Minimal HTTP endpoint: `POST /rpc` with `{"code": "..."}` runs Lua in the
// running game and returns the result as JSON. Always binds to 127.0.0.1 so the
// endpoint is invisible to other machines.
//
// The socket thread never touches Lua: it queues the request and drain() runs it
// from ScriptRunner::on_frame, on the thread that already owns the Lua state.
class ScriptRpc {
public:
    ScriptRpc() = default;
    ~ScriptRpc();

    ScriptRpc(const ScriptRpc&) = delete;
    ScriptRpc& operator=(const ScriptRpc&) = delete;

    bool start(uint16_t port);
    void stop();

    bool is_running() const { return m_running.load(std::memory_order_acquire); }
    uint16_t port() const { return m_port; }
    uint64_t served_requests() const { return m_served.load(std::memory_order_relaxed); }
    std::string last_error() const;

    void drain(ScriptRunner& runner);

private:
    struct Job {
        std::string code{};
        bool expression{false};
        uint32_t timeout_ms{5000};

        std::mutex mutex{};
        std::condition_variable cv{};
        bool done{false};
        bool cancelled{false};

        int status{200};
        std::string body{};
    };

    using JobPtr = std::shared_ptr<Job>;

    void accept_loop(std::stop_token stop_token);
    void serve_client(uintptr_t client);
    void fail_pending();
    int handle(const std::string& method, const std::string& target, const std::string& body, std::string& response);
    void execute(ScriptRunner& runner, Job& job);

    std::mutex m_queue_mutex{};
    std::deque<JobPtr> m_queue{};
    std::jthread m_thread{};
    std::atomic<bool> m_running{false};
    std::atomic<uint64_t> m_served{0};
    uintptr_t m_listen_socket{0};
    uint16_t m_port{0};

    mutable std::mutex m_error_mutex{};
    std::string m_last_error{};
};

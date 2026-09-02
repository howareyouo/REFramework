#pragma once

#include <Windows.h>

#include <string_view>
#include <unordered_set>
#include <unordered_map>
#include <thread>
#include <vector>
#include <mutex>
#include <shared_mutex>
#include <chrono>

class WindowFilter {
public:
    static WindowFilter& get();

public:
    WindowFilter();
    virtual ~WindowFilter();

    bool is_filtered(HWND hwnd);

    void filter_window(HWND hwnd) {
        std::scoped_lock _{m_mutex};
        m_filtered_windows.insert(hwnd);
    }

    // Shared fast-path cache used by D3D11/D3D12 hooks to avoid
    // repeated WindowFilter lookups for the same HWND.
    static bool is_hwnd_filtered_fast(HWND hwnd);

    // Checks if a window is permanently filtered (in m_filtered_windows),
    // as opposed to transiently filtered (pending job queue).
    bool is_permanently_filtered(HWND hwnd);

    // Maximum number of entries in the fast-path cache
    static constexpr size_t MAX_FILTERED_HWND_CACHE_SIZE = 1024;

private:
    bool is_filtered_nocache(HWND hwnd);

    std::recursive_mutex m_mutex{};
    std::unordered_set<HWND> m_window_jobs{};
    std::unique_ptr<std::jthread> m_job_thread{};

    std::unordered_set<HWND> m_seen_windows{};
    std::unordered_set<HWND> m_filtered_windows{};
    std::chrono::time_point<std::chrono::steady_clock> m_last_job_tick{};

    // Static cache for is_hwnd_filtered_fast
    static std::unordered_map<HWND, bool> s_filtered_hwnd_cache;
    static std::shared_mutex s_filtered_hwnd_cache_mtx;
};
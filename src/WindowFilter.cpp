#include <spdlog/spdlog.h>

#include "WindowFilter.hpp"

// To prevent usage of statics (TLS breaks the present thread...?)
std::unique_ptr<WindowFilter> g_window_filter{};

WindowFilter& WindowFilter::get() {
    if (g_window_filter == nullptr) {
        g_window_filter = std::make_unique<WindowFilter>();
    }

    return *g_window_filter;
}

WindowFilter::WindowFilter() {
    // We create a job thread because GetWindowTextA can actually deadlock inside
    // the present thread...
    m_job_thread = std::make_unique<std::jthread>([this](std::stop_token s){
        while (!s.stop_requested()) {
            std::this_thread::sleep_for(std::chrono::milliseconds{100});

            m_last_job_tick = std::chrono::steady_clock::now();

            // Quick unlocked check to avoid lock contention when idle
            if (m_window_jobs.empty()) {
                continue; // FIX: was `return` which permanently killed the thread
            }

            // Copy jobs under lock, then process without lock to avoid
            // deadlock when GetWindowTextA sends WM_GETTEXT to a hung window
            std::unordered_set<HWND> jobs_copy;
            {
                std::scoped_lock _{m_mutex};

                // Re-check under lock (double-checked pattern)
                if (m_window_jobs.empty()) {
                    continue;
                }

                jobs_copy.swap(m_window_jobs);
            }

            for (const auto hwnd : jobs_copy) {
                char window_name[256]{};
                if (GetWindowTextA(hwnd, window_name, sizeof(window_name)) != 0) {
                    spdlog::info("[WindowFilter] Encountered new window: {}", window_name);
                }

                if (is_filtered_nocache(hwnd)) {
                    filter_window(hwnd);
                }
            }
        }
    });
}

WindowFilter::~WindowFilter() {
    m_job_thread->request_stop();
    m_job_thread->join();
}

bool WindowFilter::is_filtered(HWND hwnd) {
    if (hwnd == nullptr) {
        return true;
    }
    
    std::scoped_lock _{m_mutex};

    if (m_filtered_windows.find(hwnd) != m_filtered_windows.end()) {
        return true;
    }

    // If there is a job for this window, filter it until the job is done
    if (m_window_jobs.find(hwnd) != m_window_jobs.end()) {
        // If the thread is dead for some reason, do not filter it.
        return std::chrono::steady_clock::now() - m_last_job_tick <= std::chrono::seconds{2};
    }

    // if we havent even seen this window yet, add it to the job queue
    // and return true;
    if (m_seen_windows.find(hwnd) == m_seen_windows.end()) {
        m_seen_windows.insert(hwnd);
        m_window_jobs.insert(hwnd);
        return true;
    }

    return false;
}

bool WindowFilter::is_permanently_filtered(HWND hwnd) {
    if (hwnd == nullptr) {
        return true;
    }
    std::scoped_lock _{m_mutex};
    return m_filtered_windows.find(hwnd) != m_filtered_windows.end();
}

bool WindowFilter::is_filtered_nocache(HWND hwnd) {
    // get window name
    char window_name[256]{};
    GetWindowTextA(hwnd, window_name, sizeof(window_name));

    const auto sv = std::string_view{window_name};

    if (sv.find("UE4SS") != std::string_view::npos) {
        return true;
    }

    if (sv.find("PimaxXR") != std::string_view::npos) {
        return true;
    }

    // TODO: more problematic windows
    return false;
}

// Static members for the fast cache
std::unordered_map<HWND, bool> WindowFilter::s_filtered_hwnd_cache{};
std::shared_mutex WindowFilter::s_filtered_hwnd_cache_mtx{};

bool WindowFilter::is_hwnd_filtered_fast(HWND hwnd) {
    if (hwnd == nullptr) {
        return true;
    }

    {
        std::shared_lock<std::shared_mutex> _(s_filtered_hwnd_cache_mtx);
        auto it = s_filtered_hwnd_cache.find(hwnd);
        if (it != s_filtered_hwnd_cache.end()) {
            return it->second;
        }
    }

    const bool filtered = WindowFilter::get().is_filtered(hwnd);

    if (filtered) {
        // Only cache true for permanently filtered windows;
        // transient true (pending job queue) must not be cached
        if (WindowFilter::get().is_permanently_filtered(hwnd)) {
            std::unique_lock<std::shared_mutex> _(s_filtered_hwnd_cache_mtx);
            if (s_filtered_hwnd_cache.size() < MAX_FILTERED_HWND_CACHE_SIZE) {
                s_filtered_hwnd_cache[hwnd] = true;
            }
        }
    } else {
        std::unique_lock<std::shared_mutex> _(s_filtered_hwnd_cache_mtx);
        if (s_filtered_hwnd_cache.size() < MAX_FILTERED_HWND_CACHE_SIZE) {
            s_filtered_hwnd_cache[hwnd] = false;
        }
    }

    return filtered;
}
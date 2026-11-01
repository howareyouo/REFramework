#pragma once

#include <algorithm>
#include <utility/ScopeGuard.hpp>
#include <vector>

// Vector for Lua callbacks that defers add/remove made while it is being
// iterated (e.g. a script registering re.on_frame from inside an on_frame
// callback) until the outermost iteration finishes, so the range being
// iterated is never invalidated.
template <typename T>
class SafeCallbackVector {
public:
    [[nodiscard]] auto acquire_iteration() {
        ++m_use_count;

        return utility::ScopeGuard([this]() {
            if (--m_use_count > 0) {
                return;
            }

            for (const auto& fn : m_pending_removals) {
                std::erase(m_callbacks, fn);
            }

            m_pending_removals.clear();
            m_callbacks.insert(m_callbacks.end(), m_pending.begin(), m_pending.end());
            m_pending.clear();
        });
    }

    auto& get() { return m_callbacks; }
    bool empty() const { return m_callbacks.empty(); }

    void add(const T& fn) {
        (m_use_count > 0 ? m_pending : m_callbacks).push_back(fn);
    }

    void remove(const T& fn) {
        if (m_use_count > 0) {
            m_pending_removals.push_back(fn);
        } else {
            std::erase(m_callbacks, fn);
        }
    }

private:
    std::vector<T> m_callbacks{};
    std::vector<T> m_pending{};
    std::vector<T> m_pending_removals{};
    int m_use_count{0};
};

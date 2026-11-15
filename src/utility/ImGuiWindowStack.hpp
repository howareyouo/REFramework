#pragma once

#include <imgui_internal.h>

#include <spdlog/spdlog.h>

#include <string>
#include <string_view>

namespace utility {
// A callback that returns or raises between Begin() and End() leaves ImGui's
// stacks misaligned. Asserts are compiled out in this build, so nothing reports
// the mismatch: whatever is submitted afterwards lands inside the window the
// callback left open, and the menu's own End() then closes that window instead
// of its own.
//
// One of these closes whatever a callback leaves behind when it goes out of
// scope, through the same End()/EndChild()/TreePop()/PopStyleColor() path
// EndFrame() uses, so a misbehaving callback costs only its own UI.
//
// `owner` names the callback in the log line. The mismatch is otherwise silent,
// so that line is the only way to find out who leaves a window open.
class ImGuiWindowStackGuard {
public:
    explicit ImGuiWindowStackGuard(std::string_view owner = {}) : m_owner{owner} {
        auto* ctx = ImGui::GetCurrentContext();
        m_valid = ctx != nullptr && ctx->CurrentWindow != nullptr;

        if (m_valid) {
            ImGui::ErrorRecoveryStoreState(&m_state);
        }
    }

    ~ImGuiWindowStackGuard() {
        if (!m_valid) {
            return;
        }

        auto* ctx = ImGui::GetCurrentContext();

        // The frame ended underneath us (a callback ran past EndFrame).
        if (ctx == nullptr || ctx->CurrentWindow == nullptr) {
            return;
        }

        const int delta = ctx->CurrentWindowStack.Size - m_state.SizeOfWindowStack;

        if (delta != 0) {
            // The innermost window is the one the callback left open, so its name
            // names the culprit even when many scripts share a single state.
            const char* innermost = ctx->CurrentWindow != nullptr && ctx->CurrentWindow->Name != nullptr
                ? ctx->CurrentWindow->Name
                : "?";

            report(delta, innermost);
        }

        // Only closes windows; a callback that closed one too many cannot be
        // undone, so recovery is a no-op for a negative delta.
        ImGui::ErrorRecoveryTryToRecoverState(&m_state);
    }

    ImGuiWindowStackGuard(const ImGuiWindowStackGuard&) = delete;
    ImGuiWindowStackGuard& operator=(const ImGuiWindowStackGuard&) = delete;

private:
    void report(int delta, const char* innermost) const {
        // A callback that leaks every frame would otherwise bury the log.
        static int reports = 0;
        static constexpr int report_limit = 16;

        if (reports > report_limit) {
            return;
        }

        ++reports;

        if (reports == report_limit + 1) {
            spdlog::error("[ui] '{}' and others leave ImGui windows open; further reports suppressed", m_owner);
            return;
        }

        if (delta > 0) {
            spdlog::error("[ui] '{}' left {} ImGui window(s) open ({} -> {}), innermost '{}'; closing them so the rest of the frame draws separately",
                m_owner, delta, m_state.SizeOfWindowStack, m_state.SizeOfWindowStack + delta, innermost);
        } else {
            spdlog::error("[ui] '{}' closed {} ImGui window(s) it did not open ({} -> {}), innermost '{}'",
                m_owner, -delta, m_state.SizeOfWindowStack, m_state.SizeOfWindowStack + delta, innermost);
        }
    }

    std::string m_owner;
    ImGuiErrorRecoveryState m_state{};
    bool m_valid{false};
};
} // namespace utility

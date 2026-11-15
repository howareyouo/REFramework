#pragma once

#include <imgui_internal.h>

namespace utility {
// A callback that raises between Begin() and End() leaves ImGui's window stack
// misaligned. Asserts are compiled out in this build, so nothing reports the
// mismatch: every callback drawn afterwards is submitted into the window the
// failing one left open. One of these closes whatever a callback leaves open
// when it goes out of scope, through the same End()/EndChild()/TreePop()/
// PopStyleColor() path EndFrame() uses, so a failing callback costs only its own
// UI.
class ImGuiWindowStackGuard {
public:
    ImGuiWindowStackGuard() { ImGui::ErrorRecoveryStoreState(&m_state); }
    ~ImGuiWindowStackGuard() { ImGui::ErrorRecoveryTryToRecoverState(&m_state); }

    ImGuiWindowStackGuard(const ImGuiWindowStackGuard&) = delete;
    ImGuiWindowStackGuard& operator=(const ImGuiWindowStackGuard&) = delete;

private:
    ImGuiErrorRecoveryState m_state;
};
} // namespace utility

#include <spdlog/spdlog.h>

#include <safetyhook/inline_hook.hpp>

#include "FunctionHookMinHook.hpp"

using namespace std;


FunctionHookMinHook::FunctionHookMinHook(Address target, Address destination)
    : m_target{ target },
      m_destination{ destination }
{
    spdlog::info("Attempting to hook {:p}->{:p}", target.ptr(), destination.ptr());
}

FunctionHookMinHook::~FunctionHookMinHook() {
    remove();
}

bool FunctionHookMinHook::create() {
    if (m_target == 0 || m_destination == 0) {
        spdlog::error("FunctionHookMinHook not initialized");
        return false;
    }

    auto result = safetyhook::InlineHook::create(m_target, m_destination);
    if (!result) {
        std::string error = "";
        switch (result.error().type) {
            case safetyhook::InlineHook::Error::BAD_ALLOCATION:
                error = "bad allocation";
                break;
            case safetyhook::InlineHook::Error::FAILED_TO_DECODE_INSTRUCTION:
                error = "failed to decode instruction";
                break;
            case safetyhook::InlineHook::Error::SHORT_JUMP_IN_TRAMPOLINE:
                error = "short jump in trampoline";
                break;
            case safetyhook::InlineHook::Error::IP_RELATIVE_INSTRUCTION_OUT_OF_RANGE:
                error = "IP relative instruction out of range";
                break;
            case safetyhook::InlineHook::Error::UNSUPPORTED_INSTRUCTION_IN_TRAMPOLINE:
                error = "unsupported instruction in trampoline";
                break;
            case safetyhook::InlineHook::Error::FAILED_TO_UNPROTECT:
                error = "failed to unprotect memory";
                break;
            case safetyhook::InlineHook::Error::NOT_ENOUGH_SPACE:
                error = "not enough space";
                break;
            default:
                error = std::format("unknown error {}", (int32_t)result.error().type);
                break;
        };

        spdlog::error("Failed to hook {:x}: {}", m_target, error);
        return false;
    }

    m_inline_hook = std::move(*result);
    spdlog::info("Hooked {:x}->{:x}", m_target, m_destination);
    return true;
}

bool FunctionHookMinHook::remove() {
    if (!m_inline_hook.has_value()) {
        return true;
    }

    m_inline_hook.reset();
    m_target = 0;
    m_destination = 0;

    return true;
}

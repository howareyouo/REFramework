#pragma once

#include <windows.h>
#include <cstdint>
#include <optional>

#include <safetyhook.hpp>

#include <utility/Address.hpp>

class FunctionHookMinHook {
public:
    FunctionHookMinHook() = delete;
    FunctionHookMinHook(const FunctionHookMinHook& other) = delete;
    FunctionHookMinHook(FunctionHookMinHook&& other) = delete;
    FunctionHookMinHook(Address target, Address destination);
    virtual ~FunctionHookMinHook();

    bool create();

    // Called automatically by the destructor, but you can call it explicitly
    // if you need to remove the hook.
    bool remove();

    auto get_original() const {
        return m_inline_hook ? m_inline_hook->trampoline().address() : 0;
    }

    template <typename T>
    T* get_original() const {
        return m_inline_hook ? m_inline_hook->original<T*>() : nullptr;
    }

    auto is_valid() const {
        return m_inline_hook.has_value();
    }

    FunctionHookMinHook& operator=(const FunctionHookMinHook& other) = delete;
    FunctionHookMinHook& operator=(FunctionHookMinHook&& other) = delete;

private:
    std::optional<safetyhook::InlineHook> m_inline_hook;

    uintptr_t m_target{ 0 };
    uintptr_t m_destination{ 0 };
};

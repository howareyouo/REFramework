#pragma once

#include <windows.h>

namespace utility {
// Replacement for deprecated IsBadReadPtr - uses VirtualQuery instead.
inline bool is_protection_readable(DWORD protect) {
    // PAGE_GUARD is a modifier rather than a protection, reading it raises an exception.
    if (protect & (PAGE_NOACCESS | PAGE_GUARD)) {
        return false;
    }

    constexpr DWORD readable_protections = PAGE_READONLY | PAGE_READWRITE | PAGE_WRITECOPY
                                         | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY;

    return (protect & readable_protections) != 0;
}

// Checks that every page spanned by [addr, addr + size) is committed and readable.
inline bool is_readable(const void* addr, size_t size) {
    if (addr == nullptr) {
        return false;
    }

    auto cursor = (uintptr_t)addr;
    const auto end = cursor + size;

    while (cursor < end) {
        MEMORY_BASIC_INFORMATION mbi{};
        if (VirtualQuery((LPCVOID)cursor, &mbi, sizeof(mbi)) == 0) {
            return false;
        }

        if (mbi.State != MEM_COMMIT || !is_protection_readable(mbi.Protect)) {
            return false;
        }

        const auto region_end = (uintptr_t)mbi.BaseAddress + mbi.RegionSize;
        if (region_end <= cursor) {
            return false;
        }

        cursor = region_end;
    }

    return true;
}
} // namespace utility

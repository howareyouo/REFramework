#include <algorithm>
#include <cstdlib>
#include <cstring>

#include <utility/Scan.hpp>
#include <utility/Module.hpp>
#include <spdlog/spdlog.h>

#include "Memory.hpp"

namespace sdk::memory {
namespace {
using allocate_fn_t = void* (*)(size_t);
using deallocate_fn_t = void (*)(void*);

// Works back to the very first RE Engine build. It sits inside the startup routine
// that creates the window/application and references "RE ENGINE [%ls] %ls port:%3d".
constexpr auto ALLOCATE_PATTERN = "B9 ? ? ? ? E8 ? ? ? ? 45 33 F6 48 85 C0";

struct Allocator {
    allocate_fn_t allocate{};
    deallocate_fn_t deallocate{};
};

// Resolved lazily on first use: the executable must be mapped and spdlog up by then.
const Allocator& allocator() {
    static const Allocator instance = []() -> Allocator {
        Allocator result{};

        const auto ref = utility::scan(utility::get_executable(), ALLOCATE_PATTERN);

        if (!ref) {
            spdlog::error("[sdk::memory] Failed to find allocate function!");
            return result;
        }

        result.allocate = (allocate_fn_t)utility::calculate_absolute(*ref + 6);

        if (result.allocate == nullptr) {
            spdlog::error("[sdk::memory] Failed to calculate allocate function!");
            return result;
        }

        spdlog::info("[sdk::memory] Found allocate function at {:x}", (uintptr_t)result.allocate);

        // In every RE Engine game, deallocate is the next jmp after the allocate prologue.
        const auto first_insn = utility::decode_one((uint8_t*)result.allocate);
        const auto jmp = utility::scan_opcode((uintptr_t)result.allocate + (first_insn ? first_insn->Length : 1), 50, 0xE9);

        if (!jmp) {
            spdlog::error("[sdk::memory] Failed to find deallocate function!");
            return result;
        }

        result.deallocate = (deallocate_fn_t)*jmp;
        spdlog::info("[sdk::memory] Found deallocate function at {:x}", (uintptr_t)result.deallocate);

        return result;
    }();

    return instance;
}
}

void* allocate(size_t size, bool zero_memory) {
    const auto allocate_fn = allocator().allocate;

    void* result = nullptr;

    if (allocate_fn != nullptr) {
        result = allocate_fn(size);
    } else {
        spdlog::error("[sdk::memory] allocate function not found, falling back to malloc");
        result = std::malloc(size);
    }

    if (zero_memory && result != nullptr) {
        std::memset(result, 0, size);
    }

    return result;
}

void deallocate(void* ptr) {
    const auto deallocate_fn = allocator().deallocate;

    if (deallocate_fn != nullptr) {
        deallocate_fn(ptr);
    } else {
        spdlog::error("[sdk::memory] deallocate function not found, falling back to free");
        std::free(ptr);
    }
}

// old_size is required because the engine allocator doesn't expose the size of a block.
void* reallocate(void* ptr, size_t old_size, size_t size) {
    if (ptr == nullptr) {
        return allocate(size);
    }

    if (old_size == size) {
        return ptr;
    }

    // No realloc equivalent is available, so allocate + copy + free manually.
    auto* new_mem = (uint8_t*)allocate(size);

    if (new_mem == nullptr) {
        return nullptr;
    }

    std::memcpy(new_mem, ptr, std::min<size_t>(old_size, size));
    deallocate(ptr);

    return new_mem;
}

namespace detail {
void* allocate_plugin_loader(size_t size) {
    return allocate(size);
}
}
}

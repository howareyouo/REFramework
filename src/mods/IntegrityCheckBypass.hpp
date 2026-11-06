#pragma once

#include <memory>
#include <string_view>
#include <regex>

#include "Mod.hpp"
#include "utility/Patch.hpp"
#include "utility/FunctionHook.hpp"

#include <bddisasm.h>

// Always on for RE3
// Because we use hooks that modify the integrity of the executable
// And RE3 has unfortunately decided to implement an integrity check on the executable code of the process
class IntegrityCheckBypass : public Mod {
public:
    std::string_view get_name() const override { return "IntegrityCheckBypass"; };
    std::optional<std::string> on_initialize() override;

    void on_frame() override;
    void on_config_load(const utility::Config& cfg) override;
    void on_config_save(utility::Config& cfg) override;
    void on_draw_ui() override;
    
    static void ignore_application_entries();

    static void setup_pristine_syscall();
    static void fix_virtual_protect();

    static void hook_add_vectored_exception_handler();
    static void hook_rtl_exit_user_process();

    static void allow_veh() {
        s_veh_allowed = true;
    }
    
    static bool is_veh_called() {
        return s_veh_called;
    }

    static std::shared_ptr<IntegrityCheckBypass>& get_shared_instance();

private:
    static void* renderer_create_blas_hook(void* a1, void* a2, void* a3, void* a4, void* a5);
    static inline std::unique_ptr<FunctionHook> s_renderer_create_blas_hook{};
    static inline uint32_t* s_corruption_when_zero{ nullptr };
    static inline uint32_t s_last_non_zero_corruption{ 8 }; // What I've seen it default to

    static void sha3_rsa_code_midhook(safetyhook::Context& context);
    static void pak_load_check_function(safetyhook::Context& context);
    static void patch_version_hook(safetyhook::Context& context);
    static int scan_patch_files_count();
    static void restore_unencrypted_paks();
    static inline safetyhook::MidHook s_sha3_rsa_code_midhook;
    static inline safetyhook::MidHook s_pak_load_check_function_hook;
    static inline safetyhook::MidHook s_patch_version_hook;
    static inline std::optional<uintptr_t> s_sha3_code_end{};
    static inline int32_t s_sha3_reg_index{-1};
    static inline int32_t s_patch_version_reg_index{-1};
    static inline int s_patch_count;
    static inline bool s_patch_count_checked;
    static inline std::optional<std::uint8_t> s_pak_flags_value{};
    static inline safetyhook::MidHook s_patch_store_flags_hook;
    static inline INSTRUX s_pak_load_check_insn{};

    static void anti_debug_watcher();
    static void init_anti_debug_watcher();
    static void nuke_heap_allocated_code(uintptr_t addr);
    static inline std::unique_ptr<std::jthread> s_anti_anti_debug_thread{nullptr};

    static BOOL WINAPI virtual_protect_impl(LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect, PDWORD lpflOldProtect);
    static BOOL WINAPI virtual_protect_hook(LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect, PDWORD lpflOldProtect);
    
    using NtProtectVirtualMemory_t = NTSTATUS(NTAPI*)(HANDLE ProcessHandle, PVOID* BaseAddress, SIZE_T* NumberOfBytesToProtect, ULONG NewAccessProtection, PULONG OldAccessProtection);
    static inline NtProtectVirtualMemory_t s_pristine_protect_virtual_memory{ nullptr };
    static inline NtProtectVirtualMemory_t s_og_protect_virtual_memory{ nullptr };

    // Kernelbase's VirtualProtect, captured before our hook goes in. The
    // fallback below has to reach the real thing without re-entering the hook.
    using VirtualProtect_t = BOOL(WINAPI*)(LPVOID, SIZE_T, DWORD, PDWORD);
    static inline VirtualProtect_t s_real_virtual_protect{ nullptr };

    // Re-entry guard: safetyhook used to open the target page by calling the
    // exported VirtualProtect, which landed back in virtual_protect_hook while
    // the hook was still being installed. The root fix is
    // patches/safetyhook-ntprotect.patch (safetyhook now calls
    // NtProtectVirtualMemory directly); this stays as a second line of defense.
    static inline thread_local bool s_virtual_protect_in_hook{ false };

    static inline std::unique_ptr<FunctionHook> s_virtual_protect_hook{};

    static PVOID WINAPI add_vectored_exception_handler_hook(ULONG FirstHandler, PVECTORED_EXCEPTION_HANDLER VectoredHandler);
    static inline bool s_veh_allowed{false};
    static inline bool s_veh_called{false};

    static inline std::unique_ptr<FunctionHook> s_add_vectored_exception_handler_hook{};

    static void* rtl_exit_user_process_hook(uint32_t code);
    static inline std::unique_ptr<FunctionHook> s_rtl_exit_user_process_hook{};
    static void pak_store_flags_hook(safetyhook::Context& context);

    void disable_update_timers(std::string_view name) const;

    std::vector<std::unique_ptr<Patch>> m_patches{};
};

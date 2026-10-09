#pragma once

#include <cstdint>
#include <functional>
#include <vector>
#include <memory>
#include <mutex>
#include <stack>
#include <atomic>
#include <string_view>
#include <utility>

#include <asmjit/asmjit.h>

#include "utility/FunctionHook.hpp"
#include "sdk/REVTableHook.hpp"
#include "sdk/RETypeDB.hpp"

class REManagedObject;

class HookManager {
public:
    enum class PreHookResult : int {
        CALL_ORIGINAL,
        SKIP_ORIGINAL,
    };

    struct HookedFn;

    using PreHookFn = std::function<PreHookResult(std::vector<uintptr_t>& args, std::vector<sdk::RETypeDefinition*>& arg_tys, uintptr_t ret_addr)>;
    using PostHookFn = std::function<void(uintptr_t& ret_val, sdk::RETypeDefinition* ret_ty, uintptr_t ret_addr)>;
    using HookId = size_t;

    struct HookedVTable {
        HookManager& hookman;
        std::unique_ptr<sdk::REVTableHook> vtable_hook{};
        std::unordered_map<sdk::REMethodDefinition*, std::unique_ptr<HookedFn>> hooked_fns{};
        std::recursive_mutex mux{};
    };

    struct HookedFn {
        HookManager& hookman;
        void* target_fn{};
        std::unique_ptr<FunctionHook> fn_hook{};
        uintptr_t facilitator_fn{};
        std::vector<sdk::RETypeDefinition*> arg_tys{};
        sdk::REMethodDefinition* fn_def{};
        sdk::RETypeDefinition* ret_ty{};
        std::recursive_mutex mux{};
        std::shared_mutex access_mux{};

        struct CallbackLists {
            std::vector<std::pair<HookId, PreHookFn>> pre{};
            std::vector<std::pair<HookId, PostHookFn>> post{};
            bool empty() const { return pre.empty() && post.empty(); }
        };

        std::atomic<std::shared_ptr<const CallbackLists>> cbs{std::make_shared<CallbackLists>()};

        bool is_virtual{false};
        HookedVTable* vtable{nullptr};

        // Lock-free TLS slot for per-thread HookStorage (index into thread-local vector).
        uint32_t tls_idx{};

        struct HookStorage {
            size_t* args{};
            uintptr_t This{};
            uintptr_t ret_addr_pre{};
            uintptr_t ret_val{};
            std::stack<uintptr_t> ptr_stack{};
            std::vector<size_t> args_impl{};
            uint32_t pre_depth{0};
            uint32_t overall_depth{0};
            uint32_t post_depth{0};
            bool pre_warned_recursion{false};
            bool overall_warned_recursion{false};
            bool post_warned_recursion{false};
        };

        static uint32_t allocate_tls_idx() noexcept;

        __declspec(noinline) static HookStorage* get_storage(HookedFn* fn) noexcept;

        __declspec(noinline) static void push_ptr(HookStorage* storage, uintptr_t reg) {
            storage->ptr_stack.push(reg);
        }
        __declspec(noinline) static uintptr_t pop_ptr(HookStorage* storage) {
            auto val = storage->ptr_stack.top();
            storage->ptr_stack.pop();
            return val;
        }

        __declspec(noinline) static PreHookResult on_pre_hook_static(HookedFn* fn) { return fn->on_pre_hook(); }
        __declspec(noinline) static void on_post_hook_static(HookedFn* fn) { fn->on_post_hook(); }

        PreHookResult on_pre_hook();
        void on_post_hook();

        void add_callback(HookId id, PreHookFn pre_fn, PostHookFn post_fn);
        bool remove_callback(HookId id);

        void warn_recursive(uint32_t depth, bool& warned, std::string_view label);

        HookedFn(HookManager& hm);
        ~HookedFn();
    };

    HookId add(sdk::REMethodDefinition* fn, PreHookFn pre_fn, PostHookFn post_fn, bool ignore_jmp = false);
    HookId add_vtable(::REManagedObject* obj, sdk::REMethodDefinition* fn, PreHookFn pre_fn, PostHookFn post_fn);

    struct EitherOr {
        ::REManagedObject* obj{nullptr};
        sdk::REMethodDefinition* fn{nullptr};
        bool ignore_jmp{false};
    };
    HookId add_either_or(const EitherOr& either_or, PreHookFn pre_fn, PostHookFn post_fn) {
        return either_or.obj == nullptr
            ? add(either_or.fn, pre_fn, post_fn, either_or.ignore_jmp)
            : add_vtable(either_or.obj, either_or.fn, pre_fn, post_fn);
    }
    void remove(sdk::REMethodDefinition* fn, HookId id);

private:
    void create_jitted_facilitator(
        std::unique_ptr<HookedFn>& hooked_fn,
        sdk::REMethodDefinition* fn,
        std::function<uintptr_t()> hook_initialization);

    asmjit::JitRuntime m_jit{};
    std::mutex m_jit_mux{};
    std::unordered_map<sdk::REMethodDefinition*, std::unique_ptr<HookedFn>> m_hooked_fns{};
    std::unordered_map<::REManagedObject*, std::unique_ptr<HookedVTable>> m_hooked_vtables{};

    HookId m_next_hook_id{1};
};

inline HookManager g_hookman{};

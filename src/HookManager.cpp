#include <ranges>
#include <string_view>
#include <atomic>
#include <algorithm>

#include <spdlog/spdlog.h>

#include <utility/Scan.hpp>

#include "HookManager.hpp"

namespace detail {
void* get_actual_function(void* possible_fn) {
    if (!possible_fn) {
        return nullptr;
    }

    auto actual_fn = possible_fn;
    auto ip = (uintptr_t)possible_fn;

    for (auto i = 0; i < 10; ++i) {
        const auto instr = utility::decode_one((uint8_t*)ip);
        if (!instr) break;
        ip += instr->Length;

        if (instr->Category == ND_CAT_RET || instr->Category == ND_CAT_INTERRUPT) {
            return actual_fn;
        }

        // Follow an unconditional jmp (0xE9 jmp rel32) to the actual function.
        if (instr->BranchInfo.IsBranch && !instr->BranchInfo.IsConditional && instr->Category != ND_CAT_CALL) {
            if (*(uint8_t*)(ip - instr->Length) == 0xE9) {
                actual_fn = (void*)(ip + *(int32_t*)(ip - instr->Length + 1));
                return actual_fn;
            }
        }
    }

    if (possible_fn != actual_fn) {
        spdlog::info("[HookManager] Using actual function @ {:p} for wrapper function @ {:p}", actual_fn, possible_fn);
    }

    return actual_fn;
}
}

HookManager::HookedFn::HookedFn(HookManager& hm) : hookman{hm} {
}

HookManager::HookedFn::~HookedFn() {
    fn_hook.reset();

    if (facilitator_fn) {
        std::scoped_lock _{hookman.m_jit_mux};
        hookman.m_jit.release(facilitator_fn);
    }
}

uint32_t HookManager::HookedFn::allocate_tls_idx() noexcept {
    static std::atomic<uint32_t> next{0};
    return next.fetch_add(1, std::memory_order_relaxed);
}

__declspec(noinline) HookManager::HookedFn::HookStorage* HookManager::HookedFn::get_storage(HookedFn* fn) noexcept {
    thread_local std::vector<std::unique_ptr<HookStorage>> tls;
    const auto idx = fn->tls_idx;
    if (idx >= tls.size()) {
        tls.resize(idx + 1);
    }
    auto& slot = tls[idx];
    if (!slot) {
        slot = std::make_unique<HookStorage>();
        slot->args_impl.resize(size_t(2) + 2 + fn->fn_def->get_num_params());
        slot->args = slot->args_impl.data();
    }
    return slot.get();
}

void HookManager::HookedFn::warn_recursive(uint32_t depth, bool& warned, std::string_view label) {
    if (depth == 0 || warned) {
        return;
    }
    warned = true;
    const auto tid = std::hash<std::thread::id>{}(std::this_thread::get_id());
    const auto dt = fn_def->get_declaring_type();
    const auto cls = dt ? dt->get_full_name() : "unknownclass";
    if (label == "Overall") {
        spdlog::warn("[HookManager] (Overall) '{}.{}' appears to be calling itself in some way (thread ID: {:x})", cls, fn_def->get_name(), tid);
    } else {
        spdlog::warn("[HookManager] ({}) Recursive hook detected for '{}.{}' (thread ID: {:x})", label, cls, fn_def->get_name(), tid);
    }
}

HookManager::PreHookResult HookManager::HookedFn::on_pre_hook() {
    auto storage = get_storage(this);

    warn_recursive(storage->pre_depth, storage->pre_warned_recursion, "Pre");
    warn_recursive(storage->overall_depth, storage->overall_warned_recursion, "Overall");

    ++storage->pre_depth;
    const auto ret_addr_pre = storage->ret_addr_pre;
    const auto cbs = this->cbs.load(std::memory_order_acquire);

    auto any_skipped = false;
    for (const auto& [id, pre_fn] : cbs->pre) {
        if (pre_fn(storage->args_impl, arg_tys, ret_addr_pre) == PreHookResult::SKIP_ORIGINAL) {
            any_skipped = true;
        }
    }

    ++storage->overall_depth;
    --storage->pre_depth;

    return any_skipped ? PreHookResult::SKIP_ORIGINAL : PreHookResult::CALL_ORIGINAL;
}

void HookManager::HookedFn::on_post_hook() {
    auto storage = get_storage(this);

    warn_recursive(storage->post_depth, storage->post_warned_recursion, "Post");

    ++storage->post_depth;
    --storage->overall_depth;

    auto& ret_val = storage->ret_val;
    const auto cbs = this->cbs.load(std::memory_order_acquire);

    for (const auto& [id, post_fn] : cbs->post | std::views::reverse) {
        post_fn(ret_val, ret_ty, storage->ret_addr_pre);
    }

    --storage->post_depth;
}

void HookManager::HookedFn::add_callback(HookId id, PreHookFn pre_fn, PostHookFn post_fn) {
    auto next = std::make_shared<CallbackLists>(*cbs.load(std::memory_order_relaxed));
    if (pre_fn) next->pre.emplace_back(id, std::move(pre_fn));
    if (post_fn) next->post.emplace_back(id, std::move(post_fn));
    cbs.store(std::move(next), std::memory_order_release);
}

bool HookManager::HookedFn::remove_callback(HookId id) {
    auto old = cbs.load(std::memory_order_relaxed);
    auto next = std::make_shared<CallbackLists>(*old);
    std::erase_if(next->pre, [id](const auto& cb) { return cb.first == id; });
    std::erase_if(next->post, [id](const auto& cb) { return cb.first == id; });
    const auto now_empty = next->empty();
    cbs.store(std::move(next), std::memory_order_release);
    while (old.use_count() > 1) {
        std::this_thread::yield();
    }
    return now_empty;
}

void HookManager::create_jitted_facilitator(
    std::unique_ptr<HookedFn>& hook,
    sdk::REMethodDefinition* fn,
    std::function<uintptr_t()> hook_initialization)
{
    auto& arg_tys = hook->arg_tys;

    using namespace asmjit;
    using namespace asmjit::x86;

    std::scoped_lock _{m_jit_mux};
    CodeHolder code{};
    code.init(m_jit.environment());
    Assembler a{&code};

    constexpr auto HIDDEN_ARGUMENT_COUNT = 2;
    constexpr size_t STACK_STORAGE_AMOUNT = 80;

    auto hook_label = a.newLabel();
    auto on_pre_hook_label = a.newLabel();
    auto on_post_hook_label = a.newLabel();
    auto orig_label = a.newLabel();
    auto get_storage_label = a.newLabel();
    auto push_ptr_label = a.newLabel();
    auto pop_ptr_label = a.newLabel();
    auto ret_label = a.newLabel();
    auto skip_label = a.newLabel();

    // --- Prologue: save volatile registers & return address ---
    a.mov(rax, ptr(rsp));
    a.push(r12);
    a.push(r13);
    a.push(r14);
    a.mov(r13, rbx);
    a.mov(r14, rax);
    a.push(rbx);
    a.push(rcx);
    a.push(rdx);
    a.push(r8);
    a.push(r9);

    auto store_xmm_args = [&a]() {
        a.sub(rsp, 16 * 4);
        a.movdqu(ptr(rsp), xmm0);
        a.movdqu(ptr(rsp, 16), xmm1);
        a.movdqu(ptr(rsp, 32), xmm2);
        a.movdqu(ptr(rsp, 48), xmm3);
    };
    auto pop_xmm_args = [&a]() {
        a.movdqu(xmm0, ptr(rsp));
        a.movdqu(xmm1, ptr(rsp, 16));
        a.movdqu(xmm2, ptr(rsp, 32));
        a.movdqu(xmm3, ptr(rsp, 48));
        a.add(rsp, 16 * 4);
    };

    store_xmm_args();

    a.mov(rbx, rsp);
    a.sub(rsp, STACK_STORAGE_AMOUNT);
    a.and_(rsp, -16);

    a.mov(rcx, ptr(hook_label));
    a.call(ptr(get_storage_label));

    a.mov(r12, rax);
    a.mov(ptr(r12, offsetof(HookedFn::HookStorage, ret_addr_pre)), r14);
    a.mov(rcx, r12);
    a.mov(rdx, r14);
    a.call(ptr(push_ptr_label));
    a.mov(rcx, r12);
    a.mov(rdx, r13);
    a.call(ptr(push_ptr_label));

    a.mov(rsp, rbx);
    pop_xmm_args();
    a.pop(r9);
    a.pop(r8);
    a.pop(rdx);
    a.pop(rcx);
    a.pop(rbx);
    a.pop(r14);
    a.pop(r13);
    a.mov(rax, r12);
    a.pop(r12);
    a.mov(r10, rax);
    a.mov(rax, ptr(rax));

    static_assert(offsetof(HookedFn::HookStorage, args) == 0);
    a.mov(ptr(rax), rcx);

    auto args_start_offset = fn->is_static() ? 8 : 16;
    if (!fn->is_static()) {
        a.mov(ptr(rax, 8), rdx);
    }

    auto emit_arg = [&a](uint32_t off, bool is_float, bool saving) {
        auto mem = ptr(rax, off);
        switch (off) {
        case 8:
            if (is_float) saving ? a.movq(mem, xmm1) : a.movq(xmm1, mem);
            else          saving ? a.mov(mem, rdx) : a.mov(rdx, mem);
            break;
        case 16:
            if (is_float) saving ? a.movq(mem, xmm2) : a.movq(xmm2, mem);
            else          saving ? a.mov(mem, r8) : a.mov(r8, mem);
            break;
        case 24:
            if (is_float) saving ? a.movq(mem, xmm3) : a.movq(xmm3, mem);
            else          saving ? a.mov(mem, r9) : a.mov(r9, mem);
            break;
        default:
            if (off >= 32) {
                if (saving) {
                    a.mov(r11, ptr(rsp, sizeof(void*) + off));
                    a.mov(mem, r11);
                } else {
                    a.mov(rax, ptr(r10));
                    a.mov(rax, mem);
                    a.mov(ptr(rsp, sizeof(void*) + off), rax);
                }
            }
            break;
        }
    };

    const auto num_params = fn->get_num_params();
    for (auto i = 0u; i < num_params + HIDDEN_ARGUMENT_COUNT; ++i) {
        bool is_float = false;
        if (i < num_params && arg_tys[i]->get_full_name() == "System.Single") {
            is_float = true;
        }
        emit_arg(args_start_offset + i * 8, is_float, true);
    }

    a.mov(rax, rsp);
    a.mov(rax, ptr(rax));
    a.push(r12);
    a.mov(r12, r10);
    a.mov(rbx, rsp);
    a.sub(rsp, STACK_STORAGE_AMOUNT);
    a.and_(rsp, -16);
    a.mov(rcx, ptr(hook_label));
    a.call(ptr(on_pre_hook_label));
    a.mov(r11, rax);
    a.mov(rsp, rbx);
    a.mov(r10, r12);
    a.pop(r12);

    a.mov(rax, ptr(r10));
    a.mov(rcx, ptr(rax));
    if (!fn->is_static()) {
        a.mov(rdx, ptr(rax, 8));
    }
    for (auto i = 0u; i < num_params + HIDDEN_ARGUMENT_COUNT; ++i) {
        bool is_float = false;
        if (i < num_params && arg_tys[i]->get_full_name() == "System.Single") {
            is_float = true;
        }
        emit_arg(args_start_offset + i * 8, is_float, false);
    }

    a.lea(rax, ptr(ret_label));
    a.mov(ptr(rsp), rax);
    a.mov(rbx, r10);
    a.cmp(r11, (int)PreHookResult::CALL_ORIGINAL);
    a.jnz(skip_label);
    a.jmp(ptr(orig_label));

    a.bind(skip_label);
    a.add(rsp, 8);

    a.bind(ret_label);
    a.mov(r10, rbx);
    constexpr auto ret_val_offset = offsetof(HookedFn::HookStorage, ret_val);
    bool is_ret_float = hook->ret_ty->get_full_name() == "System.Single";
    if (is_ret_float) a.movq(ptr(r10, ret_val_offset), xmm0);
    else              a.mov(ptr(r10, ret_val_offset), rax);

    a.push(r12);
    a.push(r13);
    a.mov(r12, r10);
    a.mov(rbx, rsp);
    a.sub(rsp, STACK_STORAGE_AMOUNT);
    a.and_(rsp, -16);
    a.mov(rcx, ptr(hook_label));
    a.call(ptr(on_post_hook_label));
    a.mov(rsp, rbx);
    a.mov(rcx, r12);
    a.call(ptr(pop_ptr_label));
    a.mov(r13, rax);
    a.mov(rcx, r12);
    a.call(ptr(pop_ptr_label));
    a.mov(r11, rax);
    a.mov(rbx, r13);
    a.mov(r10, r12);
    a.pop(r13);
    a.pop(r12);

    if (is_ret_float) a.movq(xmm0, ptr(r10, ret_val_offset));
    else              a.mov(rax, ptr(r10, ret_val_offset));
    a.jmp(r11);

    a.bind(hook_label);
    a.dq((uint64_t)hook.get());
    a.bind(on_pre_hook_label);
    a.dq((uint64_t)&HookedFn::on_pre_hook_static);
    a.bind(on_post_hook_label);
    a.dq((uint64_t)&HookedFn::on_post_hook_static);
    a.bind(get_storage_label);
    a.dq((uint64_t)&HookedFn::get_storage);
    a.bind(push_ptr_label);
    a.dq((uint64_t)&HookedFn::push_ptr);
    a.bind(pop_ptr_label);
    a.dq((uint64_t)&HookedFn::pop_ptr);
    a.bind(orig_label);
    a.dq(0);

    m_jit.add(&hook->facilitator_fn, &code);
    *(uintptr_t*)(hook->facilitator_fn + code.labelOffsetFromBase(orig_label)) = hook_initialization();
}

HookManager::HookId HookManager::add(sdk::REMethodDefinition* fn, HookManager::PreHookFn pre_fn, HookManager::PostHookFn post_fn, bool ignore_jmp) {
    if (!fn) {
        spdlog::error("[HookManager] Cannot add nullptr function");
        return HookId{};
    }

    auto target_fn = ignore_jmp ? fn->get_function() : detail::get_actual_function(fn->get_function());
    if (!target_fn) {
        spdlog::error("[HookManager] Cannot add method that resolves to nullptr");
        return HookId{};
    }

    spdlog::info("[HookManager] Adding hook for '{}' @ {:p}...", fn->get_name(), target_fn);

    if (auto search = m_hooked_fns.find(fn); search != m_hooked_fns.end()) {
        spdlog::info("[HookManager] Reusing existing hook...");
        auto& hook = search->second;
        std::scoped_lock _{hook->mux};
        std::unique_lock __{hook->access_mux};
        auto hook_id = m_next_hook_id++;
        hook->add_callback(hook_id, std::move(pre_fn), std::move(post_fn));
        spdlog::info("[HookManager] Hook {} added for '{}' @ {:p}", hook_id, fn->get_name(), target_fn);
        return hook_id;
    }

    spdlog::info("[HookManager] Creating a new hook...");

    auto hook = std::make_unique<HookedFn>(*this);
    hook->fn_def = fn;
    hook->target_fn = target_fn;
    hook->tls_idx = HookedFn::allocate_tls_idx();
    auto hook_id = m_next_hook_id++;
    hook->add_callback(hook_id, std::move(pre_fn), std::move(post_fn));
    hook->arg_tys = fn->get_param_types();
    hook->ret_ty = fn->get_return_type();

    create_jitted_facilitator(hook, fn, [&]() {
        hook->fn_hook = std::make_unique<FunctionHook>(hook->target_fn, (void*)hook->facilitator_fn);
        if (!hook->fn_hook->create()) {
            spdlog::error("[HookManager] Failed to hook function for '{}'", fn->get_name());
            return uintptr_t{0};
        }
        return hook->fn_hook->get_original();
    });

    m_hooked_fns.emplace(fn, std::move(hook));
    spdlog::info("[HookManager] Hook {} added for '{}' @ {:p}", hook_id, fn->get_name(), target_fn);
    return hook_id;
}

HookManager::HookId HookManager::add_vtable(::REManagedObject* obj, sdk::REMethodDefinition* fn, PreHookFn pre_fn, PostHookFn post_fn) {
#if TDB_VER == 49
    throw std::runtime_error("VTable hooks are not supported in TDB 49");
#endif

    if (!obj || !fn) {
        spdlog::error("[HookManager] Cannot add nullptr function or object");
        return HookId{};
    }

    if (fn->get_virtual_index() == -1) {
        spdlog::error("[HookManager] Cannot add non-virtual function with add_vtable, use add instead.");
        return HookId{};
    }

    spdlog::info("[HookManager] Adding hook for '{}' @ {:p} (vtable index {})...", fn->get_name(), fn->get_function(), fn->get_virtual_index());

    auto search = m_hooked_vtables.find(obj);
    if (search == m_hooked_vtables.end()) {
        spdlog::info("[HookManager] Creating a new VT hook...");
        auto vhook = std::make_unique<HookedVTable>(*this);
        std::scoped_lock _{vhook->mux};
        vhook->vtable_hook = std::make_unique<sdk::REVTableHook>(obj);
        if (!vhook->vtable_hook->is_hooked()) {
            spdlog::error("[HookManager] Failed to hook vtable for {:x}", (uintptr_t)obj);
            return HookId{};
        }
        m_hooked_vtables[obj] = std::move(vhook);
        search = m_hooked_vtables.find(obj);
        spdlog::info("[HookManager] VT hook created for {:x}", (uintptr_t)obj);
    } else {
        spdlog::info("[HookManager] Reusing existing VT hook...");
    }

    auto& vhook = search->second;
    std::scoped_lock _{vhook->mux};

    if (auto it = vhook->hooked_fns.find(fn); it != vhook->hooked_fns.end()) {
        spdlog::info("[HookManager] Reusing existing VT method hook...");
        auto& hook_fn = it->second;
        std::unique_lock __{hook_fn->access_mux};
        auto hook_id = m_next_hook_id++;
        hook_fn->add_callback(hook_id, std::move(pre_fn), std::move(post_fn));
        spdlog::info("[HookManager] VT Hook {} added for '{}' @ {:p}", hook_id, fn->get_name(), fn->get_function());
        return hook_id;
    }

    spdlog::info("[HookManager] Creating a new VT method hook...");

    auto hook_fn = std::make_unique<HookedFn>(*this);
    hook_fn->fn_def = fn;
    hook_fn->target_fn = fn->get_function();
    hook_fn->tls_idx = HookedFn::allocate_tls_idx();
    auto hook_id = m_next_hook_id++;
    hook_fn->add_callback(hook_id, std::move(pre_fn), std::move(post_fn));
    hook_fn->arg_tys = fn->get_param_types();
    hook_fn->ret_ty = fn->get_return_type();

    create_jitted_facilitator(hook_fn, fn, [&]() -> uintptr_t {
        if (!vhook->vtable_hook->hook_method(fn->get_virtual_index(), (void*)hook_fn->facilitator_fn)) {
            spdlog::error("[HookManager] Failed to hook vtable method for {:x}", (uintptr_t)obj);
            return uintptr_t{0};
        }
        return vhook->vtable_hook->get_original<uintptr_t>(fn->get_virtual_index());
    });

    vhook->hooked_fns.emplace(fn, std::move(hook_fn));
    spdlog::info("[HookManager] VT Hook {} added for '{}' @ {:p}", hook_id, fn->get_name(), fn->get_function());
    return hook_id;
}

void HookManager::remove(sdk::REMethodDefinition* fn, HookId id) {
    if (!fn) return;

    if (auto search = m_hooked_fns.find(fn); search != m_hooked_fns.end()) {
        spdlog::info("[HookManager] Removing hook ID {} from '{}'", id, fn->get_name());
        auto& hook = search->second;
        std::scoped_lock _{hook->mux};
        std::unique_lock __{hook->access_mux};
        hook->remove_callback(id);
        return;
    }

    std::vector<::REManagedObject*> stale_vtables;
    for (auto& [obj, vhook] : m_hooked_vtables) {
        if (auto it = vhook->hooked_fns.find(fn); it != vhook->hooked_fns.end()) {
            spdlog::info("[HookManager] Removing VT method hook ID {} from '{}'", id, fn->get_name());
            auto& hook_fn = it->second;
            std::scoped_lock _{vhook->mux};
            std::unique_lock __{hook_fn->access_mux};
            if (hook_fn->remove_callback(id)) {
                stale_vtables.push_back(obj);
            }
        }
    }

    for (auto obj : stale_vtables) {
        spdlog::info("[HookManager] Removing VT hook for {:x}", (uintptr_t)obj);
        m_hooked_vtables.erase(obj);
    }
}

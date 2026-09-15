#include <algorithm>
#include <array>
#include <cstdint>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>
#include <vector>

#include <spdlog/spdlog.h>

#include <utility/Scan.hpp>
#include <utility/Module.hpp>

#include "Application.hpp"
#include "RETypeDB.hpp"
#include "RETypes.hpp"
#include "SceneManager.hpp"

#include "Renderer.hpp"

namespace sdk {
namespace renderer {
namespace detail {
// ---------------------------------------------------------------------------
// Engine function/vtable lookups.
//
// Everything in this block runs once, lazily, on the first call that needs it -
// never on a per-frame path. The engine functions are mostly found by scanning
// for a string they reference and then resolving one of the CALL instructions
// around it, so these helpers hold the variations of that recipe and each
// engine function only has to say which string and which call it wants.
// ---------------------------------------------------------------------------
using AddSceneViewFn = void (*)(void*);

// Scans for `pattern` and resolves the call target at `call_offset` in it.
template <typename Fn>
Fn find_fn_from_sig(std::string_view pattern, size_t call_offset) {
    const auto ref = utility::scan(utility::get_executable(), std::string{pattern});

    if (!ref) {
        return nullptr;
    }

    return (Fn)utility::calculate_absolute(*ref + call_offset);
}

AddSceneViewFn get_add_scene_view() {
    static const auto add_scene_view_fn = []() -> AddSceneViewFn {
        spdlog::info("[Renderer] Finding add_scene_view_fn");

        /*
        .text:0000000142952B16 41 8B 86 B4 0A 00 00                          mov     eax, [r14+0AB4h]
        .text:0000000142952B1D 83 E0 01                                      and     eax, 1
        .text:0000000142952B20 48 83 C0 1C                                   add     rax, 1Ch
        .text:0000000142952B24 48 69 C0 88 00 00 00                          imul    rax, 88h
        .text:0000000142952B2B 49 03 C6                                      add     rax, r14
        .text:0000000142952B2E 49 89 86 F0 0F 00 00                          mov     [r14+0FF0h], rax
        .text:0000000142952B35 48 8B 3D 4C 0C 39 06                          mov     rdi, cs:g_scene_manager
        .text:0000000142952B3C 48 8B 5F 20                                   mov     rbx, [rdi+20h]
        .text:0000000142952B40 48 8B CB                                      mov     rcx, rbx        ; lpCriticalSection
        .text:0000000142952B43 FF 15 67 E7 F6 01                             call    cs:EnterCriticalSection
        .text:0000000142952B49 45 33 C9                                      xor     r9d, r9d
        .text:0000000142952B4C 4C 8D 05 8D 0F 00 00                          lea     r8, addSceneView(via::SceneView*)
        */
        // String refs in the function containing this pattern:
        // L"Renderer::DelayEndTask"
        // L"Renderer::DelayReleaseTask"
        const auto fn = find_fn_from_sig<AddSceneViewFn>("4C 8D 05 ? ? ? ? 48 8D ? ? 48 8D ? 08 E8 ? ? ? ? 48 ? ? FF 15", 3);

        if (fn == nullptr) {
            spdlog::error("[Renderer] Failed to find add_scene_view_fn");
            return nullptr;
        }

        spdlog::info("[Renderer] add_scene_view_fn: {:x}", (uintptr_t)fn);

        return fn;
    }();

    return add_scene_view_fn;
}

// Follows the jmp thunk that some engine versions put in front of native
// methods. With `scan_instructions` > 0 the jmp is also looked for further into
// the function, for thunks that have some setup before jumping.
void* resolve_jmp(void* fn, size_t scan_instructions = 0) {
    if (fn == nullptr) {
        return nullptr;
    }

    if (((uint8_t*)fn)[0] == 0xE9) {
        return (void*)utility::calculate_absolute((uintptr_t)fn + 1);
    }

    if (scan_instructions == 0) {
        return fn;
    }

    const auto jmp = utility::scan_opcode((uintptr_t)fn, scan_instructions, 0xE9);

    if (!jmp) {
        return fn;
    }

    return (void*)utility::calculate_absolute(*jmp + 1);
}

// Walks `call_index` CALL instructions (1-based) forward from the instruction
// that references `needle` and resolves the target of the last one. The
// RenderContext functions all live that many calls behind one of their strings.
template <typename Fn>
Fn find_fn_after_string_ref(std::string_view name, std::string_view needle, size_t call_index, bool needle_is_standalone = false) {
    spdlog::info("[{}] Searching for {}", name, name);

    const auto game = utility::get_executable();
    std::optional<uintptr_t> string_data{};

    if (needle_is_standalone) {
        // The string can also be part of a longer one, only accept the copy that
        // starts right after a NUL byte.
        const auto all_strings = utility::scan_strings(game, std::string{needle}, true);

        if (all_strings.empty()) {
            spdlog::error("[{}] Failed to find {} strings", name, needle);
            return nullptr;
        }

        for (const auto& str : all_strings) {
            if (*(uint8_t*)(str - 1) == 0) {
                string_data = str;
                break;
            }
        }

        if (!string_data) {
            spdlog::error("[{}] Failed to find correct {} string", name, needle);
            return nullptr;
        }
    } else {
        string_data = utility::scan_string(game, std::string{needle});

        if (!string_data) {
            spdlog::error("[{}] Failed to find {} string", name, needle);
            return nullptr;
        }
    }

    const auto string_ref = utility::scan_displacement_reference(game, *string_data);

    if (!string_ref) {
        spdlog::error("[{}] Failed to find {} reference", name, needle);
        return nullptr;
    }

    std::optional<uintptr_t> call{};
    uintptr_t current_ip{*string_ref + 4};

    for (size_t i = 0; i < call_index; ++i) {
        call = utility::scan_mnemonic(current_ip, 100, "CALL");

        if (!call) {
            spdlog::error("[{}] Failed to find next CALL instruction", name);
            return nullptr;
        }

        current_ip = *call + 5;
    }

    const auto result = utility::resolve_displacement(*call);

    if (!result) {
        spdlog::error("[{}] Failed to resolve displacement", name);
        return nullptr;
    }

    spdlog::info("[{}] Found {} at {:x}", name, name, *result);

    return (Fn)*result;
}

// Resolves the instruction that references `needle`.
template <typename Str>
std::optional<uintptr_t> find_string_ref(std::string_view what, const Str& needle, bool zero_terminated = false) {
    const auto game = utility::get_executable();
    const auto string = utility::scan_string(game, needle, zero_terminated);

    if (!string) {
        spdlog::error("Failed to find {} (no string)", what);
        return std::nullopt;
    }

    const auto string_ref = utility::scan_displacement_reference(game, *string);

    if (!string_ref) {
        spdlog::error("Failed to find {} (no string ref)", what);
        return std::nullopt;
    }

    return string_ref;
}

// Scans backwards from a string reference for the `call_index`-th (1-based) CALL
// instruction and resolves its target.
std::optional<uintptr_t> find_call_behind(std::string_view what, uintptr_t string_ref, size_t call_index, size_t max_instructions) {
    uintptr_t ip = string_ref;
    size_t found = 0;

    for (size_t i = 0; i < max_instructions; ++i) {
        const auto resolved = utility::resolve_instruction(ip);

        if (!resolved) {
            spdlog::error("Failed to find {} (could not resolve instruction)", what);
            return std::nullopt;
        }

        ip = resolved->addr;

        if (*(uint8_t*)ip == 0xE8 && ++found == call_index) {
            return utility::calculate_absolute(ip + 1);
        }

        ip -= 1;
    }

    return std::nullopt;
}

// Locates one of the engine's resource factories. They are all found the same
// way: `call_index` CALL instructions before the code that references `needle`.
template <typename Fn, typename Str>
Fn find_factory(std::string_view what, const Str& needle, size_t call_index, size_t max_instructions) {
    spdlog::info("Searching for {}", what);

    const auto string_ref = find_string_ref(what, needle);

    if (!string_ref) {
        return nullptr;
    }

    const auto call = find_call_behind(what, *string_ref, call_index, max_instructions);

    if (!call) {
        return nullptr;
    }

    spdlog::info("Found {}: {:x}", what, *call);

    return (Fn)*call;
}

using AddLayerFn = RenderLayer* (*)(RenderLayer*, ::REType*, uint32_t, uint8_t);

// RenderLayer::AddLayer is the most-called function inside addSceneView, so
// disassemble it and take the call target that shows up the most.
AddLayerFn find_add_layer_via_disassembly() {
    auto add_scene_view_fn = get_add_scene_view();

    if (add_scene_view_fn == nullptr) {
        return nullptr;
    }

    spdlog::info("[Renderer] Scanning for RenderLayer::AddLayer using disassembler");

    if (const auto resolved = resolve_jmp(add_scene_view_fn, 4); resolved != add_scene_view_fn) {
        add_scene_view_fn = (decltype(add_scene_view_fn))resolved;
        spdlog::info("[Renderer] Jmp detected, add_scene_view_fn: {:x}", (uintptr_t)add_scene_view_fn);
    }

    uintptr_t ip = (uintptr_t)add_scene_view_fn;

    std::unordered_map<uintptr_t, uint32_t> calls;
    uintptr_t best_call = 0;

    for (auto i = 0 ; i < 150; ++i) {
        const auto decoded = utility::decode_one((uint8_t*)ip);

        if (!decoded) {
            spdlog::error("[Renderer] Failed to decode instruction @ 0x{:x} ({:x})", ip, ip - (uintptr_t)add_scene_view_fn);
            break;
        }

        if (std::string_view{decoded->Mnemonic}.starts_with("RET") || std::string_view{decoded->Mnemonic}.starts_with("INT3")) {
            spdlog::error("[Renderer] Encountering RET or INT3 @ 0x{:x} ({:x})", ip, ip - (uintptr_t)add_scene_view_fn);
            break;
        }

        if (*(uint8_t*)ip == 0xE8) {
            const auto addr = utility::calculate_absolute(ip + 1);
            calls[addr]++;

            if (best_call != 0) {
                if (calls[best_call] < calls[addr]) {
                    best_call = addr;
                }
            } else {
                best_call = addr;
            }

            if (calls[addr] >= 3) {
                spdlog::info("[Renderer] Found 3 calls to add_scene_view_fn, stopping scan");
                break;
            }
        }

        ip += decoded->Length;
    }

    if (best_call == 0) {
        spdlog::error("[Renderer] Failed to find RenderLayer::AddLayer using a disassembler");
        return nullptr;
    }

    spdlog::info("[Renderer] RenderLayer::AddLayer found at {:x}", best_call);

    return (AddLayerFn)best_call;
}

// Offsets of the members of the renderer object that hold a RenderLayer.
// Both callers cache the offset themselves, this only does the scan.
std::optional<size_t> find_render_layer_member_offset(void* renderer) {
    for (size_t i = 0; i < 0x10000; i += sizeof(void*)) {
        const auto ptr = *(REManagedObject**)((uintptr_t)renderer + i);

        if (ptr == nullptr) {
            continue;
        }

        if (!utility::re_managed_object::is_managed_object(ptr)) {
            continue;
        }

        if (utility::re_managed_object::is_a(ptr, "via.render.RenderLayer")) {
            return i;
        }
    }

    return std::nullopt;
}

// Bruteforces the offset of a member holding an object whose vtable's type info
// getter (slot 3) returns a RETypeCLR with the name `want_type`. Used for the
// structures that are not part of the TDB.
std::optional<size_t> find_type_info_member(void* obj, size_t begin, size_t end, std::string_view want_type, std::string_view log_prefix) {
    static constexpr size_t GET_TYPEINFO_FN_INDEX = 3;

    for (size_t i = begin; i < end; i += sizeof(void*)) try {
        // Grab vtable.
        const auto ptr = *(uintptr_t*)((uintptr_t)obj + i);

        if (ptr == 0 || IsBadReadPtr((void*)ptr, sizeof(void*))) {
            continue;
        }

        const auto vtable = *(uintptr_t**)ptr;

        if (vtable == 0 || IsBadReadPtr((void*)vtable, sizeof(void*))) {
            continue;
        }

        const auto get_typeinfo_fn = vtable[GET_TYPEINFO_FN_INDEX];

        if (get_typeinfo_fn == 0 || IsBadReadPtr((void*)get_typeinfo_fn, sizeof(void*))) {
            continue;
        }

        if (!utility::get_module_within(get_typeinfo_fn)) {
            continue;
        }

        // The generated accessor is a plain "mov rax, [rip+disp32]".
        if (((uint8_t*)get_typeinfo_fn)[0] != 0x48 || ((uint8_t*)get_typeinfo_fn)[1] != 0x8B || ((uint8_t*)get_typeinfo_fn)[2] != 0x05) {
            spdlog::info("[{}] Skipping offset {:x} because get_typeinfo_fn does not look like a mov rax", log_prefix, i);
            continue;
        }

        const auto type_info = ((sdk::RETypeCLR* (*)())get_typeinfo_fn)();

        if (type_info == nullptr || IsBadReadPtr(type_info, sizeof(void*))) {
            continue;
        }

        if (type_info->name == nullptr || IsBadReadPtr(type_info->name, sizeof(void*))) {
            continue;
        }

        const auto type_name = std::string_view{type_info->name};

        if (type_name == want_type) {
            spdlog::info("[{}] Found {} at offset {:x}", log_prefix, want_type, i);
            return i;
        }

        spdlog::info("[{}] Checked offset {:x}, type name: {}", log_prefix, i, type_name);
    } catch(...) {
        continue;
    }

    return std::nullopt;
}

// via.render.layer.Scene's REType, looked up once.
::REType* scene_layer_type() {
    static const auto type = []() -> ::REType* {
        const auto def = sdk::find_type_definition("via.render.layer.Scene");
        return def != nullptr ? def->get_type() : nullptr;
    }();

    return type;
}

// Visits every direct child layer whose type is exactly `layer_type`. The layer
// is handed over as it is stored in the parent's array, so the address of its
// slot can be taken. `fn` returns true to stop the iteration.
template <typename Fn>
void for_each_layer_of_type(RenderLayer* self, ::REType* layer_type, Fn&& fn) {
    for (RenderLayer*& layer : self->get_layers()) {
        if (layer == nullptr || layer->info == nullptr || layer->info->classInfo == nullptr) {
            continue;
        }

        if (utility::re_managed_object::get_type(layer) != layer_type) {
            continue;
        }

        if (fn(layer)) {
            return;
        }
    }
}

// Memoizes the reflection descriptor of a field. Resolving one builds a string
// and takes a lock, so the per-frame getters must not pay for that every call.
class FieldRef {
public:
    FieldRef(::REType* owner, std::string_view name)
        : m_owner{owner},
          m_name{name},
          m_desc{owner != nullptr ? utility::re_type::get_field_desc(owner, name) : nullptr} {}

    template <typename T>
    T get(::REManagedObject* obj) const {
        // Only reuse the descriptor for objects of exactly the cached type,
        // a derived class may shadow the field.
        if (m_desc != nullptr && utility::re_managed_object::get_type(obj) == m_owner) {
            return utility::re_managed_object::get_field<T>(obj, m_desc);
        }

        return utility::re_managed_object::get_field<T>(obj, m_name);
    }

private:
    ::REType* m_owner;
    std::string_view m_name;
    VariableDescriptor* m_desc;
};
} // namespace detail

RenderLayer* RenderLayer::add_layer(::REType* layer_type, uint32_t priority, uint8_t offset) {
    // can be found inside addSceneView
    static const auto add_layer_fn = []() -> detail::AddLayerFn {
        spdlog::info("[Renderer] Finding RenderLayer::AddLayer");

        const auto mod = utility::get_executable();

        auto ref = utility::scan(mod, "41 B8 00 00 00 05 48 8B F8 E8 ? ? ? ?"); // mov r8d, 5000000h; call add_layer

        if (!ref) {
            // Fallback pattern
            ref = utility::scan(mod, "41 B8 00 00 00 05 48 89 C7 E8 ? ? ? ?"); // mov r8d, 5000000h; call add_layer
        }

        if (!ref) {
            const auto disassembled = detail::find_add_layer_via_disassembly();

            if (disassembled == nullptr) {
                spdlog::error("[Renderer] Failed to find add_layer");
                return nullptr;
            }

            return disassembled;
        }

        const auto add_layer_fn = (detail::AddLayerFn)utility::calculate_absolute(*ref + 10);

        if (add_layer_fn == nullptr || IsBadReadPtr(add_layer_fn, sizeof(add_layer_fn))) {
            spdlog::error("[Renderer] Failed to calculate add_layer");
            return nullptr;
        }

        spdlog::info("[Renderer] RenderLayer::AddLayer: {:x}", (uintptr_t)add_layer_fn);

        return add_layer_fn;
    }();

    if (add_layer_fn == nullptr) {
        return nullptr;
    }

    return add_layer_fn(this, layer_type, priority, offset);
}

sdk::NativeArray<RenderLayer*>& RenderLayer::get_layers() {
    static uint32_t layers_offset = 0;

    if (layers_offset == 0) {
        spdlog::info("[Renderer] Finding RenderLayer::layers");

        const auto root_layer = sdk::renderer::get_root_layer();

        if (root_layer == nullptr) {
            spdlog::error("[Renderer] Failed to find root layer");
            throw std::runtime_error("[Renderer] Failed to find root layer");
        }

        // Scan through the root layer for a pointer to a RenderLayer object
        for (auto i = 0; i < 0x500; i += sizeof(void*)) {
            auto ptr = *(RenderLayer***)((uintptr_t)root_layer + i);

            if (ptr == nullptr || IsBadReadPtr(ptr, sizeof(ptr))) {
                continue;
            }

            const auto potential_layer = *ptr;

            if (potential_layer == nullptr || IsBadReadPtr(potential_layer, sizeof(potential_layer))) {
                continue;
            }

            if (!utility::re_managed_object::is_managed_object(potential_layer)) {
                continue;
            }

            if (utility::re_managed_object::is_a(potential_layer, "via.render.RenderLayer")) {
                layers_offset = i;
                break;
            }
        }

        spdlog::info("[Renderer] RenderLayer::layers: {:x}", layers_offset);
    }

    return *(sdk::NativeArray<RenderLayer*>*)((uintptr_t)this + layers_offset);
}

RenderLayer** RenderLayer::find_layer(::REType* layer_type) {
    RenderLayer** out = nullptr;

    detail::for_each_layer_of_type(this, layer_type, [&out](RenderLayer*& layer) {
        out = &layer;
        return true;
    });

    return out;
}

std::tuple<RenderLayer*, RenderLayer**> RenderLayer::find_layer_recursive(const ::REType* layer_type) {
    for (RenderLayer*& layer : get_layers()) {
        if (layer == nullptr || layer->info == nullptr || layer->info->classInfo == nullptr) {
            continue;
        }

        if (utility::re_managed_object::get_type(layer) == layer_type) {
            return {this, &layer};
        }

        if (auto f = layer->find_layer_recursive(layer_type); std::get<0>(f) != nullptr && std::get<1>(f) != nullptr) {
            return f;
        }
    }

    return {nullptr, nullptr};
}

std::tuple<RenderLayer*, RenderLayer**> RenderLayer::find_layer_recursive(std::string_view type_name) {
    const auto def = sdk::find_type_definition(type_name);

    if (def == nullptr) {
        return {nullptr, nullptr};
    }

    const auto t = def->get_type();

    if (t == nullptr) {
        return {nullptr, nullptr};
    }

    return find_layer_recursive(t);
}

std::vector<RenderLayer*> RenderLayer::find_layers(::REType* layer_type) {
    std::vector<RenderLayer*> out{};

    detail::for_each_layer_of_type(this, layer_type, [&out](RenderLayer*& layer) {
        out.push_back(layer);
        return false;
    });

    return out;
}

std::vector<layer::Scene*> RenderLayer::find_all_scene_layers() {
    const auto scene_type = detail::scene_layer_type();

    if (scene_type == nullptr) {
        return {};
    }

    auto layers = find_layers(scene_type);

    if (layers.empty()) {
        return {};
    }

    return *(std::vector<layer::Scene*>*)&layers;
}

std::vector<layer::Scene*> RenderLayer::find_fully_rendered_scene_layers() {
    std::vector<layer::Scene*> out{};
    find_fully_rendered_scene_layers(out);
    return out;
}

void RenderLayer::find_fully_rendered_scene_layers(std::vector<layer::Scene*>& out) {
    out.clear();

    struct Entry {
        uint32_t view_id;
        layer::Scene* scene;
    };

    // Reused across calls, so this only allocates on the very first one. The layers are
    // collected before anything else runs, leaving the tree untouched while the engine getters
    // further down are called.
    static thread_local std::vector<Entry> entries{};
    entries.clear();

    detail::for_each_layer_of_type(this, detail::scene_layer_type(), [](RenderLayer*& layer) {
        entries.push_back({0, (layer::Scene*)layer});
        return false;
    });

    std::erase_if(entries, [](Entry& entry) {
        return !entry.scene->is_fully_rendered();
    });

    // get_view_id() is a reflected function call, so it is fetched once per layer and sorted on,
    // rather than once per comparison.
    for (auto& entry : entries) {
        entry.view_id = entry.scene->get_view_id();
    }

    // Sorted on the id alone, which is all the previous comparator looked at, so layers sharing
    // an id still come out in the same order.
    std::sort(entries.begin(), entries.end(), [](const Entry& a, const Entry& b) {
        return a.view_id < b.view_id;
    });

    out.reserve(entries.size());

    for (const auto& entry : entries) {
        out.push_back(entry.scene);
    }
}

RenderLayer* RenderLayer::get_parent() {
    // Cached: call_object_func hashes the method name and takes a lock on every
    // call, and this is called per frame.
    static const auto get_parent_method = sdk::find_method_definition("via.render.RenderLayer", "get_Parent");

    if (get_parent_method == nullptr) {
        return nullptr;
    }

    return get_parent_method->call<RenderLayer*>(sdk::get_thread_context(), this);
}

void RenderLayer::set_parent(RenderLayer* layer) {
    static std::optional<uint32_t> offset = std::nullopt;

    if (!offset) {
        const auto parent = get_parent();

        if (parent != nullptr) {
            for (auto i = 0; i < 0x100; i += sizeof(void*)) {
                if (*(RenderLayer**)((uintptr_t)this + i) == parent) {
                    offset = i;
                    spdlog::info("[Renderer] Parent offset: {:x}", i);
                    break;
                }
            }
        }
    }

    if (offset.has_value()) {
        *(RenderLayer**)((uintptr_t)this + *offset) = layer;
    }
}

RenderLayer* RenderLayer::find_parent(::REType* layer_type) {
    for (auto parent = get_parent(); parent != nullptr; parent = parent->get_parent()) {
        if (parent->info == nullptr || parent->info->classInfo == nullptr) {
            break;
        }

        const auto t = utility::re_managed_object::get_type(parent);

        if (t == layer_type) {
            return parent;
        }
    }

    return nullptr;
}

RenderLayer* RenderLayer::clone(bool recursive) {
    auto new_layer = (RenderLayer*)utility::re_managed_object::get_type_definition(this)->create_instance_full();

    if (new_layer == nullptr) {
        spdlog::error("[Renderer] Failed to clone layer");
        return nullptr;
    }

    new_layer->clone(this, recursive);

    return new_layer;
}

void RenderLayer::clone(RenderLayer* other, bool recursive) {
    this->m_parent = other->m_parent;
    this->m_priority = other->m_priority;

#if TDB_VER > 49
    for (auto i = 0; i < sdk::renderer::RenderLayer::NUM_PRIORITY_OFFSETS; ++i) {
        this->m_priority_offsets[i] = other->m_priority_offsets[i];
    }
#endif

    this->clone_layers(other, recursive);
}

void RenderLayer::clone_layers(RenderLayer* other, bool recursive) {
    for (auto child_layer : other->get_layers()) {
        if (child_layer == this) {
            continue;
        }

        const auto def = utility::re_managed_object::get_type_definition(child_layer);

        if (def == nullptr) {
            continue;
        }

        const auto t = def->get_type();

        if (t == nullptr) {
            continue;
        }

        if (this->find_layer(t) != nullptr) {
            continue;
        }

        auto new_child_layer = add_layer(t, child_layer->m_priority);

        if (recursive && new_child_layer != nullptr) {
            new_child_layer->clone_layers(child_layer, recursive);
        }
    }
}

::sdk::renderer::TargetState* RenderLayer::get_target_state(std::string_view name) {
    return utility::re_managed_object::get_field<::sdk::renderer::TargetState*>(this, name);
}

void RenderContext::set_pipeline_state(sdk::renderer::PipelineState* pipeline_state) {
    using Fn = void (*)(RenderContext*, sdk::renderer::PipelineState*);
    static const Fn set_pipeline_state_fn = detail::find_fn_after_string_ref<Fn>("RenderContext::set_pipeline_state", "UpdateDepthBlockerState", 4);

    if (set_pipeline_state_fn == nullptr) {
        return;
    }

    set_pipeline_state_fn(this, pipeline_state);
}
void RenderContext::dispatch_ray(uint32_t tgx, uint32_t tgy, uint32_t tgz, Fence& fence) {
    using Fn = void (*)(RenderContext*, uint32_t, uint32_t, uint32_t, Fence*);
    static const Fn func = detail::find_fn_after_string_ref<Fn>("RenderContext::dispatch_ray", "PathSpaceRayTracing", 6);

    if (func == nullptr) {
        return;
    }

    func(this, tgx, tgy, tgz, &fence);
}

void RenderContext::dispatch_32bit_constant(uint32_t tgx, uint32_t tgy, uint32_t tgz, uint32_t constant, bool disable_uav_barrier) {
    using Fn = void (*)(RenderContext*, uint32_t, uint32_t, uint32_t, uint32_t, bool);
    static const Fn func = detail::find_fn_after_string_ref<Fn>("RenderContext::dispatch_32bit_constant", "ClearDepthBlockerState", 6);

    if (func == nullptr) {
        return;
    }

    func(this, tgx, tgy, tgz, constant, disable_uav_barrier);
}

void RenderContext::dispatch(uint32_t tgx, uint32_t tgy, uint32_t tgz, bool disable_uav_barrier) {
    using Fn = void (*)(RenderContext*, uint32_t, uint32_t, uint32_t, bool);
    static const Fn func = detail::find_fn_after_string_ref<Fn>("RenderContext::dispatch", "Reconstruct", 6, true);

    if (func == nullptr) {
        return;
    }

    func(this, tgx, tgy, tgz, disable_uav_barrier);
}

sdk::renderer::command::Base* RenderContext::alloc(uint32_t t, uint32_t size) {
    // I am just being very lazy right now and just using a pattern instead of 
    // using copy_texture and scanning through the function for the first call
    static const auto func = []() -> sdk::renderer::command::Base* (*)(RenderContext*, uint32_t, uint32_t) {
        spdlog::info("Searching for RenderContext::alloc");

        /*
            // In wilds this looks more like this
            BA 09 00 00 00    mov     edx, 9
            41 B8 30 00 00 00 mov     r8d, 30h
            E8 ? ? ? ?        call    alloc
        */
        const auto game = utility::get_executable();
        const auto scan_result = utility::scan(game, "48 8b ? 44 8d 42 38 e8 ? ? ? ?");

        if (!scan_result) {
            const auto midfn_result = utility::scan(game, "81 FF ? 08 00 00 *[32] 8D ? 0F 83 ? f0");

            if (midfn_result) {
                const auto fn_start = utility::find_function_start_unwind(*midfn_result);
                if (!fn_start) {
                    spdlog::error("Failed to find start of function for potential RenderContext::alloc");
                    return nullptr;
                }
                spdlog::info("Found potential RenderContext::alloc at {:x} using mid-function pattern", *fn_start);
                return (sdk::renderer::command::Base* (*)(RenderContext*, uint32_t, uint32_t))*fn_start;
            }

            spdlog::error("Failed to find RenderContext::alloc");
            return nullptr;
        }

        const auto result = utility::calculate_absolute(*scan_result + 8);

        spdlog::info("Found RenderContext::alloc at {:x}", result);

        return (sdk::renderer::command::Base* (*)(RenderContext*, uint32_t, uint32_t))result;
    }();

    if (func == nullptr) {
        return nullptr;
    }

    return func(this, t, size);
}

static_assert(offsetof(command::Clear, clear_color) == 0x28, "Clear::clear_color offset is wrong");
static_assert(offsetof(command::Clear, view) == 0x20, "Clear::view offset is wrong");
static_assert(offsetof(command::Clear, target) == 0x18, "Clear::target offset is wrong");

void RenderContext::clear_rtv(sdk::renderer::RenderTargetView* rtv, float color[4], bool delay) {
    if (rtv == nullptr) {
        return;
    }

    static const auto clear_typeid = sdk::get_enum_value<uint32_t>("via.render.command.TypeId", "Clear");
    auto new_command = (command::Clear*)alloc(clear_typeid, sizeof(command::Clear));

    if (new_command != nullptr) {
        new_command->target = get_render_target();
        new_command->clear_type = delay && is_delay_enabled() ? 128 : 0;
        new_command->view.rtv = rtv;
        new_command->clear_color[0] = color[0];
        new_command->clear_color[1] = color[1];
        new_command->clear_color[2] = color[2];
        new_command->clear_color[3] = color[3];
        rtv->m_render_frame = get_protect_frame();
    }
}

/*
- 0x9B CopyImage
+ 0x93 ReadonlyDepth
- 0x8A TemporalDenoiserGBufferCombine
+ 0x85 PrevAODepth
- 0x75 InputVelocity
- 0x6D ModifiedGBufferSRV
+ 0x66 g_BilateralUpscaleDownscaledDepth
- 0x62 RE_POSTPROCESS_Color
- 0x5B CopyImage
+ 0x48 PostEffect Copy
- 0x2D InputVelocity
- 0x24 InterleaveNormalDepth
- 0x1D InterleaveNormalDepthHalf
- 0x1D RE_POSTPROCESS_Color
- 0x14 InterleaveNormalDepthWithoutGBuffer
- 0x11 CopyImage
- 0xD InterleaveNormalDepthHalfWithoutGBuffer
*/
// In DD2+ there's some extra garbage going on that we don't want to deal with,
// so the RenderContext::copy_texture function is called directly instead of
// building a copy command.
void RenderContext::copy_texture(Texture* dest, Texture* src, Fence& fence) {
#if TDB_VER < 82
    using CopyTexFn = void (*)(RenderContext*, Texture*, Texture*, Fence&);
    static const auto func = []() -> CopyTexFn {
        spdlog::info("Searching for RenderContext::copy_texture");

        std::vector<std::string> string_choices {
            // CopyTexture isn't directly behind InterleaveNormalDepthHalfWithoutGBuffer in DD2+
#if TDB_VER < 73
            "InterleaveNormalDepthHalfWithoutGBuffer",
#endif
            "opyImage", // Engine has a weird optimization sometimes where it starts from the +1 offset
            "CopyImage",
        };

        for (const auto& str_choice : string_choices) {
            spdlog::info("Scanning for string: {}", str_choice);

            const auto string_ref = detail::find_string_ref("copy_texture", str_choice, true);

            if (!string_ref) {
                continue;
            }

            const auto call = detail::find_call_behind("copy_texture", *string_ref, 1, 20);

            if (call) {
                spdlog::info("Found copy_texture: {:x}", *call);
                return (CopyTexFn)*call;
            }
        }

        spdlog::error("Could not find copy_texture, trying fallback");

        const auto game = utility::get_executable();

        // Look for alloc call behind RE_POSTPROCESS_Color
        /*
            BA 01 00 00 00                                mov     edx, 1 ; this is the copy texture command type
            41 B8 30 00 00 00                             mov     r8d, 30h ; can change, can also be a lea instruction
            E8 9B A5 7E 09                                call    alloc
            48 85 C0                                      test    rax, rax
        */
        const auto basic_sig_scan = utility::scan(game, "BA 01 00 00 00 41 B8 30 00 00 00 E8 ? ? ? ? 48 85 C0");

        if (!basic_sig_scan) {
            spdlog::error("Failed to find copy_texture (fallback)");
            return nullptr;
        }

        const auto fn_start = utility::find_function_start_with_call(*basic_sig_scan);

        if (!fn_start) {
            spdlog::error("Failed to find copy_texture (fallback fn_start)");
            return nullptr;
        }

        spdlog::info("Found copy_texture (fallback): {:x}", *fn_start);

        return (CopyTexFn)*fn_start;
    }();

    if (func == nullptr) {
        return;
    }

    func(this, dest, src, fence);
#else
    using CopyTexFn = void (*)(RenderContext*, Texture*, int32_t, Texture*, int32_t, Fence&);
    static const auto func = []() -> CopyTexFn {
        spdlog::info("Searching for RenderContext::copy_texture (>= TDB82)");

        const auto game = utility::get_executable();
        // constants 0x301 (the typeid 1 or'd with something) 0x36, 0x3f, 0x2a.
        const auto mid_result = utility::scan(game, "01 03 00 00 *[64] 36 *[32] 3f *[32] 2a");

        if (!mid_result) {
            spdlog::error("Failed to find copy_texture (>= TDB82)");
            return nullptr;
        }

        const auto fn_start = utility::find_function_start_unwind(*mid_result);

        if (!fn_start) {
            spdlog::error("Failed to find copy_texture function start (>= TDB82)");
            return nullptr;
        }

        spdlog::info("Found copy_texture (>= TDB82) at {:x}", *fn_start);

        return (CopyTexFn)*fn_start;
    }();

    if (func == nullptr) {
        return;
    }

    // src, src_subresource, dst, dst_subresource, fence
    func(this, src, -1, dest, -1, fence);
#endif
}

std::optional<uint32_t> Renderer::get_render_frame() const {
    static const auto tdef = sdk::find_type_definition("via.render.Renderer");
    static const auto m = tdef != nullptr ? tdef->get_method("get_RenderFrame") : nullptr;

    if (m == nullptr) {
        return std::nullopt;
    }

    return m->call<uint32_t>(sdk::get_thread_context(), this);
}

ConstantBuffer* Renderer::get_constant_buffer(std::string_view name) const {
    static const auto tdef = sdk::find_type_definition("via.render.Renderer");
    static const auto t = tdef != nullptr ? tdef->get_type() : nullptr;
    const auto field_desc = utility::re_type::get_field_desc(t, name);
    return utility::re_managed_object::get_field<ConstantBuffer*>((::REManagedObject*)this, field_desc);
}

Renderer* get_renderer() {
    return (Renderer*)sdk::get_native_singleton("via.render.Renderer");
}

// The rendering entry points are all invoked the same way, through the
// application's function table.
void wait_rendering() {
    static const auto entry = sdk::Application::get()->get_function("WaitRendering");
    entry->func(entry->entry);
}

void begin_rendering() {
    static const auto entry = sdk::Application::get()->get_function("BeginRendering");
    entry->func(entry->entry);
}

void end_rendering() {
    static const auto entry = sdk::Application::get()->get_function("EndRendering");
    entry->func(entry->entry);
}

void begin_update_primitive() {
    static const auto entry = sdk::Application::get()->get_function("BeginUpdatePrimitive");
    entry->func(entry->entry);
}

void update_primitive() {
    static const auto entry = sdk::Application::get()->get_function("UpdatePrimitive");
    entry->func(entry->entry);
}

void end_update_primitive() {
    static const auto entry = sdk::Application::get()->get_function("EndUpdatePrimitive");
    entry->func(entry->entry);
}

void add_scene_view(void* scene_view) {
    if (const auto add_scene_view_fn = detail::get_add_scene_view()) {
        add_scene_view_fn(scene_view);
    }
}

void remove_scene_view(void* scene_view) {
    static const auto remove_scene_view_fn = []() -> void (*)(void*) {
        spdlog::info("[Renderer] Finding remove_scene_view_fn");

        // Almost the same as add_scene_view pattern, is set up right after add_scene_view
        const auto fn = detail::find_fn_from_sig<void (*)(void*)>("4C 8D 05 ? ? ? ? 48 8D ? ? ? 48 8D ? 28 E8 ? ? ? ? 48 ? ? FF 15", 3);

        if (fn == nullptr) {
            spdlog::error("[Renderer] Failed to find remove_scene_view_fn");
            return nullptr;
        }

        spdlog::info("[Renderer] remove_scene_view_fn: {:x}", (uintptr_t)fn);

        return fn;
    }();

    if (remove_scene_view_fn != nullptr) {
        remove_scene_view_fn(scene_view);
    }
}

RenderLayer* get_root_layer() {
    auto renderer = sdk::get_native_singleton("via.render.Renderer");

    if (renderer == nullptr) {
        spdlog::error("[Renderer] Failed to find renderer");
        return nullptr;
    }

    static uint32_t root_layer_offset = 0;

    if (root_layer_offset == 0) {
        spdlog::info("[Renderer] Finding root_layer_offset");

        auto get_output_layer_fn = sdk::find_native_method("via.render.Renderer", "getOutputLayer");

        if (get_output_layer_fn == nullptr) {
            spdlog::error("[Renderer] Failed to find getOutputLayer");

            // Hacky fix for >= TDB74
            const auto offset = detail::find_render_layer_member_offset(renderer);

            if (!offset) {
                spdlog::error("[Renderer] Failed to find root_layer_offset with fallback");
                return nullptr;
            }

            root_layer_offset = (uint32_t)*offset;
            spdlog::info("[Renderer] Found root_layer_offset with fallback: {:x}", root_layer_offset);

            return *(RenderLayer**)((uintptr_t)renderer + root_layer_offset);
        }

        // Resolve the jmp to the real function
        get_output_layer_fn = (decltype(get_output_layer_fn))detail::resolve_jmp(get_output_layer_fn, 10);

        spdlog::info("[Renderer] Real getOutputLayer: {:x}", (uintptr_t)get_output_layer_fn);

        // Find the offset to the root layer (RE3, RE8)
        auto ref = utility::scan((uintptr_t)get_output_layer_fn, 0x100, "48 8B 81 ? ? ? ?");

        if (!ref) {
            // Fallback pattern to scan for (RE2)
            ref = utility::scan((uintptr_t)get_output_layer_fn, 0x100, "4C 8B 80 ? ? ? ?");

            // fallback pattern to scan for (RE7)
            if (!ref) {
                ref = utility::scan((uintptr_t)get_output_layer_fn, 0x100, "4C 8B 89 ? ? ? ?"); // mov r9, [rcx+?]
            }

            if (!ref) {
                spdlog::error("[Renderer] Failed to find root_layer_offset");
                return nullptr;
            }
        }

        root_layer_offset = *(uint32_t*)(*ref + 3);

        spdlog::info("[Renderer] root_layer_offset: {:x}", root_layer_offset);
    }

    return *(RenderLayer**)((uintptr_t)renderer + root_layer_offset);
}

RenderLayer* find_layer(::REType* layer_type) {
    auto renderer = sdk::get_native_singleton("via.render.Renderer");

    if (renderer == nullptr) {
        spdlog::error("[Renderer] Failed to find renderer");
        return nullptr;
    }

    static uint32_t layers_offset = 0;

    // Scan through the renderer object to find a RenderLayer pointer
    if (layers_offset == 0) {
        spdlog::info("[Renderer] Finding layers_offset");

        const auto offset = detail::find_render_layer_member_offset(renderer);

        if (!offset) {
            spdlog::error("[Renderer] Failed to find layers_offset");
            return nullptr;
        }

        layers_offset = (uint32_t)*offset;

        spdlog::info("[Renderer] layers_offset: {:x}", layers_offset);
    }

    const auto& layers = *(std::array<RenderLayer*, 256>*)((uintptr_t)renderer + layers_offset);

    for (auto& layer : layers) {
        if (layer == nullptr || layer->info == nullptr || layer->info->classInfo == nullptr) {
            continue;
        }

        const auto t = utility::re_managed_object::get_type(layer);

        if (t == layer_type) {
            return layer;
        }
    }

    return nullptr;
}

sdk::renderer::layer::Output* get_output_layer() {
    auto renderer_t = sdk::find_type_definition("via.render.Renderer");

    if (renderer_t == nullptr) {
        spdlog::error("[Renderer] Failed to find via.render.Renderer type");
        return nullptr;
    }

    static const auto get_output_layer_method = renderer_t->get_method("getOutputLayer");

    if (get_output_layer_method == nullptr) {
        auto root = get_root_layer();

        if (root == nullptr) {
            return nullptr;
        }

        static const auto output_t = sdk::find_type_definition("via.render.layer.Output");
        static const auto output_retype = output_t != nullptr ? output_t->get_type() : nullptr;

        auto [parent, found] = root->find_layer_recursive(output_retype);

        if (found == nullptr) {
            return nullptr;
        }

        return (sdk::renderer::layer::Output*)*found;
    }

    return sdk::call_native_func<sdk::renderer::layer::Output*>(nullptr, renderer_t, "getOutputLayer", sdk::get_thread_context(), nullptr);
}

std::optional<Vector2f> world_to_screen(const Vector3f& world_pos) {
    auto camera = sdk::get_primary_camera();

    if (camera == nullptr) {
        return std::nullopt;
    }

    auto main_view = sdk::get_main_view();

    if (main_view == nullptr) {
        return std::nullopt;
    }

    auto context = sdk::get_thread_context();

    static const auto transform_def = sdk::find_type_definition("via.Transform");
    static const auto math_t = sdk::find_type_definition("via.math");

    static const auto get_gameobject_method = transform_def->get_method("get_GameObject");
    static const auto get_axisz_method = transform_def->get_method("get_AxisZ");
    static const auto world_to_screen = math_t->get_method("worldPos2ScreenPos(via.vec3, via.mat4, via.mat4, via.Size)");

    auto camera_gameobject = get_gameobject_method->call<REGameObject*>(context, camera);
    auto camera_transform = camera_gameobject->transform;

    Matrix4x4f proj{}, view{};
    float screen_size[2]{};

    auto camera_origin = sdk::get_transform_position(camera_transform);
    camera_origin.w = 1.0f;

    Vector4f camera_forward{};
    get_axisz_method->call<void*>(&camera_forward, context, camera_transform);

    camera_forward.w = 1.0f;

    sdk::call_object_func<void*>(camera, "get_ProjectionMatrix", &proj, context, camera);
    sdk::call_object_func<void*>(camera, "get_ViewMatrix", &view, context, camera);
    sdk::call_object_func<void*>(main_view, "get_WindowSize", &screen_size, context, main_view);

    const Vector4f pos = Vector4f{world_pos, 1.0f};
    Vector4f screen_pos{};

    const auto delta = pos - camera_origin;

    // behind camera
    if (glm::dot(Vector3f{delta}, Vector3f{-camera_forward}) <= 0.0f) {
        return std::nullopt;
    }

    world_to_screen->call<void*>(&screen_pos, context, &pos, &view, &proj, &screen_size);

    return Vector2f{screen_pos.x, screen_pos.y};
}

/*
- 0x4B VortexelTurbulenceGPU::VelocitiesX
- 0x4A systems/shader/rayTracingDenoiserOld/rayTracingSimulation.sdf
- 0x46 systems/rendering/NullWhite.tex
- 0x46 systems/effect/Noise3D_MSK4.tex
- 0x19 UpdateDepthBlocker
- 0x19 Deinterlace
- 0x19 cbGeneratePolyline
- 0x19 cbTransformBasePoints
- 0x19 CBBakeType
- 0x19 cbGenerateBasePoints
*/
ConstantBuffer* create_constant_buffer(void* desc) {
    using Fn = ConstantBuffer* (*)(void*, void*);
    static const auto fn = detail::find_factory<Fn>("create_constant_buffer", "cbTransformBasePoints", 1, 20);

    if (fn == nullptr) {
        return nullptr;
    }

    return fn(nullptr, desc);
}

/*
+ 0x8B CircularDOF_WorkComponent0Im
+ 0x83 CircularDOF_WorkTexture
- 0x82 omposite
- 0x79 systems/effect/Stochastic_Sample8_MSK4.tex
+ 0x75 HDRImage
+ 0x73 HDRImage
- 0x6A HDRImage
- 0x67 systems/effect/Stochastic_Sample4_MSK4.tex
- 0x67 DensityMapTexture
- 0x5C systems/shader/advancedSystem.sdf
- 0x5A BaseColorTextrure
- 0x52 tSrc
- 0x4E HDRImage
- 0x4C CircularDOF_NearCOCFilteredHQ
- 0x3F CircularDOF_SceneMipTexture
*/
TargetState* create_target_state(TargetState::Desc* desc) {
    using Fn = TargetState* (*)(void*, TargetState::Desc*);
    // third call back from this string reference is the one we want
    static const auto fn = detail::find_factory<Fn>("create_target_state", "CircularDOF_SceneMipTexture", 3, 50);

    if (fn == nullptr) {
        return nullptr;
    }

    return fn(nullptr, desc);
}

/*
+ 0x217 Wrinkle_VertAreaSkin
- 0x20A EchoParam
+ 0x203 CapturePlane
+ 0x1F9 systems/shader/systemDevelop.sdf
+ 0x1F3 Wrinkle_ProbagateDupVertex
+ 0x1CF Wrinkle_ProbagateDupVertex_MaxMode
- 0x1CA PrevLDRImage
+ 0x1AB Wrinkle_DrawAreaToTexture2
- 0x1A5 MeshToUVTextureMap_2ndUVto1stUV
- 0x18A LDRImage
+ 0x187 Wrinkle_DrawAreaToTexture2_MaxMode
+ 0x163 Wrinkle_CheapBlur
- 0x145 MeshToUVTextureSkin2nd_Pos
+ 0xD9 systems/shader/speedTree/speedTree.sdf
- 0x18 width=%u,height=%u,depth=%u,mip=%u,array=%u,format=%u,usage=%u,bind=%u
*/
Texture* create_texture(Texture::Desc* desc) {
    using Fn = Texture* (*)(void*, Texture::Desc*);
    static constexpr auto needle = L"width=%u,height=%u,depth=%u,mip=%u,array=%u,format=%u,usage=%u,bind=%u";

    static const auto fn = []() -> Fn {
        if (const auto fn = detail::find_factory<Fn>("create_texture", needle, 1, 20)) {
            return fn;
        }

        spdlog::error("Failed to find create_texture, trying fallback");

        const auto string_ref = detail::find_string_ref("create_texture", needle);

        if (!string_ref) {
            return nullptr;
        }

        const auto fn_start = utility::find_function_start_with_call(*string_ref);

        if (!fn_start) {
            spdlog::error("Failed to find create_texture (no fallback)");
            return nullptr;
        }

        const auto first_call = utility::scan_mnemonic(*fn_start, 100, "CALL");

        if (!first_call) {
            spdlog::error("Failed to find create_texture (no first call)");
            return nullptr;
        }

        const auto second_call = utility::scan_mnemonic(*first_call + 1, 100, "CALL");

        if (!second_call) {
            spdlog::error("Failed to find create_texture (no second call)");
            return nullptr;
        }

        const auto result = (Texture* (*)(void*, Texture::Desc*))utility::calculate_absolute(*second_call + 1);

        spdlog::info("Found create_texture (fallback): {:x}", (uintptr_t)result);

        return result;
    }();

    static const auto renderer = sdk::renderer::get_renderer();

    if (fn == nullptr || renderer == nullptr) {
        return nullptr;
    }

    return fn(renderer->get_device(), desc);
}
/*
+ 0x20A Wrinkle_DrawAreaToTexture2
+ 0x1E6 Wrinkle_DrawAreaToTexture2_MaxMode
+ 0x1C2 Wrinkle_CheapBlur
- 0x1B8 EchoParam
+ 0x185 width=%u,height=%u,depth=%u,mip=%u,array=%u,format=%u,usage=%u,bind=%u
- 0x178 PrevLDRImage
- 0x168 systems/shader/advancedSystem.sdf
- 0x138 LDRImage
- 0xE0 BaseColorTextrure
- 0xD4 DensityMapTexture
- 0x9F BaseColorTextrure
*/
/*
48 C7 44 24 24 05 00 00 00                    mov     [rsp+78h+var_54], 5
C7 44 24 30 01 00 00 00                       mov     [rsp+78h+var_48], 1
44 89 7C 24 2C                                mov     [rsp+78h+var_4C], r15d
C7 44 24 20 1C 00 00 00                       mov     [rsp+78h+var_58], 1Ch
E8 89 EB 78 00                                call    create_render_target_view
*/

// In RE4+:
/*
- 0x269 CircularDOF_NearCOCFilteredHQ
- 0x266 CircularDOF_NearCOCMaskForTile
+ 0x261 CircularDOF_WorkComponent0Re
- 0x235 tSrc
+ 0x212 Wrinkle_CheapBlur
+ 0x212 Echo
- 0x1F1 CircularDOF_NearCOCMaskForTileHQ
+ 0x1F0 CircularDOF_WorkComponent0Im
- 0x1D0 CircularDOF_NearCOCFiltered
- 0x19A EchoParam
+ 0x15B width=%u,height=%u,depth=%u,mip=%u,array=%u,format=%u,usage=%u,bind=%u
- 0x15A PrevLDRImage
- 0x149 CircularDOF_NearCOCFilteredHQ
- 0x11A LDRImage
+ 0xC3 width=%u,height=%u,depth=%u,mip=%u,array=%u,format=%u,usage=%u,bind=%u
*/
/*
4C 8D 45 B8                                   lea     r8, [rbp+40h+var_88]
49 8B CE                                      mov     rcx, r14
E8 ? ? ? ?                                    call    create_render_target_view
48 8B 8F F0 04 00 00                          mov     rcx, [rdi+4F0h]
48 8B D8                                      mov     rbx, rax
4C 89 BF F0 04 00 00                          mov     [rdi+4F0h], r15
*/
RenderTargetView* create_render_target_view(sdk::renderer::RenderResource* resource, void* desc) {
    using Fn = RenderTargetView* (*)(void*, sdk::renderer::RenderResource* resource, void*);
    static const auto fn = []() -> Fn {
        spdlog::info("Searching for create_render_target_view");

        auto result = detail::find_fn_from_sig<Fn>("44 89 7C 24 2C C7 44 24 20 1C 00 00 00 E8 ? ? ? ?", 14);

        if (result == nullptr) {
            spdlog::info("Could not find first ref, performing fallback scan");
            result = detail::find_fn_from_sig<Fn>("4C 8D 45 B8 49 8B CE E8 ? ? ? ?", 8);
        }

        if (result == nullptr) {
            spdlog::error("Failed to find create_render_target_view (no ref)");
            return nullptr;
        }

        spdlog::info("Found create_render_target_view: {:x}", (uintptr_t)result);

        return result;
    }();

    if (fn == nullptr) {
        return nullptr;
    }

    return fn(nullptr, resource, desc);
}

ID3D12Resource* TargetState::get_native_resource_d3d12() const {
    const auto rtv = get_rtv(0);

    if (rtv == nullptr) {
        return nullptr;
    }

    // sizeof(via.render.RenderTargetView) + 8;
    const auto tex = rtv->get_texture_d3d12();

    if (tex == nullptr) {
        // An indirect target state owns no texture, its resource can be reached
        // through get_target_state_d3d12(). Not needed so far.
        return nullptr;
    }

    const auto internal_resource = tex->get_d3d12_resource_container();

    if (internal_resource == nullptr) {
        return nullptr;
    }

    return internal_resource->get_native_resource();
}

DirectXResource<ID3D12Resource>* Texture::get_d3d12_resource_container() {
#if TDB_VER < 71
    return *(DirectXResource<ID3D12Resource>**)((uintptr_t)this + s_d3d12_resource_offset);
#else
    static std::optional<size_t> offset = std::nullopt;

    if (!offset) {
        spdlog::info("Searching for Texture D3D12Resource offset (via.render.RenderResource bruteforce)");
        offset = detail::find_type_info_member(this, 0x98, 0x200, "via.render.RenderResource", "Texture");
    }

    if (!offset) {
        return nullptr;
    }

    return *(DirectXResource<ID3D12Resource>**)((uintptr_t)this + *offset);
#endif
}

Texture* Texture::clone() {
    return sdk::renderer::create_texture(get_desc());
}

sdk::intrusive_ptr<RenderTargetView> RenderTargetView::clone() {
    auto tex = this->get_texture_d3d12();

    if (tex == nullptr) {
        return nullptr;
    }

    return sdk::renderer::create_render_target_view(tex->clone(), &get_desc());
}

sdk::intrusive_ptr<RenderTargetView> RenderTargetView::clone(uint32_t new_width, uint32_t new_height) {
    auto tex = this->get_texture_d3d12();

    if (tex == nullptr) {
        return nullptr;
    }

    return sdk::renderer::create_render_target_view(tex->clone(new_width, new_height), &get_desc());
}

namespace detail {
#if TDB_VER >= 74
    constexpr auto rtv_size = 0xA8;
#elif TDB_VER >= 71
#if defined(SF6) || defined(DD2)
    constexpr auto rtv_size = 0x98;
#elif defined(MHRISE)
    constexpr auto rtv_size = 0x88;
#else
    constexpr auto rtv_size = 0x98 - sizeof(void*);
#endif
#elif TDB_VER == 70
    constexpr auto rtv_size = 0x90 - sizeof(void*);
#elif TDB_VER == 69
    constexpr auto rtv_size = 0x88 - sizeof(void*);
#elif TDB_VER <= 67
// TODO: 66 and below
    constexpr auto rtv_size = 0x88 - sizeof(void*);
#endif
}

sdk::intrusive_ptr<Texture>& RenderTargetView::get_texture_d3d12() const {
    // The via.render.RenderTargetView is not part of the normal TDB... I think.
    static const auto rtv_type = reframework::get_types()->get("via.render.RenderTargetView");

    // The texture and target state members are always at the very start of the RenderTargetViewDX12 structure
    // so we can very easily automate it like this, otherwise we fall back to the hardcoded offset
    if (rtv_type != nullptr && rtv_type->size > 0 && rtv_type->size < 0x1000) {
        const auto rtv_size = rtv_type->size;

#if TDB_VER >= 81
        return *(sdk::intrusive_ptr<Texture>*)((uintptr_t)this + rtv_size + (sizeof(void*) * 4)); // 0xE0 usually

#elif TDB_VER >= 74
        return *(sdk::intrusive_ptr<Texture>*)((uintptr_t)this + rtv_size + (sizeof(void*) * 4)); // 0xC8 usually
#elif TDB_VER < 73
        return *(sdk::intrusive_ptr<Texture>*)((uintptr_t)this + rtv_size + sizeof(void*));
#else
        return *(sdk::intrusive_ptr<Texture>*)((uintptr_t)this + rtv_size + (sizeof(void*) * 3));
#endif
    }
    
#if TDB_VER >= 74
    return *(sdk::intrusive_ptr<Texture>*)((uintptr_t)this + detail::rtv_size + (sizeof(void*) * 4)); // 0xC8 usually
#elif TDB_VER < 73
    return *(sdk::intrusive_ptr<Texture>*)((uintptr_t)this + detail::rtv_size + sizeof(void*));
#else
    return *(sdk::intrusive_ptr<Texture>*)((uintptr_t)this + detail::rtv_size + (sizeof(void*) * 3));
#endif
}

sdk::intrusive_ptr<TargetState>& RenderTargetView::get_target_state_d3d12() const {
    // The via.render.RenderTargetView is not part of the normal TDB... I think.
    static const auto rtv_type = reframework::get_types()->get("via.render.RenderTargetView");

    if (rtv_type != nullptr && rtv_type->size > 0 && rtv_type->size < 0x1000) {
        const auto rtv_size = rtv_type->size;

        return *(sdk::intrusive_ptr<TargetState>*)((uintptr_t)this + rtv_size);
    }
    
    return *(sdk::intrusive_ptr<TargetState>*)((uintptr_t)this + detail::rtv_size);
}

sdk::intrusive_ptr<TargetState> TargetState::clone() const {
    // Cloning without dimension overrides, the desc is copied as is.
    return clone(std::vector<std::array<uint32_t, 2>>{});
}

sdk::intrusive_ptr<TargetState> TargetState::clone(const std::vector<std::array<uint32_t, 2>>& new_dimensions) const {
    auto cloned_desc = get_desc();

    if (cloned_desc.num_rtv > 0) {
        cloned_desc.rtvs = (decltype(cloned_desc.rtvs))sdk::memory::allocate(cloned_desc.num_rtv * sizeof(void*));

        for (auto i = 0; i < cloned_desc.num_rtv; ++i) {
            auto rtv = get_rtv(i);

            if (rtv == nullptr) {
                continue;
            }

            if (i < new_dimensions.size()) {
                if (i == 0) {
                    cloned_desc.rect.right = (float)new_dimensions[i][0];
                    cloned_desc.rect.bottom = (float)new_dimensions[i][1];
                }

                cloned_desc.rtvs[i] = rtv->clone(new_dimensions[i][0], new_dimensions[i][1]);
            } else {
                cloned_desc.rtvs[i] = rtv->clone();
            }
        }
    } else {
        cloned_desc.rtvs = nullptr;
    }

    return sdk::renderer::create_target_state(&cloned_desc);
}

void*& layer::Output::get_present_state() {
    static uint32_t output_target_offset = 0;

    if (output_target_offset == 0) {
        spdlog::info("[Renderer] Finding output_target_offset");

        auto get_scene_view_fn = sdk::find_native_method("via.render.layer.Output", "get_SceneView");

        if (get_scene_view_fn == nullptr) {
            spdlog::error("[Renderer] Failed to find get_SceneView");
            return *(void**)((uintptr_t)this + sdk::find_type_definition("via.render.RenderLayer")->get_size());
        }

        // Resolve the jmp to the real function
        get_scene_view_fn = (decltype(get_scene_view_fn))detail::resolve_jmp(get_scene_view_fn);

        // Find the offset to the output target
        // First instruction is a mov, so we don't need to pattern scan for it
        output_target_offset = *(uint8_t*)((uintptr_t)get_scene_view_fn + 3);

        spdlog::info("[Renderer] output_target_offset: {:x}", output_target_offset);
    }

    return *(void**)((uintptr_t)this + output_target_offset);
}

REManagedObject*& layer::Output::get_scene_view() {
    static uint32_t scene_view_offset = 0;

    if (scene_view_offset == 0) {
        spdlog::info("[Renderer] Finding scene_view_offset");

        // because if this is a manually created output layer,
        // we might not have the scene view and output state set up yet
        auto top_output_layer = sdk::renderer::get_output_layer();

        if (top_output_layer == nullptr) {
            spdlog::error("[Renderer] Failed to find top_output_layer");
            return *(REManagedObject**)((uintptr_t)this + 0);
        }

        // Call get_SceneView so we can get a scene view
        // to scan the object for
        const auto scene_view = sdk::call_object_func<void*>(top_output_layer, "get_SceneView", sdk::get_thread_context(), top_output_layer);
        const auto output_target = top_output_layer->get_present_state();

        if (scene_view == nullptr) {
            spdlog::error("[Renderer] Failed to find scene_view");
            return *(REManagedObject**)((uintptr_t)this + 0);
        }

        if (output_target == nullptr) {
            spdlog::error("[Renderer] Failed to find output_target");
            return *(REManagedObject**)((uintptr_t)this + 0);
        }

        // Find the offset to the scene view
        for (auto i = 0; i < 0x1000; i += sizeof(void*)) {
            if (*(void**)((uintptr_t)output_target + i) == scene_view) {
                scene_view_offset = i;
                break;
            }
        }

        spdlog::info("[Renderer] scene_view_offset: {:x}", scene_view_offset);
    }

    return *(REManagedObject**)((uintptr_t)get_present_state() + scene_view_offset);
}

uint32_t layer::Scene::get_view_id() const {
    static const auto get_view_id_method = sdk::find_method_definition("via.render.layer.Scene", "get_ViewID");

    if (get_view_id_method == nullptr) {
        return 0;
    }

    return get_view_id_method->call<uint32_t>(sdk::get_thread_context(), this);
}

RECamera* layer::Scene::get_camera() const {
    static const auto get_camera_method = sdk::find_method_definition("via.render.layer.Scene", "get_Camera");

    if (get_camera_method == nullptr) {
        return nullptr;
    }

    return get_camera_method->call<RECamera*>(sdk::get_thread_context(), this);
}

RECamera* layer::Scene::get_main_camera_if_possible() const {
    const auto camera = get_camera();

    if (camera == nullptr) {
        return nullptr;
    }

    const auto camera_gameobject = utility::re_component::get_game_object(camera);

    if (camera_gameobject == nullptr) {
        return nullptr;
    }

    const auto name = utility::re_string::get_view(camera_gameobject->name);

    static constexpr std::array<std::wstring_view, 10> camera_names {
        L"MainCamera",
        L"Main Camera",
        L"GameCamera", // DMC5
        L"ess_DefaultCamera",
        L"ess_DefaultCamera_01",
        L"WTMainCamera",
        L"DefaultCamera",
        L"Camera_mainmenu",
        L"Camera_cp7mainmenu",
        L"SnowCamera", // MHRise
    };

    for (const auto& camera_name : camera_names) {
        if (name.starts_with(camera_name)) {
            return camera;
        }
    }

    return nullptr;
}

REManagedObject* layer::Scene::get_mirror() const {
    static const auto get_mirror_method = sdk::find_method_definition("via.render.layer.Scene", "get_Mirror");

    if (get_mirror_method == nullptr) {
        return nullptr;
    }

    return get_mirror_method->call<REManagedObject*>(sdk::get_thread_context(), this);
}

bool layer::Scene::is_enabled() const {
    static const auto is_enabled_method = sdk::find_method_definition("via.render.layer.Scene", "get_Enable");

    if (is_enabled_method == nullptr) {
        return false;
    }

    return is_enabled_method->call<bool>(sdk::get_thread_context(), this);
}

sdk::renderer::SceneInfo* layer::Scene::get_scene_info() {
    static const detail::FieldRef field{detail::scene_layer_type(), "SceneInfo"};
    return field.get<SceneInfo*>(this);
}

sdk::renderer::SceneInfo* layer::Scene::get_depth_distortion_scene_info() {
    static const detail::FieldRef field{detail::scene_layer_type(), "DepthDistortionSceneInfo"};
    return field.get<SceneInfo*>(this);
}

sdk::renderer::SceneInfo* layer::Scene::get_filter_scene_info() {
    static const detail::FieldRef field{detail::scene_layer_type(), "FilterSceneInfo"};
    return field.get<SceneInfo*>(this);
}

sdk::renderer::SceneInfo* layer::Scene::get_jitter_disable_scene_info() {
    static const detail::FieldRef field{detail::scene_layer_type(), "JitterDisableSceneInfo"};
    return field.get<SceneInfo*>(this);
}

sdk::renderer::SceneInfo* layer::Scene::get_jitter_disable_post_scene_info() {
    static const detail::FieldRef field{detail::scene_layer_type(), "JitterDisablePostSceneInfo"};
    return field.get<SceneInfo*>(this);
}

sdk::renderer::SceneInfo* layer::Scene::get_z_prepass_scene_info() {
    static const detail::FieldRef field{detail::scene_layer_type(), "ZPrepassSceneInfo"};
    return field.get<SceneInfo*>(this);
}

std::optional<size_t> layer::PrepareOutput::get_output_state_offset() {
    static std::optional<size_t> s_output_state_offset = std::nullopt;

    if (!s_output_state_offset) {
        s_output_state_offset = detail::find_type_info_member(this, 0x10, 0x500, "via.render.TargetState", "PrepareOutput");

        if (!s_output_state_offset) {
            spdlog::warn("[PrepareOutput] Failed to find output state offset, trying next time...");
        }
    }

    return s_output_state_offset;
}

Texture* layer::Scene::get_depth_stencil() {
    static const detail::FieldRef field{detail::scene_layer_type(), "DepthStencilTex"};
    return field.get<::sdk::renderer::Texture*>(this);
}

TargetState* layer::Scene::get_motion_vectors_state() {
    static const detail::FieldRef field{detail::scene_layer_type(), "VelocityTarget"};
    return field.get<::sdk::renderer::TargetState*>(this);
}

ID3D12Resource* layer::Scene::get_depth_stencil_d3d12() {
    const auto tex = get_depth_stencil();

    if (tex == nullptr) {
        return nullptr;
    }

    const auto internal_resource = tex->get_d3d12_resource_container();

    if (internal_resource == nullptr) {
        return nullptr;
    }

    return internal_resource->get_native_resource();
}
}
}

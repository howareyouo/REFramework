#include "Mods.hpp"
#include "REFramework.hpp"
#include <utility/Scan.hpp>
#include <utility/Module.hpp>
#include <utility/String.hpp>
#include <utility/Memory.hpp>

#include <type_traits>

#include "sdk/GUIPrimitiveSystem.hpp"
#include "sdk/Application.hpp"

#include "Hooks.hpp"

Hooks* g_hook = nullptr;

std::shared_ptr<Hooks>& Hooks::get() {
    static std::shared_ptr<Hooks> instance = std::make_shared<Hooks>();
    return instance;
}

Hooks::Hooks() {
    g_hook = this;
}

std::optional<std::string> Hooks::on_initialize() {
    auto game = g_framework->get_module().as<HMODULE>();

    if (!utility::get_module_size(game)) {
        return "Unable to get module size";
    }

    for (auto hook : m_hook_list) {
        spdlog::info("[Hooks] Entering hook...");

        auto result = hook();

        // Error occurred when hooking
        if (result) {
            return result;
        }
    }

    spdlog::info("[Hooks] Finished hooking");

    return Mod::on_initialize();
}

namespace {

// The single dispatch core shared by every "pre -> original -> post" hook.
//
// `original` performs the real call into the game (a trampoline with its
// arguments already bound), `pre`/`post` run once per mod. When `pre` returns
// bool it acts as a filter: if any mod returns false the original call is
// skipped, but every pre and every post still runs.
//
// While the framework is not ready only the original runs, so the game behaves
// exactly as if REFramework were not loaded during startup.
template <typename Original, typename Pre, typename Post>
auto dispatch(Original&& original, Pre&& pre, Post&& post) {
    if (!g_framework->is_ready()) {
        return original();
    }

    const auto& mods = g_framework->get_mods()->get_mods();

    bool run_original = true;

    for (const auto& mod : mods) {
        if constexpr (std::is_same_v<std::invoke_result_t<Pre, Mod*>, bool>) {
            if (!pre(mod.get())) {
                run_original = false;
            }
        } else {
            pre(mod.get());
        }
    }

    if constexpr (std::is_void_v<std::invoke_result_t<Original>>) {
        if (run_original) {
            original();
        }

        for (const auto& mod : mods) {
            post(mod.get());
        }
    } else {
        std::invoke_result_t<Original> ret{};

        if (run_original) {
            ret = original();
        }

        for (const auto& mod : mods) {
            post(mod.get());
        }

        return ret;
    }
}

} // namespace

// The static body for one render-layer callback. `x` names the mod callback
// fragment (scene/post_effect/...), `x2` the layer type, `x3` update/draw.
#define LAYER_HOOK_BODY(x, x2, x3) \
void Hooks::RenderLayerHook<sdk::renderer::layer::##x2##>::##x3##(sdk::renderer::layer::##x2##* layer, void* render_ctx) { \
    auto& hook = g_hook->m_layer_hooks.##x##.##x3##_hook; \
    dispatch([&] { hook.original(layer, render_ctx); }, \
             [layer, render_ctx](Mod* mod) { return mod->on_pre_##x##_layer_##x3##(layer, render_ctx); }, \
             [layer, render_ctx](Mod* mod) { mod->on_##x##_layer_##x3##(layer, render_ctx); }); \
}

LAYER_HOOK_BODY(scene, Scene, update);
LAYER_HOOK_BODY(scene, Scene, draw);
LAYER_HOOK_BODY(post_effect, PostEffect, update);
LAYER_HOOK_BODY(post_effect, PostEffect, draw);
LAYER_HOOK_BODY(overlay, Overlay, update);
LAYER_HOOK_BODY(overlay, Overlay, draw);
LAYER_HOOK_BODY(prepare_output, PrepareOutput, update);
LAYER_HOOK_BODY(prepare_output, PrepareOutput, draw);
LAYER_HOOK_BODY(output, Output, update);
LAYER_HOOK_BODY(output, Output, draw);

void* Hooks::update_transform_hook(RETransform* t, uint8_t a2, uint32_t a3) {
    auto& hook = g_hook->m_update_transform;

    if (!g_framework->is_ready()) {
        return hook.original(t, a2, a3);
    }

    // update_transform fires once per transform every frame, so it uses the
    // narrowed per-callback dispatch lists instead of the full mod list.
    const auto& dispatch_lists = g_framework->get_mods()->dispatch();

    for (auto* mod : dispatch_lists.pre_update_transform) {
        mod->on_pre_update_transform(t);
    }

    auto ret = hook.original(t, a2, a3);

    for (auto* mod : dispatch_lists.update_transform) {
        mod->on_update_transform(t);
    }

    return ret;
}

void* Hooks::update_camera_controller_hook(void* a1, RopewayPlayerCameraController* camera_controller) {
    auto& hook = g_hook->m_update_camera_controller;

    return dispatch(
        [&] { return hook.original(a1, camera_controller); },
        [camera_controller](Mod* mod) { mod->on_pre_update_camera_controller(camera_controller); },
        [camera_controller](Mod* mod) { mod->on_update_camera_controller(camera_controller); });
}

void* Hooks::update_camera_controller2_hook(void* a1, RopewayPlayerCameraController* camera_controller) {
    auto& hook = g_hook->m_update_camera_controller2;

    return dispatch(
        [&] { return hook.original(a1, camera_controller); },
        [camera_controller](Mod* mod) { mod->on_pre_update_camera_controller2(camera_controller); },
        [camera_controller](Mod* mod) { mod->on_update_camera_controller2(camera_controller); });
}

void* Hooks::gui_draw_hook(REComponent* gui_element, void* primitive_context) {
    auto& hook = g_hook->m_gui_draw;

    return dispatch(
        [&] { return hook.original(gui_element, primitive_context); },
        [&](Mod* mod) { return mod->on_pre_gui_draw_element(gui_element, primitive_context); },
        [&](Mod* mod) { mod->on_gui_draw_element(gui_element, primitive_context); });
}

void Hooks::update_before_lock_scene_hook(void* ctx) {
    auto& hook = g_hook->m_update_before_lock_scene;

    dispatch(
        [&] { hook.original(ctx); },
        [ctx](Mod* mod) { mod->on_pre_update_before_lock_scene(ctx); },
        [ctx](Mod* mod) { mod->on_update_before_lock_scene(ctx); });
}

void Hooks::global_application_entry_hook(void* entry, const char* name, size_t hash, void* original) {
    auto* self = g_hook;
    auto original_fn = (void (*)(void*))original;

    if (!g_framework->is_game_data_initialized()) {
        return original_fn(entry);
    }

    const auto should_allow_ignore = sdk::VM::s_tdb_version >= 73 ?
                                     (hash != 0x76b8100bec7c12c3 && hash != 0x9f63c0fc4eea6626) :
                                     true;

    if (should_allow_ignore) {
        std::shared_lock _{self->m_application_entry_data_mutex};

        if (self->m_ignored_application_entries.contains(hash)) {
            return;
        }
    }

    if (hash == "BeginRendering"_fnv) {
#if TDB_VER >= 73
        if (auto primitive_system = sdk::gui::renderer::PrimitiveSystem::get(); primitive_system != nullptr) {
            auto primitive_buffer = primitive_system->get_primitive_buffer();

            if (primitive_buffer != nullptr && primitive_buffer->scratch.used >= primitive_buffer->scratch.size) {
                spdlog::info("[GUI] Resizing scratch buffer from {} to {}", primitive_buffer->scratch.size, primitive_buffer->scratch.size * 2);
                primitive_buffer->scratch.resize(primitive_buffer->scratch.size * 2);
            }
        }
#endif
        g_framework->run_imgui_frame(false);
    }

    const auto& mods = g_framework->get_mods()->get_mods();

    for (auto& mod : mods) {
        mod->on_pre_application_entry(entry, name, hash);
    }

    original_fn(entry);

    for (auto& mod : mods) {
        mod->on_application_entry(entry, name, hash);
    }
}

float* Hooks::view_get_size_hook(REManagedObject* scene_view, float* result) {
    auto& hook = g_hook->m_view_get_size;

    return dispatch(
        [&] { return hook.original(scene_view, result); },
        [&](Mod* mod) { mod->on_pre_view_get_size(scene_view, result); },
        [&](Mod* mod) { mod->on_view_get_size(scene_view, result); });
}

Matrix4x4f* Hooks::camera_get_projection_matrix_hook(REManagedObject* camera, Matrix4x4f* result) {
    auto& hook = g_hook->m_camera_get_projection_matrix;

    return dispatch(
        [&] { return hook.original(camera, result); },
        [&](Mod* mod) { mod->on_pre_camera_get_projection_matrix(camera, result); },
        [&](Mod* mod) { mod->on_camera_get_projection_matrix(camera, result); });
}

Matrix4x4f* Hooks::camera_get_view_matrix_hook(REManagedObject* camera, Matrix4x4f* result) {
    auto& hook = g_hook->m_camera_get_view_matrix;

    return dispatch(
        [&] { return hook.original(camera, result); },
        [&](Mod* mod) { mod->on_pre_camera_get_view_matrix(camera, result); },
        [&](Mod* mod) { mod->on_camera_get_view_matrix(camera, result); });
}

namespace {

// Resolves a native method by name and installs its hook, reporting the same
// errors the individual hook_* functions used to build by hand.
template <typename Fn>
std::optional<std::string> hook_native_method(std::string_view type, std::string_view method, Hooks::GameHook<Fn>& slot, Fn* hook_fn) {
    auto func = sdk::find_native_method(type, method);

    if (func == nullptr) {
        return std::string{"Failed to find "} + std::string{type} + "::" + std::string{method};
    }

    spdlog::info("{}.{}: {:x}", type, method, (uintptr_t)func);

    if (!slot.create(func, hook_fn)) {
        return std::string{"Failed to hook "} + std::string{type} + "::" + std::string{method};
    }

    return std::nullopt;
}

// Resolves a native method by name, then locates the real call target inside it
// with the first matching byte pattern, and hooks that.
template <typename Fn, typename Patterns>
std::optional<std::string> hook_native_via_patterns(std::string_view type, std::string_view method, Hooks::GameHook<Fn>& slot, Fn* hook_fn, const Patterns& patterns) {
    auto func = sdk::find_native_method(type, method);

    if (func == nullptr) {
        return std::string{"Hook init failed: "} + std::string{type} + "." + std::string{method} + " function not found.";
    }

    spdlog::info("{}.{}: {:x}", type, method, (uintptr_t)func);

    for (auto pattern : patterns) {
        auto ref = utility::find_pattern_in_path((uint8_t*)func, 1000, false, pattern);

        if (!ref) {
            continue;
        }

        auto native_func = utility::calculate_absolute(ref->addr + 4);

        if (!slot.create(native_func, hook_fn)) {
            return std::string{"Hook init failed: "} + std::string{type} + "." + std::string{method} + " native function hook failed.";
        }

        spdlog::info("Hooked {}.{}", type, method);

        return std::nullopt;
    }

    return std::string{"Hook init failed: "} + std::string{type} + "." + std::string{method} + " native function not found. Pattern scan failed.";
}

} // namespace

std::optional<std::string> Hooks::hook_update_transform() {
    auto game = g_framework->get_module().as<HMODULE>();

    // UpdateTransform is found near a call whose surroundings differ per game;
    // if this ever breaks, get the via.SceneManager singleton, find its
    // constructor, and look for the job function added near the end of it:
    //   if ( *(_BYTE *)(v2 + 0x114) )
    //     UpdateTransform(v14, 0, v10);
    //   else
    //     sub_141DD4140(v14, 0i64, v10);
    struct TransformPattern {
        const char* pat;
        uint32_t offset;
    };

    static const TransformPattern pats[] {
        { "E8 ? ? ? ? 48 8B 5B ? 48 85 DB 75 ? 48 8B 4D 40 48 ? ?", 1 }, // RE2 - MHRise v1.0
        { "33 D2 E8 ? ? ? ? B8 01 00 00 00 F0 0F", 3 }, // RE7/RE2/RE3 update to TDB v70/newer games?
        { "0F B6 D1 48 8B CB E8 ? ? ? ? 48 8B 9B ? ? ? ?", 7 }, // RE7
        { "0F B6 D0 48 8B CB E8 ? ? ? ? 48 8B 9B ? ? ? ?", 7 }, // RE7 Demo
        { "31 D2 41 ? F8 E8 ? ? ? ? EB", 6}, // MHWILDS/TDB74+
        { "31 D2 41 ? F8 E8 ? ? ? ? B8 01 00 00 00 F0", 6 }, // MHS3/TDB82+ (lock xadd after call)
    };

    uintptr_t update_transform = 0;

    for (auto& pat : pats) {
        if (auto result = utility::scan(game, pat.pat)) {
            update_transform = utility::calculate_absolute(*result + pat.offset);
            break;
        }
    }

    if (update_transform == 0) {
        spdlog::error("Unable to find UpdateTransform pattern.");
        return std::nullopt; // Not strictly necessary except for freecam
    }

    spdlog::info("UpdateTransform: {:x}", update_transform);

    // Can be found by breakpointing RETransform's worldTransform
    if (!m_update_transform.create(update_transform, &update_transform_hook)) {
        spdlog::error("Failed to hook UpdateTransform");
        return std::nullopt; // who cares
    }

    return std::nullopt;
}

std::optional<std::string> Hooks::hook_update_camera_controller() {
#if defined(RE2) || defined(RE3)
    return hook_native_method(game_namespace("camera.PlayerCameraController"), "updateCameraPosition",
                              m_update_camera_controller, &update_camera_controller_hook);
#else
    return std::nullopt;
#endif
}

std::optional<std::string> Hooks::hook_update_camera_controller2() {
#if defined(RE2) || defined(RE3)
    return hook_native_method(game_namespace("camera.TwirlerCameraControllerRoot"), "update",
                              m_update_camera_controller2, &update_camera_controller2_hook);
#else
    return std::nullopt;
#endif
}

std::optional<std::string> Hooks::hook_gui_draw() {
    spdlog::info("[Hooks] Attempting to hook GUI functions...");

    auto game = g_framework->get_module().as<HMODULE>();

    // This pattern appears to work all the way from RE2 to RE8.
    // If this ever breaks, its parent function is found within via.gui.GUIManager.
    // It is used as a draw callback; the assignment can be found within the
    // constructor near the end.
    // "onEnd(via.gui.TextAnimationEndArg)" can be used as a reference to find the constructor.
    // "copyProperties(via.gui.PlayObject)" also works in RE7 and onwards.
    struct GuiDrawPattern {
        const char* pat;
        size_t offset;
    };

    static const GuiDrawPattern pats[] {
        { "49 8B 0C CE 48 83 79 10 00 74 ? E8 ? ? ? ?", 12 },
        { "49 8B 0C CE 48 83 79 20 00 74 ? E8 ? ? ? ?", 12 }, // RE7
        { "48 8B 0C C3 48 83 79 ? 00 74 ? 48 89 ? E8 ? ? ? ?", 15 }, // MHWILDS
        { "49 8B 0C C6 48 83 79 ? 00 74 ? E8 ? ? ? ?", 12 }, // PRAGMATA
    };

    uintptr_t gui_draw_call = 0;
    size_t offset = 0;

    for (auto& pat : pats) {
        if (auto result = utility::scan(game, pat.pat)) {
            gui_draw_call = *result;
            offset = pat.offset;
            break;
        }
    }

    if (gui_draw_call == 0) {
        spdlog::error("[Hooks] Unable to find gui_draw_call pattern.");
        return std::nullopt; // Don't bother erroring out the entire mod just because of this
    }

    spdlog::info("[Hooks] Found gui_draw_call at {:x}", gui_draw_call);

    auto gui_draw = utility::calculate_absolute(gui_draw_call + offset);
    spdlog::info("[Hooks] gui_draw: {:x}", gui_draw);

    if (!m_gui_draw.create(gui_draw, &gui_draw_hook)) {
        return "Failed to hook GUI::draw";
    }

    return std::nullopt;
}

std::optional<std::string> Hooks::hook_all_application_entries() {
    spdlog::info("[Hooks] Attempting to application entries...");

    auto application = sdk::Application::get();

    if (application == nullptr) {
        return "Failed to get via.Application";
    }

    spdlog::info("[Hooks] Found via.Application at {:x}", (uintptr_t)application);

    // Total hook size: 10 (mov rdx) + 10 (mov r8) + 10 (mov r9) + 10 (mov r10) + 3 (jmp r10) = 43 bytes
    constexpr size_t kHookSize = 43;

    auto generate_hook_func = [&](const char* name, uintptr_t original_func, uintptr_t hook_addr) {
        uint8_t hook[kHookSize]{};

        // movabs rdx, entry_name_addr
        hook[0] = 0x48; hook[1] = 0xBA;
        *(uintptr_t*)&hook[2] = (uintptr_t)name;

        // movabs r8, entry_name_hash
        hook[10] = 0x49; hook[11] = 0xB8;
        *(uintptr_t*)&hook[12] = utility::hash(name);

        // movabs r9, original_func (passed to the hook as its 4th argument)
        hook[20] = 0x49; hook[21] = 0xB9;
        *(uintptr_t*)&hook[22] = original_func;

        // movabs r10, hook_addr
        hook[30] = 0x49; hook[31] = 0xBA;
        *(uintptr_t*)&hook[32] = hook_addr;

        // jmp r10
        hook[40] = 0x41; hook[41] = 0xFF; hook[42] = 0xE2;

        // Allocate permanent memory for the hook and copy into it
        auto allocated_hook = VirtualAlloc(nullptr, kHookSize, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
        if (allocated_hook == nullptr) {
            spdlog::error("Failed to allocate {} bytes for hook '{}'", kHookSize, name);
            return (LPVOID)nullptr;
        }
        memcpy(allocated_hook, hook, kHookSize);

        return allocated_hook;
    };

    for (auto i = 0; i < 1024; ++i) {
        auto entry = application->get_function(i);

        if (entry == nullptr || entry->description == nullptr) {
            continue;
        }

        auto func = entry->func;

        if (func == nullptr) {
            continue;
        }

        spdlog::info("{} {} entry: {:x}", i, entry->description, (uintptr_t)entry);

        auto generated_hook = generate_hook_func((const char*)entry->description, (uintptr_t)func, (uintptr_t)&global_application_entry_hook);

        // We are just going to replace the pointer to the function for now.
        // Doing a full hook with FunctionHook eats up a lot of initialization
        // time because of the constant thread suspension.
        // The original function pointer is embedded directly into the generated
        // hook, so no per-call hashmap lookup is needed inside the hook.
        entry->func = (void (*)(void*))generated_hook;

        spdlog::info("Hooked {} {:x}->{:x}", entry->description, (uintptr_t)func, (uintptr_t)generated_hook);
    }

    return std::nullopt;
}

std::optional<std::string> Hooks::hook_update_before_lock_scene() {
    // This function is removed (or not reflected) >= TDB74...
#if TDB_VER < 74
    auto update_before_lock_scene = sdk::find_native_method("via.render.EntityRenderer", "updateBeforeLockScene");

    if (update_before_lock_scene == nullptr) {
        return "Unable to find via::render::EntityRenderer::updateBeforeLockScene";
    }

    spdlog::info("updateBeforeLockScene: {:x}", (uintptr_t)update_before_lock_scene);

    if (!m_update_before_lock_scene.create(update_before_lock_scene, &update_before_lock_scene_hook)) {
        return "Failed to hook via::render::EntityRenderer::updateBeforeLockScene";
    }
#endif

    return std::nullopt;
}

std::optional<std::string> Hooks::hook_view_get_size() {
    // We're going to hook via.SceneView.get_Size so we can
    // spoof the render target size to the HMD's resolution.
    static const char* patterns[] {
        "49 8B C8 E8",
        "48 8B CB E8",
#if TDB_VER >= 74
        "48 89 F2 E8", // >= TDB74 (MHWILDS)
        "48 8B CF E8", // Pragmata
#endif
    };

    return hook_native_via_patterns("via.SceneView", "get_Size", m_view_get_size, &view_get_size_hook, patterns);
}

std::optional<std::string> Hooks::hook_camera_get_projection_matrix() {
    // We're going to hook via.Camera.get_ProjectionMatrix so we can
    // override the camera's Projection matrix with the HMD's Projection matrix (per-eye)
    static const char* patterns[] {
        "49 8B C8 E8",
        "48 8B CB E8",
#if TDB_VER >= 74
        "48 89 F2 E8", // >= TDB74?
#endif
    };

    return hook_native_via_patterns("via.Camera", "get_ProjectionMatrix", m_camera_get_projection_matrix, &camera_get_projection_matrix_hook, patterns);
}

std::optional<std::string> Hooks::hook_camera_get_view_matrix() {
    static const char* patterns[] {
        "49 8B C8 E8",
        "48 8B CB E8",
#if TDB_VER >= 74
        "48 89 F2 E8", // >= TDB74?
#endif
    };

    return hook_native_via_patterns("via.Camera", "get_ViewMatrix", m_camera_get_view_matrix, &camera_get_view_matrix_hook, patterns);
}

template <typename T>
std::optional<std::string> Hooks::hook_render_layer(RenderLayerHook<T>& hook) {
    auto t = sdk::find_type_definition(hook.name);

    if (t == nullptr) {
        return std::string{"Hooks init failed: "} + hook.name + " type not found.";
    }

    void* fake_obj = t->create_instance();

    if (fake_obj == nullptr) {
        return std::string{"Hooks init failed: "} + "Failed to create fake " + hook.name + " instance.";
    }

    auto obj_vtable = *(uintptr_t**)fake_obj;

    if (obj_vtable == nullptr) {
        return std::string{"Hooks init failed: "} + hook.name + " vtable not found.";
    }

    spdlog::info("{:s} vtable: {:x}", hook.name, (uintptr_t)obj_vtable - g_framework->get_module());

    // Shared handling for the Draw/Update vtable slots: report the native, skip
    // stubs, otherwise install the hook.
    const auto hook_slot = [&](uint32_t index, const char* label, auto&& create) -> std::optional<std::string> {
        auto native = obj_vtable[index];

        if (native == 0) {
            return std::string{"Hooks init failed: "} + hook.name + " " + label + " native not found.";
        }

        spdlog::info("{:s}.{:s}: {:x}", hook.name, label, native);

        if (utility::is_stub_code((uint8_t*)native)) {
            spdlog::info("Skipping {} hook for {:s}, stub code detected", label, hook.name);
            return std::nullopt;
        }

        if (!create(native)) {
            return std::string{"Hooks init failed: "} + hook.name + " " + label + " native function hook failed.";
        }

        return std::nullopt;
    };

    if (auto error = hook_slot(sdk::renderer::RenderLayer::DRAW_VTABLE_INDEX, "draw",
                               [&](uintptr_t native) { return hook.hook_draw(native); })) {
        return error;
    }

    return hook_slot(sdk::renderer::RenderLayer::UPDATE_VTABLE_INDEX, "update",
                     [&](uintptr_t native) { return hook.hook_update(native); });
}

std::optional<std::string> Hooks::hook_render_layers() {
    std::optional<std::string> error;

    auto hook_one = [&](auto& layer_hook) {
        if (!error.has_value()) {
            error = hook_render_layer(layer_hook);
        }
    };

    hook_one(m_layer_hooks.overlay);
    hook_one(m_layer_hooks.post_effect);
    hook_one(m_layer_hooks.scene);
    hook_one(m_layer_hooks.output);
    hook_one(m_layer_hooks.prepare_output);

    return error;
}

#include "Mods.hpp"
#include "REFramework.hpp"
#include <type_traits>
#include <utility/Scan.hpp>
#include <utility/Module.hpp>
#include <utility/String.hpp>
#include <utility/Memory.hpp>

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

    const auto mod_size = utility::get_module_size(game);

    if (!mod_size) {
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



#define LAYER_HOOK_BODY(x, x2, x3) \
void Hooks::RenderLayerHook<sdk::renderer::layer::##x2##>::##x3##(sdk::renderer::layer::##x2##* layer, void* render_ctx) {\
    if (!g_framework->is_ready()) {\
        auto original_func = g_hook->m_layer_hooks.##x##.##x3##_hook->get_original<decltype(RenderLayerHook<sdk::renderer::layer::##x2##>::##x3##)>();\
        original_func(layer, render_ctx); \
        return; \
    } \
    bool any_false = false; \
    const auto& mods = g_framework->get_mods()->get_mods(); \
    for (auto& mod : mods) { \
        const auto result = mod->on_pre_##x##_layer_##x3##(layer, render_ctx); \
        if (!result) { \
            any_false = true; \
        } \
    } \
    if (!any_false) { \
        auto original_func = g_hook->m_layer_hooks.##x##.##x3##_hook->get_original<decltype(RenderLayerHook<sdk::renderer::layer::##x2##>::##x3##)>();\
        original_func(layer, render_ctx); \
    } \
    for (auto& mod : mods) { \
        mod->on_##x##_layer_##x3##(layer, render_ctx); \
    }\
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

namespace {
// Standard mod-dispatch skeleton for hooked functions: while the framework is
// not ready it forwards straight to the original; afterwards every mod's pre
// callback runs, then the original, then every mod's post callback. The
// callbacks receive the Mod& so adapters can forward whichever arguments the
// corresponding Mod virtuals take.
template <typename Ret, typename Original, typename Pre, typename Post>
Ret dispatch_mods(Original&& original, Pre&& pre_cb, Post&& post_cb) {
    if (!g_framework->is_ready()) {
        return original();
    }

    const auto& mods = g_framework->get_mods()->get_mods();

    for (auto& mod : mods) {
        pre_cb(*mod);
    }

    if constexpr (std::is_void_v<Ret>) {
        original();
        for (auto& mod : mods) {
            post_cb(*mod);
        }
    } else {
        auto ret = original();
        for (auto& mod : mods) {
            post_cb(*mod);
        }
        return ret;
    }
}
} // namespace

std::optional<std::string> Hooks::hook_update_transform() {
    auto game = g_framework->get_module().as<HMODULE>();

    // The 48 8B 4D 40 bit might change.
    // Version 1.0 jmp stub: game+0x1dc7de0
    // Version 1
    //auto updateTransformCall = utility::scan(game, "E8 ? ? ? ? 48 8B 5B ? 48 85 DB 75 ? 48 8B 4D 40 48 31 E1");

    // Version 2 Dec 17th, 2019 (works on old version too) game.exe+0x1DD3FF0
    // If this ever changes, get the singleton for via.SceneManager, find its
    // constructor function, and look for the job function added near the end of the constructor
    // UpdateTransform gets called near the end of the job, looks like this:
    /*
      if ( *(_BYTE *)(v2 + 0x114) )
        UpdateTransform(v14, 0, v10);
      else
        sub_141DD4140(v14, 0i64, v10);
    */

    struct TransformPattern {
        std::string pat;
        uint32_t offset;
    };

    /*
        these instructions are near the UpdateTransform call
        mov     eax, 1
        lock xadd [rsi+318h], eax
        cdqe
    */
    std::vector<TransformPattern> pats {
        { "E8 ? ? ? ? 48 8B 5B ? 48 85 DB 75 ? 48 8B 4D 40 48 ? ?", 1 }, // RE2 - MHRise v1.0
        { "33 D2 E8 ? ? ? ? B8 01 00 00 00 F0 0F", 3 }, // RE7/RE2/RE3 update to TDB v70/newer games?
        { "0F B6 D1 48 8B CB E8 ? ? ? ? 48 8B 9B ? ? ? ?", 7 }, // RE7
        { "0F B6 D0 48 8B CB E8 ? ? ? ? 48 8B 9B ? ? ? ?", 7 }, // RE7 Demo
        { "31 D2 41 ? F8 E8 ? ? ? ? EB", 6}, // MHWILDS/TDB74+
        { "31 D2 41 ? F8 E8 ? ? ? ? B8 01 00 00 00 F0", 6 }, // MHS3/TDB82+ (lock xadd after call)
    };

    uintptr_t update_transform = 0;

    for (auto& pat : pats) {
        auto result = utility::scan(game, pat.pat.c_str());

        if (result) {
            update_transform = utility::calculate_absolute(*result + pat.offset);
            break;
        }
    }

    if (update_transform == 0) {
        spdlog::error("Unable to find UpdateTransform pattern.");
        return std::nullopt; // Allow it to continue anyways, it's not strictly necessary except for freecam
    }

    spdlog::info("UpdateTransform: {:x}", update_transform);

    // Can be found by breakpointing RETransform's worldTransform
    m_update_transform_hook = std::make_unique<FunctionHook>(update_transform, &update_transform_hook);

    if (!m_update_transform_hook->create()) {
        //return "Failed to hook UpdateTransform";
        spdlog::error("Failed to hook UpdateTransform");
        return std::nullopt; // who cares
    }

    return std::nullopt;
}

std::optional<std::string> Hooks::hook_update_camera_controller() {

    return std::nullopt;
}

std::optional<std::string> Hooks::hook_update_camera_controller2() {

    return std::nullopt;
}

std::optional<std::string> Hooks::hook_gui_draw() {
    spdlog::info("[Hooks] Attempting to hook GUI functions...");

    auto game = g_framework->get_module().as<HMODULE>();
    auto application = sdk::Application::get();

    // This pattern appears to work all the way from RE2 to RE8.
    // If this ever breaks, its parent function is found within via.gui.GUIManager.
    // It is used as a draw callback. The assignment can be found within the constructor near the end.
    // "onEnd(via.gui.TextAnimationEndArg)" can be used as a reference to find the constructor.
    // "copyProperties(via.gui.PlayObject)" also works in RE7 and onwards
    // In RE2:
    /*  
    *(_QWORD *)(v23 + 8 * v22) = &vtable_thing;
    *(_QWORD *)(v23 + 8 * v22 + 8) = gui_manager;
    *(_OWORD *)(v23 + 8 * v22 + 16) = v34;
    *(_QWORD *)(v23 + 8 * v22 + 32) = gui_manager;
    ++*(_DWORD *)(gui_manager + 232);
    *(_QWORD *)&v35 = draw_task_function; <-- "gui_draw_call" is found within this function.
    */
    size_t offset = 12;
    spdlog::info("[Hooks] Scanning for first GUI draw call...");
    auto gui_draw_call = utility::scan(game, "49 8B 0C CE 48 83 79 10 00 74 ? E8 ? ? ? ?");

    if (!gui_draw_call) {
        spdlog::info("[Hooks] Scanning for fallback GUI draw call...");
        // RE7 (+0x20 grabs the owner ptr, 0x10 in others)
        gui_draw_call = utility::scan(game, "49 8B 0C CE 48 83 79 20 00 74 ? E8 ? ? ? ?");

        if (!gui_draw_call) {
            // MHWILDS
            gui_draw_call = utility::scan(game, "48 8B 0C C3 48 83 79 ? 00 74 ? 48 89 ? E8 ? ? ? ?");
            offset = 15;

            if (!gui_draw_call) {
                // PRAGMATA
                gui_draw_call = utility::scan(game, "49 8B 0C C6 48 83 79 ? 00 74 ? E8 ? ? ? ?");
                offset = 12;

                if (!gui_draw_call) {
                    //return "Unable to find gui_draw_call pattern.";
                    spdlog::error("[Hooks] Unable to find gui_draw_call pattern.");
                    return std::nullopt; // Don't bother erroring out the entire mod just because of this
                }
            }
        }
    }

    spdlog::info("[Hooks] Found gui_draw_call at {:x}", *gui_draw_call);

    auto gui_draw = utility::calculate_absolute(*gui_draw_call + offset);
    spdlog::info("[Hooks] gui_draw: {:x}", gui_draw);

    m_gui_draw_hook = std::make_unique<FunctionHook>(gui_draw, &gui_draw_hook);

    if (!m_gui_draw_hook->create()) {
        return "Failed to hook GUI::draw";
    }

    return std::nullopt;
}

std::optional<std::string> Hooks::hook_application_entry(std::string name, std::unique_ptr<FunctionHook>& hook, void (*hook_fn)(void*)) {
    auto application = sdk::Application::get();

    if (application == nullptr) {
        return "Failed to get via.Application";
    }

    auto entry = application->get_function(name);

    if (entry == nullptr) {
        return "Unable to find via::Application::" + name;
    }

    auto func = entry->func;

    if (func == nullptr) {
        return "via::Application::" + name + " is null";
    }

    spdlog::info("{} entry: {:x}", name, (uintptr_t)entry);
    spdlog::info("{}: {:x}", name, (uintptr_t)func - g_framework->get_module());

    hook = std::make_unique<FunctionHook>(func, hook_fn);

    if (!hook->create()) {
        return "Failed to hook via::Application::" + name;
    }
    
    spdlog::info("Hooked via::Application::{}", name);

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
        
        // We are just going to replace the pointer to the function for now
        // Doing a full hook with FunctionHook eats up a lot of initialization time because of
        // the constant thread suspension. 
        // The original function pointer is embedded directly into the generated hook,
        // so no per-call hashmap lookup is needed inside global_application_entry_hook_internal.
        entry->func = (void (*)(void*))generated_hook;

        spdlog::info("Hooked {} {:x}->{:x}", entry->description, (uintptr_t)func, (uintptr_t)generated_hook);
    }

    return std::nullopt;
}

std::optional<std::string> Hooks::hook_update_before_lock_scene() {
    // This function is removed (or not reflected) >= TDB74...
    // Hook updateBeforeLockScene
    auto update_before_lock_scene = sdk::find_native_method("via.render.EntityRenderer", "updateBeforeLockScene");

    if (update_before_lock_scene == nullptr) {
        return "Unable to find via::render::EntityRenderer::updateBeforeLockScene";
    }

    spdlog::info("updateBeforeLockScene: {:x}", (uintptr_t)update_before_lock_scene);

    m_update_before_lock_scene_hook = std::make_unique<FunctionHook>(update_before_lock_scene, &update_before_lock_scene_hook);

    if (!m_update_before_lock_scene_hook->create()) {
        return "Failed to hook via::render::EntityRenderer::updateBeforeLockScene";
    }

    return std::nullopt;
}

std::optional<std::string> Hooks::hook_lightshaft_draw() {

    return std::nullopt;
}

std::optional<std::string> Hooks::hook_view_get_size() {
    // We're going to hook via.SceneView.get_Size so we can
    // spoof the render target size to the HMD's resolution.
    auto get_size_func = sdk::find_native_method("via.SceneView", "get_Size");

    if (get_size_func == nullptr) {
        return "Hook init failed: via.SceneView.get_Size function not found.";
    }

    spdlog::info("via.SceneView.get_Size: {:x}", (uintptr_t)get_size_func);

    // Pattern scan for the native function call
    //auto ref = utility::scan((uintptr_t)get_size_func, 0x100, "49 8B C8 E8");
    auto ref = utility::find_pattern_in_path((uint8_t*)get_size_func, 1000, false, "49 8B C8 E8");

    if (!ref) {
        ref = utility::find_pattern_in_path((uint8_t*)get_size_func, 1000, false, "48 8B CB E8");
    }

    

    if (!ref) {
        return "Hook init failed: via.SceneView.get_Size native function not found. Pattern scan failed.";
    }

    auto native_func = utility::calculate_absolute(ref->addr + 4);

    // Hook the native function
    m_view_get_size_hook = std::make_unique<FunctionHook>(native_func, view_get_size_hook);

    if (!m_view_get_size_hook->create()) {
        return "Hook init failed: via.SceneView.get_Size native function hook failed.";
    }

    return std::nullopt;
}

std::optional<std::string> Hooks::hook_camera_get_projection_matrix() {
    // We're going to hook via.Camera.get_ProjectionMatrix so we can
    // override the camera's Projection matrix with the HMD's Projection matrix (per-eye)
    auto func = sdk::find_native_method("via.Camera", "get_ProjectionMatrix");

    if (func == nullptr) {
        return "Hook init failed: via.Camera.get_ProjectionMatrix function not found.";
    }

    spdlog::info("via.Camera.get_ProjectionMatrix: {:x}", (uintptr_t)func);
    
    // Pattern scan for the native function call
    auto ref = utility::find_pattern_in_path((uint8_t*)func, 1000, false, "49 8B C8 E8");

    if (!ref) {
        ref = utility::find_pattern_in_path((uint8_t*)func, 1000, false, "48 8B CB E8");
    }
    

    if (!ref) {
        return "Hook init failed: via.Camera.get_ProjectionMatrix native function not found. Pattern scan failed.";
    }

    auto native_func = utility::calculate_absolute(ref->addr + 4);

    // Hook the native function
    m_camera_get_projection_matrix_hook = std::make_unique<FunctionHook>(native_func, camera_get_projection_matrix_hook);

    if (!m_camera_get_projection_matrix_hook->create()) {
        return "Hook init failed: via.Camera.get_ProjectionMatrix native function hook failed.";
    }

    spdlog::info("Hooked via.Camera.get_ProjectionMatrix");

    return std::nullopt;
}

std::optional<std::string> Hooks::hook_camera_get_view_matrix() {
    auto func = sdk::find_native_method("via.Camera", "get_ViewMatrix");

    if (func == nullptr) {
        return "Hook init failed: via.Camera.get_ViewMatrix function not found.";
    }

    spdlog::info("via.Camera.get_ViewMatrix: {:x}", (uintptr_t)func);

    // Pattern scan for the native function call
    auto ref = utility::find_pattern_in_path((uint8_t*)func, 1000, false, "49 8B C8 E8");

    if (!ref) {
        ref = utility::find_pattern_in_path((uint8_t*)func, 1000, false, "48 8B CB E8");
    }


    if (!ref) {
        return "Hook init failed: via.Camera.get_ViewMatrix native function not found. Pattern scan failed.";
    }

    auto native_func = utility::calculate_absolute(ref->addr + 4);

    // Hook the native function
    m_camera_get_view_matrix_hook = std::make_unique<FunctionHook>(native_func, camera_get_view_matrix_hook);

    if (!m_camera_get_view_matrix_hook->create()) {
        return "Hook init failed: via.Camera.get_ViewMatrix native function hook failed.";
    }

    return std::nullopt;
}

std::optional<std::string> Hooks::hook_render_layer(Hooks::RenderLayerHook<sdk::renderer::RenderLayer>& hook) {
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

    auto draw_native = obj_vtable[sdk::renderer::RenderLayer::DRAW_VTABLE_INDEX];

    if (draw_native == 0) {
        return std::string{"Hooks init failed: "} + hook.name + " draw native not found.";
    }

    spdlog::info("{:s}.Draw: {:x}", hook.name, (uintptr_t)draw_native);

    // Set the first byte to the ret instruction
    //m_overlay_draw_patch = Patch::create(draw_native, { 0xC3 });

    if (!utility::is_stub_code((uint8_t*)draw_native)) {
        if (!hook.hook_draw(draw_native)) {
            return std::string{"Hooks init failed: "} + hook.name + " draw native function hook failed.";
        }
    } else {
        spdlog::info("Skipping draw hook for {:s}, stub code detected", hook.name);
    }

    auto update_native = obj_vtable[sdk::renderer::RenderLayer::UPDATE_VTABLE_INDEX];

    if (update_native == 0) {
        return std::string{"Hooks init failed: "} + hook.name + " update native not found.";
    }

    spdlog::info("{:s}.Update: {:x}", hook.name, (uintptr_t)update_native);

    if (!utility::is_stub_code((uint8_t*)update_native)) {
        if (!hook.hook_update(update_native)) {
            return std::string{"Hooks init failed: "} + hook.name + " update native function hook failed.";
        }
    } else {
        spdlog::info("Skipping update hook for {:s}, stub code detected", hook.name);
    }

    return std::nullopt;
}

void* Hooks::update_transform_hook_internal(RETransform* t, uint8_t a2, uint32_t a3) {
    if (!g_framework->is_ready()) {
        return m_update_transform_hook->get_original<decltype(update_transform_hook)>()(t, a2, a3);
    }

    const auto& dispatch_lists = g_framework->get_mods()->dispatch();

    for (auto* mod : dispatch_lists.pre_update_transform) {
        mod->on_pre_update_transform(t);
    }

    auto ret = m_update_transform_hook->get_original<decltype(update_transform_hook)>()(t, a2, a3);

    for (auto* mod : dispatch_lists.update_transform) {
        mod->on_update_transform(t);
    }

    return ret;
}

void* Hooks::update_transform_hook(RETransform* t, uint8_t a2, uint32_t a3) {
    return g_hook->update_transform_hook_internal(t, a2, a3);
}

void* Hooks::update_camera_controller_hook_internal(void* a1, RopewayPlayerCameraController* camera_controller) {
    return dispatch_mods<void*>(
        [this, a1, camera_controller] { return m_update_camera_controller_hook->get_original<decltype(update_camera_controller_hook)>()(a1, camera_controller); },
        [camera_controller](Mod& mod) { mod.on_pre_update_camera_controller(camera_controller); },
        [camera_controller](Mod& mod) { mod.on_update_camera_controller(camera_controller); }
    );
}

void* Hooks::update_camera_controller_hook(void* a1, RopewayPlayerCameraController* camera_controller) {
    return g_hook->update_camera_controller_hook_internal(a1, camera_controller);
}

void* Hooks::update_camera_controller2_hook_internal(void* a1, RopewayPlayerCameraController* camera_controller) {
    return dispatch_mods<void*>(
        [this, a1, camera_controller] { return m_update_camera_controller2_hook->get_original<decltype(update_camera_controller2_hook)>()(a1, camera_controller); },
        [camera_controller](Mod& mod) { mod.on_pre_update_camera_controller2(camera_controller); },
        [camera_controller](Mod& mod) { mod.on_update_camera_controller2(camera_controller); }
    );
}

void* Hooks::update_camera_controller2_hook(void* a1, RopewayPlayerCameraController* camera_controller) {
    return g_hook->update_camera_controller2_hook_internal(a1, camera_controller);
}

void* Hooks::gui_draw_hook_internal(REComponent* gui_element, void* primitive_context) {
    auto original_func = m_gui_draw_hook->get_original<decltype(gui_draw_hook)>();

    if (!g_framework->is_ready()) {
        return original_func(gui_element, primitive_context);
    }

    auto& mods = g_framework->get_mods()->get_mods();

    bool any_false = false;

    for (auto& mod : mods) {
        if (!mod->on_pre_gui_draw_element(gui_element, primitive_context)) {
            any_false = true;
        }
    }

    void* ret = nullptr;

    if (!any_false) {
        ret = original_func(gui_element, primitive_context);
    }

    for (auto& mod : mods) {
        mod->on_gui_draw_element(gui_element, primitive_context);
    }

    return ret;
}

void* Hooks::gui_draw_hook(REComponent* gui_element, void* primitive_context) {
    return g_hook->gui_draw_hook_internal(gui_element, primitive_context);
}

void Hooks::update_before_lock_scene_hook_internal(void* ctx) {
    dispatch_mods<void>(
        [this, ctx] { m_update_before_lock_scene_hook->get_original<decltype(update_before_lock_scene_hook)>()(ctx); },
        [ctx](Mod& mod) { mod.on_pre_update_before_lock_scene(ctx); },
        [ctx](Mod& mod) { mod.on_update_before_lock_scene(ctx); }
    );
}

void Hooks::update_before_lock_scene_hook(void* ctx) {
    g_hook->update_before_lock_scene_hook_internal(ctx);
}

void Hooks::lightshaft_draw_hook_internal(void* shaft, void* render_context) {
    dispatch_mods<void>(
        [this, shaft, render_context] { m_lightshaft_draw_hook->get_original<decltype(lightshaft_draw_hook)>()(shaft, render_context); },
        [shaft, render_context](Mod& mod) { mod.on_pre_lightshaft_draw(shaft, render_context); },
        [shaft, render_context](Mod& mod) { mod.on_lightshaft_draw(shaft, render_context); }
    );
}

void Hooks::lightshaft_draw_hook(void* shaft, void* render_context) {
    g_hook->lightshaft_draw_hook_internal(shaft, render_context);
}

void Hooks::global_application_entry_hook_internal(void* entry, const char* name, size_t hash, void* original) {
    auto original_fn = (void (*)(void*))original;

    if (!g_framework->is_game_data_initialized()) {
        return original_fn(entry);
    }

    const auto should_allow_ignore = sdk::VM::s_tdb_version >= 73 ?
                                     (hash != 0x76b8100bec7c12c3 && hash != 0x9f63c0fc4eea6626) :
                                     true;

    if (should_allow_ignore) {
        std::shared_lock _{m_application_entry_data_mutex};

        if (m_ignored_application_entries.contains(hash)) {
            return;
        }
    }

    if (hash == "BeginRendering"_fnv) {
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

void Hooks::global_application_entry_hook(void* entry, const char* name, size_t hash, void* original) {
    g_hook->global_application_entry_hook_internal(entry, name, hash, original);
}

float* Hooks::view_get_size_hook_internal(REManagedObject* scene_view, float* result) {
    return dispatch_mods<float*>(
        [this, scene_view, result] { return m_view_get_size_hook->get_original<decltype(view_get_size_hook)>()(scene_view, result); },
        [scene_view, result](Mod& mod) { mod.on_pre_view_get_size(scene_view, result); },
        [scene_view, result](Mod& mod) { mod.on_view_get_size(scene_view, result); }
    );
}

float* Hooks::view_get_size_hook(REManagedObject* scene_view, float* result) {
    return g_hook->view_get_size_hook_internal(scene_view, result);
}

Matrix4x4f* Hooks::camera_get_projection_matrix_hook_internal(REManagedObject* camera, Matrix4x4f* result) {
    return dispatch_mods<Matrix4x4f*>(
        [this, camera, result] { return m_camera_get_projection_matrix_hook->get_original<decltype(camera_get_projection_matrix_hook)>()(camera, result); },
        [camera, result](Mod& mod) { mod.on_pre_camera_get_projection_matrix(camera, result); },
        [camera, result](Mod& mod) { mod.on_camera_get_projection_matrix(camera, result); }
    );
}

Matrix4x4f* Hooks::camera_get_projection_matrix_hook(REManagedObject* camera, Matrix4x4f* result) {
    return g_hook->camera_get_projection_matrix_hook_internal(camera, result);
}

Matrix4x4f* Hooks::camera_get_view_matrix_hook_internal(REManagedObject* camera, Matrix4x4f* result) {
    return dispatch_mods<Matrix4x4f*>(
        [this, camera, result] { return m_camera_get_view_matrix_hook->get_original<decltype(camera_get_view_matrix_hook)>()(camera, result); },
        [camera, result](Mod& mod) { mod.on_pre_camera_get_view_matrix(camera, result); },
        [camera, result](Mod& mod) { mod.on_camera_get_view_matrix(camera, result); }
    );
}

Matrix4x4f* Hooks::camera_get_view_matrix_hook(REManagedObject* camera, Matrix4x4f* result) {
    return g_hook->camera_get_view_matrix_hook_internal(camera, result);
}
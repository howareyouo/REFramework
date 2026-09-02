#include <spdlog/spdlog.h>

#include "mods/BackBufferRenderer.hpp"
#include "mods/APIProxy.hpp"
#include "mods/Camera.hpp"
#include "mods/Graphics.hpp"
#include "mods/FreeCam.hpp"
#include "mods/Hooks.hpp"
#include "mods/IntegrityCheckBypass.hpp"
#include "mods/ManualFlashlight.hpp"
#include "mods/PluginLoader.hpp"
#include "mods/REFrameworkConfig.hpp"
#include "mods/MethodDatabase.hpp"
#include "mods/Scene.hpp"
#include "mods/ScriptRunner.hpp"
#include "mods/LooseFileLoader.hpp"
#include "mods/FaultyFileDetector.hpp"
#include "mods/TemporalUpscaler.hpp"

#include "Mods.hpp"

Mods::Mods() {
    m_mods.emplace_back(BackBufferRenderer::get());
    m_mods.emplace_back(REFrameworkConfig::get());

#if defined(REENGINE_AT)
    m_mods.emplace_back(IntegrityCheckBypass::get_shared_instance());
#endif

#ifndef BAREBONES
    m_mods.emplace_back(MethodDatabase::get());
    m_mods.emplace_back(Hooks::get());
    m_mods.emplace_back(LooseFileLoader::get());

#if defined(MHWILDS)
    m_mods.emplace_back(FaultyFileDetector::get());
#endif

    m_mods.emplace_back(TemporalUpscaler::get());

#if defined(RE8) || defined(RE7)
    m_mods.emplace_back(RE8VR::get());
#endif

    // All games!!!
    m_mods.emplace_back(Camera::get());
    m_mods.emplace_back(Graphics::get());

#if defined(RE2) || defined(RE3) || defined(RE8)
    m_mods.emplace_back(std::make_unique<ManualFlashlight>());
#endif

    m_mods.emplace_back(std::make_unique<FreeCam>());

#if TDB_VER > 49
    m_mods.emplace_back(std::make_unique<SceneMods>());
#endif

#endif

    m_mods.emplace_back(APIProxy::get());
    m_mods.emplace_back(PluginLoader::get());
    m_mods.emplace_back(ScriptRunner::get());

    build_dispatch_lists();
}

namespace {

// Probe types override exactly ONE callback so the single differing vtable
// slot can be located. Generated from REF_GAME_CALLBACK_LIST (Mods.hpp), so
// adding a callback requires only one new table entry. The table names the
// dispatch-list member (without the "on_" prefix); the actual Mod virtual is
// on_<name>, hence the prefixing here. The `tag` gives every probe a unique,
// non-trivial body so /OPT:ICF cannot fold it onto the base Mod's empty
// override (which would hide the differing slot); `s_probe_sink` is volatile
// so the store is never optimized away.
static volatile int s_probe_sink = 0;
#define REF_PROBE_DEF(name, ret, args, tag) \
    struct name##Probe : Mod { ret on_##name args override { s_probe_sink = (tag); } };
REF_GAME_CALLBACK_LIST(REF_PROBE_DEF)
#undef REF_PROBE_DEF

// Find the vtable slot of the single callback overridden by `probe`.
// Returns -1 if it could not be located (layout change / safety bound).
int find_callback_slot(Mod& base, Mod& probe) {
    void** base_vt = *(void***)&base;
    void** probe_vt = *(void***)&probe;

    // The vtable is a few dozen entries; 128 is a safe upper bound so we
    // never walk off into unrelated memory.
    for (int i = 0; i < 128; ++i) {
        if (base_vt[i] != probe_vt[i]) {
            return i;
        }
    }

    spdlog::error("[Mods] Failed to locate callback vtable slot (vtable layout changed?)");
    return -1;
}

void collect_mods_for_slot(Mod& base, int slot, const std::vector<std::shared_ptr<Mod>>& all, std::vector<Mod*>& out) {
    out.clear();

    // If we could not locate the slot, fall back to dispatching to every mod.
    // This only loses the optimization; it never drops the callback, so the
    // mods that rely on it (Camera/FreeCam/ManualFlashlight/ScriptRunner) keep
    // working even if the vtable layout assumptions ever break.
    if (slot < 0) {
        spdlog::error("[Mods] Unlocatable callback slot; falling back to full mod dispatch");

        for (auto& m : all) {
            out.push_back(m.get());
        }

        return;
    }

    void** base_vt = *(void***)&base;

    for (auto& m : all) {
        void** vt = *(void***)m.get();

        // A differing vtable slot means this mod overrides the callback.
        if (vt[slot] != base_vt[slot]) {
            out.push_back(m.get());
        }
    }
}

} // namespace

void Mods::build_dispatch_lists() {
    Mod base_mod{};

#define REF_BUILD_DISPATCH(name, ret, args, tag) \
    do { \
        name##Probe probe{}; \
        collect_mods_for_slot(base_mod, find_callback_slot(base_mod, probe), m_mods, m_dispatch.name); \
    } while (0);

    REF_GAME_CALLBACK_LIST(REF_BUILD_DISPATCH)

#undef REF_BUILD_DISPATCH
}

#undef REF_GAME_CALLBACK_LIST

std::optional<std::string> Mods::on_initialize() const {
    for (auto& mod : m_mods) {
        spdlog::info("{:s}::on_initialize()", mod->get_name().data());

        if (auto e = mod->on_initialize(); e != std::nullopt) {
            spdlog::info("{:s}::on_initialize() has failed: {:s}", mod->get_name().data(), *e);
            return e;
        }
    }

    utility::Config cfg{ (REFramework::get_persistent_dir() / REFrameworkConfig::REFRAMEWORK_CONFIG_NAME).string() };

    for (auto& mod : m_mods) {
        spdlog::info("{:s}::on_config_load()", mod->get_name().data());
        mod->on_config_load(cfg);
    }

    return std::nullopt;
}


std::optional<std::string> Mods::on_initialize_d3d_thread() const {
    auto do_not_hook_d3d = g_framework->acquire_do_not_hook_d3d();

    utility::Config cfg{ (REFramework::get_persistent_dir() / REFrameworkConfig::REFRAMEWORK_CONFIG_NAME).string() };

    // once here to at least setup the values
    for (auto& mod : m_mods) {
        spdlog::info("{:s}::on_config_load()", mod->get_name().data());
        mod->on_config_load(cfg);
    }

    for (auto& mod : m_mods) {
        spdlog::info("{:s}::on_initialize_d3d_thread()", mod->get_name().data());

        if (auto e = mod->on_initialize_d3d_thread(); e != std::nullopt) {
            spdlog::info("{:s}::on_initialize_d3d_thread() has failed: {:s}", mod->get_name().data(), *e);
            return e;
        }
    }

    for (auto& mod : m_mods) {
        spdlog::info("{:s}::on_config_load()", mod->get_name().data());
        mod->on_config_load(cfg);
    }

    return std::nullopt;
}

void Mods::on_pre_imgui_frame() const {
    for (auto& mod : m_mods) {
        mod->on_pre_imgui_frame();
    }
}

void Mods::on_frame() const {
    for (auto& mod : m_mods) {
        mod->on_frame();
    }
}

void Mods::on_present() const {
    for (auto& mod : m_mods) {
        mod->on_early_present();
    }

    for (auto& mod : m_mods) {
        mod->on_present();
    }
}

void Mods::on_post_frame() const {
    for (auto& mod : m_mods) {
        mod->on_post_frame();
    }
}

void Mods::on_draw_ui() const {
    for (auto& mod : m_mods) {
        mod->on_draw_ui();
    }
}

void Mods::on_device_reset() const {
    for (auto& mod : m_mods) {
        mod->on_device_reset();
    }
}

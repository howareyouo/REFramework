#pragma once

#include "Mod.hpp"

// Single source of truth for the per-callback dispatch lists below.
// One entry per hot Mod game callback: name, return type, argument list, and a
// unique probe tag. Each probe is a tiny subclass overriding exactly one
// callback; it is only instantiated at startup to locate that callback's
// vtable slot (the single slot where the probe differs from the base Mod), so
// its body never actually runs.
//
// Only the genuinely hot per-frame callbacks live here. update_transform is
// invoked thousands of times per frame (once per transform), so skipping the
// mods that do not override it is a measurable win. Every other game callback
// fires at most a handful of times per frame; the empty virtual dispatch there
// is noise, so those hooks just iterate all mods directly.
//
// Each probe body must be UNIQUE and non-trivial: an empty `{}` body compiles
// to the same code as the base Mod's empty override, and MSVC's /OPT:ICF would
// then fold them onto one address, hiding the differing vtable slot. The tag
// argument gives every probe a distinct body so the slot is always locatable.
#define REF_GAME_CALLBACK_LIST(X) \
    X(pre_update_transform, void, (RETransform*), 1) \
    X(update_transform, void, (RETransform*), 2)

class Mods {
public:
    Mods();
    virtual ~Mods() {}

    std::optional<std::string> on_initialize() const;
    std::optional<std::string> on_initialize_d3d_thread() const;

    void on_pre_imgui_frame() const;
    void on_frame() const;
    void on_present() const;
    void on_post_frame() const;
    void on_draw_ui() const;
    void on_device_reset() const;

    const auto& get_mods() const {
        return m_mods;
    }

    // Per-callback dispatch lists: only mods that actually override each hot
    // callback (determined once at startup by comparing vtable slots against
    // the base Mod implementation). The update_transform hooks iterate these
    // instead of all mods, eliminating empty virtual dispatch on the hottest
    // per-frame callback.
    struct Dispatch {
#define REF_DISPATCH_MEMBER(name, ret, args, tag) std::vector<Mod*> name{};
        REF_GAME_CALLBACK_LIST(REF_DISPATCH_MEMBER)
#undef REF_DISPATCH_MEMBER
    };

    const Dispatch& dispatch() const {
        return m_dispatch;
    }

private:
    void build_dispatch_lists();

    std::vector<std::shared_ptr<Mod>> m_mods;
    Dispatch m_dispatch{};
};
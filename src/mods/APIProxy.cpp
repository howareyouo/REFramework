#include <shared_mutex>
#include <string_view>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>

#include <spdlog/spdlog.h>

#include "utility/FunctionHookMinHook.hpp"
#include "utility/String.hpp"

#include "ScriptRunner.hpp"

#include "PluginLoader.hpp"
#include "APIProxy.hpp"

// For cimgui redirection when on_imgui_frame is called.
namespace cimgui {
std::unique_ptr<FunctionHookMinHook> g_load_library_ex_w_hook{nullptr};

HMODULE load_library_ex_w_hook(LPCWSTR lpLibFileName, HANDLE hFile, DWORD dwFlags) {
    if (lpLibFileName != nullptr) {
        if (std::wstring_view{lpLibFileName}.contains(L"cimgui.dll")) {
            spdlog::info("[LoadLibraryExW] Redirecting cimgui.dll to ourselves");
            return REFramework::get_reframework_module();
        }
    }

    auto og = g_load_library_ex_w_hook->get_original<decltype(LoadLibraryExW)>();
    return og(lpLibFileName, hFile, dwFlags);
}

void setup_hook() {
    static bool attempted = false;
    if (attempted) {
        return;
    }
    attempted = true;

    if (cimgui::g_load_library_ex_w_hook == nullptr) {
        auto llxw = GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryExW");

        if (llxw != nullptr) {
            spdlog::info("[REFramework] Hooking LoadLibraryExW for cimgui.dll redirection");

            cimgui::g_load_library_ex_w_hook = std::make_unique<FunctionHookMinHook>(LoadLibraryExW, cimgui::load_library_ex_w_hook);

            if (!cimgui::g_load_library_ex_w_hook->create()) {
                spdlog::error("[REFramework] Failed to hook LoadLibraryExW for cimgui.dll redirection");
                return;
            }
        }
    }
}
} // namespace cimgui

// Shared helper to get cached ImGui allocator functions and build the callback data.
static REFImGuiFrameCbData get_cached_imgui_cb_data() {
    static ImGuiMemAllocFunc cached_alloc_fn{};
    static ImGuiMemFreeFunc cached_free_fn{};
    static void* cached_user_data{};
    static bool alloc_cached = false;

    if (!alloc_cached) {
        ImGui::GetAllocatorFunctions(&cached_alloc_fn, &cached_free_fn, &cached_user_data);
        alloc_cached = true;
    }

    ::REFImGuiFrameCbData data{};
    data.context = ImGui::GetCurrentContext();
    data.malloc_fn = (void*)cached_alloc_fn;
    data.free_fn = (void*)cached_free_fn;
    data.user_data = cached_user_data;
    return data;
}

namespace {

void log_cb_exception(std::string_view event, const char* name = nullptr) {
    if (name != nullptr) {
        spdlog::error("[APIProxy] Exception occurred in {} callback ({}); one of the plugins has an error.", event, name);
    } else {
        spdlog::error("[APIProxy] Exception occurred in {} callback; one of the plugins has an error.", event);
    }
}

// Register one callback under the shared mutex.
template <typename Fn>
bool add_cb(std::shared_mutex& mtx, std::vector<Fn>& cbs, Fn cb) {
    std::unique_lock _{mtx};
    cbs.push_back(cb);
    return true;
}

// Register an entry-keyed callback (pre/post application entry) under the shared mutex.
template <typename Fn>
bool add_cb(std::shared_mutex& mtx, std::unordered_map<size_t, std::vector<Fn>>& cbs, size_t key, Fn cb) {
    std::unique_lock _{mtx};
    cbs[key].push_back(cb);
    return true;
}

// Run every callback under a shared lock, isolating plugin exceptions.
// Void callbacks are fire-and-forget; bool callbacks aggregate (any false => false).
template <typename Fn, typename... Args>
bool invoke_cbs(std::shared_mutex& mtx, const std::vector<Fn>& cbs, std::string_view event, Args&&... args) {
    std::shared_lock _{mtx};
    bool ok = true;

    for (auto cb : cbs) {
        try {
            if constexpr (std::is_void_v<std::invoke_result_t<Fn&, Args...>>) {
                cb(std::forward<Args>(args)...);
            } else if (!cb(std::forward<Args>(args)...)) {
                ok = false;
            }
        } catch (...) {
            log_cb_exception(event);
        }
    }

    return ok;
}

// Same, but stop at the first callback returning false (on_message semantics).
template <typename Fn, typename... Args>
bool invoke_cbs_until(std::shared_mutex& mtx, const std::vector<Fn>& cbs, std::string_view event, Args&&... args) {
    std::shared_lock _{mtx};

    for (auto cb : cbs) {
        try {
            if (!cb(std::forward<Args>(args)...)) {
                return false;
            }
        } catch (...) {
            log_cb_exception(event);
        }
    }

    return true;
}

// Application-entry callbacks: lookup by fnv hash, fire all in the group.
template <typename Fn>
void invoke_app_entry(std::shared_mutex& mtx, const std::unordered_map<size_t, std::vector<Fn>>& map, std::string_view event, size_t hash, const char* name) {
    std::shared_lock _{mtx};

    if (auto it = map.find(hash); it != map.end()) {
        for (auto cb : it->second) {
            try {
                cb();
            } catch (...) {
                log_cb_exception(event, name);
            }
        }
    }
}

// imgui callbacks: only touch the cimgui hook and allocator cache when listeners exist.
template <typename Fn>
void invoke_imgui(std::shared_mutex& mtx, const std::vector<Fn>& cbs, std::string_view event) {
    std::shared_lock _{mtx};

    if (cbs.empty()) {
        return;
    }

    cimgui::setup_hook();
    auto data = get_cached_imgui_cb_data();

    for (auto cb : cbs) {
        try {
            cb(&data);
        } catch (...) {
            log_cb_exception(event);
        }
    }
}

} // namespace

std::shared_ptr<APIProxy>& APIProxy::get() {
    static auto instance = std::make_shared<APIProxy>();
    return instance;
}

bool APIProxy::add_on_lua_state_created(REFLuaStateCreatedCb cb) {
    add_cb(m_api_cb_mtx, m_on_lua_state_created_cbs, cb);

    // Call the callback outside the lock to prevent potential deadlock
    // if the callback tries to access other APIProxy methods.
    auto& state = ScriptRunner::get()->get_state();

    if (state != nullptr && state->lua().lua_state() != nullptr) {
        cb(state->lua());
    }

    return true;
}

bool APIProxy::add_on_lua_state_destroyed(REFLuaStateDestroyedCb cb) {
    return add_cb(m_api_cb_mtx, m_on_lua_state_destroyed_cbs, cb);
}

bool APIProxy::add_on_present(REFOnPresentCb cb) {
    return add_cb(m_api_cb_mtx, m_on_present_cbs, cb);
}

bool APIProxy::add_on_pre_application_entry(std::string_view name, REFOnPreApplicationEntryCb cb) {
    if (name.empty()) {
        return false;
    }

    return add_cb(m_api_cb_mtx, m_on_pre_application_entry_cbs, utility::hash(name), cb);
}

bool APIProxy::add_on_post_application_entry(std::string_view name, REFOnPostApplicationEntryCb cb) {
    if (name.empty()) {
        return false;
    }

    return add_cb(m_api_cb_mtx, m_on_post_application_entry_cbs, utility::hash(name), cb);
}

bool APIProxy::add_on_device_reset(REFOnDeviceResetCb cb) {
    return add_cb(m_api_cb_mtx, m_on_device_reset_cbs, cb);
}

bool APIProxy::add_on_message(REFOnMessageCb cb) {
    return add_cb(m_api_cb_mtx, m_on_message_cbs, cb);
}

bool APIProxy::add_on_imgui_frame(REFOnImGuiFrameCb cb) {
    return add_cb(m_api_cb_mtx, m_on_imgui_frame_cbs, cb);
}

bool APIProxy::add_on_imgui_draw_ui(REFOnImGuiDrawUICb cb) {
    return add_cb(m_api_cb_mtx, m_on_imgui_draw_ui_cbs, cb);
}

bool APIProxy::add_on_pre_gui_draw_element(REFOnPreGuiDrawElementCb cb) {
    return add_cb(m_api_cb_mtx, m_on_pre_gui_draw_element_cbs, cb);
}

void APIProxy::on_lua_state_created(sol::state& state) {
    invoke_cbs(m_api_cb_mtx, m_on_lua_state_created_cbs, "on_lua_state_created", state.lua_state());
}

void APIProxy::on_lua_state_destroyed(sol::state& state) {
    invoke_cbs(m_api_cb_mtx, m_on_lua_state_destroyed_cbs, "on_lua_state_destroyed", state.lua_state());
}

void APIProxy::on_present() {
    reframework::update_renderer_data();

    invoke_cbs(m_api_cb_mtx, m_on_present_cbs, "on_present");
}

void APIProxy::on_frame() {
    invoke_imgui(m_api_cb_mtx, m_on_imgui_frame_cbs, "on_imgui_frame");
}

void APIProxy::on_draw_ui() {
    invoke_imgui(m_api_cb_mtx, m_on_imgui_draw_ui_cbs, "on_imgui_draw_ui");
}

void APIProxy::on_pre_application_entry(void* entry, const char* name, size_t hash) {
    invoke_app_entry(m_api_cb_mtx, m_on_pre_application_entry_cbs, "on_pre_application_entry", hash, name);
}

void APIProxy::on_application_entry(void* entry, const char* name, size_t hash) {
    invoke_app_entry(m_api_cb_mtx, m_on_post_application_entry_cbs, "on_post_application_entry", hash, name);
}

void APIProxy::on_device_reset() {
    invoke_cbs(m_api_cb_mtx, m_on_device_reset_cbs, "on_device_reset");
}

bool APIProxy::on_message(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    return invoke_cbs_until(m_api_cb_mtx, m_on_message_cbs, "on_message", hwnd, msg, wparam, lparam);
}

bool APIProxy::on_pre_gui_draw_element(REComponent* gui_element, void* primitive_context) {
    return invoke_cbs(m_api_cb_mtx, m_on_pre_gui_draw_element_cbs, "on_pre_gui_draw_element", gui_element, primitive_context);
}
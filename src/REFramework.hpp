#pragma once

#include <array>
#include <atomic>
#include <bit>
#include <thread>
#include <unordered_set>
#include <filesystem>
#include <map>

#include <spdlog/spdlog.h>
#include <imgui.h>
#include <utility/Patch.hpp>

#include <../../directxtk12-src/Inc/GraphicsMemory.h>
#include "utility/d3d12/CommandContext.hpp"

class Mods;
class REGlobals;
class RETypes;

#include "D3D11Hook.hpp"
#include "D3D12Hook.hpp"
#include "DInputHook.hpp"
#include "WindowsMessageHook.hpp"

// Global facilitator
class REFramework {
private:
    void hook_monitor();
    std::atomic<uint32_t> m_do_not_hook_d3d_count{0};

public:
    struct DoNotHook {
        DoNotHook(std::atomic<uint32_t>& count) : m_count(count) {
            ++m_count;
        }
    
        ~DoNotHook() {
            --m_count;
        }

    private:
        std::atomic<uint32_t>& m_count;
    };

    DoNotHook acquire_do_not_hook_d3d() {
        return DoNotHook{m_do_not_hook_d3d_count};
    }


public:
    REFramework(HMODULE reframework_module);
    virtual ~REFramework();

    static auto get_reframework_module() { return s_reframework_module; }
    static void set_reframework_module(HMODULE module) { s_reframework_module = module; }

    bool is_valid() const { return m_valid; }

    bool is_dx11() const { return m_is_d3d11; }

    bool is_dx12() const { return m_is_d3d12; }

    const auto& get_mods() const { return m_mods; }

    const auto& get_mouse_delta() const { return m_mouse_delta; }
    const auto& get_keyboard_state() const { return m_last_keys; }

    Address get_module() const { return m_game_module; }

    bool is_ready() const { return m_initialized && m_game_data_initialized; }
    bool is_game_data_initialized() const { return m_game_data_initialized; }
    bool is_ui_focused() const { return m_is_ui_focused; }

    void run_imgui_frame(bool from_present);

    void on_frame_d3d11();
    void on_post_present_d3d11();
    void on_frame_d3d12();
    void on_post_present_d3d12();

    // Common initialization logic shared between on_frame_d3d11 and on_frame_d3d12.
    // Returns true if initialization is OK and the frame should proceed.
    bool on_frame_common_init();
    void on_reset();

    void patch_set_cursor_pos();
    void remove_set_cursor_pos_patch();

    bool on_message(HWND wnd, UINT message, WPARAM w_param, LPARAM l_param);
    void on_direct_input_keys(const std::array<uint8_t, 256>& keys);

    static inline bool s_fallback_appdata{false};
    static inline bool s_checked_file_permissions{false};
    static std::filesystem::path get_persistent_dir();
    static std::filesystem::path get_persistent_dir(const std::string& dir) {
        return get_persistent_dir() / dir;
    }

    void request_save_config() {
        m_wants_save_config = true;
    }

    enum class RendererType : uint8_t {
        D3D11,
        D3D12
    };
    
    auto get_renderer_type() const { return m_renderer_type; }
    auto& get_d3d11_hook() const { return m_d3d11_hook; }
    auto& get_d3d12_hook() const { return m_d3d12_hook; }

    auto get_window() const { return m_wnd; }
    auto get_last_window_pos() const { return m_last_window_pos; } // REFramework imgui window
    auto get_last_window_size() const { return m_last_window_size; } // REFramework imgui window

    static const char* get_game_name() {
    #if defined(RE2)
        return "re2";
    #elif defined(RE3)
        return "re3";
    #elif defined(RE4)
        return "re4";
    #elif defined(RE7)
        return "re7";
    #elif defined(RE8)
        return "re8";
    #elif defined(RE9)
        return "re9";
    #elif defined(DMC5)
        return "dmc5";
    #elif defined(MHRISE)
        return "mhrise";
    #elif defined(SF6)
        return "sf6";
    #elif defined(DD2)
        return "dd2";
    #elif defined(MHWILDS)
        return "mhwilds";
    #elif defined(MHSTORIES3)
        return "mhstories3";
    #elif defined(PRAGMATA)
        return "pragmata";
    #else
        return "unknown";
    #endif
    }

    bool is_drawing_ui() const {
        return m_draw_ui;
    }

    void set_draw_ui(bool state, bool should_save = true);

    auto& get_hook_monitor_mutex() {
        return m_hook_monitor_mutex;
    }

    auto& get_startup_mutex() {
        return m_startup_mutex;
    }

    // ImGui 1.92 RendererHasTextures 机制下，改字号不需要重新加载字体文件。
    // PushFont(font, size) 会自动调用 GetFontBaked(size) 按需 bake 新字号，
    // 旧字号 baked 由 ImGui GC 自动回收。因此只更新 m_font_size 即可。
    void set_font_size(int size) { 
        m_font_size = size;
    }

    auto get_font_size() const { return m_font_size; }
    auto get_default_font() const { return m_default_font; }

    void set_font(std::string path) { 
        if (m_default_font_file != path) {
            m_default_font_file = path;
            loaded_fonts.clear();
            m_fonts_need_init = true;
        }
    }

    int add_font(const std::filesystem::path& filepath, float size);

    ImFont* get_font(int index) const {
        if (index >= 0 && index < m_additional_fonts.size()) {
            return m_additional_fonts[index].font;
        } else {
            return nullptr;
        }
    }

    auto get_font_size(int index) const {
        if (index >= 0 && index < m_additional_fonts.size()) {
            return m_additional_fonts[index].size;
        } else {
            return m_font_size;
        }
    }

private:
        void save_config();
    void consume_input();
    void init_fonts();
    void invalidate_device_objects();

    void draw_ui();

public:
    bool hook_d3d11();
    bool hook_d3d12();

private: // 启动流水线（构造函数各阶段辅助函数，按调用顺序排列）
    void init_logging();
    void log_system_info();
    void log_os_version();
    void preallocate_hook_buffer();
    void register_dll_notification();
    void backup_game_dlls_to_storage();
    void platform_early_setup();
    void early_init_file_loader();
    bool wait_for_renderer(); // 返回 true 表示首帧已渲染，可立即 hook D3D12

    // hook_d3d11/hook_d3d12 的公共流程：重建 hook 对象 → 注册回调 → hook → 失败回滚
    template <typename HookT, typename RegisterCallbacks>
    bool hook_d3d_impl(std::unique_ptr<HookT>& hook_slot, bool& hooked_flag, bool other_hooked, const char* api_name, RegisterCallbacks&& register_callbacks);

    // on_frame_d3d11/on_frame_d3d12 的公共序言：设 renderer 类型 → prelude(后端前置检查) →
    // 首次初始化 → message hook → device 校验 → on_frame_common_init → 首帧引导。
    // 调用方必须已持有 m_imgui_mtx，并且要保持到函数结束：序言与绘制路径都要与游戏线程的 run_imgui_frame 互斥。
    // 返回 false 时调用方应直接 return；is_init_ok 输出 common_init 结果。
    // prelude/device_provider 语义见实现。
    template <typename Prelude, typename DeviceFn>
    bool frame_prologue(RendererType type, Prelude&& prelude, DeviceFn&& device_provider, bool& is_init_ok);

private:
    bool initialize();
    bool initialize_game_data();
    bool initialize_windows_message_hook();

    bool first_frame_initialize();

    void call_on_frame();

    static inline HMODULE s_reframework_module{};

    bool m_first_frame{true};
    bool m_first_frame_d3d_initialize{true};
    bool m_is_d3d12{false};
    bool m_is_d3d11{false};
    bool m_valid{false};
    bool m_initialized{false};
    bool m_created_default_cfg{false};
    bool m_started_game_data_thread{false};
    std::atomic<bool> m_terminating{false}; // Destructor is called
    std::atomic<bool> m_game_data_initialized{false};
    std::atomic<bool> m_mods_fully_initialized{false};
    
    // UI
    bool m_has_frame{false};
    bool m_wants_device_object_cleanup{false};
    bool m_wants_save_config{false};
    bool m_draw_ui{true};
    bool m_last_draw_ui{m_draw_ui};
    bool m_is_ui_focused{false};
    bool m_cursor_state{false};
    bool m_cursor_state_changed{true};
    bool m_ui_option_transparent{true};
    bool m_ui_passthrough{false};
    
    ImVec2 m_last_window_pos{};
    ImVec2 m_last_window_size{};

    struct AdditionalFont {
        std::filesystem::path filepath{};
        float size{16};
        ImFont* font{};
    };

    std::string m_default_font_file = "DEFAULT";
    bool m_fonts_need_init{true};
    float m_font_size{16};
    ImFont* m_default_font{};
    std::map<std::string, ImFont*> loaded_fonts{};
    std::vector<AdditionalFont> m_additional_fonts{};

    std::mutex m_input_mutex{};
    std::recursive_mutex m_config_mtx{};
    std::recursive_mutex m_imgui_mtx{};
    std::recursive_mutex m_patch_mtx{};

    HWND m_wnd{0};
    HMODULE m_game_module{0};

    float m_accumulated_mouse_delta[2]{};
    float m_mouse_delta[2]{};
    std::array<uint8_t, 256> m_last_keys{0};
    std::unique_ptr<D3D11Hook> m_d3d11_hook{};
    std::unique_ptr<D3D12Hook> m_d3d12_hook{};
    std::unique_ptr<WindowsMessageHook> m_windows_message_hook;
    std::unique_ptr<DInputHook> m_dinput_hook;
    std::shared_ptr<spdlog::logger> m_logger;
    Patch::Ptr m_set_cursor_pos_patch{};

    std::string m_error{""};

    // Game-specific stuff
    std::unique_ptr<Mods> m_mods;

    std::shared_mutex m_hook_monitor_mutex{};
    std::recursive_mutex m_startup_mutex{};
    std::unique_ptr<std::jthread> m_d3d_monitor_thread{};
    std::atomic<std::chrono::steady_clock::time_point> m_last_present_time{};
    std::atomic<std::chrono::steady_clock::time_point> m_last_message_time{};
    std::atomic<std::chrono::steady_clock::time_point> m_last_sendmessage_time{};
    std::atomic<std::chrono::steady_clock::time_point> m_last_chance_time{};
    uint32_t m_frames_since_init{0};
    std::atomic<bool> m_has_last_chance{true};
    bool m_first_initialize{true};

    std::atomic<bool> m_sent_message{false};
    std::atomic<bool> m_message_hook_requested{false};

    RendererType m_renderer_type{RendererType::D3D11};

    template <typename T> using ComPtr = Microsoft::WRL::ComPtr<T>;

private: // D3D misc
    void set_imgui_style() noexcept;

private: // D3D11 Init
    bool init_d3d11();
    void deinit_d3d11();

private: // D3D12 Init
    bool init_d3d12();
    void deinit_d3d12();

private: // D3D11 members
    struct D3D11 {
        ComPtr<ID3D11Texture2D> blank_rt{};
		ComPtr<ID3D11Texture2D> rt{};
        ComPtr<ID3D11RenderTargetView> blank_rt_rtv{};
		ComPtr<ID3D11RenderTargetView> rt_rtv{};
		ComPtr<ID3D11ShaderResourceView> rt_srv{};
        uint32_t rt_width{};
        uint32_t rt_height{};
		ComPtr<ID3D11RenderTargetView> bb_rtv{};
    } m_d3d11{};

public:
    auto& get_blank_rendertarget_d3d11() { return m_d3d11.blank_rt; }
    auto& get_rendertarget_d3d11() { return m_d3d11.rt; }
    auto get_rendertarget_width_d3d11() const { return m_d3d11.rt_width; }
    auto get_rendertarget_height_d3d11() const { return m_d3d11.rt_height; }

private: // D3D12 members
    struct D3D12 {
        std::vector<std::unique_ptr<d3d12::CommandContext>> cmd_ctxs{};
        uint32_t cmd_ctx_index{0};

        enum class RTV : int{
            BACKBUFFER_0,
            BACKBUFFER_1,
            BACKBUFFER_2,
            BACKBUFFER_3,
            BACKBUFFER_4,
            BACKBUFFER_5,
            BACKBUFFER_6,
            BACKBUFFER_7,
            BACKBUFFER_8,
            BACKBUFFER_LAST = BACKBUFFER_8,
            IMGUI,
            BLANK,
            COUNT,
        };

        enum class SRV : int {
            IMGUI_VR,
            BLANK,
            // ImGui 后端纹理（字体等动态纹理）槽位从 DYNAMIC_BEGIN 起，由 srv_alloc 统一分配
            DYNAMIC_BEGIN,
            COUNT = DYNAMIC_BEGIN + 16 // 预留 16 个动态槽位给 ImGui 纹理
        };

        ComPtr<ID3D12DescriptorHeap> rtv_desc_heap{};
        ComPtr<ID3D12DescriptorHeap> srv_desc_heap{};
        ComPtr<ID3D12Resource> rts[(int)RTV::COUNT]{};

        auto& get_rt(RTV rtv) { return rts[(int)rtv]; }

        D3D12_CPU_DESCRIPTOR_HANDLE get_cpu_rtv(ID3D12Device* device, RTV rtv) {
            return {rtv_desc_heap->GetCPUDescriptorHandleForHeapStart().ptr +
                    (SIZE_T)rtv * (SIZE_T)device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV)};
        }

        D3D12_CPU_DESCRIPTOR_HANDLE get_cpu_srv(ID3D12Device* device, SRV srv) {
            return {srv_desc_heap->GetCPUDescriptorHandleForHeapStart().ptr +
                    (SIZE_T)srv * (SIZE_T)device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV)};
        }

        D3D12_GPU_DESCRIPTOR_HANDLE get_gpu_srv(ID3D12Device* device, SRV srv) {
            return {srv_desc_heap->GetGPUDescriptorHandleForHeapStart().ptr +
                    (SIZE_T)srv * (SIZE_T)device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV)};
        }

        // ImGui 两个 DX12 后端（backbuffer / VR）共享同一 SRV 堆，描述符必须统一分配，
        // 否则各自从槽位 0 开始会互相覆盖字体纹理。1.92 动态字体 bake 会反复创建/销毁
        // 纹理，因此用位图空闲表支持真正的 free，槽位随堆重建时 reset。
        struct SrvAllocator {
            static constexpr int DYNAMIC_COUNT = (int)SRV::COUNT - (int)SRV::DYNAMIC_BEGIN;

            // 返回堆内槽位索引，耗尽返回 -1
            int alloc() {
                if (free_mask == 0) {
                    return -1;
                }
                const auto bit = std::countr_zero(free_mask);
                free_mask &= ~(1u << bit);
                return (int)SRV::DYNAMIC_BEGIN + bit;
            }

            void free(int index) {
                const auto bit = index - (int)SRV::DYNAMIC_BEGIN;
                if (bit >= 0 && bit < DYNAMIC_COUNT) {
                    free_mask |= (1u << bit);
                }
            }

            void reset() { free_mask = (1u << DYNAMIC_COUNT) - 1; }

            uint32_t free_mask{0};
        } srv_alloc{};

        uint32_t rt_width{};
        uint32_t rt_height{};

        std::array<void*, 2> imgui_backend_datas{};
        std::unique_ptr<DirectX::DX12::GraphicsMemory> graphics_memory{}; // for use in several places around REF
    } m_d3d12{};

public:
    auto& get_blank_rendertarget_d3d12() { return m_d3d12.get_rt(D3D12::RTV::BLANK); }
    auto& get_rendertarget_d3d12() { return m_d3d12.get_rt(D3D12::RTV::IMGUI); }
    auto get_rendertarget_width_d3d12() { return m_d3d12.rt_width; }
    auto get_rendertarget_height_d3d12() { return m_d3d12.rt_height; }

private:
};

extern std::unique_ptr<REFramework> g_framework;

// 统一安全的钩子监视器互斥锁访问。
// 在 g_framework 尚未初始化完成（构造函数尚未返回）时，后面的调用者自旋等待，
// 避免其他线程（如 D3D11/D3D12 钩子）因空指针解引用导致崩溃。
inline std::shared_mutex& get_hook_monitor_mutex_safe() {
    while (g_framework == nullptr) {
        std::this_thread::yield(); // 自旋等待启动线程完成
    }
    return g_framework->get_hook_monitor_mutex();
}

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(
    HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam); // Use ImGui::GetCurrentContext()

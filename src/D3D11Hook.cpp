#include <algorithm>
#include <mutex>
#include <spdlog/spdlog.h>
#include <utility/Thread.hpp>
#include <utility/Module.hpp>

#include "REFramework.hpp"
#include "WindowFilter.hpp"
#include "D3D11Hook.hpp"

using namespace std;

static D3D11Hook* g_d3d11_hook = nullptr;

namespace {
    // RAII: 临时还原被 hook 的函数字节，析构时自动恢复 hooked 状态
    class ScopedFunctionUnhook {
    public:
        ScopedFunctionUnhook(void* func, const std::vector<uint8_t>& original_bytes)
            : m_func(func), m_size(original_bytes.size()) {
            m_hooked_bytes.resize(m_size);
            memcpy(m_hooked_bytes.data(), func, m_size);
            ProtectionOverride prot{func, m_size, PAGE_EXECUTE_READWRITE};
            memcpy(func, original_bytes.data(), m_size);
        }

        ~ScopedFunctionUnhook() {
            ProtectionOverride prot{m_func, m_size, PAGE_EXECUTE_READWRITE};
            memcpy(m_func, m_hooked_bytes.data(), m_size);
        }

        ScopedFunctionUnhook(const ScopedFunctionUnhook&) = delete;
        ScopedFunctionUnhook& operator=(const ScopedFunctionUnhook&) = delete;

    private:
        void* m_func;
        std::vector<uint8_t> m_hooked_bytes;
        size_t m_size;
    };

    // 提取：present / resize_buffers 共用的窗口过滤检查
    inline bool is_swapchain_filtered(IDXGISwapChain* swap_chain) {
        DXGI_SWAP_CHAIN_DESC desc{};
        swap_chain->GetDesc(&desc);
        return WindowFilter::is_hwnd_filtered_fast(desc.OutputWindow);
    }

    // RAII: 管理重入标志和上一次结果，比手动 set/reset 更健壮
    struct ReentrancyScope {
        bool& flag;
        HRESULT& stored;
        ReentrancyScope(bool& f, HRESULT& r) : flag(f), stored(r) { flag = true; }
        void store(HRESULT hr) { stored = hr; }
        ~ReentrancyScope() { flag = false; }
    };
} // namespace

D3D11Hook::~D3D11Hook() {
    unhook();
}

bool D3D11Hook::hook() {
    spdlog::info("Hooking D3D11");

    g_d3d11_hook = this;

    HWND h_wnd = GetDesktopWindow();
    IDXGISwapChain* swap_chain = nullptr;
    ID3D11Device* device = nullptr;
    ID3D11DeviceContext* context = nullptr;

    D3D_FEATURE_LEVEL feature_level = D3D_FEATURE_LEVEL_11_0;
    DXGI_SWAP_CHAIN_DESC swap_chain_desc{}; // C++ value-init，替代 ZeroMemory
    swap_chain_desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    swap_chain_desc.BufferCount = 1;
    swap_chain_desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swap_chain_desc.OutputWindow = h_wnd;
    swap_chain_desc.SampleDesc.Count = 1;
    swap_chain_desc.Windowed = TRUE;
    swap_chain_desc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
    swap_chain_desc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
    swap_chain_desc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

    const auto original_bytes = utility::get_original_bytes(&D3D11CreateDeviceAndSwapChain);

    // 提取重复的设备创建调用
    auto create_device = [&]() -> HRESULT {
        return D3D11CreateDeviceAndSwapChain(
            nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, D3D11_CREATE_DEVICE_BGRA_SUPPORT,
            &feature_level, 1, D3D11_SDK_VERSION, &swap_chain_desc,
            &swap_chain, &device, nullptr, &context);
    };

    if (original_bytes) {
        spdlog::info("D3D11CreateDeviceAndSwapChain appears to be hooked, temporarily unhooking");
        ScopedFunctionUnhook unhooker(&D3D11CreateDeviceAndSwapChain, *original_bytes);

        if (FAILED(create_device())) {
            spdlog::error("Failed to create D3D11 device");
            return false;
        }
        spdlog::info("Restoring hooked bytes for D3D11CreateDeviceAndSwapChain");
    } else {
        if (FAILED(create_device())) {
            spdlog::error("Failed to create D3D11 device");
            return false;
        }
    }

    utility::ThreadSuspender suspender{};

    try {
        m_present_hook.reset();
        m_resize_buffers_hook.reset();

        auto& present_fn = (*(void***)swap_chain)[8];
        auto& resize_buffers_fn = (*(void***)swap_chain)[13];

        m_present_hook = std::make_unique<PointerHook>(&present_fn, (void*)&D3D11Hook::present);
        m_resize_buffers_hook = std::make_unique<PointerHook>(&resize_buffers_fn, (void*)&D3D11Hook::resize_buffers);

        m_hooked = true;
    } catch (const std::exception& e) {
        spdlog::error("Failed to hook D3D11: {}", e.what());
        m_hooked = false;
    }

    suspender.resume();

    if (device) device->Release();
    if (context) context->Release();
    if (swap_chain) swap_chain->Release();
    return m_hooked;
}

bool D3D11Hook::unhook() {
    if (!m_hooked) {
        return true;
    }

    spdlog::info("Unhooking D3D11");

    if (m_present_hook->remove() && m_resize_buffers_hook->remove()) {
        m_hooked = false;
        return true;
    }

    return false;
}

thread_local bool g_inside_d3d11_present = false;
thread_local HRESULT last_d3d11_present_result = S_OK;

HRESULT WINAPI D3D11Hook::present(IDXGISwapChain* swap_chain, UINT sync_interval, UINT flags) {
    std::scoped_lock _{get_hook_monitor_mutex_safe()};

    auto d3d11 = g_d3d11_hook;
    auto present_fn = d3d11->m_present_hook->get_original<decltype(D3D11Hook::present)*>();

    if (is_swapchain_filtered(swap_chain)) {
        return present_fn(swap_chain, sync_interval, flags);
    }

    d3d11->m_inside_present = true;

    if (d3d11->m_swapchain_0 == nullptr) {
        d3d11->m_swapchain_0 = swap_chain;
        d3d11->m_swap_chain = swap_chain;
    } else if (d3d11->m_swapchain_1 == nullptr && swap_chain != d3d11->m_swapchain_0) {
        d3d11->m_swapchain_1 = swap_chain;
    }

    if (d3d11->m_device == nullptr) {
        swap_chain->GetDevice(IID_PPV_ARGS(&d3d11->m_device));
    }

    // 保留原始顺序：先检查重入，再执行 on_present
    if (g_inside_d3d11_present) {
        return last_d3d11_present_result;
    }

    if (d3d11->m_on_present) {
        d3d11->m_on_present(*d3d11);
    }

    HRESULT result = S_OK;
    {
        ReentrancyScope guard(g_inside_d3d11_present, last_d3d11_present_result);
        if (!d3d11->m_ignore_next_present) {
            result = present_fn(swap_chain, sync_interval, flags);
            guard.store(result);
        } else {
            d3d11->m_ignore_next_present = false;
            guard.store(S_OK);
        }
    }

    if (d3d11->m_on_post_present) {
        d3d11->m_on_post_present(*d3d11);
    }

    d3d11->m_last_depthstencil_used.Reset();
    d3d11->m_inside_present = false;

    return result;
}

thread_local bool g_inside_d3d11_resize_buffers = false;
thread_local HRESULT last_d3d11_resize_buffers_result = S_OK;

HRESULT WINAPI D3D11Hook::resize_buffers(
    IDXGISwapChain* swap_chain, UINT buffer_count, UINT width, UINT height, DXGI_FORMAT new_format, UINT swap_chain_flags) {
    std::scoped_lock _{get_hook_monitor_mutex_safe()};

    auto d3d11 = g_d3d11_hook;
    auto resize_buffers_fn = d3d11->m_resize_buffers_hook->get_original<decltype(D3D11Hook::resize_buffers)*>();

    if (is_swapchain_filtered(swap_chain)) {
        return resize_buffers_fn(swap_chain, buffer_count, width, height, new_format, swap_chain_flags);
    }

    d3d11->m_swap_chain = swap_chain;
    d3d11->m_swapchain_0 = nullptr;
    d3d11->m_swapchain_1 = nullptr;
    d3d11->m_last_depthstencil_used.Reset();

    // 保留原始顺序：先执行 on_resize_buffers，再检查重入
    if (d3d11->m_on_resize_buffers) {
        d3d11->m_on_resize_buffers(*d3d11);
    }

    if (g_inside_d3d11_resize_buffers) {
        return last_d3d11_resize_buffers_result;
    }

    ReentrancyScope guard(g_inside_d3d11_resize_buffers, last_d3d11_resize_buffers_result);
    HRESULT result = resize_buffers_fn(swap_chain, buffer_count, width, height, new_format, swap_chain_flags);
    guard.store(result);
    return result;
}

void WINAPI D3D11Hook::set_render_targets(
    ID3D11DeviceContext* context, UINT num_views, ID3D11RenderTargetView* const* rtvs, ID3D11DepthStencilView* dsv) {
    std::scoped_lock _{get_hook_monitor_mutex_safe()};

    auto d3d11 = g_d3d11_hook;

    if (dsv != nullptr) {
        D3D11_DEPTH_STENCIL_VIEW_DESC desc{};
        dsv->GetDesc(&desc);

        if (desc.Flags & D3D11_DSV_FLAG::D3D11_DSV_READ_ONLY_DEPTH) {
            dsv->GetResource((ID3D11Resource**)d3d11->m_last_depthstencil_used.GetAddressOf());
        }
    }

    auto set_render_targets_fn = d3d11->m_set_render_targets_hook->get_original<decltype(set_render_targets)*>();
    return set_render_targets_fn(context, num_views, rtvs, dsv);
}

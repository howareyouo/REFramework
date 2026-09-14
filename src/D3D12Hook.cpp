#include <algorithm>
#include <type_traits>
#include <thread>
#include <future>
#include <unordered_set>
#include <wrl/client.h>

#include <shared_mutex>
#include <mutex>

#include <spdlog/spdlog.h>
#include <utility/Thread.hpp>
#include <utility/Module.hpp>
#include <utility/String.hpp>
#include <utility/RTTI.hpp>
#include <utility/Scan.hpp>
#include <utility/ScopeGuard.hpp>

#include "REFramework.hpp"

#include "WindowFilter.hpp"

#include "D3D12Hook.hpp"

static D3D12Hook* g_d3d12_hook = nullptr;
thread_local bool g_inside_d3d12_hook = false;

static std::once_flag s_streamline_once{};

// Replacement for deprecated IsBadReadPtr - uses VirtualQuery instead
static bool is_protection_readable(DWORD protect) {
    // PAGE_GUARD is a modifier rather than a protection, reading it raises an exception.
    if (protect & (PAGE_NOACCESS | PAGE_GUARD)) {
        return false;
    }

    constexpr DWORD readable_protections = PAGE_READONLY | PAGE_READWRITE | PAGE_WRITECOPY
                                         | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY;

    return (protect & readable_protections) != 0;
}

// Invokes fn(address) for every readable pointer-sized slot in [base, base + max_size),
// stopping early once fn returns true.
//
// Walks VirtualQuery regions and skips ahead by RegionSize instead of re-querying
// every 8 bytes, so scanning a 4KB object costs a couple of syscalls rather than 512.
template <typename Fn>
static bool scan_readable_slots(const void* base, size_t max_size, Fn&& fn) {
    static_assert(std::is_invocable_r_v<bool, Fn&, uintptr_t>, "fn must take a uintptr_t and return bool");

    auto cursor = (uintptr_t)base;
    const auto limit = cursor + max_size;

    while (cursor < limit) {
        MEMORY_BASIC_INFORMATION mbi{};

        if (VirtualQuery((const void*)cursor, &mbi, sizeof(mbi)) == 0) {
            return false;
        }

        // The first region we cannot read through is where the object ends.
        if (mbi.State != MEM_COMMIT || !is_protection_readable(mbi.Protect)) {
            return false;
        }

        // Parenthesized because windows.h defines min as a macro.
        const auto region_end = (std::min)(limit, (uintptr_t)mbi.BaseAddress + mbi.RegionSize);

        for (auto slot = cursor; slot + sizeof(void*) <= region_end; slot += sizeof(void*)) {
            if (fn(slot)) {
                return true;
            }
        }

        cursor = region_end;
    }

    return false;
}

D3D12Hook::~D3D12Hook() {
    unhook();
}

void* D3D12Hook::Streamline::link_swapchain_to_cmd_queue(void* rcx, void* rdx, void* r8, void* r9) {
    auto& hook = D3D12Hook::s_streamline.link_swapchain_to_cmd_queue_hook;

    if (g_inside_d3d12_hook) {
        spdlog::info("[Streamline] linkSwapchainToCmdQueue: {:x} (inside D3D12 hook)", (uintptr_t)_ReturnAddress());
        return hook->get_original<decltype(link_swapchain_to_cmd_queue)>()(rcx, rdx, r8, r9);
    }

    std::shared_lock<std::shared_mutex> _{get_hook_monitor_mutex_safe()};

    spdlog::info("[Streamline] linkSwapchainToCmdQueue: {:x}", (uintptr_t)_ReturnAddress());

    bool hook_was_nullptr = g_d3d12_hook == nullptr;

    if (g_d3d12_hook != nullptr) {
        g_framework->on_reset(); // Needed to prevent a crash due to resources hanging around
        g_d3d12_hook->unhook(); // Removes all vtable hooks
    }

    const auto result = hook->get_original<decltype(link_swapchain_to_cmd_queue)>()(rcx, rdx, r8, r9);

    // Re-hooks present after the above function creates the swapchain
    // This allows the hook to immediately still function
    // rather than waiting on the hook monitor to notice the hook isn't working
    if (!hook_was_nullptr) {
        g_framework->hook_d3d12();
    }

    return result;
}

HRESULT WINAPI D3D12Hook::create_swapchain(IDXGIFactory4* factory, IUnknown* device, HWND hwnd, const DXGI_SWAP_CHAIN_DESC1* desc, const DXGI_SWAP_CHAIN_FULLSCREEN_DESC* p_fullscreen_desc, IDXGIOutput* p_restrict_to_output, IDXGISwapChain1** swap_chain) {
    auto create_swap_chain_fn = s_create_swapchain_hook->get_original<decltype(D3D12Hook::create_swapchain)*>();

    if (g_inside_d3d12_hook) {
        spdlog::info("create_swapchain (inside D3D12 hook)");
        return create_swap_chain_fn(factory, device, hwnd, desc, p_fullscreen_desc, p_restrict_to_output, swap_chain);
    }

    spdlog::info("create_swapchain called");

    std::shared_lock<std::shared_mutex> _{get_hook_monitor_mutex_safe()};

    bool hook_was_nullptr = g_d3d12_hook == nullptr;

    if (g_d3d12_hook != nullptr && g_framework->get_d3d12_hook() != nullptr) {
        g_framework->on_reset(); // Needed to prevent a crash due to resources hanging around
        g_d3d12_hook->unhook(); // Removes all vtable hooks
    }

    const auto result = create_swap_chain_fn(factory, device, hwnd, desc, p_fullscreen_desc, p_restrict_to_output, swap_chain);

    // rather than waiting on the hook monitor to notice the hook isn't working
    if (!hook_was_nullptr) {
        g_framework->hook_d3d12();
    }

    return result;
}

void D3D12Hook::hook_streamline(HMODULE dlssg_module) try {
    std::call_once(s_streamline_once, [&]() {
        spdlog::info("[Streamline] Hooking Streamline");

        if (dlssg_module == nullptr) {
            dlssg_module = GetModuleHandleW(L"sl.dlss_g.dll");
        }

        if (dlssg_module == nullptr) {
            spdlog::error("[Streamline] Failed to get sl.dlss_g.dll module handle");
            return;
        }

        const auto str = utility::scan_string(dlssg_module, "linkSwapchainToCmdQueue");

        if (!str) {
            spdlog::error("[Streamline] Failed to find linkSwapchainToCmdQueue");
            return;
        }

        const auto str_ref = utility::scan_displacement_reference(dlssg_module, *str);

        if (!str_ref) {
            spdlog::error("[Streamline] Failed to find linkSwapchainToCmdQueue reference");
            return;
        }

        const auto fn = utility::find_function_start_with_call(*str_ref);

        if (!fn) {
            spdlog::error("[Streamline] Failed to find linkSwapchainToCmdQueue function");
            return;
        }

        D3D12Hook::s_streamline.link_swapchain_to_cmd_queue_hook = std::make_unique<FunctionHook>(*fn, (uintptr_t)&Streamline::link_swapchain_to_cmd_queue);

        if (D3D12Hook::s_streamline.link_swapchain_to_cmd_queue_hook->create()) {
            spdlog::info("[Streamline] Hooked linkSwapchainToCmdQueue");
        } else {
            spdlog::error("[Streamline] Failed to hook linkSwapchainToCmdQueue");
        }
    });
} catch(...) {
    spdlog::error("[Streamline] Failed to hook Streamline");
}

namespace {

// A hidden window, only ever used as a fallback target for CreateSwapChainForHwnd.
class DummyWindow {
public:
    DummyWindow() = default;
    ~DummyWindow() {
        if (m_hwnd != nullptr) {
            ::DestroyWindow(m_hwnd);
        }

        if (m_class_name != nullptr) {
            ::UnregisterClass(m_class_name, m_hinstance);
        }
    }

    DummyWindow(const DummyWindow&) = delete;
    DummyWindow& operator=(const DummyWindow&) = delete;

    // Returns nullptr if the window could not be created; callers go ahead and try the
    // swapchain anyway, which is what we've always done.
    HWND create() {
        if (m_hwnd != nullptr) {
            return m_hwnd;
        }

        WNDCLASSEX wc{};
        wc.cbSize = sizeof(WNDCLASSEX);
        wc.style = CS_HREDRAW | CS_VREDRAW;
        wc.lpfnWndProc = DefWindowProc;
        wc.hInstance = GetModuleHandle(NULL);
        wc.lpszClassName = TEXT("REFRAMEWORK_DX12_DUMMY");

        if (::RegisterClassEx(&wc) != 0) {
            m_class_name = wc.lpszClassName;
        }

        m_hinstance = wc.hInstance;
        m_hwnd = ::CreateWindow(wc.lpszClassName, TEXT("REF DX Dummy Window"), WS_OVERLAPPEDWINDOW,
                                0, 0, 100, 100, NULL, NULL, wc.hInstance, NULL);

        return m_hwnd;
    }

private:
    HWND m_hwnd{};
    HMODULE m_hinstance{};
    LPCTSTR m_class_name{};
};

// Creates a throwaway device. Another overlay (ReShade and friends) may have hooked
// D3D12CreateDevice; if so the original bytes get put back temporarily so the overlay
// never sees this dummy device.
Microsoft::WRL::ComPtr<ID3D12Device> create_dummy_device(D3D_FEATURE_LEVEL feature_level) {
    // Resolved manually rather than linked, the user may be running Windows 7.
    const auto d3d12_module = LoadLibraryA("d3d12.dll");

    if (d3d12_module == nullptr) {
        spdlog::error("Failed to load d3d12.dll");
        return nullptr;
    }

    const auto d3d12_create_device = (decltype(D3D12CreateDevice)*)GetProcAddress(d3d12_module, "D3D12CreateDevice");

    if (d3d12_create_device == nullptr) {
        spdlog::error("Failed to get D3D12CreateDevice export");
        return nullptr;
    }

    Microsoft::WRL::ComPtr<ID3D12Device> device;

    const auto original_bytes = utility::get_original_bytes(d3d12_create_device);

    if (!original_bytes) {
        if (FAILED(d3d12_create_device(nullptr, feature_level, IID_PPV_ARGS(device.GetAddressOf())))) {
            spdlog::error("Failed to create D3D12 Dummy device");
            return nullptr;
        }

        return device;
    }

    spdlog::info("D3D12CreateDevice appears to be hooked, temporarily unhooking");

    std::vector<uint8_t> hooked_bytes(original_bytes->size());
    memcpy(hooked_bytes.data(), d3d12_create_device, original_bytes->size());

    HRESULT result{E_FAIL};

    // The override has to stay alive across both memcpys, the second one needs write access.
    {
        ProtectionOverride protection_override{d3d12_create_device, original_bytes->size(), PAGE_EXECUTE_READWRITE};
        memcpy(d3d12_create_device, original_bytes->data(), original_bytes->size());

        result = d3d12_create_device(nullptr, feature_level, IID_PPV_ARGS(device.GetAddressOf()));

        spdlog::info("Restoring hooked bytes for D3D12CreateDevice");
        memcpy(d3d12_create_device, hooked_bytes.data(), hooked_bytes.size());
    }

    if (FAILED(result)) {
        spdlog::error("Failed to create D3D12 Dummy device");
        return nullptr;
    }

    return device;
}

Microsoft::WRL::ComPtr<IDXGIFactory4> create_dummy_dxgi_factory() {
    // Resolved manually rather than linked, the user may be running Windows 7.
    const auto dxgi_module = LoadLibraryA("dxgi.dll");

    if (dxgi_module == nullptr) {
        spdlog::error("Failed to load dxgi.dll");
        return nullptr;
    }

    const auto create_dxgi_factory = (decltype(CreateDXGIFactory)*)GetProcAddress(dxgi_module, "CreateDXGIFactory");

    if (create_dxgi_factory == nullptr) {
        spdlog::error("Failed to get CreateDXGIFactory export");
        return nullptr;
    }

    Microsoft::WRL::ComPtr<IDXGIFactory4> factory;

    if (FAILED(create_dxgi_factory(IID_PPV_ARGS(factory.GetAddressOf())))) {
        spdlog::error("Failed to create D3D12 Dummy DXGI Factory");
        return nullptr;
    }

    return factory;
}

// dummy_window is owned by the caller because it has to outlive the swapchain.
Microsoft::WRL::ComPtr<IDXGISwapChain1> create_dummy_swapchain(IDXGIFactory4* factory, ID3D12CommandQueue* command_queue, DummyWindow& dummy_window) {
    Microsoft::WRL::ComPtr<IDXGISwapChain1> swap_chain;

    DXGI_SWAP_CHAIN_DESC1 desc{};
    desc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
    desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    desc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;
    desc.BufferCount = 2;
    desc.SampleDesc.Count = 1;
    desc.AlphaMode = DXGI_ALPHA_MODE_PREMULTIPLIED;
    desc.Width = 1;
    desc.Height = 1;

    struct Attempt {
        const char* name;
        std::function<HRESULT()> create;
    };

    std::vector<Attempt> attempts{
        // CreateSwapChainForComposition goes first because some overlays hook
        // CreateSwapChainForHwnd, and this is only ever a dummy swapchain - we don't
        // want to screw up the overlay.
        {"CreateSwapChainForComposition", [&]() {
            return factory->CreateSwapChainForComposition(command_queue, &desc, nullptr, swap_chain.GetAddressOf());
        }},
        {"CreateSwapChainForHwnd (dummy window)", [&]() {
            const auto hwnd = dummy_window.create();

            desc.BufferCount = 3;
            desc.Width = 0;
            desc.Height = 0;
            desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
            desc.Flags = DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT;
            desc.SampleDesc.Quality = 0;
            desc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
            desc.AlphaMode = DXGI_ALPHA_MODE_UNSPECIFIED;
            desc.Scaling = DXGI_SCALING_STRETCH;

            return factory->CreateSwapChainForHwnd(command_queue, hwnd, &desc, nullptr, nullptr, swap_chain.GetAddressOf());
        }},
        {"CreateSwapChainForHwnd (desktop window)", [&]() {
            return factory->CreateSwapChainForHwnd(command_queue, GetDesktopWindow(), &desc, nullptr, nullptr, swap_chain.GetAddressOf());
        }},
    };

    for (auto i = 0; i < attempts.size(); i++) {
        spdlog::info("Trying swapchain attempt {}: {}", i, attempts[i].name);

        try {
            if (!FAILED(attempts[i].create())) {
                spdlog::info("Created dummy swapchain on attempt {}", i);
                return swap_chain;
            }
        } catch (const std::exception& e) {
            spdlog::error("Failed to create dummy swapchain on attempt {}: {}", i, e.what());
        } catch (...) {
            spdlog::error("Failed to create dummy swapchain on attempt {}: unknown exception", i);
        }

        spdlog::error("Attempt {} failed", i);
    }

    return nullptr;
}

// True for a frame generation interposer (Streamline/DLSS3 or FSR3) rather than the
// swapchain the game actually presents with.
bool is_frame_generation_swapchain(IDXGISwapChain1* swap_chain) {
    try {
        const auto ti = utility::rtti::get_type_info(swap_chain);
        const auto classname = ti != nullptr && ti->name() != nullptr ? std::string_view{ti->name()} : "unknown";
        const auto raw_name = ti != nullptr && ti->raw_name() != nullptr ? std::string_view{ti->raw_name()} : "unknown";

        spdlog::info("Swapchain type info: {}", classname);
        spdlog::info("Swapchain raw type info: {}", raw_name);

        if (classname.contains("interposer::DXGISwapChain")) { // DLSS3
            spdlog::info("Found Streamline (DLSSFG) swapchain during dummy initialization: {:x}", (uintptr_t)swap_chain);
            return true;
        }

        if (classname.contains("FrameInterpolationSwapChain")) { // FSR3
            spdlog::info("Found FSR3 swapchain during dummy initialization: {:x}", (uintptr_t)swap_chain);
            return true;
        }
    } catch (const std::exception& e) {
        spdlog::error("Failed to get type info: {}", e.what());
    } catch (...) {
        spdlog::error("Failed to get type info: unknown exception");
    }

    return false;
}

struct CommandQueueScan {
    uint32_t command_queue_offset{0};
    uint32_t proton_swapchain_offset{0};

    // Non-zero when the command queue was found one pointer away from the swapchain,
    // which is how both Proton and the frame generation interposers lay things out.
    uintptr_t inner_swapchain{0};
};

// There is no API to get the command queue out of a swapchain, so it gets scanned for.
CommandQueueScan find_command_queue_offset(IDXGISwapChain1* swap_chain, ID3D12CommandQueue* command_queue) {
    constexpr auto scan_size = 512 * sizeof(void*);

    CommandQueueScan result{};

    scan_readable_slots(swap_chain, scan_size, [&](uintptr_t slot) {
        if (*(ID3D12CommandQueue**)slot != command_queue) {
            return false;
        }

        result.command_queue_offset = (uint32_t)(slot - (uintptr_t)swap_chain);
        spdlog::info("Found command queue offset: {:x}", result.command_queue_offset);

        return true;
    });

    if (result.command_queue_offset != 0) {
        return result;
    }

    // Scan through every pointer in the swapchain looking for one that owns the command queue.
    // This is usually only necessary for Proton.
    scan_readable_slots(swap_chain, scan_size, [&](uintptr_t slot) {
        const auto scan_base = *(uintptr_t*)slot;

        if (scan_base == 0) {
            return false;
        }

        return scan_readable_slots((const void*)scan_base, scan_size, [&](uintptr_t inner_slot) {
            if (*(ID3D12CommandQueue**)inner_slot != command_queue) {
                return false;
            }

            result.command_queue_offset = (uint32_t)(inner_slot - scan_base);
            result.proton_swapchain_offset = (uint32_t)(slot - (uintptr_t)swap_chain);
            result.inner_swapchain = scan_base;

            spdlog::info("Proton potentially detected");
            spdlog::info("Found command queue offset: {:x}", result.command_queue_offset);

            return true;
        });
    });

    return result;
}

} // namespace

bool D3D12Hook::hook() {
    spdlog::info("Hooking D3D12");

    g_d3d12_hook = this;
    g_inside_d3d12_hook = true;

    utility::ScopeGuard guard{[]() {
        g_inside_d3d12_hook = false;
    }};

    // The offsets and vtables outlive an unhook, so re-hooking can skip all the probing.
    if (s_command_queue_offset != 0 && s_swapchain_vtable != nullptr && s_factory_vtable != nullptr) {
        spdlog::info("Reinitializing D3D12Hook via known pointers");
        return hook_impl();
    }

    spdlog::info("Creating dummy device");

    const auto device = create_dummy_device(D3D_FEATURE_LEVEL_11_0);

    if (device == nullptr) {
        return false;
    }

    spdlog::info("Dummy device: {:x}", (uintptr_t)device.Get());

    spdlog::info("Creating dummy DXGI factory");

    const auto factory = create_dummy_dxgi_factory();

    if (factory == nullptr) {
        return false;
    }

    spdlog::info("Creating dummy command queue");

    D3D12_COMMAND_QUEUE_DESC queue_desc{};
    queue_desc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
    queue_desc.Priority = 0;
    queue_desc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
    queue_desc.NodeMask = 0;

    Microsoft::WRL::ComPtr<ID3D12CommandQueue> command_queue;

    if (FAILED(device->CreateCommandQueue(&queue_desc, IID_PPV_ARGS(command_queue.GetAddressOf())))) {
        spdlog::error("Failed to create D3D12 Dummy Command Queue");
        return false;
    }

    spdlog::info("Creating dummy swapchain");

    DummyWindow dummy_window{};
    const auto swap_chain1 = create_dummy_swapchain(factory.Get(), command_queue.Get(), dummy_window);

    if (swap_chain1 == nullptr) {
        spdlog::error("Failed to create D3D12 Dummy Swap Chain");
        return false;
    }

    spdlog::info("Querying dummy swapchain");

    Microsoft::WRL::ComPtr<IDXGISwapChain3> swap_chain;

    if (FAILED(swap_chain1->QueryInterface(IID_PPV_ARGS(swap_chain.GetAddressOf())))) {
        spdlog::error("Failed to retrieve D3D12 DXGI SwapChain");
        return false;
    }

    if (is_frame_generation_swapchain(swap_chain1.Get())) {
        m_using_frame_generation_swapchain = true;
    }

    spdlog::info("Finding command queue offset");

    const auto scan = find_command_queue_offset(swap_chain1.Get(), command_queue.Get());

    if (scan.command_queue_offset == 0) {
        spdlog::error("Failed to find command queue offset");
        return false;
    }

    s_command_queue_offset = scan.command_queue_offset;
    s_proton_swapchain_offset = scan.proton_swapchain_offset;

    IDXGISwapChain3* target_swapchain = swap_chain.Get();

    if (scan.inner_swapchain != 0) {
        // The command queue sits behind a pointer: either this is the real swapchain
        // owned by a frame generation interposer, or we're on Proton.
        if (m_using_frame_generation_swapchain) {
            target_swapchain = (IDXGISwapChain3*)scan.inner_swapchain;
        } else {
            m_using_proton_swapchain = true;
        }
    }

    s_swapchain_vtable = *(void***)target_swapchain;
    s_factory_vtable = *(void***)factory.Get();

    return hook_impl();
}

bool D3D12Hook::hook_impl() {
    spdlog::info("Initializing hooks");

    try {
        hook_streamline();

        m_present_hook.reset();
        m_swapchain_hook.reset();

        m_is_phase_1 = true;

        auto& present_fn = s_swapchain_vtable[8]; // Present
        m_present_hook = std::make_unique<PointerHook>(&present_fn, &D3D12Hook::present);

        if (s_create_swapchain_hook == nullptr) {
            auto& create_swapchain_fn = s_factory_vtable[15]; // CreateSwapChainForHwnd
            s_create_swapchain_hook = std::make_unique<PointerHook>(&create_swapchain_fn, &D3D12Hook::create_swapchain);
        }

        m_hooked = true;
    } catch (const std::exception& e) {
        spdlog::error("Failed to initialize hooks: {}", e.what());
        m_hooked = false;
    }

    return m_hooked;
}

bool D3D12Hook::unhook() {
    std::unique_lock<std::shared_mutex> _(get_hook_monitor_mutex_safe());

    if (!m_hooked) {
        return true;
    }

    spdlog::info("Unhooking D3D12");

    m_present_hook.reset();
    m_swapchain_hook.reset();

    m_hooked = false;
    m_is_phase_1 = true;

    return true;
}

thread_local int32_t g_present_depth = 0;

HRESULT WINAPI D3D12Hook::present(IDXGISwapChain3* swap_chain, uint64_t sync_interval, uint64_t flags, void* r9) {
    std::shared_lock<std::shared_mutex> _{get_hook_monitor_mutex_safe()};

    auto d3d12 = g_d3d12_hook;

    decltype(D3D12Hook::present)* present_fn{nullptr};

    if (d3d12->m_is_phase_1) {
        present_fn = d3d12->m_present_hook->get_original<decltype(D3D12Hook::present)*>();
    } else {
        present_fn = d3d12->m_swapchain_hook->get_method<decltype(D3D12Hook::present)*>(8);
    }

    // GetHwnd is only needed while the hook is still global (phase 1). Once we have
    // vtable hooked a specific swapchain the instance check below is what filters.
    if (d3d12->m_is_phase_1) {
        HWND swapchain_wnd{nullptr};
        swap_chain->GetHwnd(&swapchain_wnd);

        if (WindowFilter::is_hwnd_filtered_fast(swapchain_wnd)) {
            return present_fn(swap_chain, sync_interval, flags, r9);
        }
    }

    if (!d3d12->m_is_phase_1 && swap_chain != d3d12->m_swapchain_hook->get_instance()) {
        return present_fn(swap_chain, sync_interval, flags, r9);
    }

    if (d3d12->m_is_phase_1) {
        // Remove the present hook, we will just rely on the vtable hook below
        // because we don't want to cause any conflicts with other hooks
        // vtable hooks are the least intrusive
        // And doing a global pointer replacement seems to have
        // conflicts with Streamline's hooks, causing unexplainable crashes
        d3d12->m_present_hook.reset();

        // vtable hook the swapchain instead of global hooking
        // this seems safer for whatever reason
        // if we globally hook the vtable pointers, it causes all sorts of weird conflicts with other hooks
        // dont hook present though via this hook so other hooks dont get confused
        d3d12->m_swapchain_hook = std::make_unique<VtableHook>(swap_chain);
        //d3d12->m_swapchain_hook->hook_method(2, (uintptr_t)&D3D12Hook::release);
        d3d12->m_swapchain_hook->hook_method(8, (uintptr_t)&D3D12Hook::present);
        d3d12->m_swapchain_hook->hook_method(13, (uintptr_t)&D3D12Hook::resize_buffers);
        d3d12->m_swapchain_hook->hook_method(14, (uintptr_t)&D3D12Hook::resize_target);
        d3d12->m_is_phase_1 = false;

        present_fn = d3d12->m_swapchain_hook->get_method<decltype(D3D12Hook::present)*>(8);
    }

    d3d12->m_inside_present = true;
    utility::ScopeGuard inside_present_guard{[d3d12]() { d3d12->m_inside_present = false; }};

    d3d12->m_swap_chain = swap_chain;

    // Older runtimes may not implement ID3D12Device4. Don't retry the query every frame if so.
    if (d3d12->m_device == nullptr && !d3d12->m_device_query_failed) {
        if (FAILED(swap_chain->GetDevice(IID_PPV_ARGS(d3d12->m_device.GetAddressOf())))) {
            d3d12->m_device_query_failed = true;
        }
    }

    if (d3d12->m_using_proton_swapchain) {
        const auto real_swapchain = *(uintptr_t*)((uintptr_t)swap_chain + d3d12->s_proton_swapchain_offset);
        d3d12->m_command_queue = *(ID3D12CommandQueue**)(real_swapchain + d3d12->s_command_queue_offset);
    } else {
        d3d12->m_command_queue = *(ID3D12CommandQueue**)((uintptr_t)swap_chain + d3d12->s_command_queue_offset);
    }

    if (d3d12->m_swapchain_0 == nullptr) {
        d3d12->m_swapchain_0 = swap_chain;
    } else if (d3d12->m_swapchain_1 == nullptr && swap_chain != d3d12->m_swapchain_0) {
        d3d12->m_swapchain_1 = swap_chain;
    }
    
    // Restore the original bytes
    // if an infinite loop occurs, this will prevent the game from crashing
    // while keeping our hook intact
    if (g_present_depth > 0) {
        return S_OK;
    }

    if (d3d12->m_on_present) {
        d3d12->m_on_present(*d3d12);
    }

    ++g_present_depth;

    auto result = S_OK;
    
    if (!d3d12->m_ignore_next_present) {
        result = present_fn(swap_chain, sync_interval, flags, r9);

        // Only genuine failures; success codes like DXGI_STATUS_OCCLUDED
        // (returned every frame while the window is minimized/occluded) are
        // not errors and would otherwise spam the log each present.
        if (FAILED(result)) {
            spdlog::error("Present failed: {:x}", (uint64_t)result);
        }
    } else {
        d3d12->m_ignore_next_present = false;
    }

    --g_present_depth;

    if (d3d12->m_on_post_present) {
        d3d12->m_on_post_present(*d3d12);
    }

    return result;
}

thread_local int32_t g_resize_buffers_depth = 0;

HRESULT WINAPI D3D12Hook::resize_buffers(IDXGISwapChain3* swap_chain, UINT buffer_count, UINT width, UINT height, DXGI_FORMAT new_format, UINT swap_chain_flags) {
    std::shared_lock<std::shared_mutex> _{get_hook_monitor_mutex_safe()};

    spdlog::info("D3D12 resize buffers called");
    spdlog::info(" Parameters: buffer_count {} width {} height {} new_format {} swap_chain_flags {}", buffer_count, width, height, new_format, swap_chain_flags);

    auto d3d12 = g_d3d12_hook;

    auto resize_buffers_fn = d3d12->m_swapchain_hook->get_method<decltype(D3D12Hook::resize_buffers)*>(13);

    d3d12->m_display_width = width;
    d3d12->m_display_height = height;

    if (g_resize_buffers_depth > 0) {
        return S_OK;
    }

    if (d3d12->m_on_resize_buffers) {
        d3d12->m_on_resize_buffers(*d3d12);
    }

    ++g_resize_buffers_depth;

    const auto result = resize_buffers_fn(swap_chain, buffer_count, width, height, new_format, swap_chain_flags);
    
    if (FAILED(result)) {
        spdlog::error("Resize buffers failed: {:x}", result);
    }

    --g_resize_buffers_depth;

    return result;
}

thread_local int32_t g_resize_target_depth = 0;

HRESULT WINAPI D3D12Hook::resize_target(IDXGISwapChain3* swap_chain, const DXGI_MODE_DESC* new_target_parameters) {
    std::shared_lock<std::shared_mutex> _{get_hook_monitor_mutex_safe()};

    spdlog::info("D3D12 resize target called");
    spdlog::info(" Parameters: new_target_parameters {:x}", (uintptr_t)new_target_parameters);

    auto d3d12 = g_d3d12_hook;

    auto resize_target_fn = d3d12->m_swapchain_hook->get_method<decltype(D3D12Hook::resize_target)*>(14);

    // NULL is legal here, it means "go back to the fullscreen desc the swapchain was created with".
    if (new_target_parameters != nullptr) {
        d3d12->m_render_width = new_target_parameters->Width;
        d3d12->m_render_height = new_target_parameters->Height;
    }

    // Restore the original code to the resize_buffers function.
    if (g_resize_target_depth > 0) {
        return S_OK;
    }

    if (d3d12->m_on_resize_target) {
        d3d12->m_on_resize_target(*d3d12);
    }

    ++g_resize_target_depth;

    const auto result = resize_target_fn(swap_chain, new_target_parameters);
    
    if (FAILED(result)) {
        spdlog::error("Resize target failed: {:x}", result);
    }

    --g_resize_target_depth;

    return result;
}

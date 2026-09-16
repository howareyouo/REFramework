#include "FrameRenderer.hpp"
#include "REFramework.hpp"

#include <spdlog/spdlog.h>
#include <imgui.h>
#include <ImGuizmo.h>
#include <imnodes.h>
#include "re2-imgui/imgui_impl_dx11.h"
#include "re2-imgui/imgui_impl_dx12.h"
#include "re2-imgui/imgui_impl_win32.h"

#include "Mods.hpp"
#include "D3D11Hook.hpp"
#include "D3D12Hook.hpp"

namespace render {

// D3D11 Initialization
bool init_d3d11(REFramework& fw) {
    fw.deinit_d3d11();

    auto swapchain = fw.m_d3d11_hook->get_swap_chain();
    auto device = fw.m_d3d11_hook->get_device();

    spdlog::info("[D3D11] Creating RTV of back buffer...");

    Microsoft::WRL::ComPtr<ID3D11Texture2D> backbuffer{};

    if (FAILED(swapchain->GetBuffer(0, IID_PPV_ARGS(&backbuffer)))) {
        spdlog::error("[D3D11] Failed to get back buffer!");
        return false;
    }

    if (FAILED(device->CreateRenderTargetView(backbuffer.Get(), nullptr, &fw.m_d3d11.bb_rtv))) {
        spdlog::error("[D3D11] Failed to create back buffer render target view!");
        return false;
    }

    D3D11_TEXTURE2D_DESC backbuffer_desc{};
    backbuffer->GetDesc(&backbuffer_desc);
    backbuffer_desc.BindFlags |= D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE;

    spdlog::info("[D3D11] Back buffer format is {}", backbuffer_desc.Format);
    spdlog::info("[D3D11] Creating render targets...");

    {
        auto d3d11_rt_desc = backbuffer_desc;
        d3d11_rt_desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;

        if (FAILED(device->CreateTexture2D(&d3d11_rt_desc, nullptr, &fw.m_d3d11.blank_rt))) {
            spdlog::error("[D3D11] Failed to create render target texture!");
            return false;
        }

        if (FAILED(device->CreateTexture2D(&d3d11_rt_desc, nullptr, &fw.m_d3d11.rt))) {
            spdlog::error("[D3D11] Failed to create render target texture!");
            return false;
        }
    }

    spdlog::info("[D3D11] Creating rtvs...");

    if (FAILED(device->CreateRenderTargetView(fw.m_d3d11.blank_rt.Get(), nullptr, &fw.m_d3d11.blank_rt_rtv))) {
        spdlog::error("[D3D11] Failed to create render target view!");
        return false;
    }

    if (FAILED(device->CreateRenderTargetView(fw.m_d3d11.rt.Get(), nullptr, &fw.m_d3d11.rt_rtv))) {
        spdlog::error("[D3D11] Failed to create render target view!");
        return false;
    }

    spdlog::info("[D3D11] Creating srvs...");

    if (FAILED(device->CreateShaderResourceView(fw.m_d3d11.rt.Get(), nullptr, &fw.m_d3d11.rt_srv))) {
        spdlog::error("[D3D11] Failed to create shader resource view!");
        return false;
    }

    fw.m_d3d11.rt_width = backbuffer_desc.Width;
    fw.m_d3d11.rt_height = backbuffer_desc.Height;

    spdlog::info("[D3D11] Initializing ImGui D3D11...");

    Microsoft::WRL::ComPtr<ID3D11DeviceContext> context{};
    device->GetImmediateContext(&context);

    if (!ImGui_ImplDX11_Init(device, context.Get())) {
        spdlog::error("[D3D11] Failed to initialize ImGui.");
        return false;
    }

    return true;
}

void deinit_d3d11(REFramework& fw) {
    ImGui_ImplDX11_Shutdown();
    fw.m_d3d11 = {};
}

// D3D12 Initialization
static bool init_imgui_d3d12_impl(REFramework& fw, ID3D12Device* device, ID3D12CommandQueue* queue,
                                    DXGI_FORMAT rtv_format, uint32_t frame_count,
                                    ID3D12DescriptorHeap* srv_heap, void** out_backend_userdata) {
    ImGui_ImplDX12_InitInfo info{};
    info.Device = device;
    info.CommandQueue = queue;
    info.NumFramesInFlight = frame_count;
    info.RTVFormat = rtv_format;
    info.DSVFormat = DXGI_FORMAT_UNKNOWN;
    info.SrvDescriptorHeap = srv_heap;
    info.SrvDescriptorAllocFn = [](ImGui_ImplDX12_InitInfo* i, D3D12_CPU_DESCRIPTOR_HANDLE* out_cpu, D3D12_GPU_DESCRIPTOR_HANDLE* out_gpu) {
        static int next_descriptor = 0;
        int index = next_descriptor++;
        SIZE_T increment = i->Device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);
        *out_cpu = {i->SrvDescriptorHeap->GetCPUDescriptorHandleForHeapStart().ptr + (SIZE_T)index * increment};
        *out_gpu = {i->SrvDescriptorHeap->GetGPUDescriptorHandleForHeapStart().ptr + (SIZE_T)index * increment};
    };
    info.SrvDescriptorFreeFn = [](ImGui_ImplDX12_InitInfo*, D3D12_CPU_DESCRIPTOR_HANDLE, D3D12_GPU_DESCRIPTOR_HANDLE) {};

    if (!ImGui_ImplDX12_Init(&info)) {
        spdlog::error("[D3D12] Failed to initialize ImGui.");
        return false;
    }
    *out_backend_userdata = ImGui::GetIO().BackendRendererUserData;
    return true;
}

bool init_d3d12(REFramework& fw) {
    fw.deinit_d3d12();
    
    auto device = fw.m_d3d12_hook->get_device();

    spdlog::info("[D3D12] Creating DXTK graphics memory...");
    fw.m_d3d12.graphics_memory.reset();
    fw.m_d3d12.graphics_memory = std::make_unique<DirectX::DX12::GraphicsMemory>(device);

    spdlog::info("[D3D12] Creating command allocator...");
    fw.m_d3d12.cmd_ctxs.clear();

    for (auto i = 0; i < 3; ++i) {
        auto& ctx = fw.m_d3d12.cmd_ctxs.emplace_back(std::make_unique<d3d12::CommandContext>());
        if (!ctx->setup(L"Framework::m_d3d12.cmd_ctx")) {
            spdlog::error("[D3D12] Failed to create command context.");
            return false;
        }
    }

    spdlog::info("[D3D12] Creating RTV descriptor heap...");
    {
        D3D12_DESCRIPTOR_HEAP_DESC desc{};
        desc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
        desc.NumDescriptors = (int)REFramework::D3D12::RTV::COUNT; 
        desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
        desc.NodeMask = 1;

        if (FAILED(device->CreateDescriptorHeap(&desc, IID_PPV_ARGS(&fw.m_d3d12.rtv_desc_heap)))) {
            spdlog::error("[D3D12] Failed to create RTV descriptor heap.");
            return false;
        }
        fw.m_d3d12.rtv_desc_heap->SetName(L"Framework::m_d3d12.rtv_desc_heap");
    }

    spdlog::info("[D3D12] Creating SRV descriptor heap...");
    { 
        D3D12_DESCRIPTOR_HEAP_DESC desc{};
        desc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
        desc.NumDescriptors = (int)REFramework::D3D12::SRV::COUNT;
        desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

        if (FAILED(device->CreateDescriptorHeap(&desc, IID_PPV_ARGS(&fw.m_d3d12.srv_desc_heap)))) {
            spdlog::error("[D3D12] Failed to create SRV descriptor heap.");
            return false;
        }
        fw.m_d3d12.srv_desc_heap->SetName(L"Framework::m_d3d12.srv_desc_heap");
    }

    // Precompute CPU descriptor handles once
    {
        const auto rtv_increment = device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
        const auto srv_increment = device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);
        const auto rtv_base = fw.m_d3d12.rtv_desc_heap->GetCPUDescriptorHandleForHeapStart();
        const auto srv_base = fw.m_d3d12.srv_desc_heap->GetCPUDescriptorHandleForHeapStart();

        for (int i = 0; i < (int)REFramework::D3D12::RTV::COUNT; ++i) {
            fw.m_d3d12.cpu_rtvs[i] = {rtv_base.ptr + (SIZE_T)i * rtv_increment};
        }
        for (int i = 0; i < (int)REFramework::D3D12::SRV::COUNT; ++i) {
            fw.m_d3d12.cpu_srvs[i] = {srv_base.ptr + (SIZE_T)i * srv_increment};
        }
    }

    spdlog::info("[D3D12] Creating render targets...");
    auto swapchain = fw.m_d3d12_hook->get_swap_chain();
    DXGI_SWAP_CHAIN_DESC swapchain_desc{};

    if (FAILED(swapchain->GetDesc(&swapchain_desc))) {
        spdlog::error("[D3D12] Failed to get swap chain description.");
        return false;
    }

    spdlog::info("[D3D12] Swapchain buffer count: {}", swapchain_desc.BufferCount);

    {
        if (swapchain_desc.BufferCount > (int)REFramework::D3D12::RTV::BACKBUFFER_LAST + 1) {
            spdlog::warn("[D3D12] Too many back buffers ({} vs {}).", swapchain_desc.BufferCount, (int)REFramework::D3D12::RTV::BACKBUFFER_LAST + 1);
        }

        for (auto i = 0; i < (int)swapchain_desc.BufferCount; ++i) {
            if (SUCCEEDED(swapchain->GetBuffer(i, IID_PPV_ARGS(&fw.m_d3d12.rts[i])))) {
                device->CreateRenderTargetView(fw.m_d3d12.rts[i].Get(), nullptr, fw.m_d3d12.get_cpu_rtv(device, (REFramework::D3D12::RTV)i));
            } else {
                spdlog::error("[D3D12] Failed to get back buffer for rtv {}", i);
                fw.m_d3d12.rts[i].Reset();
            }
        }

        auto& backbuffer = fw.m_d3d12.get_rt(REFramework::D3D12::RTV::BACKBUFFER_0);
        if (backbuffer == nullptr) {
            spdlog::error("[D3D12] Failed to get first back buffer RTV.");
            fw.deinit_d3d12();
            return false;
        }

        auto desc = backbuffer->GetDesc();
        spdlog::info("[D3D12] Back buffer format is {}", desc.Format);

        D3D12_HEAP_PROPERTIES props{};
        props.Type = D3D12_HEAP_TYPE_DEFAULT;
        props.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
        props.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;

        auto d3d12_rt_desc = desc;
        d3d12_rt_desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;

        D3D12_CLEAR_VALUE clear_value{};
        clear_value.Format = d3d12_rt_desc.Format;

        if (FAILED(device->CreateCommittedResource(&props, D3D12_HEAP_FLAG_NONE, &d3d12_rt_desc,
                D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE, &clear_value,
                IID_PPV_ARGS(&fw.m_d3d12.get_rt(REFramework::D3D12::RTV::IMGUI))))) {
            spdlog::error("[D3D12] Failed to create the imgui render target.");
            return false;
        }
        fw.m_d3d12.get_rt(REFramework::D3D12::RTV::IMGUI)->SetName(L"Framework::m_d3d12.rts[IMGUI]");

        if (FAILED(device->CreateCommittedResource(&props, D3D12_HEAP_FLAG_NONE, &d3d12_rt_desc,
                D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE, &clear_value,
                IID_PPV_ARGS(&fw.m_d3d12.get_rt(REFramework::D3D12::RTV::BLANK))))) {
            spdlog::error("[D3D12] Failed to create the blank render target.");
            return false;
        }
        fw.m_d3d12.get_rt(REFramework::D3D12::RTV::BLANK)->SetName(L"Framework::m_d3d12.rts[BLANK]");

        device->CreateRenderTargetView(
            fw.m_d3d12.get_rt(REFramework::D3D12::RTV::IMGUI).Get(), nullptr,
            fw.m_d3d12.get_cpu_rtv(device, REFramework::D3D12::RTV::IMGUI));
        device->CreateRenderTargetView(
            fw.m_d3d12.get_rt(REFramework::D3D12::RTV::BLANK).Get(), nullptr,
            fw.m_d3d12.get_cpu_rtv(device, REFramework::D3D12::RTV::BLANK));
        device->CreateShaderResourceView(
            fw.m_d3d12.get_rt(REFramework::D3D12::RTV::IMGUI).Get(), nullptr,
            fw.m_d3d12.get_cpu_srv(device, REFramework::D3D12::SRV::IMGUI_VR));
        device->CreateShaderResourceView(
            fw.m_d3d12.get_rt(REFramework::D3D12::RTV::BLANK).Get(), nullptr,
            fw.m_d3d12.get_cpu_srv(device, REFramework::D3D12::SRV::BLANK));

        fw.m_d3d12.rt_width = (uint32_t)desc.Width;
        fw.m_d3d12.rt_height = (uint32_t)desc.Height;
    }

    spdlog::info("[D3D12] Initializing ImGui...");
    auto& bb = fw.m_d3d12.get_rt(REFramework::D3D12::RTV::BACKBUFFER_0);
    auto bb_desc = bb->GetDesc();

    if (!init_imgui_d3d12_impl(fw, device, fw.m_d3d12_hook->get_command_queue(), bb_desc.Format,
                               swapchain_desc.BufferCount, fw.m_d3d12.srv_desc_heap.Get(), &fw.m_d3d12.imgui_backend_datas[0])) {
        return false;
    }

    ImGui::GetIO().BackendRendererUserData = nullptr;

    auto& bb_vr = fw.m_d3d12.get_rt(REFramework::D3D12::RTV::IMGUI);
    auto bb_vr_desc = bb_vr->GetDesc();

    if (!init_imgui_d3d12_impl(fw, device, fw.m_d3d12_hook->get_command_queue(), bb_vr_desc.Format,
                               swapchain_desc.BufferCount, fw.m_d3d12.srv_desc_heap.Get(), &fw.m_d3d12.imgui_backend_datas[1])) {
        return false;
    }

    return true;
}

void deinit_d3d12(REFramework& fw) {
    for (auto& ctx : fw.m_d3d12.cmd_ctxs) {
        if (ctx != nullptr) {
            ctx->reset();
        }
    }
    fw.m_d3d12.cmd_ctxs.clear();

    for (auto userdata : fw.m_d3d12.imgui_backend_datas) {
        if (userdata != nullptr) {
            ImGui::GetIO().BackendRendererUserData = userdata;
            ImGui_ImplDX12_Shutdown();
        }
    }
    ImGui::GetIO().BackendRendererUserData = nullptr;
    fw.m_d3d12 = {};
}

// Per-frame rendering ---------------------------------------------------------

void on_frame_d3d11(REFramework& fw) {
    std::scoped_lock _{ fw.m_imgui_mtx };

    if (!fw.m_initialized) {
        if (!fw.initialize()) {
            return;
        }
        spdlog::info("REFramework initialized");
        fw.m_initialized = true;
        return;
    }

    if (fw.m_message_hook_requested.load()) {
        fw.initialize_windows_message_hook();
    }

    auto device = fw.m_d3d11_hook->get_device();
    if (device == nullptr) {
        spdlog::error("D3D11 device was null when it shouldn't be, returning...");
        fw.m_initialized = false;
        return;
    }

    const auto is_init_ok = fw.on_frame_common_init();

    if (!fw.m_has_frame && is_init_ok) {
        return;
    }

    if (!fw.m_has_frame) {
        fw.init_fonts();
    }

    fw.invalidate_device_objects();
    ImGui_ImplDX11_NewFrame();

    if (!fw.m_has_frame) {
        fw.run_imgui_frame(true);
    }

    if (is_init_ok && fw.m_mods != nullptr) {
        fw.m_mods->on_present();
    }

    Microsoft::WRL::ComPtr<ID3D11DeviceContext> context{};
    float clear_color[]{0.0f, 0.0f, 0.0f, 0.0f};

    fw.m_d3d11_hook->get_device()->GetImmediateContext(&context);
    context->ClearRenderTargetView(fw.m_d3d11.blank_rt_rtv.Get(), clear_color);
    context->OMSetRenderTargets(1, fw.m_d3d11.bb_rtv.GetAddressOf(), nullptr);
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

    if (is_init_ok) {
        fw.m_mods->on_post_frame();
    }
}

void on_post_present_d3d11(REFramework& fw) {
    const auto now = std::chrono::steady_clock::now();

    if (!fw.m_error.empty() || !fw.m_initialized || !fw.m_game_data_initialized) {
        if (fw.m_last_present_time.load() <= now) {
            fw.m_last_present_time.store(now);
        }
        return;
    }

    if (fw.m_mods != nullptr) {
        for (auto& mod : fw.m_mods->get_mods()) {
            mod->on_post_present();
        }
    }

    if (fw.m_last_present_time.load() <= now) {
        fw.m_last_present_time.store(now);
    }
}

void on_frame_d3d12(REFramework& fw) {
    std::scoped_lock _{ fw.m_imgui_mtx };

    auto command_queue = fw.m_d3d12_hook->get_command_queue();
    
    if (!fw.m_initialized) {
        if (!fw.initialize()) {
            return;
        }
        spdlog::info("REFramework initialized");
        fw.m_initialized = true;
        return;
    }

    if (command_queue == nullptr) {
        spdlog::error("Null Command Queue");
        return;
    }

    if (fw.m_message_hook_requested.load()) {
        fw.initialize_windows_message_hook();
    }

    auto device = fw.m_d3d12_hook->get_device();
    if (device == nullptr) {
        spdlog::error("D3D12 Device was null when it shouldn't be, returning...");
        fw.m_initialized = false;
        return;
    }

    const auto is_init_ok = fw.on_frame_common_init();

    auto do_per_frame_thing = [&]() {
        ImGui::GetIO().BackendRendererUserData = fw.m_d3d12.imgui_backend_datas[0];
        const auto prev_cleanup = fw.m_wants_device_object_cleanup;
        fw.invalidate_device_objects();
        ImGui_ImplDX12_NewFrame();

        ImGui::GetIO().BackendRendererUserData = fw.m_d3d12.imgui_backend_datas[1];
        fw.m_wants_device_object_cleanup = prev_cleanup;
        fw.invalidate_device_objects();
        ImGui_ImplDX12_NewFrame();
    };

    if (!fw.m_has_frame && is_init_ok) {
        return;
    }

    if (!fw.m_has_frame) {
        fw.init_fonts();
    }

    do_per_frame_thing();

    if (!fw.m_has_frame) {
        fw.run_imgui_frame(true);
    }

    if (is_init_ok && fw.m_mods != nullptr) {
        fw.m_mods->on_present();
    }

    if (fw.m_d3d12.cmd_ctxs.empty()) {
        return;
    }

    auto swapchain = fw.m_d3d12_hook->get_swap_chain();
    const auto bb_index = swapchain->GetCurrentBackBufferIndex();
    auto& cmd_ctx = fw.m_d3d12.cmd_ctxs[bb_index % fw.m_d3d12.cmd_ctxs.size()];

    if (cmd_ctx == nullptr) {
        return;
    }

    if (fw.m_d3d12.get_rt((REFramework::D3D12::RTV)bb_index) == nullptr) {
        spdlog::error("RTV for index {} is null, reinitializing...", bb_index);
        fw.deinit_d3d12();
        fw.m_has_frame = false;
        fw.m_first_initialize = false;
        fw.m_initialized = false;
        return;
    }

    cmd_ctx->wait(INFINITE);
    {
        std::scoped_lock _{ cmd_ctx->mtx };
        cmd_ctx->has_commands = true;

        D3D12_RESOURCE_BARRIER barrier{};
        barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
        barrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
        barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;

        D3D12_CPU_DESCRIPTOR_HANDLE rts[1]{};

        // Transition IMGUI RT -> RENDER_TARGET
        barrier.Transition.pResource = fw.m_d3d12.get_rt(REFramework::D3D12::RTV::IMGUI).Get();
        barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_PRESENT;
        barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_RENDER_TARGET;
        cmd_ctx->cmd_list->ResourceBarrier(1, &barrier);

        float clear_color[]{0.0f, 0.0f, 0.0f, 0.0f};
        cmd_ctx->cmd_list->ClearRenderTargetView(fw.m_d3d12.cpu_rtvs[(int)REFramework::D3D12::RTV::IMGUI], clear_color, 0, nullptr);
        rts[0] = fw.m_d3d12.cpu_rtvs[(int)REFramework::D3D12::RTV::IMGUI];
        cmd_ctx->cmd_list->OMSetRenderTargets(1, rts, FALSE, NULL);
        cmd_ctx->cmd_list->SetDescriptorHeaps(1, fw.m_d3d12.srv_desc_heap.GetAddressOf());

        ImGui::GetIO().BackendRendererUserData = fw.m_d3d12.imgui_backend_datas[0];
        ImGui_ImplDX12_RenderDrawData(ImGui::GetDrawData(), cmd_ctx->cmd_list.Get());
        
        // Transition IMGUI RT -> PRESENT
        barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
        barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_PRESENT;
        cmd_ctx->cmd_list->ResourceBarrier(1, &barrier);

        // Transition back buffer -> RENDER_TARGET
        barrier.Transition.pResource = fw.m_d3d12.rts[bb_index].Get();
        barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_PRESENT;
        barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_RENDER_TARGET;
        cmd_ctx->cmd_list->ResourceBarrier(1, &barrier);
        rts[0] = fw.m_d3d12.cpu_rtvs[bb_index];
        cmd_ctx->cmd_list->OMSetRenderTargets(1, rts, FALSE, NULL);
        cmd_ctx->cmd_list->SetDescriptorHeaps(1, fw.m_d3d12.srv_desc_heap.GetAddressOf());

        ImGui::GetIO().BackendRendererUserData = fw.m_d3d12.imgui_backend_datas[0];
        ImGui_ImplDX12_RenderDrawData(ImGui::GetDrawData(), cmd_ctx->cmd_list.Get());

        // Transition back buffer -> PRESENT
        barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
        barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_PRESENT;
        cmd_ctx->cmd_list->ResourceBarrier(1, &barrier);

        cmd_ctx->execute();
    }

    if (is_init_ok && fw.m_mods != nullptr) {
        fw.m_mods->on_post_frame();
    }
}

void on_post_present_d3d12(REFramework& fw) {
    const auto now = std::chrono::steady_clock::now();

    if (!fw.m_error.empty() || !fw.m_initialized || !fw.m_game_data_initialized) {
        if (fw.m_last_present_time.load() <= now) {
            fw.m_last_present_time.store(now);
        }
        return;
    }

    if (fw.m_d3d12.graphics_memory != nullptr) {
        auto& hook = fw.get_d3d12_hook();
        auto command_queue = hook->get_command_queue();
        fw.m_d3d12.graphics_memory->Commit(command_queue);
    }

    if (fw.m_mods != nullptr) {
        for (auto& mod : fw.m_mods->get_mods()) {
            mod->on_post_present();
        }
    }

    if (fw.m_last_present_time.load() <= now) {
        fw.m_last_present_time.store(now);
    }
}

} // namespace render

#include "BackBufferRenderer.hpp"

std::shared_ptr<BackBufferRenderer>& BackBufferRenderer::get() {
    static auto instance = std::make_shared<BackBufferRenderer>();
    return instance;
}

std::optional<std::string> BackBufferRenderer::on_initialize_d3d_thread() {
    if (g_framework->is_dx12()) {
        if (!ensure_swapchain()) {
            return "Failed to get swapchain or device";
        }

        d3d12::ComPtr<ID3D12Resource> backbuffer{};
        if (FAILED(m_d3d12.swapchain->GetBuffer(0, IID_PPV_ARGS(&backbuffer)))) {
            return "Failed to get back buffer";
        }

        m_d3d12.default_rt_state = DirectX::RenderTargetState{backbuffer->GetDesc().Format, DXGI_FORMAT_UNKNOWN};

        ensure_command_contexts();

        spdlog::info("BackBufferRenderer D3D12 initialized");
    } else {
        // TODO
        spdlog::info("BackBufferRenderer D3D11 initialized");
    }

    // OK
    return Mod::on_initialize();
}

void BackBufferRenderer::on_device_reset() {
    m_d3d12.device = nullptr;
    m_d3d12.swapchain = nullptr;
    m_d3d12.swapchain3.Reset();

    for (auto& ctx : m_d3d12.command_contexts) {
        ctx.reset();
    }

    for (auto& bb : m_d3d12.backbuffers) {
        bb.reset();
    }
}

void BackBufferRenderer::ensure_command_contexts() {
    for (auto& context : m_d3d12.command_contexts) {
        if (context == nullptr) {
            context = std::make_unique<d3d12::CommandContext>();
            context->setup(L"BackBufferRenderer D3D12 Command Context");
        }
    }
}

bool BackBufferRenderer::ensure_swapchain() {
    auto* device = g_framework->get_d3d12_hook()->get_device();
    auto* swapchain = g_framework->get_d3d12_hook()->get_swap_chain();

    if (device == nullptr || swapchain == nullptr) {
        return false;
    }

    m_d3d12.device = device;

    // Re-query the swapchain3 interface only when the swapchain changed (resize/device reset).
    if (m_d3d12.swapchain != swapchain) {
        m_d3d12.swapchain = swapchain;
        m_d3d12.swapchain3.Reset();

        if (FAILED(swapchain->QueryInterface(IID_PPV_ARGS(&m_d3d12.swapchain3)))) {
            return false;
        }
    }

    return m_d3d12.swapchain3 != nullptr;
}

d3d12::TextureContext* BackBufferRenderer::ensure_backbuffer(UINT index) {
    const auto slot = index % m_d3d12.backbuffers.size();

    d3d12::ComPtr<ID3D12Resource> backbuffer{};
    if (FAILED(m_d3d12.swapchain->GetBuffer(index, IID_PPV_ARGS(&backbuffer)))) {
        return nullptr;
    }

    auto& ctx = m_d3d12.backbuffers[slot];
    if (ctx != nullptr && ctx->texture.Get() == backbuffer.Get()) {
        return ctx.get();
    }

    ctx = std::make_unique<d3d12::TextureContext>();
    if (!ctx->setup(m_d3d12.device, backbuffer.Get(), std::nullopt, std::nullopt, L"BackBufferRenderer Backbuffer")) {
        spdlog::error("[BackBufferRenderer] Failed to setup backbuffer {}", index);
        ctx.reset();
        return nullptr;
    }

    spdlog::info("[BackBufferRenderer] Setting up backbuffer {}", index);
    return ctx.get();
}

void BackBufferRenderer::render_d3d12() {
    // Short-lived lock just for the emptiness check; the actual queue is drained
    // later under the same mutex via swap(). The render work runs outside the
    // lock, since it may submit more work itself.
    {
        std::scoped_lock _{m_d3d12.render_work_mtx};

        if (m_d3d12.render_work.empty()) {
            return;
        }
    }

    ensure_command_contexts();

    if (!ensure_swapchain()) {
        return;
    }

    const auto bb_index = m_d3d12.swapchain3->GetCurrentBackBufferIndex();

    auto* bb_context = ensure_backbuffer(bb_index);
    if (bb_context == nullptr) {
        return;
    }

    auto& command_context = m_d3d12.command_contexts[bb_index % m_d3d12.command_contexts.size()];
    command_context->wait(2000);

    const auto desc = bb_context->texture->GetDesc();

    D3D12_RECT scissor_rect{};
    scissor_rect.right = (LONG)desc.Width;
    scissor_rect.bottom = (LONG)desc.Height;

    m_d3d12.viewport.Width = (float)desc.Width;
    m_d3d12.viewport.Height = (float)desc.Height;
    m_d3d12.viewport.MaxDepth = 1.0f;

    auto* backbuffer = bb_context->texture.Get();
    auto& cmd_list = command_context->cmd_list;

    command_context->transition(backbuffer, D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET);

    auto rtv = bb_context->get_rtv();
    cmd_list->OMSetRenderTargets(1, &rtv, FALSE, nullptr);
    cmd_list->RSSetViewports(1, &m_d3d12.viewport);
    cmd_list->RSSetScissorRects(1, &scissor_rect);

    decltype(m_d3d12.render_work) work{};
    {
        std::scoped_lock _{m_d3d12.render_work_mtx};
        work.swap(m_d3d12.render_work);
    }

    const RenderWorkData data{
        cmd_list.Get(),
        m_d3d12.viewport,
        bb_context
    };

    for (auto& fn : work) {
        fn(data);
    }

    command_context->transition(backbuffer, D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT);

    command_context->execute();
}

void BackBufferRenderer::render_d3d11() {
    // TODO
}

void BackBufferRenderer::on_present() {
    if (g_framework->is_dx12()) {
        render_d3d12();
    } else {
        render_d3d11();
    }
}

void BackBufferRenderer::on_frame() {
    // Clearing this here instead of every time whenever we present fixes flickering in some games
    std::scoped_lock _{m_d3d12.render_work_mtx};
    m_d3d12.render_work.clear();
}
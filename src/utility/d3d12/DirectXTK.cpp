#include "DirectXTK.hpp"

namespace d3d12 {
void render_srv_to_rtv(
    DirectX::DX12::SpriteBatch* batch,
    ID3D12GraphicsCommandList* command_list, 
    const d3d12::TextureContext& src, 
    const d3d12::TextureContext& dst, 
    D3D12_RESOURCE_STATES src_state, 
    D3D12_RESOURCE_STATES dst_state)
{
    const auto dst_desc = dst.texture->GetDesc();
    const auto src_desc = src.texture->GetDesc();

    const D3D12_VIEWPORT viewport{ 0.0f, 0.0f, (float)dst_desc.Width, (float)dst_desc.Height, D3D12_MIN_DEPTH, D3D12_MAX_DEPTH };
    const RECT rect{ 0, 0, (LONG)dst_desc.Width, (LONG)dst_desc.Height };

    batch->SetViewport(viewport);

    const auto transition = [&](D3D12_RESOURCE_STATES before, D3D12_RESOURCE_STATES after) {
        D3D12_RESOURCE_BARRIER barrier{};
        barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
        barrier.Transition.pResource = dst.texture.Get();
        barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
        barrier.Transition.StateBefore = before;
        barrier.Transition.StateAfter = after;
        command_list->ResourceBarrier(1, &barrier);
    };

    if (dst_state != D3D12_RESOURCE_STATE_RENDER_TARGET) {
        transition(dst_state, D3D12_RESOURCE_STATE_RENDER_TARGET);
    }

    // Set RTV to backbuffer
    D3D12_CPU_DESCRIPTOR_HANDLE rtv_heaps[] = { dst.get_rtv() };
    command_list->OMSetRenderTargets(1, rtv_heaps, FALSE, nullptr);

    // Setup viewport and scissor rects
    command_list->RSSetViewports(1, &viewport);
    command_list->RSSetScissorRects(1, &rect);

    batch->Begin(command_list, DirectX::DX12::SpriteSortMode::SpriteSortMode_Immediate);

    // Set descriptor heaps
    ID3D12DescriptorHeap* game_heaps[] = { src.srv_heap->Heap() };
    command_list->SetDescriptorHeaps(1, game_heaps);

    batch->Draw(src.get_srv_gpu(), 
        DirectX::XMUINT2{ (uint32_t)src_desc.Width, (uint32_t)src_desc.Height },
        rect,
        DirectX::Colors::White);

    batch->End();

    // Transition dst to dst_state
    if (dst_state != D3D12_RESOURCE_STATE_RENDER_TARGET) {
        transition(D3D12_RESOURCE_STATE_RENDER_TARGET, dst_state);
    }
}
}

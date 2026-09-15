#include <utility/String.hpp>

#include <spdlog/spdlog.h>

#include "CommandContext.hpp"
#include "TextureContext.hpp"

namespace d3d12 {
namespace {
std::unique_ptr<DirectX::DescriptorHeap> make_heap(ID3D12Device* device, D3D12_DESCRIPTOR_HEAP_TYPE type,
    D3D12_DESCRIPTOR_HEAP_FLAGS flags, const char* label)
{
    try {
        return std::make_unique<DirectX::DescriptorHeap>(device, type, flags, 1);
    } catch (...) {
        spdlog::error("Failed to create {} descriptor heap", label);
        return nullptr;
    }
}
}

bool TextureContext::setup(ID3D12Device* device, ID3D12Resource* rsrc, std::optional<DXGI_FORMAT> rtv_format, std::optional<DXGI_FORMAT> srv_format, const wchar_t* name) {
    spdlog::info("Setting up texture context for {}", utility::narrow(name));

    reset();

    commands.setup(name);

    texture = rsrc;

    if (rsrc == nullptr) {
        return false;
    }

    return create_rtv(device, rtv_format) && create_srv(device, srv_format);
}

bool TextureContext::create_rtv(ID3D12Device* device, std::optional<DXGI_FORMAT> format) {
    spdlog::info("Creating RTV for texture context");

    rtv_heap = make_heap(device, D3D12_DESCRIPTOR_HEAP_TYPE_RTV, D3D12_DESCRIPTOR_HEAP_FLAG_NONE, "RTV");

    if (rtv_heap == nullptr || rtv_heap->Heap() == nullptr) {
        return false;
    }

    if (format) {
        D3D12_RENDER_TARGET_VIEW_DESC rtv_desc{};
        rtv_desc.Format = (DXGI_FORMAT)*format;
        rtv_desc.ViewDimension = D3D12_RTV_DIMENSION_TEXTURE2D;
        device->CreateRenderTargetView(texture.Get(), &rtv_desc, get_rtv());
    } else {
        device->CreateRenderTargetView(texture.Get(), nullptr, get_rtv());
    }

    return true;
}

bool TextureContext::create_srv(ID3D12Device* device, std::optional<DXGI_FORMAT> format) {
    spdlog::info("Creating SRV for texture context");

    srv_heap = make_heap(device, D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV, D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE, "SRV");

    if (srv_heap == nullptr || srv_heap->Heap() == nullptr) {
        return false;
    }

    if (format) {
        D3D12_SHADER_RESOURCE_VIEW_DESC srv_desc{};
        srv_desc.Format = (DXGI_FORMAT)*format;
        srv_desc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
        srv_desc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
        srv_desc.Texture2D.MipLevels = 1;
        device->CreateShaderResourceView(texture.Get(), &srv_desc, get_srv_cpu());
    } else {
        device->CreateShaderResourceView(texture.Get(), nullptr, get_srv_cpu());
    }

    return true;
}
}

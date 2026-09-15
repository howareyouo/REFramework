#include <spdlog/spdlog.h>
#include <utility/String.hpp>

#include "REFramework.hpp"

#include "ResourceCopier.hpp"

namespace d3d12 {
namespace {
D3D12_RESOURCE_BARRIER make_transition(ID3D12Resource* resource, D3D12_RESOURCE_STATES before, D3D12_RESOURCE_STATES after) {
    D3D12_RESOURCE_BARRIER barrier{};
    barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    barrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
    barrier.Transition.pResource = resource;
    barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    barrier.Transition.StateBefore = before;
    barrier.Transition.StateAfter = after;
    return barrier;
}

void record_copy_barriers(
    ID3D12GraphicsCommandList* cmd_list,
    ID3D12Resource* src, ID3D12Resource* dst,
    D3D12_RESOURCE_STATES src_before, D3D12_RESOURCE_STATES src_after,
    D3D12_RESOURCE_STATES dst_before, D3D12_RESOURCE_STATES dst_after)
{
    const D3D12_RESOURCE_BARRIER barriers[2]{
        make_transition(src, src_before, src_after),
        make_transition(dst, dst_before, dst_after),
    };

    cmd_list->ResourceBarrier(2, barriers);
}
}

bool ResourceCopier::setup(const wchar_t* name) {
    std::scoped_lock _{this->mtx};

    this->internal_name = name;

    auto& hook = g_framework->get_d3d12_hook();
    auto device = hook->get_device();

    this->cmd_allocator.Reset();
    this->cmd_list.Reset();
    this->fence.Reset();

    const auto fail = [&](const char* what) {
        spdlog::error("[d3d12] Failed to create {} for {}", what, utility::narrow(name));
        return false;
    };

    if (FAILED(device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&this->cmd_allocator)))) {
        return fail("command allocator");
    }

    this->cmd_allocator->SetName(name);

    if (FAILED(device->CreateCommandList(
            0, D3D12_COMMAND_LIST_TYPE_DIRECT, this->cmd_allocator.Get(), nullptr, IID_PPV_ARGS(&this->cmd_list)))) {
        return fail("command list");
    }

    this->cmd_list->SetName(name);

    if (FAILED(device->CreateFence(this->fence_value, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&this->fence)))) {
        return fail("fence");
    }

    this->fence->SetName(name);

    // Close any pre-existing event so a second setup() without an intervening
    // reset() doesn't leak the previous handle.
    if (this->fence_event) {
        CloseHandle(this->fence_event);
    }

    this->fence_event = CreateEvent(nullptr, FALSE, FALSE, nullptr);

    return true;
}

void ResourceCopier::reset() {
    std::scoped_lock _{this->mtx};
    this->wait(2000);

    this->cmd_allocator.Reset();
    this->cmd_list.Reset();
    this->fence.Reset();
    this->fence_value = 0;
    if (this->fence_event) {
        CloseHandle(this->fence_event);
        this->fence_event = 0;
    }
    this->waiting_for_fence = false;
}

void ResourceCopier::wait(uint32_t ms) {
    std::scoped_lock _{this->mtx};

    if (this->fence_event && this->waiting_for_fence) {
        // Only reclaim the allocator/list once the GPU has actually finished
        // with them. On timeout the fence hasn't been signaled yet, so resetting
        // now would be undefined behavior (the GPU may still be executing the
        // recorded commands); keep waiting_for_fence set so the next wait retries.
        if (WaitForSingleObject(this->fence_event, ms) != WAIT_OBJECT_0) {
            spdlog::error("[d3d12] Timed out waiting for fence on {}", utility::narrow(this->internal_name));
            return;
        }

        ResetEvent(this->fence_event);
        this->waiting_for_fence = false;

        if (FAILED(this->cmd_allocator->Reset())) {
            spdlog::error("[d3d12] Failed to reset command allocator for {}", utility::narrow(this->internal_name));
        }

        if (FAILED(this->cmd_list->Reset(this->cmd_allocator.Get(), nullptr))) {
            spdlog::error("[d3d12] Failed to reset command list for {}", utility::narrow(this->internal_name));
        }

        this->has_commands = false;
    }
}

void ResourceCopier::copy(ID3D12Resource* src, ID3D12Resource* dst, D3D12_RESOURCE_STATES src_state, D3D12_RESOURCE_STATES dst_state) {
    std::scoped_lock _{this->mtx};

    if (src == nullptr || dst == nullptr) {
        spdlog::error("[d3d12] nullptr passed to ResourceCopier::copy");
        return;
    }

    // Switch src into copy source and dst into copy destination, copy, switch back.
    record_copy_barriers(this->cmd_list.Get(), src, dst,
        src_state, D3D12_RESOURCE_STATE_COPY_SOURCE,
        dst_state, D3D12_RESOURCE_STATE_COPY_DEST);

    this->cmd_list->CopyResource(dst, src);

    record_copy_barriers(this->cmd_list.Get(), src, dst,
        D3D12_RESOURCE_STATE_COPY_SOURCE, src_state,
        D3D12_RESOURCE_STATE_COPY_DEST, dst_state);

    this->has_commands = true;
}

void ResourceCopier::copy_region(ID3D12Resource* src, ID3D12Resource* dst, D3D12_BOX* src_box, D3D12_RESOURCE_STATES src_state, D3D12_RESOURCE_STATES dst_state) {
    std::scoped_lock _{this->mtx};

    if (src == nullptr || dst == nullptr) {
        spdlog::error("[d3d12] nullptr passed to ResourceCopier::copy_region");
        return;
    }

    record_copy_barriers(this->cmd_list.Get(), src, dst,
        src_state, D3D12_RESOURCE_STATE_COPY_SOURCE,
        dst_state, D3D12_RESOURCE_STATE_COPY_DEST);

    D3D12_TEXTURE_COPY_LOCATION src_loc{};
    src_loc.pResource = src;
    src_loc.Type = D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX;
    src_loc.SubresourceIndex = 0;

    D3D12_TEXTURE_COPY_LOCATION dst_loc{};
    dst_loc.pResource = dst;
    dst_loc.Type = D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX;
    dst_loc.SubresourceIndex = 0;

    this->cmd_list->CopyTextureRegion(&dst_loc, 0, 0, 0, &src_loc, src_box);

    record_copy_barriers(this->cmd_list.Get(), src, dst,
        D3D12_RESOURCE_STATE_COPY_SOURCE, src_state,
        D3D12_RESOURCE_STATE_COPY_DEST, dst_state);

    this->has_commands = true;
}

void ResourceCopier::clear_rtv(ID3D12Resource* dst, D3D12_CPU_DESCRIPTOR_HANDLE rtv, const float* color, D3D12_RESOURCE_STATES dst_state) {
    std::scoped_lock _{this->mtx};

    // No need to switch if we're already in the right state.
    const bool needs_transition = dst_state != D3D12_RESOURCE_STATE_RENDER_TARGET;

    if (needs_transition) {
        const auto barrier = make_transition(dst, dst_state, D3D12_RESOURCE_STATE_RENDER_TARGET);
        this->cmd_list->ResourceBarrier(1, &barrier);
    }

    this->cmd_list->ClearRenderTargetView(rtv, color, 0, nullptr);

    if (needs_transition) {
        const auto barrier = make_transition(dst, D3D12_RESOURCE_STATE_RENDER_TARGET, dst_state);
        this->cmd_list->ResourceBarrier(1, &barrier);
    }

    this->has_commands = true;
}

void ResourceCopier::execute() {
    std::scoped_lock _{this->mtx};

    if (this->has_commands) {
        if (FAILED(this->cmd_list->Close())) {
            spdlog::error("[d3d12] Failed to close command list. ({})", utility::narrow(this->internal_name));
            return;
        }

        auto command_queue = g_framework->get_d3d12_hook()->get_command_queue();
        ID3D12CommandList* const cmd_lists[] = {this->cmd_list.Get()};
        command_queue->ExecuteCommandLists(1, cmd_lists);
        command_queue->Signal(this->fence.Get(), ++this->fence_value);
        this->fence->SetEventOnCompletion(this->fence_value, this->fence_event);
        this->waiting_for_fence = true;
        this->has_commands = false;
    }
}
}

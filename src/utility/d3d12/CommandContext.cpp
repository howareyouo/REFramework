#include <spdlog/spdlog.h>
#include <utility/String.hpp>

#include "REFramework.hpp"

#include "TextureContext.hpp"
#include "CommandContext.hpp"

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

bool CommandContext::setup(const wchar_t* name) {
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
    this->list_open = true;
    this->warned_list_closed = false;

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

void CommandContext::reset() {
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
    this->list_open = true;
}

bool CommandContext::reopen_list() {
    const bool ok = SUCCEEDED(this->cmd_allocator->Reset()) &&
        SUCCEEDED(this->cmd_list->Reset(this->cmd_allocator.Get(), nullptr));

    if (ok) {
        this->list_open = true;
        this->warned_list_closed = false;
    }

    return ok;
}

bool CommandContext::ensure_recording() {
    if (this->cmd_list != nullptr && this->list_open) {
        return true;
    }

    if (!this->warned_list_closed) {
        spdlog::warn("[d3d12] Command list not open for recording ({}); a previous fence wait likely timed out", utility::narrow(this->internal_name));
        this->warned_list_closed = true;
    }

    return false;
}

void CommandContext::wait(uint32_t ms) {
    std::scoped_lock _{this->mtx};

    if (this->fence_event && this->waiting_for_fence) {
        // Only reclaim the allocator/list once the GPU has actually finished with
        // them: on timeout the fence isn't signaled yet, so resetting now would be
        // undefined behavior. Keeping waiting_for_fence set makes the next wait()
        // retry instead. Fast path: the fence was usually signaled long ago, so
        // query it first and skip the WaitForSingleObject syscall (this runs every
        // frame from the present thread).
        if (this->fence == nullptr || this->fence->GetCompletedValue() < this->fence_value) {
            if (WaitForSingleObject(this->fence_event, ms) != WAIT_OBJECT_0) {
                spdlog::error("[d3d12] Timed out waiting for fence on {}", utility::narrow(this->internal_name));
                return;
            }
        }

        ResetEvent(this->fence_event);
        this->waiting_for_fence = false;

        // After a device removal / GPU fault these resets fail while the fence
        // reports completion; reopening the list unconditionally there made us
        // record into a broken list and retry Close() every frame forever.
        if (!this->reopen_list()) {
            spdlog::error("[d3d12] Failed to reset command allocator/list for {}", utility::narrow(this->internal_name));
        }

        this->has_commands = false;
    } else if (!this->list_open && this->cmd_list != nullptr) {
        // Recovery branch: the list is stuck closed with no pending fence
        // (e.g. after a failed Close()). There is nothing to wait on, so without
        // this the context would stay dead forever.
        this->reopen_list();
        this->has_commands = false;
    }
}

void CommandContext::copy(ID3D12Resource* src, ID3D12Resource* dst, D3D12_RESOURCE_STATES src_state, D3D12_RESOURCE_STATES dst_state) {
    std::scoped_lock _{this->mtx};

    if (src == nullptr || dst == nullptr) {
        spdlog::error("[d3d12] nullptr passed to copy");
        return;
    }

    if (!this->ensure_recording()) {
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

void CommandContext::copy_region(ID3D12Resource* src, ID3D12Resource* dst, D3D12_BOX* src_box, D3D12_RESOURCE_STATES src_state, D3D12_RESOURCE_STATES dst_state) {
    std::scoped_lock _{this->mtx};

    if (src == nullptr || dst == nullptr) {
        spdlog::error("[d3d12] nullptr passed to copy_region");
        return;
    }

    if (!this->ensure_recording()) {
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

// Batch2: record a bare resource state transition into this context's command
// list without performing a copy. Used by TemporalUpscaler's experimental
// direct-output path to sandwich the plugin's internal EvaluateUpscaler
// submission between PRESENT->UAV and UAV->PRESENT barriers (command queue is
// FIFO, so ordering with the plugin's own ExecuteCommandLists is guaranteed).
void CommandContext::transition(ID3D12Resource* dst, D3D12_RESOURCE_STATES before_state, D3D12_RESOURCE_STATES after_state) {
    std::scoped_lock _{this->mtx};

    if (dst == nullptr || before_state == after_state) {
        return;
    }

    if (!this->ensure_recording()) {
        return;
    }

    const auto barrier = make_transition(dst, before_state, after_state);
    this->cmd_list->ResourceBarrier(1, &barrier);
    this->has_commands = true;
}

void CommandContext::clear_rtv(ID3D12Resource* dst, D3D12_CPU_DESCRIPTOR_HANDLE rtv, const float* color,D3D12_RESOURCE_STATES dst_state) {
    std::scoped_lock _{this->mtx};

    if (dst == nullptr) {
        spdlog::error("[d3d12] nullptr passed to clear_rtv");
        return;
    }

    if (!this->ensure_recording()) {
        return;
    }

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

void CommandContext::clear_rtv(d3d12::TextureContext& tex, const float* color, D3D12_RESOURCE_STATES dst_state) {
    if (tex.texture == nullptr || tex.rtv_heap == nullptr) {
        return;
    }

    this->clear_rtv(tex.texture.Get(), tex.get_rtv(), color, dst_state);
}

void CommandContext::execute() {
    std::scoped_lock _{this->mtx};

    if (this->has_commands) {
        if (FAILED(this->cmd_list->Close())) {
            // Anti-spam: log once per streak, then drop the recorded state so
            // we stop retrying Close() every frame. The next successful wait()
            // reopens the list and fresh commands get recorded.
            if (!this->warned_list_closed) {
                spdlog::error("[d3d12] Failed to close command list. ({})", utility::narrow(this->internal_name));
                this->warned_list_closed = true;
            }
            this->has_commands = false;
            this->list_open = false;
            return;
        }

        this->list_open = false;

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

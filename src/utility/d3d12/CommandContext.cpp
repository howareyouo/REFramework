#include <spdlog/spdlog.h>
#include <utility/String.hpp>

#include "REFramework.hpp"

#include "TextureContext.hpp"
#include "CommandContext.hpp"

namespace d3d12 {
bool CommandContext::setup(const wchar_t* name) {
    std::scoped_lock _{this->mtx};

    this->internal_name = name;

    auto& hook = g_framework->get_d3d12_hook();
    auto device = hook->get_device();

    this->cmd_allocator.Reset();
    this->cmd_list.Reset();
    this->fence.Reset();

    if (FAILED(device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&this->cmd_allocator)))) {
        spdlog::error("[d3d12] Failed to create command allocator for {}", utility::narrow(name));
        return false;
    }

    this->cmd_allocator->SetName(name);

    if (FAILED(device->CreateCommandList(
            0, D3D12_COMMAND_LIST_TYPE_DIRECT, this->cmd_allocator.Get(), nullptr, IID_PPV_ARGS(&this->cmd_list)))) {
        spdlog::error("[d3d12] Failed to create command list for {}", utility::narrow(name));
        return false;
    }
    
    this->cmd_list->SetName(name);
    this->list_open = true;
    this->warned_list_closed = false;

    if (FAILED(device->CreateFence(this->fence_value, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&this->fence)))) {
        spdlog::error("[d3d12] Failed to create fence for {}", utility::narrow(name));
        return false;
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
    //this->on_post_present(VR::get().get());

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

void CommandContext::wait(uint32_t ms) {
    std::scoped_lock _{this->mtx};

	if (this->fence_event && this->waiting_for_fence) {
        // Only reclaim the allocator/list once the GPU has actually finished
        // with them. On timeout the fence hasn't been signaled yet, so resetting
        // now would be undefined behavior (the GPU may still be executing the
        // recorded commands); keep waiting_for_fence set so the next wait retries.
        // Batch1 fast path: query the fence before blocking — in the common case
        // the GPU signaled long ago and we skip the WaitForSingleObject syscall
        // entirely (the present thread calls this every frame).
        if (this->fence == nullptr || this->fence->GetCompletedValue() < this->fence_value) {
            auto wait_result = WaitForSingleObject(this->fence_event, ms);

            if (wait_result != WAIT_OBJECT_0) {
                spdlog::error("[d3d12] Timed out waiting for fence on {}", utility::narrow(this->internal_name));
                return;
            }
        }

        ResetEvent(this->fence_event);
        this->waiting_for_fence = false;

        // Only mark the list open again if BOTH resets actually succeeded.
        // After a device removal / GPU fault these calls fail while the fence
        // reports completion — blindly setting list_open=true here made us
        // record into a broken list and retry Close() (spamming errors) every
        // frame forever.
        const bool allocator_reset_ok = SUCCEEDED(this->cmd_allocator->Reset());
        const bool list_reset_ok = SUCCEEDED(this->cmd_list->Reset(this->cmd_allocator.Get(), nullptr));

        if (!allocator_reset_ok || !list_reset_ok) {
            spdlog::error("[d3d12] Failed to reset command allocator/list for {}", utility::narrow(this->internal_name));
        } else {
            this->list_open = true;
            this->warned_list_closed = false;
        }

        this->has_commands = false;
    } else if (!this->list_open && this->cmd_list != nullptr) {
        // Recovery branch: the list is stuck in a closed state with no pending
        // fence (e.g. after a failed Close()). Without this, wait() would
        // never touch it again (nothing to wait on) and the context would stay
        // dead forever. Try to reopen it for future recording.
        const bool recover_ok = SUCCEEDED(this->cmd_allocator->Reset()) &&
            SUCCEEDED(this->cmd_list->Reset(this->cmd_allocator.Get(), nullptr));

        if (recover_ok) {
            this->list_open = true;
            this->warned_list_closed = false;
        }

        this->has_commands = false;
    }
}

void CommandContext::copy(ID3D12Resource* src, ID3D12Resource* dst, D3D12_RESOURCE_STATES src_state, D3D12_RESOURCE_STATES dst_state) {
    std::scoped_lock _{this->mtx};

    if (src == nullptr || dst == nullptr) {
        spdlog::error("[d3d12] nullptr passed to copy");
        return;
    }

    if (this->cmd_list == nullptr || !this->list_open) {
        if (!this->warned_list_closed) {
            spdlog::warn("[d3d12] Command list not open for recording ({}); a previous fence wait likely timed out", utility::narrow(this->internal_name));
            this->warned_list_closed = true;
        }
        return;
    }

    // Switch src into copy source.
    D3D12_RESOURCE_BARRIER src_barrier{};

    src_barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    src_barrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
    src_barrier.Transition.pResource = src;
    src_barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    src_barrier.Transition.StateBefore = src_state;
    src_barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_COPY_SOURCE;

    // Switch dst into copy destination.
    D3D12_RESOURCE_BARRIER dst_barrier{};
    dst_barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    dst_barrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
    dst_barrier.Transition.pResource = dst;
    dst_barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    dst_barrier.Transition.StateBefore = dst_state;
    dst_barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_COPY_DEST;

    {
        D3D12_RESOURCE_BARRIER barriers[2]{src_barrier, dst_barrier};
        this->cmd_list->ResourceBarrier(2, barriers);
    }

    // Copy the resource.
    this->cmd_list->CopyResource(dst, src);

    // Switch back to present.
    src_barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_COPY_SOURCE;
    src_barrier.Transition.StateAfter = src_state;
    dst_barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_COPY_DEST;
    dst_barrier.Transition.StateAfter = dst_state;

    {
        D3D12_RESOURCE_BARRIER barriers[2]{src_barrier, dst_barrier};
        this->cmd_list->ResourceBarrier(2, barriers);
    }

    this->has_commands = true;
}

void CommandContext::copy_region(ID3D12Resource* src, ID3D12Resource* dst, D3D12_BOX* src_box, D3D12_RESOURCE_STATES src_state, D3D12_RESOURCE_STATES dst_state) {
    std::scoped_lock _{this->mtx};

    if (src == nullptr || dst == nullptr) {
        spdlog::error("[d3d12] nullptr passed to copy_region");
        return;
    }

    if (this->cmd_list == nullptr || !this->list_open) {
        if (!this->warned_list_closed) {
            spdlog::warn("[d3d12] Command list not open for recording ({}); a previous fence wait likely timed out", utility::narrow(this->internal_name));
            this->warned_list_closed = true;
        }
        return;
    }

    // Switch src into copy source.
    D3D12_RESOURCE_BARRIER src_barrier{};

    src_barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    src_barrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
    src_barrier.Transition.pResource = src;
    src_barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    src_barrier.Transition.StateBefore = src_state;
    src_barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_COPY_SOURCE;

    // Switch dst into copy destination.
    D3D12_RESOURCE_BARRIER dst_barrier{};
    dst_barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    dst_barrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
    dst_barrier.Transition.pResource = dst;
    dst_barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    dst_barrier.Transition.StateBefore = dst_state;
    dst_barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_COPY_DEST;

    {
        D3D12_RESOURCE_BARRIER barriers[2]{src_barrier, dst_barrier};
        this->cmd_list->ResourceBarrier(2, barriers);
    }

    // Copy the resource.
    D3D12_TEXTURE_COPY_LOCATION src_loc{};
    src_loc.pResource = src;
    src_loc.Type = D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX;
    src_loc.SubresourceIndex = 0;

    D3D12_TEXTURE_COPY_LOCATION dst_loc{};
    dst_loc.pResource = dst;
    dst_loc.Type = D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX;
    dst_loc.SubresourceIndex = 0;

    this->cmd_list->CopyTextureRegion(&dst_loc, 0, 0, 0, &src_loc, src_box);

    // Switch back to present.
    src_barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_COPY_SOURCE;
    src_barrier.Transition.StateAfter = src_state;
    dst_barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_COPY_DEST;
    dst_barrier.Transition.StateAfter = dst_state;

    {
        D3D12_RESOURCE_BARRIER barriers[2]{src_barrier, dst_barrier};
        this->cmd_list->ResourceBarrier(2, barriers);
    }

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

    if (this->cmd_list == nullptr || !this->list_open) {
        if (!this->warned_list_closed) {
            spdlog::warn("[d3d12] Command list not open for recording ({}); a previous fence wait likely timed out", utility::narrow(this->internal_name));
            this->warned_list_closed = true;
        }
        return;
    }

    D3D12_RESOURCE_BARRIER barrier{};
    barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    barrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
    barrier.Transition.pResource = dst;
    barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    barrier.Transition.StateBefore = before_state;
    barrier.Transition.StateAfter = after_state;

    this->cmd_list->ResourceBarrier(1, &barrier);
    this->has_commands = true;
}

void CommandContext::clear_rtv(ID3D12Resource* dst, D3D12_CPU_DESCRIPTOR_HANDLE rtv, const float* color,D3D12_RESOURCE_STATES dst_state) {
    std::scoped_lock _{this->mtx};

    if (dst == nullptr) {
        spdlog::error("[d3d12] nullptr passed to clear_rtv");
        return;
    }

    if (this->cmd_list == nullptr || !this->list_open) {
        if (!this->warned_list_closed) {
            spdlog::warn("[d3d12] Command list not open for recording ({}); a previous fence wait likely timed out", utility::narrow(this->internal_name));
            this->warned_list_closed = true;
        }
        return;
    }

    // Switch dst into copy destination.
    D3D12_RESOURCE_BARRIER dst_barrier{};
    dst_barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    dst_barrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
    dst_barrier.Transition.pResource = dst;
    dst_barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    dst_barrier.Transition.StateBefore = dst_state;
    dst_barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_RENDER_TARGET;

    // No need to switch if we're already in the right state.
    if (dst_state != dst_barrier.Transition.StateAfter) {
        D3D12_RESOURCE_BARRIER barriers[1]{dst_barrier};
        this->cmd_list->ResourceBarrier(1, barriers);
    }

    // Clear the resource.
    this->cmd_list->ClearRenderTargetView(rtv, color, 0, nullptr);

    // Switch back to present.
    dst_barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
    dst_barrier.Transition.StateAfter = dst_state;

    if (dst_state != dst_barrier.Transition.StateBefore) {
        D3D12_RESOURCE_BARRIER barriers[1]{dst_barrier};
        this->cmd_list->ResourceBarrier(1, barriers);
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
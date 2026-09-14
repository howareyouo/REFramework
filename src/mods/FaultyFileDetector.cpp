#include "FaultyFileDetector.hpp"

#include <algorithm>
#include <array>
#include <format>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>
#include <utility/Module.hpp>
#include <utility/Scan.hpp>
#include <utility/String.hpp>

#include <safetyhook/mid_hook.hpp>

#include "REFramework.hpp"

namespace {

// TODO: the offsets unlikely to change, but if they do this breaks.
#pragma pack(push, 1)
struct REResourceViaRaw {
    void* vtable;
    wchar_t* path;
    std::uint8_t unk10[0x28];
    bool isInitialized; // 0x38; shader/texture resources don't use it, don't rely on it
};
#pragma pack(pop)

// The resource currently being parsed on this thread. Equivalent to the old
// per-thread map, but lock-free: set_argument and parse_finish always fire on
// the thread that called the hooked parse function.
thread_local REResourceViaRaw* t_resource_in_parse = nullptr;

// Display/log metadata indexed by FaultyReason; shared by logging and the UI.
struct ReasonInfo {
    std::string_view log_name;
    std::string_view ui_label;
    ImVec4 color;
};

const std::array<ReasonInfo, 4> kReasonInfo{{
    {"Unknown reason", "Unknown", ImVec4(0.8f, 0.8f, 0.8f, 1.0f)},
    {"Missing file", "Missing File", ImVec4(1.0f, 1.0f, 0.0f, 1.0f)},
    {"Invalid file", "Invalid File", ImVec4(1.0f, 0.5f, 0.0f, 1.0f)},
    {"PAK should be encrypted", "Should Be Encrypted", ImVec4(1.0f, 0.0f, 0.0f, 1.0f)},
}};

template <typename T>
T* get_register_value(safetyhook::Context& ctx, uint8_t reg) {
    #define REF_REG_CASE(upper, lower) case NDR_##upper: return reinterpret_cast<T*>(ctx.lower)
    switch (reg) {
        REF_REG_CASE(RAX, rax); REF_REG_CASE(RBX, rbx); REF_REG_CASE(RCX, rcx); REF_REG_CASE(RDX, rdx);
        REF_REG_CASE(RSI, rsi); REF_REG_CASE(RDI, rdi); REF_REG_CASE(RBP, rbp); REF_REG_CASE(RSP, rsp);
        REF_REG_CASE(R8, r8);  REF_REG_CASE(R9, r9);   REF_REG_CASE(R10, r10); REF_REG_CASE(R11, r11);
        REF_REG_CASE(R12, r12); REF_REG_CASE(R13, r13); REF_REG_CASE(R14, r14); REF_REG_CASE(R15, r15);
        default: return nullptr;
    }
    #undef REF_REG_CASE
}

// Scan a short instruction window for `mov rcx, reg`; returns the address
// right after it, where the resource argument is known to be in RCX.
uint8_t* find_resource_argument_assign(uint8_t* start, uint8_t* end) {
    static const int max_instructions = 10;

    for (int i = 0; i < max_instructions && start < end; ++i) {
        auto instr = utility::decode_one(start);
        if (instr && instr->Instruction == ND_INS_MOV && instr->OperandsCount >= 2 &&
            instr->Operands[0].Type == ND_OP_REG && instr->Operands[0].Info.Register.Reg == NDR_RCX &&
            instr->Operands[1].Type == ND_OP_REG) {
            auto assigned = start + instr->Length;
            spdlog::info("[FaultyFileDetector]: Found resource argument assign at 0x{:x}, hooking to extract it at: 0x{:x}", (uintptr_t)start, (uintptr_t)assigned);
            return assigned;
        }
        start += instr ? instr->Length : 1;
    }

    return nullptr;
}

} // namespace

std::shared_ptr<FaultyFileDetector>& FaultyFileDetector::get() {
    static auto instance = std::shared_ptr<FaultyFileDetector>(new FaultyFileDetector());
    return instance;
}

FaultyFileDetector::FaultyFileDetector() {
    m_logger = spdlog::basic_logger_mt("FaultyFileDetector", REFramework::get_persistent_dir("reframework_faulty_files.txt").string(), true);
    m_logger->set_level(spdlog::level::info);
    m_logger->flush_on(spdlog::level::info);
    m_logger->set_pattern("\"%l\" %v");
}

void FaultyFileDetector::fail(std::string_view message) {
    m_blocking_error = message;
    spdlog::error("[FaultyFileDetector] {}", *m_blocking_error);
}

std::optional<std::string> FaultyFileDetector::on_initialize() {
    initialize_impl();
    return Mod::on_initialize();
}

void FaultyFileDetector::initialize_impl() {
    if (m_initialized) {
        return;
    }

    m_initialized = true;

    auto create_resource_func = sdk::ResourceManager::get_create_resource_function();
    if (create_resource_func == nullptr) {
        fail("Can't find load resource function!");
        return;
    }

    m_create_resource_original = safetyhook::create_inline(
        reinterpret_cast<uint8_t*>(create_resource_func),
        reinterpret_cast<uint8_t*>(&FaultyFileDetector::create_resource_hook_wrapper)
    );

    if (!m_create_resource_original) {
        fail("Failed to hook load resource function!");
        return;
    }

    if (!scan_resource_process_parse_and_hook()) {
        return;
    }

    spdlog::info("[FaultyFileDetector]: Initialized successfully");
}

std::optional<uintptr_t> FaultyFileDetector::install_parse_finish_hooks(std::uint8_t* anchor) {
    // The displacement reference points one byte past the CALL instruction (past its disp32).
    auto call_ptr = anchor - 1;
    auto call = utility::decode_one(call_ptr);

    if (!call || call->Instruction != ND_INS_CALLNR || call->OperandsCount < 1 || call->Operands[0].Type != ND_OP_OFFS) {
        spdlog::warn("[FaultyFileDetector]: Failed to decode probable call instruction at 0x{:X}", (uintptr_t)call_ptr);
        return std::nullopt;
    }

    // Look for three consecutive vtable calls after the constructor call:
    // call qword ptr [rax + 20h/48h/38h]. The second call is the one whose
    // result we want to check, so we hook right after it.
    static const std::array<int, 3> parse_call_offsets{ 0x20, 0x48, 0x38 };
    static const int max_instructions_search_range = 60;

    uint8_t* parse_call_ptr = nullptr;
    uint8_t* parse_call_return_address = nullptr;
    uint8_t* start_searching_resource_access_ptr = nullptr;

    auto ip = call_ptr + call->Length;
    int stage = 0;

    for (int i = 0; i < max_instructions_search_range; ++i) {
        auto instr = utility::decode_one(ip);
        if (!instr) {
            break;
        }

        if (instr->Instruction == ND_INS_CALLNI && instr->OperandsCount >= 1 && instr->Operands[0].Type == ND_OP_MEM) {
            auto mem = instr->Operands[0].Info.Memory;
            if (mem.Base == NDR_RAX && mem.Disp == parse_call_offsets[stage]) {
                if (stage == 0) {
                    start_searching_resource_access_ptr = ip + instr->Length;
                } else if (stage == 1) {
                    parse_call_ptr = ip;
                    parse_call_return_address = ip + instr->Length;
                } else {
                    stage = 3;
                    break;
                }
                ++stage;
            }
        }

        ip += instr->Length;
    }

    if (stage != 3) {
        spdlog::warn("[FaultyFileDetector]: Failed to find three consecutive vtable calls after unk constructor call at 0x{:X}", (uintptr_t)anchor);
        return std::nullopt;
    }

    if (parse_call_ptr == nullptr || parse_call_return_address == nullptr || start_searching_resource_access_ptr == nullptr) {
        spdlog::error("[FaultyFileDetector]: parse_call_ptr is null even though we found all three calls, this should not happen");
        return std::nullopt;
    }

    // Very fragile way, but it works for now
    auto resource_argument_assigned_ptr = find_resource_argument_assign(start_searching_resource_access_ptr, parse_call_ptr);
    if (resource_argument_assigned_ptr == nullptr) {
        spdlog::warn("[FaultyFileDetector]: Failed to find resource argument assign from 0x{:X}", (uintptr_t)parse_call_ptr);
        return std::nullopt;
    }

    spdlog::info("[FaultyFileDetector]: All checks passed, hooking resource parse finish function at 0x{:X}", (uintptr_t)parse_call_return_address);

    // Hook after the parse finishes and at the argument assignment.
    m_resource_parse_finish_hooks.push_back(
        safetyhook::create_mid(parse_call_return_address, &dispatch<&FaultyFileDetector::resource_parse_finish_hook>));
    m_resource_set_argument_hooks.push_back(
        safetyhook::create_mid(resource_argument_assigned_ptr, &dispatch<&FaultyFileDetector::resource_set_argument_hook>));

    return utility::find_function_start((uintptr_t)parse_call_return_address);
}

bool FaultyFileDetector::scan_resource_process_parse_and_hook() {
    // Future note: related function has a text: ResourceManager::parallelProc, seems like logger or profile marker or something
    static const char* resource_manager_unk_constructor_pattern = "41 56 56 57 53 48 83 EC 28 44 89 C7 48 89 D3 48 89 CE 44 89 41 08 48 C7 41 48 00 00 00 00 48 8D 05 ? ? ? ? 48 89 01 48 8D 51 50 48 8D 05 ? ? ? ? 48 89 41 50 4C 8D 71 58 4C 89 F1";

    auto game = utility::get_executable();
    auto resource_manager_unk_constructor_ptr = utility::scan(game, resource_manager_unk_constructor_pattern);

    if (!resource_manager_unk_constructor_ptr) {
        fail("Failed to hook parse resource function (anchor to search not found)!");
        return false;
    }

    auto unk_constructor_refs = utility::scan_displacement_references(game, resource_manager_unk_constructor_ptr.value());
    if (unk_constructor_refs.empty()) {
        fail("Failed to hook parse resource function (no references to constructor found)!");
        return false;
    }

    std::unordered_set<uintptr_t> process_func_candidates;

    for (auto anchor : unk_constructor_refs) {
        auto fn = install_parse_finish_hooks(reinterpret_cast<std::uint8_t*>(anchor));
        if (fn.has_value() && !process_func_candidates.contains(fn.value())) {
            process_func_candidates.insert(fn.value());
        }
    }

    // Search for the function that gets the next resource to process.
    // That function also checks for the validity of the resource stream.
    const wchar_t* resource_path_format = L"%ls/%ls/%ls.%d";

    auto str_offset = utility::scan_string(game, resource_path_format, true);
    if (str_offset.has_value()) {
        for (auto candidate_fn_addr : process_func_candidates) {
            auto possible_get_next_resource_to_process_call = utility::find_encapsulating_function_disp(candidate_fn_addr, str_offset.value());
            if (!possible_get_next_resource_to_process_call.has_value()) {
                continue;
            }

            // TODO: For now only one exists, but if multiple exists we should hook them all, just need to figure out how to differentiate them
            spdlog::info("[FaultyFileDetector]: Found possible get next resource to process function at 0x{:X}", possible_get_next_resource_to_process_call.value());

            // Follow the failure function
            const int scan_resource_path_usage_length = 1024;
            auto using_resource_path_offset = utility::scan_displacement_reference(possible_get_next_resource_to_process_call.value(), scan_resource_path_usage_length, str_offset.value());

            if (!using_resource_path_offset.has_value()) {
                continue;
            }

            // Skip the displacement value
            auto next_instr = using_resource_path_offset.value() + 4;

            const int scan_resource_stream_failed_length = 2048;
            utility::exhaustive_decode(
                (uint8_t*)next_instr,
                scan_resource_stream_failed_length,
                [this](utility::ExhaustionContext& ctx) -> utility::ExhaustionResult {
                    // Calls can leave the failure path; don't follow them.
                    if (ctx.instrux.Instruction == ND_INS_CALLNI || ctx.instrux.Instruction == ND_INS_CALLNR ||
                        ctx.instrux.Instruction == ND_INS_CALLFD || ctx.instrux.Instruction == ND_INS_CALLFI) {
                        return utility::ExhaustionResult::STEP_OVER;
                    }

                    // The stream-open failure mark: `mov dword ptr [reg + 3C], FFFFFFFF`
                    if (ctx.instrux.Instruction == ND_INS_MOV && ctx.instrux.OperandsCount >= 2 &&
                        ctx.instrux.Operands[0].Type == ND_OP_MEM && ctx.instrux.Operands[0].Info.Memory.Disp == 0x3C &&
                        ctx.instrux.Operands[1].Type == ND_OP_IMM && ((ctx.instrux.Operands[1].Info.Immediate.Imm & 0xFFFFFFFF) == 0xFFFFFFFF)) {
                        m_resource_open_failed_addr = (std::uint8_t*)ctx.addr;
                        m_resource_open_failed_register = ctx.instrux.Operands[0].Info.Memory.Base;
                        return utility::ExhaustionResult::BREAK;
                    }

                    return utility::ExhaustionResult::CONTINUE;
                });

            if (m_resource_open_failed_addr) {
                spdlog::info("[FaultyFileDetector]: Found resource stream failed check at 0x{:X}, hooking to detect failed resource stream", (uintptr_t)m_resource_open_failed_addr);

                m_resource_open_failed_hook = safetyhook::create_mid(m_resource_open_failed_addr, &dispatch<&FaultyFileDetector::resource_parse_open_stream_failed_hook>);
                break;
            }

            spdlog::warn("[FaultyFileDetector]: Failed to find resource stream failed check after using resource path at 0x{:X}", (uintptr_t)using_resource_path_offset.value());
        }
    }

    if (m_resource_parse_finish_hooks.empty()) {
        fail("Failed to hook parse resource function (no valid parse function hooks created)!");
        return false;
    }

    return true;
}

void FaultyFileDetector::on_config_load(const utility::Config& cfg) {
    config_load_options(cfg, m_options);
}

void FaultyFileDetector::on_config_save(utility::Config& cfg) {
    config_save_options(cfg, m_options);
}

sdk::Resource* FaultyFileDetector::create_resource_hook_wrapper(sdk::ResourceManager* resource_manager, void* type_info, wchar_t* name) {
    if (auto* self = get().get(); self != nullptr) {
        return self->create_resource_hook(resource_manager, type_info, name);
    }
    return nullptr;
}

sdk::Resource* FaultyFileDetector::create_resource_hook(sdk::ResourceManager* resource_manager, void* type_info, wchar_t* name) {
    //spdlog::warn("[FaultyFileDetector]: create_resource_hook called with name: {}", utility::narrow(name ? name : L"(null)"));
    auto original_result = m_create_resource_original.call<sdk::Resource*>(resource_manager, type_info, name);
    if (!m_enabled->value()) {
        return original_result;
    }
    if (original_result == nullptr && name != nullptr) {
        try_add_to_faulty_list(name, FaultyTier::Severe, FaultyReason::MissingFile);
    }
    return original_result;
}

void FaultyFileDetector::resource_parse_open_stream_failed_hook(safetyhook::Context& ctx) {
    if (!m_enabled->value()) {
        return;
    }

    auto resource = get_register_value<REResourceViaRaw>(ctx, m_resource_open_failed_register);
    if (resource != nullptr && resource->path != nullptr) {
        try_add_to_faulty_list(resource->path, FaultyTier::Severe, FaultyReason::MissingFile);
    }
}

void FaultyFileDetector::resource_set_argument_hook(safetyhook::Context& ctx) {
    if (!m_enabled->value()) {
        return;
    }

    // No lock needed: parse_finish for this resource runs on the same thread.
    t_resource_in_parse = reinterpret_cast<REResourceViaRaw*>(ctx.rcx);
}

void FaultyFileDetector::resource_parse_finish_hook(safetyhook::Context& ctx) {
    if (!m_enabled->value()) {
        return;
    }

    // Check parse result
    if ((ctx.rax & 0x1) != 0) { // rax bit 0 = parse result (0 = fail, 1 = success)
        return;
    }

    auto resource = t_resource_in_parse;
    if (resource != nullptr && resource->path != nullptr) {
        try_add_to_faulty_list(resource->path, FaultyTier::Severe, FaultyReason::Invalid);
    }
}

void FaultyFileDetector::try_add_to_faulty_list(std::wstring_view filename, FaultyTier tier, FaultyReason reason) {
    if (filename.empty()) {
        return;
    }

    bool should_log = false;

    {
        std::scoped_lock lock{m_mutex};

        // Only allocate and insert if this is a genuinely new file
        // (most calls are duplicates of already-recorded failures). The
        // transparent hash lets this find run on the wstring_view directly.
        if (m_faulty_files.find(filename) == m_faulty_files.end()) {
            auto name_wstr = std::wstring{filename};
            m_faulty_files.insert(name_wstr);

            // Add to recent files for this reason
            auto& reason_deque = m_recent_faulty_files_by_reason[reason];
            reason_deque.push_front(std::move(name_wstr));

            // Trim recent files to max size for this reason. Clamp to 0 so a
            // negative configured value can't wrap to a huge size_t and defeat
            // the trim (leaving the deque to grow unbounded).
            const size_t max_recent = (size_t)std::max(0, m_max_recent_files->value());
            while (reason_deque.size() > max_recent) {
                reason_deque.pop_back();
            }

            should_log = true;
        }
    }

    if (should_log && m_logger) {
        static const spdlog::level::level_enum tier_levels[] = {
            spdlog::level::info,
            spdlog::level::warn,
            spdlog::level::err,
        };

        const auto& reason_info = kReasonInfo[std::clamp((int)reason, (int)FaultyReason::Unknown, (int)FaultyReason::ShouldBeEncrypted)];
        m_logger->log(tier_levels[std::clamp((int)tier, (int)FaultyTier::None, (int)FaultyTier::Severe)],
                      "{} \"{}\" \"{}\"", (int)reason, reason_info.log_name, utility::narrow(filename));
    }
}

void FaultyFileDetector::on_draw_ui() {
    ImGui::SetNextItemOpen(false, ImGuiCond_::ImGuiCond_FirstUseEver);

    if (!ImGui::CollapsingHeader(get_name().data())) {
        return;
    }

    if (m_blocking_error.has_value()) {
        ImGui::TextWrapped("Error: %s", m_blocking_error->c_str());
        return;
    }

    std::scoped_lock lock{m_mutex};

    // Display statistics
    ImGui::TextWrapped("Total faulty files encountered: %zu", m_faulty_files.size());

    if (m_faulty_files.empty()) {
        ImGui::TextWrapped("No faulty files detected!");
        return;
    }

    ImGui::TextWrapped("Faulty files detected!");
    ImGui::TextWrapped("See reframework_faulty_files.txt for full list and details. Use external tool to find out what mod/patch is causing the issue.");

    bool changed = false;

    changed |= m_enabled->draw("Enable Faulty File Detector");
    changed |= m_max_recent_files->draw("Max Recent Files to Display");

    if (ImGui::TreeNode("Show recent##ShowRecentFaultyFiles")) {
        // Display files organized by reason
        for (size_t reason = 0; reason < kReasonInfo.size(); ++reason) {
            auto it = m_recent_faulty_files_by_reason.find((FaultyReason)reason);
            if (it == m_recent_faulty_files_by_reason.end() || it->second.empty()) {
                continue; // Skip if no files for this reason
            }

            const auto& files = it->second;
            const int count_to_display = std::min((int)files.size(), m_max_recent_files->value());
            const auto& info = kReasonInfo[reason];

            ImGui::PushStyleColor(ImGuiCol_Text, info.color);

            if (ImGui::TreeNode(std::format("{} ({})", info.ui_label, files.size()).c_str())) {
                for (int i = 0; i < count_to_display; ++i) {
                    ImGui::TextWrapped("%s", utility::narrow(files[i]).c_str());
                }

                if (files.size() > (size_t)count_to_display) {
                    ImGui::TextWrapped("... and %zu more", files.size() - count_to_display);
                }

                ImGui::TreePop();
            }

            ImGui::PopStyleColor();
        }

        ImGui::TreePop();
    }

    if (changed) {
        g_framework->request_save_config();
    }
}
// ScanSelf.hpp - self-contained x64 instruction-length decoder and code walker.
//
// Shipped decode kernel: bdshim (shared/utility/bdshim) serves the bddisasm
// API slice that kananlib and src/ link against on top of rfw::scan::decode()
// here, and the bddisasm target in CMakeLists.txt is built from this file plus
// the shim instead of fetching bddisasm. Swapping kananlib's own Scan.hpp
// entry points for the rfw::scan primitives below is a remaining phase; see
// docs/SELFMADE_SCANNER.md for the migration state.
//
// This is NOT a disassembler: it decodes lengths, branch kinds and the
// RIP-relative displacement, and rejects encodings it does not know. Every
// primitive here mirrors the kananlib routine it replaces, including the
// quirks of its walker (see the comments in ScanSelf.cpp).
//
// Validated against bddisasm over the whole RE4 .text section by
// tools/scan_diff: 25.4M instructions inside .pdata function bodies, 33 length
// disagreements (0.00013%), all of them in jump tables embedded in code.
//
// No REFramework/imgui dependency on purpose: only <windows.h> and the
// standard library, so tools/scan_diff can compile it offline.
#pragma once

#include <windows.h>

#include <cstdint>
#include <functional>
#include <optional>
#include <span>
#include <string_view>

namespace rfw::scan {

// Control-flow class of one instruction, as far as the walker cares.
enum class Kind : uint8_t {
    Other,
    Call,    // e8 rel32                       - direct call
    Jmp,     // e9 rel32, eb rel8              - direct unconditional jump
    Jcc,     // 7x rel8, 0f 8x rel32, e0-e3    - conditional branch
    Ret,     // c3, c2 imm16                   - retn (kananlib stops here)
    Int3,    // cc
    IndCall, // ff /2, ff /3                   - call through memory/register
    IndJmp,  // ff /4, ff /5                   - jmp through memory/register
};

struct Insn {
    uint8_t len{};          // total instruction length, 1..15
    Kind kind{Kind::Other};
    bool rip_operand{};     // has a RIP-relative memory operand (not a 67-prefixed absolute)
    int32_t disp{};         // that operand's displacement (valid when rip_operand)
    uintptr_t target{};     // rip_operand: ip + len + disp. relative branch: ip + len + rel

    // The rest exists for the bddisasm compatibility layer in
    // shared/utility/bdshim, which has to fill in a full INSTRUX. The walker
    // above reads none of it, so filling it cannot change how a scan behaves.
    uint8_t opcode{};       // main opcode byte, after any escape
    uint8_t map{};          // 0 legacy, 1 = 0F, 2 = 0F38, 3 = 0F3A
    uint8_t modrm{};
    uint8_t modrm_reg{};
    uint8_t modrm_mod{};
    bool has_modrm{};
    bool has_sib{};
    uint8_t sib{};
    uint8_t scale{};        // 1, 2, 4, 8 (valid when has_index)
    bool has_base{};
    uint8_t base{};         // GPR number, 0 = rax
    bool has_index{};
    uint8_t index{};        // GPR number, 0 = rax
    uint8_t disp_size{};    // 0, 1, 2 or 4
    bool has_imm{};
    uint8_t imm_size{};
    uint64_t imm{};         // raw (zero-extended) immediate
    bool rel8{};            // the relative offset is 1 byte wide
    bool vex{};             // VEX2/VEX3/EVEX encoded
    bool opsize{};          // 0x66 present
    bool addrsize{};        // 0x67 present
    bool lock{};            // 0xF0 present
    bool rep{};             // 0xF2/0xF3 present
    uint8_t rex{};          // the REX byte, 0 when absent (0x40 with all bits clear is still a REX)
    bool has_rex{};
};

// Decodes one instruction at `ip`. Returns false for encodings this decoder
// does not cover (invalid in 64-bit mode, longer than 15 bytes, unknown map),
// which is the walker's signal to stop - bddisasm did the same via ND_SUCCESS.
bool decode(const uint8_t* ip, Insn& out);

// True when [p, p+n) is committed and readable. Stands in for kananlib's
// SEH/IsBadReadPtr probes; VirtualQuery keeps it out of kernel32.
bool readable(const void* p, size_t n);

enum class WalkAction : uint8_t {
    Continue,
    Break,    // stop the whole walk, return to the caller
    StepOver, // do not follow this branch target, keep decoding
};

struct WalkCtx {
    uintptr_t addr{};         // instruction address
    uintptr_t branch_start{}; // first instruction of the current segment
    const Insn* insn{};
};

// Restricts every walk started while the guard is alive to [lo, hi): a path
// that reaches outside the window simply ends, so an import thunk resolved to
// kernel32 code cannot consume the instruction budget. Nested guards restore the
// previous window, and the window is thread-local, so primitives invoked from
// inside a walk inherit it. hi <= lo disables the limit.
class RegionGuard {
public:
    RegionGuard(uintptr_t lo, uintptr_t hi);
    ~RegionGuard();

    RegionGuard(const RegionGuard&) = delete;
    RegionGuard& operator=(const RegionGuard&) = delete;

private:
    uintptr_t prev_lo_;
    uintptr_t prev_hi_;
};

// Decodes `start` and everything reachable from it: direct jumps are followed
// in place, conditional jumps / calls / call thunks are queued, RET and INT3
// end a path. `max_insns` is the per-path budget.
void walk(uintptr_t start, size_t max_insns, const std::function<WalkAction(const WalkCtx&)>& cb);

// "? ? 6B CA EB 85" style mask: two hex digits per byte, "?" / "??" for any.
struct BytePattern {
    uint8_t bytes[32]{};
    uint8_t mask[32]{};
    size_t len{};

    static std::optional<BytePattern> parse(std::string_view text);
    bool matches(const uint8_t* at) const;
};

struct Hit {
    uintptr_t addr{};   // address of the instruction that matched
    uintptr_t target{}; // RIP-relative operand target (0 for pattern hits)
    uint8_t len{};      // length of that instruction
};

// kananlib::find_string_reference_in_path: first instruction on the walk whose
// RIP-relative operand points at exactly `needle` (UCS-2, NUL terminated).
std::optional<Hit> find_string_ref(uintptr_t start, std::wstring_view needle, bool follow_calls,
                                   size_t max_insns = 200);

// kananlib::find_pattern_in_path: first instruction start on the walk that
// matches `pattern` (the pattern must start on the instruction boundary).
std::optional<Hit> find_pattern_in_path(uintptr_t start, size_t max_insns, bool follow_calls,
                                        const BytePattern& pattern);

// Start of the function containing `addr`, resolved through the image's .pdata
// (chained entries are unwound to the primary function). `image_base` is the
// module base - also the flat-image base in tools/scan_probe.
std::optional<uintptr_t> find_function_start(uintptr_t image_base, uintptr_t addr);

// True when `addr` is exactly the begin of a .pdata entry that is not a chained
// fragment. The detour installer refuses anything else: hooking a function's
// cold part or an internal label overwrites mid-body code and crashes the game
// the first time the real entry runs.
bool is_function_begin(uintptr_t image_base, uintptr_t addr);

} // namespace rfw::scan

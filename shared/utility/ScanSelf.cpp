// ScanSelf.cpp - see ScanSelf.hpp for the why.
//
// Layout of this file:
//   1. opcode attribute tables (ModRM / immediate shape / branch class)
//   2. decode()  - instruction length + branch kind + RIP-relative target
//   3. readable()
//   4. walk()    - kananlib::exhaustive_decode, behaviour for behaviour
//   5. the four primitives built on top
#include "ScanSelf.hpp"

#include <array>
#include <cstddef>
#include <cstring>
#include <memory>
#include <string>
#include <unordered_set>
#include <vector>

namespace rfw::scan {
namespace {

// ---------------------------------------------------------------------------
// 1. Opcode attributes
// ---------------------------------------------------------------------------

// Immediate operand shape. Group3* depend on the ModRM reg field, Enter is
// enter's iw+ib, MovImm is the r64/r32 case that grows to 8 bytes with REX.W.
enum class ImmKind : uint8_t {
    None,
    B,      // imm8
    W,      // imm16
    Z,      // imm16/imm32 by 66; imm32 stays imm32 under REX.W
    MovImm, // 66 ? 2 : (REX.W ? 8 : 4)
    Moffs,  // 67 ? 4 : 8
    Enter,  // iw + ib
    Group3B,
    Group3Z,
    Rel8,
    Rel32,
};

struct OpInfo {
    bool modrm{};
    bool valid{true};
    ImmKind imm{ImmKind::None};
    Kind kind{Kind::Other};
};

// One-byte opcode map (64-bit mode: no aaa/aas/daa/das/popa/pusha/into/salc/
// les/lds/bound/far imm jumps, and 0x40-0x4f / 0x26 / 0x2e / 0x36 / 0x3e /
// 0x64 / 0x65 / 0x66 / 0x67 / 0xf0 / 0xf2 / 0xf3 never reach here).
OpInfo legacy_attrs(uint8_t op) {
    OpInfo o{};

    // 0x00-0x3f: add/or/adc/sbb/and/sub/xor/cmp, each as
    // [Eb,Gb] [Ev,Gv] [Gb,Eb] [Gv,Ev] AL,imm8 eAX,immZ and two invalid slots.
    if (op < 0x40) {
        switch (op & 7) {
        case 0: case 1: case 2: case 3: o.modrm = true; break;
        case 4: o.imm = ImmKind::B; break;
        case 5: o.imm = ImmKind::Z; break;
        default: o.valid = false; break;
        }
        return o;
    }

    if (op < 0x50) { o.valid = false; return o; } // stray REX
    if (op < 0x60) { return o; }                   // push/pop r64

    switch (op) {
    case 0x60: case 0x61: o.valid = false; return o; // pusha/popa
    case 0x63: o.modrm = true; return o;             // movsxd
    case 0x68: o.imm = ImmKind::Z; return o;         // push imm
    case 0x69: o.modrm = true; o.imm = ImmKind::Z; return o;
    case 0x6a: o.imm = ImmKind::B; return o;
    case 0x6b: o.modrm = true; o.imm = ImmKind::B; return o;
    default: break;
    }
    if (op < 0x70) { return o; } // ins/outs

    if (op < 0x80) { o.imm = ImmKind::Rel8; o.kind = Kind::Jcc; return o; } // jcc rel8

    switch (op) {
    case 0x80: o.modrm = true; o.imm = ImmKind::B; return o;
    case 0x81: o.modrm = true; o.imm = ImmKind::Z; return o;
    case 0x82: o.valid = false; return o; // invalid in 64-bit
    case 0x83: o.modrm = true; o.imm = ImmKind::B; return o;
    case 0x9a: o.valid = false; return o; // call far ptr
    default: break;
    }
    if (op < 0x90) { o.modrm = true; return o; } // test/xchg/mov/lea/pop
    if (op < 0xa0) { return o; }                 // xchg eAX / nop / cdqe / cwde / wait / pushf

    if (op < 0xa4) { o.imm = ImmKind::Moffs; return o; } // mov al/eAX <-> moffs
    if (op < 0xa8) { return o; }                         // movs/cmps
    switch (op) {
    case 0xa8: o.imm = ImmKind::B; return o;
    case 0xa9: o.imm = ImmKind::Z; return o;
    default: break;
    }
    if (op < 0xb0) { return o; }                            // stos/lods/scas
    if (op < 0xb8) { o.imm = ImmKind::B; return o; }         // mov r8, imm8
    if (op < 0xc0) { o.imm = ImmKind::MovImm; return o; }    // mov r32/r64, imm

    switch (op) {
    case 0xc0: case 0xc1: o.modrm = true; o.imm = ImmKind::B; return o;
    case 0xc2: o.imm = ImmKind::W; o.kind = Kind::Ret; return o;
    case 0xc3: o.kind = Kind::Ret; return o;
    case 0xc6: o.modrm = true; o.imm = ImmKind::B; return o;
    case 0xc7: o.modrm = true; o.imm = ImmKind::Z; return o;
    case 0xc8: o.imm = ImmKind::Enter; return o;
    case 0xc9: return o;                                  // leave
    case 0xca: o.imm = ImmKind::W; return o;               // retf imm16 (not RETN)
    case 0xcb: return o;                                  // retf
    case 0xcc: o.kind = Kind::Int3; return o;
    case 0xcd: o.imm = ImmKind::B; return o;
    case 0xce: o.valid = false; return o;
    default: break;
    }
    if (op < 0xd4) { o.modrm = true; return o; } // rol/rcr over r/m
    switch (op) {
    case 0xd4: case 0xd5: case 0xd6: o.valid = false; return o; // aam/aad/salc
    case 0xd7: return o;                                        // xlat
    default: break;
    }
    if (op < 0xe0) { o.modrm = true; return o; }             // x87
    if (op < 0xe4) { o.imm = ImmKind::Rel8; o.kind = Kind::Jcc; return o; } // loop/jrcxz
    if (op < 0xe8) { o.imm = ImmKind::B; return o; }         // in/out imm8
    switch (op) {
    case 0xe8: o.imm = ImmKind::Rel32; o.kind = Kind::Call; return o;
    case 0xe9: o.imm = ImmKind::Rel32; o.kind = Kind::Jmp; return o;
    case 0xea: o.valid = false; return o; // jmp far ptr
    case 0xeb: o.imm = ImmKind::Rel8; o.kind = Kind::Jmp; return o;
    default: break;
    }
    if (op < 0xf0) { return o; } // in/out dx

    switch (op) {
    case 0xf1: case 0xf4: case 0xf5: case 0xf8: case 0xf9:
    case 0xfa: case 0xfb: case 0xfc: case 0xfd: return o;
    case 0xf6: o.modrm = true; o.imm = ImmKind::Group3B; return o;
    case 0xf7: o.modrm = true; o.imm = ImmKind::Group3Z; return o;
    case 0xfe: o.modrm = true; return o;
    case 0xff: o.modrm = true; return o;
    default: break;
    }

    o.valid = false; // 0xf0/0xf2/0xf3 are prefixes and never reach here
    return o;
}

// Two-byte (0F) opcode map. Defaults to "ModRM, no immediate"; the exceptions
// are the ModRM-less instructions, the jcc rel32 block and the ones that carry
// an imm8. 0x0f (3DNow!) takes ModRM + imm8.
OpInfo map0f_attrs(uint8_t op) {
    OpInfo o{};

    switch (op) {
    case 0x05: case 0x06: case 0x07: case 0x08: case 0x09: case 0x0b: case 0x0e:
    case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x37:
    case 0x77:
    case 0xa0: case 0xa1: case 0xa2: case 0xa8: case 0xa9: case 0xaa:
        return o; // syscall/clts/.../emms/vzeroupper/cpuid/rsm: no ModRM
    case 0x0f: case 0x70: case 0x71: case 0x72: case 0x73:
    case 0xa4: case 0xac: case 0xba:
    case 0xc2: case 0xc4: case 0xc5: case 0xc6:
        o.modrm = true;
        o.imm = ImmKind::B;
        return o;
    default: break;
    }

    if (op >= 0x80 && op <= 0x8f) { o.imm = ImmKind::Rel32; o.kind = Kind::Jcc; return o; }
    if (op >= 0xc8 && op <= 0xcf) { return o; } // bswap

    o.modrm = true;
    return o;
}

// UNWIND_INFO is not declared by every toolchain's winnt.h, and only the first
// four bytes matter here.
struct UnwindInfo {
    uint8_t version_and_flags;
    uint8_t size_of_prolog;
    uint8_t count_of_codes;
    uint8_t frame_register;
};

constexpr uint8_t kUnwindFlagChainInfo = 0x04;

using RuntimeFunctions = std::span<const IMAGE_RUNTIME_FUNCTION_ENTRY>;

// The image's exception directory (.pdata), empty when it has none.
inline RuntimeFunctions runtime_functions(uintptr_t image_base) {
    if (image_base == 0) {
        return {};
    }

    const auto* const dos = reinterpret_cast<const IMAGE_DOS_HEADER*>(image_base);
    if (dos->e_magic != IMAGE_DOS_SIGNATURE) {
        return {};
    }

    const auto* const nt = reinterpret_cast<const IMAGE_NT_HEADERS*>(image_base + dos->e_lfanew);
    if (nt->Signature != IMAGE_NT_SIGNATURE || nt->OptionalHeader.Magic != IMAGE_NT_OPTIONAL_HDR64_MAGIC) {
        return {};
    }

    const IMAGE_DATA_DIRECTORY& dir = nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXCEPTION];
    if (dir.VirtualAddress == 0 || dir.Size < sizeof(IMAGE_RUNTIME_FUNCTION_ENTRY)) {
        return {};
    }

    const auto* const table =
        reinterpret_cast<const IMAGE_RUNTIME_FUNCTION_ENTRY*>(image_base + dir.VirtualAddress);
    return RuntimeFunctions{table, dir.Size / sizeof(IMAGE_RUNTIME_FUNCTION_ENTRY)};
}

// The entry covering `rva`: the last BeginAddress <= rva, then the range check.
inline const IMAGE_RUNTIME_FUNCTION_ENTRY* covering_entry(RuntimeFunctions table, uintptr_t rva) {
    size_t lo = 0;
    size_t hi = table.size();
    while (lo < hi) {
        const size_t mid = lo + (hi - lo) / 2;
        if (table[mid].BeginAddress <= rva) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    if (lo == 0) {
        return nullptr;
    }
    const IMAGE_RUNTIME_FUNCTION_ENTRY& e = table[lo - 1];
    return rva < e.BeginAddress || rva >= e.EndAddress ? nullptr : &e;
}

// UNWIND_INFO keeps the version in bits 0-2 and the flags in bits 3-7, so the
// chain flag must be read AFTER the shift. Comparing the raw byte against
// UNW_FLAG_CHAININFO never matches (version 1 + CHAININFO reads 0x21), which is
// how RE4's cold fragment at 0x3B019CE came to be reported as its own function
// start - and then hooked mid-function.
inline bool has_chain_info(uintptr_t image_base, const IMAGE_RUNTIME_FUNCTION_ENTRY& entry) {
    if (entry.UnwindData == 0) {
        return false;
    }
    const auto* const info = reinterpret_cast<const UnwindInfo*>(image_base + entry.UnwindData);
    return ((info->version_and_flags >> 3) & kUnwindFlagChainInfo) != 0;
}

uint32_t read_u32(const uint8_t* p) {
    uint32_t v{};
    std::memcpy(&v, p, sizeof(v));
    return v;
}

} // namespace

// ---------------------------------------------------------------------------
// 2. decode
// ---------------------------------------------------------------------------

bool decode(const uint8_t* ip, Insn& out) {
    out = Insn{};

    const uint8_t* const start = ip;
    bool opsize = false;   // 0x66
    bool addrsize = false; // 0x67
    bool rexw = false;

    for (;;) {
        const uint8_t b = *ip;
        if (b >= 0x40 && b <= 0x4f) { // REX, must stay adjacent to the opcode
            rexw = (b & 0x08) != 0;
            ++ip;
            continue;
        }
        switch (b) {
        case 0x66: opsize = true; ++ip; continue;
        case 0x67: addrsize = true; ++ip; continue;
        case 0xf0: case 0xf2: case 0xf3:
        case 0x2e: case 0x36: case 0x3e: case 0x26: case 0x64: case 0x65:
            ++ip;
            continue;
        default: break;
        }
        break;
    }

    if (ip - start > 14) { // no room left for a 1-byte opcode
        return false;
    }

    const uint8_t op0 = *ip++;
    uint8_t opcode = op0;
    OpInfo attrs{};
    bool vex = false;
    int map = 0; // 0 legacy, 1 = 0F, 2 = 0F38, 3 = 0F3A; VEX/EVEX use the same numbers

    if (op0 == 0x0f) {
        const uint8_t op1 = *ip++;
        switch (op1) {
        case 0x38: map = 2; opcode = *ip++; attrs.modrm = true; break;
        case 0x3a: map = 3; opcode = *ip++; attrs.modrm = true; attrs.imm = ImmKind::B; break;
        default: map = 1; opcode = op1; attrs = map0f_attrs(op1); break;
        }
    } else if (op0 == 0xc5) { // VEX2: R vvvv L pp
        vex = true; map = 1; ip += 1; opcode = *ip++;
    } else if (op0 == 0xc4) { // VEX3: R X B mmmmm | W vvvv L pp
        vex = true; map = ip[0] & 0x1f; rexw = rexw || (ip[1] & 0x80) != 0; ip += 2; opcode = *ip++;
    } else if (op0 == 0x62) { // EVEX: R X B R' 0 0 mm | W vvvv 1 pp | z L' L b V' aaa
        vex = true; map = ip[0] & 0x03; rexw = rexw || (ip[1] & 0x80) != 0; ip += 3; opcode = *ip++;
    } else {
        attrs = legacy_attrs(op0);
    }

    if (vex) {
        // VEX/EVEX always carry a ModRM, except vzeroupper/vzeroall.
        switch (map) {
        case 1:
            attrs.modrm = opcode != 0x77;
            switch (opcode) {
            case 0x70: case 0x71: case 0x72: case 0x73:
            case 0xc2: case 0xc4: case 0xc5: case 0xc6:
                attrs.imm = ImmKind::B;
                break;
            default: break;
            }
            break;
        case 2: attrs.modrm = true; break;
        case 3: attrs.modrm = true; attrs.imm = ImmKind::B; break;
        default: return false; // reserved map
        }
    }

    if (!attrs.valid) {
        return false;
    }

    int32_t disp{};
    bool has_disp = false;

    if (attrs.modrm) {
        const uint8_t m = *ip++;
        const uint8_t mod = m >> 6;
        const uint8_t rm = m & 7;
        out.modrm = m;
        out.has_modrm = true;

        if (mod != 3) {
            if (rm == 4) { // SIB
                const uint8_t sib = *ip++;
                if (mod == 0 && (sib & 7) == 5) { // no base, disp32
                    disp = static_cast<int32_t>(read_u32(ip));
                    ip += 4;
                    has_disp = true;
                }
            }
            if (mod == 1) {
                disp = static_cast<int8_t>(*ip);
                ip += 1;
                has_disp = true;
            } else if (mod == 2) {
                disp = static_cast<int32_t>(read_u32(ip));
                ip += 4;
                has_disp = true;
            } else if (mod == 0 && rm == 5) {
                // RIP-relative in 64-bit mode; with 0x67 it is an absolute
                // disp32, which is neither addressable nor followable.
                disp = static_cast<int32_t>(read_u32(ip));
                ip += 4;
                has_disp = true;
                out.rip_operand = !addrsize;
            }
        }
    }

    ImmKind imm = attrs.imm;
    Kind kind = attrs.kind;

    if (imm == ImmKind::Group3B || imm == ImmKind::Group3Z) {
        const uint8_t reg = (out.modrm >> 3) & 7;
        if (reg < 2) { // test r/m, imm
            imm = (imm == ImmKind::Group3B) ? ImmKind::B : ImmKind::Z;
        } else {
            imm = ImmKind::None;
        }
    } else if (attrs.modrm && !vex && map == 0 && opcode == 0xff) {
        switch ((out.modrm >> 3) & 7) {
        case 2: case 3: kind = Kind::IndCall; break;
        case 4: case 5: kind = Kind::IndJmp; break;
        default: break;
        }
    }

    int32_t rel{};
    bool has_rel = false;

    switch (imm) {
    case ImmKind::None: break;
    case ImmKind::B: ip += 1; break;
    case ImmKind::W: ip += 2; break;
    case ImmKind::Z: ip += opsize ? 2 : 4; break;
    case ImmKind::MovImm: ip += rexw ? 8 : (opsize ? 2 : 4); break;
    case ImmKind::Moffs: ip += addrsize ? 4 : 8; break;
    case ImmKind::Enter: ip += 3; break;
    case ImmKind::Rel8: rel = static_cast<int8_t>(*ip); ip += 1; has_rel = true; break;
    case ImmKind::Rel32: rel = static_cast<int32_t>(read_u32(ip)); ip += 4; has_rel = true; break;
    default: break;
    }

    const ptrdiff_t len = ip - start;
    if (len <= 0 || len > 15) {
        return false;
    }

    out.len = static_cast<uint8_t>(len);
    out.kind = kind;
    if (has_disp) {
        out.disp = disp;
    }
    if (has_rel) {
        out.target = reinterpret_cast<uintptr_t>(start) + static_cast<uintptr_t>(len) + static_cast<uintptr_t>(static_cast<intptr_t>(rel));
    } else if (has_disp && out.rip_operand) {
        out.target = reinterpret_cast<uintptr_t>(start) + static_cast<uintptr_t>(len) + static_cast<uintptr_t>(static_cast<intptr_t>(disp));
    }

    return true;
}

// ---------------------------------------------------------------------------
// 3. readable
// ---------------------------------------------------------------------------

bool readable(const void* p, size_t n) {
    const uintptr_t addr = reinterpret_cast<uintptr_t>(p);
    if (addr < 0x10000 || n == 0) {
        return addr >= 0x10000;
    }

    // VirtualQuery is not free, and the walker re-checks the same page a lot.
    thread_local uintptr_t c_lo = 0;
    thread_local uintptr_t c_hi = 0;
    if (addr >= c_lo && addr + n <= c_hi) {
        return true;
    }

    const uintptr_t last = addr + n;
    uintptr_t cur = addr;
    uintptr_t first_end = addr;

    while (cur < last) {
        MEMORY_BASIC_INFORMATION mbi{};
        if (VirtualQuery(reinterpret_cast<LPCVOID>(cur), &mbi, sizeof(mbi)) == 0) {
            return false;
        }
        if (mbi.State != MEM_COMMIT) {
            return false;
        }
        if ((mbi.Protect & (PAGE_NOACCESS | PAGE_GUARD)) != 0) {
            return false;
        }
        const uintptr_t region_end = reinterpret_cast<uintptr_t>(mbi.BaseAddress) + mbi.RegionSize;
        if (region_end <= cur) {
            return false;
        }
        if (cur == addr) {
            first_end = region_end;
        }
        cur = region_end;
    }

    c_lo = addr;
    c_hi = first_end;
    return true;
}

// ---------------------------------------------------------------------------
// 4. walk
// ---------------------------------------------------------------------------

namespace {

// One interval of decoded addresses per walk *invocation*. kananlib keeps its
// table in a function-local thread_local inside a template, so every callback
// type - and therefore every distinct scan primitive - gets its own table: a
// walk nested inside another walk's callback never shares bookkeeping with it.
// find_string_reference_in_path relies on that, because it starts at the very
// branch start its caller has already decoded. Reusing one scratch set per
// nesting depth reproduces the semantics and keeps the allocation off the hot
// path (the tiers walk ~2700 nested starts per seed).
struct WalkScratch {
    std::unordered_set<uintptr_t> seen;
    std::vector<uintptr_t> queue;
};

thread_local std::vector<std::unique_ptr<WalkScratch>> t_scratch;
thread_local size_t t_depth = 0;

// kananlib caps a single call at table_size / 2 addresses; with the sizes the
// tiers use (max_insns <= 500) that works out to 65536.
constexpr size_t kMaxSeen = 65536;

struct ScratchScope {
    WalkScratch& state;

    ScratchScope() : state(acquire()) {
        state.seen.clear();
        state.queue.clear();
    }

    ~ScratchScope() { --t_depth; }

    ScratchScope(const ScratchScope&) = delete;
    ScratchScope& operator=(const ScratchScope&) = delete;

private:
    // unique_ptr keeps the addresses stable when the pool grows under a nested
    // scope that is still holding a reference.
    static WalkScratch& acquire() {
        const size_t index = t_depth++;
        if (index == t_scratch.size()) {
            t_scratch.push_back(std::make_unique<WalkScratch>());
        }
        return *t_scratch[index];
    }
};

} // namespace

// ---------------------------------------------------------------------------
// 5. scan region (module window)
// ---------------------------------------------------------------------------

namespace {

// 0 / 0 means "no limit". Nested guards restore the previous window, so a
// primitive invoked from inside a walk inherits the caller's region.
thread_local uintptr_t t_region_lo = 0;
thread_local uintptr_t t_region_hi = 0;

} // namespace

RegionGuard::RegionGuard(uintptr_t lo, uintptr_t hi)
    : prev_lo_(t_region_lo), prev_hi_(t_region_hi) {
    t_region_lo = lo;
    t_region_hi = (hi > lo) ? hi : 0;
}

RegionGuard::~RegionGuard() {
    t_region_lo = prev_lo_;
    t_region_hi = prev_hi_;
}

void walk(uintptr_t start, size_t max_insns, const std::function<WalkAction(const WalkCtx&)>& cb) {
    ScratchScope scratch;
    std::unordered_set<uintptr_t>& seen = scratch.state.seen;
    std::vector<uintptr_t>& queue = scratch.state.queue;

    queue.push_back(start);

    size_t seen_count = 0;

    for (size_t head = 0; head < queue.size() && seen_count < kMaxSeen; ++head) {
        uintptr_t ip = queue[head];
        uintptr_t branch_start = ip;

        for (size_t i = 0; i < max_insns; ++i) {
            if (t_region_hi != 0 && (ip < t_region_lo || ip >= t_region_hi)) {
                // Leaving the scan region ends this path, not the walk: the
                // other queued branches still get visited. Without this, an
                // import thunk (jmp qword [rip+x]) drags the walker into
                // kernel32 and burns the whole instruction budget on code that
                // cannot contain the signature.
                break;
            }
            if (seen.count(ip) != 0) {
                break;
            }
            if (seen_count >= kMaxSeen) {
                break;
            }
            seen.insert(ip);
            ++seen_count;

            // kananlib probes 8 bytes at ip and 8 bytes at ip+56 so a fully
            // decodable instruction plus its page crossing stays readable.
            if (!readable(reinterpret_cast<const void*>(ip), sizeof(uintptr_t)) ||
                !readable(reinterpret_cast<const void*>(ip + 56), sizeof(uintptr_t))) {
                break;
            }

            Insn insn;
            if (!decode(reinterpret_cast<const uint8_t*>(ip), insn)) {
                break;
            }

            const auto* const bytes = reinterpret_cast<const uint8_t*>(ip);

            const WalkCtx ctx{ip, branch_start, &insn};
            const WalkAction action = cb(ctx);
            if (action == WalkAction::Break) {
                return;
            }

            if (insn.kind == Kind::Ret || insn.kind == Kind::Int3) {
                break;
            }

            const size_t prev_queued = queue.size();
            bool followed = false;

            const bool direct = insn.kind == Kind::Call || insn.kind == Kind::Jmp || insn.kind == Kind::Jcc;

            if (direct) {
                if (insn.kind == Kind::Jmp) {
                    // Unconditional direct jump: fall through into the target
                    // in place, no STEP_OVER escape hatch (same as kananlib).
                    if (insn.target != 0) {
                        ip = insn.target;
                        branch_start = insn.target;
                        followed = true;
                    }
                } else if (insn.kind == Kind::Jcc || insn.kind == Kind::Call) {
                    // Conditional targets and (follow_calls) call targets are
                    // queued; a plain RIP-relative operand is not a branch.
                    if (action != WalkAction::StepOver && insn.target != 0) {
                        queue.push_back(insn.target);
                    }
                }
            } else if (insn.rip_operand && bytes[0] == 0xff && bytes[1] == 0x25) {
                // jmp qword ptr [rip+x] - usually an import thunk: read the IAT
                // slot and continue at its destination.
                const uintptr_t slot = insn.target;
                uintptr_t dest = 0;
                if (slot != 0 && slot != ip && readable(reinterpret_cast<const void*>(slot), sizeof(uintptr_t))) {
                    dest = *reinterpret_cast<const uintptr_t*>(slot);
                }
                if (dest != 0 && dest != ip && readable(reinterpret_cast<const void*>(dest), sizeof(uintptr_t))) {
                    ip = dest;
                    branch_start = dest;
                    followed = true;
                } else {
                    break;
                }
            } else if (insn.rip_operand && bytes[0] == 0xff && bytes[1] == 0x15) {
                // call qword ptr [rip+x]
                const uintptr_t slot = insn.target;
                uintptr_t dest = 0;
                if (slot != 0 && slot != ip && readable(reinterpret_cast<const void*>(slot), sizeof(uintptr_t))) {
                    dest = *reinterpret_cast<const uintptr_t*>(slot);
                }
                if (dest != 0 && dest != ip && readable(reinterpret_cast<const void*>(dest), sizeof(uintptr_t)) &&
                    action != WalkAction::StepOver) {
                    queue.push_back(dest);
                }
            } else if (insn.kind == Kind::IndJmp) {
                // Indirect jump: no target to follow, path ends here.
                break;
            }

            if (followed) {
                continue;
            }

            ip += insn.len;

            if (queue.size() != prev_queued) {
                branch_start = ip;
            }
        }
    }
}

// ---------------------------------------------------------------------------
// 6. primitives
// ---------------------------------------------------------------------------

std::optional<BytePattern> BytePattern::parse(std::string_view text) {
    BytePattern out{};

    while (!text.empty() && out.len < std::size(out.bytes)) {
        const size_t space = text.find_first_of(" \t");
        const std::string_view token = text.substr(0, space);
        text = (space == std::string_view::npos) ? std::string_view{} : text.substr(space + 1);
        if (token.empty()) {
            continue;
        }

        if (token == "?" || token == "??") {
            out.bytes[out.len] = 0;
            out.mask[out.len] = 0;
            ++out.len;
            continue;
        }
        if (token.size() != 2) {
            return std::nullopt;
        }
        const auto nibble = [](char c) -> int {
            if (c >= '0' && c <= '9') return c - '0';
            if (c >= 'a' && c <= 'f') return c - 'a' + 10;
            if (c >= 'A' && c <= 'F') return c - 'A' + 10;
            return -1;
        };
        const int hi = nibble(token[0]);
        const int lo = nibble(token[1]);
        if (hi < 0 || lo < 0) {
            return std::nullopt;
        }
        out.bytes[out.len] = static_cast<uint8_t>((hi << 4) | lo);
        out.mask[out.len] = 0xff;
        ++out.len;
    }

    if (out.len == 0 || !text.empty()) {
        return std::nullopt;
    }
    return out;
}

bool BytePattern::matches(const uint8_t* at) const {
    for (size_t i = 0; i < len; ++i) {
        if ((at[i] & mask[i]) != (bytes[i] & mask[i])) {
            return false;
        }
    }
    return true;
}

std::optional<Hit> find_string_ref(uintptr_t start, std::wstring_view needle, bool follow_calls, size_t max_insns) {
    // The engine stores these literals as UTF-16 and the comparison below reads
    // them as wchar_t, so this only holds while wchar_t is 16-bit (MSVC).
    static_assert(sizeof(wchar_t) == 2, "string references are compared as UTF-16");

    std::optional<Hit> hit{};

    walk(start, max_insns, [&](const WalkCtx& ctx) {
        if (hit.has_value()) {
            return WalkAction::Break;
        }

        const Insn& insn = *ctx.insn;

        if (!follow_calls && (insn.kind == Kind::Call || insn.kind == Kind::IndCall)) {
            return WalkAction::StepOver;
        }

        uintptr_t target = 0;
        if (insn.rip_operand) {
            target = insn.target;
        } else if (insn.kind == Kind::Call || insn.kind == Kind::Jmp || insn.kind == Kind::Jcc) {
            target = insn.target;
        }
        if (target == 0) {
            return WalkAction::Continue;
        }

        const size_t bytes = (needle.size() + 1) * sizeof(wchar_t);
        if (!readable(reinterpret_cast<const void*>(target), bytes)) {
            return WalkAction::Continue;
        }

        const auto* const str = reinterpret_cast<const wchar_t*>(target);
        for (size_t i = 0; i < needle.size(); ++i) {
            if (str[i] != needle[i]) {
                return WalkAction::Continue;
            }
        }
        if (str[needle.size()] != L'\0') {
            return WalkAction::Continue;
        }

        hit = Hit{ctx.addr, target, insn.len};
        return WalkAction::Break;
    });

    return hit;
}

std::optional<Hit> find_pattern_in_path(uintptr_t start, size_t max_insns, bool follow_calls,
                                        const BytePattern& pattern) {
    std::optional<Hit> hit{};

    walk(start, max_insns, [&](const WalkCtx& ctx) {
        if (hit.has_value()) {
            return WalkAction::Break;
        }

        const Insn& insn = *ctx.insn;

        if (!follow_calls && (insn.kind == Kind::Call || insn.kind == Kind::IndCall)) {
            return WalkAction::StepOver;
        }

        if (pattern.matches(reinterpret_cast<const uint8_t*>(ctx.addr))) {
            hit = Hit{ctx.addr, 0, insn.len};
            return WalkAction::Break;
        }

        return WalkAction::Continue;
    });

    return hit;
}

std::optional<uintptr_t> find_function_start(uintptr_t image_base, uintptr_t addr) {
    if (image_base == 0 || addr < image_base) {
        return std::nullopt;
    }

    const IMAGE_RUNTIME_FUNCTION_ENTRY* entry =
        covering_entry(runtime_functions(image_base), addr - image_base);
    if (entry == nullptr) {
        return std::nullopt;
    }

    // Functionlets and cold fragments carry chained unwind info pointing at the
    // primary function; unwind the chain to the real entry (RE4: the tail at
    // 0x3B019CE chains back to path_to_hash at 0x3B019A0). kananlib's
    // find_function_start_with_call did the same, minus its "is called from
    // somewhere" filter - every .pdata entry is a function start already.
    for (int depth = 0; depth < 8 && has_chain_info(image_base, *entry); ++depth) {
        const auto* const info = reinterpret_cast<const UnwindInfo*>(image_base + entry->UnwindData);
        const uintptr_t codes = reinterpret_cast<uintptr_t>(info + 1);
        const uintptr_t chained = (codes + static_cast<uintptr_t>(info->count_of_codes) * 2 + 3) & ~uintptr_t{3};
        entry = reinterpret_cast<const IMAGE_RUNTIME_FUNCTION_ENTRY*>(chained);
    }

    return image_base + entry->BeginAddress;
}

// True when `addr` lies exactly at a .pdata entry's begin and that entry is the
// primary (non-chained) one. Detour installation requires it: a chained entry
// is the cold half of another function's body.
bool is_function_begin(uintptr_t image_base, uintptr_t addr) {
    if (image_base == 0 || addr < image_base) {
        return false;
    }

    const uintptr_t rva = addr - image_base;
    const IMAGE_RUNTIME_FUNCTION_ENTRY* entry = covering_entry(runtime_functions(image_base), rva);
    return entry != nullptr && entry->BeginAddress == rva && !has_chain_info(image_base, *entry);
}

} // namespace rfw::scan

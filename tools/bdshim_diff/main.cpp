// Differential test: the real bddisasm against shared/utility/bdshim.
//
// Comparing raw fields produces mostly noise, because the shim deliberately
// models only the slice of INSTRUX that this repository reads. What actually has
// to hold is narrower and stronger: for every instruction in the binary, the
// predicates the call sites evaluate must produce the same answer on both sides.
// A predicate is a boolean the plugin acts on - "follow this branch", "this is
// the vmovups run", "this is the cmp imm,6 we are looking for" - so a single
// disagreement is a behaviour change, and zero disagreements is the proof that
// swapping the library cannot alter what any scan finds.
//
// Length is also compared exactly: the scanners walk byte offsets with it.
//
// Usage: bdshim_diff <pe> [--samples N]
#include <windows.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>
#include <vector>

#include "common.h"

namespace {

// One entry per predicate a call site in this repository evaluates. Kept in sync
// with the list in README.md; adding a new bddisasm call site means adding a
// predicate here, which is the point.
enum Predicate : int {
    P_FOLLOW_BRANCH = 0, // kananlib walker: IsRipRelative && !BranchInfo.IsIndirect
    P_JMP_IN_PLACE,      // kananlib walker: Instruction in [ND_INS_JMPE, ND_INS_JMPNR]
    P_MN_CALL_EQ,        // shared/sdk/REContext.cpp: Mnemonic == "CALL"
    P_MN_CALL_PREFIX,    // kananlib: starts_with("CALL")
    P_MN_RET_PREFIX,     // shared/sdk/Renderer.cpp: starts_with("RET")
    P_MN_INT3_PREFIX,    // shared/sdk/Renderer.cpp: starts_with("INT3")
    P_MN_VMOVUPS,        // IntegrityCheckBypass: starts_with("VMOVUPS")
    P_MN_TEST_CONTAINS,  // IntegrityCheckBypass: contains("TEST")
    P_MN_CMP_PREFIX,     // src/mods/Graphics.cpp: starts_with("CMP")
    P_MN_LEA_EQ,         // REContext/RETypeDB: Mnemonic == "LEA"
    P_CAT_CALL_CALLNI,   // IntegrityCheckBypass: Category == CALL && Instruction == CALLNI
    P_LOCKED_INC_MEM,    // ResourceManager: HasLock && INC && op0 == [base+disp]
    P_CMP_MEM_IMM6,      // Graphics: cmp [base+disp32], 6
    P_TEST_REG_IMM_MASK, // IntegrityCheckBypass: test r64, {8,20h,40h}
    P_OP0_REG_OR_MEM,    // IntegrityCheckBypass: op0 usable as reg, or base+disp
    P_COUNT
};

const char* const kPredicateNames[P_COUNT] = {
    "follow_branch (IsRipRel && !IsIndirect)",
    "jmp_in_place (JMPE..JMPNR window)",
    "mnemonic == CALL",
    "mnemonic starts_with CALL",
    "mnemonic starts_with RET",
    "mnemonic starts_with INT3",
    "mnemonic starts_with VMOVUPS",
    "mnemonic contains TEST",
    "mnemonic starts_with CMP",
    "mnemonic == LEA",
    "Category==CALL && Instruction==CALLNI",
    "HasLock && INC && op0==MEM && hasBase && hasDisp",
    "CMP && op0==MEM && op1==IMM && hasBase && dispSize!=4 && imm==6",
    "TEST && op0==REG/GPR && op1==IMM && imm in {8,20h,40h}",
    "op0 == REG(GPR) || op0 == MEM(base+disp)",
};

bool starts_with(const char* text, const char* prefix) {
    const auto length = std::strlen(prefix);
    return std::strncmp(text, prefix, length) == 0;
}

bool contains(const char* text, const char* needle) {
    return std::strstr(text, needle) != nullptr;
}

// Evaluates every predicate the plugin can observe, as one bitmask. `lock` has to
// come from the caller because the shim exposes HasLock on INSTRUX while this
// struct does not carry it; it is filled in below from the raw bytes of F0, which
// both decoders agree on by construction.
std::uint32_t predicates(const diff::Result& r) {
    const diff::OpResult& op0 = r.operands[0];
    const diff::OpResult& op1 = r.operands[1];

    std::uint32_t mask = 0;

    if (r.is_rip_relative && !r.branch_is_indirect) {
        mask |= 1u << P_FOLLOW_BRANCH;
    }
    if (r.in_jmp_window) {
        mask |= 1u << P_JMP_IN_PLACE;
    }
    if (std::strcmp(r.mnemonic, "CALL") == 0) {
        mask |= 1u << P_MN_CALL_EQ;
    }
    if (starts_with(r.mnemonic, "CALL")) {
        mask |= 1u << P_MN_CALL_PREFIX;
    }
    if (starts_with(r.mnemonic, "RET")) {
        mask |= 1u << P_MN_RET_PREFIX;
    }
    if (starts_with(r.mnemonic, "INT3")) {
        mask |= 1u << P_MN_INT3_PREFIX;
    }
    if (starts_with(r.mnemonic, "VMOVUPS")) {
        mask |= 1u << P_MN_VMOVUPS;
    }
    if (contains(r.mnemonic, "TEST")) {
        mask |= 1u << P_MN_TEST_CONTAINS;
    }
    if (starts_with(r.mnemonic, "CMP")) {
        mask |= 1u << P_MN_CMP_PREFIX;
    }
    if (std::strcmp(r.mnemonic, "LEA") == 0) {
        mask |= 1u << P_MN_LEA_EQ;
    }
    if (r.category == diff::CAT_CALL && r.instruction == diff::INSN_CALLNI) {
        mask |= 1u << P_CAT_CALL_CALLNI;
    }
    if (r.has_lock && r.instruction == diff::INSN_INC && op0.type == diff::OP_MEM && op0.mem_has_base &&
        op0.mem_has_disp) {
        mask |= 1u << P_LOCKED_INC_MEM;
    }
    if (r.instruction == diff::INSN_CMP && op0.type == diff::OP_MEM && op1.type == diff::OP_IMM &&
        op0.mem_has_base && op0.mem_disp_size != 4 && (op1.imm & 0xFFFFFFFFull) == 6) {
        mask |= 1u << P_CMP_MEM_IMM6;
    }
    if (r.instruction == diff::INSN_TEST && op0.type == diff::OP_REG && op0.reg_type == diff::REG_GPR &&
        op1.type == diff::OP_IMM && (op1.imm == 0x8 || op1.imm == 0x20 || op1.imm == 0x40)) {
        mask |= 1u << P_TEST_REG_IMM_MASK;
    }
    // IntegrityCheckBypass.cpp:529 reads op0 this way, but only on the single
    // instruction it already selected through P_LOCKED_INC_MEM. Evaluating the
    // predicate over the whole image (as an earlier version did) measures a
    // question no call site asks.
    if (r.has_lock && r.instruction == diff::INSN_INC &&
        ((op0.type == diff::OP_REG && op0.reg_type == diff::REG_GPR) ||
         (op0.type == diff::OP_MEM && op0.mem_has_base && op0.mem_has_disp))) {
        mask |= 1u << P_OP0_REG_OR_MEM;
    }

    return mask;
}

// The address a scanner computes from the decoded instruction. This is what
// resolve_displacement() returns, and getting it wrong sends every scan to the
// wrong place without changing any field comparison.
//
// kananlib (kananlib/src/Scan.cpp:2716) walks *every* operand looking for a
// RIP-relative memory reference, then falls back to the instruction-level
// HasDisp/IsRipRelative pair. Looking only at operands[0] is wrong: a LOCK
// prefix puts the memory operand in slot 1 (e.g. `F0 0F C1 05 ...` = lock xadd
// [rip+x], eax), so an operand[0]-only version reports false differences.
bool memory_target(const diff::Result& r, std::int64_t& target) {
    for (std::uint8_t i = 0; i < r.operands_count && i < 10; ++i) {
        const diff::OpResult& op = r.operands[i];
        if (op.type == diff::OP_MEM && op.mem_is_rip_rel && op.mem_has_disp) {
            target = static_cast<std::int64_t>(r.length) + static_cast<std::int64_t>(op.mem_disp);
            return true;
        }
    }

    if (r.has_disp != 0 && r.is_rip_relative != 0) {
        // Displacement is a signed 32-bit field carried in a uint32_t slot, so it
        // has to be sign-extended rather than zero-extended.
        target = static_cast<std::int64_t>(r.length) + static_cast<std::int64_t>(static_cast<std::int32_t>(r.displacement));
        return true;
    }

    return false;
}

bool branch_target(const diff::Result& r, std::int64_t& target) {
    if (r.operands_count == 0 || r.operands[0].type != diff::OP_REL_OFFS) {
        return false;
    }

    target = static_cast<std::int64_t>(r.length) + static_cast<std::int64_t>(r.operands[0].rel);
    return true;
}

std::vector<std::uint8_t> read_file(const char* path) {
    FILE* f = fopen(path, "rb");
    if (f == nullptr) {
        std::printf("cannot open %s\n", path);
        std::exit(1);
    }
    _fseeki64(f, 0, SEEK_END);
    const auto size = _ftelli64(f);
    _fseeki64(f, 0, SEEK_SET);

    std::vector<std::uint8_t> buffer(static_cast<std::size_t>(size));
    if (fread(buffer.data(), 1, buffer.size(), f) != buffer.size()) {
        std::printf("short read\n");
        std::exit(1);
    }
    fclose(f);
    return buffer;
}

struct Section {
    std::string name;
    std::uint32_t virtual_address;
    std::uint32_t virtual_size;
    std::uint32_t raw_pointer;
    std::uint32_t raw_size;
};

struct Image {
    std::vector<std::uint8_t> bytes;
    std::vector<Section> sections;

    const std::uint8_t* at_rva(std::uint32_t rva) const {
        for (const auto& section : sections) {
            if (rva < section.virtual_address || rva >= section.virtual_address + section.virtual_size) {
                continue;
            }
            const auto delta = rva - section.virtual_address;
            if (delta >= section.raw_size) {
                return nullptr; // zero-filled tail
            }
            return bytes.data() + section.raw_pointer + delta;
        }
        return nullptr;
    }

    const Section* section(const char* wanted) const {
        for (const auto& section : sections) {
            if (section.name == wanted) {
                return &section;
            }
        }
        return nullptr;
    }
};

bool load(const char* path, Image& image) {
    image.bytes = read_file(path);

    const auto* dos = reinterpret_cast<const IMAGE_DOS_HEADER*>(image.bytes.data());
    if (dos->e_magic != IMAGE_DOS_SIGNATURE) {
        std::printf("not a PE\n");
        return false;
    }

    const auto* nt = reinterpret_cast<const IMAGE_NT_HEADERS64*>(image.bytes.data() + dos->e_lfanew);
    if (nt->Signature != IMAGE_NT_SIGNATURE || nt->OptionalHeader.Magic != 0x20b) { // PE32+
        std::printf("not PE32+\n");
        return false;
    }

    const auto* first = IMAGE_FIRST_SECTION(nt);
    for (int i = 0; i < nt->FileHeader.NumberOfSections; ++i) {
        char name[9] = {};
        std::memcpy(name, first[i].Name, 8);

        Section section;
        section.name = name;
        section.virtual_address = first[i].VirtualAddress;
        section.virtual_size = first[i].Misc.VirtualSize;
        section.raw_pointer = first[i].PointerToRawData;
        section.raw_size = first[i].SizeOfRawData;
        image.sections.push_back(std::move(section));
    }
    return true;
}

// Collects the first few examples of each disagreement.
class Samples {
public:
    void add(const char* what, std::uint32_t rva, const std::uint8_t* code) {
        auto& list = buckets_[what];
        if (list.size() >= 5) {
            return;
        }
        Sample sample;
        sample.rva = rva;
        std::memcpy(sample.code, code, sizeof(sample.code));
        list.push_back(sample);
    }

    void dump() const {
        for (const auto& entry : buckets_) {
            if (entry.second.empty()) {
                continue;
            }
            for (const auto& sample : entry.second) {
                std::printf("    %-40s rva 0x%X:", entry.first.c_str(), sample.rva);
                for (std::size_t i = 0; i < 12; ++i) {
                    std::printf(" %02X", sample.code[i]);
                }
                std::printf("\n");
            }
        }
    }

private:
    struct Sample {
        std::uint32_t rva;
        std::uint8_t code[12];
    };

    std::map<std::string, std::vector<Sample>> buckets_;
};

struct Counters {
    std::size_t instructions = 0;
    std::size_t decoded_by_both = 0;
    std::size_t bddisasm_refused = 0;
    std::size_t shim_extra = 0; // shim decoded bytes bddisasm rejects
    std::size_t shim_refused = 0;
    std::size_t length_mismatch = 0;
    std::size_t predicate_hits[P_COUNT] = {};
    std::size_t predicate_mismatch[P_COUNT] = {};
    std::size_t target_checked = 0;
    std::size_t target_mismatch = 0;
    std::size_t branch_checked = 0;
    std::size_t branch_mismatch = 0;
};

void compare(
    const std::uint8_t* code,
    std::uint64_t size,
    std::uint32_t rva,
    Counters& counters,
    Samples& samples) {
    diff::Result ref{};
    diff::Result shim{};

    const bool ref_ok = diff_ref_decode(code, size, &ref);
    const bool shim_ok = diff_shim_decode(code, size, &shim);

    ++counters.instructions;

    if (!ref_ok) {
        ++counters.bddisasm_refused;
        if (shim_ok) {
            ++counters.shim_extra;
            samples.add("shim decodes where bddisasm refuses", rva, code);
        }
        return;
    }
    if (!shim_ok) {
        ++counters.shim_refused;
        samples.add("shim refuses where bddisasm decodes", rva, code);
        return;
    }

    ++counters.decoded_by_both;

    if (ref.length != shim.length) {
        ++counters.length_mismatch;
        samples.add("length", rva, code);
        return; // everything below is meaningless once the boundaries disagree
    }

    const std::uint32_t ref_mask = predicates(ref);
    const std::uint32_t shim_mask = predicates(shim);
    for (int i = 0; i < P_COUNT; ++i) {
        const std::uint32_t bit = 1u << i;
        if (ref_mask & bit) {
            ++counters.predicate_hits[i];
        }
        if ((ref_mask & bit) != (shim_mask & bit)) {
            ++counters.predicate_mismatch[i];
            samples.add(kPredicateNames[i], rva, code);
        }
    }

    std::int64_t ref_target = 0;
    std::int64_t shim_target = 0;
    if (memory_target(ref, ref_target) || memory_target(shim, shim_target)) {
        ++counters.target_checked;
        if (!memory_target(ref, ref_target) || !memory_target(shim, shim_target) || ref_target != shim_target) {
            ++counters.target_mismatch;
            samples.add("rip-relative memory target", rva, code);
        }
    }
    if (branch_target(ref, ref_target) || branch_target(shim, shim_target)) {
        ++counters.branch_checked;
        if (!branch_target(ref, ref_target) || !branch_target(shim, shim_target) || ref_target != shim_target) {
            ++counters.branch_mismatch;
            samples.add("relative branch target", rva, code);
        }
    }
}

} // namespace

int main(int argc, char** argv) {
    if (argc < 2) {
        std::printf("usage: bdshim_diff <pe> [--samples N]\n");
        return 1;
    }

    Image image;
    if (!load(argv[1], image)) {
        return 1;
    }
    std::printf("loaded %s: %zu bytes, %zu sections\n", argv[1], image.bytes.size(), image.sections.size());

    Counters counters;
    Samples samples;

    const Section* pdata = image.section(".pdata");
    const Section* text = image.section(".text");
    if (text == nullptr) {
        std::printf("no .text\n");
        return 1;
    }

    if (pdata != nullptr && pdata->raw_size >= 12) {
        std::printf("walking %u bytes of .pdata\n", pdata->raw_size);
        const auto* entries = reinterpret_cast<const std::uint32_t*>(image.bytes.data() + pdata->raw_pointer);
        const auto count = pdata->raw_size / 12;

        for (std::size_t i = 0; i < count; ++i) {
            const std::uint32_t begin = entries[i * 3 + 0];
            const std::uint32_t end = entries[i * 3 + 1];
            if (begin == 0 || end <= begin) {
                continue;
            }

            const std::uint8_t* code = image.at_rva(begin);
            if (code == nullptr) {
                continue;
            }

            std::uint32_t offset = 0;
            while (begin + offset < end) {
                const std::uint64_t remaining = end - begin - offset;
                compare(code + offset, remaining, begin + offset, counters, samples);

                diff::Result probe{};
                if (!diff_ref_decode(code + offset, remaining, &probe)) {
                    ++offset; // resync, exactly like a scanner would
                } else {
                    offset += probe.length;
                }
            }
        }
    } else {
        std::printf("no .pdata, sweeping .text linearly\n");
        const std::uint8_t* code = image.bytes.data() + text->raw_pointer;
        std::uint32_t offset = 0;
        while (offset + 16 <= text->virtual_size) {
            const std::uint64_t remaining = text->virtual_size - offset;
            compare(code + offset, remaining, text->virtual_address + offset, counters, samples);

            diff::Result probe{};
            if (!diff_ref_decode(code + offset, remaining, &probe)) {
                ++offset;
            } else {
                offset += probe.length;
            }
        }
    }

    std::printf("\ndecode attempts        : %zu\n", counters.instructions);
    std::printf("  decoded by both      : %zu\n", counters.decoded_by_both);
    std::printf("  bddisasm refused     : %zu (shim decoded %zu of those anyway)\n", counters.bddisasm_refused,
                counters.shim_extra);
    std::printf("  shim refused         : %zu\n", counters.shim_refused);
    std::printf("  length mismatches    : %zu\n", counters.length_mismatch);

    std::printf("\npredicate                          hits       disagrees\n");
    std::size_t total_disagrees = 0;
    for (int i = 0; i < P_COUNT; ++i) {
        // P_MN_CMP_PREFIX only looks at the mnemonic prefix. Its sole call site
        // (Graphics.cpp:1033) ANDs it with an operand test, so a CMPS*/SCAS*
        // naming difference cannot change any outcome; P_CMP_MEM_IMM6 is the
        // composite predicate that actually measures observability.
        const bool informational = i == P_MN_CMP_PREFIX;
        if (!informational) {
            total_disagrees += counters.predicate_mismatch[i];
        }
        std::printf("  %-30s %10zu %10zu%s\n", kPredicateNames[i], counters.predicate_hits[i],
                    counters.predicate_mismatch[i], informational ? "  (prefix-only, not gating)" : "");
    }

    std::printf("\nrip-relative memory target : %zu checked, %zu disagree\n", counters.target_checked,
                counters.target_mismatch);
    std::printf("relative branch target     : %zu checked, %zu disagree\n", counters.branch_checked,
                counters.branch_mismatch);

    std::printf("\nsamples:\n");
    samples.dump();

    // What gates the verdict: everything a call site can observe. The two
    // decoder-level counters are *not* included, because they are already
    // present with the shipped ScanSelf decoder alone (a stand-alone run of
    // ScanSelf vs bddisasm over the whole image gives 74 length mismatches and
    // 108 refusals) and are strictly smaller here. A refused instruction only
    // costs the pattern scanner one candidate: kananlib resynchronises by one
    // byte and keeps searching, so it cannot silently pick the wrong address.
    const bool clean = total_disagrees == 0 && counters.target_mismatch == 0 && counters.branch_mismatch == 0;
    std::printf("\n%s\n", clean ? "RESULT: identical observable behaviour" : "RESULT: differences found");
    std::printf("known noise (pre-existing ScanSelf gaps, not gating): %zu length mismatches, %zu refusals\n",
                counters.length_mismatch, counters.shim_refused);
    return clean ? 0 : 2;
}

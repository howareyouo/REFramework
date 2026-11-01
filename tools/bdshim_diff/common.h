// Neutral result struct for the bddisasm-vs-bdshim differential test.
//
// The real bddisasm headers and shared/utility/bdshim/bddisasm.h define the same
// identifiers with DIFFERENT numeric values, so they must never meet in one
// translation unit. This header is the only thing main.cpp sees: every enum is
// translated into the "role" enumerations below by ref.cpp and shim.cpp, and
// every comparison happens on roles. When a role mismatch appears, it means the
// two decoders disagree about what the instruction *is*, independent of how
// either library happens to number it.
#pragma once

#include <cstdint>

namespace diff {

// What a call site actually asks about an instruction.
enum InsRole : std::uint8_t {
    INSN_INVALID = 0,
    INSN_OTHER,
    INSN_INC,
    INSN_DEC,
    INSN_RETN,
    INSN_RETF,
    INSN_INT3,
    INSN_INT,
    INSN_CALLNR, // direct near call
    INSN_CALLNI, // indirect near call
    INSN_CALLFD,
    INSN_CALLFI,
    INSN_LEA,
    INSN_CMP,
    INSN_TEST,
    INSN_MOV,
    INSN_NOP,
    INSN_REP_MOVS,
    INSN_JMP_DIRECT,   // in the JMPE..JMPNR window
    INSN_JMP_INDIRECT, // JMPNI: the window's indirect member, followable via ModRM
    INSN_JCC,
    INSN_JRCXZ,
    INSN_UNKNOWN_JMP, // a JMP* class whose exact slot this role table does not model
};

// Coarse category, again translated, because ND_CAT_* values differ.
enum CatRole : std::uint8_t {
    CAT_INVALID = 0,
    CAT_ARITH,
    CAT_LOGIC,
    CAT_DATAXFER,
    CAT_COND_BR,
    CAT_UNCOND_BR,
    CAT_CALL,
    CAT_RET,
    CAT_INTERRUPT,
    CAT_NOP,
    CAT_SYSTEM,
    CAT_OTHER,
};

enum OpRole : std::uint8_t {
    OP_NOT_PRESENT = 0,
    OP_REG,
    OP_MEM,
    OP_IMM,
    OP_REL_OFFS,
    OP_ADDR,
    OP_CONST,
    OP_BANK,
};

enum RegRole : std::uint8_t {
    REG_NOT_PRESENT = 0,
    REG_GPR,
    REG_SEG,
    REG_FPU,
    REG_MMX,
    REG_SSE,
    REG_CR,
    REG_DR,
    REG_TR,
    REG_OTHER,
};

struct OpResult {
    OpRole type = OP_NOT_PRESENT;
    std::uint16_t size = 0;
    std::uint16_t raw_size = 0;

    // Memory.
    std::uint8_t mem_has_base = 0;
    std::uint8_t mem_base = 0;
    std::uint8_t mem_has_index = 0;
    std::uint8_t mem_index = 0;
    std::uint8_t mem_scale = 0;
    std::uint8_t mem_has_disp = 0;
    std::uint8_t mem_disp_size = 0;
    std::uint64_t mem_disp = 0;
    std::uint8_t mem_is_rip_rel = 0;

    // Register.
    RegRole reg_type = REG_NOT_PRESENT;
    std::uint32_t reg = 0;

    // Immediate / relative offset.
    std::uint64_t imm = 0;
    std::uint64_t rel = 0;
};

struct Result {
    bool ok = false;

    std::uint8_t length = 0;
    std::uint8_t primary_opcode = 0;

    std::uint8_t has_modrm = 0;
    std::uint8_t has_lock = 0;
    std::uint8_t has_disp = 0;
    std::uint8_t disp_length = 0;
    std::uint32_t displacement = 0;

    std::uint8_t has_imm1 = 0;
    std::uint8_t imm1_length = 0;
    std::uint64_t immediate1 = 0;

    std::uint8_t has_rel_offs = 0;
    std::uint8_t rel_offs_length = 0;
    std::uint32_t relative_offset = 0;
    std::uint8_t is_rip_relative = 0;

    std::uint8_t branch_is_branch = 0;
    std::uint8_t branch_is_conditional = 0;
    std::uint8_t branch_is_indirect = 0;
    std::uint8_t branch_is_far = 0;
    std::uint8_t rip_access = 0;
    std::uint8_t memory_access = 0;

    InsRole instruction = INSN_INVALID;
    CatRole category = CAT_INVALID;

    // Computed with each side's own ND_INS_* numbering: kananlib decides to
    // follow an instruction in place with
    // `Instruction >= ND_INS_JMPE && Instruction <= ND_INS_JMPNR`, so what
    // matters is membership in that window, not the role.
    std::uint8_t in_jmp_window = 0;
    std::uint8_t is_jcc_slot = 0;
    std::uint8_t is_jrcxz_slot = 0;

    std::uint8_t operands_count = 0;
    OpResult operands[10];

    // bddisasm's own text, NUL terminated.
    char mnemonic[32] = {};
};

} // namespace diff

extern "C" {
// Each returns true when it produced a result; false means "this decoder refused
// the bytes". Defined in ref.cpp and shim.cpp respectively.
bool diff_ref_decode(const std::uint8_t* code, std::uint64_t size, diff::Result* out);
bool diff_shim_decode(const std::uint8_t* code, std::uint64_t size, diff::Result* out);
}

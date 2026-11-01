// Decodes with shared/utility/bdshim and normalises the result into diff::Result.
// This is the only translation unit allowed to include the shim headers.
#include "common.h"

#include <cstring>

#include <bddisasm.h>

namespace {

diff::InsRole insn_role(ND_INS_CLASS value) {
    switch (value) {
    case ND_INS_INVALID: return diff::INSN_INVALID;
    case ND_INS_INC: return diff::INSN_INC;
    case ND_INS_DEC: return diff::INSN_DEC;
    case ND_INS_RETN: return diff::INSN_RETN;
    case ND_INS_RETF: return diff::INSN_RETF;
    case ND_INS_INT3: return diff::INSN_INT3;
    case ND_INS_INT: return diff::INSN_INT;
    case ND_INS_CALLNR: return diff::INSN_CALLNR;
    case ND_INS_CALLNI: return diff::INSN_CALLNI;
    case ND_INS_CALLFD: return diff::INSN_CALLFD;
    case ND_INS_CALLFI: return diff::INSN_CALLFI;
    case ND_INS_LEA: return diff::INSN_LEA;
    case ND_INS_CMP: return diff::INSN_CMP;
    case ND_INS_TEST: return diff::INSN_TEST;
    case ND_INS_MOV: return diff::INSN_MOV;
    case ND_INS_JMPNI: return diff::INSN_JMP_INDIRECT;
    case ND_INS_Jcc: return diff::INSN_JCC;
    case ND_INS_JrCXZ: return diff::INSN_JRCXZ;
    default: break;
    }

    if (value >= ND_INS_JMPE && value <= ND_INS_JMPNR) {
        return diff::INSN_JMP_DIRECT;
    }
    return diff::INSN_OTHER;
}

diff::CatRole cat_role(ND_INS_CATEGORY value) {
    switch (value) {
    case ND_CAT_INVALID: return diff::CAT_INVALID;
    case ND_CAT_ARITH: return diff::CAT_ARITH;
    case ND_CAT_LOGIC: return diff::CAT_LOGIC;
    case ND_CAT_DATAXFER: return diff::CAT_DATAXFER;
    case ND_CAT_COND_BR: return diff::CAT_COND_BR;
    case ND_CAT_UNCOND_BR: return diff::CAT_UNCOND_BR;
    case ND_CAT_CALL: return diff::CAT_CALL;
    case ND_CAT_RET: return diff::CAT_RET;
    case ND_CAT_INTERRUPT: return diff::CAT_INTERRUPT;
    case ND_CAT_NOP: return diff::CAT_NOP;
    case ND_CAT_SYSTEM: return diff::CAT_SYSTEM;
    default: return diff::CAT_OTHER;
    }
}

diff::OpRole op_role(ND_OPERAND_TYPE value) {
    switch (value) {
    case ND_OP_NOT_PRESENT: return diff::OP_NOT_PRESENT;
    case ND_OP_REG: return diff::OP_REG;
    case ND_OP_MEM: return diff::OP_MEM;
    case ND_OP_IMM: return diff::OP_IMM;
    case ND_OP_OFFS: return diff::OP_REL_OFFS;
    case ND_OP_ADDR: return diff::OP_ADDR;
    case ND_OP_CONST: return diff::OP_CONST;
    case ND_OP_BANK: return diff::OP_BANK;
    default: return diff::OP_NOT_PRESENT;
    }
}

diff::RegRole reg_role(ND_REG_TYPE value) {
    switch (value) {
    case ND_REG_NOT_PRESENT: return diff::REG_NOT_PRESENT;
    case ND_REG_GPR: return diff::REG_GPR;
    case ND_REG_SEG: return diff::REG_SEG;
    case ND_REG_FPU: return diff::REG_FPU;
    case ND_REG_MMX: return diff::REG_MMX;
    case ND_REG_SSE: return diff::REG_SSE;
    case ND_REG_CR: return diff::REG_CR;
    case ND_REG_DR: return diff::REG_DR;
    case ND_REG_TR: return diff::REG_TR;
    default: return diff::REG_OTHER;
    }
}

} // namespace

extern "C" bool diff_shim_decode(const std::uint8_t* code, std::uint64_t size, diff::Result* out) {
    INSTRUX ix{};
    const auto status = NdDecodeEx(&ix, code, size, ND_CODE_64, ND_DATA_64);
    if (!ND_SUCCESS(status)) {
        return false;
    }

    out->ok = true;
    out->length = ix.Length;
    out->primary_opcode = ix.PrimaryOpCode;

    out->has_modrm = ix.HasModRm;
    out->has_lock = ix.HasLock;
    out->has_disp = ix.HasDisp;
    out->disp_length = ix.DispLength;
    out->displacement = ix.Displacement;

    out->has_imm1 = ix.HasImm1;
    out->imm1_length = ix.Imm1Length;
    out->immediate1 = ix.Immediate1;

    out->has_rel_offs = ix.HasRelOffs;
    out->rel_offs_length = ix.RelOffsLength;
    out->relative_offset = ix.RelativeOffset;
    out->is_rip_relative = ix.IsRipRelative;

    out->branch_is_branch = ix.BranchInfo.IsBranch;
    out->branch_is_conditional = ix.BranchInfo.IsConditional;
    out->branch_is_indirect = ix.BranchInfo.IsIndirect;
    out->branch_is_far = ix.BranchInfo.IsFar;
    out->rip_access = ix.RipAccess;
    out->memory_access = ix.MemoryAccess;

    out->instruction = insn_role(ix.Instruction);
    out->category = cat_role(ix.Category);

    out->in_jmp_window = (ix.Instruction >= ND_INS_JMPE && ix.Instruction <= ND_INS_JMPNR);
    out->is_jcc_slot = ix.Instruction == ND_INS_Jcc;
    out->is_jrcxz_slot = ix.Instruction == ND_INS_JrCXZ;

    out->operands_count = ix.OperandsCount;
    for (std::uint8_t i = 0; i < ix.OperandsCount && i < 10; ++i) {
        const ND_OPERAND& src = ix.Operands[i];
        diff::OpResult& dst = out->operands[i];

        dst.type = op_role(src.Type);
        dst.size = src.Size;
        dst.raw_size = src.RawSize;

        switch (src.Type) {
        case ND_OP_MEM:
            dst.mem_has_base = src.Info.Memory.HasBase;
            dst.mem_base = src.Info.Memory.Base;
            dst.mem_has_index = src.Info.Memory.HasIndex;
            dst.mem_index = src.Info.Memory.Index;
            dst.mem_scale = src.Info.Memory.Scale;
            dst.mem_has_disp = src.Info.Memory.HasDisp;
            dst.mem_disp_size = src.Info.Memory.DispSize;
            dst.mem_disp = src.Info.Memory.Disp;
            dst.mem_is_rip_rel = src.Info.Memory.IsRipRel;
            break;
        case ND_OP_REG:
            dst.reg_type = reg_role(src.Info.Register.Type);
            dst.reg = src.Info.Register.Reg;
            break;
        case ND_OP_IMM:
            dst.imm = src.Info.Immediate.Imm;
            break;
        case ND_OP_OFFS:
            dst.rel = src.Info.RelativeOffset.Rel;
            break;
        default:
            break;
        }
    }

    std::strncpy(out->mnemonic, ix.Mnemonic, sizeof(out->mnemonic) - 1);
    return true;
}

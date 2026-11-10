// bdshim.cpp - the bddisasm API surface, backed by rfw::scan::decode().
//
// See bddisasm.h for what is faithful and what is deliberately approximate.
// The rule followed throughout: everything some caller in this repository
// reads is reproduced as bddisasm would report it, verified by
// tools/bdshim_diff over the whole of re4.exe; everything else is left zero.
#include "bddisasm.h"
#include "bdshemu.h"

#include "../ScanSelf.hpp"

#include <cstring>

namespace {

using rfw::scan::Insn;
using rfw::scan::Kind;

// ModRM reg field used as an opcode extension rather than a register. For these
// the second operand is never a register, and the reg field must be read as the
// raw 3 bits.
bool is_group_opcode(const Insn& insn) {
    if (insn.vex) {
        return insn.map == 1 && (insn.opcode == 0x71 || insn.opcode == 0x72 || insn.opcode == 0x73 ||
                                 insn.opcode == 0xae || insn.opcode == 0xc7);
    }

    if (insn.map == 0) {
        switch (insn.opcode) {
        case 0x80: case 0x81: case 0x83: case 0x8f:
        case 0xc0: case 0xc1: case 0xc6: case 0xc7:
        case 0xd0: case 0xd1: case 0xd2: case 0xd3:
        case 0xf6: case 0xf7: case 0xfe: case 0xff:
            return true;
        default:
            return false;
        }
    }

    if (insn.map == 1) {
        switch (insn.opcode) {
        case 0x00: case 0x01:
        case 0x18: case 0x19: case 0x1a: case 0x1b: case 0x1c: case 0x1d: case 0x1e: case 0x1f:
        case 0xae: case 0xba: case 0xc7:
            return true;
        default:
            return false;
        }
    }

    return false;
}

// True for the opcodes whose immediate form names the accumulator implicitly
// (add al, imm8 / cmp eax, imm32 / test al, imm8 / in al, imm8 ...). bddisasm
// lists that accumulator as operand 0, and IntegrityCheckBypass's `test`
// matcher requires exactly that: operands[0] is a GPR, operands[1] the mask.
bool has_accumulator_operand(const Insn& insn) {
    if (insn.vex || insn.map != 0) {
        return false;
    }

    const uint8_t op = insn.opcode;
    if (op >= 0x04 && op <= 0x3d) {
        return (op & 7) >= 4;
    }

    return op == 0xa8 || op == 0xa9 || (op >= 0xe4 && op <= 0xe7);
}

// bddisasm's [reg, r/m] vs [r/m, reg] operand order, for the encodings where the
// distinction is visible to a caller.
bool register_first(const Insn& insn) {
    if (!insn.has_modrm) {
        return false;
    }

    if (insn.vex || insn.map != 0) {
        // 0F/VEX forms are [reg, r/m] except for the stores.
        return !(insn.opcode == 0x11 || insn.opcode == 0x13 || insn.opcode == 0x29 || insn.opcode == 0x7f);
    }

    const uint8_t op = insn.opcode;
    if (op < 0x40) {
        return (op & 2) != 0;
    }
    if (op >= 0x38 && op <= 0x3b) {
        return (op & 2) != 0;
    }
    if (op >= 0x88 && op <= 0x8d) {
        return op == 0x8d || (op & 2) != 0;
    }
    if (op == 0x62 || op == 0x63) {
        return true;
    }

    return false;
}

// The REX.B / VEX.B bit. ScanSelf keeps the extended base for memory operands
// but not for the r/m register form, and a register-direct operand needs it as
// well: Memory.Base and Register.Reg both carry the extension so that they can
// index the GPR file directly.
bool rex_b(const Insn& insn, const ND_UINT8* code) {
    if (insn.has_rex) {
        return (insn.rex & 0x01) != 0;
    }
    if (insn.vex) {
        if (code[0] == 0xc4 || code[0] == 0x62) { // VEX3 / EVEX only encode B
            return (code[1] & 0x20) == 0;
        }
    }
    return false;
}

// VEX/EVEX implied prefix (pp), needed to tell VMOVUPS from VMOVUPD.
uint8_t vex_pp(const Insn& insn, const ND_UINT8* code) {
    if (!insn.vex) {
        return 0;
    }
    if (code[0] == 0xc5) {
        return code[1] & 3;
    }
    if (code[0] == 0xc4 || code[0] == 0x62) {
        return code[2] & 3;
    }
    return 0;
}

uint16_t register_size(const Insn& insn) {
    if ((insn.rex & 0x08) != 0) {
        return 8;
    }
    return insn.opsize ? 2 : 4;
}

void fill_register(ND_OPERAND& operand, ND_UINT32 reg, ND_UINT16 size) {
    operand.Type = ND_OP_REG;
    operand.Size = size;
    operand.RawSize = size;
    operand.Info.Register.Type = ND_REG_GPR;
    operand.Info.Register.Size = size;
    operand.Info.Register.Reg = reg;
    operand.Info.Register.Count = 1;
}

void fill_memory(ND_OPERAND& operand, const Insn& insn) {
    operand.Type = ND_OP_MEM;

    ND_OPDESC_MEMORY& mem = operand.Info.Memory;
    mem.HasBase = insn.has_base ? ND_TRUE : ND_FALSE;
    mem.HasIndex = insn.has_index ? ND_TRUE : ND_FALSE;
    mem.HasDisp = insn.disp_size != 0 ? ND_TRUE : ND_FALSE;
    mem.IsRipRel = insn.rip_operand ? ND_TRUE : ND_FALSE;
    mem.Base = insn.base;
    mem.Index = insn.index;
    mem.Scale = insn.has_index ? insn.scale : 0;
    mem.DispSize = insn.disp_size;
    // Sign extended, because resolve_displacement() does
    // `ip + Length + (intptr_t)Memory.Disp`.
    mem.Disp = insn.disp_size != 0 ? static_cast<ND_UINT64>(static_cast<ND_SINT64>(insn.disp)) : 0;
}

void fill_rm(ND_OPERAND& operand, const Insn& insn, const ND_UINT8* code) {
    if (insn.modrm_mod == 3) {
        fill_register(operand, static_cast<ND_UINT32>((insn.modrm & 7) | (rex_b(insn, code) ? 8 : 0)),
                      register_size(insn));
        return;
    }
    fill_memory(operand, insn);
}

void fill_immediate(ND_OPERAND& operand, ND_UINT64 value, ND_UINT8 size) {
    operand.Type = ND_OP_IMM;
    operand.Size = size;
    operand.RawSize = size;
    operand.Info.Immediate.Imm = value;
    operand.Info.Immediate.RawSize = size;
}

uint32_t read_u32(const ND_UINT8* p) {
    uint32_t value{};
    std::memcpy(&value, p, sizeof(value));
    return value;
}

} // namespace

extern "C" NDSTATUS NdDecodeEx(
    INSTRUX* out,
    const ND_UINT8* code,
    ND_SIZET size,
    ND_UINT8 def_code,
    ND_UINT8 def_data) {
    if (out == nullptr || code == nullptr || size == 0 || def_code != ND_CODE_64) {
        return ND_STATUS_INVALID_INSTRUX;
    }

    Insn insn{};
    if (!rfw::scan::decode(code, insn)) {
        return ND_STATUS_INVALID_INSTRUX;
    }

    *out = INSTRUX{};

    out->DefCode = def_code;
    out->DefData = def_data;
    out->DefStack = ND_STACK_64;

    out->Length = insn.len;
    out->PrimaryOpCode = insn.opcode;
    out->OpCodeBytes[0] = insn.map == 0 ? 0 : 0x0f;
    out->OpCodeBytes[1] = insn.opcode;

    out->HasModRm = insn.has_modrm ? ND_TRUE : ND_FALSE;
    out->HasSib = insn.has_sib ? ND_TRUE : ND_FALSE;
    out->HasLock = insn.lock ? ND_TRUE : ND_FALSE;
    out->HasOpSize = insn.opsize ? ND_TRUE : ND_FALSE;
    out->HasAddrSize = insn.addrsize ? ND_TRUE : ND_FALSE;
    out->HasRex = insn.has_rex ? ND_TRUE : ND_FALSE;
    out->HasEvex = (insn.vex && code[0] == 0x62) ? ND_TRUE : ND_FALSE;
    out->HasVex = (insn.vex && code[0] != 0x62) ? ND_TRUE : ND_FALSE;
    out->HasRepnzXacquireBnd = (insn.rep && code[0] == 0xf2) ? ND_TRUE : ND_FALSE;
    out->HasRepRepzXrelease = (insn.rep && code[0] == 0xf3) ? ND_TRUE : ND_FALSE;

    out->HasDisp = insn.disp_size != 0 ? ND_TRUE : ND_FALSE;
    out->DispLength = insn.disp_size;
    out->Displacement = static_cast<ND_UINT32>(insn.disp);
    out->SignDisp = insn.disp < 0 ? ND_TRUE : ND_FALSE;

    out->HasImm1 = insn.has_imm ? ND_TRUE : ND_FALSE;
    out->Imm1Length = insn.imm_size;
    out->Immediate1 = insn.imm;

    // A relative offset is the operand of exactly these encodings; the indirect
    // call/jmp forms carry a ModRM and are handled as memory operands below.
    const bool has_rel = insn.kind == Kind::Jcc ||
                         (insn.kind == Kind::Call && insn.map == 0 && insn.opcode == 0xe8) ||
                         (insn.kind == Kind::Jmp && insn.map == 0 && (insn.opcode == 0xe9 || insn.opcode == 0xeb));

    int32_t rel = 0;
    if (has_rel) {
        rel = insn.rel8 ? static_cast<int8_t>(code[insn.len - 1])
                        : static_cast<int32_t>(read_u32(code + insn.len - 4));
        out->HasRelOffs = ND_TRUE;
        out->RelOffsLength = insn.rel8 ? 1 : 4;
        out->RelativeOffset = insn.rel8 ? static_cast<ND_UINT32>(static_cast<ND_UINT8>(rel))
                                        : static_cast<ND_UINT32>(rel);
    }

    // bddisasm sets this for every relative branch as well as for RIP-relative
    // memory operands, and kananlib's walker gates branch following on it.
    out->IsRipRelative = (insn.rip_operand || has_rel) ? ND_TRUE : ND_FALSE;

    const uint8_t group = static_cast<uint8_t>((insn.modrm >> 3) & 7);
    const bool grouped = is_group_opcode(insn);
    // FF /3 and FF /5 are the far (inter-segment) indirect forms: bddisasm names
    // them CALLF and JMPF, and REContext's `Mnemonic == "CALL"` test relies on
    // that distinction.
    const bool far_call = insn.map == 0 && insn.opcode == 0xff && group == 3;
    const bool far_jmp = insn.map == 0 && insn.opcode == 0xff && group == 5;

    const bool is_branch = insn.kind == Kind::Call || insn.kind == Kind::Jmp || insn.kind == Kind::Jcc ||
                           insn.kind == Kind::IndCall || insn.kind == Kind::IndJmp;
    if (is_branch) {
        out->RipAccess = ND_ACCESS_WRITE;
        out->BranchInfo.IsBranch = 1;
        out->BranchInfo.IsConditional = insn.kind == Kind::Jcc ? 1 : 0;
        // bddisasm derives IsIndirect from the presence of a ModRM.
        out->BranchInfo.IsIndirect = insn.has_modrm ? 1 : 0;
        out->BranchInfo.IsFar = (far_call || far_jmp) ? 1 : 0;
    }

    const char* mnemonic = "X";
    ND_INS_CLASS ins_class = ND_INS_OTHER;
    ND_INS_CATEGORY category = ND_CAT_OTHER;

    switch (insn.kind) {
    case Kind::Call:
        mnemonic = "CALL";
        ins_class = ND_INS_CALLNR;
        category = ND_CAT_CALL;
        break;
    case Kind::IndCall:
        mnemonic = far_call ? "CALLF" : "CALL";
        ins_class = far_call ? ND_INS_CALLFI : ND_INS_CALLNI;
        category = ND_CAT_CALL;
        break;
    case Kind::Jmp:
        mnemonic = "JMP";
        ins_class = insn.rel8 ? ND_INS_JMPE : ND_INS_JMPNR;
        category = ND_CAT_UNCOND_BR;
        break;
    case Kind::IndJmp:
        mnemonic = far_jmp ? "JMPF" : "JMP";
        ins_class = far_jmp ? ND_INS_JMPFI : ND_INS_JMPNI;
        category = ND_CAT_UNCOND_BR;
        break;
    case Kind::Jcc:
        if (insn.map == 0 && insn.opcode >= 0xe0 && insn.opcode <= 0xe3) {
            mnemonic = "JRCXZ";
            ins_class = ND_INS_JrCXZ;
        } else {
            mnemonic = "JCC";
            ins_class = ND_INS_Jcc;
        }
        category = ND_CAT_COND_BR;
        break;
    case Kind::Ret:
        mnemonic = "RETN";
        ins_class = ND_INS_RETN;
        category = ND_CAT_RET;
        break;
    case Kind::Int3:
        mnemonic = "INT3";
        ins_class = ND_INS_INT3;
        category = ND_CAT_INTERRUPT;
        break;
    case Kind::Other:
        break;
    }

    ND_UINT8 count = 0;

    if (has_rel) {
        ND_OPERAND& operand = out->Operands[0];
        operand.Type = ND_OP_OFFS;
        operand.Size = 8;
        operand.RawSize = insn.rel8 ? 1 : 4;
        operand.Info.RelativeOffset.Rel = static_cast<ND_UINT64>(static_cast<ND_SINT64>(rel));
        operand.Info.RelativeOffset.RawSize = insn.rel8 ? 1 : 4;
        count = 1;
    } else {
        if (insn.has_modrm) {
            if (grouped) {
                fill_rm(out->Operands[0], insn, code);
                count = 1;
            } else if (register_first(insn)) {
                fill_register(out->Operands[0], insn.modrm_reg, register_size(insn));
                fill_rm(out->Operands[1], insn, code);
                count = 2;
            } else {
                fill_rm(out->Operands[0], insn, code);
                fill_register(out->Operands[1], insn.modrm_reg, register_size(insn));
                count = 2;
            }
        } else if (insn.has_imm && has_accumulator_operand(insn)) {
            fill_register(out->Operands[0], 0, register_size(insn));
            count = 1;
        }

        if (insn.has_imm) {
            fill_immediate(out->Operands[count++], insn.imm, insn.imm_size);
        }
    }

    out->OperandsCount = count;
    out->ExpOperandsCount = count;

    if (insn.kind == Kind::Other) {
        const uint8_t op = insn.opcode;

        if (insn.map == 0) {
            switch (op) {
            case 0x38: case 0x39: case 0x3a: case 0x3b: case 0x3c: case 0x3d:
                mnemonic = "CMP";
                ins_class = ND_INS_CMP;
                category = ND_CAT_ARITH;
                break;
            case 0x80: case 0x81: case 0x82: case 0x83:
                if (group == 7) {
                    mnemonic = "CMP";
                    ins_class = ND_INS_CMP;
                    category = ND_CAT_ARITH;
                }
                break;
            case 0x84: case 0x85: case 0xa8: case 0xa9:
                mnemonic = "TEST";
                ins_class = ND_INS_TEST;
                category = ND_CAT_LOGIC;
                break;
            case 0xf6: case 0xf7:
                if (group < 2) {
                    mnemonic = "TEST";
                    ins_class = ND_INS_TEST;
                    category = ND_CAT_LOGIC;
                }
                break;
            case 0x88: case 0x89: case 0x8a: case 0x8b:
                mnemonic = "MOV";
                ins_class = ND_INS_MOV;
                category = ND_CAT_DATAXFER;
                break;
            case 0x8d:
                mnemonic = "LEA";
                ins_class = ND_INS_LEA;
                category = ND_CAT_DATAXFER;
                break;
            case 0x90:
                mnemonic = "NOP";
                category = ND_CAT_NOP;
                break;
            case 0xc2: case 0xc3:
                mnemonic = "RETN";
                ins_class = ND_INS_RETN;
                category = ND_CAT_RET;
                break;
            case 0xca: case 0xcb:
                mnemonic = "RETF";
                ins_class = ND_INS_RETF;
                category = ND_CAT_RET;
                break;
            case 0xcc:
                mnemonic = "INT3";
                ins_class = ND_INS_INT3;
                category = ND_CAT_INTERRUPT;
                break;
            case 0xcd:
                mnemonic = "INT";
                ins_class = ND_INS_INT;
                category = ND_CAT_INTERRUPT;
                break;
            case 0xfe: case 0xff:
                if (group == 0) {
                    mnemonic = "INC";
                    ins_class = ND_INS_INC;
                    category = ND_CAT_ARITH;
                } else if (group == 1) {
                    mnemonic = "DEC";
                    ins_class = ND_INS_DEC;
                    category = ND_CAT_ARITH;
                }
                break;
            default:
                break;
            }
        } else if (insn.vex && insn.map == 1) {
            const uint8_t pp = vex_pp(insn, code);

            switch (insn.opcode) {
            case 0x10: case 0x11:
                switch (pp) {
                case 0: mnemonic = "VMOVUPS"; break;
                case 1: mnemonic = "VMOVUPD"; break;
                case 2: mnemonic = "VMOVSS"; break;
                default: mnemonic = "VMOVSD"; break;
                }
                category = ND_CAT_DATAXFER;
                break;
            case 0x28: case 0x29:
                mnemonic = pp == 0 ? "VMOVAPS" : "VMOVAPD";
                category = ND_CAT_DATAXFER;
                break;
            default:
                break;
            }
        }
    }

    std::strncpy(out->Mnemonic, mnemonic, sizeof(out->Mnemonic) - 1);
    out->Instruction = ins_class;
    out->Category = category;

    // Only used by utility::emulate's writes_to_memory hint, which this build
    // never links; keep it conservative rather than wrong.
    for (ND_UINT8 i = 0; i < count; ++i) {
        if (out->Operands[i].Type != ND_OP_MEM) {
            continue;
        }
        const bool read_only = ins_class == ND_INS_CMP || ins_class == ND_INS_TEST || ins_class == ND_INS_LEA;
        out->MemoryAccess = read_only || i != 0 ? ND_ACCESS_READ : ND_ACCESS_ANY_WRITE;
        break;
    }

    return ND_STATUS_SUCCESS;
}

extern "C" SHEMU_STATUS ShemuEmulate(SHEMU_CONTEXT* context) {
    (void)context;
    return SHEMU_STATUS_NOT_SUPPORTED;
}

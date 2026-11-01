// bdshim_text.cpp - NdToText, the one piece of bddisasm's formatter this build
// needs.
//
// shared/sdk/ResourceManager.cpp:241 renders a single instruction to text,
// lowercases it, collapses repeated spaces and then tests the result for a
// "lock" prefix or a "lea rcx, [" prefix. That is the entire consumer, so this
// implements operand rendering only as far as those two tests reach: register
// names sized to the operand, "[base+index*scale+0xdisp]" for memory and
// "0x..." for immediates and relative offsets. Everything bddisasm does beyond
// that (decorators, segment overrides in the text, broadcast prefixes, string
// operand annotations) is not reproduced.
//
// Kept in its own translation unit so the text tables stay out of bdshim.cpp,
// which is on the cold path of nothing but still benefits from being small.
#include "bddisasm.h"

#include <cstdio>
#include <cstring>

namespace {

const char* const k_gpr64[16] = {"rax", "rcx", "rdx", "rbx", "rsp", "rbp", "rsi", "rdi",
                                 "r8",  "r9",  "r10", "r11", "r12", "r13", "r14", "r15"};
const char* const k_gpr32[16] = {"eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi",
                                 "r8d", "r9d", "r10d", "r11d", "r12d", "r13d", "r14d", "r15d"};
const char* const k_gpr16[16] = {"ax", "cx", "dx", "bx", "sp", "bp", "si", "di",
                                 "r8w", "r9w", "r10w", "r11w", "r12w", "r13w", "r14w", "r15w"};
const char* const k_gpr8[16] = {"al", "cl", "dl", "bl", "spl", "bpl", "sil", "dil",
                                "r8b", "r9b", "r10b", "r11b", "r12b", "r13b", "r14b", "r15b"};

// Appends to a fixed buffer, always leaving room for the terminator, and reports
// how much of the requested text did not fit so the caller can stop early.
struct Writer {
    char* buffer;
    size_t capacity;
    size_t used = 0;

    bool full() const { return used + 1 >= capacity; }

    void append(const char* text) {
        if (full() || text == nullptr) {
            return;
        }

        size_t length = 0;
        while (text[length] != '\0' && used + length + 1 < capacity) {
            ++length;
        }

        std::memcpy(buffer + used, text, length);
        used += length;
        buffer[used] = '\0';
    }

    void append_char(char c) {
        if (full()) {
            return;
        }

        buffer[used++] = c;
        buffer[used] = '\0';
    }
};

void append_register(Writer& out, const ND_OPDESC_REGISTER& reg) {
    char text[32];

    switch (reg.Type) {
    case ND_REG_GPR:
        if (reg.Reg < 16) {
            const char* const* table = k_gpr32;
            if (reg.Size == 8) {
                table = k_gpr64;
            } else if (reg.Size == 2) {
                table = k_gpr16;
            } else if (reg.Size == 1) {
                table = k_gpr8;
            }

            out.append(table[reg.Reg]);
            return;
        }
        break;
    case ND_REG_SSE:
        std::snprintf(text, sizeof(text), "xmm%u", static_cast<unsigned>(reg.Reg));
        out.append(text);
        return;
    case ND_REG_MMX:
        std::snprintf(text, sizeof(text), "mm%u", static_cast<unsigned>(reg.Reg));
        out.append(text);
        return;
    case ND_REG_SEG: {
        static const char* const segments[6] = {"es", "cs", "ss", "ds", "fs", "gs"};
        if (reg.Reg < 6) {
            out.append(segments[reg.Reg]);
            return;
        }
        break;
    }
    case ND_REG_CR:
        std::snprintf(text, sizeof(text), "cr%u", static_cast<unsigned>(reg.Reg));
        out.append(text);
        return;
    case ND_REG_DR:
        std::snprintf(text, sizeof(text), "dr%u", static_cast<unsigned>(reg.Reg));
        out.append(text);
        return;
    default:
        break;
    }

    std::snprintf(text, sizeof(text), "reg%u", static_cast<unsigned>(reg.Reg));
    out.append(text);
}

// A displacement always prints with an explicit sign, using the absolute value:
// bddisasm writes "[rdx-0x10]", never "[rdx+-0x10]".
void append_displacement(Writer& out, const ND_OPDESC_MEMORY& mem) {
    char text[32];

    const auto disp = static_cast<long long>(mem.Disp);
    unsigned long long magnitude = static_cast<unsigned long long>(disp < 0 ? -disp : disp);

    std::snprintf(text, sizeof(text), "%s0x%llX", disp < 0 ? "-" : "+", magnitude);
    out.append(text);
}

void append_memory(Writer& out, const ND_OPDESC_MEMORY& mem) {
    out.append_char('[');

    if (mem.IsRipRel) {
        out.append("rip");
    } else if (mem.HasBase) {
        const ND_OPDESC_REGISTER base{ND_REG_GPR, 8, mem.Base, 1};
        append_register(out, base);
    }

    if (mem.HasIndex) {
        const ND_OPDESC_REGISTER index{ND_REG_GPR, 8, mem.Index, 1};
        out.append_char('+');
        append_register(out, index);
        if (mem.Scale > 1) {
            out.append_char('*');
            out.append_char(static_cast<char>('0' + mem.Scale));
        }
    }

    if (mem.HasDisp) {
        append_displacement(out, mem);
    }

    out.append_char(']');
}

} // namespace

extern "C" NDSTATUS NdToText(const INSTRUX* Instrux, ND_UINT64 Rip, ND_UINT32 BufferSize, char* Buffer) {
    if (Instrux == nullptr || Buffer == nullptr || BufferSize == 0) {
        return ND_STATUS_BUFFER_TOO_SMALL;
    }

    Writer out{Buffer, BufferSize};
    Buffer[0] = '\0';

    if (Instrux->HasLock) {
        out.append("lock ");
    }

    // Mnemonic was already chosen by NdDecodeEx and is upper case, matching
    // bddisasm's own rendering before the caller lowercases it.
    out.append(Instrux->Mnemonic);
    out.append_char(' ');

    // After a lock prefix bddisasm writes the operand list, but the caller's
    // "lock" test only looks at the leading token, so a missing operand list on
    // a truncated buffer stays harmless.
    for (ND_UINT8 i = 0; i < Instrux->OperandsCount && i < ND_MAX_OPERAND; ++i) {
        const ND_OPERAND& operand = Instrux->Operands[i];

        if (i != 0) {
            out.append(", ");
        }

        char text[32];

        switch (operand.Type) {
        case ND_OP_REG:
            append_register(out, operand.Info.Register);
            break;
        case ND_OP_MEM:
            append_memory(out, operand.Info.Memory);
            break;
        case ND_OP_IMM:
            std::snprintf(text, sizeof(text), "0x%llX", static_cast<unsigned long long>(operand.Info.Immediate.Imm));
            out.append(text);
            break;
        case ND_OP_OFFS:
            // bddisasm prints the resolved target as well as the raw offset; the
            // resolved form is the useful half.
            std::snprintf(text, sizeof(text), "0x%llX",
                          static_cast<unsigned long long>(Rip + Instrux->Length + static_cast<long long>(operand.Info.RelativeOffset.Rel)));
            out.append(text);
            break;
        case ND_OP_ADDR:
            out.append("far ptr");
            break;
        default:
            out.append("?");
            break;
        }

        if (out.full()) {
            return ND_STATUS_BUFFER_TOO_SMALL;
        }
    }

    // Trim the trailing separator a zero-operand instruction would otherwise
    // leave behind, then report overflow.
    if (out.used > 0 && out.buffer[out.used - 1] == ' ') {
        out.buffer[--out.used] = '\0';
    }

    return out.full() ? ND_STATUS_BUFFER_TOO_SMALL : ND_STATUS_SUCCESS;
}

// bddisasm.h - source-compatible stand-in for Bitdefender's bddisasm.
//
// Why this exists: bddisasm is ~585 KB of opcode tables in the final DLL, but
// the plugin only ever asks it for instruction length, branch kind, the
// RIP-relative displacement, a handful of operand shapes and a few mnemonics.
// shared/utility/ScanSelf.cpp already decodes exactly that. This header and
// bdshim.cpp expose the slice of the bddisasm API that kananlib and the plugin
// actually touch, backed by the self-made decoder, so both can be compiled
// unmodified and the library can be dropped.
//
// Fidelity contract - what is faithful and what is not:
//   * Length, PrimaryOpCode, HasModRm/HasSib/HasDisp/HasRelOffs/HasImm1,
//     Displacement, RelativeOffset, Immediate1, IsRipRelative, Category,
//     BranchInfo, MemoryAccess and the explicit operands follow bddisasm.
//     tools/bdshim_diff checks all of them instruction-for-instruction over
//     re4.exe against the real library.
//   * Mnemonic is only filled in for the literals some caller compares
//     against (see the table in bdshim.cpp); everything else decodes as "X".
//     This is deliberate: a full mnemonic table is most of the 585 KB. If you
//     add a call site that compares a new mnemonic, add it to the table.
//   * Everything else (formatting, attributes, flags, ISA sets, validation) is
//     absent. Do not reintroduce bddisasm callers that need it.
//
// The enumerations below are NOT numerically identical to bddisasm's: only the
// relations the callers depend on are preserved (ND_OP_*, ND_REG_GPR, and the
// ND_INS_JMPE..ND_INS_JMPNR window that must contain the unconditional direct
// jumps and nothing else). Never include this header together with the real
// bddisasm in one translation unit.
#pragma once

#include <cstddef>
#include <cstdint>

// ---------------------------------------------------------------------------
// Base types
// ---------------------------------------------------------------------------

typedef std::uint8_t ND_UINT8;
typedef std::uint16_t ND_UINT16;
typedef std::uint32_t ND_UINT32;
typedef std::uint64_t ND_UINT64;
typedef std::int8_t ND_SINT8;
typedef std::int16_t ND_SINT16;
typedef std::int32_t ND_SINT32;
typedef std::int64_t ND_SINT64;

typedef ND_UINT64 ND_SIZET;
typedef ND_UINT8 ND_BOOL;
typedef ND_UINT32 NDSTATUS;

#define ND_NULL ((void*)(0))
#define ND_TRUE 1
#define ND_FALSE 0

// Same shape as the original: success is anything without the top bit set.
#define ND_SUCCESS(status) ((status) < 0x80000000)
#define ND_STATUS_SUCCESS 0x00000000
#define ND_STATUS_INVALID_INSTRUX 0x80000001
#define ND_STATUS_BUFFER_TOO_SMALL 0x80000002

// ---------------------------------------------------------------------------
// Decode modes
// ---------------------------------------------------------------------------

#define ND_CODE_16 0
#define ND_CODE_32 1
#define ND_CODE_64 2

#define ND_DATA_16 0
#define ND_DATA_32 1
#define ND_DATA_64 2

#define ND_STACK_16 0
#define ND_STACK_32 1
#define ND_STACK_64 2

#define ND_MAX_INSTRUCTION_LEN 15
#define ND_MAX_OPERAND 10
#define ND_MAX_MNEMONIC_LENGTH 16

// ---------------------------------------------------------------------------
// Operand access masks (bddisasm values, kept bit-exact for callers that test
// MemoryAccess against ND_ACCESS_ANY_WRITE)
// ---------------------------------------------------------------------------

#define ND_ACCESS_NONE 0x00
#define ND_ACCESS_READ 0x01
#define ND_ACCESS_WRITE 0x02
#define ND_ACCESS_COND_READ 0x04
#define ND_ACCESS_COND_WRITE 0x08
#define ND_ACCESS_ANY_READ (ND_ACCESS_READ | ND_ACCESS_COND_READ)
#define ND_ACCESS_ANY_WRITE (ND_ACCESS_WRITE | ND_ACCESS_COND_WRITE)
#define ND_ACCESS_PREFETCH 0x10

// ---------------------------------------------------------------------------
// Enumerations
// ---------------------------------------------------------------------------

// GPR numbers, as bddisasm's registers.h defines them. These are the values the
// decoder puts in ND_OPDESC_REGISTER::Reg and ND_OPDESC_MEMORY::Base/Index, so
// IntegrityCheckBypass's "which register holds the patch version" switch can
// compare against them directly. Only the 64-bit block is needed; the 32/16/8-bit
// aliases, segment, control, debug and test-register blocks have no callers.
enum {
    NDR_RAX = 0, NDR_RCX, NDR_RDX, NDR_RBX, NDR_RSP, NDR_RBP, NDR_RSI, NDR_RDI,
    NDR_R8,      NDR_R9,  NDR_R10, NDR_R11, NDR_R12, NDR_R13, NDR_R14, NDR_R15,
};

// Order matches bddisasm's ND_OPERAND_TYPE.
typedef enum _ND_OPERAND_TYPE {
    ND_OP_NOT_PRESENT = 0,
    ND_OP_REG,
    ND_OP_MEM,
    ND_OP_IMM,
    ND_OP_OFFS, // relative offset (branches); Info.RelativeOffset
    ND_OP_ADDR,
    ND_OP_CONST,
    ND_OP_BANK,
} ND_OPERAND_TYPE;

// Order matches bddisasm's ND_REG_TYPE for the entries that exist here.
typedef enum _ND_REG_TYPE {
    ND_REG_NOT_PRESENT = 0,
    ND_REG_GPR,
    ND_REG_SEG,
    ND_REG_FPU,
    ND_REG_MMX,
    ND_REG_SSE,
    ND_REG_CR,
    ND_REG_DR,
    ND_REG_TR,
} ND_REG_TYPE;

// Instruction class. Only these are produced, and the values below 100 are
// arbitrary. What matters is the jump window: kananlib tests
// `Instruction >= ND_INS_JMPE && Instruction <= ND_INS_JMPNR` to mean "an
// unconditional direct jump, follow it in place". bddisasm happens to put Jcc
// and JrCXZ outside that range (capital M sorts before lowercase c), so the
// window must stay clear of them here too.
typedef enum _ND_INS_CLASS {
    ND_INS_INVALID = 0,
    ND_INS_OTHER = 1,
    ND_INS_INC = 2,
    ND_INS_DEC = 3,
    ND_INS_RETN = 4,
    ND_INS_RETF = 5,
    ND_INS_INT3 = 6,
    ND_INS_INT = 7,
    ND_INS_CALLNR = 8,  // direct near call
    ND_INS_CALLNI = 9,  // indirect near call
    ND_INS_CALLFD = 10, // far call, direct
    ND_INS_CALLFI = 11, // far call, indirect
    ND_INS_LEA = 12,
    ND_INS_CMP = 13,
    ND_INS_TEST = 14,
    ND_INS_MOV = 15,

    ND_INS_JMPE = 100,  // jmpe (0F 00 /6, 0F B8), the window's first member
    ND_INS_JMPFD = 101, // far jmp, direct (EA)
    ND_INS_JMPFI = 102, // far jmp, indirect (FF /5)
    ND_INS_JMPNI = 103, // jmp r/m (indirect, FF /4)
    ND_INS_JMPNR = 104, // jmp rel8/rel16/rel32

    ND_INS_Jcc = 110,   // 7x, 0f 8x
    ND_INS_JrCXZ = 111, // e0-e3
} ND_INS_CLASS;

typedef enum _ND_INS_CATEGORY {
    ND_CAT_INVALID = 0,
    ND_CAT_ARITH,
    ND_CAT_LOGIC,
    ND_CAT_DATAXFER,
    ND_CAT_COND_BR,
    ND_CAT_UNCOND_BR,
    ND_CAT_CALL,
    ND_CAT_RET,
    ND_CAT_INTERRUPT,
    ND_CAT_NOP,
    ND_CAT_SYSTEM,
    ND_CAT_OTHER,
} ND_INS_CATEGORY;

// ---------------------------------------------------------------------------
// Operand descriptors
// ---------------------------------------------------------------------------

typedef struct _ND_OPDESC_MEMORY {
    ND_BOOL HasSeg : 1;
    ND_BOOL HasBase : 1;
    ND_BOOL HasIndex : 1;
    ND_BOOL HasDisp : 1;
    ND_BOOL IsRipRel : 1;
    ND_BOOL IsStack : 1;
    ND_BOOL IsDirect : 1;

    ND_UINT8 DispSize; // 1, 2 or 4
    ND_UINT8 Seg;
    ND_UINT8 Base;  // GPR number, REX.B included
    ND_UINT8 Index; // GPR number, REX.X included
    ND_UINT8 Scale; // 1, 2, 4 or 8

    ND_UINT64 Disp; // sign extended
} ND_OPDESC_MEMORY;

typedef struct _ND_OPDESC_REGISTER {
    ND_REG_TYPE Type;
    ND_UINT16 Size; // bytes
    ND_UINT32 Reg;  // register number inside Type, REX.R included
    ND_UINT8 Count;
} ND_OPDESC_REGISTER;

typedef struct _ND_OPDESC_IMMEDIATE {
    ND_UINT64 Imm;
    ND_UINT8 RawSize;
} ND_OPDESC_IMMEDIATE;

typedef struct _ND_OPDESC_RELOFFSET {
    ND_UINT64 Rel; // sign extended
    ND_UINT8 RawSize;
} ND_OPDESC_RELOFFSET;

typedef struct _ND_OPERAND {
    ND_OPERAND_TYPE Type;
    ND_UINT16 Size;
    ND_UINT16 RawSize;
    ND_UINT8 Access;
    ND_UINT8 Flags;

    union {
        ND_OPDESC_IMMEDIATE Immediate;
        ND_OPDESC_REGISTER Register;
        ND_OPDESC_RELOFFSET RelativeOffset;
        ND_OPDESC_MEMORY Memory;
    } Info;
} ND_OPERAND, *PND_OPERAND;

typedef struct _ND_BRANCH_INFO {
    ND_UINT8 IsBranch : 1;
    ND_UINT8 IsConditional : 1;
    ND_UINT8 IsIndirect : 1;
    ND_UINT8 IsFar : 1;
} ND_BRANCH_INFO;

// ---------------------------------------------------------------------------
// INSTRUX - the slice the callers read. Field names match bddisasm so existing
// source keeps compiling; the fields bddisasm has and nobody reads are absent.
// ---------------------------------------------------------------------------

typedef struct _INSTRUX {
    ND_UINT8 DefCode; // ND_CODE_*
    ND_UINT8 DefData; // ND_DATA_*
    ND_UINT8 DefStack;
    ND_UINT8 VendMode;
    ND_UINT8 FeatMode;

    // Prefixes.
    ND_BOOL HasRex : 1;
    ND_BOOL HasVex : 1;
    ND_BOOL HasEvex : 1;
    ND_BOOL HasOpSize : 1;          // 0x66 present
    ND_BOOL HasAddrSize : 1;        // 0x67 present
    ND_BOOL HasLock : 1;            // 0xF0 present
    ND_BOOL HasRepnzXacquireBnd : 1; // 0xF2 present
    ND_BOOL HasRepRepzXrelease : 1;  // 0xF3 present
    ND_BOOL HasSeg : 1;

    // Indicators.
    // bddisasm sets this for any RIP-relative memory operand AND for every
    // relative branch (its NdFetchRelativeOffset sets it unconditionally), and
    // kananlib's walker gates branch following on it - so it must be set for
    // direct jmp/jcc/call too, not just for [rip+x] operands.
    ND_BOOL IsRipRelative : 1;

    // Components.
    ND_BOOL HasModRm : 1;
    ND_BOOL HasSib : 1;
    ND_BOOL HasDisp : 1;
    ND_BOOL HasImm1 : 1;
    ND_BOOL HasImm2 : 1;
    ND_BOOL HasRelOffs : 1;
    ND_BOOL SignDisp : 1;

    ND_UINT8 Length; // 1..15
    ND_UINT8 WordLength;
    ND_UINT8 PrefLength;
    ND_UINT8 OpLength;
    ND_UINT8 DispLength;
    ND_UINT8 Imm1Length;
    ND_UINT8 RelOffsLength;

    ND_UINT8 Rep;
    ND_UINT8 Seg;

    ND_UINT32 Displacement;   // raw, as encoded
    ND_UINT32 RelativeOffset; // raw, as encoded
    ND_UINT64 Immediate1;

    ND_UINT8 OperandsCount;
    ND_UINT8 ExpOperandsCount;
    ND_OPERAND Operands[ND_MAX_OPERAND];

    ND_UINT8 RipAccess;
    ND_UINT8 StackAccess;
    ND_UINT8 MemoryAccess;

    ND_BRANCH_INFO BranchInfo;

    ND_INS_CLASS Instruction;
    ND_INS_CATEGORY Category;

    char Mnemonic[ND_MAX_MNEMONIC_LENGTH];

    ND_UINT8 OpCodeBytes[3];
    ND_UINT8 PrimaryOpCode;
} INSTRUX, *PINSTRUX;

#ifdef __cplusplus
extern "C" {
#endif

// Decodes one instruction. Only ND_CODE_64 is supported: every call site in the
// plugin and in kananlib passes ND_CODE_64/ND_DATA_64 unconditionally.
NDSTATUS
NdDecodeEx(
    INSTRUX* Instrux,
    const ND_UINT8* Code,
    ND_SIZET Size,
    ND_UINT8 DefCode,
    ND_UINT8 DefData);

// Renders an instruction back to text. Produces "<mnemonic> <op0>, <op1>, ..."
// with a leading "lock " when the LOCK prefix is present, operands as register
// names, "[base+index*scale+0xdisp]" for memory and "0x..." for immediates and
// relative offsets. That is enough for the one caller
// (shared/sdk/ResourceManager.cpp, which lowercases the result, collapses
// spaces and tests for "lock" / "lea rcx, ["), and it is deliberately not a
// cycle-accurate reimplementation of bddisasm's formatter.
NDSTATUS
NdToText(
    const INSTRUX* Instrux,
    ND_UINT64 Rip,
    ND_UINT32 BufferSize,
    char* Buffer);

#ifdef __cplusplus
}
#endif

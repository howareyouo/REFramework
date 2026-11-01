// bdshemu.h - compile-only stand-in for bddisasm's shellcode emulator.
//
// kananlib/src/Emulation.cpp includes <bdshemu.h> and builds a SHEMU_CONTEXT,
// but the plugin never calls utility::emulate(), so that translation unit is
// never pulled into the link and nothing here runs. It exists so the build does
// not need the emulator (which is another ~120 KB of tables) at all.
//
// If something ever does call utility::emulate(), ShemuEmulate() returns
// SHEMU_STATUS_NOT_SUPPORTED and the caller's error path takes over - it will
// not silently produce wrong results.
#pragma once

#include "bddisasm.h"

#define ND_MAX_MMX_REGS 8
#define ND_MAX_SSE_REGS 16
#define ND_MAX_REGISTER_SIZE 64

typedef ND_UINT64 NDR_RFLAGS;

#define NDR_RFLAG_IF 0x0200

typedef struct _SHEMU_SEG {
    ND_UINT64 Base;
    ND_UINT64 Limit;
    ND_UINT64 Selector;
    ND_UINT64 AccessRights;
} SHEMU_SEG, *PSHEMU_SEG;

typedef struct _SHEMU_SEG_REGS {
    SHEMU_SEG Es;
    SHEMU_SEG Cs;
    SHEMU_SEG Ss;
    SHEMU_SEG Ds;
    SHEMU_SEG Fs;
    SHEMU_SEG Gs;
} SHEMU_SEG_REGS, *PSHEMU_SEG_REGS;

typedef struct _SHEMU_GPR_REGS {
    ND_UINT64 RegRax;
    ND_UINT64 RegRcx;
    ND_UINT64 RegRdx;
    ND_UINT64 RegRbx;
    ND_UINT64 RegRsp;
    ND_UINT64 RegRbp;
    ND_UINT64 RegRsi;
    ND_UINT64 RegRdi;
    ND_UINT64 RegR8;
    ND_UINT64 RegR9;
    ND_UINT64 RegR10;
    ND_UINT64 RegR11;
    ND_UINT64 RegR12;
    ND_UINT64 RegR13;
    ND_UINT64 RegR14;
    ND_UINT64 RegR15;
    ND_UINT64 RegCr2;
    ND_UINT64 RegFlags;
    ND_UINT64 RegDr7;
    ND_UINT64 RegRip;
    ND_UINT64 RegCr0;
    ND_UINT64 RegCr4;
} SHEMU_GPR_REGS, *PSHEMU_GPR_REGS;

typedef void (*ShemuPrint)(void* Context, const char* Format, ...);

typedef ND_BOOL (*ShemuMemAccess)(
    void* ShemuContext,
    ND_UINT64 Gla,
    ND_SIZET Size,
    ND_UINT8* Buffer,
    ND_BOOL Store);

typedef unsigned int SHEMU_STATUS;

#define SHEMU_SUCCESS 0x00000000
#define SHEMU_STATUS_NOT_SUPPORTED 0x80000001

#define SHEMU_DEFAULT_NOP_THRESHOLD 75
#define SHEMU_DEFAULT_STR_THRESHOLD 8
#define SHEMU_DEFAULT_MEM_THRESHOLD 8

typedef struct _SHEMU_CONTEXT {
    INSTRUX Instruction;
    SHEMU_GPR_REGS Registers;
    SHEMU_SEG_REGS Segments;

    ND_UINT8 Mode;
    ND_UINT8 Ring;

    ND_UINT8* Shellcode;
    ND_UINT8* Stack;
    ND_UINT8* Intbuf;

    ND_UINT64 ShellcodeBase;
    ND_UINT64 StackBase;

    ND_UINT32 ShellcodeSize;
    ND_UINT32 StackSize;
    ND_UINT32 IntbufSize;

    ND_UINT32 InstructionsCount;
    ND_UINT32 MaxInstructionsCount;

    ND_UINT64 TibBase;
    ND_UINT64 Flags;
    ND_UINT32 Options;

    ND_UINT32 NopThreshold;
    ND_UINT32 StrThreshold;
    ND_UINT32 MemThreshold;

    void* AuxData;
    ShemuPrint Log;
    ShemuMemAccess AccessMemory;
} SHEMU_CONTEXT, *PSHEMU_CONTEXT;

#ifdef __cplusplus
extern "C" {
#endif

SHEMU_STATUS
ShemuEmulate(
    SHEMU_CONTEXT* Context);

#ifdef __cplusplus
}
#endif

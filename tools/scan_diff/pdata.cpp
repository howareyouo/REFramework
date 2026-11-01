// .pdata-scoped differential test: only real function bodies.
#include <windows.h>
#include <bddisasm.h>

#include <cstdio>
#include <cstring>
#include <vector>

#include "ScanSelf.hpp"

extern "C" void* nd_memset(void* s, int c, unsigned long long n) { return memset(s, c, (size_t)n); }

int main(int argc, char** argv) {
    FILE* f = fopen(argv[1], "rb");
    fseek(f, 0, SEEK_END);
    long long sz = _ftelli64(f);
    fseek(f, 0, SEEK_SET);
    std::vector<uint8_t> img((size_t)sz);
    fread(img.data(), 1, img.size(), f);
    fclose(f);

    auto* dos = (PIMAGE_DOS_HEADER)img.data();
    auto* nt = (PIMAGE_NT_HEADERS64)(img.data() + dos->e_lfanew);
    auto* sec = IMAGE_FIRST_SECTION(nt);

    auto rva_to_off = [&](DWORD rva) -> size_t {
        for (int i = 0; i < nt->FileHeader.NumberOfSections; ++i) {
            if (rva >= sec[i].VirtualAddress && rva < sec[i].VirtualAddress + sec[i].Misc.VirtualSize)
                return sec[i].PointerToRawData + (rva - sec[i].VirtualAddress);
        }
        return 0;
    };

    auto* dir = &nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXCEPTION];
    if (!dir->VirtualAddress) {
        printf("no exception dir\n");
        return 1;
    }

    size_t base_off = rva_to_off(dir->VirtualAddress);
    auto* rf = (PIMAGE_RUNTIME_FUNCTION_ENTRY)(img.data() + base_off);
    size_t count = dir->Size / sizeof(IMAGE_RUNTIME_FUNCTION_ENTRY);

    size_t insns = 0, fails = 0, lens = 0, reported = 0, fns = 0;
    for (size_t i = 0; i < count; ++i) {
        DWORD b = rf[i].BeginAddress, e = rf[i].EndAddress;
        if (b == 0 || e <= b) continue;
        size_t off = rva_to_off(b), end = rva_to_off(e);
        if (!off || !end || end <= off || end > img.size()) continue;
        ++fns;
        while (off + 16 <= end) {
            const uint8_t* p = img.data() + off;
            INSTRUX ix{};
            auto st = NdDecodeEx(&ix, p, 64, ND_CODE_64, ND_DATA_64);
            rfw::scan::Insn insn{};
            bool ok = rfw::scan::decode(p, insn);
            ++insns;
            if (!ND_SUCCESS(st)) break;
            if (!ok || insn.len != ix.Length) {
                if (!ok) ++fails; else ++lens;
                if (reported < 40) {
                    printf("[%s] fn=0x%lX off=0x%zX ours=%u bdd=%u bytes=%02X %02X %02X %02X %02X %02X %02X %02X\n",
                           ok ? "len" : "fail", (unsigned long)b, off, ok ? insn.len : 0, ix.Length,
                           p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7]);
                    ++reported;
                }
            }
            off += ix.Length;
        }
    }

    printf("\n[pdata] functions=%zu insns=%zu ours_fail=%zu (%.5f%%) len_mismatch=%zu (%.5f%%)\n", fns, insns,
           fails, 100.0 * (double)fails / (double)(insns ? insns : 1), lens,
           100.0 * (double)lens / (double)(insns ? insns : 1));
    return 0;
}

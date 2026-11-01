// Differential test: bddisasm vs the self-made decoder in src/scan.cpp.
// Sequential decode of a whole PE .text section, compare instruction lengths.

#include <windows.h>
#include <bddisasm.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

#include "ScanSelf.hpp"

static std::vector<uint8_t> read_file(const char* path) {
    FILE* f = fopen(path, "rb");
    if (!f) {
        printf("cannot open %s\n", path);
        exit(1);
    }
    fseek(f, 0, SEEK_END);
    long long sz = _ftelli64(f);
    fseek(f, 0, SEEK_SET);
    std::vector<uint8_t> buf((size_t)sz);
    if (fread(buf.data(), 1, buf.size(), f) != buf.size()) {
        printf("short read\n");
        exit(1);
    }
    fclose(f);
    return buf;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("usage: diff <pe>\n");
        return 1;
    }

    auto img = read_file(argv[1]);
    printf("loaded %s: %zu bytes\n", argv[1], img.size());

    auto* dos = (PIMAGE_DOS_HEADER)img.data();
    if (dos->e_magic != IMAGE_DOS_SIGNATURE) {
        printf("not a PE\n");
        return 1;
    }
    auto* nt = (PIMAGE_NT_HEADERS64)(img.data() + dos->e_lfanew);
    if (nt->Signature != IMAGE_NT_SIGNATURE) {
        printf("not PE32+\n");
        return 1;
    }

    auto* sec = IMAGE_FIRST_SECTION(nt);
    uint8_t* text = nullptr;
    size_t text_off = 0, text_size = 0;
    for (int i = 0; i < nt->FileHeader.NumberOfSections; ++i) {
        char name[9]{};
        memcpy(name, sec[i].Name, 8);
        if (strcmp(name, ".text") == 0) {
            text = img.data() + sec[i].PointerToRawData;
            text_off = sec[i].PointerToRawData;
            text_size = sec[i].Misc.VirtualSize;
            break;
        }
    }
    if (!text) {
        printf("no .text\n");
        return 1;
    }
    printf(".text: file offset 0x%zX virtual size 0x%zX\n", text_off, text_size);

    size_t total = 0, our_fail = 0, bdd_fail = 0, len_mismatch = 0;
    size_t reported = 0;
    const size_t kReport = 60;

    for (size_t off = 0; off + 64 <= text_size;) {
        const uint8_t* p = text + off;

        INSTRUX ix{};
        auto st = NdDecodeEx(&ix, p, 64, ND_CODE_64, ND_DATA_64);

        rfw::scan::Insn insn{};
        bool ours_ok = rfw::scan::decode(p, insn);

        ++total;

        if (!ND_SUCCESS(st)) {
            ++bdd_fail;
            // bddisasm gave up: our decoder must also give up, otherwise we would
            // happily walk over data that bddisasm refuses to decode.
            if (ours_ok && reported < kReport) {
                printf("[bdd-fail] off=0x%zX ours=%u bytes=%02X %02X %02X %02X %02X %02X %02X %02X\n",
                       off, insn.len, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7]);
                ++reported;
            }
            off += 1; // resync
            continue;
        }

        if (!ours_ok) {
            ++our_fail;
            if (reported < kReport) {
                printf("[ours-fail] off=0x%zX bdd_len=%u bytes=%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X\n",
                       off, ix.Length, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8], p[9], p[10],
                       p[11], p[12], p[13], p[14]);
                ++reported;
            }
            off += ix.Length;
            continue;
        }

        if (insn.len != ix.Length) {
            ++len_mismatch;
            if (reported < kReport) {
                printf("[len] off=0x%zX ours=%u bdd=%u bytes=%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X\n",
                       off, insn.len, ix.Length, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8], p[9],
                       p[10], p[11], p[12], p[13], p[14]);
                ++reported;
            }
            off += ix.Length;
            continue;
        }

        off += ix.Length;
    }

    printf("\ntotal=%zu ours_fail=%zu (%.4f%%) bdd_fail=%zu len_mismatch=%zu (%.4f%%)\n", total, our_fail,
           100.0 * (double)our_fail / (double)total, bdd_fail, len_mismatch,
           100.0 * (double)len_mismatch / (double)total);
    return 0;
}

extern "C" void* nd_memset(void* s, int c, unsigned long long n) { return memset(s, c, (size_t)n); }

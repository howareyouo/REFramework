import sys

def balance(path):
    src = open(path, encoding="utf-8", errors="ignore").read()
    depth = 0
    i = 0
    line = 1
    instr = False
    inc = None
    inlc = False
    inbc = False
    while i < len(src):
        c = src[i]
        if c == "\n":
            line += 1
        if instr:
            if c == "\\":
                i += 2
                continue
            if c == inc:
                instr = False
        elif inlc:
            if c == "\n":
                inlc = False
        elif inbc:
            if c == "*" and i + 1 < len(src) and src[i + 1] == "/":
                inbc = False
                i += 1
        elif c == '"' or c == "'":
            instr = True
            inc = c
        elif c == "/" and i + 1 < len(src) and src[i + 1] == "/":
            inlc = True
            i += 1
        elif c == "/" and i + 1 < len(src) and src[i + 1] == "*":
            inbc = True
            i += 1
        elif c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
        i += 1
    return depth

for path in sys.argv[1:]:
    d = balance(path)
    if d != 0:
        print(f"{d:+d} {path}")
print("check done")

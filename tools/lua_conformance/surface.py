"""Compare the Lua-visible surface of the sol2 bindings against the hand-written ones.

The probes in this directory sample the API; this walks all of it. It reads the
binding sources at two revisions -- the sol2 baseline and the rewrite -- and
reports every name the baseline exposed that the rewrite does not, plus every
name the rewrite added. The first list has to be empty for the rewrite to be a
superset rather than a subset.

    python tools/lua_conformance/surface.py compare
    python tools/lua_conformance/surface.py compare --base 0321fe8e --head HEAD
    python tools/lua_conformance/surface.py verify --rev 0321fe8e

`compare` is pure source analysis and needs no game. `verify` takes the baseline
names and asks the running game for each one -- namespace members by lookup, and
usertype members by iterating a live instance -- which is what turns "nothing was
dropped" into a measurement instead of a reading of the source.
"""
import argparse
import importlib.util
import json
import re
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
REPO = HERE.parent.parent

# Every file that binds Lua names directly. ScriptRunner.cpp holds the re/thread/log
# tables, the math usertypes and REFramework; the four under bindings/ hold the rest.
FILES = [
    "src/mods/bindings/Sdk.cpp",
    "src/mods/bindings/ImGui.cpp",
    "src/mods/bindings/FS.cpp",
    "src/mods/bindings/Json.cpp",
    "src/mods/ScriptRunner.cpp",
]

# A usertype a revision publishes through the state itself lands in the globals.
GLOBALS = "_G"

STATE_RECEIVERS = {"lua", "m_lua", "sol_state", "sv", "s", "state", "L"}

# sol2's metamethod keys, in meta_function order as declared in sol/sol.hpp.
# Entries that hold no Lua key -- call_construct, storage, gc_names, static_index,
# static_new_index -- are left out, as is `next`.
META_FUNCTIONS = {
    "construct": "new",
    "index": "__index",
    "new_index": "__newindex",
    "mode": "__mode",
    "call": "__call",
    "call_function": "__call",
    "metatable": "__metatable",
    "to_string": "__tostring",
    "length": "__len",
    "unary_minus": "__unm",
    "addition": "__add",
    "subtraction": "__sub",
    "multiplication": "__mul",
    "division": "__div",
    "modulus": "__mod",
    "power_of": "__pow",
    "involution": "__pow",
    "concatenation": "__concat",
    "equal_to": "__eq",
    "less_than": "__lt",
    "less_than_or_equal_to": "__le",
    "garbage_collect": "__gc",
    "floor_division": "__idiv",
    "bitwise_left_shift": "__shl",
    "bitwise_right_shift": "__shr",
    "bitwise_not": "__bnot",
    "bitwise_and": "__band",
    "bitwise_or": "__bor",
    "bitwise_xor": "__bxor",
    "pairs": "__pairs",
    "ipairs": "__ipairs",
    "type": "__type",
    "type_info": "__typeinfo",
}

# A hand-written metatable names itself in __name, and the two not already named
# the way sol2 named them need the pair to line up with the baseline.
USERTYPE_ALIASES = {
    "ImGuiTableSortSpecs": "TableSortSpecs",
    "ImGuiTableColumnSortSpecs": "TableColumnSortSpecs",
}

# The rewrite generates its array bindings from one macro, so the members are not
# readable from the call site.
NEW_ARRAY_MACRO = "LUA_HAND_DYNAMIC_ARRAY"

MATH_NAMES = {
    "Vector2f": "Vector2f",
    "Vector3f": "Vector3f",
    "Vector4f": "Vector4f",
    "Matrix4x4f": "Matrix4x4f",
    "glm::quat": "Quaternion",
}

# A Lua expression per usertype that yields a live instance to iterate. Types
# absent here are compared from the source only, which `verify` reports.
INSTANCES = {
    "RETypeDefinition": 'sdk.find_type_definition("via.vec2")',
    "REMethodDefinition": 'sdk.find_type_definition("via.vec2"):get_methods()[1]',
    "REField": 'sdk.find_type_definition("via.vec2"):get_fields()[1]',
    "REProperty": 'sdk.find_type_definition("via.vec2"):get_properties()[1]',
    "REManagedObject": 'sdk.get_managed_singleton("app.SingletonManager")',
    "SystemArray": 'sdk.create_managed_array(sdk.find_type_definition("System.Int32"), 2)',
    "ValueType": 'ValueType(sdk.find_type_definition("System.Int32"))',
    "MemoryView": "sdk.to_memoryview(sdk.to_ptr(1), 16)",
    "Vector2f": "Vector2f.new(1.0, 2.0)",
    "Vector3f": "Vector3f.new(1.0, 2.0, 3.0)",
    "Vector4f": "Vector4f.new(1.0, 2.0, 3.0, 4.0)",
    "Matrix4x4f": "Matrix4x4f.new()",
    "Quaternion": "Quaternion.new()",
    "REFramework": "reframework",
}


def show(rev, path):
    # `WORKTREE` reads the file as it is on disk, so an uncommitted change to a
    # binding can be compared before it goes through a build.
    if rev == "WORKTREE":
        file = REPO / path
        return file.read_text(encoding="utf-8", errors="replace") if file.is_file() else ""

    out = subprocess.run(["git", "show", "%s:%s" % (rev, path)], cwd=str(REPO),
                         capture_output=True, text=True, encoding="utf-8", errors="replace")
    if out.returncode != 0:
        sys.exit("git show %s:%s failed: %s" % (rev, path, out.stderr.strip()))
    return out.stdout


def mask(src):
    """Blanks comments while keeping every other character at its index."""
    out = list(src)
    i, n = 0, len(src)

    while i < n:
        c = src[i]

        if c in "\"'":
            quote = c
            i += 1
            while i < n:
                if src[i] == "\\":
                    i += 2
                    continue
                if src[i] == quote:
                    i += 1
                    break
                i += 1
            continue

        if c == "/" and i + 1 < n and src[i + 1] == "/":
            while i < n and src[i] != "\n":
                out[i] = " "
                i += 1
            continue

        if c == "/" and i + 1 < n and src[i + 1] == "*":
            out[i] = out[i + 1] = " "
            i += 2
            while i < n and not (src[i] == "*" and i + 1 < n and src[i + 1] == "/"):
                if src[i] != "\n":
                    out[i] = " "
                i += 1
            if i < n:
                out[i] = out[i + 1] = " "
                i += 2
            continue

        i += 1

    return "".join(out)


GROUP_CLOSE = {")": "(", "]": "[", "}": "{", ">": "<"}


def skip_group(src, start):
    """Index just past the group opened at src[start], nested groups included."""
    stack = [src[start]]
    i, n = start + 1, len(src)

    while i < n:
        c = src[i]

        if c in "\"'":
            quote = c
            i += 1
            while i < n:
                if src[i] == "\\":
                    i += 2
                    continue
                if src[i] == quote:
                    i += 1
                    break
                i += 1
            continue

        # A '<' only opens a group while the stack holds nothing but '<', which
        # keeps the comparison operators inside a lambda body from being read as
        # template arguments.
        if c == "<" and all(o == "<" for o in stack):
            stack.append(c)
        elif c in "([{":
            stack.append(c)
        elif c in ")]}>":
            if stack and stack[-1] == GROUP_CLOSE[c]:
                stack.pop()
                if not stack:
                    return i + 1

        i += 1

    raise ValueError("unbalanced group at %d" % start)


def split_top(text):
    """Splits on commas that sit outside every group."""
    out, depth, start, i, n = [], 0, 0, 0, len(text)

    while i < n:
        c = text[i]

        if c in "\"'":
            quote = c
            i += 1
            while i < n:
                if text[i] == "\\":
                    i += 2
                    continue
                if text[i] == quote:
                    i += 1
                    break
                i += 1
            continue

        # < and > are left alone: a comparison inside a lambda body unbalances a
        # count, and the only names taken out of an argument are bare literals.
        if c in "([{":
            depth += 1
        elif c in ")]}":
            depth -= 1
        elif c == "," and depth == 0:
            out.append(text[start:i])
            start = i + 1

        i += 1

    out.append(text[start:])
    return out


STRING = re.compile(r'^"((?:[^"\\]|\\.)*)"$')


def string_value(expr):
    m = STRING.match(expr.strip())
    return m.group(1) if m else None


def leading_strings(text):
    """The string literals that sit in a key position of a comma separated list."""
    return [v for v in (string_value(arg) for arg in split_top(text)) if v is not None]


def macro_bodies(src):
    """name -> body text of every #define, line continuations joined.

    A one-line define carries its body on the same line, so the body starts
    right after the name rather than at the end of the line.
    """
    out = {}

    for m in re.finditer(r"(?m)^[ \t]*#define[ \t]+(\w+)", src):
        lines, i = [], m.end()

        while True:
            nl = src.find("\n", i)
            end = nl if nl != -1 else len(src)
            line = src[i:end]
            joined = line.endswith("\\")
            lines.append(line[:-1] if joined else line)

            if not joined or nl == -1:
                break

            i = nl + 1

        out[m.group(1)] = "\n".join(lines)

    return out


def join_continuations(text):
    return text.replace("\\\r\n", "").replace("\\\n", "")


def string_constants(src):
    """NAME -> literal for a `static constexpr const char* NAME = "...";`."""
    pattern = r'(?:constexpr|const)\s+(?:const\s+)?char\s*\*\s*(?:const\s+)?(\w+)\s*=\s*"([^"]*)"'
    return {m.group(1): m.group(2) for m in re.finditer(pattern, mask(src))}


class Inventory:
    def __init__(self):
        self.namespaces = {}
        self.usertypes = {}

    def ns(self, table, name):
        self.namespaces.setdefault(table, set()).add(name)

    def ut(self, type_name, name):
        self.usertypes.setdefault(type_name, set()).add(name)

    def to_json(self):
        return {"namespaces": {k: sorted(v) for k, v in sorted(self.namespaces.items())},
                "usertypes": {k: sorted(v) for k, v in sorted(self.usertypes.items())}}


def bound_tables(clean):
    """variable name -> the Lua table it is published as."""
    return {m.group(2): m.group(1)
            for m in re.finditer(r'(?:\bm_)?lua\["(\w+)"\]\s*=\s*(\w+)\s*;', clean)}


def target_table(bound, receiver):
    """The Lua table a call on `receiver` writes into, or None when unknown."""
    if receiver in bound:
        return bound[receiver]

    if receiver in STATE_RECEIVERS:
        return GLOBALS

    return None


def read_table_writes(clean, inv):
    """`tbl["name"] = value` on a table the state publishes.

    An entry the same file assigns nil later never reaches a script, so a global
    that only exists while the bindings run is not part of the surface.
    """
    bound = bound_tables(clean)
    writes = []

    for m in re.finditer(r'\b(\w+)\s*\[\s*"([^"]+)"\s*\]\s*=(?!=)([^;\n]*)', clean):
        table = target_table(bound, m.group(1))
        if table is not None:
            writes.append((table, m.group(2), m.group(3)))

    cleared = {name for _, name, rhs in writes if "sol::nil" in rhs or "lua_pushnil" in rhs}

    for table, name, _ in writes:
        if name not in cleared:
            inv.ns(table, name)

    return bound


def reg_names(clean, var):
    """The names in a luaL_Reg list, however the array is spelled.

    Each entry is a `{ "name", fn }` pair, so the names are read out of the
    braces rather than from the comma separated list around them.
    """
    m = re.search(r"\b%s\s*\[\s*\]\s*=?" % re.escape(var), clean)
    if m is None:
        return []

    brace = clean.find("{", m.end())
    if brace == -1:
        return []

    end = skip_group(clean, brace)
    body = clean[brace:end]
    pairs = re.findall(r'\{\s*"([^"]+)"\s*,', body)

    return pairs if pairs else leading_strings(body[1:-1])


def literal_table_target(clean, after):
    """The global a table built in place is published as, or None.

    The table is filled by lua_setfield(..., -2, ...) calls and published by the
    next lua_setglobal. A call that starts a different table in between means the
    setglobal belongs to that one instead.
    """
    tail = clean[after:]
    m = re.search(r'lua_setglobal\s*\(\s*\w+\s*,\s*"([^"]+)"\s*\)', tail)
    if m is None:
        return None

    between = tail[:m.start()]
    if re.search(r"lua_newtable|luaL_setfuncs|luaL_newmetatable", between):
        return None

    return m.group(1)


def read_setfuncs_tables(clean, inv):
    """A luaL_Reg list handed to luaL_setfuncs on the table a global is built from."""
    for m in re.finditer(r"luaL_setfuncs\s*\(\s*\w+\s*,\s*(\w+)\s*,", clean):
        names = reg_names(clean, m.group(1))
        if not names:
            continue

        table = literal_table_target(clean, m.end())
        if table is None:
            continue

        for name in names:
            inv.ns(table, name)


def read_math_type_tables(clean, inv):
    """open_math_type_table(TYPE, ctor, fields, n, "Name"): the metatable itself
    is published under the last argument, with the constructor on it.

    The helper does the luaL_getmetatable and the lua_setglobal, so the name is a
    parameter rather than a literal handed to lua_setglobal.
    """
    for m in re.finditer(r"\bopen_math_type_table\s*(?:<[^<>()]*>)?\s*\(", clean):
        end = skip_group(clean, m.end() - 1)
        args = split_top(clean[m.end():end - 1])
        name = string_value(args[-1]) if args else None

        if name is None:
            continue

        inv.ns(GLOBALS, name)
        inv.ut(name, "new")


def read_literal_tables(clean, inv, known_types=frozenset()):
    """A table built in place: lua_newtable, a run of lua_setfield, lua_setglobal."""
    last_global = -1

    for m in re.finditer(r'lua_setglobal\s*\(\s*\w+\s*,\s*"([^"]+)"\s*\)', clean):
        name = m.group(1)
        inv.ns(GLOBALS, name)

        start = clean.rfind("lua_newtable", max(last_global, 0), m.start())
        last_global = m.end()

        if start == -1:
            continue

        for field in re.finditer(r'lua_setfield\s*\(\s*\w+\s*,\s*-2\s*,\s*"([^"]+)"\s*\)', clean[start:m.start()]):
            if name in known_types:
                inv.ut(name, field.group(1))
            else:
                inv.ns(name, field.group(1))


def enum_entries(src):
    """array name -> member names, for the `{ "Name", value }` enum tables."""
    clean = mask(src)
    out = {}

    for m in re.finditer(r"\b(\w+)\s*\[\s*\]\s*(?:=\s*)?\{", clean):
        brace = clean.index("{", m.end() - 1)
        end = skip_group(clean, brace)
        out[m.group(1)] = re.findall(r'\{\s*"([^"]+)"\s*,', clean[brace:end])

    return out


def read_put_enum(src, clean, inv, spans):
    """lh::put_enum(L, "Name", ARRAY): an enum table on the table being built."""
    entries = enum_entries(src)

    for m in re.finditer(r'\blh::put_enum\s*\(\s*\w+\s*,\s*"([^"]+)"\s*,\s*(\w+)\s*\)', clean):
        tables = []
        owner = innermost_function(spans, m.start())

        if owner is not None:
            for call in re.finditer(r"\b%s\s*\(" % re.escape(owner[0]), clean):
                if not (owner[1] <= call.start() < owner[2]):
                    tables.append(literal_table_target(clean, call.end()))

        tables.append(literal_table_target(clean, m.end()))

        for table in sorted({t for t in tables if t is not None}):
            inv.ns(table, m.group(1))
            for member in entries.get(m.group(2), []):
                inv.ns(table, "%s.%s" % (m.group(1), member))


def read_enums(clean, inv, bound):
    """Enum tables: the table itself and each member of it."""
    for m in re.finditer(r"\b(\w+)\.new_enum(?:\s*<[^(]*?>)?\s*\(", clean):
        table = target_table(bound, m.group(1))
        if table is None:
            continue

        end = skip_group(clean, m.end() - 1)
        body = clean[m.end():end - 1]
        args = split_top(body)
        name = string_value(args[0]) if args else None
        if name is None:
            continue

        inv.ns(table, name)

        brace = body.find("{")
        if brace != -1:
            close = skip_group(body, brace)
            for member in re.findall(r'\{\s*"([^"]+)"\s*,', body[brace:close]):
                inv.ns(table, "%s.%s" % (name, member))
        else:
            for member in leading_strings(", ".join(args[1:])):
                inv.ns(table, "%s.%s" % (name, member))


def methods_of(clean, var):
    """Members of a `lh::methods var` chain.

    The chain either starts on the declaration's own statement or on the next
    one, and it may begin with fallback_index, which is the read fallback rather
    than a member.
    """
    decl = re.search(r"\blh::methods\s+%s\s*\([^;]*\)\s*;" % re.escape(var), clean)
    if decl is None:
        return []

    step = re.compile(r"[ \t\r\n]*(?:(;)[ \t\r\n]*)?(?:\.|(?<![.\w])(\w+)\s*\.)[ \t\r\n]*"
                      r"(add|prop|meta|fallback_index)\s*\(")

    out, i = [], decl.end()
    has_fallback = False

    while True:
        m = step.match(clean, i)

        if m is None:
            break

        # A bare '.' continues the statement; a receiver repeats the variable;
        # anything else belongs to another chain.
        receiver = m.group(2)
        if receiver is not None:
            if receiver != var or m.group(1) is not None:
                break

        open_paren = m.end() - 1
        end = skip_group(clean, open_paren)

        if m.group(3) == "fallback_index":
            has_fallback = True
        else:
            args = split_top(clean[open_paren + 1:end - 1])
            if args:
                name = string_value(args[0])
                if name is not None:
                    out.append(name)

        i = end

    # install() puts a dispatcher in __index whenever a fallback is given, so the
    # metatable carries one even though the chain never names it.
    if has_fallback:
        out.append("__index")

    return out


def sol2_macro_members(macros, name, depth=0):
    """Member names a sol2 binding macro expands to, nested fragments included."""
    if depth > 6 or name not in macros:
        return []

    body = join_continuations(macros[name])
    out = re.findall(r'\s*"([^"]+)"\s*,', body)

    for m in re.finditer(r"sol::meta_function::(\w+)", body):
        if m.group(1) in META_FUNCTIONS:
            out.append(META_FUNCTIONS[m.group(1)])

    for m in re.finditer(r"\b([A-Z][A-Z0-9_]{4,})\s*\(", body):
        if m.group(1) in macros and m.group(1) != name:
            out += sol2_macro_members(macros, m.group(1), depth + 1)

    return out


def read_sol2_usertypes(src, inv):
    """new_usertype<T>("Name", "member", value, ...) in every revision that uses it."""
    clean = mask(src)
    macros = macro_bodies(src)
    bound = bound_tables(clean)

    for m in re.finditer(r"\bnew_usertype\s*<", clean):
        try:
            after_template = skip_group(clean, m.end() - 1)
        except ValueError:
            continue

        while after_template < len(clean) and clean[after_template] in " \t\r\n":
            after_template += 1

        if after_template >= len(clean) or clean[after_template] != "(":
            continue

        end = skip_group(clean, after_template)
        args = split_top(clean[after_template + 1:end - 1])
        type_name = string_value(args[0]) if args else None
        if type_name is None:
            continue

        receiver = re.search(r"([A-Za-z_]\w*)\s*\.\s*$", clean[:m.start()])
        table = target_table(bound, receiver.group(1)) if receiver else None
        if table is not None:
            inv.ns(table, type_name)

        for arg in args[1:]:
            value = string_value(arg)
            if value is not None:
                inv.ut(type_name, value)
                continue

            meta = re.match(r"\s*sol::meta_function::(\w+)\s*$", arg)
            if meta is not None and meta.group(1) in META_FUNCTIONS:
                inv.ut(type_name, META_FUNCTIONS[meta.group(1)])
                continue

            call = re.match(r"\s*(\w+)\s*\(", arg)
            if call is not None and call.group(1) in macros:
                for member in sol2_macro_members(macros, call.group(1)):
                    inv.ut(type_name, member)

    for m in re.finditer(r"(?m)^\s*(DYNAMIC_ARRAY\w+)\s*\(([^;]*)\)\s*;", clean):
        macro = m.group(1)
        if macro not in macros:
            continue

        parts = [a.strip() for a in split_top(m.group(2))]
        type_name = string_value(parts[-1]) if parts else None
        if type_name is None:
            continue

        for member in sol2_macro_members(macros, macro):
            inv.ut(type_name, member)


def read_hand_usertypes(src, inv, spans):
    """lh::install<T>(L, "Name", var, ...) with var filled by a chain of .add()."""
    clean = mask(src)
    macros = macro_bodies(src)

    for m in re.finditer(r"\blh::(install|install_borrowed)\s*<", clean):
        try:
            after_template = skip_group(clean, m.end() - 1)
        except ValueError:
            continue

        call_start = len(clean) - len(clean[after_template:].lstrip())
        if call_start >= len(clean) or clean[call_start] != "(":
            continue

        end = skip_group(clean, call_start)
        args = [a.strip() for a in split_top(clean[call_start + 1:end - 1])]
        if len(args) < 3:
            continue

        type_name, var = string_value(args[1]), args[2]
        if type_name is None or not re.fullmatch(r"\w+", var):
            continue

        inv.ns(GLOBALS, type_name)

        for member in methods_of(clean, var):
            inv.ut(type_name, member)

        # install() writes __eq/__call/__gc from its trailing arguments.
        if len(args) > 3 and args[3] != "nullptr":
            inv.ut(type_name, "__eq")

        if len(args) > 4 and args[4] != "nullptr":
            inv.ut(type_name, "__call")

    for m in re.finditer(r"(?m)^\s*" + NEW_ARRAY_MACRO + r"\s*\((.+)\)\s*$", clean):
        parts = [a.strip() for a in split_top(m.group(1))]
        if len(parts) < 4:
            continue

        type_name = string_value(parts[3])
        if type_name is None:
            continue

        body = join_continuations(macros.get(NEW_ARRAY_MACRO, ""))
        for member in re.findall(r'\.(?:add|prop)\(\s*"([^"]+)"', body):
            inv.ut(type_name, member)

        for meta in re.findall(r'\.meta\(\s*"(__\w+)"\s*,', body):
            inv.ut(type_name, meta)

        # The array macro routes integer indexing through a fallback closure.
        if ".fallback_index(" in body:
            inv.ut(type_name, "__index")

    for m in re.finditer(r"open_math_metatable\s*\(([^;]*)\)\s*;", clean):
        source = re.search(r"math_metatable<\s*([\w:]+)\s*>", m.group(1))
        if source is None:
            continue

        type_name = MATH_NAMES.get(source.group(1))
        if type_name is None:
            continue

        args = [a.strip() for a in split_top(m.group(1))]
        methods = next((a for a in args if a.endswith("_METHODS")), None)
        if methods is None:
            continue

        for member in reg_names(clean, methods):
            inv.ut(type_name, member)

        inv.ut(type_name, "__index")
        if args[-1] != "nullptr":
            inv.ut(type_name, "__newindex")

        # x/y/z/w sit in a MathField table the __index closure reads.
        fields = enum_entries(src)
        index_body = hand_function_body(clean, spans, args[3]) if len(args) > 3 else None

        if index_body is not None:
            for field in re.finditer(r"math_index\s*<[^>]*>\s*\(\s*\w+\s*,\s*(\w+)\s*,", index_body):
                for member in fields.get(field.group(1), []):
                    inv.ut(type_name, member)


def function_spans(clean):
    """(name, body start, body end) for every definition in the file."""
    out = []

    for m in re.finditer(r"(?m)^[ \t]*[A-Za-z_][\w:<>,\s*&]*\b(\w+)\s*\([^;{}]*\)\s*\{", clean):
        try:
            end = skip_group(clean, m.end() - 1)
        except ValueError:
            continue

        out.append((m.group(1), m.end(), end - 1))

    return out


def innermost_function(spans, index):
    """The definition whose body holds `index`, taken as the smallest one."""
    best = None

    for span in spans:
        if span[1] <= index < span[2] and (best is None or span[2] - span[1] < best[2] - best[1]):
            best = span

    return best


def hand_function_body(clean, spans, name):
    """The body of a function written through the LUA_HAND_FUNC macro."""
    m = re.search(r"LUA_HAND_FUNC\s*\(\s*%s\s*\)\s*\{" % re.escape(name), clean)

    if m is not None:
        try:
            end = skip_group(clean, m.end() - 1)
            return clean[m.end():end - 1]
        except ValueError:
            pass

    for name_, start, end in spans:
        if name_ == name:
            return clean[start:end]

    return None


def strcmp_keys(clean, spans, function):
    """Keys a hand-written __index dispatches on."""
    body = hand_function_body(clean, spans, function)

    if body is None:
        return []

    return re.findall(r'strcmp\s*\(\s*\w+\s*,\s*"([^"]+)"', body)


def read_hand_metatables(src, clean, inv, spans):
    """Types the rewrite builds with luaL_newmetatable and names in __name."""
    constants = string_constants(src)

    for m in re.finditer(r"luaL_newmetatable\s*\(\s*\w+\s*,\s*(\w+)\s*\)", clean):
        if m.group(1) not in constants:
            continue

        found = innermost_function(spans, m.start())
        if found is None:
            continue

        body = clean[found[1]:found[2]]

        named = re.search(r'lua_pushliteral\s*\(\s*\w+\s*,\s*"([^"]+)"\s*\)\s*;\s*'
                          r'lua_setfield\s*\(\s*\w+\s*,\s*-2\s*,\s*"__name"\s*\)', body)
        if named is None:
            continue

        type_name = USERTYPE_ALIASES.get(named.group(1), named.group(1))

        for s in re.finditer(r"luaL_setfuncs\s*\(\s*\w+\s*,\s*(\w+)\s*,", body):
            for member in reg_names(clean, s.group(1)):
                inv.ut(type_name, member)

        for f in re.finditer(r"lua_pushcfunction\s*\(\s*\w+\s*,\s*([\w:]+)\s*\)\s*;\s*"
                             r'lua_setfield\s*\(\s*\w+\s*,\s*-2\s*,\s*"__index"\s*\)', body):
            for member in strcmp_keys(clean, spans, f.group(1).split("::")[-1]):
                inv.ut(type_name, member)


def parse_sol2(src):
    inv = Inventory()
    clean = mask(src)
    bound = read_table_writes(clean, inv)
    read_enums(clean, inv, bound)
    read_sol2_usertypes(src, inv)
    return inv


def parse_hand(src):
    inv = Inventory()
    clean = mask(src)
    spans = function_spans(clean)
    bound = read_table_writes(clean, inv)
    read_enums(clean, inv, bound)
    read_setfuncs_tables(clean, inv)
    read_math_type_tables(clean, inv)
    read_hand_usertypes(src, inv, spans)
    read_literal_tables(clean, inv, set(inv.usertypes))
    read_put_enum(src, clean, inv, spans)
    read_hand_metatables(src, clean, inv, spans)
    # Types that a file kept on sol2 -- REFramework, for one -- keep that surface.
    read_sol2_usertypes(src, inv)
    return inv


def merge(into, other):
    for table, names in other.namespaces.items():
        into.namespaces.setdefault(table, set()).update(names)
    for type_name, names in other.usertypes.items():
        into.usertypes.setdefault(type_name, set()).update(names)


def inventory_for(rev, parse):
    inv = Inventory()
    for path in FILES:
        merge(inv, parse(show(rev, path)))
    return inv


def cmd_compare(args):
    base = inventory_for(args.base, parse_sol2)
    head = inventory_for(args.head, parse_hand)

    dropped = sorted("%s.%s" % (table, name)
                     for table, names in base.namespaces.items()
                     for name in names - head.namespaces.get(table, set()))
    dropped += sorted("%s:%s" % (type_name, name)
                      for type_name, names in base.usertypes.items()
                      for name in names - head.usertypes.get(type_name, set()))

    added = sorted("%s.%s" % (table, name)
                   for table, names in head.namespaces.items()
                   for name in names - base.namespaces.get(table, set()))
    added += sorted("%s:%s" % (type_name, name)
                    for type_name, names in head.usertypes.items()
                    for name in names - base.usertypes.get(type_name, set()))

    base_names = sum(len(v) for v in base.namespaces.values()) + sum(len(v) for v in base.usertypes.values())
    head_names = sum(len(v) for v in head.namespaces.values()) + sum(len(v) for v in head.usertypes.values())

    print("%s: %d tables, %d usertypes, %d names" % (args.base, len(base.namespaces), len(base.usertypes), base_names))
    print("%s: %d tables, %d usertypes, %d names" % (args.head, len(head.namespaces), len(head.usertypes), head_names))
    print()
    print("dropped (%d)" % len(dropped))
    for name in dropped:
        print("  - %s" % name)
    print()
    print("added (%d)" % len(added))
    for name in added:
        print("  + %s" % name)

    Path(args.out).write_text(json.dumps({"base": base.to_json(), "head": head.to_json()}, indent=1),
                              encoding="utf-8")
    print()
    print("wrote %s" % args.out)

    return 1 if dropped else 0


def lua_quote(value):
    return '"%s"' % value.replace("\\", "\\\\").replace('"', '\\"')


def verify_script(inv):
    """A Lua program that resolves every baseline name against the running game."""
    checks = []

    def add(label, candidates):
        checks.append((label, candidates))

    for table, names in sorted(inv.namespaces.items()):
        head = [] if table == GLOBALS else [table]
        for name in sorted(names):
            # `ColumnFlags.DefaultHide` is one literal key in the `imgui` table,
            # while `io.FontGlobalScale` may be nested tables; accept either
            # reading rather than guessing from the dot.
            candidates = [head + [name]]
            if "." in name:
                candidates.append(head + name.split("."))
            add(name if table == GLOBALS else "%s.%s" % (table, name), candidates)

    # Members reached through the type table itself (`_G.ValueType.new`,
    # `imgui.ImDrawList.add_text`): sol2 publishes them on the named metatable,
    # the rewrite publishes them on the table lh::install builds. Metacomponents
    # (`__eq`, `__index`) are skipped -- they are never addressed by name.
    owners = {}
    for table, names in inv.namespaces.items():
        for name in names:
            if name in inv.usertypes:
                owners[name] = table

    for type_name, members in sorted(inv.usertypes.items()):
        table = owners.get(type_name)
        if table is None:
            continue
        prefix = type_name if table == GLOBALS else "%s.%s" % (table, type_name)
        head = [type_name] if table == GLOBALS else [table, type_name]
        for member in sorted(members):
            if not member.startswith("__"):
                add("%s.%s" % (prefix, member), [head + [member]])

    lines = [
        "local missing, mismatched, seen, raised = {}, {}, 0, {}",
        "",
        "local function resolve(keys)",
        "    local value = _G",
        "    for i = 1, #keys do",
        "        if type(value) ~= 'table' then return nil end",
        "        value = value[keys[i]]",
        "        if value == nil then return nil end",
        "    end",
        "    return value",
        "end",
        "",
        "local function check(label, candidates)",
        "    local value, error_text = nil, nil",
        "    for _, keys in ipairs(candidates) do",
        "        -- An __index that raises counts as a miss, so one bad read does",
        "        -- not take the whole run with it.",
        "        local ok, found = pcall(resolve, keys)",
        "        if ok then",
        "            if found ~= nil then value = found break end",
        "        elseif error_text == nil then",
        "            error_text = tostring(found)",
        "        end",
        "    end",
        "    seen = seen + 1",
        "    if value == nil then",
        "        missing[#missing + 1] = label",
        "        if error_text ~= nil then",
        "            raised[#raised + 1] = label .. ' -> ' .. error_text",
        "        end",
        "    end",
        "end",
        "",
        "for _, entry in ipairs({",
    ]

    for label, candidates in checks:
        rendered = ", ".join(
            "{%s}" % ", ".join(lua_quote(key) for key in keys) for keys in candidates)
        lines.append("    {%s, {%s}}," % (lua_quote(label), rendered))

    lines += [
        "}) do",
        "    check(entry[1], entry[2])",
        "end",
        "",
        "local function probe(instance, name)",
        "    local mt = getmetatable(instance)",
        "    if type(mt) == 'table' then",
        "        local ok, field = pcall(function() return mt[name] end)",
        "        if ok and field ~= nil then return true end",
        "        local got_index, index = pcall(function() return mt.__index end)",
        "        if got_index and type(index) == 'table' then",
        "            local ok2, member = pcall(function() return index[name] end)",
        "            if ok2 and member ~= nil then return true end",
        "        end",
        "    end",
        "    -- A member may be dispatched from C instead of sitting in a table, so",
        "    -- read it off the instance itself too. That is the path a script takes.",
        "    local ok3, value = pcall(function() return instance[name] end)",
        "    return ok3 and value ~= nil",
        "end",
        "",
        "local typed, untyped = 0, 0",
        "",
    ]

    for type_name, expr in sorted(INSTANCES.items()):
        members_ = sorted(inv.usertypes.get(type_name, set()))
        if not members_:
            continue

        lines.append("do")
        lines.append("    local ok, instance = pcall(function() return %s end)" % expr)
        lines += [
            "    if ok and instance ~= nil then",
            "        typed = typed + 1",
            "        for _, name in ipairs({%s}) do" % ", ".join(lua_quote(m) for m in members_),
            "            if not probe(instance, name) then",
            "                missing[#missing + 1] = %s .. ':' .. name" % lua_quote(type_name),
            "            end",
            "        end",
            "    else",
            "        untyped = untyped + 1",
            "    end",
            "end",
            "",
        ]

    lines += [
        "return table.concat({",
        "    'names checked: ' .. seen,",
        "    'usertypes iterated: ' .. typed,",
        "    'usertypes not reachable: ' .. untyped,",
        "    'missing: ' .. #missing,",
        "    table.concat(missing, '\\n'),",
        "    'reads that raised: ' .. #raised,",
        "    table.concat(raised, '\\n'),",
        "    'kind mismatch: ' .. #mismatched,",
        "    table.concat(mismatched, '\\n'),",
        "}, '\\n')",
    ]

    return "\n".join(lines)


def load_rpc_client():
    path = REPO / "docs" / "lua_rpc" / "lua.py"
    spec = importlib.util.spec_from_file_location("lua_rpc_client", path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def cmd_verify(args):
    inv = inventory_for(args.rev, parse_sol2)
    script = verify_script(inv)
    Path(args.script).write_text(script, encoding="utf-8", newline="\n")

    client = load_rpc_client()
    reply = client.lua(script, port=args.port, timeout_ms=60000)

    if not reply.get("ok"):
        sys.exit("rpc failed: %s" % reply.get("error"))

    text = (reply.get("returns") or [""])[0]
    Path(args.out).write_text(text, encoding="utf-8", newline="\n")
    print(text)

    failed = re.search(r"(?m)^missing: [1-9]", text) or re.search(r"(?m)^kind mismatch: [1-9]", text)
    return 1 if failed else 0


def main():
    p = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    sub = p.add_subparsers(dest="command", required=True)

    c = sub.add_parser("compare", help="diff the baseline surface against the rewrite")
    c.add_argument("--base", default="0321fe8e", help="sol2 revision")
    c.add_argument("--head", default="HEAD", help="hand-written revision")
    c.add_argument("--out", default="/tmp/surface.json")
    c.set_defaults(func=cmd_compare)

    v = sub.add_parser("verify", help="ask the running game for every baseline name")
    v.add_argument("--rev", default="0321fe8e", help="sol2 revision the names come from")
    v.add_argument("--port", type=int, default=13377)
    v.add_argument("--script", default="/tmp/surface_verify.lua")
    v.add_argument("--out", default="/tmp/surface_verify.txt")
    v.set_defaults(func=cmd_verify)

    args = p.parse_args()
    sys.exit(args.func(args))


if __name__ == "__main__":
    main()
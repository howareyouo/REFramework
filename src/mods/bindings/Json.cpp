#include <filesystem>
#include <fstream>
#include <iterator>
#include <limits>
#include <stdexcept>
#include <string>

#include <lua.hpp> // wraps the C headers in extern "C"; lua.h alone mismatches the C-built runtime

#include <json.hpp>
#include <spdlog/spdlog.h>

#include "../ScriptRunner.hpp"

#include "Json.hpp"
#include "LuaHand.hpp"

namespace api::json {
using json = nlohmann::json;
namespace fs = std::filesystem;

namespace {
// The data directory is the root of every path a script may reach here.
// REFramework::get_persistent_dir() caches the user directory itself, so the
// joined path can be resolved once for the lifetime of the process.
const fs::path& datadir() {
    static const fs::path dir = REFramework::get_persistent_dir() / "reframework" / "data";
    return dir;
}

// Turns a script-supplied path into a real path, or raises so the misuse stays
// visible to the script. `api` only names the caller in the error message.
fs::path resolve_path(const std::string& filepath, const char* api) {
    if (filepath.find("..") != std::string::npos) {
        throw std::runtime_error{std::string{api} + " does not allow access to parent directories"};
    }

    if (fs::path{filepath}.is_absolute()) {
        throw std::runtime_error{std::string{api} + " does not allow absolute paths"};
    }

    return datadir() / filepath;
}

// Only a number overrides the default; nil and anything else keep it.
int indent_of(lua_State* L, int index, int fallback) {
    return lua_type(L, index) == LUA_TNUMBER ? static_cast<int>(lua_tointeger(L, index)) : fallback;
}

// A key copied off the stack as text. luaL_tolstring pushes its own string
// instead of converting in place, so the key stays valid for the next lua_next.
std::string key_string(lua_State* L, int index) {
    size_t length = 0;
    const auto text = luaL_tolstring(L, index, &length);
    std::string out{text, length};

    lua_pop(L, 1);

    return out;
}

// A table whose keys are 1..n becomes an array, anything else an object.
// Deciding that while walking means the table is visited once: the elements
// collected so far are folded into an object the first time a key breaks the
// sequence.
json encode(lua_State* L, int index) {
    index = lua_absindex(L, index);

    switch (lua_type(L, index)) {
    case LUA_TBOOLEAN:
        return lua_toboolean(L, index) != 0;
    case LUA_TNUMBER:
        // Parentheses, not braces: nlohmann reads json{5} as a one-element array.
        return lua_isinteger(L, index) != 0 ? json(lua_tointeger(L, index)) : json(lua_tonumber(L, index));
    case LUA_TSTRING: {
        size_t length = 0;
        const auto text = lua_tolstring(L, index, &length);

        return std::string{text, length};
    }
    case LUA_TTABLE: {
        json result = json::array();
        int next = 1;

        lua_pushnil(L);

        while (lua_next(L, index) != 0) {
            // The key stays under the value on the stack; it is inspected before
            // the value so a nested table cannot disturb it.
            if (result.is_array() && (lua_type(L, -2) != LUA_TNUMBER || lua_tointeger(L, -2) != next)) {
                json object = json::object();

                for (size_t i = 0; i < result.size(); ++i) {
                    object[std::to_string(i + 1)] = std::move(result[i]);
                }

                result = std::move(object);
            }

            if (result.is_array()) {
                result.push_back(encode(L, -1));
                ++next;
            } else {
                result[key_string(L, -2)] = encode(L, -1);
            }

            lua_pop(L, 1);
        }

        return result;
    }
    default: // nil, functions, userdata and threads have no JSON equivalent
        return json{};
    }
}

// Leaves the Lua value for `j` on top of the stack. Pushing straight onto the
// stack keeps the stack use at the nesting depth.
void push_value(lua_State* L, const json& j) {
    switch (j.type()) {
    case json::value_t::boolean:
        lua_pushboolean(L, j.get<bool>() ? 1 : 0);
        return;
    case json::value_t::number_integer:
        lua_pushinteger(L, static_cast<lua_Integer>(j.get<int64_t>()));
        return;
    case json::value_t::number_unsigned: {
        const auto value = j.get<uint64_t>();

        // Lua integers are signed, so only the top of the uint64 range loses
        // precision by becoming a float.
        if (value <= static_cast<uint64_t>(std::numeric_limits<lua_Integer>::max())) {
            lua_pushinteger(L, static_cast<lua_Integer>(value));
        } else {
            lua_pushnumber(L, static_cast<lua_Number>(value));
        }

        return;
    }
    case json::value_t::number_float:
        lua_pushnumber(L, j.get<double>());
        return;
    case json::value_t::string: {
        // get_ref() hands out the stored string instead of copying it.
        const auto& text = j.get_ref<const std::string&>();
        lua_pushlstring(L, text.data(), text.size());
        return;
    }
    case json::value_t::array: {
        lua_createtable(L, static_cast<int>(j.size()), 0);
        lua_Integer index = 0;

        for (const auto& element : j) {
            push_value(L, element);
            lua_rawseti(L, -2, ++index);
        }

        return;
    }
    case json::value_t::object: {
        lua_createtable(L, 0, static_cast<int>(j.size()));

        for (auto it = j.begin(); it != j.end(); ++it) {
            const auto& key = it.key();
            lua_pushlstring(L, key.data(), key.size());
            push_value(L, it.value());
            lua_rawset(L, -3);
        }

        return;
    }
    default: // null, and the shapes Lua has no value for (binary, discarded)
        lua_pushnil(L);
        return;
    }
}
} // namespace

LUA_HAND_FUNC(l_load_string) {
    const std::string text{luaL_checkstring(L, 1)};

    try {
        push_value(L, json::parse(text));
    } catch (const std::exception&) {
        lua_pushnil(L);
    }

    return 1;
}
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(l_dump_string) {
    try {
        const auto result = encode(L, 1).dump(indent_of(L, 2, -1));
        lua_pushlstring(L, result.data(), result.size());
    } catch (const std::exception&) {
        lua_pushliteral(L, "");
    }

    return 1;
}
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(l_load_file) {
    const std::string filepath{luaL_checkstring(L, 1)};
    const auto path = resolve_path(filepath, "json.load_file");

    try {
        std::ifstream file{path};
        // nlohmann's stream adapter walks the streambuf one character at a time,
        // so the file is read in one go and parsed from memory.
        const std::string text{std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};

        push_value(L, json::parse(text));
    } catch (const std::exception& e) {
        spdlog::error("[JSON] Failed to load file {}: {}", filepath, e.what());
        lua_pushnil(L);
    }

    return 1;
}
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(l_dump_file) {
    const std::string filepath{luaL_checkstring(L, 1)};
    const auto path = resolve_path(filepath, "json.dump_file");

    try {
        // Serialize before touching the file: dump() can throw (e.g. invalid
        // UTF-8), and opening the target first would already have truncated it.
        const auto contents = encode(L, 2).dump(indent_of(L, 3, 4));

        fs::create_directories(path.parent_path());

        // Write to a temporary file and swap it in, so a crash or kill mid-write
        // never leaves the target empty or partially written.
        auto tmp_path = path;
        tmp_path += ".tmp";

        {
            std::ofstream f{tmp_path, std::ios::out | std::ios::trunc};
            f << contents;
            f.close();

            if (!f) {
                std::error_code ec{};
                fs::remove(tmp_path, ec);
                throw std::runtime_error{"failed to write temporary file"};
            }
        }

        try {
            fs::rename(tmp_path, path);
        } catch (...) {
            std::error_code ec{};
            fs::remove(tmp_path, ec);
            throw;
        }

        lua_pushboolean(L, 1);
    } catch (const std::exception& e) {
        spdlog::error("[JSON] Failed to dump file {}: {}", filepath, e.what());
        lua_pushboolean(L, 0);
    }

    return 1;
}
LUA_HAND_CATCH(L)

} // namespace api::json

static const luaL_Reg JSON_FUNCS[]{
    {"load_string", api::json::l_load_string},
    {"dump_string", api::json::l_dump_string},
    {"load_file", api::json::l_load_file},
    {"dump_file", api::json::l_dump_file},
    {nullptr, nullptr},
};

void bindings::open_json(ScriptState* s) {
    auto L = s->lua().lua_state();

    lua_newtable(L);
    luaL_setfuncs(L, JSON_FUNCS, 0);
    lua_setglobal(L, "json");
}
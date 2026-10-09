#include <filesystem>
#include <fstream>
#include <iterator>
#include <string>

#include <json.hpp>
#include <spdlog/spdlog.h>

#include "../ScriptRunner.hpp"

#include "Json.hpp"

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
        throw sol::error{std::string{api} + " does not allow access to parent directories"};
    }

    if (fs::path{filepath}.is_absolute()) {
        throw sol::error{std::string{api} + " does not allow absolute paths"};
    }

    return datadir() / filepath;
}

// Only a number overrides the default; nil and anything else keep it.
int indent_of(const sol::object& obj, int fallback) {
    return obj.get_type() == sol::type::number ? obj.as<int>() : fallback;
}

// A table whose keys are 1..n becomes an array, anything else an object.
// Deciding that while walking means the table is visited once: the elements
// collected so far are folded into an object the first time a key breaks the
// sequence.
json encode(const sol::object& obj) {
    switch (obj.get_type()) {
    case sol::type::boolean:
        return obj.as<bool>();
    case sol::type::number: {
        // The only place that needs the Lua stack: an integer has to stay an
        // integer, and lua_isinteger reads the value off the stack.
        lua_State* L = obj.lua_state();
        obj.push();
        // Parentheses, not braces: nlohmann reads json{5} as a one-element array.
        const json number = lua_isinteger(L, -1) != 0 ? json(lua_tointeger(L, -1)) : json(lua_tonumber(L, -1));
        lua_pop(L, 1);

        return number;
    }
    case sol::type::string:
        return obj.as<std::string>();
    case sol::type::table: {
        json result = json::array();
        int next = 1;

        for (const auto& [key, value] : obj.as<sol::table>()) {
            if (result.is_array() && (key.get_type() != sol::type::number || key.as<int>() != next)) {
                json object = json::object();

                for (size_t i = 0; i < result.size(); ++i) {
                    object[std::to_string(i + 1)] = std::move(result[i]);
                }

                result = std::move(object);
            }

            if (result.is_array()) {
                result.push_back(encode(value));
                ++next;
            } else {
                result[key.as<std::string>()] = encode(value);
            }
        }

        return result;
    }
    default: // nil, functions, userdata and threads have no JSON equivalent
        return json{};
    }
}

// Leaves the Lua value for `j` on top of the stack. Pushing straight onto the
// stack keeps the stack use at the nesting depth and saves the temporary
// sol::object (a registry reference) that a sol2 round trip spends per node.
void push_value(lua_State* L, const json& j) {
    switch (j.type()) {
    case json::value_t::boolean:
        sol::stack::push(L, j.get<bool>());
        return;
    case json::value_t::number_integer:
        sol::stack::push(L, j.get<int64_t>());
        return;
    case json::value_t::number_unsigned:
        // sol2 pushes a float for values that do not fit a Lua integer.
        sol::stack::push(L, j.get<uint64_t>());
        return;
    case json::value_t::number_float:
        sol::stack::push(L, j.get<double>());
        return;
    case json::value_t::string:
        // get_ref() hands out the stored string instead of copying it.
        sol::stack::push(L, j.get_ref<const std::string&>());
        return;
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

sol::object load_string(sol::this_state l, const std::string& s) {
    try {
        push_value(l, json::parse(s));
        return sol::stack::pop<sol::object>(l);
    } catch (const std::exception&) {
        return sol::nil;
    }
}

std::string dump_string(sol::object obj, sol::object indent_obj) {
    try {
        return encode(obj).dump(indent_of(indent_obj, -1));
    } catch (const std::exception&) {
        return {};
    }
}

sol::object load_file(sol::this_state l, const std::string& filepath) {
    const auto path = resolve_path(filepath, "json.load_file");

    try {
        std::ifstream file{path};
        // nlohmann's stream adapter walks the streambuf one character at a time,
        // so the file is read in one go and parsed from memory.
        const std::string text{std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};

        push_value(l, json::parse(text));
        return sol::stack::pop<sol::object>(l);
    } catch (const std::exception& e) {
        spdlog::error("[JSON] Failed to load file {}: {}", filepath, e.what());
        return sol::nil;
    }
}

bool dump_file(const std::string& filepath, sol::object obj, sol::object indent_obj) {
    const auto path = resolve_path(filepath, "json.dump_file");

    try {
        fs::create_directories(path.parent_path());
        std::ofstream{path} << encode(obj).dump(indent_of(indent_obj, 4));
        return true;
    } catch (const std::exception& e) {
        spdlog::error("[JSON] Failed to dump file {}: {}", filepath, e.what());
        return false;
    }
}

} // namespace api::json

void bindings::open_json(ScriptState* s) {
    auto& lua = s->lua();
    auto json = lua.create_table();

    json["load_string"] = api::json::load_string;
    json["dump_string"] = api::json::dump_string;
    json["load_file"] = api::json::load_file;
    json["dump_file"] = api::json::dump_file;
    lua["json"] = json;
}

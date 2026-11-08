#include <algorithm>
#include <filesystem>
#include <fstream>
#include <regex>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>

#include <lua.hpp> // wraps the C headers in extern "C"; lua.h alone mismatches the C-built runtime

#include "../ScriptRunner.hpp"

#include "FS.hpp"
#include "LuaHand.hpp"

namespace fs = std::filesystem;
namespace lh = lua_hand;

namespace api::fs {
namespace detail {
::fs::path get_datadir(std::string wanted_subdir = "") {
    static const std::string modpath = []() {
        std::string result{};
        result.resize(1024, 0);
        result.resize(GetModuleFileName(nullptr, result.data(), result.size()));

        return result;
    }();

    if (!wanted_subdir.empty() && wanted_subdir.find("$") != std::string::npos) {
        if (wanted_subdir.find("$natives") != std::string::npos) {
            auto datadir = ::fs::path{modpath}.parent_path() / "natives";

            ::fs::create_directories(datadir);

            return datadir;
        }

        if (wanted_subdir.find("$autorun") != std::string::npos) {
            auto datadir = REFramework::get_persistent_dir() / "reframework" / "autorun";

            ::fs::create_directories(datadir);

            return datadir;
        }
        
        // todo, other subdirs?
    }

    auto datadir = REFramework::get_persistent_dir() / "reframework" / "data";

    ::fs::create_directories(datadir);

    return datadir;
}

::fs::path fix_subdir(::fs::path subdir) {
    ::fs::path out{subdir};

    if (subdir.begin() != subdir.end()) {
        if(*subdir.begin() == "$natives") {
            out = ::fs::path{};

            // The subdirectory must start with the second subdirectory.
            for (auto it = ++subdir.begin(); it != subdir.end(); ++it) {
                out = out / *it;
            }
        }
    }

    return out;
}

// Rejects any path that would escape the data directory. Every rejection is
// raised as an exception so the enclosing thunk turns it into a Lua error with
// the stack already unwound.
::fs::path correct_subpath(const std::string& filepath, bool allow_dll) {
    if (filepath.find("..") != std::string::npos) {
        throw std::runtime_error{"This API does not allow access to parent directories"};
    }

    if (::fs::path(filepath).is_absolute()) {
        throw std::runtime_error{"This API does not allow the use of absolute paths"};
    }

    const auto corrected_subpath = fix_subdir(::fs::path{filepath});

    if (corrected_subpath.string().find("..") != std::string::npos) {
        throw std::runtime_error{"This API does not allow access to parent directories"};
    }

    if (corrected_subpath.is_absolute()) {
        throw std::runtime_error{"This API does not allow the use of absolute paths"};
    }

    const auto path = get_datadir(filepath) / corrected_subpath;

    if (!allow_dll) {
        auto extension = path.extension().string();
        std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);

        // it's not a good idea to allow DLLs to be written to disk from Lua scripts.
        if (extension == ".dll" || extension == ".exe") {
            throw std::runtime_error{"This API does not allow interacting with executables or DLLs"};
        }
    }

    return path;
}

// The original stdlib functions stay in the registry: the wrappers below
// forward to them once the path has been checked.
constexpr const char* OLD_IO_OPEN = "REFramework.io_open";
constexpr const char* OLD_IO_LINES = "REFramework.io_lines";
constexpr const char* OLD_IO_INPUT = "REFramework.io_input";
constexpr const char* OLD_IO_OUTPUT = "REFramework.io_output";
constexpr const char* OLD_REQUIRE = "REFramework.require";
constexpr const char* OLD_LOADLIB = "REFramework.loadlib";

void save_field(lua_State* L, int index, const char* key, const char* registry_key) {
    lua_getfield(L, index, key);
    lua_setfield(L, LUA_REGISTRYINDEX, registry_key);
}

// io.open keeps no default when the path is missing, so the argument is required.
int forward_file(lua_State* L, const char* registry_key) {
    const auto path = correct_subpath(luaL_checkstring(L, 1), false);

    ::fs::create_directories(path.parent_path());

    lua_getfield(L, LUA_REGISTRYINDEX, registry_key);
    lua_pushstring(L, path.string().c_str());
    lua_call(L, 1, 1);

    return 1;
}

// io.lines/input/output take nil to mean the standard handles, and only a path
// has to be redirected through the data directory.
int forward_file_or_nil(lua_State* L, const char* registry_key, const char* api) {
    lua_getfield(L, LUA_REGISTRYINDEX, registry_key);

    if (lh::is_none(L, 1)) {
        lua_pushnil(L);
        lua_call(L, 1, 1);

        return 1;
    }

    if (!lh::is_str(L, 1)) {
        throw std::runtime_error{std::string{api} + ": expected a string or nil as the first argument"};
    }

    const auto path = correct_subpath(lua_tostring(L, 1), false);

    ::fs::create_directories(path.parent_path());

    lua_pushstring(L, path.string().c_str());
    lua_call(L, 1, 1);

    return 1;
}

// Copies every key/value pair from the table at `src` into the table at `dst`.
void copy_table(lua_State* L, int dst, int src) {
    dst = lua_absindex(L, dst);
    src = lua_absindex(L, src);

    lua_pushnil(L);

    while (lua_next(L, src) != 0) {
        lua_pushvalue(L, -2);
        lua_insert(L, -2);
        lua_settable(L, dst);
    }
}
} // namespace detail

using namespace detail;

LUA_HAND_FUNC(l_glob) {
    // A non-string argument is treated as an absent one, which is what the
    // typed sol2 parameters did for nil.
    const char* filter = lh::opt_str(L, 1, nullptr);
    const char* modifier = lh::opt_str(L, 2, nullptr);

    std::regex filter_regex;

    try {
        filter_regex = std::regex{filter != nullptr ? filter : ".*"};
    } catch (const std::regex_error& e) {
        // An invalid pattern would otherwise throw std::regex_error across the Lua
        // boundary; turn it into a Lua error so a script typo can't crash the game.
        throw std::runtime_error{std::string{"fs.glob: invalid pattern: "} + e.what()};
    }

    const auto datadir = get_datadir(modifier != nullptr ? modifier : "");

    lua_createtable(L, 0, 0);
    lua_Integer i = 0;

    for (const auto& entry : ::fs::recursive_directory_iterator{datadir}) {
        if (!entry.is_regular_file() && !entry.is_symlink()) {
            continue;
        }

        // Entries come straight from the iterator, so the relative path is a pure
        // string operation here (fs::relative would canonicalize on disk).
        const auto relpath = entry.path().lexically_relative(datadir).string();

        if (std::regex_match(relpath, filter_regex)) {
            lua_pushlstring(L, relpath.data(), relpath.size());
            lua_rawseti(L, -2, ++i);
        }
    }

    return 1;
}
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(l_write) {
    size_t length = 0;
    const auto data = luaL_checklstring(L, 2, &length);
    const auto path = correct_subpath(luaL_checkstring(L, 1), false);

    ::fs::create_directories(path.parent_path());

    std::ofstream file{path};

    file.write(data, static_cast<std::streamsize>(length));

    return 0;
}
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(l_read) {
    const auto path = correct_subpath(luaL_checkstring(L, 1), false);

    if (!::fs::exists(path)) {
        lua_pushliteral(L, "");

        return 1;
    }

    ::fs::create_directories(path.parent_path());

    std::ifstream file{path};
    std::stringstream buffer;
    buffer << file.rdbuf();

    const auto text = buffer.str();
    lua_pushlstring(L, text.data(), text.size());

    return 1;
}
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(l_io_open) {
    forward_file(L, OLD_IO_OPEN);

    return 1;
}
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(l_io_lines) {
    forward_file_or_nil(L, OLD_IO_LINES, "io.lines");

    return 1;
}
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(l_io_input) {
    forward_file_or_nil(L, OLD_IO_INPUT, "io.input");

    return 1;
}
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(l_io_output) {
    forward_file_or_nil(L, OLD_IO_OUTPUT, "io.output");

    return 1;
}
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(l_require) {
    const std::string_view filepath{luaL_checkstring(L, 1)};

    if (filepath.find("..") != std::string_view::npos) {
        throw std::runtime_error{"require does not allow access to parent directories"};
    }

    if (::fs::path{filepath}.is_absolute()) {
        throw std::runtime_error{"require does not allow the use of absolute paths"};
    }

    // Do not allow modification of the package path or cpath. We restore it to a pristine value before calling the original require.
    lua_getglobal(L, "package");

    lua_getfield(L, LUA_REGISTRYINDEX, "package_path");
    lua_setfield(L, -2, "path");

    lua_getfield(L, LUA_REGISTRYINDEX, "package_cpath");
    lua_setfield(L, -2, "cpath");

    lua_newtable(L);
    lua_getfield(L, LUA_REGISTRYINDEX, "package_searchers");
    copy_table(L, -2, -1);
    lua_pop(L, 1);
    lua_setfield(L, -2, "searchers");

    lua_pop(L, 1);

    lua_getfield(L, LUA_REGISTRYINDEX, OLD_REQUIRE);
    lua_pushvalue(L, 1);
    lua_call(L, 1, 1);

    return 1;
}
LUA_HAND_CATCH(L)

LUA_HAND_FUNC(l_loadlib) {
    const std::string_view filepath{luaL_checkstring(L, 1)};
    const auto path = correct_subpath(std::string{filepath}, true);

    auto extension = path.extension().string();
    std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);

    if (extension != ".dll") {
        throw std::runtime_error{"package.loadlib: only DLLs are allowed"};
    }

    // The original filepath is forwarded, not the resolved one, matching what
    // this wrapper has always passed through.
    lua_getfield(L, LUA_REGISTRYINDEX, OLD_LOADLIB);
    lua_pushvalue(L, 1);
    lua_pushvalue(L, 2);
    lua_call(L, 2, 1);

    return 1;
}
LUA_HAND_CATCH(L)
} // namespace api::fs

static const luaL_Reg FS_FUNCS[]{
    {"glob", api::fs::l_glob},
    {"write", api::fs::l_write},
    {"read", api::fs::l_read},
    {nullptr, nullptr},
};

void bindings::open_fs(ScriptState* s) {
    auto L = s->lua().lua_state();

    lua_newtable(L);
    luaL_setfuncs(L, FS_FUNCS, 0);
    lua_setglobal(L, "fs");

    luaL_requiref(L, LUA_IOLIBNAME, luaopen_io, 1);
    lua_pop(L, 1);

    // Replace the io functions with safe versions that can't be used to access parent directories and can't be used to open files outside of the data directory.
    // Addendum: Now io APIs can access the "natives" directory relative to the executable.
    lua_getglobal(L, "io");

    api::fs::detail::save_field(L, -1, "open", api::fs::detail::OLD_IO_OPEN);
    lua_pushcfunction(L, api::fs::l_io_open);
    lua_setfield(L, -2, "open");

    api::fs::detail::save_field(L, -1, "lines", api::fs::detail::OLD_IO_LINES);
    lua_pushcfunction(L, api::fs::l_io_lines);
    lua_setfield(L, -2, "lines");

    api::fs::detail::save_field(L, -1, "input", api::fs::detail::OLD_IO_INPUT);
    lua_pushcfunction(L, api::fs::l_io_input);
    lua_setfield(L, -2, "input");

    api::fs::detail::save_field(L, -1, "output", api::fs::detail::OLD_IO_OUTPUT);
    lua_pushcfunction(L, api::fs::l_io_output);
    lua_setfield(L, -2, "output");

    // These functions can take nil as the first argument and they will return the default filehandle associated with stdin, stdout, or stderr.
    // So they should be safe in that respect.
    lua_pushnil(L); // on second thought, I don't want to allow popen. If someone really wants this functionality, they can just make a C++ plugin and use the C++ API.
    lua_setfield(L, -2, "popen");

    lua_pop(L, 1);

    lua_getglobal(L, "require");
    lua_setfield(L, LUA_REGISTRYINDEX, api::fs::detail::OLD_REQUIRE);
    lua_pushcfunction(L, api::fs::l_require);
    lua_setglobal(L, "require");

    lua_getglobal(L, "package");
    api::fs::detail::save_field(L, -1, "loadlib", api::fs::detail::OLD_LOADLIB);
    lua_pushcfunction(L, api::fs::l_loadlib);
    lua_setfield(L, -2, "loadlib");
    lua_pop(L, 1);
}
#include <algorithm>
#include <array>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <optional>
#include <regex>

#include "../ScriptRunner.hpp"

#include "FS.hpp"

namespace fs = std::filesystem;

namespace api::fs {
namespace detail {
namespace {
// Where a script-supplied path is allowed to point. "$natives" and "$autorun"
// are the magic prefixes scripts use to reach the two extra folders; everything
// else stays inside the persistent data directory.
enum class location : size_t {
    data,
    natives,
    autorun,
};

const ::fs::path& datadir(location loc) {
    // Resolved once and reused for the lifetime of the process. Creating the
    // directory is left to the callers, so this stays side-effect free.
    static const std::array<::fs::path, 3> dirs = [] {
        std::string module_path(1024, '\0');
        module_path.resize(GetModuleFileName(nullptr, module_path.data(), (DWORD)module_path.size()));

        return std::array<::fs::path, 3>{
            REFramework::get_persistent_dir() / "reframework" / "data",
            ::fs::path{module_path}.parent_path() / "natives",
            REFramework::get_persistent_dir() / "reframework" / "autorun",
        };
    }();

    return dirs[static_cast<size_t>(loc)];
}

location locate(const std::string& filepath) {
    if (filepath.find('$') == std::string::npos) {
        return location::data;
    }

    if (filepath.find("$natives") != std::string::npos) {
        return location::natives;
    }

    if (filepath.find("$autorun") != std::string::npos) {
        return location::autorun;
    }

    return location::data;
}

// Raises a plain Lua error. Like lua_error, this never returns, which lets the
// callers below keep the success path straight instead of threading a
// std::optional through every filesystem helper.
[[noreturn]] void raise(lua_State* l, const char* msg) {
    lua_pushstring(l, msg);
    lua_error(l);
}

[[noreturn]] void raise(lua_State* l, const std::string& msg) {
    lua_pushlstring(l, msg.data(), msg.size());
    lua_error(l);
}

std::string lowercase_extension(const ::fs::path& path) {
    auto ext = path.extension().string();
    std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
    return ext;
}

// "$natives" is a marker rather than a real folder: the datadir already points
// at the natives directory, so the leading component has to be dropped.
::fs::path strip_magic_prefix(const ::fs::path& subdir) {
    auto it = subdir.begin();

    if (it == subdir.end() || *it != "$natives") {
        return subdir;
    }

    ::fs::path out;

    for (++it; it != subdir.end(); ++it) {
        out /= *it;
    }

    return out;
}

// Turns a script-supplied path into a real path inside the sandbox, or raises.
::fs::path resolve(lua_State* l, const std::string& filepath, bool allow_dll = false) {
    if (filepath.find("..") != std::string::npos) {
        raise(l, "This API does not allow access to parent directories");
    }

    if (::fs::path{filepath}.is_absolute()) {
        raise(l, "This API does not allow the use of absolute paths");
    }

    const auto subpath = strip_magic_prefix(::fs::path{filepath});

    if (subpath.string().find("..") != std::string::npos) {
        raise(l, "This API does not allow access to parent directories");
    }

    if (subpath.is_absolute()) {
        raise(l, "This API does not allow the use of absolute paths");
    }

    auto path = datadir(locate(filepath)) / subpath;

    // Letting a script drop a DLL or EXE on disk is asking for trouble.
    if (!allow_dll) {
        const auto ext = lowercase_extension(path);

        if (ext == ".dll" || ext == ".exe") {
            raise(l, "This API does not allow interacting with executables or DLLs");
        }
    }

    return path;
}
} // namespace
} // namespace detail

sol::table glob(sol::this_state l, const char* filter, const char* modifier) {
    sol::state_view state{l};

    std::optional<std::regex> filter_regex;
    try {
        filter_regex.emplace(filter != nullptr ? filter : ".*");
    } catch (const std::regex_error& e) {
        // An invalid pattern would otherwise throw std::regex_error across the Lua
        // boundary; turn it into a Lua error so a script typo can't crash the game.
        luaL_error(l, "fs.glob: invalid pattern: %s", e.what());
        return state.create_table();
    }

    auto results = state.create_table();
    const auto& root = detail::datadir(detail::locate(modifier != nullptr ? modifier : ""));

    ::fs::create_directories(root);

    auto i = 0;

    for (const auto& entry : ::fs::recursive_directory_iterator{root}) {
        if (!entry.is_regular_file() && !entry.is_symlink()) {
            continue;
        }

        // Entries come straight from the iterator, so the relative path is a pure
        // string operation here (fs::relative would canonicalize on disk).
        auto relpath = entry.path().lexically_relative(root).string();

        if (std::regex_match(relpath, *filter_regex)) {
            results[++i] = relpath;
        }
    }

    return results;
}

void write(sol::this_state l, const std::string& filepath, const std::string& data) {
    const auto path = detail::resolve(l, filepath);

    ::fs::create_directories(path.parent_path());

    std::ofstream{path} << data;
}

std::string read(sol::this_state l, const std::string& filepath) {
    const auto path = detail::resolve(l, filepath);

    if (!::fs::exists(path)) {
        return "";
    }

    ::fs::create_directories(path.parent_path());

    std::ifstream file{path};
    return std::string(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
}
} // namespace api::fs

namespace {
// Resolves the path argument of an io function through the sandbox, keeping the
// stock behaviour for nil (the default stdin/stdout/stderr streams). `old` is
// the original Lua implementation being wrapped.
sol::object sandboxed_io(sol::this_state l, sol::object arg, const char* name, const sol::function& old) {
    if (arg == sol::nil) {
        return old(sol::nil);
    }

    if (!arg.is<std::string>()) {
        api::fs::detail::raise(l, std::string{name} + ": expected a string or nil as the first argument");
    }

    const auto path = api::fs::detail::resolve(l, arg.as<std::string>());

    fs::create_directories(path.parent_path());

    return old(path.string());
}
} // namespace

void bindings::open_fs(ScriptState* s) {
    auto& lua = s->lua();
    // Named `fs_table` rather than `fs` on purpose: a local called `fs` would
    // hide the std::filesystem alias used below.
    auto fs_table = lua.create_table();

    fs_table["glob"] = api::fs::glob;
    fs_table["write"] = api::fs::write;
    fs_table["read"] = api::fs::read;
    lua["fs"] = fs_table;

    lua.open_libraries(sol::lib::io);

    // Replace the io functions with safe versions that can't be used to access parent directories and can't be used to open files outside of the data directory.
    // Addendum: Now io APIs can access the "natives" directory relative to the executable.
    auto io = lua["io"];

    sol::function old_open = io["open"];

    io["open"] = [old_open](sol::this_state l, const std::string& filepath, sol::object mode) -> sol::object {
        const auto path = api::fs::detail::resolve(l, filepath);

        fs::create_directories(path.parent_path());

        return old_open(path.string(), mode);
    };

    // I don't want to allow this. If someone really wants this functionality, they can just make a C++ plugin and use the C++ API.
    io["popen"] = sol::make_object(lua, sol::nil);

    // These functions can take nil as the first argument and they will return the default filehandle associated with stdin, stdout, or stderr.
    // So they should be safe in that respect.
    for (const auto* fn : {"lines", "input", "output"}) {
        const auto name = std::string{"io."} + fn;
        sol::function old = io[fn];

        io[fn] = [name, old](sol::this_state l, sol::object filepath_or_nil) -> sol::object {
            return sandboxed_io(l, filepath_or_nil, name.c_str(), old);
        };
    }

    sol::function old_require = lua["require"];

    lua["require"] = [old_require](sol::this_state l, const std::string& filepath) -> sol::object {
        if (filepath.find("..") != std::string::npos) {
            api::fs::detail::raise(l, "require does not allow access to parent directories");
        }

        if (fs::path{filepath}.is_absolute()) {
            api::fs::detail::raise(l, "require does not allow the use of absolute paths");
        }

        // Do not allow modification of the package path or cpath. We restore it to a pristine value before calling the original require.
        auto lua = sol::state_view{l};
        lua["package"]["path"] = lua.registry()["package_path"];
        lua["package"]["cpath"] = lua.registry()["package_cpath"];
        lua["package"]["searchers"] = lua.create_table();

        sol::table searchers = lua.registry()["package_searchers"];
        for (auto&& [k, v] : searchers) {
            lua["package"]["searchers"][k] = v;
        }

        return old_require(filepath);
    };

    sol::function old_loadlib = lua["package"]["loadlib"];

    lua["package"]["loadlib"] = [old_loadlib](sol::this_state l, const std::string& filepath, const std::string& funcname) -> sol::object {
        const auto path = api::fs::detail::resolve(l, filepath, true);

        if (api::fs::detail::lowercase_extension(path) != ".dll") {
            api::fs::detail::raise(l, "package.loadlib: only DLLs are allowed");
        }

        return old_loadlib(filepath, funcname);
    };
}

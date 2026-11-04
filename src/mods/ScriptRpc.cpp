#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
// winsock2 must come before windows.h, which ScriptRunner.hpp pulls in.
#include <winsock2.h>
#include <ws2tcpip.h>

#include <algorithm>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <deque>
#include <string>
#include <string_view>
#include <thread>
#include <vector>

#include <json.hpp>
#include <lua.h>
#include <lauxlib.h>
#include <spdlog/spdlog.h>

#include "ScriptRpc.hpp"
#include "ScriptRunner.hpp"

using json = nlohmann::json;

namespace {

constexpr size_t kMaxHeaderBytes = 16 * 1024;
constexpr size_t kMaxBodyBytes = 256 * 1024;
constexpr size_t kMaxQueuedJobs = 64;

// A request runs on the frame thread, so the instruction budget is what keeps
// `while true do end` from freezing the game: 20M instructions is well under a
// tenth of a second for typical reflection-heavy code.
constexpr uint64_t kInstructionBudget = 20'000'000;
constexpr int kHookSlice = 100'000;

constexpr int kMaxSerializeDepth = 6;
constexpr int kMaxTableEntries = 200;
constexpr int kMaxJsonNodes = 4000;

std::string lower(std::string_view text) {
    std::string out{text};
    std::transform(out.begin(), out.end(), out.begin(), [](unsigned char c) { return (char)std::tolower(c); });
    return out;
}

std::string trim(std::string_view text) {
    const auto first = text.find_first_not_of(" \t\r\n");

    if (first == std::string_view::npos) {
        return {};
    }

    const auto last = text.find_last_not_of(" \t\r\n");
    return std::string{text.substr(first, last - first + 1)};
}

// --- Lua -> JSON ------------------------------------------------------------

struct NodeBudget {
    int remaining{kMaxJsonNodes};
};

json lua_to_json(lua_State* L, int index, NodeBudget& budget, int depth);

json lua_table_to_json(lua_State* L, int index, NodeBudget& budget, int depth) {
    // A table whose keys are all positive integers becomes a JSON array; anything
    // else becomes an object so scripts can return named structures.
    bool is_array = true;
    int counted = 0;

    lua_pushnil(L);

    while (lua_next(L, index) != 0) {
        if (lua_type(L, -2) != LUA_TNUMBER || !lua_isinteger(L, -2) || lua_tointeger(L, -2) < 1) {
            is_array = false;
        }

        lua_pop(L, 1); // value; the key stays for the next lua_next

        if (++counted > kMaxTableEntries) {
            lua_pop(L, 1); // the leftover key
            break;
        }
    }

    json result = is_array ? json::array() : json::object();

    if (is_array) {
        const lua_Integer count = std::min<lua_Integer>((lua_Integer)lua_rawlen(L, index), kMaxTableEntries);

        for (lua_Integer i = 1; i <= count; ++i) {
            lua_rawgeti(L, index, i);
            result.push_back(lua_to_json(L, -1, budget, depth + 1));
            lua_pop(L, 1);
        }

        return result;
    }

    int emitted = 0;
    lua_pushnil(L);

    while (lua_next(L, index) != 0) {
        std::string key{};

        switch (lua_type(L, -2)) {
        case LUA_TSTRING: {
            size_t length = 0;
            const char* text = lua_tolstring(L, -2, &length);
            key.assign(text, length);
            break;
        }
        case LUA_TNUMBER:
            key = lua_isinteger(L, -2) ? std::to_string(lua_tointeger(L, -2)) : std::to_string(lua_tonumber(L, -2));
            break;
        default:
            key = std::string{"<"} + luaL_typename(L, -2) + ">";
            break;
        }

        result[key] = lua_to_json(L, -1, budget, depth + 1);
        lua_pop(L, 1); // value

        if (++emitted >= kMaxTableEntries) {
            lua_pop(L, 1); // the leftover key
            break;
        }
    }

    return result;
}

json lua_to_json(lua_State* L, int index, NodeBudget& budget, int depth) {
    index = lua_absindex(L, index);

    if (--budget.remaining < 0) {
        return "<truncated>";
    }

    switch (lua_type(L, index)) {
    case LUA_TNIL:
        return nullptr;

    case LUA_TBOOLEAN:
        return lua_toboolean(L, index) != 0;

    case LUA_TNUMBER: {
        if (lua_isinteger(L, index)) {
            return (int64_t)lua_tointeger(L, index);
        }

        const double value = lua_tonumber(L, index);

        if (!std::isfinite(value)) {
            return std::isnan(value) ? "nan" : (value > 0.0 ? "inf" : "-inf");
        }

        return value;
    }

    case LUA_TSTRING: {
        size_t length = 0;
        const char* text = lua_tolstring(L, index, &length);
        return std::string(text, length);
    }

    case LUA_TTABLE:
        return depth >= kMaxSerializeDepth ? json{"<table: max depth>"} : lua_table_to_json(L, index, budget, depth);

    case LUA_TFUNCTION:
        return "<function>";

    case LUA_TTHREAD:
        return "<thread>";

    default: {
        // userdata / lightuserdata: the metatable name plus address is what a
        // caller needs to keep going; never calls __tostring here because this
        // runs outside the protected call.
        std::string name{"userdata"};

        if (lua_getmetatable(L, index) != 0) {
            lua_pushliteral(L, "__name");
            lua_rawget(L, -2);

            if (lua_type(L, -1) == LUA_TSTRING) {
                name = lua_tostring(L, -1);
            }

            lua_pop(L, 2);
        }

        char address[32]{};
        std::snprintf(address, sizeof(address), "%p", lua_topointer(L, index));
        return "<" + name + ": " + address + ">";
    }
    }
}

// --- instruction budget -----------------------------------------------------

struct InstructionBudget {
    uint64_t remaining{kInstructionBudget};
    bool exceeded{false};
};

thread_local InstructionBudget* g_active_budget{nullptr};

void budget_hook(lua_State* L, lua_Debug*) {
    if (g_active_budget == nullptr) {
        lua_sethook(L, nullptr, 0, 0);
        return;
    }

    if (g_active_budget->remaining <= (uint64_t)kHookSlice) {
        g_active_budget->remaining = 0;
        g_active_budget->exceeded = true;
        lua_sethook(L, nullptr, 0, 0);
        luaL_error(L, "instruction budget exceeded (possible infinite loop)");
        return;
    }

    g_active_budget->remaining -= (uint64_t)kHookSlice;
}

// Replaces print() for the duration of one request so callers see the same text
// the log gets. The upvalue is the buffer owned by the running request.
int capture_print(lua_State* L) {
    auto* output = static_cast<std::string*>(lua_touserdata(L, lua_upvalueindex(1)));

    if (output == nullptr) {
        return 0;
    }

    const int count = lua_gettop(L);

    for (int i = 1; i <= count; ++i) {
        size_t length = 0;
        const char* text = luaL_tolstring(L, i, &length); // may raise; we are inside pcall here

        if (text != nullptr) {
            if (i > 1) {
                output->push_back('\t');
            }

            output->append(text, length);
        }

        lua_pop(L, 1);
    }

    output->push_back('\n');
    return 0;
}

json run_lua(ScriptState& state, const std::string& code, bool expression) {
    lua_State* L = state.lua().lua_state();
    const int base = lua_gettop(L);

    json response{};
    response["ok"] = false;
    response["elapsed_ms"] = 0;
    std::string output{};

    // Keep the original print at base + 1 so it can be restored on every path.
    lua_getglobal(L, "print");
    lua_pushlightuserdata(L, &output);
    lua_pushcclosure(L, capture_print, 1);
    lua_setglobal(L, "print");

    const std::string chunk = expression ? ("return " + code) : code;

    if (luaL_loadbufferx(L, chunk.data(), chunk.size(), "=rpc", "t") != LUA_OK) {
        const char* message = lua_tostring(L, -1);
        response["error"] = message != nullptr ? message : "failed to compile the chunk";
    } else {
        InstructionBudget budget{};
        g_active_budget = &budget;
        lua_sethook(L, budget_hook, LUA_MASKCOUNT, kHookSlice);

        const auto start = std::chrono::steady_clock::now();
        const int status = lua_pcall(L, 0, LUA_MULTRET, 0);
        response["elapsed_ms"] = (uint32_t)std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now() - start).count();

        lua_sethook(L, nullptr, 0, 0);
        g_active_budget = nullptr;

        if (status != LUA_OK) {
            const char* message = lua_tostring(L, -1);
            response["error"] = message != nullptr ? message : "unknown Lua error";

            if (budget.exceeded) {
                response["budget_exceeded"] = true;
            }
        } else {
            NodeBudget nodes{};
            json returns = json::array();
            // The saved print sits at base + 1, so results start after it.
            const int results_base = base + 1;
            const int result_count = lua_gettop(L) - results_base;

            for (int i = 1; i <= result_count; ++i) {
                returns.push_back(lua_to_json(L, results_base + i, nodes, 0));
            }

            response["ok"] = true;
            response["returns"] = std::move(returns);
        }
    }

    lua_pushvalue(L, base + 1);
    lua_setglobal(L, "print");
    lua_settop(L, base);

    if (!output.empty()) {
        response["print"] = std::move(output);
    }

    return response;
}

// --- HTTP -------------------------------------------------------------------

struct HttpRequest {
    std::string method{};
    std::string target{};
    std::string body{};
    size_t content_length{0};
};

const char* reason_phrase(int status) {
    switch (status) {
    case 200: return "OK";
    case 400: return "Bad Request";
    case 404: return "Not Found";
    case 405: return "Method Not Allowed";
    case 429: return "Too Many Requests";
    case 503: return "Service Unavailable";
    case 504: return "Gateway Timeout";
    default: return "Unknown";
    }
}

std::string to_payload(const json& body) {
    // replace: game strings are not necessarily valid UTF-8, and dump() throws on
    // invalid input without an error handler.
    return body.dump(-1, ' ', false, json::error_handler_t::replace);
}

std::string http_response(int status, const std::string& payload) {
    std::string head = "HTTP/1.1 " + std::to_string(status) + " " + reason_phrase(status) + "\r\n";
    head += "Content-Type: application/json; charset=utf-8\r\n";
    head += "Content-Length: " + std::to_string(payload.size()) + "\r\n";
    head += "Connection: close\r\n\r\n";

    return head + payload;
}

void send_all(SOCKET client, const std::string& data) {
    size_t sent = 0;

    while (sent < data.size()) {
        const int written = ::send(client, data.data() + sent, (int)(data.size() - sent), 0);

        if (written <= 0) {
            return;
        }

        sent += (size_t)written;
    }
}

bool read_http_request(SOCKET client, HttpRequest& request, std::string& error) {
    std::string raw{};
    char chunk[4096]{};
    size_t header_end = std::string::npos;

    while (header_end == std::string::npos) {
        const int received = ::recv(client, chunk, sizeof(chunk), 0);

        if (received <= 0) {
            error = "connection closed before the headers arrived";
            return false;
        }

        raw.append(chunk, (size_t)received);
        header_end = raw.find("\r\n\r\n");

        if (header_end == std::string::npos && raw.size() > kMaxHeaderBytes) {
            error = "headers too large";
            return false;
        }
    }

    const auto line_end = raw.find("\r\n");
    const std::string request_line = raw.substr(0, line_end);
    const auto first_space = request_line.find(' ');
    const auto second_space = first_space == std::string::npos ? std::string::npos : request_line.find(' ', first_space + 1);

    if (first_space == std::string::npos || second_space == std::string::npos) {
        error = "malformed request line";
        return false;
    }

    request.method = request_line.substr(0, first_space);
    request.target = request_line.substr(first_space + 1, second_space - first_space - 1);

    for (size_t pos = line_end + 2; pos < header_end;) {
        const auto next = raw.find("\r\n", pos);

        if (next == std::string::npos || next > header_end) {
            break;
        }

        const std::string line = raw.substr(pos, next - pos);
        pos = next + 2;

        const auto colon = line.find(':');

        if (colon == std::string::npos) {
            continue;
        }

        if (lower(trim(line.substr(0, colon))) == "content-length") {
            try {
                request.content_length = (size_t)std::stoul(trim(line.substr(colon + 1)));
            } catch (...) {
                error = "malformed content-length";
                return false;
            }
        }
    }

    if (request.content_length > kMaxBodyBytes) {
        error = "body too large";
        return false;
    }

    std::string body = raw.substr(header_end + 4);

    while (body.size() < request.content_length) {
        const int received = ::recv(client, chunk, sizeof(chunk), 0);

        if (received <= 0) {
            error = "connection closed while reading the body";
            return false;
        }

        body.append(chunk, (size_t)received);
    }

    request.body = body.substr(0, request.content_length);
    return true;
}

bool ensure_winsock() {
    static std::once_flag once{};
    static bool available = false;

    std::call_once(once, [] {
        WSADATA data{};
        available = WSAStartup(MAKEWORD(2, 2), &data) == 0;
    });

    return available;
}

} // namespace

// --- ScriptRpc --------------------------------------------------------------

ScriptRpc::~ScriptRpc() {
    stop();
}

bool ScriptRpc::start(uint16_t port) {
    if (m_running.load(std::memory_order_acquire)) {
        return true;
    }

    if (!ensure_winsock()) {
        return false;
    }

    const SOCKET listener = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (listener == INVALID_SOCKET) {
        return false;
    }

    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(INADDR_LOOPBACK); // loopback only, never the LAN

    if (::bind(listener, reinterpret_cast<sockaddr*>(&address), sizeof(address)) == SOCKET_ERROR ||
        ::listen(listener, 8) == SOCKET_ERROR) {
        {
            std::scoped_lock lock{m_error_mutex};
            m_last_error = "bind/listen on 127.0.0.1:" + std::to_string(port) + " failed with " +
                           std::to_string(WSAGetLastError());
            spdlog::error("[ScriptRpc] {}", m_last_error);
        }

        ::closesocket(listener);
        return false;
    }

    m_port = port;
    m_listen_socket = (uintptr_t)listener;
    m_running.store(true, std::memory_order_release);
    m_thread = std::jthread{[this](std::stop_token stop_token) { accept_loop(stop_token); }};

    spdlog::info("[ScriptRpc] Listening on http://127.0.0.1:{}/rpc", port);
    return true;
}

void ScriptRpc::stop() {
    if (!m_running.exchange(false, std::memory_order_acq_rel)) {
        return;
    }

    fail_pending();

    if (m_thread.joinable()) {
        m_thread.request_stop();
    }

    if (m_listen_socket != 0) {
        ::closesocket((SOCKET)m_listen_socket); // wakes the accept loop out of select()
        m_listen_socket = 0;
    }

    if (m_thread.joinable()) {
        m_thread.join();
    }

    m_thread = std::jthread{};
    spdlog::info("[ScriptRpc] Stopped");
}

std::string ScriptRpc::last_error() const {
    std::scoped_lock lock{m_error_mutex};
    return m_last_error;
}

void ScriptRpc::accept_loop(std::stop_token stop_token) {
    const SOCKET listener = (SOCKET)m_listen_socket;

    while (!stop_token.stop_requested()) {
        fd_set read_set;
        FD_ZERO(&read_set);
        FD_SET(listener, &read_set);

        timeval timeout{};
        timeout.tv_usec = 200 * 1000;

        if (::select(0, &read_set, nullptr, nullptr, &timeout) <= 0) {
            continue;
        }

        const SOCKET client = ::accept(listener, nullptr, nullptr);

        if (client == INVALID_SOCKET) {
            continue;
        }

        serve_client((uintptr_t)client);
        ::closesocket(client);
    }
}

void ScriptRpc::serve_client(uintptr_t client_raw) {
    const SOCKET client = (SOCKET)client_raw;
    DWORD timeout_ms = 10000;
    ::setsockopt(client, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout_ms, sizeof(timeout_ms));
    ::setsockopt(client, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout_ms, sizeof(timeout_ms));

    HttpRequest request{};
    std::string error{};

    if (!read_http_request(client, request, error)) {
        send_all(client, http_response(400, to_payload(json{{"ok", false}, {"error", error}})));
        return;
    }

    std::string response{};
    const int status = handle(request.method, request.target, request.body, response);
    send_all(client, http_response(status, response));
}

int ScriptRpc::handle(const std::string& method, const std::string& target, const std::string& body, std::string& response) {
    const auto path = target.substr(0, target.find('?'));

    if (path != "/rpc") {
        response = json{{"ok", false}, {"error", "POST /rpc is the only endpoint"}}.dump();
        return 404;
    }

    if (method != "POST") {
        response = json{{"ok", false}, {"error", "use POST /rpc"}}.dump();
        return 405;
    }

    auto job = std::make_shared<Job>();

    try {
        const json payload = json::parse(body);
        job->code = payload.value("code", std::string{});
        job->expression = payload.value("mode", std::string{"chunk"}) == "expr";
        job->timeout_ms = std::clamp(payload.value("timeout_ms", 5000u), 100u, 30000u);
    } catch (const std::exception& e) {
        response = json{{"ok", false}, {"error", std::string{"invalid request: "} + e.what()}}.dump();
        return 400;
    }

    if (job->code.empty()) {
        response = json{{"ok", false}, {"error", "code is required"}}.dump();
        return 400;
    }

    {
        std::scoped_lock lock{m_queue_mutex};

        if (m_queue.size() >= kMaxQueuedJobs) {
            response = json{{"ok", false}, {"error", "too many queued requests"}}.dump();
            return 429;
        }

        m_queue.push_back(job);
    }

    std::unique_lock lock{job->mutex};

    if (!job->cv.wait_for(lock, std::chrono::milliseconds{job->timeout_ms}, [&job] { return job->done; })) {
        // Mark it so a late drain skips code the client already gave up on.
        job->cancelled = true;
        lock.unlock();

        response = json{{"ok", false},
                        {"error", "timed out waiting for the game thread (paused, loading, or a long-running chunk)"}}
                       .dump();
        return 504;
    }

    response = std::move(job->body);
    m_served.fetch_add(1, std::memory_order_relaxed);
    return job->status;
}

void ScriptRpc::execute(ScriptRunner& runner, Job& job) {
    struct Unlocker {
        ScriptRunner& runner;
        ~Unlocker() { runner.unlock(); }
    };

    runner.lock();
    Unlocker unlocker{runner};

    const auto& state = runner.get_state();

    json response = state == nullptr
        ? json{{"ok", false}, {"error", "lua state is not ready yet (the game is still loading)"}}
        : run_lua(*state, job.code, job.expression);

    job.status = 200;
    job.body = response.dump(-1, ' ', false, json::error_handler_t::replace);
}

void ScriptRpc::fail_pending() {
    std::deque<JobPtr> pending{};

    {
        std::scoped_lock lock{m_queue_mutex};
        pending.swap(m_queue);
    }

    for (const auto& job : pending) {
        {
            std::scoped_lock lock{job->mutex};

            if (job->done) {
                continue;
            }

            job->status = 503;
            job->body = json{{"ok", false}, {"error", "rpc server stopped"}}.dump();
            job->done = true;
        }

        job->cv.notify_all();
    }
}

void ScriptRpc::drain(ScriptRunner& runner) {
    std::deque<JobPtr> jobs{};

    {
        std::scoped_lock lock{m_queue_mutex};

        if (m_queue.empty()) {
            return;
        }

        jobs.swap(m_queue);
    }

    for (const auto& job : jobs) {
        {
            std::scoped_lock lock{job->mutex};

            if (job->cancelled) {
                continue;
            }
        }

        execute(runner, *job);

        {
            std::scoped_lock lock{job->mutex};
            job->done = true;
        }

        job->cv.notify_all();
    }
}

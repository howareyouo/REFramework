-- The math usertypes: constructors, fields, methods, operators, and the
-- element access a matrix hands back as a borrowed pointer.
--
-- Everything here is constructed locally; no game state is touched. Floats go
-- through string.format so the report carries exact digits rather than the
-- tostring rounding one build happens to use. The names in a tostring come
-- from __name, so they double as a check that the metatable identifies itself
-- the way sol2's did.

local function f(x)
    return string.format("%.4f", x)
end

local function v3(v)
    return f(v.x) .. "," .. f(v.y) .. "," .. f(v.z)
end

local function v4(v)
    return v3(v) .. "," .. f(v.w)
end

-- Constructors: every overload and the error a wrong arity raises.
rep("vec2", v3(Vector2f.new(1.5, 2.5):to_vec3()))
rep("vec2 colon ctor", v3(Vector2f:new(3.0, 4.0):to_vec3()))
rep("vec3", v3(Vector3f.new(1.0, 2.0, 3.0)))
rep("vec4", v4(Vector4f.new(1.0, 2.0, 3.0, 4.0)))
rep("mat4 zero-arg", typename(Matrix4x4f.new()))
rep("mat4 rows", typename(Matrix4x4f.new(Vector4f.new(1, 0, 0, 0), Vector4f.new(0, 1, 0, 0),
    Vector4f.new(0, 0, 1, 0), Vector4f.new(0, 0, 0, 1))))
rep("mat4 16 floats", typename(Matrix4x4f.new(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1)))
rep("quat zero-arg", typename(Quaternion.new()))
rep("quat 4 floats", f(Quaternion.new(0.0, 0.0, 0.0, 1.0).w))
rep("quat from vec3", typename(Quaternion.new(Vector3f.new(0.0, 1.0, 0.0))))
rep("mat4 identity", typename(Matrix4x4f.identity()))

try("vec4 wrong arity", function() return Vector4f.new(1.0, 2.0, 3.0) end)
try("vec4 zero args", function() return Vector4f.new() end)
try("mat4 wrong arity", function() return Matrix4x4f.new(1.0, 2.0) end)
try("quat wrong type", function() return Quaternion.new(1.0, 2.0, 3.0, "x") end)
rep("vec2 wrong type", v3(Vector2f.new("a", 1.0):to_vec3()))
rep("vec4 loose ctor", v4(Vector4f.new(1.0, 2.0, 3.0, "x")))

-- Fields: read, write and restore, and the key shapes that miss.
local v = Vector3f.new(1.0, 2.0, 3.0)
rep("fields", v3(v))
v.y = 7.5
rep("field write", f(v.y))
v.y = 2.0
rep("field restore", f(v.y))
rep("unknown field", tostring(v.nope))
rep("integer key on vec", tostring(v[0]))
rep("field on quaternion", f(Quaternion.new(1.0, 2.0, 3.0, 4.0).z))
try("vec unknown field write", function() v.nope = 1.0 end)
try("vec wrong value write", function() v.x = "a" end)
rep("vec eq value", Vector3f.new(1.0, 2.0, 3.0) == Vector3f.new(1.0, 2.0, 3.0))

-- Methods. One call per method, values where the result is deterministic.
rep("vec3 dot", f(Vector3f.new(1.0, 2.0, 3.0):dot(Vector3f.new(4.0, 5.0, 6.0))))
rep("vec3 cross", v3(Vector3f.new(1.0, 0.0, 0.0):cross(Vector3f.new(0.0, 1.0, 0.0))))
rep("vec3 length", f(Vector3f.new(3.0, 4.0, 0.0):length()))
rep("vec3 normalized", v3(Vector3f.new(3.0, 0.0, 0.0):normalized()))
try("vec3 normalize in place", function()
    local w = Vector3f.new(2.0, 0.0, 0.0)
    w:normalize()
    return f(w.x)
end)
rep("vec3 clone", tostring(v3(Vector3f.new(1.0, 2.0, 3.0):clone()) == v3(Vector3f.new(1.0, 2.0, 3.0))))
rep("vec3 reflect", v3(Vector3f.new(1.0, -1.0, 0.0):reflect(Vector3f.new(0.0, 1.0, 0.0))))
rep("vec3 lerp", v3(Vector3f.new(0.0, 0.0, 0.0):lerp(Vector3f.new(2.0, 4.0, 6.0), 0.25)))
rep("vec3 to_vec2", v3(Vector3f.new(1.0, 2.0, 3.0):to_vec2():to_vec3()))
rep("vec2 to_vec4", v4(Vector2f.new(1.0, 2.0):to_vec4()))
rep("vec4 cross", f(Vector4f.new(1.0, 0.0, 0.0, 9.0):cross(Vector4f.new(0.0, 1.0, 0.0, 9.0)).z))

-- Operators on the value forms and the error a mismatched operand raises.
rep("vec3 add", v3(Vector3f.new(1.0, 2.0, 3.0) + Vector3f.new(10.0, 20.0, 30.0)))
rep("vec3 sub", v3(Vector3f.new(10.0, 20.0, 30.0) - Vector3f.new(1.0, 2.0, 3.0)))
rep("vec3 mul scalar", v3(Vector3f.new(1.0, 2.0, 3.0) * 2.0))
rep("vec2 add", v3((Vector2f.new(1.0, 2.0) + Vector2f.new(3.0, 4.0)):to_vec3()))
rep("vec4 mul scalar", f((Vector4f.new(1.0, 2.0, 3.0, 4.0) * 0.5).w))
try("vec3 add number", function() return Vector3f.new(1.0, 2.0, 3.0) + 1.0 end)
rep("vec3 mul string", v3(Vector3f.new(1.0, 2.0, 3.0) * "a"))
try("vec3 dot number", function() return Vector3f.new(1.0, 2.0, 3.0):dot(5.0) end)
try("vec3 dot nil", function() return Vector3f.new(1.0, 2.0, 3.0):dot(nil) end)
try("vec3 dot missing", function() return Vector3f.new(1.0, 2.0, 3.0):dot() end)

-- Quaternion methods and its operator overloads.
local q = Quaternion.new(0.0, 0.0, 0.0, 1.0)
rep("quat to_mat4", typename(q:to_mat4()))
rep("quat length", f(q:length()))
rep("quat dot self", f(q:dot(Quaternion.new(0.0, 0.0, 0.0, 1.0))))
rep("quat conjugate", v4(q:conjugate()))
rep("quat normalize", f(q:normalized().w))
rep("quat identity", f(Quaternion.identity().w))
rep("quat slerp", f(Quaternion.new(0.0, 0.0, 0.0, 1.0):slerp(Quaternion.new(0.0, 0.0, 0.0, 1.0), 0.5).w))
rep("quat inverse", f(q:inverse().w))
try("quat invert in place", function()
    local p = Quaternion.new(0.0, 0.0, 0.0, 1.0)
    p:invert()
    return f(p.w)
end)
rep("quat to_euler", typename(q:to_euler()))
rep("quat mul quat", v4(q * Quaternion.new(0.0, 0.0, 0.0, 1.0)))
rep("quat mul vec4", f((q * Vector4f.new(1.0, 2.0, 3.0, 4.0)).w))
rep("quat mul vec3", v3(q * Vector3f.new(1.0, 2.0, 3.0)))
rep("quat index 0", f(q[0]))
rep("quat index 3", f(q[3]))
rep("quat index 4", tostring(q[4]))
rep("quat index name", f(q.w))
try("quat index write round-trip", function()
    local p = Quaternion.new(0.0, 0.0, 0.0, 1.0)
    local saved = p[3]
    p[3] = 5.0
    local stored = p[3]
    p[3] = saved
    return f(stored)
end)

-- The matrix element is a borrowed pointer into the matrix, so reading a
-- component off it, cloning it and passing it back as a Vector4f are all
-- things a script does after m[0].
local m = Matrix4x4f.new(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1)
rep("mat4 index typename", typename(m[0]))
rep("mat4 index tostring", tostring(m[0]):gsub("%s*<addr>%s*$", ""))
rep("mat4 element field", f(m[0].x))
-- An integer key on the borrowed element reads nil; the members answer only
-- to their names.
rep("mat4 element integer index", tostring(m[1][2]))
try("mat4 element pairs", function()
    local n = 0

    for _ in pairs(m[0]) do
        n = n + 1
    end

    return n
end)
rep("mat4 element eq self", m[0] == m[0])
rep("mat4 element eq value", m[0] == Vector4f.new(1.0, 0.0, 0.0, 0.0))
rep("mat4 eq same", Matrix4x4f.new(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1)
    == Matrix4x4f.new(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1))
rep("mat4 eq different", Matrix4x4f.new() == Matrix4x4f.identity())
rep("quat eq same", Quaternion.new(1.0, 2.0, 3.0, 4.0) == Quaternion.new(1.0, 2.0, 3.0, 4.0))
rep("mat4 element clone", f(m[0]:clone().w))
rep("mat4 element length", f(m[0]:length()))
rep("mat4 rows to ctor", typename(Matrix4x4f.new(m[0], m[1], m[2], m[3])))
rep("mat4 mixed rows to ctor", typename(Matrix4x4f.new(m[0], Vector4f.new(0, 1, 0, 0),
    Vector4f.new(0, 0, 1, 0), Vector4f.new(0, 0, 0, 1))))
try("mat4 element write round-trip", function()
    local sx, sy, sz, sw = m[0].x, m[0].y, m[0].z, m[0].w
    m[0] = Vector4f.new(5.0, 6.0, 7.0, 8.0)
    local stored = v4(m[0])
    m[0] = Vector4f.new(sx, sy, sz, sw)
    return stored
end)
rep("mat4 element write restored", f(m[0].x))
rep("mat4 index out of range", tostring(m[4]))
try("mat4 index write out of range", function() m[9] = Vector4f.new(1.0, 1.0, 1.0, 1.0) end)
rep("mat4 element unknown", tostring(m[0].nope))
try("mat4 element unknown write", function() m[0].nope = 1.0 end)
try("mat4 element field write round-trip", function()
    local saved = m[0].y
    m[0].y = 9.0
    local stored = f(m[0].y)
    m[0].y = saved
    return stored
end)
try("mat4 element loose write", function()
    local saved = m[0].y
    m[0].y = "a"
    local stored = f(m[0].y)
    m[0].y = saved
    return stored
end)
rep("mat4 to_quat", typename(m:to_quat()))
rep("mat4 inverse", typename(m:inverse()))
try("mat4 invert in place", function()
    local p = Matrix4x4f.identity()
    p:invert()
    return typename(p)
end)
rep("mat4 interpolate", typename(Matrix4x4f.identity():interpolate(Matrix4x4f.identity(), 0.5)))
rep("mat4 matrix_rotation", typename(m:matrix_rotation()))
rep("mat4 mul mat4", typename(m * Matrix4x4f.identity()))
try("mat4 mul number", function() return m * 1.0 end)
try("quat mul number", function() return q * 1.0 end)
rep("mat4 mul vec4", f((m * Vector4f.new(1.0, 2.0, 3.0, 4.0)).w))
try("mat4 mul vec3", function() return m * Vector3f.new(1.0, 2.0, 3.0) end)
rep("mat4 unknown key", tostring(m.nope))
try("vec pairs", function()
    local n = 0

    for _ in pairs(Vector3f.new(1.0, 2.0, 3.0)) do
        n = n + 1
    end

    return n
end)
try("mat4 pairs", function()
    local n = 0

    for _ in pairs(Matrix4x4f.new()) do
        n = n + 1
    end

    return n
end)

-- The names every form of these types reports. The pointer form of a vector
-- reaches scripts through a matrix element, the value form through a
-- constructor or an engine read.
rep("name vec2", typename(Vector2f.new(1.0, 2.0)))
rep("name vec3", typename(Vector3f.new(1.0, 2.0, 3.0)))
rep("name vec4", typename(Vector4f.new(1.0, 2.0, 3.0, 4.0)))
rep("name mat4", typename(Matrix4x4f.new()))
rep("name quat", typename(Quaternion.new()))

-- An engine read hands back whatever the method database has for the camera;
-- only the shape is stable, so the report carries types, not coordinates.
try("engine vector read", function()
    local cam = sdk.get_primary_camera()

    if not cam then
        return "SKIP (no camera)"
    end

    local pos = cam:call("get_Position")

    if pos == nil then
        return "nil"
    end

    return typename(pos) .. " x=" .. math.type(pos.x)
end)

return finish()

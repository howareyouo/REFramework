#include <sdk/SceneManager.hpp>
#include <sdk/Renderer.hpp>

#define IMGUI_DEFINE_MATH_OPERATORS

#include <imgui.h>
#include <ImGuizmo.h>

#include "ImGui.hpp"

namespace imgui {
using namespace IMGUIZMO_NAMESPACE;

namespace {
constexpr int CIRCLE_SEGMENTS = 32;

auto get_proj_method = sdk::find_method_definition("via.Camera", "get_ProjectionMatrix");
auto get_view_method = sdk::find_method_definition("via.Camera", "get_ViewMatrix");

struct ScreenCircle {
    ImVec2 center{};
    float radius{};
};

struct GizmoMatrices {
    Matrix4x4f view{};
    Matrix4x4f proj{};
};

// The primary camera stays put for the duration of an ImGui frame, so its up
// vector is resolved once per frame instead of once per drawn shape.
const std::optional<Vector3f>& camera_up() {
    static int cached_frame = -1;
    static std::optional<Vector3f> cached{};

    const auto frame = ImGui::GetFrameCount();

    if (frame == cached_frame) {
        return cached;
    }

    cached_frame = frame;
    cached = std::nullopt;

    static auto transform_def = sdk::find_type_definition("via.Transform");
    static auto get_gameobject_method = transform_def->get_method("get_GameObject");
    static auto get_joints_method = transform_def->get_method("get_Joints");

    auto camera = sdk::get_primary_camera();

    if (camera == nullptr) {
        return cached;
    }

    auto camera_gameobject = get_gameobject_method->call<::REGameObject*>(sdk::get_thread_context(), camera);

    if (camera_gameobject == nullptr || camera_gameobject->transform == nullptr) {
        return cached;
    }

    auto camera_joints = get_joints_method->call<sdk::SystemArray*>(sdk::get_thread_context(), camera_gameobject->transform);

    if (camera_joints == nullptr) {
        return cached;
    }

    auto camera_joint = (::REJoint*)camera_joints->get_element(0);

    if (camera_joint == nullptr) {
        return cached;
    }

    cached = glm::normalize(sdk::get_joint_rotation(camera_joint) * Vector3f{ 0.0f, 1.0f, 0.0f });

    return cached;
}

// Projects pos and pos + up*radius into screen space; nullopt when the camera
// or either point is unavailable (e.g. behind it).
std::optional<ScreenCircle> project_circle(const Vector3f& pos, float radius) {
    const auto& up = camera_up();

    if (!up) {
        return std::nullopt;
    }

    const auto center = sdk::renderer::world_to_screen(pos);

    if (!center) {
        return std::nullopt;
    }

    const auto top = sdk::renderer::world_to_screen(pos + (*up * radius));

    if (!top) {
        return std::nullopt;
    }

    return ScreenCircle{ ImVec2{ center->x, center->y }, glm::length(*top - *center) };
}

void draw_circle(const ScreenCircle& circle, ImU32 color, bool outline) {
    auto* draw_list = ImGui::GetBackgroundDrawList();

    draw_list->AddCircleFilled(circle.center, circle.radius, color, CIRCLE_SEGMENTS);

    if (outline) {
        draw_list->AddCircle(circle.center, circle.radius,
            ImGui::GetColorU32(ImVec4(0.0f, 0.0f, 0.0f, 1.0f)), CIRCLE_SEGMENTS);
    }
}

// Points ImGuizmo at this frame's draw list/rect and fills view/proj from the
// primary camera. nullopt when there is no camera yet (e.g. during load).
std::optional<GizmoMatrices> gizmo_matrices() {
    auto camera = sdk::get_primary_camera();

    if (camera == nullptr) {
        return std::nullopt;
    }

    SetImGuiContext(ImGui::GetCurrentContext());
    SetDrawlist(ImGui::GetBackgroundDrawList());
    SetRect(0, 0, ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y);

    GizmoMatrices matrices{};
    get_proj_method->call<void*>(&matrices.proj, sdk::get_thread_context(), camera);
    get_view_method->call<void*>(&matrices.view, sdk::get_thread_context(), camera);

    return matrices;
}
}

std::optional<Vector3f> get_camera_up() {
    return camera_up();
}

bool draw_gizmo(Matrix4x4f& mat, OPERATION op, MODE mode) {
    auto matrices = gizmo_matrices();

    return matrices && Manipulate((float*)&matrices->view, (float*)&matrices->proj, op, mode, (float*)&mat);
}

void draw_cube(const Matrix4x4f& mat) {
    if (const auto matrices = gizmo_matrices()) {
        DrawCubes((float*)&matrices->view, (float*)&matrices->proj, (float*)&mat, 1);
    }
}

void draw_grid(const Matrix4x4f& mat, float size) {
    if (const auto matrices = gizmo_matrices()) {
        DrawGrid((float*)&matrices->view, (float*)&matrices->proj, (float*)&mat, size);
    }
}

void draw_sphere(const Vector3f& center, float radius, ImU32 color, bool outline) {
    if (const auto circle = project_circle(center, radius)) {
        draw_circle(*circle, color, outline);
    }
}

void draw_capsule(const Vector3f& start, const Vector3f& end, float radius, ImU32 color, bool outline) {
    const auto start_circle = project_circle(start, radius);
    const auto end_circle = project_circle(end, radius);

    if (start_circle) {
        draw_circle(*start_circle, color, outline);
    }

    if (end_circle) {
        draw_circle(*end_circle, color, outline);
    }

    if (!start_circle || !end_circle) {
        return;
    }

    const auto delta = end_circle->center - start_circle->center;
    const auto length = glm::length(Vector2f{ delta.x, delta.y });

    if (length <= 0.0f) {
        return;
    }

    // Axis perpendicular, scaled to each cap's on-screen radius.
    const ImVec2 perp{ -delta.y / length, delta.x / length };
    const ImVec2 start_offset{ perp.x * start_circle->radius, perp.y * start_circle->radius };
    const ImVec2 end_offset{ perp.x * end_circle->radius, perp.y * end_circle->radius };

    const ImVec2 start_left{ start_circle->center.x - start_offset.x, start_circle->center.y - start_offset.y };
    const ImVec2 start_right{ start_circle->center.x + start_offset.x, start_circle->center.y + start_offset.y };
    const ImVec2 end_left{ end_circle->center.x - end_offset.x, end_circle->center.y - end_offset.y };
    const ImVec2 end_right{ end_circle->center.x + end_offset.x, end_circle->center.y + end_offset.y };

    auto* draw_list = ImGui::GetBackgroundDrawList();

    draw_list->AddQuadFilled(start_left, end_left, end_right, start_right, color);

    if (outline) {
        draw_list->AddQuad(start_left, end_left, end_right, start_right,
            ImGui::GetColorU32(ImVec4(0.0f, 0.0f, 0.0f, 1.0f)));
    }
}
}

#undef IMGUI_DEFINE_MATH_OPERATORS

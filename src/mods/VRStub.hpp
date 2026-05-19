#pragma once

#include <memory>
#include <array>
#include <cmath>
#include <vector>

// VR stub - provides empty implementations when VR is disabled
class VR {
public:
    static std::shared_ptr<VR>& get() {
        static auto instance = std::make_shared<VR>();
        return instance;
    }

    bool is_hmd_active() const { return false; }
    bool is_openxr_loaded() const { return false; }
    bool is_using_controllers() const { return false; }
    bool is_using_multipass() const { return false; }
    
    // Vector3 structure
    struct Vector3 {
        float x = 0, y = 0, z = 0;
        
        Vector3 operator-(const Vector3& other) const {
            return {x - other.x, y - other.y, z - other.z};
        }
        
        Vector3 operator*(float scale) const {
            return {x * scale, y * scale, z * scale};
        }
    };
    
    // Quaternion structure
    struct Quaternion {
        float x = 0, y = 0, z = 0, w = 1;
    };
    
    Vector3 get_position(int index = 0) const { 
        return Vector3{};
    }
    
    Quaternion get_rotation(int index = 0) const {
        return Quaternion{};
    }
    
    std::array<int, 0> get_controllers() const { 
        return {};
    }
    
    float get_current_offset() const { 
        return 0.0f; 
    }
    
    unsigned int get_game_frame_count() const { 
        return 0u; 
    }
    
    unsigned int get_render_frame_count() const { 
        return 0u; 
    }
    
    void set_rotation_offset(const void* rotation) { 
        // Stub implementation - does nothing
    }
    
    // Controller related methods
    struct Vector2 {
        float x = 0, y = 0;
    };
    
    Vector2 get_left_stick_axis() const { return Vector2{}; }
    Vector2 get_right_stick_axis() const { return Vector2{}; }
    int get_left_joystick() const { return 0; }
    int get_right_joystick() const { return 0; }
    int get_action_grip() const { return 0; }
    int get_action_trigger() const { return 0; }
    
    bool is_action_active(int action, int joystick) const { return false; }
    
    // Standing origin methods
    Vector3 get_standing_origin() const { return Vector3{}; }
    void set_standing_origin(const Vector3& origin) { }
    
    // Last render matrix
    struct Matrix4x4 {
        float data[4][4] = {};
    };
    
    const Matrix4x4& get_last_render_matrix() const { 
        static Matrix4x4 empty_matrix{};
        return empty_matrix;
    }
    
    // Camera duplicator stub
    class CameraDuplicatorStub {
    public:
        std::vector<void*> get_relevant_scene_layers() const { return {}; }
    };
    
    CameraDuplicatorStub& get_camera_duplicator() {
        static CameraDuplicatorStub stub{};
        return stub;
    }
};

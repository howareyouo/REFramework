#pragma once

#include <memory>
#include <array>
#include <cmath>

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
};

#include <sdk/REMath.hpp>
#include <spdlog/spdlog.h>

#include "Enums_Internal.hpp"
#include "REString.hpp"
#include "RETransform.hpp"

namespace sdk {
Vector4f sdk::get_transform_position(RETransform* transform) {
    __declspec(align(16)) Vector4f out{};
    sdk::call_method<Vector4f*>("via.Transform", "get_Position", &out, sdk::get_thread_context(), transform);

    return out;
}

glm::quat sdk::get_transform_rotation(RETransform* transform) {
    __declspec(align(16)) glm::quat out{};
    sdk::call_method<glm::quat*>("via.Transform", "get_Rotation", &out, sdk::get_thread_context(), transform);

    return out;
}

REJoint* get_transform_joint_by_hash(RETransform* transform, uint32_t hash) {
    return sdk::call_method<REJoint*>("via.Transform", "getJointByHash", sdk::get_thread_context(), transform, hash);
}

REJoint* get_transform_joint_by_name(RETransform* transform, std::wstring_view name) {
    return sdk::call_method<REJoint*>("via.Transform", "getJointByName", sdk::get_thread_context(), transform, sdk::VM::create_managed_string(name));
}

sdk::SystemArray* get_transform_joints(RETransform* transform) {
    return sdk::call_method<sdk::SystemArray*>("via.Transform", "get_Joints", sdk::get_thread_context(), transform);
}

void set_transform_position(RETransform* transform, const Vector4f& pos, bool no_dirty) {
    if (!no_dirty) {
        __declspec(align(16)) Vector4f p = pos;
        sdk::call_method<void*>("via.Transform", "set_Position", sdk::get_thread_context(), transform, &p);
    } else {
        const auto parent_transform = sdk::call_method<RETransform*>("via.Transform", "get_Parent", sdk::get_thread_context(), transform);

        if (parent_transform != nullptr) {
            const auto parent_position = sdk::get_transform_position(parent_transform);
            const auto parent_rotation = sdk::get_transform_rotation(parent_transform);
            const auto local_diff = pos - parent_position;
            
            transform->position = glm::vec4{glm::inverse(parent_rotation) * glm::vec3{local_diff}, 1.0f};
        } else {
            transform->position = pos;
        }

        transform->worldTransform[3] = pos;
        transform->worldTransform[3].w = 1.0f;
    }
}

void set_transform_rotation(RETransform* transform, const glm::quat& rot) {
    __declspec(align(16)) glm::quat q = rot;
    sdk::call_method<void*>("via.Transform", "set_Rotation", sdk::get_thread_context(), transform, &q);
}

REJoint* sdk::get_joint_parent(REJoint* joint) {
    if (joint == nullptr || joint->info == nullptr || joint->info->parentJoint == -1) {
        return nullptr;
    }

    auto joint_transform = joint->parentTransform;

    // what da heck
    if (joint_transform == nullptr) {
        return nullptr;
    }

    return utility::re_transform::get_joint(*joint_transform, joint->info->parentJoint);
};

::RETransform* sdk::get_joint_owner(::REJoint* joint) {
    if (joint == nullptr) {
        return nullptr;
    }

    return sdk::call_method<::RETransform*>("via.Joint", "get_Owner", sdk::get_thread_context(), joint);
}

uint32_t get_joint_hash(REJoint* joint) {
    return sdk::call_method<uint32_t>("via.Joint", "get_NameHash", sdk::get_thread_context(), joint);
}

void sdk::set_joint_position(REJoint* joint, const Vector4f& position) {
    __declspec(align(16)) Vector4f pos = position;
    sdk::call_method<void*>("via.Joint", "set_Position", sdk::get_thread_context(), joint, &pos);
};

void sdk::set_joint_rotation(REJoint* joint, const glm::quat& rotation) {
    __declspec(align(16)) glm::quat rot = rotation;
    sdk::call_method<void*>("via.Joint", "set_Rotation", sdk::get_thread_context(), joint, &rot);
};

glm::quat sdk::get_joint_rotation(REJoint* joint) {
    __declspec(align(16)) glm::quat rotation{};
    sdk::call_method<glm::quat*>("via.Joint", "get_Rotation", &rotation, sdk::get_thread_context(), joint);

    return rotation;
};

Vector4f sdk::get_joint_position(REJoint* joint) {
    __declspec(align(16)) Vector4f position{};
    sdk::call_method<Vector4f*>("via.Joint", "get_Position", &position, sdk::get_thread_context(), joint);

    return position;
};

glm::quat sdk::get_joint_local_rotation(REJoint* joint) {
    __declspec(align(16)) glm::quat rotation{};
    sdk::call_method<glm::quat*>("via.Joint", "get_LocalRotation", &rotation, sdk::get_thread_context(), joint);

    return rotation;
};

Vector4f sdk::get_joint_local_position(REJoint* joint) {
    __declspec(align(16)) Vector4f position{};
    sdk::call_method<Vector4f*>("via.Joint", "get_LocalPosition", &position, sdk::get_thread_context(), joint);

    return position;
};

void sdk::set_joint_local_rotation(REJoint* joint, const glm::quat& rotation) {
    __declspec(align(16)) glm::quat rot = rotation;
    sdk::call_method<void*>("via.Joint", "set_LocalRotation", sdk::get_thread_context(), joint, &rot);
};

void sdk::set_joint_local_position(REJoint* joint, const Vector4f& position) {
    __declspec(align(16)) Vector4f pos = position;
    sdk::call_method<void*>("via.Joint", "set_LocalPosition", sdk::get_thread_context(), joint, &pos);
};

std::string sdk::get_joint_name(REJoint* joint) {
    auto sname = sdk::call_method<SystemString*>("via.Joint", "get_Name", sdk::get_thread_context(), joint);

    std::string name{};

    if (sname != nullptr) {
        name = utility::re_string::get_string(*sname);
    }

    return name;
}
}


namespace utility::re_transform {
REJoint* get_joint(const ::RETransform& transform, uint32_t index) {
    const auto joints = sdk::call_method<REArrayBase*>("via.Transform", "get_Joints", sdk::get_thread_context(), &transform);

    if (joints == nullptr) {
        return nullptr;
    }

    return utility::re_array::get_element<REJoint>(joints, index);
}

glm::mat4 calculate_base_transform(const ::RETransform& transform, REJoint* target) {
    if (target == nullptr) {
        return glm::identity<glm::mat4>();
    }

    auto parent = target->info->parentJoint;

    if (parent == -1) {
        return glm::identity<glm::mat4>();
    }

    auto parent_joint = get_joint(transform, parent);

    if (parent_joint == nullptr) {
        return glm::identity<glm::mat4>();
    }

    auto parent_transform = calculate_base_transform(transform, parent_joint);

    __declspec(align(16)) glm::quat base_rotation{};
    sdk::call_method<glm::quat*>("via.Joint", "get_BaseLocalRotation", &base_rotation, sdk::get_thread_context(), target);

    __declspec(align(16)) Vector4f base_position{};
    sdk::call_method<Vector4f*>("via.Joint", "get_BaseLocalPosition", &base_position, sdk::get_thread_context(), target);

    // Convert to matrix
    auto base_transform = glm::translate(glm::mat4(1.0f), glm::vec3(base_position.x, base_position.y, base_position.z)) * glm::mat4_cast(base_rotation);

    return parent_transform * base_transform;
}

void calculate_base_transforms(const ::RETransform& transform, REJoint* target, std::unordered_map<REJoint*, glm::mat4>& out) {
    if (auto it = out.find(target); it != out.end()) {
        return;
    }

    if (target == nullptr) {
        out[target] = glm::identity<glm::mat4>();
        return;
    }

    auto parent = target->info->parentJoint;

    if (parent == -1) {
        out[target] = glm::identity<glm::mat4>();
        return;
    }

    auto parent_joint = get_joint(transform, parent);

    if (parent_joint == nullptr) {
        out[target] = glm::identity<glm::mat4>();
        return;
    }

    calculate_base_transforms(transform, parent_joint, out);

    auto it = out.find(parent_joint);

    if (it == out.end()) {
        out[target] = glm::identity<glm::mat4>();
        return;
    }

    const auto& parent_transform = it->second;

    __declspec(align(16)) glm::quat base_rotation{};
    sdk::call_method<glm::quat*>("via.Joint", "get_BaseLocalRotation", &base_rotation, sdk::get_thread_context(), target);

    __declspec(align(16)) Vector4f base_position{};
    sdk::call_method<Vector4f*>("via.Joint", "get_BaseLocalPosition", &base_position, sdk::get_thread_context(), target);

    // Convert to matrix
    const auto base_transform = glm::translate(glm::mat4(1.0f), glm::vec3(base_position.x, base_position.y, base_position.z)) * glm::mat4_cast(base_rotation);

    out[target] = parent_transform * base_transform;
}

Vector4f calculate_tpose_pos_world(::RETransform& transform, REJoint* joint, uint32_t depth) {
    if (depth == 0) {
        depth = 1;
    }

    const auto player_pos = sdk::get_transform_position(&transform);
    const auto player_rot = sdk::get_transform_rotation(&transform);

    std::vector<::REJoint*> joints{};

    auto cur_joint = joint;

    for (auto i = 0; i < depth; ++i) {
        cur_joint = sdk::get_joint_parent(cur_joint);
        joints.push_back(cur_joint);
    }

    std::unordered_map<REJoint*, glm::mat4> known_joints{};
    utility::re_transform::calculate_base_transforms(transform, joint, known_joints);
    utility::re_transform::calculate_base_transforms(transform, cur_joint, known_joints);

    auto parent_pos = sdk::get_joint_position(cur_joint);
    auto parent_rot = sdk::get_joint_rotation(cur_joint);
    auto original_parent_pos = player_pos + (player_rot * known_joints[cur_joint][3]);

    for (auto i = 0; i < depth; ++i) {
        auto joint = joints[depth-i];

        utility::re_transform::calculate_base_transforms(transform, cur_joint, known_joints);

        auto original_pos = player_pos + (player_rot * known_joints[joint][3]);
        const auto diff = original_pos - original_parent_pos;
        const auto updated_pos = parent_pos + diff;
        
        original_parent_pos = original_pos;
        parent_pos = updated_pos;
    }

    const auto original_pos = player_pos + (player_rot * known_joints[joint][3]);
    const auto diff = original_pos - original_parent_pos;

    return parent_pos + diff;
}

void apply_joints_tpose(::RETransform& transform, const std::vector<REJoint*>& joints_initial, uint32_t additional_parents) {
    if (joints_initial.empty() || joints_initial[0] == nullptr) {
        spdlog::info("No joints to apply tpose");
        return;
    }
    
    auto joints = joints_initial;

    auto player_pos = sdk::get_transform_position(&transform);
    auto player_rot = sdk::get_transform_rotation(&transform);

    joints.insert(joints.begin(), sdk::get_joint_parent(joints[0]));

    for (auto i = 0; i < additional_parents; i++) {
        auto parent = sdk::get_joint_parent(joints[0]);

        if (parent == nullptr) {
            break;
        }

        joints.insert(joints.begin(), parent);
    }

    std::vector<Vector3f> original_positions(joints.size());
    std::vector<glm::quat> original_rotations(joints.size());
    std::vector<Vector3f> current_positions(joints.size());

    std::unordered_map<REJoint*, glm::mat4> base_transforms{};

    for (auto i = 0; i < joints.size(); i++) {
        auto joint = joints[i];

        if (joint == nullptr) {
            continue;
        }

        utility::re_transform::calculate_base_transforms(transform, joint, base_transforms);

        auto it = base_transforms.find(joint);

        if (it == base_transforms.end()) {
            continue;
        }

        const auto& base_transform = it->second;

        original_positions[i] = player_pos + (player_rot * base_transform[3]);
        original_rotations[i] = player_rot * glm::quat_cast(base_transform);
        current_positions[i] = sdk::get_joint_position(joints[i]);
    }

    // second pass
    for (auto i = 0; i < joints.size() - 1; i++) {
        auto joint = joints[i];

        if (joint == nullptr) {
            continue;
        }

        auto next_joint = joints[i + 1];

        if (next_joint != nullptr) {
            auto diff = original_positions[i + 1] - original_positions[i];
            auto updated_pos = Vector4f{current_positions[i] + diff, 1.0f};

            sdk::set_joint_position(next_joint, updated_pos);
            sdk::set_joint_rotation(next_joint, original_rotations[i+1]);

            current_positions[i + 1] = updated_pos;
        }
    }
}
}
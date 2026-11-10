#include <spdlog/spdlog.h>

#include <utility/Relocate.hpp>

#include "RETypeDB.hpp"
#include "REType.hpp"
#include "REContext.hpp"
#include "Memory.hpp"
#include "RENativeArray.hpp"

#include "MotionFsm2Layer.hpp"

namespace sdk {
namespace behaviortree {
namespace {
template <typename T, typename ArrayMember, typename ObjectGetter>
std::vector<T> collect_tree_entries(const TreeNode* node, ArrayMember array_member, ObjectGetter object_getter, bool skip_null = false) {
    const auto tree_data = node->get_data();

    if (tree_data == nullptr) {
        return {};
    }

    const auto tree_owner = node->get_owner();

    if (tree_owner == nullptr) {
        return {};
    }

    std::vector<T> out{};

    const auto& arr = tree_data->*array_member;

    for (auto i = 0; i < arr.count; ++i) {
        const auto entry = (tree_owner->*object_getter)(arr.data[i]);

        if (skip_null && entry == nullptr) {
            continue;
        }

        out.push_back(entry);
    }

    return out;
}

::REManagedObject* get_tree_object_entry(bool is_delay_setup_objects, uint32_t index,
        const regenny::via::ManagedObjectArray& static_arr,
        const regenny::via::ManagedObjectArray& delayed_arr,
        const regenny::via::ManagedObjectArray& normal_arr) {
    if (_bittest((const long*)&index, 30)) {
        const auto new_idx = index & 0xFFFFFFF;
        if (new_idx >= static_arr.count || static_arr.objects == nullptr) {
            return nullptr;
        }

        return (::REManagedObject*)static_arr.objects[new_idx];
    }

    if (is_delay_setup_objects) {
        if (index >= delayed_arr.count || delayed_arr.objects == nullptr) {
            return nullptr;
        }

        return (::REManagedObject*)delayed_arr.objects[index];
    }

    if (index >= normal_arr.count || normal_arr.objects == nullptr) {
        return nullptr;
    }

    return (::REManagedObject*)normal_arr.objects[index];
}
}

std::vector<TreeNode*> TreeNode::get_children() const {
    return collect_tree_entries<TreeNode*>(this, &regenny::via::behaviortree::TreeNodeData::children, &TreeObject::get_node, true);
}

std::vector<::REManagedObject*> TreeNode::get_unloaded_actions() const {
    return collect_tree_entries<::REManagedObject*>(this, &regenny::via::behaviortree::TreeNodeData::actions, &TreeObject::get_unloaded_action);
}

std::vector<::REManagedObject*> TreeNode::get_actions() const {
    // Push it back even if it's null, because the action may not be loaded
    // and we may want to compare indices, or just want to know what the action is before it's loaded.
    return collect_tree_entries<::REManagedObject*>(this, &regenny::via::behaviortree::TreeNodeData::actions, &TreeObject::get_action);
}

std::vector<::REManagedObject*> TreeNode::get_transition_conditions() const {
    return collect_tree_entries<::REManagedObject*>(this, &regenny::via::behaviortree::TreeNodeData::transition_conditions, &TreeObject::get_condition);
}

std::vector<::REManagedObject*> TreeNode::get_transition_events() const {
    return collect_tree_entries<::REManagedObject*>(this, &regenny::via::behaviortree::TreeNodeData::start_transitions, &TreeObject::get_transition);
}

std::vector<::REManagedObject*> TreeNode::get_conditions() const {
    return collect_tree_entries<::REManagedObject*>(this, &regenny::via::behaviortree::TreeNodeData::conditions, &TreeObject::get_condition);
}

std::vector<TreeNode*> TreeNode::get_states() const {
    return collect_tree_entries<TreeNode*>(this, &regenny::via::behaviortree::TreeNodeData::states, &TreeObject::get_node);
}

std::vector<TreeNode*> TreeNode::get_start_states() const {
    return collect_tree_entries<TreeNode*>(this, &regenny::via::behaviortree::TreeNodeData::start_states, &TreeObject::get_node);
}

void TreeNode::append_action(uint32_t action_index) {
    auto tree_data = get_data();

    if (tree_data == nullptr) {
        return;
    }

    auto& arr = *(sdk::NativeArrayNoCapacity<uint32_t>*)&tree_data->actions;
    arr.push_back(action_index);
}

void TreeNode::replace_action(uint32_t index, uint32_t action_index) {
    auto tree_data = get_data();

    if (tree_data == nullptr) {
        return;
    }

    if (index >= tree_data->actions.count) {
        return;
    }

    tree_data->actions.data[index] = action_index;
}

void TreeNode::remove_action(uint32_t index) {
    auto tree_data = get_data();

    if (tree_data == nullptr) {
        return;
    }

    auto& arr = *(sdk::NativeArrayNoCapacity<uint32_t>*)&tree_data->actions;
    arr.erase(index);
}

void TreeNode::relocate(uintptr_t old_start, uintptr_t old_end, uintptr_t new_start) {
    auto selector = (::REManagedObject*)get_selector();

    if (selector != nullptr && utility::re_managed_object::is_managed_object(selector)) {
        const auto td = utility::re_managed_object::get_type_definition(selector);

        if (td != nullptr) {
            utility::relocate_pointers((uint8_t*)selector, old_start, old_end, new_start, 1, sizeof(void*), td->get_size());
        }
    }

    utility::relocate_pointers((uint8_t*)this, old_start, old_end, new_start, 0, sizeof(void*), sizeof(*this));
}

void BehaviorTree::set_current_node(sdk::behaviortree::TreeNode* node, uint32_t tree_idx, void* set_node_info) {
    static auto method = sdk::find_method_definition("via.behaviortree.BehaviorTree", "setCurrentNode(System.UInt64, System.UInt32, via.behaviortree.SetNodeInfo)");

    if (method == nullptr) {
        return;
    }

    method->call(sdk::get_thread_context(), this, node->get_id(), tree_idx, set_node_info);
}

bool TreeObject::is_delayed() const {
    static auto bhvt_manager = sdk::get_native_singleton("via.behaviortree.BehaviorTreeManager");
    const auto bhvt_manager_t = sdk::find_type_definition("via.behaviortree.BehaviorTreeManager");

    if (bhvt_manager_t == nullptr) {
        return false;
    }

    const auto is_delay_setup_objects_prop = utility::re_type::get_field_desc(bhvt_manager_t->get_type(), "DelaySetupObjects");

    const auto is_delay_setup_objects = utility::re_managed_object::get_field<bool>((::REManagedObject*)bhvt_manager, is_delay_setup_objects_prop);

    if (!is_delay_setup_objects) {
        // For some reason this can happen
        if (this->actions.count == 0 && this->conditions.count == 0 && this->transitions.count == 0) {
            if (this->delayed_actions.count > 0 || this->delayed_conditions.count > 0 || this->delayed_transitions.count > 0) {
                return true;
            }
        }
    }

    return is_delay_setup_objects;
}

void TreeObject::relocate(uintptr_t old_start, uintptr_t old_end, sdk::NativeArrayNoCapacity<TreeNode>& new_nodes) {
    const auto new_start = (uintptr_t)new_nodes.begin();
    const auto new_end = (uintptr_t)new_nodes.end();

    for (auto& node : new_nodes) {
        node.relocate(old_start, old_end, new_start);
    }

    utility::relocate_pointers((uint8_t*)this, old_start, old_end, new_start, 1, sizeof(void*), sizeof(*this));

    this->root_node = new_nodes.begin();
}

void TreeObject::relocate_datas(uintptr_t old_start, uintptr_t old_end, sdk::NativeArrayNoCapacity<TreeNodeData>& new_nodes) {
    const auto new_start = (uintptr_t)new_nodes.begin();
    const auto new_end = (uintptr_t)new_nodes.end();

    // This ISN'T the data. This is the actual nodes. Inside of the nodes contains a pointer to the data
    // Which we need to fix.
    const auto& actual_nodes = this->get_node_array();

    // Fix the pointers that point to the data inside of the nodes.
    utility::relocate_pointers((uint8_t*)actual_nodes.begin(), old_start, old_end, new_start, 1, sizeof(void*), actual_nodes.size() * sizeof(TreeNode));
    utility::relocate_pointers((uint8_t*)this, old_start, old_end, new_start, 1, sizeof(void*), sizeof(*this));
}

::REManagedObject* TreeObject::get_uservariable_hub() const {
    static uint32_t uservar_hub_offset = [this]() -> uint32_t {
        spdlog::info("Searching for uservar hub offset...");

        for (auto i = 0; i < sizeof(*this); i += sizeof(void*)) {
            const auto obj = *(::REManagedObject**)((uintptr_t)this + i);

            if (obj == nullptr || !utility::re_managed_object::is_managed_object(obj)) {
                continue;
            }

            if (utility::re_managed_object::is_a(obj, "via.userdata.UserVariablesHub")) {
                spdlog::info("Found uservar hub at offset {:x}", i);
                return i;
            }
        }

        spdlog::error("Failed to find UserVariablesHub in TreeObject");
        return 0;
    }();

    return *(::REManagedObject**)((uintptr_t)this + uservar_hub_offset);
}

void CoreHandle::relocate(uintptr_t old_start, uintptr_t old_end, sdk::NativeArrayNoCapacity<TreeNode>& new_nodes) {
    const auto new_start = (uintptr_t)new_nodes.begin();
    const auto new_end = (uintptr_t)new_nodes.end();

    this->get_tree_object()->relocate(old_start, old_end, new_nodes);

    utility::relocate_pointers((uint8_t*)this, old_start, old_end, new_start, 1, sizeof(void*), sizeof(*this));
}

void CoreHandle::relocate_datas(uintptr_t old_start, uintptr_t old_end, sdk::NativeArrayNoCapacity<TreeNodeData>& new_nodes) {
    const auto new_start = (uintptr_t)new_nodes.begin();
    const auto new_end = (uintptr_t)new_nodes.end();

    this->get_tree_object()->relocate_datas(old_start, old_end, new_nodes);

    utility::relocate_pointers((uint8_t*)this, old_start, old_end, new_start, 1, sizeof(void*), sizeof(*this));
}

::REManagedObject* TreeObject::get_action(uint32_t index) const {
    const auto is_delay_setup_objects = is_delayed();

    if (this->data == nullptr) {
        return nullptr;
    }

    return get_tree_object_entry(is_delay_setup_objects, index, this->data->static_actions, this->delayed_actions, this->actions);
}

::REManagedObject* TreeObject::get_unloaded_action(uint32_t index) const {
    if (this->data == nullptr) {
        return nullptr;
    }

    if (_bittest((const long*)&index, 30)) {
        const auto new_idx = index & 0xFFFFFFF;
        if (new_idx >= this->data->static_actions.count || this->data->static_actions.objects == nullptr) {
            return nullptr;
        }

        return (::REManagedObject*)this->data->static_actions.objects[new_idx];
    } else {
        if (index >= this->data->actions.count || this->data->actions.objects == nullptr) {
            return nullptr;
        }

        return (::REManagedObject*)this->data->actions.objects[index];
    }
}

::REManagedObject* TreeObject::get_condition(int32_t index) const {
    const auto is_delay_setup_objects = is_delayed();

    if (this->data == nullptr || index == -1) {
        return nullptr;
    }

    return get_tree_object_entry(is_delay_setup_objects, index, this->data->static_conditions, this->delayed_conditions, this->conditions);
}

::REManagedObject* TreeObject::get_transition(int32_t index) const {
    const auto is_delay_setup_objects = is_delayed();

    if (this->data == nullptr) {
        return nullptr;
    }

    return get_tree_object_entry(is_delay_setup_objects, index, this->data->static_transitions, this->delayed_transitions, this->transitions);
}

uint32_t TreeObject::get_action_count() const {
    const auto is_delay_setup_objects = is_delayed();

    return is_delay_setup_objects ? this->delayed_actions.count : this->actions.count;
}

uint32_t TreeObject::get_condition_count() const {
    const auto is_delay_setup_objects = is_delayed();

    return is_delay_setup_objects ? this->delayed_conditions.count : this->conditions.count;
}

uint32_t TreeObject::get_transition_count() const {
    const auto is_delay_setup_objects = is_delayed();

    return is_delay_setup_objects ? this->delayed_transitions.count : this->transitions.count;
}
}
}
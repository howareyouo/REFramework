#include "RETypeDB.hpp"

#include "SystemArray.hpp"

size_t sdk::SystemArray::get_size() {
    return (size_t)sdk::call_method_safe<int32_t>("System.Array", "GetLength", sdk::get_thread_context(), this, 0);
}

::REManagedObject* sdk::SystemArray::get_element(int32_t index) {
    if (index < 0 || index >= get_size()) {
        return nullptr;
    }

    return sdk::call_method_safe<::REManagedObject*>("System.Array", "GetValue(System.Int32)", sdk::get_thread_context(), this, index);
}

void sdk::SystemArray::set_element(int32_t index, ::REManagedObject* value) {
    if (index < 0 || index >= get_size()) {
        throw std::out_of_range("index out of range");
    }

    sdk::call_method_safe<void>("System.Array", "SetValue(System.Object, System.Int32)", sdk::get_thread_context(), this, value, index);
}

std::vector<::REManagedObject*> sdk::SystemArray::get_elements() {
    std::vector<::REManagedObject*> elements{};
    const auto size = get_size();

    for (size_t i = 0; i < size; i++) {
        elements.push_back(get_element(i));
    }

    return elements;
}


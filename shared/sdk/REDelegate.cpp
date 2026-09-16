#include "REDelegate.hpp"

namespace sdk {
void Delegate::invoke() {
    auto ctx = sdk::get_thread_context();
    for (uint32_t i = 0; i < num_methods; i++) {
        auto& method = methods[i];
        if (method.func == nullptr) {
            continue;
        }

        method.func(ctx, method.object);
    }
}
}
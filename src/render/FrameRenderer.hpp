#pragma once

class REFramework;

namespace render {
    bool init_d3d11(REFramework& fw);
    void deinit_d3d11(REFramework& fw);
    bool init_d3d12(REFramework& fw);
    void deinit_d3d12(REFramework& fw);
    void on_frame_d3d11(REFramework& fw);
    void on_post_present_d3d11(REFramework& fw);
    void on_frame_d3d12(REFramework& fw);
    void on_post_present_d3d12(REFramework& fw);
}

// Trimmed cimgui - only wraps ImGui functions used by the REFramework project
#include <imgui.h>
#include <imgui_internal.h>
#include "cimgui.h"

// Basic struct constructors/destructors
CIMGUI_API ImVec2* ImVec2_ImVec2_Nil(void) { return IM_NEW(ImVec2)(); }
CIMGUI_API void ImVec2_destroy(ImVec2* self) { IM_DELETE(self); }
CIMGUI_API ImVec2* ImVec2_ImVec2_Float(float _x, float _y) { return IM_NEW(ImVec2)(_x, _y); }
CIMGUI_API ImVec4* ImVec4_ImVec4_Nil(void) { return IM_NEW(ImVec4)(); }
CIMGUI_API void ImVec4_destroy(ImVec4* self) { IM_DELETE(self); }
CIMGUI_API ImVec4* ImVec4_ImVec4_Float(float _x, float _y, float _z, float _w) { return IM_NEW(ImVec4)(_x, _y, _z, _w); }
CIMGUI_API ImTextureRef* ImTextureRef_ImTextureRef_Nil(void) { return IM_NEW(ImTextureRef)(); }
CIMGUI_API void ImTextureRef_destroy(ImTextureRef* self) { IM_DELETE(self); }
CIMGUI_API ImTextureRef* ImTextureRef_ImTextureRef_TextureID(ImTextureID tex_id) { return IM_NEW(ImTextureRef)(tex_id); }
CIMGUI_API ImTextureID ImTextureRef_GetTexID(ImTextureRef* self) { return self->GetTexID(); }

// Context
CIMGUI_API ImGuiContext* igCreateContext(ImFontAtlas* shared_font_atlas) { return ImGui::CreateContext(shared_font_atlas); }
CIMGUI_API void igDestroyContext(ImGuiContext* ctx) { return ImGui::DestroyContext(ctx); }
CIMGUI_API ImGuiContext* igGetCurrentContext() { return ImGui::GetCurrentContext(); }
CIMGUI_API void igSetCurrentContext(ImGuiContext* ctx) { return ImGui::SetCurrentContext(ctx); }
CIMGUI_API ImGuiIO* igGetIO_Nil() { return &ImGui::GetIO(); }
CIMGUI_API ImGuiPlatformIO* igGetPlatformIO_Nil() { return &ImGui::GetPlatformIO(); }
CIMGUI_API ImGuiStyle* igGetStyle() { return &ImGui::GetStyle(); }
CIMGUI_API void igNewFrame() { return ImGui::NewFrame(); }
CIMGUI_API void igEndFrame() { return ImGui::EndFrame(); }
CIMGUI_API void igRender() { return ImGui::Render(); }
CIMGUI_API ImDrawData* igGetDrawData() { return ImGui::GetDrawData(); }
CIMGUI_API void igStyleColorsDark(ImGuiStyle* dst) { return ImGui::StyleColorsDark(dst); }

// Allocators
CIMGUI_API void igSetAllocatorFunctions(ImGuiMemAllocFunc alloc_func, ImGuiMemFreeFunc free_func, void* user_data) { return ImGui::SetAllocatorFunctions(alloc_func, free_func, user_data); }
CIMGUI_API void igGetAllocatorFunctions(ImGuiMemAllocFunc* p_alloc_func, ImGuiMemFreeFunc* p_free_func, void** p_user_data) { return ImGui::GetAllocatorFunctions(p_alloc_func, p_free_func, p_user_data); }

// Windows
CIMGUI_API bool igBegin(const char* name, bool* p_open, ImGuiWindowFlags flags) { return ImGui::Begin(name, p_open, flags); }
CIMGUI_API void igEnd() { return ImGui::End(); }
CIMGUI_API bool igBeginChild_Str(const char* str_id, const ImVec2 size, ImGuiChildFlags child_flags, ImGuiWindowFlags window_flags) { return ImGui::BeginChild(str_id, size, child_flags, window_flags); }
CIMGUI_API void igEndChild() { return ImGui::EndChild(); }
CIMGUI_API bool igIsWindowFocused(ImGuiFocusedFlags flags) { return ImGui::IsWindowFocused(flags); }
CIMGUI_API bool igIsWindowHovered(ImGuiHoveredFlags flags) { return ImGui::IsWindowHovered(flags); }
CIMGUI_API ImDrawList* igGetWindowDrawList() { return ImGui::GetWindowDrawList(); }
CIMGUI_API void igGetWindowPos(ImVec2* pOut) { *pOut = ImGui::GetWindowPos(); }
CIMGUI_API void igGetWindowSize(ImVec2* pOut) { *pOut = ImGui::GetWindowSize(); }
CIMGUI_API void igSetNextWindowPos(const ImVec2 pos, ImGuiCond cond, const ImVec2 pivot) { return ImGui::SetNextWindowPos(pos, cond, pivot); }
CIMGUI_API void igSetNextWindowSize(const ImVec2 size, ImGuiCond cond) { return ImGui::SetNextWindowSize(size, cond); }

// Scroll
CIMGUI_API float igGetScrollX() { return ImGui::GetScrollX(); }
CIMGUI_API float igGetScrollY() { return ImGui::GetScrollY(); }
CIMGUI_API void igSetScrollX_Float(float scroll_x) { return ImGui::SetScrollX(scroll_x); }
CIMGUI_API void igSetScrollY_Float(float scroll_y) { return ImGui::SetScrollY(scroll_y); }
CIMGUI_API float igGetScrollMaxX() { return ImGui::GetScrollMaxX(); }
CIMGUI_API float igGetScrollMaxY() { return ImGui::GetScrollMaxY(); }
CIMGUI_API void igSetScrollHereX(float center_x_ratio) { return ImGui::SetScrollHereX(center_x_ratio); }
CIMGUI_API void igSetScrollHereY(float center_y_ratio) { return ImGui::SetScrollHereY(center_y_ratio); }
CIMGUI_API void igSetScrollFromPosX_Float(float local_x, float center_x_ratio) { return ImGui::SetScrollFromPosX(local_x, center_x_ratio); }
CIMGUI_API void igSetScrollFromPosY_Float(float local_y, float center_y_ratio) { return ImGui::SetScrollFromPosY(local_y, center_y_ratio); }

// Font/Stack
CIMGUI_API void igPushFont(ImFont* font, float font_size_base_unscaled) { return ImGui::PushFont(font, font_size_base_unscaled); }
CIMGUI_API void igPopFont() { return ImGui::PopFont(); }
CIMGUI_API float igGetFontSize() { return ImGui::GetFontSize(); }
CIMGUI_API void igPushStyleColor_U32(ImGuiCol idx, ImU32 col) { return ImGui::PushStyleColor(idx, col); }
CIMGUI_API void igPushStyleColor_Vec4(ImGuiCol idx, const ImVec4 col) { return ImGui::PushStyleColor(idx, col); }
CIMGUI_API void igPopStyleColor(int count) { return ImGui::PopStyleColor(count); }
CIMGUI_API void igPushStyleVar_Float(ImGuiStyleVar idx, float val) { return ImGui::PushStyleVar(idx, val); }
CIMGUI_API void igPushStyleVar_Vec2(ImGuiStyleVar idx, const ImVec2 val) { return ImGui::PushStyleVar(idx, val); }
CIMGUI_API void igPopStyleVar(int count) { return ImGui::PopStyleVar(count); }
CIMGUI_API void igPushItemWidth(float item_width) { return ImGui::PushItemWidth(item_width); }
CIMGUI_API void igPopItemWidth() { return ImGui::PopItemWidth(); }
CIMGUI_API void igSetNextItemWidth(float item_width) { return ImGui::SetNextItemWidth(item_width); }
CIMGUI_API float igCalcItemWidth() { return ImGui::CalcItemWidth(); }

// Color
CIMGUI_API ImU32 igGetColorU32_Col(ImGuiCol idx, float alpha_mul) { return ImGui::GetColorU32(idx, alpha_mul); }
CIMGUI_API ImU32 igGetColorU32_Vec4(const ImVec4 col) { return ImGui::GetColorU32(col); }
CIMGUI_API ImU32 igGetColorU32_U32(ImU32 col, float alpha_mul) { return ImGui::GetColorU32(col, alpha_mul); }
CIMGUI_API ImU32 igColorConvertFloat4ToU32(const ImVec4 in) { return ImGui::ColorConvertFloat4ToU32(in); }

// Cursor
CIMGUI_API void igGetCursorScreenPos(ImVec2* pOut) { *pOut = ImGui::GetCursorScreenPos(); }
CIMGUI_API void igSetCursorScreenPos(const ImVec2 pos) { return ImGui::SetCursorScreenPos(pos); }
CIMGUI_API void igGetCursorPos(ImVec2* pOut) { *pOut = ImGui::GetCursorPos(); }
CIMGUI_API void igSetCursorPos(const ImVec2 local_pos) { return ImGui::SetCursorPos(local_pos); }
CIMGUI_API void igGetCursorStartPos(ImVec2* pOut) { *pOut = ImGui::GetCursorStartPos(); }

// Layout
CIMGUI_API void igSeparator() { return ImGui::Separator(); }
CIMGUI_API void igSameLine(float offset_from_start_x, float spacing) { return ImGui::SameLine(offset_from_start_x, spacing); }
CIMGUI_API void igNewLine() { return ImGui::NewLine(); }
CIMGUI_API void igSpacing() { return ImGui::Spacing(); }
CIMGUI_API void igIndent(float indent_w) { return ImGui::Indent(indent_w); }
CIMGUI_API void igUnindent(float indent_w) { return ImGui::Unindent(indent_w); }
CIMGUI_API void igBeginGroup() { return ImGui::BeginGroup(); }
CIMGUI_API void igEndGroup() { return ImGui::EndGroup(); }

// ID
CIMGUI_API void igPushID_Str(const char* str_id) { return ImGui::PushID(str_id); }
CIMGUI_API void igPushID_Ptr(const void* ptr_id) { return ImGui::PushID(ptr_id); }
CIMGUI_API void igPushID_Int(int int_id) { return ImGui::PushID(int_id); }
CIMGUI_API void igPopID() { return ImGui::PopID(); }
CIMGUI_API ImGuiID igGetID_Str(const char* str_id) { return ImGui::GetID(str_id); }
CIMGUI_API ImGuiID igGetID_Ptr(const void* ptr_id) { return ImGui::GetID(ptr_id); }

// Text
CIMGUI_API void igTextUnformatted(const char* text, const char* text_end) { return ImGui::TextUnformatted(text, text_end); }
CIMGUI_API void igText(const char* fmt, ...) { va_list args; va_start(args, fmt); ImGui::TextV(fmt, args); va_end(args); }
CIMGUI_API void igTextV(const char* fmt, va_list args) { return ImGui::TextV(fmt, args); }
CIMGUI_API void igTextColored(const ImVec4 col, const char* fmt, ...) { va_list args; va_start(args, fmt); ImGui::TextColoredV(col, fmt, args); va_end(args); }
CIMGUI_API void igTextColoredV(const ImVec4 col, const char* fmt, va_list args) { return ImGui::TextColoredV(col, fmt, args); }
CIMGUI_API void igTextWrapped(const char* fmt, ...) { va_list args; va_start(args, fmt); ImGui::TextWrappedV(fmt, args); va_end(args); }
CIMGUI_API void igTextWrappedV(const char* fmt, va_list args) { return ImGui::TextWrappedV(fmt, args); }
CIMGUI_API void igBulletText(const char* fmt, ...) { va_list args; va_start(args, fmt); ImGui::BulletTextV(fmt, args); va_end(args); }

// Widgets
CIMGUI_API bool igButton(const char* label, const ImVec2 size) { return ImGui::Button(label, size); }
CIMGUI_API bool igSmallButton(const char* label) { return ImGui::SmallButton(label); }
CIMGUI_API bool igInvisibleButton(const char* str_id, const ImVec2 size, ImGuiButtonFlags flags) { return ImGui::InvisibleButton(str_id, size, flags); }
CIMGUI_API bool igArrowButton(const char* str_id, ImGuiDir dir) { return ImGui::ArrowButton(str_id, dir); }
CIMGUI_API bool igCheckbox(const char* label, bool* v) { return ImGui::Checkbox(label, v); }
CIMGUI_API void igProgressBar(float fraction, const ImVec2 size_arg, const char* overlay) { return ImGui::ProgressBar(fraction, size_arg, overlay); }

// Combo
CIMGUI_API bool igBeginCombo(const char* label, const char* preview_value, ImGuiComboFlags flags) { return ImGui::BeginCombo(label, preview_value, flags); }
CIMGUI_API void igEndCombo() { return ImGui::EndCombo(); }
CIMGUI_API bool igCombo_Str_arr(const char* label, int* current_item, const char* const items[], int items_count, int popup_max_height_in_items) { return ImGui::Combo(label, current_item, items, items_count, popup_max_height_in_items); }
CIMGUI_API bool igCombo_Str(const char* label, int* current_item, const char* items_separated_by_zeros, int popup_max_height_in_items) { return ImGui::Combo(label, current_item, items_separated_by_zeros, popup_max_height_in_items); }

// Drag/Slider/Input
CIMGUI_API bool igDragFloat(const char* label, float* v, float v_speed, float v_min, float v_max, const char* format, ImGuiSliderFlags flags) { return ImGui::DragFloat(label, v, v_speed, v_min, v_max, format, flags); }
CIMGUI_API bool igDragFloat2(const char* label, float v[2], float v_speed, float v_min, float v_max, const char* format, ImGuiSliderFlags flags) { return ImGui::DragFloat2(label, v, v_speed, v_min, v_max, format, flags); }
CIMGUI_API bool igDragFloat3(const char* label, float v[3], float v_speed, float v_min, float v_max, const char* format, ImGuiSliderFlags flags) { return ImGui::DragFloat3(label, v, v_speed, v_min, v_max, format, flags); }
CIMGUI_API bool igDragFloat4(const char* label, float v[4], float v_speed, float v_min, float v_max, const char* format, ImGuiSliderFlags flags) { return ImGui::DragFloat4(label, v, v_speed, v_min, v_max, format, flags); }
CIMGUI_API bool igDragInt(const char* label, int* v, float v_speed, int v_min, int v_max, const char* format, ImGuiSliderFlags flags) { return ImGui::DragInt(label, v, v_speed, v_min, v_max, format, flags); }
CIMGUI_API bool igSliderFloat(const char* label, float* v, float v_min, float v_max, const char* format, ImGuiSliderFlags flags) { return ImGui::SliderFloat(label, v, v_min, v_max, format, flags); }
CIMGUI_API bool igSliderInt(const char* label, int* v, int v_min, int v_max, const char* format, ImGuiSliderFlags flags) { return ImGui::SliderInt(label, v, v_min, v_max, format, flags); }
CIMGUI_API bool igInputText(const char* label, char* buf, size_t buf_size, ImGuiInputTextFlags flags, ImGuiInputTextCallback callback, void* user_data) { return ImGui::InputText(label, buf, buf_size, flags, callback, user_data); }
CIMGUI_API bool igInputTextMultiline(const char* label, char* buf, size_t buf_size, const ImVec2 size, ImGuiInputTextFlags flags, ImGuiInputTextCallback callback, void* user_data) { return ImGui::InputTextMultiline(label, buf, buf_size, size, flags, callback, user_data); }
CIMGUI_API bool igInputFloat(const char* label, float* v, float step, float step_fast, const char* format, ImGuiInputTextFlags flags) { return ImGui::InputFloat(label, v, step, step_fast, format, flags); }
CIMGUI_API bool igInputInt(const char* label, int* v, int step, int step_fast, ImGuiInputTextFlags flags) { return ImGui::InputInt(label, v, step, step_fast, flags); }

// Color picker/edit
CIMGUI_API bool igColorEdit3(const char* label, float col[3], ImGuiColorEditFlags flags) { return ImGui::ColorEdit3(label, col, flags); }
CIMGUI_API bool igColorEdit4(const char* label, float col[4], ImGuiColorEditFlags flags) { return ImGui::ColorEdit4(label, col, flags); }
CIMGUI_API bool igColorPicker3(const char* label, float col[3], ImGuiColorEditFlags flags) { return ImGui::ColorPicker3(label, col, flags); }
CIMGUI_API bool igColorPicker4(const char* label, float col[4], ImGuiColorEditFlags flags, const float* ref_col) { return ImGui::ColorPicker4(label, col, flags, ref_col); }

// Tree
CIMGUI_API bool igTreeNode_Str(const char* label) { return ImGui::TreeNode(label); }
CIMGUI_API bool igTreeNode_StrStr(const char* str_id, const char* fmt, ...) { va_list args; va_start(args, fmt); bool ret = ImGui::TreeNodeV(str_id, fmt, args); va_end(args); return ret; }
CIMGUI_API bool igTreeNode_Ptr(const void* ptr_id, const char* fmt, ...) { va_list args; va_start(args, fmt); bool ret = ImGui::TreeNodeV(ptr_id, fmt, args); va_end(args); return ret; }
CIMGUI_API bool igTreeNodeV_Str(const char* str_id, const char* fmt, va_list args) { return ImGui::TreeNodeV(str_id, fmt, args); }
CIMGUI_API bool igTreeNodeV_Ptr(const void* ptr_id, const char* fmt, va_list args) { return ImGui::TreeNodeV(ptr_id, fmt, args); }
CIMGUI_API bool igTreeNodeEx_Str(const char* label, ImGuiTreeNodeFlags flags) { return ImGui::TreeNodeEx(label, flags); }
CIMGUI_API bool igTreeNodeEx_StrStr(const char* str_id, ImGuiTreeNodeFlags flags, const char* fmt, ...) { va_list args; va_start(args, fmt); bool ret = ImGui::TreeNodeExV(str_id, flags, fmt, args); va_end(args); return ret; }
CIMGUI_API bool igTreeNodeEx_Ptr(const void* ptr_id, ImGuiTreeNodeFlags flags, const char* fmt, ...) { va_list args; va_start(args, fmt); bool ret = ImGui::TreeNodeExV(ptr_id, flags, fmt, args); va_end(args); return ret; }
CIMGUI_API bool igTreeNodeExV_Str(const char* str_id, ImGuiTreeNodeFlags flags, const char* fmt, va_list args) { return ImGui::TreeNodeExV(str_id, flags, fmt, args); }
CIMGUI_API bool igTreeNodeExV_Ptr(const void* ptr_id, ImGuiTreeNodeFlags flags, const char* fmt, va_list args) { return ImGui::TreeNodeExV(ptr_id, flags, fmt, args); }
CIMGUI_API void igTreePush_Str(const char* str_id) { return ImGui::TreePush(str_id); }
CIMGUI_API void igTreePush_Ptr(const void* ptr_id) { return ImGui::TreePush(ptr_id); }
CIMGUI_API void igTreePop() { return ImGui::TreePop(); }
CIMGUI_API bool igCollapsingHeader_TreeNodeFlags(const char* label, ImGuiTreeNodeFlags flags) { return ImGui::CollapsingHeader(label, flags); }
CIMGUI_API bool igCollapsingHeader_BoolPtr(const char* label, bool* p_visible, ImGuiTreeNodeFlags flags) { return ImGui::CollapsingHeader(label, p_visible, flags); }
CIMGUI_API void igSetNextItemOpen(bool is_open, ImGuiCond cond) { return ImGui::SetNextItemOpen(is_open, cond); }

// Selectable
CIMGUI_API bool igSelectable_Bool(const char* label, bool selected, ImGuiSelectableFlags flags, const ImVec2 size) { return ImGui::Selectable(label, selected, flags, size); }
CIMGUI_API bool igSelectable_BoolPtr(const char* label, bool* p_selected, ImGuiSelectableFlags flags, const ImVec2 size) { return ImGui::Selectable(label, p_selected, flags, size); }

// ListBox
CIMGUI_API bool igBeginListBox(const char* label, const ImVec2 size) { return ImGui::BeginListBox(label, size); }
CIMGUI_API void igEndListBox() { return ImGui::EndListBox(); }

// Menu
CIMGUI_API bool igBeginMenuBar() { return ImGui::BeginMenuBar(); }
CIMGUI_API void igEndMenuBar() { return ImGui::EndMenuBar(); }
CIMGUI_API bool igBeginMainMenuBar() { return ImGui::BeginMainMenuBar(); }
CIMGUI_API void igEndMainMenuBar() { return ImGui::EndMainMenuBar(); }
CIMGUI_API bool igBeginMenu(const char* label, bool enabled) { return ImGui::BeginMenu(label, enabled); }
CIMGUI_API void igEndMenu() { return ImGui::EndMenu(); }
CIMGUI_API bool igMenuItem_Bool(const char* label, const char* shortcut, bool selected, bool enabled) { return ImGui::MenuItem(label, shortcut, selected, enabled); }
CIMGUI_API bool igMenuItem_BoolPtr(const char* label, const char* shortcut, bool* p_selected, bool enabled) { return ImGui::MenuItem(label, shortcut, p_selected, enabled); }

// Tooltip/Popup
CIMGUI_API bool igBeginTooltip() { return ImGui::BeginTooltip(); }
CIMGUI_API void igEndTooltip() { return ImGui::EndTooltip(); }
CIMGUI_API void igSetTooltip(const char* fmt, ...) { va_list args; va_start(args, fmt); ImGui::SetTooltipV(fmt, args); va_end(args); }
CIMGUI_API void igSetTooltipV(const char* fmt, va_list args) { return ImGui::SetTooltipV(fmt, args); }
CIMGUI_API bool igBeginPopup(const char* str_id, ImGuiWindowFlags flags) { return ImGui::BeginPopup(str_id, flags); }
CIMGUI_API void igEndPopup() { return ImGui::EndPopup(); }
CIMGUI_API void igOpenPopup_Str(const char* str_id, ImGuiPopupFlags popup_flags) { return ImGui::OpenPopup(str_id, popup_flags); }
CIMGUI_API void igCloseCurrentPopup() { return ImGui::CloseCurrentPopup(); }
CIMGUI_API bool igBeginPopupContextItem(const char* str_id, ImGuiPopupFlags popup_flags) { return ImGui::BeginPopupContextItem(str_id, popup_flags); }
CIMGUI_API bool igIsPopupOpen_Str(const char* str_id, ImGuiPopupFlags flags) { return ImGui::IsPopupOpen(str_id, flags); }

// Disabled
CIMGUI_API void igBeginDisabled(bool disabled) { return ImGui::BeginDisabled(disabled); }
CIMGUI_API void igEndDisabled() { return ImGui::EndDisabled(); }

// IsItem
CIMGUI_API bool igIsItemHovered(ImGuiHoveredFlags flags) { return ImGui::IsItemHovered(flags); }
CIMGUI_API bool igIsItemActive() { return ImGui::IsItemActive(); }
CIMGUI_API bool igIsItemFocused() { return ImGui::IsItemFocused(); }
CIMGUI_API void igGetItemRectMin(ImVec2* pOut) { *pOut = ImGui::GetItemRectMin(); }
CIMGUI_API void igGetItemRectMax(ImVec2* pOut) { *pOut = ImGui::GetItemRectMax(); }
CIMGUI_API void igSetItemDefaultFocus() { return ImGui::SetItemDefaultFocus(); }

// DrawList
CIMGUI_API ImDrawList* igGetBackgroundDrawList_Nil() { return ImGui::GetBackgroundDrawList(); }
CIMGUI_API ImDrawList* igGetForegroundDrawList_Nil() { return ImGui::GetForegroundDrawList(); }
CIMGUI_API ImGuiViewport* igGetMainViewport() { return ImGui::GetMainViewport(); }

// Calc
CIMGUI_API void igCalcTextSize(ImVec2* pOut, const char* text, const char* text_end, bool hide_text_after_double_hash, float wrap_width) { *pOut = ImGui::CalcTextSize(text, text_end, hide_text_after_double_hash, wrap_width); }

// Keyboard/Mouse
CIMGUI_API bool igIsKeyDown_Nil(ImGuiKey key) { return ImGui::IsKeyDown(key); }
CIMGUI_API bool igIsKeyPressed_Bool(ImGuiKey key, bool repeat) { return ImGui::IsKeyPressed(key, repeat); }
CIMGUI_API bool igIsKeyReleased_Nil(ImGuiKey key) { return ImGui::IsKeyReleased(key); }
CIMGUI_API bool igIsMouseDown_Nil(ImGuiMouseButton button) { return ImGui::IsMouseDown(button); }
CIMGUI_API bool igIsMouseClicked_Bool(ImGuiMouseButton button, bool repeat) { return ImGui::IsMouseClicked(button, repeat); }
CIMGUI_API bool igIsMouseReleased_Nil(ImGuiMouseButton button) { return ImGui::IsMouseReleased(button); }
CIMGUI_API bool igIsMouseDoubleClicked_Nil(ImGuiMouseButton button) { return ImGui::IsMouseDoubleClicked(button); }
CIMGUI_API void igGetMousePos(ImVec2* pOut) { *pOut = ImGui::GetMousePos(); }
CIMGUI_API ImGuiMouseCursor igGetMouseCursor() { return ImGui::GetMouseCursor(); }
CIMGUI_API void igSetMouseCursor(ImGuiMouseCursor cursor_type) { return ImGui::SetMouseCursor(cursor_type); }

// Clipboard
CIMGUI_API const char* igGetClipboardText() { return ImGui::GetClipboardText(); }
CIMGUI_API void igSetClipboardText(const char* text) { return ImGui::SetClipboardText(text); }

// Table
CIMGUI_API bool igBeginTable(const char* str_id, int columns, ImGuiTableFlags flags, const ImVec2 outer_size, float inner_width) { return ImGui::BeginTable(str_id, columns, flags, outer_size, inner_width); }
CIMGUI_API void igEndTable() { return ImGui::EndTable(); }
CIMGUI_API void igTableNextRow(ImGuiTableRowFlags row_flags, float min_row_height) { return ImGui::TableNextRow(row_flags, min_row_height); }
CIMGUI_API bool igTableNextColumn() { return ImGui::TableNextColumn(); }
CIMGUI_API bool igTableSetColumnIndex(int column_n) { return ImGui::TableSetColumnIndex(column_n); }
CIMGUI_API void igTableSetupColumn(const char* label, ImGuiTableColumnFlags flags, float init_width_or_weight, ImGuiID user_id) { return ImGui::TableSetupColumn(label, flags, init_width_or_weight, user_id); }
CIMGUI_API void igTableSetupScrollFreeze(int cols, int rows) { return ImGui::TableSetupScrollFreeze(cols, rows); }
CIMGUI_API void igTableHeader(const char* label) { return ImGui::TableHeader(label); }
CIMGUI_API void igTableHeadersRow() { return ImGui::TableHeadersRow(); }
CIMGUI_API ImGuiTableSortSpecs* igTableGetSortSpecs() { return ImGui::TableGetSortSpecs(); }
CIMGUI_API int igTableGetColumnCount() { return ImGui::TableGetColumnCount(); }
CIMGUI_API int igTableGetColumnIndex() { return ImGui::TableGetColumnIndex(); }
CIMGUI_API int igTableGetRowIndex() { return ImGui::TableGetRowIndex(); }
CIMGUI_API const char* igTableGetColumnName_Int(int column_n) { return ImGui::TableGetColumnName(column_n); }
CIMGUI_API ImGuiTableColumnFlags igTableGetColumnFlags(int column_n) { return ImGui::TableGetColumnFlags(column_n); }
CIMGUI_API void igTableSetBgColor(ImGuiTableBgTarget target, ImU32 color, int column_n) { return ImGui::TableSetBgColor(target, color, column_n); }

// Current window
CIMGUI_API ImGuiWindow* igGetCurrentWindow() { return ImGui::GetCurrentWindow(); }

// Item sizing
CIMGUI_API bool igItemAdd(const ImRect bb, ImGuiID id, const ImRect* nav_bb, ImGuiItemFlags extra_flags) { return ImGui::ItemAdd(bb, id, nav_bb, extra_flags); }
CIMGUI_API void igItemSize_Vec2(const ImVec2 size, float text_baseline_y) { return ImGui::ItemSize(size, text_baseline_y); }

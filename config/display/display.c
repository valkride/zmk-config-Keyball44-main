#include <zmk/display/widgets/battery_status.h>
#include <zmk/display/widgets/bt_status.h>
#include <zmk/display/widgets/layer_status.h>
#include <lvgl.h>

static lv_obj_t *widget;

lv_obj_t *custom_status_widget_create(lv_obj_t *parent) {
    widget = lv_obj_create(parent);

    // Top row: battery + BT profile
    lv_obj_t *top_row = lv_cont_create(widget, NULL);
    lv_cont_set_layout(top_row, LV_LAYOUT_ROW_MID);

    lv_obj_t *battery = zmk_battery_status_create(top_row);
    lv_obj_t *bt = zmk_bt_status_create(top_row);

    // Below: active layer
    lv_obj_t *layer = zmk_layer_status_create(widget);

    lv_obj_align(top_row, NULL, LV_ALIGN_IN_TOP_MID, 0, 0);
    lv_obj_align(layer, top_row, LV_ALIGN_OUT_BOTTOM_MID, 0, 2);

    return widget;
}
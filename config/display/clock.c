#include <lvgl.h>
#include <zephyr/kernel.h>
#include <stdio.h>
#include <time.h>

static lv_obj_t *widget;
static lv_obj_t *label;

lv_obj_t *clock_widget_create(lv_obj_t *parent) {
    widget = lv_obj_create(parent);
    label = lv_label_create(widget, NULL);
    lv_label_set_text(label, "12:34"); // Static test text
    lv_obj_align(label, NULL, LV_ALIGN_CENTER, 0, 0);
    return widget;
}
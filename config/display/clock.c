#include <lvgl.h>
#include <zephyr/kernel.h>
#include <stdio.h>
#include <time.h>

static lv_obj_t *widget;
static lv_obj_t *label;
static struct k_work_delayable clock_timer;

static void update_time(struct k_work *work) {
    static char buf[6];
    struct tm now = {0};

    // Replace this with your platform's RTC/time function if needed
    extern void zmk_rtc_get_time(struct tm *now);
    zmk_rtc_get_time(&now);

    snprintf(buf, sizeof(buf), "%02d:%02d", now.tm_hour, now.tm_min);
    lv_label_set_text(label, buf);

    // Schedule next update in 60 seconds
    k_work_schedule(&clock_timer, K_SECONDS(60));
}

lv_obj_t *clock_widget_create(lv_obj_t *parent) {
    widget = lv_obj_create(parent);
    label = lv_label_create(widget, NULL);
    lv_label_set_text(label, "00:00");
    lv_obj_align(label, NULL, LV_ALIGN_CENTER, 0, 0);

    k_work_init_delayable(&clock_timer, update_time);
    // Update immediately, then every minute
    k_work_schedule(&clock_timer, K_NO_WAIT);

    return widget;
}
#include "mou_brr.h"

static bool burst_active = false;
static uint16_t last_click_timer = 0;

bool process_mou_brr(uint16_t keycode, keyrecord_t *record, uint16_t trigger) {
    if (keycode == trigger && record->event.pressed) {
        burst_active = true;
        last_click_timer = timer_read();
        return false;
    }

    if (burst_active && record->event.pressed) {
        burst_active = false;
    }

    return true;
}

void mou_brr_task(void) {
    if (burst_active && timer_elapsed(last_click_timer) > 50) {
        register_code(MS_BTN1);
        unregister_code(MS_BTN1);
        last_click_timer = timer_read();
    }
}

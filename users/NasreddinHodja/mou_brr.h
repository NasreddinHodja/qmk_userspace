#pragma once
#include QMK_KEYBOARD_H

bool process_mou_brr(uint16_t keycode, keyrecord_t *record, uint16_t trigger);
void mou_brr_task(void);

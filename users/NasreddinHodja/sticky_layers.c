#include "sticky_layers.h"

bool should_stick = false;
uint8_t last_sticky_layer = 0;

bool is_sticky_layer(uint8_t layer) {
    for (uint8_t i = 0; i < sticky_layer_count; i++) {
        if (sticky_layers[i] == layer) return true;
    }
    return false;
}

void handle_layer_stick(uint16_t keycode, keyrecord_t *record) {
    uint8_t active = get_highest_layer(layer_state);

    if (record->event.pressed && is_sticky_layer(active)) {
        bool valid_key = (keymap_key_to_keycode(active, record->event.key) != KC_TRNS &&
                          keycode != KC_NO);
        should_stick = valid_key;

        if (should_stick) last_sticky_layer = active;
        else layer_off(active);
    }
}

layer_state_t handle_sticky_layer_state(layer_state_t state, uint8_t layer) {
    if (should_stick && layer != last_sticky_layer) {
        state |= (1UL << last_sticky_layer);
        should_stick = false;
    }
    return state;
}

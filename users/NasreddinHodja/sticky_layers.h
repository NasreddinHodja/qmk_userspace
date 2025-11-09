#pragma once
#include QMK_KEYBOARD_H

extern const uint8_t sticky_layers[];
extern const uint8_t sticky_layer_count;
extern bool should_stick;
extern uint8_t last_sticky_layer;

bool is_sticky_layer(uint8_t layer);
void handle_layer_stick(uint16_t keycode, keyrecord_t *record);
layer_state_t handle_sticky_layer_state(layer_state_t state, uint8_t layer);

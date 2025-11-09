#pragma once
#include "quantum.h"

extern const char* const layer_names[];
extern const uint8_t layer_count;

void send_layer_report(uint8_t layer);

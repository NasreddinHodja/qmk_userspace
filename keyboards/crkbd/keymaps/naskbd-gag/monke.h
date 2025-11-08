#pragma once

#include "quantum.h"

#define MONKE_MIN_WORD_LENGTH 1
#define MONKE_MAX_WORD_LENGTH 12
#define MONKE_DELAY_MS 50

void monke_init(void);

void monke_start(void);
void monke_stop(void);
bool monke_is_active(void);

void monke_task(void);

bool monke_process_record(uint16_t keycode, keyrecord_t* record);

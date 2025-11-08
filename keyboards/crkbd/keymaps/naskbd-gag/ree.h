#pragma once

#include "quantum.h"

// Configuration
#define REE_DELAY_MS 50   // Delay between each 'e' in milliseconds

// Start/stop ree generation
void ree_start(void);
void ree_stop(void);
bool ree_is_active(void);

// Call this from matrix_scan_user
void ree_task(void);

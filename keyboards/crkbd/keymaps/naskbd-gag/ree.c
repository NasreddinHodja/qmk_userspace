#include "ree.h"

static bool is_reeing = false;
static bool initial_sent = false;
static uint32_t last_send_time = 0;

void ree_start(void) {
    is_reeing = true;
    initial_sent = false;
    last_send_time = timer_read32();

    send_string("REEEEEEEEEEEEEEEEE");
    initial_sent = true;
}

void ree_stop(void) {
    is_reeing = false;
    initial_sent = false;
}

bool ree_is_active(void) {
    return is_reeing;
}

void ree_task(void) {
    if (!is_reeing) {
        return;
    }

    if (timer_elapsed32(last_send_time) < REE_DELAY_MS) {
        return;
    }

    send_string("EEEEEEEEEEEEEEEE");
    last_send_time = timer_read32();
}

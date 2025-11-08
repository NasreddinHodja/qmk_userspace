#include <string.h>
#include <stdlib.h>

#include "monke.h"

static const char CHARSET[] = "abcdefghijklmnopqrstuvwxyz";
#define CHARSET_SIZE (sizeof(CHARSET) - 1)

static bool is_generating = false;
static uint32_t last_send_time = 0;
static uint32_t seed = 0;

static uint32_t monke_rand(void) {
    seed = (1103515245 * seed + 12345) & 0x7FFFFFFF;
    return seed;
}

void monke_init(void) {
    is_generating = false;
    seed = timer_read32();
}

void monke_start(void) {
    is_generating = true;
    last_send_time = timer_read32();
    seed ^= timer_read32();
}

void monke_stop(void) {
    is_generating = false;
}

bool monke_is_active(void) {
    return is_generating;
}

static void generate_random_word(void) {
    char word[MONKE_MAX_WORD_LENGTH + 1] = {0};

    uint32_t rand_val = monke_rand();
    uint8_t length;

    uint8_t length_dice = rand_val % 100;
    if (length_dice < 40) {
        length = (rand_val % 3) + 1;  // 1-3
    } else if (length_dice < 80) {
        length = (rand_val % 3) + 4;  // 4-6
    } else {
        length = (rand_val % 6) + 7;  // 7-12
    }

    if (length > MONKE_MAX_WORD_LENGTH) {
        length = MONKE_MAX_WORD_LENGTH;
    }

    for (uint8_t i = 0; i < length; i++) {
        rand_val = monke_rand();
        word[i] = CHARSET[rand_val % CHARSET_SIZE];
    }

    word[length] = '\0';

    send_string(word);
    send_string(" ");
}

void monke_task(void) {
    if (!is_generating) {
        return;
    }

    if (timer_elapsed32(last_send_time) < MONKE_DELAY_MS) {
        return;
    }

    generate_random_word();
    last_send_time = timer_read32();
}

bool monke_process_record(uint16_t keycode, keyrecord_t* record) {
    return true;
}

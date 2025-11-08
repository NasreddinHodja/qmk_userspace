#include <stdint.h>

#include "raw_hid.h"

#include QMK_KEYBOARD_H

#include "monke.h"
#include "samara.h"
#include "ree.h"

enum custom_keycodes {
    MONKE = SAFE_RANGE,
    SAMRA,
    REE,
};

// base mods
#define HRGUI(key) MT(MOD_LGUI, key)
#define HRALT(key) MT(MOD_LALT, key)
#define HRCTL(key) MT(MOD_LCTL, key)
#define HRSFT(key) MT(MOD_LSFT, key)
#define HRAGR(key) MT(MOD_RALT, key)

#define SYM_LGUI LGUI_T(KC_0)
#define SYM_LALT LALT_T(KC_1)
#define SYM_LCTL LCTL_T(KC_2)
#define SYM_LSFT LSFT_T(KC_3)
#define SYM_RGUI LGUI_T(KC_4)
#define SYM_RALT LALT_T(KC_5)
#define SYM_RCTL LCTL_T(KC_6)
#define SYM_RSFT LSFT_T(KC_7)

// overrides
const key_override_t home_ko = ko_make_basic(MOD_MASK_CTRL, KC_HOME, MS_WHLL);
const key_override_t pgdn_ko = ko_make_basic(MOD_MASK_CTRL, KC_PGDN, MS_WHLD);
const key_override_t pgup_ko = ko_make_basic(MOD_MASK_CTRL, KC_PGUP, MS_WHLU);
const key_override_t end_ko  = ko_make_basic(MOD_MASK_CTRL, KC_END, MS_WHLR);

const key_override_t dmrec_ko = ko_make_basic(MOD_MASK_CTRL, DM_REC1, DM_REC2);
const key_override_t dmply_ko = ko_make_basic(MOD_MASK_CTRL, DM_PLY1, DM_PLY2);

const key_override_t* key_overrides[] = {
    &home_ko,
    &pgdn_ko,
    &pgup_ko,
    &end_ko,
    &dmrec_ko,
    &dmply_ko,
};

// combos
const uint16_t PROGMEM tab_combo[]    = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM quote_combo[]  = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM circ_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM dquote_combo[]   = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM tilde_combo[]  = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM hash_combo[]  = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM dlr_combo[]  = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM ampr_combo[]  = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM caps_combo[]  = {KC_L, KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM del_combo[]  = {KC_W, KC_F, KC_P, COMBO_END};

combo_t key_combos[] = {
    COMBO(tab_combo, KC_TAB),
    COMBO(quote_combo, KC_QUOT),
    COMBO(circ_combo, KC_CIRC),
    COMBO(dquote_combo, KC_DQUO),
    COMBO(tilde_combo, KC_TILD),
    COMBO(hash_combo, KC_HASH),
    COMBO(ampr_combo, KC_AMPR),
    COMBO(dlr_combo, KC_DLR),
    COMBO(caps_combo, KC_CAPS),
    COMBO(del_combo, KC_DEL),
};

enum layers {
    _BASE,
    _SYM,
    _NAV,
    _MOU,
    _FUN,
    _GAM,
    _GNM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_split_3x6_3(
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
    XXXXXXX, KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,                      KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX, HRGUI(KC_A), HRALT(KC_R), HRCTL(KC_S), HRSFT(KC_T), HRAGR(KC_G), HRAGR(KC_M), HRSFT(KC_N), HRCTL(KC_E), HRALT(KC_I), HRGUI(KC_O), XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   ,                      KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH, XXXXXXX,
//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                XXXXXXX, LT(_NAV, KC_ESC), LT(_MOU, KC_BSPC),    LT(_FUN, KC_ENT), LT(_SYM, KC_SPC), XXXXXXX
                                    //`--------------------------'  `--------------------------'
),

[_SYM] = LAYOUT_split_3x6_3(
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
    XXXXXXX, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX, SYM_LGUI, SYM_LALT, SYM_LCTL, SYM_LSFT, KC_BSLS,                  KC_PIPE, SYM_RSFT, SYM_RCTL, SYM_RALT, SYM_RGUI, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX, KC_COLN, KC_QUES, KC_PERC, KC_EXLM , KC_GRV,                      KC_BSLS, KC_RPRN, KC_RBRC, KC_RCBR, KC_GT, XXXXXXX,
//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        XXXXXXX, KC_MINS, KC_UNDS,    XXXXXXX, _______, XXXXXXX
                                    //`--------------------------'  `--------------------------'
),

[_NAV] = LAYOUT_split_3x6_3(
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
    XXXXXXX, KC_AGIN, KC_UNDO, C(KC_V), C(KC_C), KC_CUT ,                      KC_CUT , C(KC_C), C(KC_V), KC_UNDO, KC_AGIN, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_VOLU,                      KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_TAB , XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END , XXXXXXX, XXXXXXX,
//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        XXXXXXX, _______, XXXXXXX,    KC_INS , KC_DEL , XXXXXXX
                                    //`--------------------------'  `--------------------------'
),

[_MOU] = LAYOUT_split_3x6_3(
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
    XXXXXXX, KC_AGIN, KC_UNDO, C(KC_V), C(KC_C), KC_CUT ,                      KC_CUT , C(KC_C), C(KC_V), KC_UNDO, KC_AGIN, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_VOLU,                      MS_LEFT, MS_DOWN, MS_UP  , MS_RGHT, KC_TAB , XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD,                      MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, MS_BTN3, XXXXXXX,
//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        XXXXXXX, XXXXXXX, _______,    MS_BTN2, MS_BTN1, XXXXXXX
                                    //`--------------------------'  `--------------------------'
),

[_FUN] = LAYOUT_split_3x6_3(
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
    XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_PAUS,                      TG(_GAM),DM_PLY1, DM_REC1, DM_RSTP, XXXXXXX, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX, KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_PSCR,                      QK_BOOT, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX, KC_F9  , KC_F10 , KC_F11 , KC_F12 , XXXXXXX,                      QK_LOCK, MONKE  , SAMRA  , REE    , XXXXXXX, XXXXXXX,
//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        XXXXXXX, KC_APP , XXXXXXX,    _______, XXXXXXX, XXXXXXX
                                    //`--------------------------'  `--------------------------'
),

[_GAM] = LAYOUT_split_3x6_3(
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_T   , KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   ,                      KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_G   , KC_LSFT, KC_A   , KC_S   , KC_D   , KC_F   ,                      KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_B   , KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   ,                      KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, TG(_GAM),
//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_ESC , LT(_GNM, KC_SPC), KC_RBRC,    XXXXXXX, XXXXXXX, XXXXXXX
                                    //`--------------------------'  `--------------------------'
),

[_GNM] = LAYOUT_split_3x6_3(
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_GRV , KC_1   , KC_2   , _______, KC_3   , KC_4   ,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_M   , _______, _______, _______, _______, KC_5   ,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_I   , _______, KC_9   , KC_8   , KC_7   , KC_6   ,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(_GAM),
//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        XXXXXXX, _______, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                    //`--------------------------'  `--------------------------'
),
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case REE:
            if (record->event.pressed) {
                if (!ree_is_active()) {
                    ree_start();
                } else {
                    ree_stop();
                }
            }
            return false;

        case SAMRA:
            if (record->event.pressed) {
                samara_send();
            }
            return false;

        case MONKE:
            if (record->event.pressed) {
                if (!monke_is_active()) {
                    monke_start();
                } else {
                    monke_stop();
                }
            }
            return false;

        // hr mods in SYM
        case SYM_LGUI:
            if (record->tap.count) {
                if (record->event.pressed) {
                    tap_code16(KC_AT);
                }
                return false;
            }
            break;

        case SYM_LALT:
            if (record->tap.count) {
                if (record->event.pressed) {
                    tap_code16(KC_EQL);
                }
                return false;
            }
            break;

        case SYM_LCTL:
            if (record->tap.count) {
                if (record->event.pressed) {
                    tap_code16(KC_ASTR);
                }
                return false;
            }
            break;

        case SYM_LSFT:
            if (record->tap.count) {
                if (record->event.pressed) {
                    tap_code16(KC_PLUS);
                }
                return false;
            }
            break;

        case SYM_RSFT:
            if (record->tap.count) {
                if (record->event.pressed) {
                    tap_code16(KC_LPRN);
                }
                return false;
            }
            break;

        case SYM_RCTL:
            if (record->tap.count) {
                if (record->event.pressed) {
                    tap_code16(KC_LBRC);
                }
                return false;
            }
            break;

        case SYM_RALT:
            if (record->tap.count) {
                if (record->event.pressed) {
                    tap_code16(KC_LCBR);
                }
                return false;
            }
            break;

        case SYM_RGUI:
            if (record->tap.count) {
                if (record->event.pressed) {
                    tap_code16(KC_LT);
                }
                return false;
            }
            break;
    }

    if (monke_is_active() && record->event.pressed && keycode != MONKE) {
        monke_stop();
    }
    if (ree_is_active() && record->event.pressed && keycode != REE) {
        ree_stop();
    }
    return true;
}

const char* layer_names[] = {
    [0] = "BASE",
    [1] = "SYM",
    [2] = "NAV",
    [3] = "MOU",
    [4] = "FUN",
    [5] = "GAM",
    [6] = "GNM",
};

#define NUM_LAYERS (sizeof(layer_names) / sizeof(layer_names[0]))

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);

    uint8_t report[32] = {0};
    report[0]          = 0x01;  // message type
    report[1]          = layer; // layer number

    const char* layer_name = (layer < NUM_LAYERS && layer_names[layer] != NULL) ? layer_names[layer] : "UNKNOWN";

    strncpy((char*)&report[2], layer_name, 30);

    raw_hid_send(report, 32);

    return state;
}

void matrix_scan_user(void) {
    monke_task();
    ree_task();
}

void keyboard_post_init_user(void) {
    monke_init();
}

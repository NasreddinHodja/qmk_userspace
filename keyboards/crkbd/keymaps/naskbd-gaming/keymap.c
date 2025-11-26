#include QMK_KEYBOARD_H
#include "raw_hid.h"

#include <stdint.h>

#include "sticky_layers/sticky_layers.h"
#include "layer_report/layer_report.h"
#include "mouse_brr/mouse_brr.h"

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
const key_override_t dmrec_ko = ko_make_basic(MOD_MASK_CTRL, DM_REC1, DM_REC2);
const key_override_t dmply_ko = ko_make_basic(MOD_MASK_CTRL, DM_PLY1, DM_PLY2);

const key_override_t* key_overrides[] = {
    &dmrec_ko,
    &dmply_ko,
};

// combos
const uint16_t PROGMEM tab_combo[]    = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM quote_combo[]  = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM circ_combo[]   = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM dquote_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM tilde_combo[]  = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM hash_combo[]   = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM dlr_combo[]    = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM ampr_combo[]   = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM caps_combo[]   = {KC_L, KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM del_combo[]    = {KC_W, KC_F, KC_P, COMBO_END};

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

enum nas_keycodes {
    MOU_BRR = SAFE_RANGE
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
const char* const layer_names[] = {
    [0] = "BASE",
    [1] = "SYM",
    [2] = "NAV",
    [3] = "MOU",
    [4] = "FUN",
    [5] = "GAM",
    [6] = "GNM",
};
const uint8_t layer_count = sizeof(layer_names) / sizeof(layer_names[0]);

const uint8_t sticky_layers[] = { _MOU };
const uint8_t sticky_layer_count = sizeof(sticky_layers) / sizeof(sticky_layers[0]);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_split_3x6_3(
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
    XXXXXXX, KC_Q   , KC_W   , KC_F   , KC_P   , KC_B,                      KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX, HRGUI(KC_A), HRALT(KC_R), HRCTL(KC_S), HRSFT(KC_T), HRAGR(KC_G), HRAGR(KC_M), HRSFT(KC_N), HRCTL(KC_E), HRALT(KC_I), HRGUI(KC_O), XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V,                      KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                XXXXXXX, LT(_NAV, KC_ESC), LT(_MOU, KC_BSPC),    LT(_FUN, KC_ENT), LT(_SYM, KC_SPC), XXXXXXX
                                    //`--------------------------'  `--------------------------'
),

[_SYM] = LAYOUT_split_3x6_3(
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
    XXXXXXX, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX, SYM_LGUI, SYM_LALT, SYM_LCTL, SYM_LSFT, KC_BSLS,                  KC_PIPE, SYM_RSFT, SYM_RCTL, SYM_RALT, SYM_RGUI, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX, KC_COLN, KC_QUES, KC_PERC, KC_EXLM , KC_GRV,                      KC_BSLS, KC_RPRN, KC_RBRC, KC_RCBR, KC_GT  , XXXXXXX,
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
    XXXXXXX, KC_VOLD, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END , XXXXXXX, XXXXXXX,
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
    XXXXXXX, KC_VOLD, KC_MPRV, KC_MPLY, KC_MNXT, MOU_BRR,                      MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, MS_BTN3, XXXXXXX,
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
    XXXXXXX, KC_F9  , KC_F10 , KC_F11 , KC_F12 , XXXXXXX,                      QK_LOCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
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

bool handle_sym_tap(uint16_t keycode, keyrecord_t *record) {
    if (!record->tap.count || !record->event.pressed) return true;
    switch (keycode) {
        case SYM_LGUI: tap_code16(KC_AT); break;
        case SYM_LALT: tap_code16(KC_ASTR); break;
        case SYM_LCTL: tap_code16(KC_PLUS); break;
        case SYM_LSFT: tap_code16(KC_EQL); break;

        case SYM_RSFT: tap_code16(KC_LPRN); break;
        case SYM_RCTL: tap_code16(KC_LBRC); break;
        case SYM_RALT: tap_code16(KC_LCBR); break;
        case SYM_RGUI: tap_code16(KC_LT); break;
        default: return true;
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!handle_sym_tap(keycode, record)) return false;

    handle_layer_stick(keycode, record);

    if (!process_mou_brr(keycode, record, MOU_BRR)) return false;

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);

    send_layer_report(layer);

    return handle_sticky_layer_state(state, layer);
}

void matrix_scan_user(void) {
    mou_brr_task();
}

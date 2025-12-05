#include QMK_KEYBOARD_H
#include "raw_hid.h"
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
const uint16_t PROGMEM caps_combo[]   = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM del_combo[]    = {KC_P, KC_B, COMBO_END};
const uint16_t PROGMEM csv_combo[]   = {C(KC_V), C(KC_C), COMBO_END};
const uint16_t PROGMEM csc_combo[]   = {C(KC_W), C(KC_V), COMBO_END};

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
    COMBO(csv_combo, LCS(KC_V)),
    COMBO(csc_combo, LCS(KC_C)),
};

enum nas_keycodes {
    MOU_BRR = SAFE_RANGE,
    K_A,
    K_AO,
    K_O,
    K_OES,
};

enum layers {
    _BASE,
    _NUM,
    _SYM,
    _NAV,
    _MOU,
    _FUN,
};
const char* const layer_names[] = {
    [_BASE] = "BASE",
    [_NUM] = "NUM",
    [_SYM] = "SYM",
    [_NAV] = "NAV",
    [_MOU] = "MOU",
    [_FUN] = "FUN",
};
const uint8_t layer_count = sizeof(layer_names) / sizeof(layer_names[0]);

const uint8_t sticky_layers[] = { _MOU };
const uint8_t sticky_layer_count = sizeof(sticky_layers) / sizeof(sticky_layers[0]);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_Q   , KC_W   , KC_F   , KC_P   , KC_B,                      KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, XXXXXXX,
    XXXXXXX, HRGUI(KC_A), HRALT(KC_R), HRCTL(KC_S), HRSFT(KC_T), HRAGR(KC_G), HRAGR(KC_M), HRSFT(KC_N), HRCTL(KC_E), HRALT(KC_I), HRGUI(KC_O), XXXXXXX,
    XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V,                      KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH, XXXXXXX,
                                XXXXXXX, LT(_NAV, KC_ESC), LT(_MOU, KC_BSPC),    LT(_SYM, KC_ENT), LT(_NUM, KC_SPC), XXXXXXX
),

[_NUM] = LAYOUT_split_3x6_3(
    XXXXXXX, XXXXXXX, KC_9   , KC_8   , KC_7   , KC_LBRC,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_GRV , KC_3   , KC_2   , KC_1   , KC_EQL ,                      KC_RALT, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
    XXXXXXX, KC_SLSH, KC_6   , KC_5   , KC_4   , KC_RBRC,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        XXXXXXX, LT(_FUN, KC_0), KC_BSLS,      XXXXXXX, _______, XXXXXXX
),

[_SYM] = LAYOUT_split_3x6_3(
    XXXXXXX, XXXXXXX, KC_AT  , KC_LCBR, KC_LPRN, KC_LT  ,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_PERC, KC_ASTR, KC_EXLM, KC_PLUS,                      KC_RALT, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_PIPE, KC_RCBR, KC_RPRN, KC_GT  ,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        XXXXXXX, KC_MINS, KC_UNDS,    _______, XXXXXXX, XXXXXXX
),

[_NAV] = LAYOUT_split_3x6_3(
    XXXXXXX, C(KC_Z), C(KC_U), C(KC_V), C(KC_C), C(KC_X),                      C(KC_X), C(KC_C), C(KC_V), C(KC_U), C(KC_Z), XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_VOLU,                      KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_TAB , XXXXXXX,
    XXXXXXX, KC_VOLD, KC_MPRV, KC_MPLY, KC_MNXT, C(KC_A),                      KC_HOME, KC_PGDN, KC_PGUP, KC_END , XXXXXXX, XXXXXXX,
                                        XXXXXXX, _______, XXXXXXX,    KC_INS , LT(_FUN, KC_DEL) , XXXXXXX
),

[_MOU] = LAYOUT_split_3x6_3(
    XXXXXXX, C(KC_Z), C(KC_U), C(KC_V), C(KC_C), C(KC_X),                      C(KC_X), C(KC_C), C(KC_V), C(KC_U), C(KC_Z), XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_VOLU,                      MS_LEFT, MS_DOWN, MS_UP  , MS_RGHT, KC_TAB , XXXXXXX,
    XXXXXXX, KC_VOLD, KC_MPRV, KC_MPLY, KC_MNXT, MOU_BRR,                      MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, MS_BTN3, XXXXXXX,
                                        XXXXXXX, XXXXXXX, _______,    MS_BTN2, MS_BTN1, XXXXXXX
),

[_FUN] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_F10 , KC_F9  , KC_F8  , KC_F7  , KC_PAUS,                      XXXXXXX, DM_PLY1, DM_REC1, DM_RSTP, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_F11 , KC_F3  , KC_F2  , KC_F1  , KC_PSCR,                      QK_BOOT, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
    XXXXXXX, KC_F12 , KC_F6  , KC_F5  , KC_F4  , XXXXXXX,                      QK_LOCK, KC_APP , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        XXXXXXX, _______, XXXXXXX,    XXXXXXX, _______, XXXXXXX
),
};

bool ced_toggled = false;
bool handle_ced(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;
    switch (keycode) {
        case KC_COMM:
            if (!(get_mods() & MOD_BIT(KC_RALT))) break;
            ced_toggled = true;
            break;
        case HRSFT(KC_T):
            if (ced_toggled) {
                tap_code16(KC_TILD); tap_code16(KC_A);
                ced_toggled = false;
                return false;
            }
            break;
        case KC_D:
            if (ced_toggled) {
                tap_code16(KC_TILD); tap_code16(KC_O);
                ced_toggled = false;
                return false;
            }
            break;
        case HRSFT(KC_N):
            if (ced_toggled) {
                tap_code16(KC_TILD); tap_code16(KC_A); SEND_STRING("o");
                ced_toggled = false;
                return false;
            }
            break;
        case KC_H:
            if (ced_toggled) {
                tap_code16(KC_TILD); tap_code16(KC_O); SEND_STRING("es");
                ced_toggled = false;
                return false;
            }
            break;
        default:
            ced_toggled = false;
            return true;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!handle_ced(keycode, record)) return false;

    handle_layer_stick(keycode, record);

    if (!process_mou_brr(keycode, record, MOU_BRR)) return false;

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);
    send_layer_report(layer);
    layer_state_t new_state = handle_sticky_layer_state(state, layer);
    return new_state;
}

void matrix_scan_user(void) {
    mou_brr_task();
}

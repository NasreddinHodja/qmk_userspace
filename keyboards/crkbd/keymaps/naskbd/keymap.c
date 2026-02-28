#include QMK_KEYBOARD_H
#include "raw_hid.h"

#include <stdint.h>
#include "print.h"

// #include "sticky_layers/sticky_layers.h"
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
    // CED
    K_A, K_AO, K_O, K_OES,
    // linkedin & gh links
    K_LKN, K_GHL,
    // SYS
    K_WM0, K_WM1, K_WM2, K_WM3, K_WM4, K_WM5, K_WM6, K_WM7, K_WM8, K_WM9,
};

enum layers {
    _BASE,
    _NUM,
    _SYM,
    _NAV,
    _MOU,
    _FUN,
    _GAM,
    /* _GNM, */
    _SYS,
};
const char* const layer_names[] = {
    [_BASE] = "BASE",
    [_NUM] = "NUM",
    [_SYM] = "SYM",
    [_NAV] = "NAV",
    [_MOU] = "MOU",
    [_GAM] = "GAM",
    /* [_GNM] = "GNM", */
    [_SYS] = "SYS",
};
const uint8_t layer_count = sizeof(layer_names) / sizeof(layer_names[0]);


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_Q   , KC_W   , KC_F   , KC_P   , KC_B,                      KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, XXXXXXX,
    XXXXXXX, HRGUI(KC_A), HRALT(KC_R), HRCTL(KC_S), HRSFT(KC_T), HRAGR(KC_G), HRAGR(KC_M), HRSFT(KC_N), HRCTL(KC_E), HRALT(KC_I), HRGUI(KC_O), XXXXXXX,
    XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V,                      KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH, XXXXXXX,
                                XXXXXXX, LT(_NAV, KC_ESC), LT(_SYS, KC_BSPC),    LT(_SYM, KC_ENT), LT(_NUM, KC_SPC), XXXXXXX
),

[_NUM] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_GRV , KC_9   , KC_8   , KC_7   , KC_LBRC,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_QUOT, KC_3   , KC_2   , KC_1   , KC_EQL ,                      KC_RALT, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
    XXXXXXX, KC_SLSH, KC_6   , KC_5   , KC_4   , KC_RBRC,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        XXXXXXX, LT(_FUN, KC_0), KC_BSLS,      XXXXXXX, _______, XXXXXXX
),

[_SYM] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_CIRC, KC_TILD, KC_LCBR, KC_LPRN, KC_AMPR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_PERC, KC_HASH, KC_ASTR, KC_EXLM, KC_PLUS,                      KC_RALT, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
    XXXXXXX, KC_AT  , KC_PIPE, KC_RCBR, KC_RPRN, KC_DLR ,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        XXXXXXX, KC_MINS, KC_UNDS,    _______, XXXXXXX, XXXXXXX
),

[_NAV] = LAYOUT_split_3x6_3(
    XXXXXXX, C(KC_Z), C(KC_U), C(KC_V), C(KC_C), C(KC_X),                      C(KC_X), C(KC_C), C(KC_V), C(KC_U), KC_MUTE, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_CAPS,                      KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_VOLU, XXXXXXX,
    XXXXXXX, TG(_MOU), KC_MPRV, KC_MPLY, KC_MNXT, C(KC_A),                      KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_VOLD, XXXXXXX,
                                        XXXXXXX, _______, XXXXXXX,    KC_INS , LT(_FUN, KC_DEL) , XXXXXXX
),

[_MOU] = LAYOUT_split_3x6_3(
    XXXXXXX, C(KC_Z), C(KC_U), C(KC_V), C(KC_C), C(KC_X),                      C(KC_X), C(KC_C), C(KC_V), C(KC_U), C(KC_Z), XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_VOLU,                      MS_LEFT, MS_DOWN, MS_UP  , MS_RGHT, KC_TAB , XXXXXXX,
    XXXXXXX, KC_VOLD, KC_MPRV, KC_MPLY, KC_MNXT, MOU_BRR,                      MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, MS_BTN3, XXXXXXX,
                                        _______, _______, _______,    MS_BTN2, MS_BTN1, XXXXXXX
),

[_FUN] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_F10 , KC_F9  , KC_F8  , KC_F7  , KC_PAUS,                      TG(_GAM), DM_PLY1, DM_REC1, DM_RSTP, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_F11 , KC_F3  , KC_F2  , KC_F1  , KC_PSCR,                      QK_BOOT, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
    XXXXXXX, KC_F12 , KC_F6  , KC_F5  , KC_F4  , EE_CLR ,                      QK_LOCK, KC_APP , K_LKN , K_GHL , XXXXXXX, XXXXXXX,
                                        XXXXXXX, _______, XXXXXXX,    XXXXXXX, _______, XXXXXXX
),
[_GAM] = LAYOUT_split_3x6_3(
    KC_T   , KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   ,                      KC_Y, KC_U   , KC_I   , KC_O   , KC_P   , XXXXXXX,
    KC_G   , KC_LSFT, KC_A   , KC_S   , KC_D   , KC_F   ,                      KC_H, KC_J   , KC_K   , KC_L   , KC_SCLN, XXXXXXX,
    KC_B   , KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   ,                      KC_N, KC_M   , KC_COMM, KC_DOT , KC_SLSH, TG(_GAM),
    /* KC_B   , KC_LCTL, KC_Z   , KC_1   , KC_2   , KC_V   ,                      KC_N, KC_3   , KC_4   , KC_DOT , KC_SLSH, TG(_GAM), */
                                        XXXXXXX, /* LT(_GNM, KC_SPC) */ KC_ESC, KC_BSPC,    KC_ENT, KC_SPC , XXXXXXX
),
/* [_GNM] = LAYOUT_split_3x6_3( */
/*     _______, _______, KC_1   , _______, KC_2   , KC_3   ,                      _______, _______, _______, _______, _______, _______, */
/*     KC_0   , _______, _______, _______, _______, KC_4   ,                      _______, _______, _______, _______, _______, _______, */
/*     _______, _______, KC_9   , KC_7   , KC_6   , KC_5   ,                      _______, _______, _______, _______, _______, _______, */
/*                                         XXXXXXX, _______, XXXXXXX,    _______, _______, _______ */
/* ), */
[_SYS] = LAYOUT_split_3x6_3(
    XXXXXXX, G(KC_Q), K_WM9   , K_WM8   , K_WM7   , XXXXXXX,                      XXXXXXX, C(KC_A), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, K_WM3   , K_WM2   , K_WM1   , XXXXXXX,                      XXXXXXX, KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, K_WM6   , K_WM5   , K_WM4   , XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        XXXXXXX, XXXXXXX, _______,    XXXXXXX, XXXXXXX, XXXXXXX
),
};

bool handle_links(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;
    if (keycode == K_LKN) {
        SEND_STRING("www.linkedin.com/in/tom");
        tap_code16(KC_QUOT); tap_code16(KC_A);
        SEND_STRING("s-bizet-0474971b7");
        return false;
    }
    if (keycode == K_GHL) {
        SEND_STRING("https://github.com/NasreddinHodja");
        return false;
    }
    return true;
}

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

bool handle_sys(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;
    if (keycode < K_WM0 || keycode > K_WM9) return true;

    static const uint16_t wm_keys[] = {
        KC_0, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9
    };

    uint8_t idx = keycode - K_WM0;

    if (get_mods() & MOD_MASK_SHIFT) {
        uint8_t saved_mods = get_mods();
        del_mods(MOD_MASK_SHIFT);
        tap_code16(C(KC_A));
        tap_code16(wm_keys[idx]);
        set_mods(saved_mods);
    } else {
        tap_code16(G(wm_keys[idx]));
    }

    return false;
}

bool handle_mou_exit(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;
    if (get_highest_layer(layer_state) != _MOU) return true;

    if (keymap_key_to_keycode(_MOU, record->event.key) == KC_TRNS) {
        layer_off(_MOU);
        return false;
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!handle_mou_exit(keycode, record)) return false;
    if (!handle_ced(keycode, record)) return false;
    if (!handle_sys(keycode, record)) return false;
    if (!handle_links(keycode, record)) return false;

    if (!process_mou_brr(keycode, record, MOU_BRR)) return false;

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    send_layer_report(get_highest_layer(state));
    return state;
}

void matrix_scan_user(void) {
    mou_brr_task();
}

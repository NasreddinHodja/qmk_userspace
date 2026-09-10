#include "keycodes.h"
#include QMK_KEYBOARD_H

#include <stdint.h>

#include "layer_report/layer_report.h"
#include "mouse_brr/mouse_brr.h"

#define NAS_LAYOUT_3x6_3( \
    k0A, k0B, k0C, k0D, k0E, k0F, \
    k1A, k1B, k1C, k1D, k1E, k1F, \
    k2A, k2B, k2C, k2D, k2E, k2F, \
    k3D, k3E, k3F, \
    k4F, k4E, k4D, k4C, k4B, k4A, \
    k5F, k5E, k5D, k5C, k5B, k5A, \
    k6F, k6E, k6D, k6C, k6B, k6A, \
    k7F, k7E, k7D  \
) { \
    { k0A, k0B, k0C, k0D, k0E, k0F }, \
    { k1A, k1B, k1C, k1D, k1E, k1F }, \
    { k2A, k2B, k2C, k2D, k2E, k2F }, \
    { XXX, XXX, XXX, k3D, k3E, k3F }, \
    { k4A, k4B, k4C, k4D, k4E, k4F }, \
    { k5A, k5B, k5C, k5D, k5E, k5F }, \
    { k6A, k6B, k6C, k6D, k6E, k6F }, \
    { XXX, XXX, XXX, k7D, k7E, k7F }  \
}

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


//   B  L  D  C  V  |  J  Y  O  U  ;
//   N  R  T  S  G  |  P  H  A  E  I
//   X  Q  M  W  Z  |  K  F  ,  .  /

// combos
const uint16_t PROGMEM tab_combo[]    = {KC_L, KC_D, COMBO_END};
const uint16_t PROGMEM quote_combo[]  = {KC_D, KC_C, COMBO_END};
const uint16_t PROGMEM circ_combo[]   = {KC_Q, KC_M, COMBO_END};
const uint16_t PROGMEM tilde_combo[]  = {KC_M, KC_W, COMBO_END};
const uint16_t PROGMEM dlr_combo[]    = {KC_Y, KC_O, COMBO_END};
const uint16_t PROGMEM ampr_combo[]   = {KC_O, KC_U, COMBO_END};
const uint16_t PROGMEM caps_combo[]   = {KC_J, KC_Y, COMBO_END};
const uint16_t PROGMEM del_combo[]    = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM csv_combo[]    = {C(KC_V), C(KC_C), COMBO_END};
const uint16_t PROGMEM csc_combo[]    = {C(KC_A), C(KC_V), COMBO_END};

combo_t key_combos[] = {
    COMBO(tab_combo, KC_TAB),
    COMBO(quote_combo, KC_QUOT),
    COMBO(circ_combo, KC_CIRC),
    COMBO(tilde_combo, KC_TILD),
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
    // links
    K_LKL, K_GHL, K_EML,
    // SYS
    K_WM0, K_WM1, K_WM2, K_WM3, K_WM4, K_WM5, K_WM6, K_WM7, K_WM8, K_WM9,
    // GMP hat
    JS_UP, JS_DN, JS_LT, JS_RT,
};

enum layers {
    _BASE,
    _NUM,
    _SYM,
    /* _ITL, */
    _NAV,
    _MOU,
    _FUN,
    _FPS,
    _FPSN,
    _MOBA,
    _MOBAN,
    _GMP,
    _SYS,
    _PST,
};
const char* const layer_names[] = {
    [_BASE] = "BASE",
    [_NUM] = "NUM",
    [_SYM] = "SYM",
    [_NAV] = "NAV",
    [_MOU] = "MOU",
    [_FUN] = "FUN",
    [_FPS] = "FPS",
    [_FPSN] = "FPSN",
    [_MOBA] = "MOBA",
    [_MOBAN] = "MOBAN",
    [_GMP] = "GMP",
    [_SYS] = "SYS",
    [_PST] = "PST",
};
const uint8_t layer_count = sizeof(layer_names) / sizeof(layer_names[0]);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = NAS_LAYOUT_3x6_3(
    KC_TAB , KC_B       , KC_L       , KC_D       , KC_C            , KC_V,
    KC_QUOT, HRGUI(KC_N), HRALT(KC_R), HRCTL(KC_T), HRSFT(KC_S)     , HRAGR(KC_G),
    XXXXXXX, KC_X       , KC_Q       , KC_M       , KC_W            , KC_Z,
                                       XXXXXXX    , LT(_NAV, KC_ESC), LT(_SYS, KC_BSPC),

    KC_J                   , KC_Y            , KC_O       , KC_U       , KC_SCLN    , KC_ENT,
    HRAGR(KC_P)            , HRSFT(KC_H)     , HRCTL(KC_A), HRALT(KC_E), HRGUI(KC_I), KC_BSPC,
    KC_K                   , KC_F            , KC_COMM    , KC_DOT     , KC_SLSH    , XXXXXXX,
    LT(_SYM, RALT(KC_QUOT)), LT(_NUM, KC_SPC), XXXXXXX
),

[_NUM] = NAS_LAYOUT_3x6_3(
    XXXXXXX, KC_GRV , KC_9, KC_8   , KC_7          , KC_LBRC,
    XXXXXXX, KC_QUOT, KC_3, KC_2   , KC_1          , KC_EQL,
    XXXXXXX, KC_SLSH, KC_6, KC_5   , KC_4          , KC_RBRC,
                            XXXXXXX, LT(_FUN, KC_0), KC_BSLS,

    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_RALT, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_LLCK, XXXXXXX,
    XXXXXXX, _______, XXXXXXX
),

[_SYM] = NAS_LAYOUT_3x6_3(
    XXXXXXX, RALT(KC_CIRC), RALT(KC_TILD), KC_LCBR, KC_LPRN, KC_AMPR,
    XXXXXXX, KC_PERC      , KC_HASH      , KC_ASTR, KC_EXLM, KC_PLUS,
    XXXXXXX, KC_AT        , KC_PIPE      , KC_RCBR, KC_RPRN, KC_DLR,
                                           XXXXXXX, KC_MINS, KC_UNDS,

    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_RALT, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_LLCK, XXXXXXX,
    _______, XXXXXXX, XXXXXXX
),

[_NAV] = NAS_LAYOUT_3x6_3(
    XXXXXXX, C(KC_Z), C(KC_A) , C(KC_V), C(KC_C), C(KC_X),
    XXXXXXX, KC_LGUI, KC_LALT , KC_LCTL, KC_LSFT, KC_VOLU,
    XXXXXXX, QK_LLCK, TG(_MOU), KC_MUTE, KC_MPLY, KC_VOLD,
                                XXXXXXX, _______, XXXXXXX,

    XXXXXXX, KC_BSPC         , KC_ENT , KC_TAB , XXXXXXX, XXXXXXX,
    KC_LEFT, KC_DOWN         , KC_UP  , KC_RGHT, KC_CAPS, XXXXXXX,
    KC_HOME, KC_PGDN         , KC_PGUP, KC_END , XXXXXXX, XXXXXXX,
    KC_INS , LT(_FUN, KC_DEL), XXXXXXX
),

[_MOU] = NAS_LAYOUT_3x6_3(
    XXXXXXX, C(KC_Z), C(KC_U), C(KC_V), C(KC_C), C(KC_X),
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_VOLU,
    XXXXXXX, KC_VOLD, KC_MPRV, KC_MPLY, KC_MNXT, MOU_BRR,
                               _______, _______, _______,

    C(KC_X), C(KC_C), C(KC_V), C(KC_U), C(KC_Z), XXXXXXX,
    MS_LEFT, MS_DOWN, MS_UP  , MS_RGHT, KC_TAB , XXXXXXX,
    MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, MS_BTN3, XXXXXXX,
    MS_BTN2, MS_BTN1, XXXXXXX
),

[_FUN] = NAS_LAYOUT_3x6_3(
    XXXXXXX, KC_F10, KC_F9, KC_F8  , KC_F7  , KC_PAUS,
    XXXXXXX, KC_F11, KC_F3, KC_F2  , KC_F1  , KC_PSCR,
    XXXXXXX, KC_F12, KC_F6, KC_F5  , KC_F4  , EE_CLR,
                            XXXXXXX, _______, XXXXXXX,

    TG(_FPS), DM_PLY1, DM_REC1  , DM_RSTP, XXXXXXX, TG(_GMP),
    TG(_MOBA), KC_LSFT, KC_LCTL  , KC_LALT, KC_LGUI, QK_BOOT,
    QK_LOCK , KC_APP , OSL(_PST), XXXXXXX, XXXXXXX, QK_LLCK,
    XXXXXXX , _______, XXXXXXX
),

[_FPS] = NAS_LAYOUT_3x6_3(
    KC_T, KC_TAB , KC_Q, KC_W    , KC_E  , KC_R,
    KC_G, KC_LSFT, KC_A, KC_S    , KC_D  , KC_F,
    KC_B, KC_LCTL, KC_Z, KC_X    , KC_C  , KC_V,
                         MO(_FPSN), KC_SPC, KC_ESC,

    KC_Y  , KC_U   , KC_I   , KC_O  , KC_P   , XXXXXXX,
    KC_H  , KC_J   , KC_K   , KC_L  , KC_SCLN, XXXXXXX,
    KC_N  , KC_M   , KC_COMM, KC_DOT, KC_SLSH, TG(_FPS),
    KC_ENT, KC_BSPC, XXXXXXX
),

[_FPSN] = NAS_LAYOUT_3x6_3(
    KC_1  , KC_2   , KC_3   , XXXXXXX, KC_4   , KC_5,
    KC_0  , _______, _______, _______, _______, KC_6,
    KC_GRV, _______, KC_9   , _______, KC_8   , KC_7,
                              _______, XXXXXXX, XXXXXXX,

    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______
),

[_MOBA] = NAS_LAYOUT_3x6_3(
    KC_TAB , KC_Q, KC_W, KC_E   , KC_R    , KC_T,
    KC_LSFT, KC_A, KC_S, KC_D   , KC_F    , KC_G,
    KC_LCTL, KC_Z, KC_X, KC_C   , KC_V    , KC_B,
                         KC_MINS, MO(_MOBAN), KC_ESC,

    KC_Y  , KC_U   , KC_I   , KC_O  , KC_P   , XXXXXXX,
    KC_H  , KC_J   , KC_K   , KC_L  , KC_SCLN, XXXXXXX,
    KC_N  , KC_M   , KC_COMM, KC_DOT, KC_SLSH, TG(_MOBA),
    KC_ENT, KC_BSPC, XXXXXXX
),

[_MOBAN] = NAS_LAYOUT_3x6_3(
    KC_TAB , KC_6  , KC_7   , KC_6   , KC_8   , KC_9   ,
    KC_LSFT, KC_1  , KC_2   , KC_3   , KC_4   , KC_5   ,
    KC_LCTL, KC_GRV, KC_BSLS, KC_RBRC, KC_LBRC, KC_SLSH,
                              XXXXXXX, _______, XXXXXXX,

    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______
),

[_GMP] = NAS_LAYOUT_3x6_3(
    JS_9, JS_8, XXXXXXX, XXXXXXX, JS_DN  , JS_LT,
    JS_1, JS_3, XXXXXXX, KC_SPC , JS_RT  , JS_UP,
    JS_0, JS_2, JS_5   , JS_7   , JS_6   , JS_4,
                         XXXXXXX, XXXXXXX, XXXXXXX,

    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(_GMP),
    XXXXXXX, KC_SPC , XXXXXXX
),

[_SYS] = NAS_LAYOUT_3x6_3(
    XXXXXXX, G(KC_Q), K_WM9, K_WM8  , K_WM7  , XXXXXXX,
    XXXXXXX, C(KC_A), K_WM3, K_WM2  , K_WM1  , XXXXXXX,
    XXXXXXX, XXXXXXX, K_WM6, K_WM5  , K_WM4  , XXXXXXX,
                             XXXXXXX, XXXXXXX, _______,

    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX
),

[_PST] = NAS_LAYOUT_3x6_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, K_LKL  , K_GHL  , K_EML  , XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               XXXXXXX, XXXXXXX, XXXXXXX,

    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX
),
};

bool handle_links(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;
    if (keycode == K_LKL) {
        SEND_STRING("www.linkedin.com/in/tom");
        tap_code16(KC_QUOT); tap_code16(KC_A);
        SEND_STRING("s-bizet-0474971b7");
        return false;
    }
    if (keycode == K_GHL) {
        SEND_STRING("https://github.com/NasreddinHodja");
        return false;
    }
    if (keycode == K_EML) {
        SEND_STRING("tbizetde@gmail.com");
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
        case HRSFT(KC_S):
            if (ced_toggled) {
                tap_code16(KC_TILD); tap_code16(KC_A);
                ced_toggled = false;
                return false;
            }
            break;
        case KC_W:
            if (ced_toggled) {
                tap_code16(KC_TILD); tap_code16(KC_O);
                ced_toggled = false;
                return false;
            }
            break;
        case HRSFT(KC_H):
            if (ced_toggled) {
                tap_code16(KC_TILD); tap_code16(KC_A);
                SEND_STRING("o");
                ced_toggled = false;
                return false;
            }
            break;
        case KC_F:
            if (ced_toggled) {
                tap_code16(KC_TILD); tap_code16(KC_O);
                SEND_STRING("es");
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
    KC_0, KC_1, KC_2, KC_3, KC_4,
    KC_5, KC_6, KC_7, KC_8, KC_9
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

bool handle_gmp_hat(uint16_t keycode, keyrecord_t *record) {
    static bool hat_up = false, hat_dn = false, hat_lt = false, hat_rt = false;
    switch (keycode) {
        case JS_UP: hat_up = record->event.pressed; break;
        case JS_DN: hat_dn = record->event.pressed; break;
        case JS_LT: hat_lt = record->event.pressed; break;
        case JS_RT: hat_rt = record->event.pressed; break;
        default: return true;
    }
    if      ( hat_up && !hat_lt && !hat_rt) joystick_set_hat(JOYSTICK_HAT_NORTH);
    else if ( hat_up &&  hat_rt)            joystick_set_hat(JOYSTICK_HAT_NORTHEAST);
    else if (!hat_up && !hat_dn &&  hat_rt) joystick_set_hat(JOYSTICK_HAT_EAST);
    else if ( hat_dn &&  hat_rt)            joystick_set_hat(JOYSTICK_HAT_SOUTHEAST);
    else if ( hat_dn && !hat_lt && !hat_rt) joystick_set_hat(JOYSTICK_HAT_SOUTH);
    else if ( hat_dn &&  hat_lt)            joystick_set_hat(JOYSTICK_HAT_SOUTHWEST);
    else if (!hat_up && !hat_dn &&  hat_lt) joystick_set_hat(JOYSTICK_HAT_WEST);
    else if ( hat_up &&  hat_lt)            joystick_set_hat(JOYSTICK_HAT_NORTHWEST);
    else                                    joystick_set_hat(JOYSTICK_HAT_CENTER);
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

bool handle_ralt_quote(uint16_t keycode, keyrecord_t *record) {
    if (keycode != LT(_SYM, KC_QUOT) || !record->tap.count) return true;
    if (record->event.pressed) {
        register_code(KC_RALT);
        tap_code(KC_QUOT);
        unregister_code(KC_RALT);
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!handle_ralt_quote(keycode, record)) return false;
    if (!handle_gmp_hat(keycode, record)) return false;
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

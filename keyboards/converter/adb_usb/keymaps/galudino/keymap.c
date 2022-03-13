/*!
    \file       keymap.c
    \brief      Source file for adb_usb keymap

    \author     Gemuele Aludino
    \date       13 Mar 2022
 */

#include QMK_KEYBOARD_H
#include "config.h"

#include "quantum.h"

/* M0115/M3501 Apple Extended Keyboard ANSI
 * ,---.   ,---------------. ,---------------. ,---------------. ,-----------.             ,---.
 * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau|             |Pwr|
 * `---'   `---------------' `---------------' `---------------' `-----------'             `---'
 * ,-----------------------------------------------------------. ,-----------. ,---------------.
 * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backspa| |Afn|Hom|PgU| |NmL|  =|  /|  *|
 * |-----------------------------------------------------------| |-----------| |---------------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \| |Del|End|PgD| |  7|  8|  9|  -|
 * |-----------------------------------------------------------| `-----------' |---------------|
 * |Esc/L1|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return  |               |  4|  5|  6|  +|
 * |-----------------------------------------------------------|     ,---.     |---------------|
 * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /|Shift     |     |Up |     |  1|  2|  3|   |
 * |-----------------------------------------------------------| ,-----------. |-----------|Ent|
 * |Ctrl |Opt |Cmd |         Space           |Cmd  |Opt |Ctrl  | |Lef|Dow|Rig| |      0|  .|   |
 * `-----------------------------------------------------------' `-----------' `---------------'
 */
#define LAYOUT_ext_ansi_aek( \
    K35,    K7A,K78,K63,K76,K60,K61,K62,K64,K65,K6D,K67,K6F, K69,K6B,K71,              K7F, \
    K32,K12,K13,K14,K15,K17,K16,K1A,K1C,K19,K1D,K1B,K18,K33, K72,K73,K74,  K47,K51,K4B,K43, \
    K30,K0C,K0D,K0E,K0F,K11,K10,K20,K22,K1F,K23,K21,K1E,K2A, K75,K77,K79,  K59,K5B,K5C,K4E, \
    K39,K00,K01,K02,K03,K05,K04,K26,K28,K25,K29,K27,    K24,               K56,K57,K58,K45, \
    K38,K06,K07,K08,K09,K0B,K2D,K2E,K2B,K2F,K2C,        K7B,     K3E,      K53,K54,K55,     \
    K36,K3A,K37,        K31,                        K7C,K7D, K3B,K3D,K3C,  K52,    K41,K4C  \
) { \
    { K00,      K01,       K02,        K03,    K04,     K05,     K06,     K07    }, \
    { K08,      K09,       KC_NO,      K0B,    K0C,     K0D,     K0E,     K0F    }, \
    { K10,      K11,       K12,        K13,    K14,     K15,     K16,     K17    }, \
    { K18,      K19,       K1A,        K1B,    K1C,     K1D,     K1E,     K1F    }, \
    { K20,      K21,       K22,        K23,    K24,     K25,     K26,     K27    }, \
    { K28,      K29,       K2A,        K2B,    K2C,     K2D,     K2E,     K2F    }, \
    { K30,      K31,       K32,        K33,    KC_NO,   K35,     K36,     K37    }, \
    { K38,      K39,       K3A,        K3B,    K3C,     K3D,     K3E,     KC_NO, }, \
    { KC_NO,    K41,       KC_NO,      K43,    KC_NO,   K45,     KC_NO,   K47    }, \
    { KC_NO,    KC_NO,     KC_NO,      K4B,    K4C,     KC_NO,   K4E,     KC_NO, }, \
    { KC_NO,    K51,       K52,        K53,    K54,     K55,     K56,     K57    }, \
    { K58,      K59,       KC_NO,      K5B,    K5C,     KC_NO,   KC_NO,   KC_NO, }, \
    { K60,      K61,       K62,        K63,    K64,     K65,     KC_NO,   K67    }, \
    { KC_NO,    K69,       KC_NO,      K6B,    KC_NO,   K6D,     KC_NO,   K6F    }, \
    { KC_NO,    K71,       K72,        K73,    K74,     K75,     K76,     K77    }, \
    { K78,      K79,       K7A,        K7B,    K7C,     K7D,     KC_NO,   K7F    }  \
}

/*
16 x 8 matrix
24 pins required?
128 keys

        0         1          2           3       4        5        6        7
    ) { \
 0    { K00,      K01,       K02,        K03,    K04,     K05,     K06,     K07    }, \
 1    { K08,      K09,       KC_NO,      K0B,    K0C,     K0D,     K0E,     K0F    }, \
 2    { K10,      K11,       K12,        K13,    K14,     K15,     K16,     K17    }, \
 3    { K18,      K19,       K1A,        K1B,    K1C,     K1D,     K1E,     K1F    }, \
 4    { K20,      K21,       K22,        K23,    K24,     K25,     K26,     K27    }, \
 5    { K28,      K29,       K2A,        K2B,    K2C,     K2D,     K2E,     K2F    }, \
 6    { K30,      K31,       K32,        K33,    KC_NO,   K35,     K36,     K37    }, \
 7    { K38,      K39,       K3A,        K3B,    K3C,     K3D,     K3E,     KC_NO, }, \
 8    { KC_NO,    K41,       KC_NO,      K43,    KC_NO,   K45,     KC_NO,   K47    }, \
 9    { KC_NO,    KC_NO,     KC_NO,      K4B,    K4C,     KC_NO,   K4E,     KC_NO, }, \
10    { KC_NO,    K51,       K52,        K53,    K54,     K55,     K56,     K57    }, \
11    { K58,      K59,       KC_NO,      K5B,    K5C,     KC_NO,   KC_NO,   KC_NO, }, \
12    { K60,      K61,       K62,        K63,    K64,     K65,     KC_NO,   K67    }, \
13    { KC_NO,    K69,       KC_NO,      K6B,    KC_NO,   K6D,     KC_NO,   K6F    }, \
14    { KC_NO,    K71,       K72,        K73,    K74,     K75,     K76,     K77    }, \
15    { K78,      K79,       K7A,        K7B,    K7C,     K7D,     KC_NO,   K7F    }  \
}
*/

enum keymap_layout {
    KM_MACOS,
    KM_FUNC,
    KM_SETTINGS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [KM_MACOS] = LAYOUT_ext_ansi_aek(
        KC_ESC,  KC_F1,   KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,                                   KC_PSCR, KC_SLCK, KC_PAUS,                                 KC_EJCT,
        KC_GRV,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,             KC_BSPC,              KC_APFN, KC_HOME, KC_PGUP,       KC_NLCK, KC_EQL, KC_PSLS, KC_PAST,
        KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC,            KC_BSLS,              KC_DEL,  KC_END,  KC_PGDN,       KC_P7,   KC_P8,  KC_P9,   KC_PMNS,
        LT(KM_FUNC, KC_ESC), KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT,          KC_ENT,                                               KC_P4,   KC_P5,  KC_P6,   KC_PPLS,
        KC_LSFT, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH,                              KC_RSFT,                       KC_UP,                  KC_P1,   KC_P2,  KC_P3,
        KC_LCTL, KC_LALT, KC_LGUI,                KC_SPC,                                  KC_RALT, KC_RCTL,                                           KC_LEFT, KC_DOWN, KC_RGHT,       KC_P0,           KC_PDOT, KC_PENT
    ),

    [KM_FUNC] = LAYOUT_ext_ansi_aek(
        _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,                          _______, _______, _______,                                       _______,
        KC_ESC,  KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_F11, KC_F12,                        KC_DEL,         KC_INS,  _______, _______,      _______,   _______,   _______,   _______,
        _______,  _______,    KC_UP,   _______,   _______,   _______,   _______,   _______,   _______,    _______,   _______,    _______, _______, _______,         _______, _______, _______,      _______,   _______,   _______,   _______,
        _______, KC_LEFT,    KC_DOWN,   KC_RGHT,   _______,   _______,   KC_LEFT,   KC_UP,   KC_DOWN,    KC_RGHT,   _______, _______,              _______,                                         _______,   _______,   _______,   _______,
        _______, _______,    _______,   _______,   _______,   _______,   KC_DEL,   _______,   _______, _______, _______,                           _______,                  _______,               _______,   _______,   _______,
        KC_CAPS, _______, _______,                MO(KM_SETTINGS),                                  KC_APP, _______,                                                _______, _______, _______,      _______,              _______,   _______
    ),

    [KM_SETTINGS] = LAYOUT_ext_ansi_aek(
        XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX,                                       RESET,
        GE_SWAP,  KC_MUTE,    KC_VOLD,   KC_VOLU,   KC_MPRV,   KC_MNXT,   KC_MSTP,   KC_BRIU,   KC_BRID,    XXXXXXX,   KC_MYCM,    KC_WAKE, XXXXXXX,  KC_PWR,       XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,   XXXXXXX,  XXXXXXX,    XXXXXXX,
        GE_NORM,  XXXXXXX,    RGB_SAI,   XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX,   RGB_VAI,    XXXXXXX,   XXXXXXX,    XXXXXXX, BS_NORM,   BS_SWAP,       XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,   XXXXXXX,  XXXXXXX,    XXXXXXX,
        XXXXXXX, RGB_HUD,    RGB_SAD,   RGB_HUI,   XXXXXXX,   XXXXXXX,   XXXXXXX,   RGB_SPD,  RGB_VAD,    RGB_SPI,   XXXXXXX, XXXXXXX,                 DEBUG,                                       XXXXXXX,   XXXXXXX,  XXXXXXX,    XXXXXXX,
        XXXXXXX, RGB_M_P,    RGB_M_B,   RGB_M_R,   RGB_M_SW,   XXXXXXX,  NK_TOGG,   XXXXXXX,   RGB_RMOD, RGB_MOD, RGB_TOG,                           EEP_RST,                XXXXXXX,               XXXXXXX,   XXXXXXX,  XXXXXXX,
        RESET, GUI_OFF, AG_NORM,                XXXXXXX,                                  GUI_ON, KC_RCTL,                                                          XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,             XXXXXXX,    XXXXXXX
    ),
};

/*!
    \file       keymap.c
    \brief      Keymap source file for Hineybush H88 TKL PCB

    \author     Gemuele Aludino
    \date       13 Mar 2022
 */

#define ASSUME_APPLE

#include QMK_KEYBOARD_H
#include "config.h"
#include "layout.h"

/*!
    \enum   keymap_layout   Members are used to switch between different layers
 */
enum keymap_layout {
    KM_MAIN = 0,     //<! macOS-centric layout
    KM_FUNC,          //<! Function keymap, activated by holding Fn key
    KM_SETTINGS,      //<! Keymap to configure keyboard hardware/firmware settings
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [KM_MAIN] = LAYOUT_tkl_ansi_wkl_custom(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,     KC_F11,     KC_F12,  KC_F13,                    KC_PSCR, KC_SLCK, KC_PAUS,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,    KC_EQL,     XXXXXXX, KC_BSPC,           KC_APFN,  KC_HOME, KC_PGUP,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,    KC_RBRC,    KC_BSLS,                    KC_DEL,  KC_END,  KC_PGDN,
    LT(KM_FUNC, KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,                KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, LT(KM_FUNC, KC_ESC),                                                 KC_UP,
    KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                                      KC_RALT,   KC_RGUI,   KC_RCTL,                                         KC_LEFT, KC_DOWN, KC_RGHT),

  [KM_FUNC] = LAYOUT_tkl_ansi_wkl_custom(
    _______,     KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24, XXXXXXX,                 XXXXXXX,             _______,  _______, _______,   \
    _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,                      _______, KC_DEL,             KC_INS,   _______, _______,   \
    _______,    _______, KC_UP, _______, _______, _______, _______, KC_INS, KC_HOME, KC_PGUP, KC_PSCR, KC_SLCK, KC_PAUS,        _______,            _______,  _______, _______, \
    KC_CAPS,        KC_LEFT, KC_DOWN, KC_RIGHT, KC_APFN, _______, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT, _______, _______,          _______,                                   \
    _______,  _______, _______, _______, _______, _______, KC_DEL, KC_END, KC_PGDN, _______,  _______,        _______, _______,              _______,            \
    _______, _______, _______,                            MO(KM_SETTINGS),                      KC_RALT, _______, _______,         _______,  _______, _______    \
    ),

  [KM_SETTINGS] = LAYOUT_tkl_ansi_wkl_custom(
    XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,            XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, KC_BRID, KC_BRIU, XXXXXXX, KC_MYCM,  KC_WAKE,  KC_PWR, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX,  XXXXXXX, RGB_SAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX,  RGB_HUD,  RGB_SAD,  RGB_HUI, XXXXXXX, XXXXXXX, XXXXXXX, RGB_SPD, RGB_VAD, RGB_SPI, XXXXXXX, XXXXXXX,   DEBUG,                                   \
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, NK_TOGG, XXXXXXX, RGB_RMOD, RGB_MOD, RGB_TOG,         XXXXXXX,  XXXXXXX,                    XXXXXXX,          \
    CG_TOGG, XXXXXXX, XXXXXXX,                            XXXXXXX,                                                 XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX  \
  )
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

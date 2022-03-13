/*!
    \file       keymap.c
    \brief      Source file for qmk firmware (keyboard matrix)

    \author     Gemuele Aludino
    \date       27 Feb 2022
    \copyright  Copyright (c) 2022 Gemuele Aludino
 */

#include "config.h"
#include QMK_KEYBOARD_H

/*!
    #define LAYOUT_60_ansi_wkl

    - Standard, WKL
        - 7.00u spacebar
        - 1.50u/1.50u bottom row modifiers
        - 1.75u right shift, 1.0u mod (split right shift)
        - 2.50u backspace
        - 2.25u left shift

    Created by combining LAYOUT_60_ANSI and LAYOUT_60_tsangan_hhkb
 */
#define LAYOUT_60_ansi_wkl( \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C,      K1E, \
  K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,           K2E, \
  K30,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C,      K3E,\
  K40, K41,  K42,              K46,                      K4B, K4C,      K4E \
) { \
  {  K00,  K01,  K02,  K03,  K04,    K05,    K06,    K07,    K08,    K09,  K0A,  K0B,  K0C,  K0D,  KNO}, \
  {  K10,  K11,  K12,  K13,  K14,    K15,    K16,    K17,    K18,    K19,  K1A,  K1B,  K1C,  KNO,  K1E   }, \
  {  K20,  K21,  K22,  K23,  K24,    K25,    K26,    K27,    K28,    K29,  K2A,  K2B,  KNO,  KNO,  K2E  }, \
  {  K30,  KNO,  K32,  K33,  K34,    K35,    K36,    K37,    K38,    K39,  K3A,  K3B,  K3C,  KNO,  K3E  }, \
  {  K40,  K41,  K42,  KNO,  KNO,    KNO,    K46,    KNO,    KNO,    KNO,  KNO,  K4B,  K4C,  KNO,  K4E  }  \
}

enum keymap_layout {
    KM_MACOS,
    KM_FUNC,
    KM_SETTINGS
};

/*
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 * │Fn/Esc│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
 * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift│FN │
 * ├─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┴┬───┬─┴───┤
 * │Ctrl │Alt│ GUI │                           │ GUI │Alt│Ctrl │
 * └─────┴───┴─────┴───────────────────────────┴─────┴───┴─────┘
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [KM_MACOS] = LAYOUT_60_ansi_wkl(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,                 KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,  KC_BSLS,
    LT(KM_FUNC, KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,                 KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,                 KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, LT(KM_FUNC, KC_DEL),
    KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                                                               KC_RGUI, KC_RALT, KC_RCTL
  ),

  [KM_FUNC] = LAYOUT_60_ansi_wkl(
    KC_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    _______, _______, KC_UP,   _______, _______, _______, _______, KC_INS, KC_HOME, KC_PGUP, KC_PSCR, KC_SLCK, KC_PAUS, _______,
    KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, KC_DEL, KC_END, KC_PGDN, _______, _______,          KC_APFN, _______,
    KC_CAPS, _______, KC_APFN,                            MO(KM_SETTINGS),                                        KC_RALT, KC_APP, KC_RCTL
  ),

  [KM_SETTINGS] = LAYOUT_60_ansi_wkl(
    GE_SWAP, KC_MUTE,   KC_VOLD,   KC_VOLU,   KC_MPRV,   KC_MNXT,   KC_MSTP,   KC_BRIU,   KC_BRID,   XXXXXXX,   KC_MYCM,  KC_WAKE,  XXXXXXX,  KC_PWR,
    GE_NORM, XXXXXXX, RGB_SAI,   XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,    RGB_VAI,    XXXXXXX,    XXXXXXX,    XXXXXXX,  BS_NORM, BS_SWAP,
    XXXXXXX, RGB_HUD,    RGB_SAD,   RGB_HUI,    XXXXXXX,    XXXXXXX,   XXXXXXX,   RGB_SPD,  RGB_VAD,  RGB_SPI,    XXXXXXX, XXXXXXX, DEBUG,
    XXXXXXX,   RGB_M_P,   RGB_M_B,    RGB_M_R,    RGB_M_SW, XXXXXXX,   NK_TOGG,    XXXXXXX, RGB_RMOD, RGB_MOD, RGB_TOG,      EEP_RST, XXXXXXX,
    RESET, GUI_OFF, AG_NORM,                               XXXXXXX,                                               AG_SWAP, GUI_ON, XXXXXXX)

};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_KANA)) {

	} else {

	}

}

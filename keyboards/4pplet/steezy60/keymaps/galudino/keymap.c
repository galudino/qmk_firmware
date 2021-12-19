/*!
    \file       keymap.c
    \brief      Source file for qmk firmware (keyboard matrix)

    \author     Gemuele Aludino
    \date       16 Oct 2021
    \copyright  Copyright (c) 2021 Gemuele Aludino
 */

#include "config.h"
#include QMK_KEYBOARD_H

enum keymap_layout {
    KM_MACOS,
    KM_FUNC,
    KM_SETTINGS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    Shift │
     * ├─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┴┬───┬─────┤
     * │Ctrl │GUI│ Alt │                           │ Alt │GUI│ Ctrl│
     * └─────┴───┴─────┴───────────────────────────┴─────┴───┴─────┘
     */
    [KM_MACOS] = LAYOUT_all(
        KC_GRV,   KC_1,    KC_2,   KC_3,    KC_4,    KC_5,   KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX,  KC_BSPC,
        KC_TAB,  	KC_Q,    KC_W,   KC_E,    KC_R,    KC_T,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        LT(KM_FUNC, KC_ESC), KC_A,    KC_S,   KC_D,    KC_F,    KC_G,   KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, XXXXXXX, KC_ENT,
        KC_LSFT, 	KC_NUBS,   KC_Z,   KC_X,    KC_C,    KC_V,   KC_B,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX, KC_RSFT, LT(KM_FUNC, KC_DEL),
        KC_LCTL, 	KC_LALT, XXXXXXX,  KC_LGUI, XXXXXXX,  KC_SPC, XXXXXXX, 			    XXXXXXX, KC_RGUI, XXXXXXX,   KC_RALT,  KC_RCTL),

    [KM_FUNC] = LAYOUT_all(
        KC_ESC,   KC_F1,    KC_F2,   KC_F3,    KC_F4,    KC_F5,   KC_F6,   KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_F11, KC_F12,  XXXXXXX,  KC_TRNS,
        KC_TRNS,  	KC_TRNS,    KC_UP,   KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_INS,    KC_HOME,    KC_PGUP,    KC_PSCR,    KC_SLCK, KC_PAUS, KC_TRNS,
        KC_TRNS, KC_LEFT,    KC_DOWN,   KC_RGHT,    KC_TRNS,    KC_TRNS,   KC_LEFT,   KC_UP,    KC_DOWN,    KC_RGHT,    KC_TRNS, KC_TRNS, XXXXXXX, KC_TRNS,
        KC_TRNS, 	KC_NUBS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_DEL,    KC_END,    KC_PGDN, KC_TRNS,  KC_TRNS, XXXXXXX, KC_APFN, KC_TRNS,
        KC_CAPS, 	KC_TRNS, XXXXXXX,  KC_APFN, XXXXXXX,  MO(KM_SETTINGS), XXXXXXX, 			    XXXXXXX, KC_TRNS, XXXXXXX, KC_APP,  KC_TRNS),

    [KM_SETTINGS] = LAYOUT_all(
        GE_SWAP,   KC_MUTE,    KC_VOLD,   KC_VOLU,    KC_MPRV,    KC_MPLY,   KC_MNXT,   KC_MSTP,    KC_BRIU,    KC_BRID,    XXXXXXX,    KC_MYCM, KC_WAKE,  XXXXXXX,  KC_PWR,
        GE_NORM,  	XXXXXXX,   RGB_SAI,   XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,    RGB_VAI,    XXXXXXX,    XXXXXXX,    XXXXXXX, BS_NORM, BS_SWAP,
        XXXXXXX, RGB_HUD,    RGB_SAD,   RGB_HUI,    XXXXXXX,    XXXXXXX,   XXXXXXX,   RGB_SPD,  RGB_VAD,  RGB_SPI,    XXXXXXX, XXXXXXX, XXXXXXX, DEBUG,
        XXXXXXX, 	XXXXXXX,   RGB_M_P,   RGB_M_B,    RGB_M_R,    RGB_M_SW,   XXXXXXX,   NK_TOGG,    XXXXXXX, RGB_RMOD, RGB_MOD, RGB_TOG, XXXXXXX, EEP_RST, XXXXXXX,
        RESET, GUI_OFF, XXXXXXX, AG_NORM, XXXXXXX,   XXXXXXX, XXXXXXX, 			    XXXXXXX, AG_SWAP, XXXXXXX, GUI_ON,  XXXXXXX),
};

/*
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    keyevent_t event = record->event;
    switch (id) { }
    return MACRO_NONE;
}

void keyboard_pre_init_user() {

}

void matrix_init_user() {

}

void matrix_scan_user() {

}

void led_set_user(uint8_t usb_led) {

}

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state)
    if (res) {}
    return res;
}
*/

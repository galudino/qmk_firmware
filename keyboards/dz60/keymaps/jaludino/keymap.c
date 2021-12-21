/*!
    \file       keymap.c
    \brief      Source file for qmk firmware (keyboard matrix)

    \author     Gemuele Aludino
    \date       19 Dec 2021
    \copyright  Copyright (c) 2021 Gemuele Aludino
 */

#include "config.h"
#include QMK_KEYBOARD_H

enum keymap_layout {
    KM_MAIN,
    KM_FUNC,
    KM_SETTINGS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [KM_MAIN] = LAYOUT(
        KC_GESC,   KC_1,    KC_2,   KC_3,    KC_4,    KC_5,   KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_GRV,  KC_BSPC,
        KC_TAB,  	KC_Q,    KC_W,   KC_E,    KC_R,    KC_T,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A,    KC_S,   KC_D,    KC_F,    KC_G,   KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, 	KC_NUBS,   KC_Z,   KC_X,    KC_C,    KC_V,   KC_B,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(KM_FUNC),
        KC_LCTL, 	KC_LGUI, KC_LALT, XXXXXXX, KC_SPC, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX,  KC_DEL, KC_RCTL),

    [KM_FUNC] = LAYOUT(
        KC_GRV,   KC_F1,    KC_F2,   KC_F3,    KC_F4,    KC_F5,   KC_F6,   KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_F11, KC_F12,  KC_TRNS,  KC_DEL,
        KC_TRNS,  	KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_INS,    KC_PSCR,    KC_SLCK,    KC_PAUS,    KC_UP, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_VOLU,    KC_VOLD,   KC_MUTE,    KC_EJCT,    KC_TRNS,   KC_ASTR,   KC_PCMM,    KC_HOME,    KC_PGUP,    KC_LEFT, KC_RIGHT, KC_TRNS,
        KC_TRNS, 	KC_NUBS,   KC_MPRV,   KC_MNXT,    KC_MPLY,    KC_MSTP,   KC_TRNS,   KC_PPLS,    KC_PMNS,    KC_END, KC_PGDN,  KC_DOWN, MO(KM_SETTINGS), KC_TRNS,
        KC_TRNS, 	KC_TRNS, KC_APFN, XXXXXXX, KC_TRNS, XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX,  KC_APP,  KC_TRNS),

    [KM_SETTINGS] = LAYOUT(
        GE_SWAP,   XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,    KC_BRIU,    KC_BRID,    XXXXXXX,    KC_MYCM, KC_WAKE,  XXXXXXX,  KC_PWR,
        GE_NORM,  	XXXXXXX,   RGB_SAI,   XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,    RGB_VAI,    XXXXXXX,    XXXXXXX,    XXXXXXX, BS_NORM, BS_SWAP,
        XXXXXXX, RGB_HUD,    RGB_SAD,   RGB_HUI,    XXXXXXX,    XXXXXXX,   XXXXXXX,   RGB_SPD,  RGB_VAD,  RGB_SPI,    XXXXXXX, XXXXXXX, DEBUG,
        XXXXXXX, 	XXXXXXX,   RGB_M_P,   RGB_M_B,    RGB_M_R,    RGB_M_SW,   XXXXXXX,   NK_TOGG,    XXXXXXX, RGB_RMOD, RGB_MOD, RGB_TOG, EEP_RST, XXXXXXX,
        RESET, GUI_OFF, AG_NORM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AG_SWAP, XXXXXXX, GUI_ON,  XXXXXXX),
};

/*
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX, KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, XXXXXXX,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,  KC_SPC,  KC_SPC,           KC_RALT, XXXXXXX, XXXXXXX, MO(1),   KC_RCTL
    ),

    LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_DEL,
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, RESET,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                   _______, _______, _______,          _______, _______, _______, _______, _______
    )
};
*/

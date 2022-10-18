/*!
    \file       keymap.c
    \brief      Keymap source file for Hineybush H88 family of TKL PCBs

    \author     Gemuele Aludino
    \date       17 Oct 2022
 */

#include "config.h"
#include "layout.h"

#include QMK_KEYBOARD_H

/*!
    \enum   keymap_layout   Members are used to switch between different layers
 */
enum keymap_layout {
    KM_MAIN = 0,      //<! Default layout, left side R0 is macOS-centric, right side R0 is Windows-centric
    KM_FUNC,          //<! Function keymap, activated by holding Fn key
    KM_SETTINGS,      //<! Keymap to configure keyboard hardware/firmware settings
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Main layer (KM_MAIN)
     *
     * ┌───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┐ ┌───┬───┬───┐
     * │Esc││F1 │F2 │F3 │F4 ││F5 │F6 │F7 │F8 ││F9 │F10│F11│F12││F13│ │PSc│Scr│Pse│
     * └───┘└───┴───┴───┴───┘└───┴───┴───┴───┘└───┴───┴───┴───┘└───┘ └───┴───┴───┘
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐ ┌───┬───┬───┐
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ \ │Bks│ │Afn│Hom│PgU│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤ ├───┼───┼───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │ | \ │ │Del│End│PgD│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────│ └───┴───┴───┘
     * │FN/Esc│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┬────┤     ┌───┐
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │Sft  │| \ │     │ ↑ │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴───┴───┼───┴┬────┴────┤ ┌───┼───┼───┐
     * │Ctrl│Alt │GUI │                             │Alt │GUI │Ctrl│ │ ← │ ↓ │ → │
     * └────┴────┴────┴─────────────────────────────┴────┴────┴────┘ └───┴───┴───┘
     *
     * FN/Esc or F/Es - Tap for Escape, hold for function layer
     * Bks - Backspace
     * PSc - Print Screen
     * Scr - Scroll Lock
     * Pse - Pause
     * Afn - Apple Fn
     * Hom - Home
     * PgU - Page Up
     * Del - Delete
     * End - End
     * PgD - Page Down
     * GUI - Windows or Command
     */
  [KM_MAIN] = LAYOUT_tkl_ansi_wkl_custom(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,     KC_F11,     KC_F12,  KC_F13,                    KC_PSCR, KC_SLCK, KC_PAUS,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,    KC_EQL,     KC_BSLS, KC_BSPC,           KC_APFN,  KC_HOME, KC_PGUP,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,    KC_RBRC,    KC_BSLS,                    KC_DEL,  KC_END,  KC_PGDN,
    LT(KM_FUNC, KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,                KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, KC_BSLS,                                                 KC_UP,
    KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                                      KC_RALT,   KC_RGUI,   KC_RCTL,                                         KC_LEFT, KC_DOWN, KC_RGHT),

    /*
     * Function layer (KM_FUNC)
     *
     * ┌───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┐ ┌───┬───┬───┐
     * │   ││F14│F15│F16│F17││F18│F19│F20│F21││F22│F23│F24│   ││   │ │   │   │   │
     * └───┘└───┴───┴───┴───┘└───┴───┴───┴───┘└───┴───┴───┴───┘└───┘ └───┴───┴───┘
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐ ┌───┬───┬───┐
     * │   │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│   │   │ │Ins│   │   │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤ ├───┼───┼───┤
     * │     │   │ ↑ │   │   │   │   │Ins│Hom│PgU│PSc│Scr│Pse│Del  │ │   │   │   │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────│ └───┴───┴───┘
     * │CapsLk│ ← │ ↓ │ → │AFn│   │ ← │ ↑ │ ↓ │ → │   │   │        │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┬────┤     ┌───┐
     * │        │   │   │   │   │   │Del│End│PgD│   │   │     │F/Es│     │   │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴───┴───┼───┴┬────┴────┤ ┌───┼───┼───┐
     * │    │    │    │       SETTINGS              │    │    │    │ │   │   │   │
     * └────┴────┴────┴─────────────────────────────┴────┴────┴────┘ └───┴───┴───┘
     */
  [KM_FUNC] = LAYOUT_tkl_ansi_wkl_custom(
    _______,     KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24, XXXXXXX,                 XXXXXXX,             _______,  _______, _______,   \
    _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,                      _______, KC_DEL,             KC_INS,   _______, _______,   \
    _______,    _______, KC_UP, _______, _______, _______, _______, KC_INS, KC_HOME, KC_PGUP, KC_PSCR, KC_SLCK, KC_PAUS,        _______,            _______,  _______, _______, \
    KC_CAPS,        KC_LEFT, KC_DOWN, KC_RIGHT, KC_APFN, _______, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT, _______, _______,          _______,                                   \
    _______,  _______, _______, _______, _______, _______, KC_DEL, KC_END, KC_PGDN, _______,  _______,        _______, _______,              _______,            \
    _______, _______, _______,                            MO(KM_SETTINGS),                      KC_RALT, _______, _______,         _______,  _______, _______    \
    ),

    /*
     * Settings layer (KM_SETTINGS)
     *
     * ┌───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┐ ┌───┬───┬───┐
     * │   ││   │   │   │   ││   │   │   │   ││   │   │   │   ││RST│ │   │   │   │
     * └───┘└───┴───┴───┴───┘└───┴───┴───┴───┘└───┴───┴───┴───┘└───┘ └───┴───┴───┘
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐ ┌───┬───┬───┐
     * │   │Mte│VDn│VUp│Prv│Ply│Nxt│Stp│BrD│BrU│   │MPc│Wak│Pow│   │ │   │   │   │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤ ├───┼───┼───┤
     * │     │   │SAI│   │   │   │   │   │VAI│   │   │   │   │     │ │   │   │   │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────│ └───┴───┴───┘
     * │      │HUD│SAD│HUI│   │   │   │SPD│VAD│SPI│   │   │DEBUG   │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┬────┤     ┌───┐
     * │        │   │   │   │   │   │NKR│   │RMD│MOD│TOG│     │    │     │   │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴───┴───┼───┴┬────┴────┤ ┌───┼───┼───┐
     * │CGTG│    │    │                             │    │    │    │ │   │   │   │
     * └────┴────┴────┴─────────────────────────────┴────┴────┴────┘ └───┴───┴───┘
     *
     * SAI - RGB Saturation +
     * SAD - RGB Saturation -
     * HUI - RGB Hue +
     * HUD - RGB Hue -
     * VAI - RGB Value (brightness) +
     * VAD - RGB Value (brightness) -
     * SPI - RGB Speed +
     * SPD - RGB Speed -
     * RMD - RGB Cycle Mode Reverse
     * MOD - RGB Cycle Mode Forward
     *
     * CGTG - Toggle Left Control/Left GUI swap
     * DEBUG - Debug Mode
     * RST - Soft Reset
     */
  [KM_SETTINGS] = LAYOUT_tkl_ansi_wkl_custom(
    XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,            XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, KC_BRID, KC_BRIU, XXXXXXX, KC_MYCM,  KC_WAKE,  KC_PWR, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX,  XXXXXXX, RGB_SAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX,  RGB_HUD,  RGB_SAD,  RGB_HUI, XXXXXXX, XXXXXXX, XXXXXXX, RGB_SPD, RGB_VAD, RGB_SPI, XXXXXXX, XXXXXXX,   DEBUG,                                   \
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, NK_TOGG, XXXXXXX, RGB_RMOD, RGB_MOD, RGB_TOG,         XXXXXXX,  XXXXXXX,                    XXXXXXX,          \
    CG_TOGG, XXXXXXX, XXXXXXX,                            XXXXXXX,                                                 XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX  \
  )
};

/*!
    \brief TODO description
 */
void matrix_init_user(void) {

}

/*!
    \brief TODO description
 */
void matrix_scan_user(void) {

}

/*!
    \brief TODO description

    \param keycode  TODO description
    \param record   TODO description
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

/*!
    \file       keymap.c
    \brief      Source file for unloved_bastard layout (keymappings)

    \author     Gemuele Aludino
    \date       09 Oct 2020
    \copyright  Copyright © 2020 Gemuele Aludino


    Copyright © 2020 Gemuele Aludino

    Permission is hereby granted, free of charge, to any person obtaining
    a copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
    DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
    TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH
    THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include QMK_KEYBOARD_H

/*!
    \enum   keymap_layout   Members are used by TG(layer) macro (to toggle a layer on or off)
                            to switch between different layers
 */
enum keymap_layout {
    KM_MACOS = 0,     //<! matches MF68 layout, macOS-centric layout
    KM_WIN,           //<! Windows-centric layout
    KM_FUNC,          //<! 0x08, function keymap, activated by holding Fn key
    KM_SETTINGS,      //<! 0x10, keymap to configure keyboard hardware/firmware settings
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*! Keymap KM_MACOS: (Base Layer) macOS-centric Layer
     ,-----------------------------------------------------------------------------.
     |Esc  |f1| f2| f3| f4|  | f5| f6| f7| f8|   | f9|f10|f11|f12|  |Prnt|ScLk|Paus|
     |-----------------------------------------------------------|  |--------------|
     | ~ | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |  0| - | = |Backsp |  | Ins|Home|PgUp|
     |-----------------------------------------------------------|  |--------------|
     |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|  | Del| End|PgDn|
     |-----------------------------------------------------------|  `--------------'
     |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
     |-----------------------------------------------------------|        ,----.
     |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |        | Up |
     |-----------------------------------------------------------|   ,-------------.
     |Ctrl |Alt | GUI |         Space           | GUI |Func| Ctrl|   |Lft | Dn |Rig|
     `-----------------------------------------------------------'   `-------------'
  */
  [KM_MACOS] = LAYOUT_tkl_ansi(
    KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,       KC_PSCR, KC_SLCK, KC_PAUS, \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_BSPC,      KC_INS,  KC_HOME, KC_PGUP, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,  KC_BSLS,      KC_DEL,  KC_END,  KC_PGDN, \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,                                  \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                    KC_RSFT,               KC_UP,            \
    KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_NO,   KC_RGUI, MO(KM_FUNC),  KC_RCTL,      KC_LEFT, KC_DOWN, KC_RGHT  \
    ),

  /*! Keymap KM_WIN: (Secondary Layer) Windows-centric Layer
     ,-----------------------------------------------------------------------------.
     |Esc  |f1| f2| f3| f4|  | f5| f6| f7| f8|   | f9|f10|f11|f12|  |Prnt|ScLk|Paus|
     |-----------------------------------------------------------|  |--------------|
     | ~ | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |  0| - | = |Backsp |  | Ins|Home|PgUp|
     |-----------------------------------------------------------|  |--------------|
     |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|  | Del| End|PgDn|
     |-----------------------------------------------------------|  `--------------'
     |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
     |-----------------------------------------------------------|        ,----.
     |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |        | Up |
     |-----------------------------------------------------------|   ,-------------.
     |Ctrl |GUI  |Alt  |        Space           | Alt |Func| Ctrl|   |Lft | Dn |Rig|
     `-----------------------------------------------------------'   `-------------'
  */
  [KM_WIN] = LAYOUT_tkl_ansi(
    KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,       KC_PSCR, KC_SLCK, KC_PAUS, \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_BSPC,      KC_INS,  KC_HOME, KC_PGUP, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,  KC_BSLS,      KC_DEL,  KC_END,  KC_PGDN, \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,                                  \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                    KC_RSFT,               KC_UP,            \
    KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_NO, KC_RALT,MO(KM_FUNC), KC_RCTL,      KC_LEFT, KC_DOWN, KC_RGHT  \
    ),

  /*! Keymap KM_FUNC: Function Layer
     ,-------------------------------------------------------------.  ,--------------.
     |Esc  |f1| f2| f3| f4|  | f5| f6| f7| f8|   | f9|f10|f11|f12  |  |Prnt|ScLk|Paus|
     |-------------------------------------------------------------|  |--------------|
     | ` |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Delete   |  |    |    |    |
     |-------------------------------------------------------------|  |--------------|
     |Tab  |   |PgU|   |   |   |   |   | Up|   |   |   |   |       |  |    |    |    |
     |-------------------------------------------------------------|  `--------------'
     |Control|Hme|PgD|End|   |   |   |Lft|Dwn|Rgt|   |   |TG(WIN)  |
     |-------------------------------------------------------------|       ,----.
     |Shift   |   |Del|   |   |   |   |Mute|V- |V+ |  |TG(SETTINGS)|       | Up |
     |-------------------------------------------------------------'   ,-------------.
     |Func|Win |Alt |        PgD                  | Alt |Ctrl| Func|   |Lft| Dn |Rig |
     `-------------------------------------------------------------'   `-------------'
  */
  [KM_FUNC] = LAYOUT_tkl_ansi(
    KC_ESC,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           KC_PSCR, KC_SLCK, KC_PAUS, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,            _______, _______, _______, \
    XXXXXXX, XXXXXXX, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           _______, _______, _______, \
    _______, KC_HOME, KC_PGDN, KC_END,  XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,          TG(KM_WIN),                                   \
    _______, XXXXXXX, KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX,                   TG(KM_SETTINGS),            _______,          \
    _______, _______, _______,                            KC_PGDN,                            _______, _______, _______, _______,           _______, _______, _______  \
  ),

  /*! Keymap KM_SETTINGS: Settings Layer
     ,------------------------------------------------------------.  ,-------------.
     |Esc  |f1| f2| f3| f4|  | f5| f6| f7| f8|   | f9|f10|f11|f12 |  |Prnt|ScLk|Paus|
     |------------------------------------------------------------|  |--------------|
     |FN0 |   |   |   |   |   |   |   |   |  |   |BL-|BL+|BL Togl |  |RGB Tog |Val+|
     |------------------------------------------------------------|  |-------------|
     |MuMode|   |   |   |   |   |   |   |   |   |   |   |  |LEDTst|  |RGB Mode|Val-|
     |------------------------------------------------------------|  `-------------'
     |AudTgl |Hz+|MS+|   |   |   |   |   |   |   |   |   |  RST   |
     |------------------------------------------------------------|       ,----.
     |ClickTgl|Hz-|MS-|   |   |   |   |   |   |   |   |Layer Clr  |       |Hue+|
     |------------------------------------------------------------   ,--------------.
     |    |    |    |                            |    |     |     |  |Sat-|Hue-|Sat+|
     `------------------------------------------------------------'  `--------------'
   */
  [KM_SETTINGS] = LAYOUT_tkl_ansi(
    KC_FN0,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BL_DEC,       XXXXXXX, XXXXXXX, XXXXXXX, \
    KC_FN0,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BL_DEC,  BL_INC,  BL_TOGG,      RGB_TOG, RGB_VAI, XXXXXXX, \
    MU_MOD,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_FN2,       RGB_MOD, RGB_VAD, XXXXXXX, \
    AU_TOG,  KC_FN1,  KC_FN3,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          RESET,                                   \
    KC_FN5,  KC_FN2,  KC_FN4,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MU_TOG,  XXXXXXX, XXXXXXX, XXXXXXX,                   TG(KM_MACOS),               RGB_HUI,          \
    XXXXXXX, XXXXXXX, XXXXXXX,                            KC_FN12,                            XXXXXXX, XXXXXXX, XXXXXXX, _______,      RGB_SAD, RGB_HUD, RGB_SAI  \
  ),
};

void matrix_init_user(void) {
    // This keymap only has a single base layer, so reset the default if needed
    if (eeconfig_read_default_layer() > 1){
        eeconfig_update_default_layer(1);
        default_layer_set(1);
    }
}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void led_set_user(uint8_t usb_led) {

}

/**
 *  @file       gcskb.h
 *  @brief      Header file for qmk firmware (keymappings)
 *
 *  @author     Gemuele Aludino
 *  @date       23 May 2020
 *  @copyright  Copyright © 2020 Gemuele Aludino
 */
/**
 *  Copyright © 2020 Gemuele Aludino
 *
 *  Permission is hereby granted, free of charge, to any person obtaining
 *  a copy of this software and associated documentation files (the "Software"),
 *  to deal in the Software without restriction, including without limitation
 *  the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *  and/or sell copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included
 *  in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 *  DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 *  TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH
 *  THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef GCSKB_H
#define GCSKB_H

#include "quantum.h"

/**
 *  @enum keymap_layout Members are used by TG(layer) macro (to toggle a layer on or off)
 *                      to switch between different layers
 */
enum keymap_layout {
    KM_MACOS,       /*<< macOS-centric layout */
    KM_WIN,         /*<< Windows-centric layout */
    KM_FUNC,        /*<< Function keymap, activated by holding Fn key */
    KM_SETTINGS     /*<< Keymap to configure keyboard hardware/firmware settings */
};

  /**
   *  Default keymap for gcskb_TKL86
   *
   *  86 key TKL (tenkeyless) layout
   *  ANSI, with 7u spacebar and 1.5-1.0-1.5 bottom row modifiers
   *
   * ,--------------------------------------------------------------------------.
   * |000|   |002|003|004|005| |006|007|008|009| |010|011|012|013|  |014|015|016|
   * |-----------------------------------------------------------|  |-----------|
   * |100|101|102|103|104|105|106|107|108|109|110|111|112|  113  |  |114|115|116|
   * |-----------------------------------------------------------|  |-----------|
   * | 200 |201|202|203|204|205|206|207|208|209|210|211|212| 213 |  |214|215|216|
   * |-----------------------------------------------------------|  `-----------'
   * |  300  |301|302|303|304|305|306|307|308|309|310|311|  313  |
   * |-----------------------------------------------------------|      ,---.
   * |   400  |402|403|404|405|406|407|408|409|410|411|   413    |      |415|
   * |-----------------------------------------------------------|  ,-----------.
   * | 500 |501| 502 |            506          | 510 |511|  513  |  |514|515|516|
   * `-----------------------------------------------------------'  `-----------'
   *
   * All layers created for this keyboard will be based off of this keymap.
   */
#define KEYMAP_GCSKB_ANSI_7U( \
	K000,       K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015, K016, \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116, \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216, \
	K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311,       K313,                   \
	K400,       K402, K403, K404, K405, K406, K407, K408, K409, K410, K411,       K413,       K415,       \
	K500, K501, K502,                   K506,                   K510, K511,       K513, K514, K515, K516  \
) { \
	{ K000,  KC_NO, K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011,  K012,  K013,  K014,  K015,  K016 }, \
	{ K100,  K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111,  K112,  K113,  K114,  K115,  K116 }, \
	{ K200,  K201,  K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211,  K212,  K213,  K214,  K215,  K216 }, \
	{ K300,  K301,  K302,  K303,  K304,  K305,  K306,  K307,  K308,  K309,  K310,  K311,  KC_NO, K313,  KC_NO, KC_NO, KC_NO }, \
	{ K400,  KC_NO, K402,  K403,  K404,  K405,  K406,  K407,  K408,  K409,  K410,  K411,  KC_NO, K413,  KC_NO, K415,  KC_NO }, \
	{ K500,  K501,  K502,  KC_NO, KC_NO, KC_NO, K506,  KC_NO, KC_NO, KC_NO, K510,  K511,  KC_NO, K513,  K514,  K515,  K516 }  \
}

  /**
   *  Default layer for gcskb_TKL86
   *  macOS-centric
   *
   *  Press and hold the Fn key to enter LAYER_FUNCTION,
   *  where you may switch to the following layers:
   *    - LAYER_QWERTY_WIN, the alternate layer (Windows-centric)
   *    - LAYER_SETTINGS, where keyboard hardware/firmware is configured
   *      (can be used to enter DFU mode, see LAYER_SETTINGS for more)
   *
   *  To switch to LAYER_QWERTY_WIN, press and hold Fn, then hit Return.
   *  To switch to LAYER_SETTINGS, press and hold Fn, then it RShift.
   *
   * ,--------------------------------------------------------------------------.
   * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12|  |PSc|SLk|Pse|
   * |-----------------------------------------------------------|  |-----------|
   * |`  |1  |2  |3  |4  |5  |6  |7  |8  |9  |0  |-  |=  |Backspc|  |Ins|Hme|PgU|
   * |-----------------------------------------------------------|  |-----------|
   * | Tab |Q  |W  |E  |R  |T  |Y  |U  |I  |O  |P  |[  |]  | \   |  |Del|End|PgD|
   * |-----------------------------------------------------------|  `-----------'
   * |CapsLk|A  |S  |D  |F  |G  |H  |J  |K  |L  |;  |'  | Return |
   * |-----------------------------------------------------------|      ,---.
   * | LShift |Z  |X  |C  |V  |B  |N  |M  |,  |.  |/  |  RShift  |      |Up |
   * |-----------------------------------------------------------|  ,-----------.
   * |LCtrl|LOp|LCmd |           Space           |RCmd |Fn |RCtrl|  |Lft|Dwn|Rgt|
   * `-----------------------------------------------------------'  `-----------'
   */
#define LAYER_QWERTY_MAC\
	KEYMAP_GCSKB_ANSI_7U(\
		KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SLCK, KC_PAUS,\
		KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_INS, KC_HOME, KC_PGUP,\
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, KC_END, KC_PGDN,\
		KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,\
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP,\
		KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_RGUI, MO(KM_FUNC), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT)\

  /**
   *  Alternate layer for gcskb_TKL86
   *  Windows-centric
   *
   *  Press and hold the Fn key to enter LAYER_FUNCTION,
   *  where you may switch to the following layers:
   *    - LAYER_QWERTY_MAC, the main layer (macOS-centric)
   *    - LAYER_SETTINGS, where keyboard hardware/firmware is configured
   *      (can be used to enter DFU mode, see LAYER_SETTINGS for more)
   *
   *  To switch to LAYER_QWERTY_MAC, press and hold Fn, then hit Return.
   *  To switch to LAYER_SETTINGS, press and hold Fn, then it RShift.
   *
   * ,--------------------------------------------------------------------------.
   * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12|  |PSc|SLk|Pse|
   * |-----------------------------------------------------------|  |-----------|
   * |`  |1  |2  |3  |4  |5  |6  |7  |8  |9  |0  |-  |=  |Backspc|  |Ins|Hme|PgU|
   * |-----------------------------------------------------------|  |-----------|
   * | Tab |Q  |W  |E  |R  |T  |Y  |U  |I  |O  |P  |[  |]  | \   |  |Del|End|PgD|
   * |-----------------------------------------------------------|  `-----------'
   * |CapsLk|A  |S  |D  |F  |G  |H  |J  |K  |L  |;  |'  | Return |
   * |-----------------------------------------------------------|      ,---.
   * | LShift |Z  |X  |C  |V  |B  |N  |M  |,  |.  |/  |  RShift  |      |Up |
   * |-----------------------------------------------------------|  ,-----------.
   * |LCtrl|LWn|LAlt |           Space           |RAlt |Fn |RCtrl|  |Lft|Dwn|Rgt|
   * `-----------------------------------------------------------'  `-----------'
   */
#define LAYER_QWERTY_WIN\
	KEYMAP_GCSKB_ANSI_7U(\
		KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SLCK, KC_PAUS,\
		KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_INS, KC_HOME, KC_PGUP,\
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, KC_END, KC_PGDN,\
		KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,\
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP,\
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(KM_FUNC), KC_RCTL, KC_LEFT,\
        KC_DOWN, KC_RGHT)\

  /**
   *  Function layer for gcskb_TKL86
   *
   *  Enter the Function layer by pressing and holding the Fn key,
   *  while in the macOS layer or Windows layer.
   *
   *  While holding the Fn key, you may enter the following layers by doing the following:
   *  - Return to toggle between the macOS layer and Windows layer
   *  - RShift to switch to the Settings layer.
   *
   *  For all other keys not mentioned above, they are 'KC_TRNS' (transparent),
   *  which means they retain the keycode from the previous layer.
   */
#define LAYER_FUNCTION\
	KEYMAP_GCSKB_ANSI_7U(\
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,\
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,\
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,\
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(KM_WIN),\
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(KM_SETTINGS), KC_TRNS,\
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)\

  /**
   *  Settings layer for gcskb_TKL86
   *
   *  Enter the Settings layer by pressing and holding the Fn key (thereby entering the Function layer)
   *  while in the macOS layer or Windows layer -- then hit the RShift key.
   *
   *  This layer is virtually identical to the Function layer,
   *  but exposes additional settings for keyboard hardware/firmware.
   *
   *  While in the Settings layer, you have the following options available:
   *  - Enter DFU mode (for flashing firmware with QMK Toolbox) by hitting Esc
   *    The only way to exit DFU mode is to
   *        - Use the 'Exit DFU' option on QMK Toolbox
   *        - Unplug and replug the keyboard (you will return to LAYER_QWERTY_MAC)
   *
   *  So, while in the macOS layer or Windows layer,
   *  to enter DFU mode:
   *  - Press and hold Fn, then hit RShift. Finally, hit Esc.
   *
   *  For all other keys not mentioned above, they are 'KC_TRNS' (transparent),
   *  which means they retain the keycode from the previous layer.
   */
#define LAYER_SETTINGS\
	KEYMAP_GCSKB_ANSI_7U(\
		RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,\
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,\
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,\
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(KM_WIN),\
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(KM_SETTINGS), KC_TRNS,\
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)\

/**
 *  Transparent layer for gcskb_TKL86
 *
 *  Use this layer as a template for new layers that you may want to create.
 */
#define _LAYER_TRANSPARENT\
	KEYMAP_GCSKB_ANSI_7U(\
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,\
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,\
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,\
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,\
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,\
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)\

#endif /* GCSKB_H */

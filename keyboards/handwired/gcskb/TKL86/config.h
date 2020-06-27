/**
 *  @file       config.h
 *  @brief      Header file for qmk firmware (firmware directives)
 *
 *  @author     Gemuele Aludino
 *  @date       08 Jun 2020
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
#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/*<< Use this directive to enable macOS-related functionality */
#define ASSUME_APPLE

/*<< USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0100
#define MANUFACTURER    galudino
#define PRODUCT         gcskb_TKL86
#define DESCRIPTION     USB Handwired ANSI TKL keyboard

#ifdef ASSUME_APPLE
# undef VENDOR_ID
# undef PRODUCT_ID
# define VENDOR_ID      0x05ac
# define PRODUCT_ID     0x024f
#endif /* ASSUME_APPLE */

/*<< key matrix size - 23 total pins used, 86/102 elements used */
#define MATRIX_ROWS 6
#define MATRIX_COLS 17

/*<< key matrix pins: rows */
#define MATRIX_ROW_PINS { D2, D3, C6, C7, D4, D5 }

/*<< key matrix pins: columns */
#define MATRIX_COL_PINS { D6, D7, B4, B5, F7, F6, F5, F4, D1, D0, F0, B3, E6, B2, B1, F1, B0 }

#define UNUSED_PINS

/*<< COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/*<< number of backlight levels */
#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 3
#endif /* BACKLIGHT_PIN */

/*<< Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/*<< Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/*<< Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/*<< key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/*<< prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS

/*<< RGB DI PIN */
#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 2
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#endif /* RGB_DI_PIN */

#endif /* CONFIG_H */

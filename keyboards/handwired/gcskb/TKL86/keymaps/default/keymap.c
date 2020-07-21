/**
 *  @file       keymap.c
 *  @brief      Source file for qmk firmware (keyboard matrix)
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
#include "gcskb.h"
#include "config.h"

enum keymap_layout {
    KM_MACOS = 0,
    KM_WIN,
    KM_FUNC,
    KM_SETTINGS
};

/**
 *	TODO: doc
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [KM_MACOS] = MAIN_LAYER_QWERTY_MAC,
    [KM_WIN] = ALTERNATE_LAYER_QWERTY_WIN,
    [KM_FUNC] = FUNCTION_LAYER,
    [KM_SETTINGS] = SETTINGS_LAYER
};

/**
 * 	TODO: doc
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	/*
	keyevent_t event = record->event;

	switch (id) {

	}
	*/

	return MACRO_NONE;
}

/**
 *  TODO: doc
 */
void keyboard_pre_init_user() {
    setPinOutput(B6);
    setPinOutput(B7);
}

/**
 * 	TODO: doc
 */
void matrix_init_user(void) {

}

/**
 * 	TODO: doc
 */
void matrix_scan_user(void) {

}

/**
 * 	TODO: doc
 */
void led_set_user(uint8_t usb_led) {
	if (usb_led & (1 << USB_LED_NUM_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		DDRB |= (1 << 6); PORTB &= ~(1 << 6);
	} else {
		DDRB &= ~(1 << 6); PORTB &= ~(1 << 6);
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		DDRB |= (1 << 7); PORTB &= ~(1 << 7);
	} else {
		DDRB &= ~(1 << 7); PORTB &= ~(1 << 7);
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_KANA)) {

	} else {

	}
}

/**
 *  TODO: doc
 */
bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);

    if (res) {
        // writePin sets the pin high for 1 and low for 0.
        // In this example the pins are inverted, setting
        // it low/0 turns it on, and high/1 turns the LED off.
        // This behavior depends on whether the LED is between the pin
        // and VCC or the pin and GND.

        writePin(B6, !led_state.caps_lock);
        writePin(B7, !led_state.scroll_lock);
    }

    return res;
}


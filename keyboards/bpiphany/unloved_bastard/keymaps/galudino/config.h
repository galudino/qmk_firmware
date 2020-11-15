/*!
    \file       config.h
    \brief      Keymap header for The Unloved Bastard

    \author     Gem Aludino
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

#pragma once

/*!
    \define     ASSUME_APPLE
    \brief      Use this directive to enable macOS-related functionality.

    \details    Many keyboards that are marketed as "Apple macOS-friendly"
                keyboards will use the Apple Inc. vendor ID, and the
                Apple Pro Keyboard product ID.

                When the correct VENDOR_ID and PRODUCT_ID are used,
                the APPLE_FN_ENABLE directive may be defined to enable
                Apple's 'fn' key (not to be confused with QMK's layer keys),
                which is recognized by macOS.

                By default, pressing any of the f-row keys while
                holding the Apple 'fn' key will invoke the "actual"
                F1-F12 keycode, instead of brightness down/up for F1/F2,
                etc.

                The Apple 'fn' key is identified as:
                    KC_APPLE_FN
                    KC_APFN

                Courtesy of user fauxpark.
                https://github.com/qmk/qmk_firmware/issues/2179

                Use of the Apple 'fn' key is not part of stock
                QMK/TMK and will likely not be merged with
                the master branch.

                To add this functionality to your own copy
                of the qmk_firmware repo, retrieve the diff
                (applefn.patch) from the GitHub issue link above.

                Download applefn.patch into your local copy
                of the qmk_firmware repository.

                Then, patch applefn.patch into the repo
                using the following:

                ```c
                % cd qmk_firmware;
                % patch -rUN -d ./ < applefn.patch;
                ```

                When prompted, provide the relative path
                of the file to be patched.
                The following files should be changed:

                    qmk_firmware/common_features.mk
                    qmk_firmware/quantum/keymap_common.c
                    qmk_firmware/tmk_core/common/action.c
                    qmk_firmware/tmk_core/common/action_code.h
                    qmk_firmware/tmk_core/common/keycode.h
                    qmk_firmware/tmk_core/common/report.c
                    qmk_firmware/tmk_core/protocol/usb_descriptor.c
                    qmk_firmware/tmk_core/protocol/vusb/vusb.c

                This copy of qmk_firmware is already patched
                to support the Apple fn key.
*/
#define ASSUME_APPLE

#ifdef ASSUME_APPLE
# undef VENDOR_ID
# undef PRODUCT_ID
# define VENDOR_ID      0x05ac  //<! (Apple Inc.)
# define PRODUCT_ID     0x024f  //<! Apple Pro Keyboard
# define APPLE_FN_ENABLE        //<! Enables keycode KC_APPLE_FN aka KC_APFN
#endif /* ASSUME_APPLE */

/*!
    \file       config.h
    \brief      Header file for qmk firmware (firmware directives)

    \author     Gemuele Aludino
    \date       26 Nov 2021
    \copyright  Copyright (c) 2021 Gemuele Aludino
 */

#ifndef CONFIG_H
#define CONFIG_H

#define ASSUME_APPLE

#include "config_common.h"

#ifdef ASSUME_APPLE
# undef VENDOR_ID
# undef PRODUCT_ID
# define VENDOR_ID          0x05ac  //<! (Apple Inc.)
# define PRODUCT_ID         0x024f  //<! (Apple Pro Keyboard)
# define APPLE_FN_ENABLE            //<! Enables keycode KC_APPLE_FN aka KC_APFN
#endif /* ASSUME_APPLE */

#endif /* CONFIG_H */

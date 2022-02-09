/*!
    \file       config.h
    \brief      Header file for qmk firmware (firmware directives)

    \author     Gemuele Aludino
    \date       16 Oct 2021
    \copyright  Copyright (c) 2021 Gemuele Aludino
 */

#define ASSUME_APPLE

#ifdef ASSUME_APPLE
# undef VENDOR_ID
# undef PRODUCT_ID
# define VENDOR_ID  0x05ac  //<! (Apple Inc.)
# define PRODUCT_ID 0x024f  //<! Apple Pro keyboard
# define APPLE_FN_ENABLE    //<! Enables keycode KC_APPLE_FN aka KC_APFN

#endif /* ASSUME_APPLE */

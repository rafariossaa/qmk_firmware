// Copyright 2024 Rafael Rios Saavedra (@Rafael Rios Saavedra)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */
#define RGBLIGHT_LED_COUNT 1

#define RGBLIGHT_HUE_STEP 148
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

// Selectively enable animations to save on code size.
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_LAYERS

#undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#undef RGBLIGHT_EFFECT_SNAKE
#undef RGBLIGHT_EFFECT_KNIGHT
#undef RGBLIGHT_EFFECT_CHRISTMAS
#undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#undef RGBLIGHT_EFFECT_RGB_TEST
#undef RGBLIGHT_EFFECT_ALTERNATING
#undef RGBLIGHT_EFFECT_TWINKLE

#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP10
#define I2C1_SCL_PIN GP11

#define OLED_BRIGHTNESS 128
#define OLED_IC OLED_IC_SH1106
#define OLED_COLUMN_OFFSET 2

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

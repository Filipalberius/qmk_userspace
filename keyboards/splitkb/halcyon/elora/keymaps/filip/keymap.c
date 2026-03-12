// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include <keymap_swedish.h>

enum layers {
    _QWERTY = 0,
    _SYM,
};

#define SYM      MO(_SYM)
// There is an extra row added for the Halcyon modules. Currently only the Encoder module is
// supported but we reserve 5 keys per half for future expansion. Your personal keymap will also
// need to be updated to include this row, and the `LAYOUT` macro will need to be updated to
// `LAYOUT_elora_hlc` in order to compile.

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 */
    [_QWERTY] = LAYOUT_elora_hlc(
     KC_ESC ,   SE_1 ,   SE_2 ,   SE_3 ,   SE_4 ,   SE_5 ,                                           SE_6 ,   SE_7 ,   SE_8 ,    SE_9 ,   SE_0 , KC_DEL ,
     KC_TAB ,   SE_Q ,   SE_W ,   SE_E ,   SE_R ,   SE_T ,                                           SE_Y ,   SE_U ,   SE_I ,    SE_O ,   SE_P , SE_ARNG,
     KC_CAPS,   SE_A ,   SE_S ,   SE_D ,   SE_F ,   SE_G ,                                           SE_H ,   SE_J ,   SE_K ,    SE_L , SE_ODIA, SE_ADIA,
     KC_LCTL,   SE_Z ,   SE_X ,   SE_C ,   SE_V ,   SE_B , KC_LEFT, KC_DOWN,     KC_UP  , KC_RGHT,   SE_N ,   SE_M , SE_COMM,  SE_DOT , SE_MINS, KC_ENT ,
                                MS_BTN1, MS_BTN2, KC_LSFT, KC_SPC , MO(1)  ,     KC_RGUI, KC_BSPC, KC_RSFT, KC_MPLY, KC_RALT
     KC_MUTE, KC_NO,  KC_NO, KC_NO, KC_NO,                                                                KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO
    ),


/*
 * Sym Layer: Numbers and symbols
 */
    [_SYM] = LAYOUT_elora_hlc(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      KC_GRV ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,                                       KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , KC_EQL ,
     KC_TILD , KC_EXLM,  KC_AT , KC_HASH,  KC_DLR, KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
     KC_PIPE , KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC, KC_LCBR, _______, _______, KC_RCBR, KC_RBRC, KC_UNDS, KC_COMM,  KC_DOT, KC_SLSH, KC_QUES,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______,  _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_PGUP, KC_PGDN),  ENCODER_CCW_CW(KC_PGUP, KC_PGDN)  },
    [1] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
};
#endif

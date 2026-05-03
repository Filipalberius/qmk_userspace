// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include <keymap_swedish.h>

enum layers {
    _QWERTY = 0,
    _SYM,
    _FN,
};

#define SYM MO(_SYM)
#define FN MO(_FN)
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
     KC_ESC ,   SE_1 ,   SE_2 ,   SE_3 ,   SE_4 ,   SE_5 ,                                           SE_6 ,   SE_7 ,   SE_8 ,   SE_9 ,   SE_0 , KC_DEL ,
     KC_TAB ,   SE_Q ,   SE_W ,   SE_E ,   SE_R ,   SE_T ,                                           SE_Y ,   SE_U ,   SE_I ,   SE_O ,   SE_P , SE_ARNG,
     KC_CAPS,   SE_A ,   SE_S ,   SE_D ,   SE_F ,   SE_G ,                                           SE_H ,   SE_J ,   SE_K ,   SE_L , SE_ODIA, SE_ADIA,
     KC_LCTL,   SE_Z ,   SE_X ,   SE_C ,   SE_V ,   SE_B , KC_LEFT, KC_DOWN,     KC_UP  , KC_RGHT,   SE_N ,   SE_M , SE_COMM, SE_DOT , SE_MINS, KC_ENT ,
                                KC_LALT,  KC_NO , KC_LSFT, KC_SPC , SYM    ,     KC_RGUI, KC_BSPC, KC_RSFT, KC_MPLY,     FN ,
     KC_MUTE,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                           KC_MUTE,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO
    ),

/*
 * Sym Layer: Numbers and symbols
 */
    [_SYM] = LAYOUT_elora_hlc(
      _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______,
      _______, SE_LABK, SE_LCBR, SE_LBRC, SE_LPRN, _______,                                        _______, SE_RPRN, SE_RBRC, SE_RCBR, SE_RABK, _______,
      _______, SE_CIRC, SE_HASH, SE_DQUO, SE_QUOT,  SE_EQL,                                        SE_TILD, SE_EXLM, SE_QUES, SE_AMPR, SE_PIPE, _______,
      _______,  SE_DLR,   SE_AT, SE_PERC, SE_SLSH, _______, KC_MPRV, _______,    _______, KC_MNXT, _______, SE_BSLS, SE_PLUS, SE_ASTR, _______, _______,
                                 _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
     _______, _______,  _______, _______, _______,                                                          _______, _______, _______, _______, _______
    ),

/*
 *  FN Layer
 */
    [_FN] = LAYOUT_elora_hlc(
      KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                                        KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
      _______, _______, _______, _______, _______, _______,                                        _______, UG_NEXT, UG_HUEU, UG_SATU, UG_VALU, _______,
      _______, _______, _______, _______, _______, _______,                                        _______, UG_PREV, UG_HUED, UG_SATD, UG_VALD, _______,
      _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, UG_TOGG, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
     _______, _______,  _______, _______, _______,                                                          _______, _______, _______, _______, _______
    ),
};

// combos
const uint16_t PROGMEM combo_qwerty_escape[] = {SE_S, SE_D,  SE_F, COMBO_END};
const uint16_t PROGMEM combo_qwerty_enter[] = {SE_J, SE_K,  SE_L, COMBO_END};

combo_t key_combos[2] = {
  COMBO(combo_qwerty_escape,     KC_ESC),
  COMBO(combo_qwerty_enter,      KC_ENT)
};


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_PGUP, KC_PGDN),  ENCODER_CCW_CW(KC_PGUP, KC_PGDN)  },
    [1] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
    [2] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
};
#endif

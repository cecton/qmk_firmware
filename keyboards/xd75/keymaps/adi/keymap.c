/* Copyright 2017 REPLACE_WITH_YOUR_NAME
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "xd75.h"

// Fillers to make layering more clear
#define _______ KC_TRNS
#define ___T___ KC_TRNS
#define XXXXXXX KC_NO

// Layer shorthand
#define _QW 0
#define _LW 1
#define _RS 2
#define _FN 3
#define _ENTFN 4
#define _MEDIA 5
#define _MOUSE 6

#define M_BACK 0
#define M_FWRD 1
#define M_PTAB 2
#define M_NTAB 3
#define M_ZOUT 4
#define M_ZOIN 5
#define M_ENTR 6
#define M_SCRN 7
#define M_NSPC 8
#define M_PSPC 9

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_QW] = { /* QWERTY */
  { KC_GRAVE,KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC  },
  { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_INSERT  },
  { KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    LT(_MOUSE, KC_SCLN), LT(_MEDIA, KC_QUOT), LT(_ENTFN, KC_ENT),  LT(_ENTFN, KC_ENT), KC_PGUP  },
  { KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT, KC_UP,   KC_PGDN  },
  { KC_LCTL, MO(_FN), KC_LGUI, KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  MO(_FN), KC_RALT, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT  },
 },

/* LOWERED
 */
 
 [_LW] = { /* LOWERED */
  { _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, KC_DEL  },
  { _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______, _______, KC_INS   },
  { _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, ___T___, ___T___, _______  },
  { _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, ___T___, ___T___, KC_PGUP, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END  },
 },

/* RAISED
 */
 
 [_RS] = { /* RAISED */
  { _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, KC_DEL  },
  { _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, _______, KC_INS   },
  { _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, ___T___, ___T___, _______  },
  { _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, ___T___, ___T___, KC_PGUP, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END  },
 },

/* FUNCTION
 */

 [_FN] = { /* FUNCTION */
  { RESET, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, KC_DEL  },
  { KC_SLCK, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  KC_PAUS, KC_PSCR  },
  { KC_CAPS, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______, _______, _______, _______  },
  { RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, BL_TOGG, BL_INC,  BL_DEC,   ___T___, ___T___, KC_PGUP, KC_WH_D  },
  { _______  , _______, _______, _______, _______, KC_BTN1, KC_BTN1, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END  },
 },

 [_ENTFN] = { /* Enter FN */
  { _______, _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______,  _______, _______  },
  { _______, M(M_PTAB), M(M_NTAB), M(M_PSPC), M(M_NSPC),  _______,  _______,  _______,  _______,  M(M_ZOUT), M(M_ZOIN),  _______,  _______,  _______, _______  },
  { _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______, _______, _______, _______  },
  { _______, M(M_BACK),  M(M_FWRD), _______, _______, _______, _______, _______, _______, _______,  _______,   _______, _______, _______, _______  },
  { _______  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
 },
 [_MEDIA] = { /* Media */
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, KC_SLCK, KC_PAUS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, KC_VOLU, _______, _______, _______, _______, _______, KC_MRWD, KC_MPLY, KC_MFFD, _______, _______, _______, _______, _______  },
  { _______, KC_VOLD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
 },
 [_MOUSE] = { /* Mouse */
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
 },
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  return MACRO_NONE;
};

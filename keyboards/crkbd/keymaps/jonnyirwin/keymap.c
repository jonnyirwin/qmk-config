/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum combos {
	SHIFT_L,
	SHIFT_R,
	CTRL_L,
	CTRL_R,
	GUI_L,
	GUI_R,
	ALT_L,
	ALT_R,
	ESC,
	TAB,
};

const uint16_t PROGMEM shift_l[] = {KC_P, KC_T, COMBO_END};
const uint16_t PROGMEM shift_r[] = {KC_L, KC_N, COMBO_END};
const uint16_t PROGMEM ctrl_l[] = {KC_F, KC_S, COMBO_END};
const uint16_t PROGMEM ctrl_r[] = {KC_U, KC_E, COMBO_END};
const uint16_t PROGMEM gui_l[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM gui_r[] = {KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM alt_l[] = {KC_Q, KC_A, COMBO_END};
const uint16_t PROGMEM alt_r[] = {KC_SCLN, KC_O, COMBO_END};
const uint16_t PROGMEM esc[] = {KC_J, KC_M, COMBO_END};
const uint16_t PROGMEM tab[] = {KC_B, KC_G, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
	[SHIFT_L] = COMBO(shift_l, KC_LSFT),
	[SHIFT_R] = COMBO(shift_r, KC_LSFT),
	[CTRL_L] = COMBO(ctrl_l, KC_LCTL),
	[CTRL_R] = COMBO(ctrl_r, KC_LCTL),
	[GUI_L] = COMBO(gui_l, KC_LGUI),
	[GUI_R] = COMBO(gui_r, KC_LGUI),
	[ALT_L] = COMBO(alt_l, KC_LALT),
	[ALT_R] = COMBO(alt_r, KC_LALT),
	[ESC] = COMBO(esc, KC_ESC),
	[TAB] = COMBO(tab, KC_TAB),
};


enum layer_names {
    _CK = 0,
    _NAV,
    _SYM,
    _MK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_CK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC ,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_HOME,   KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,  KC_O,   KC_PGUP ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_END,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_PGDN ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_BSPC, MO(_NAV), KC_SPC,     KC_ENT,   MO(_SYM), MO(_MK)
                                      //`--------------------------'  `--------------------------'
    ),

  [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS  ,    KC_1,    KC_2,    KC_3,    KC_4,  KC_5  ,                         KC_6,    KC_7,    KC_8,    KC_9,  KC_0  , KC_TRNS  ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS  , CAPS_WORD, KC_NO, KC_COMM, KC_DOT, KC_NO  ,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_NO  , KC_TRNS  ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS , S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),                      S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_TRNS  ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO , KC_TRNS, KC_NO ,    KC_TAB , S(KC_INS) , KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS  ,S(KC_6),KC_LBRC,S(KC_2),KC_RBRC, S(KC_8) ,                      KC_NUHS,S(KC_EQL),KC_MINS,S(KC_MINS),S(KC_SLSH), KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS  , S(KC_4), S(KC_9), KC_QUOT, S(KC_0), S(KC_7),                   S(KC_NUHS), S(KC_COMM), KC_EQL, S(KC_DOT),S(KC_QUOT),KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS , S(KC_5) ,S(KC_LBRC),KC_GRV,S(KC_RBRC), S(KC_NUBS),                KC_NUBS,S(KC_1),KC_DOT,S(KC_3),KC_SLSH,KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    KC_CAPS_LOCK,C(KC_BSPC),KC_DEL,    KC_NO,KC_TRNS, KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

   [_MK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS  ,KC_NO ,KC_NO ,KC_MS_U ,KC_WH_U ,KC_ACL2 ,                      KC_NO  ,KC_NO ,KC_NO ,KC_NO ,KC_NO , KC_TRNS ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS  ,KC_NO ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_ACL1 ,                      KC_NO ,KC_BTN1 ,KC_BTN2 ,KC_BTN3 ,KC_NO,  KC_TRNS ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS  ,KC_NO ,KC_NO ,KC_NO ,KC_WH_D ,KC_ACL0 ,                      KC_NO  ,KC_NO ,KC_NO ,KC_NO ,KC_NO , KC_TRNS ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO  , KC_TRNS, KC_TRNS,    KC_NO, KC_NO,  KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

  // Blank layer template
  //[_LABEL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //  KC_NO  ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,                    KC_TRNS  ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,  KC_NO ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //  KC_NO  ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,                    KC_TRNS  ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,  KC_NO ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //  KC_NO  ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,                    KC_TRNS  ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,  KC_NO ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                        KC_NO  , KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,  KC_NO
                                      //`--------------------------'  `--------------------------'
  //),
};

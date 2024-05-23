// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
	_CK = 0,
	_NAV,
	_SYM,
	_FN
};

enum combos {
	SHIFT_L,
	SHIFT_R,
	CTRL_L,
	CTRL_R,
	GUI_L,
	GUI_R,
	ALT_L,
	ALT_R,
	BKSPC,
	ESC,
	TAB,
	TMUX,
	FN_LYR
};

const uint16_t PROGMEM shift_l[] = {KC_P, KC_T, COMBO_END};
const uint16_t PROGMEM shift_r[] = {KC_L, KC_N, COMBO_END};
const uint16_t PROGMEM ctrl_l[] = {KC_F, KC_S, COMBO_END};
const uint16_t PROGMEM ctrl_r[] = {KC_U, KC_E, COMBO_END};
const uint16_t PROGMEM gui_l[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM gui_r[] = {KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM alt_l[] = {KC_Q, KC_A, COMBO_END};
const uint16_t PROGMEM alt_r[] = {KC_SCLN, KC_O, COMBO_END};
const uint16_t PROGMEM bkspc[] = {MO(_NAV), KC_SPC, COMBO_END};
const uint16_t PROGMEM esc[] = {KC_J, KC_M, COMBO_END};
const uint16_t PROGMEM tab[] = {KC_B, KC_G, COMBO_END};
const uint16_t PROGMEM tmux[] = {KC_ENT, MO(_SYM), COMBO_END};
const uint16_t PROGMEM fn_lyr[] = {KC_H, KC_DOT, COMBO_END};

combo_t key_combos[] = {
	[SHIFT_L] = COMBO(shift_l, KC_LSFT),
	[SHIFT_R] = COMBO(shift_r, KC_LSFT),
	[CTRL_L] = COMBO(ctrl_l, KC_LCTL),
	[CTRL_R] = COMBO(ctrl_r, KC_LCTL),
	[GUI_L] = COMBO(gui_l, KC_LGUI),
	[GUI_R] = COMBO(gui_r, KC_LGUI),
	[ALT_L] = COMBO(alt_l, KC_LALT),
	[ALT_R] = COMBO(alt_r, KC_LALT),
	[BKSPC] = COMBO(bkspc, KC_BSPC),
	[ESC] = COMBO(esc, KC_ESC),
	[TAB] = COMBO(tab, KC_TAB),
	[TMUX] = COMBO(tmux, C(KC_A)),
	[FN_LYR] = COMBO(fn_lyr, MO(_FN)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_CK] = LAYOUT(
            KC_Q,				KC_W,				KC_F,				KC_P,				KC_B,										KC_J,				KC_L,				KC_U,				KC_Y,				KC_SCLN,
            KC_A,				KC_R,				KC_S,				KC_T,				KC_G,										KC_M,				KC_N,				KC_E,				KC_I,				KC_O,
                                KC_X,				KC_C,				KC_D,										                                        KC_H,				KC_COMM,		    KC_DOT,
                                                                        MO(_NAV),		    KC_SPC,									    KC_ENT,			    MO(_SYM)
            ),

    [_NAV] = LAYOUT(
            KC_1,				KC_2,				KC_3,				KC_4,				KC_5,										KC_6,				KC_7,				KC_8,				KC_9,				KC_0,
            CW_TOGG,		    KC_Z,			    KC_NO,		        KC_V,			    KC_NO,									    KC_LEFT,		    KC_DOWN,		    KC_UP,			    KC_RIGHT,		    KC_NO,
                                S(KC_1),		    S(KC_3),		    S(KC_5),		                 										            S(KC_7),		    S(KC_8),		    KC_NO,
                                                                        KC_TRNS,		    KC_NO,									    KC_NO,			   KC_NO 
            ),

    [_SYM] = LAYOUT(
            S(KC_6),		    KC_LBRC,		    S(KC_2),		    KC_RBRC,		    KC_NUHS,								    KC_K,		        S(KC_EQL),	        KC_MINS,		    S(KC_MINS),	        S(KC_SLSH),
            S(KC_4),		    S(KC_9),		    KC_QUOT,		    S(KC_0),		    S(KC_NUBS),								      S(KC_NUHS),	        S(KC_COMM),	        KC_EQL,			    S(KC_DOT),	        S(KC_QUOT),
            		            S(KC_LBRC),	        KC_GRV,			    S(KC_RBRC),	        							                                    KC_NUBS,		    KC_NO,			KC_SLSH,
                                                                        C(KC_BSPC),	        KC_DEL,									    KC_NO,			    KC_TRNS
            ),

    [_FN] = LAYOUT(
            KC_F1,		    KC_F2,		    KC_F3,		    KC_F4,		    KC_F5,								    KC_NO,		        KC_NO,			KC_NO,		    KC_NO,	   S(KC_SLSH),
						KC_F6,		    KC_F7,		    KC_F8,		    KC_F9,		    KC_F10,								    KC_NO,						KC_NO,	    KC_NO,			  KC_NO,	   S(KC_QUOT),
            		          KC_F11,	      KC_F12,			  KC_F13,	        							                            KC_TRNS,		KC_NO,				KC_TRNS,
                                                      KC_NO,	      KC_NO,									  KC_NO,						KC_NO
            ),
};

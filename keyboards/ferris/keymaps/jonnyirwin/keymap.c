/*
 * Ferris/Sweep keymap — 34-key (LAYOUT_split_3x5_2).
 * Canonical ZMK layout: Colemak base, NAV/SYM/FN/SYS layers.
 */

#include QMK_KEYBOARD_H
#include "../../../common/keymap_common.h"

enum layer_names {
    _CK = 0,
    _NAV,
    _SYM,
    _FN,
    _SYS,
    _MK,
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
    SYS_LYR,
    FN_LYR,
    ESC,
    TAB,
    TMUX,
    MK_LYR,
};

const uint16_t PROGMEM shift_l[] = {KC_P,    KC_T,     COMBO_END};
const uint16_t PROGMEM shift_r[] = {KC_L,    KC_N,     COMBO_END};
const uint16_t PROGMEM ctrl_l[]  = {KC_F,    KC_S,     COMBO_END};
const uint16_t PROGMEM ctrl_r[]  = {KC_U,    KC_E,     COMBO_END};
const uint16_t PROGMEM gui_l[]   = {KC_W,    KC_R,     COMBO_END};
const uint16_t PROGMEM gui_r[]   = {KC_Y,    KC_I,     COMBO_END};
const uint16_t PROGMEM alt_l[]   = {KC_Q,    KC_A,     COMBO_END};
const uint16_t PROGMEM alt_r[]   = {KC_SCLN, KC_O,     COMBO_END};
const uint16_t PROGMEM bkspc[]   = {MO(_NAV),KC_SPC,   COMBO_END};
/* SYS: both thumb keys = LH1 + RH1 */
const uint16_t PROGMEM sys_lyr[] = {MO(_NAV),MO(_SYM), COMBO_END};
/* FN: K(inner right bottom) + /(outer right bottom) */
const uint16_t PROGMEM fn_lyr[]  = {KC_K,    KC_SLSH,  COMBO_END};
const uint16_t PROGMEM esc[]     = {KC_J,    KC_M,     COMBO_END};
const uint16_t PROGMEM tab[]     = {KC_B,    KC_G,     COMBO_END};
const uint16_t PROGMEM tmux[]    = {KC_ENT,  MO(_SYM), COMBO_END};
const uint16_t PROGMEM mk_lyr[]  = {KC_Z,    KC_SPC,   COMBO_END};

combo_t key_combos[] = {
    [SHIFT_L] = COMBO(shift_l, KC_LSFT),
    [SHIFT_R] = COMBO(shift_r, KC_LSFT),
    [CTRL_L]  = COMBO(ctrl_l,  KC_LCTL),
    [CTRL_R]  = COMBO(ctrl_r,  KC_LCTL),
    [GUI_L]   = COMBO(gui_l,   KC_LGUI),
    [GUI_R]   = COMBO(gui_r,   KC_LGUI),
    [ALT_L]   = COMBO(alt_l,   KC_LALT),
    [ALT_R]   = COMBO(alt_r,   KC_LALT),
    [BKSPC]   = COMBO(bkspc,   KC_BSPC),
    [SYS_LYR] = COMBO(sys_lyr, MO(_SYS)),
    [FN_LYR]  = COMBO(fn_lyr,  MO(_FN)),
    [ESC]     = COMBO(esc,     KC_ESC),
    [TAB]     = COMBO(tab,     KC_TAB),
    [TMUX]    = COMBO(tmux,    C(KC_A)),
    [MK_LYR]  = COMBO(mk_lyr,  MO(_MK)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_CK]  = LAYOUT_split_3x5_2(LAYER_CK_3x5_2),
    [_NAV] = LAYOUT_split_3x5_2(LAYER_NAV_3x5_2),
    [_SYM] = LAYOUT_split_3x5_2(LAYER_SYM_3x5_2),
    [_FN]  = LAYOUT_split_3x5_2(LAYER_FN_3x5_2),
    [_SYS] = LAYOUT_split_3x5_2(LAYER_SYS_3x5_2),

    [_MK] = LAYOUT_split_3x5_2(
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_WH_U, KC_NO,   KC_NO,   KC_ACL2,
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_ACL1,
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_WH_D, KC_NO,   KC_NO,   KC_ACL0,
                              KC_TRNS,  KC_TRNS,   KC_MS_BTN1, KC_MS_BTN2
    ),
};

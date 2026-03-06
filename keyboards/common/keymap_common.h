/*
 * Shared QMK layer content — canonical layout matching ZMK Berylline/Cradio.
 *
 * UK ISO keycodes used throughout (NON_US_HASH, NON_US_BSLH, etc.).
 *
 * Include this header in each board's keymap.c, then use the appropriate
 * LAYER_*_3x5_2 / LAYER_*_3x5_3 / LAYER_*_3x6_3 variant.
 *
 * ZMK → QMK keycode mapping (UK layout):
 *   NON_US_HASH   → KC_NUHS       (#)
 *   NON_US_BSLH   → KC_NUBS       (\)
 *   LS(NON_US_BSLH) → S(KC_NUBS) (|)
 *   LS(NON_US_HASH) → S(KC_NUHS) (~)
 *   LBKT          → KC_LBRC       ([)
 *   RBKT          → KC_RBRC       (])
 *   PLUS          → S(KC_EQL)     (+)
 *   MINUS         → KC_MINS       (-)
 *   UNDER         → S(KC_MINS)    (_)
 *   QMARK         → S(KC_SLSH)    (?)
 *   LPAR          → S(KC_9)       ( ( )
 *   RPAR          → S(KC_0)       ( ) )
 *   SQT           → KC_QUOT       (')
 *   LS(SQT)       → S(KC_2)       (") UK shift-2
 *   LBRC          → S(KC_LBRC)    ({)
 *   RBRC          → S(KC_RBRC)    (})
 *   GRAVE         → KC_GRV        (`)
 *   LT            → S(KC_COMM)    (<)
 *   GT            → S(KC_DOT)     (>)
 *   EQUAL         → KC_EQL        (=)
 *   SLASH         → KC_SLSH       (/)
 *   caps_word     → CW_TOGG
 */

#pragma once

/* Wrapper macros: the C preprocessor counts arguments before expanding inner
 * macros, so LAYOUT_xxx(LAYER_MACRO) is seen as 1 arg.  These variadic
 * wrappers force expansion first. */
#define LAYOUT_split_3x5_2_wrapper(...) LAYOUT_split_3x5_2(__VA_ARGS__)
#define LAYOUT_split_3x5_3_wrapper(...) LAYOUT_split_3x5_3(__VA_ARGS__)
#define LAYOUT_split_3x6_3_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)

/* ────────────────────────────────────────────────────────────────────────────
 * 3×5+2 thumb layout  (34-key: Ferris/Sweep)
 * ──────────────────────────────────────────────────────────────────────────── */

#define LAYER_CK_3x5_2 \
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, \
    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,      KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    \
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,      KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, \
                            MO(_NAV), KC_SPC,    KC_ENT,  MO(_SYM)

#define LAYER_NAV_3x5_2 \
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    \
    CW_TOGG, KC_Z,    C(KC_C), KC_V,    C(KC_V),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, G(C(KC_RGHT)), \
    KC_NO,   S(KC_1), S(KC_3), S(KC_5), KC_NO,     KC_NO,   S(KC_7), S(KC_8), G(C(KC_LEFT)), KC_NO, \
                            KC_TRNS,  KC_NO,     KC_NO,   KC_NO

#define LAYER_SYM_3x5_2 \
    S(KC_6), KC_LBRC, S(KC_2), KC_RBRC, KC_NUHS,   KC_K,    S(KC_EQL),KC_MINS,S(KC_MINS),S(KC_SLSH), \
    S(KC_4), S(KC_9), KC_QUOT, S(KC_0), S(KC_NUBS), S(KC_NUHS),S(KC_COMM),KC_EQL,S(KC_DOT),S(KC_2), \
    KC_NO,   S(KC_LBRC),KC_GRV,S(KC_RBRC),KC_NO,   KC_NO,   KC_NUBS, KC_NO,   KC_SLSH, KC_NO,  \
                         C(KC_BSPC), KC_DEL,    KC_NO,   KC_TRNS

#define LAYER_FN_3x5_2 \
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  \
    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  \
    KC_NO,   KC_F11,  KC_F12,  KC_F13,  KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  \
                            KC_NO,    KC_NO,     KC_NO,   KC_NO

#define LAYER_SYS_3x5_2 \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  \
    QK_REBOOT,QK_BOOT,KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   QK_BOOT, QK_REBOOT, \
                            KC_TRNS,  KC_NO,     KC_NO,   KC_TRNS

/* ────────────────────────────────────────────────────────────────────────────
 * 3×5+3 thumb layout  (36-key: Cheapino v2 / GoGoCorne)
 * ──────────────────────────────────────────────────────────────────────────── */

#define LAYER_CK_3x5_3 \
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, \
    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,      KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    \
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,      KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, \
                  KC_BSPC, MO(_NAV), KC_SPC,    KC_ENT,  MO(_SYM), C(KC_A)

#define LAYER_NAV_3x5_3 \
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    \
    CW_TOGG, KC_Z,    C(KC_C), KC_V,    C(KC_V),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, G(C(KC_RGHT)), \
    KC_NO,   S(KC_1), S(KC_3), S(KC_5), KC_NO,     KC_NO,   S(KC_7), S(KC_8), G(C(KC_LEFT)), KC_NO, \
                  KC_NO,   KC_TRNS,  KC_NO,     KC_NO,   KC_NO,   KC_NO

#define LAYER_SYM_3x5_3 \
    S(KC_6), KC_LBRC, S(KC_2), KC_RBRC, KC_NUHS,   KC_K,    S(KC_EQL),KC_MINS,S(KC_MINS),S(KC_SLSH), \
    S(KC_4), S(KC_9), KC_QUOT, S(KC_0), S(KC_NUBS), S(KC_NUHS),S(KC_COMM),KC_EQL,S(KC_DOT),S(KC_2), \
    KC_NO,   S(KC_LBRC),KC_GRV,S(KC_RBRC),KC_NO,   KC_NO,   KC_NUBS, KC_NO,   KC_SLSH, KC_NO,  \
                  KC_NO, C(KC_BSPC), KC_DEL,    KC_NO,   KC_TRNS, KC_NO

#define LAYER_FN_3x5_3 \
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  \
    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  \
    KC_NO,   KC_F11,  KC_F12,  KC_F13,  KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  \
                  KC_NO,   KC_NO,    KC_NO,     KC_NO,   KC_NO,   KC_NO

#define LAYER_SYS_3x5_3 \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  \
    QK_REBOOT,QK_BOOT,KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   QK_BOOT, QK_REBOOT, \
                  KC_TRNS, KC_NO,    KC_NO,     KC_NO,   KC_NO,   KC_TRNS

/* ────────────────────────────────────────────────────────────────────────────
 * 3×6+3 thumb layout  (42-key: CRKBD)
 * Outer column (col 0 left / col 5 right): ESC/TAB on left, BSPC/ENT on right.
 * ──────────────────────────────────────────────────────────────────────────── */

#define LAYER_CK_3x6_3 \
    KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
    KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,      KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,  \
    CW_TOGG, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,      KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, C(KC_A), \
                           KC_BSPC, MO(_NAV), KC_SPC,    KC_ENT,  MO(_SYM), MO(_FN)

#define LAYER_NAV_3x6_3 \
    KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS, \
    KC_TRNS, CW_TOGG, KC_Z,    C(KC_C), KC_V,    C(KC_V),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, G(C(KC_RGHT)),KC_TRNS, \
    KC_TRNS, KC_NO,   S(KC_1), S(KC_3), S(KC_5), KC_NO,     KC_NO,   S(KC_7), S(KC_8), G(C(KC_LEFT)),KC_NO,KC_TRNS, \
                           KC_NO,   KC_TRNS,  KC_NO,     KC_NO,   KC_NO,   KC_NO

#define LAYER_SYM_3x6_3 \
    KC_TRNS, S(KC_6), KC_LBRC, S(KC_2), KC_RBRC, KC_NUHS,   KC_K,    S(KC_EQL),KC_MINS,S(KC_MINS),S(KC_SLSH),KC_TRNS, \
    KC_TRNS, S(KC_4), S(KC_9), KC_QUOT, S(KC_0), S(KC_NUBS), S(KC_NUHS),S(KC_COMM),KC_EQL,S(KC_DOT),S(KC_2),KC_TRNS, \
    KC_TRNS, KC_NO,   S(KC_LBRC),KC_GRV,S(KC_RBRC),KC_NO,  KC_NO,   KC_NUBS, KC_NO,   KC_SLSH, KC_NO,  KC_TRNS, \
                        KC_NO, C(KC_BSPC), KC_DEL,    KC_NO,   KC_TRNS, KC_NO

#define LAYER_FN_3x6_3 \
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_TRNS, \
    KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_TRNS, \
    KC_TRNS, KC_NO,   KC_F11,  KC_F12,  KC_F13,  KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_TRNS, \
                           KC_NO,   KC_TRNS,  KC_NO,     KC_NO,   KC_TRNS, KC_NO

#define LAYER_SYS_3x6_3 \
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_TRNS, \
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_TRNS, \
    KC_TRNS, QK_REBOOT,QK_BOOT,KC_NO,  KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   QK_BOOT, QK_REBOOT,KC_TRNS, \
                           KC_TRNS, KC_NO,    KC_NO,     KC_NO,   KC_NO,   KC_TRNS

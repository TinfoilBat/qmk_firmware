#include "dactyl-manuform.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _MOVE   2
#define _SYM    3
#define _FN     4

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = KEYMAP_5x6(
  // left hand
   KC_ESC,    KC_1,    KC_2,    KC_3,   KC_4,   KC_5, 
   KC_GRV,    KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,
   KC_TAB,    KC_A,    KC_S,    KC_D,   KC_F,   KC_G,
   KC_LSHIFT, SFT_T(KC_Z),    KC_X,    KC_C,   KC_V,   KC_B,
            KC_LEFT, KC_RIGHT, 
                               LT(_SYM, KC_BSPC), SFT_T(KC_DEL), 
                               KC_LPRN, CTL_T(KC_ESC), 
                               KC_LCBR, LT(_FN, KC_BSLS),
        // right hand
                     KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS,
                     KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_EQL,
                     KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, 
                     KC_N,    KC_M,   KC_COMM, KC_DOT,  SFT_T(KC_SLSH), KC_RSHIFT,
                                       KC_UP, KC_DOWN,
        ALT_T(KC_ENT), LT(_SYM, KC_SPC), 
        GUI_T(KC_SCLN), KC_RPRN,
        LT(_MOVE, KC_TAB), KC_RCBR),
[_COLEMAK] = KEYMAP_5x6(
  // left hand
   _______,  _______,  _______,  _______,  _______, _______,
   _______,   KC_Q,    KC_W,   KC_F, KC_P,  KC_G,
   _______,   KC_A,    KC_R,   KC_S, KC_T,  KC_D,
   _______,   SFT_T(KC_Z),    KC_X,   KC_C, KC_V,  KC_B,
            KC_LEFT, KC_RIGHT, 
                               LT(_SYM, KC_BSPC), SFT_T(KC_DEL), 
                               KC_LPRN, CTL_T(KC_ESC), 
                               KC_LCBR, LT(_FN, KC_BSLS),
        // right hand
                  _______,  _______,  _______,  _______,  _______,  _______,
                     KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, _______,
                     KC_H,    KC_N,    KC_E,    KC_I,    KC_O, _______,
					 KC_K,    KC_M,    KC_COMM, KC_DOT,  SFT_T(KC_SLSH), _______,
                                       KC_UP, KC_DOWN,
        ALT_T(KC_ENT), LT(_SYM, KC_SPC), 
        GUI_T(KC_SCLN), KC_RPRN,
        LT(_MOVE, KC_TAB), KC_RCBR),
[_SYM] = KEYMAP_5x6(
  // left hand
  _______, _______, _______, _______, _______, _______,
  _______,  KC_PIPE, KC_EXLM, KC_LCBR, KC_RCBR, KC_AT,
  _______,  KC_AMPR, KC_HASH, KC_LPRN, KC_RPRN, KC_DLR,
  _______,  KC_SCLN, KC_PERC, KC_LBRC, KC_RBRC, KC_BSLS,
            KC_GRV,  KC_TAB, 
                               LT(_SYM, KC_BSPC), SFT_T(KC_DEL), 
                               LT(_MOVE, KC_SPC), CTL_T(KC_ESC),
                               KC_BTN1, LT(_FN, KC_TAB),
        // right hand
        _______, _______, _______, _______, _______,_______,
                     KC_PLUS, KC_7, KC_8, KC_9, KC_CIRC,_______,
                     KC_EQL,  KC_4, KC_5, KC_6, KC_ASTR,_______,
                     KC_MINS, KC_1, KC_2, KC_3, KC_SLSH,_______,
                                    KC_0, KC_DOT,
        LT(_MOVE, KC_ENT), LT(_SYM, KC_SPC), 
        CTL_T(KC_PGUP), GUI_T(KC_PGDN),
        KC_LALT, KC_DQT),
[_MOVE] = KEYMAP_5x6(
  // left hand
  // TODO modify move layer to resemble Dreymar's extend layer
  _______, _______, _______, _______, _______, _______,
  _______, RESET,   KC_WH_U, KC_MS_U, KC_WH_D,  KC_WH_U,
  _______, KC_BTN3, KC_MS_L, KC_MS_D, KC_MS_R,  KC_LGUI,
  _______, KC_BTN1, KC_BTN5, KC_BTN2, KC_BTN3,  KC_WH_D,
            KC_GRV,  KC_TAB, 
                               LT(_SYM, KC_BSPC), SFT_T(KC_DEL), 
                               LT(_MOVE, KC_SPC), CTL_T(KC_ESC),
                               KC_BTN1, LT(_FN, KC_TAB),
        // right hand
                    _______, _______, _______, _______, _______, _______,
                     KC_PGUP, KC_HOME, KC_UP,  KC_END, TO(_QWERTY), _______,
                     KC_PGDN, KC_LEFT, KC_DOWN,   KC_RIGHT, TO(_COLEMAK), _______,
                     KC_CAPS, _______,  _______,  LALT(KC_TAB),  RESET, _______,
                                       KC_MINS, KC_SCLN,
        LT(_MOVE, KC_ENT), LT(_SYM, KC_SPC),
        CTL_T(KC_PGUP), GUI_T(KC_PGDN),
        KC_LALT, KC_DQT),
[_FN] = KEYMAP_5x6(
  // left hand
  _______, _______, _______, _______, _______, _______,
   _______, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_WH_U,
   _______, KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_LGUI,
   _______, KC_F9, KC_F10,  KC_F11, KC_F12, KC_WH_D,
            KC_GRV,  KC_TAB, 
                               LT(_SYM, KC_BSPC), SFT_T(KC_DEL),
                               LT(_MOVE, KC_SPC), CTL_T(KC_ESC),
                               KC_BTN1, LT(_FN, KC_TAB),
        // right hand
                    _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______,
                     KC_CALC, KC_MAIL, KC_MYCM, KC_WHOM, _______, _______,
                     _______, _______, _______, _______, _______, _______,
                                       KC_MINS, KC_SCLN,
        LT(_MOVE, KC_ENT), LT(_SYM, KC_SPC),
        CTL_T(KC_PGUP), GUI_T(KC_PGDN),
        KC_LALT, KC_DQT),
};



void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

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
#include <stdio.h>
#include "keymap_german.h"

#define DEF 0 // Default layer
#define SYM 1 // Symbols and navigation
#define NUM 2 // numbers and function keys
#define MSC 3 // mouse and media
#define RGB 4 // mouse and media

#define WD_LEFT LCTL(KC_LEFT)
#define WD_RGHT LCTL(KC_RGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DEF] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,                         DE_Z,    DE_U,    DE_I,    DE_O,   DE_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,    DE_A,    DE_S,    DE_D,    DE_F,    DE_G,                         DE_H,    DE_J,    DE_K,    DE_L, DE_HASH, DE_PIPE, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,                         DE_N,    DE_M, DE_COMM,  DE_DOT, DE_MINS,  KC_ESC, 
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_ENT,  MO(SYM), KC_LSFT,     KC_SPC, MO(NUM), KC_LGUI
                                      //`--------------------------'  `--------------------------'

  ),

  [SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      MO(NUM),  KC_INS, KC_PGUP,   KC_UP, KC_PGDN, KC_PAUS,                      DE_EXLM, DE_QUES, DE_AMPR, DE_CIRC, DE_PERC, DE_TILD,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END,                      DE_QUOT, DE_LPRN, DE_RPRN, DE_LBRC, DE_RBRC, DE_DQUO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, DE_ADIA, DE_ODIA, DE_UDIA,   DE_SS, KC_PSCR,                      DE_LABK, DE_LCBR, DE_RCBR, DE_SLSH, DE_BSLS, DE_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    KC_RSFT, MO(MSC), _______
                                      //`--------------------------'  `--------------------------'
  ),

  [NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,  DE_DLR,                      DE_PLUS,    DE_7,    DE_8,    DE_9, DE_ASTR, _______, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, DE_EURO,                      DE_MINS,    DE_4,    DE_5,    DE_6, DE_SLSH,  DE_EQL, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_F9,  KC_F10,  KC_F11,  KC_F12,   DE_AT,                         DE_0,    DE_1,    DE_2,    DE_3,  DE_DOT,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, MO(MSC), _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [MSC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET, MO(RGB), KC_WH_U, KC_MS_U, KC_WH_D, XXXXXXX,                      XXXXXXX, KC_BTN2, XXXXXXX, KC_VOLU, KC_MPLY,  KC_DEL, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, WD_LEFT, KC_MS_L, KC_MS_D, KC_MS_R, WD_RGHT,                      KC_ACL0, KC_BTN1, XXXXXXX, KC_VOLD, KC_MPRV, XXXXXXX, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, DE_SUP2, DE_SUP3, DE_MICR,                      DE_SECT, KC_BTN3, XXXXXXX, KC_MUTE, KC_MNXT, XXXXXXX,  
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, XXXXXXX,    XXXXXXX, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [RGB] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, XXXXXXX, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, XXXXXXX, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     RGB_RMOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, XXXXXXX,    XXXXXXX, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  } else {
    return OLED_ROTATION_0;
  }
  return rotation;
}

#ifndef ANIM_FRAME_TIME
  #define ANIM_FRAME_TIME 50
#endif

 static const char mb_logo[] = {
    // 'corne_5a', 128x32px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 
    0x80, 0x80, 0x00, 0x00, 0x80, 0xc0, 0xf0, 0xf8, 0xf8, 0xfc, 0xfc, 0xfc, 0xfe, 0xfc, 0xfc, 0xfc, 
    0xf8, 0xf8, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0x00, 0xc0, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0x03, 0xf0, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0x3f, 0x0f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf8, 0xfc, 0xfe, 0x3e, 0x1f, 0x0f, 0x0f, 
    0x0f, 0x0f, 0x0f, 0x3e, 0x7e, 0x7c, 0x7c, 0x70, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xfc, 0xfe, 0x3e, 
    0x1f, 0x0f, 0x0f, 0x0f, 0x0f, 0x1f, 0x1e, 0x7e, 0xfc, 0xfc, 0xf8, 0xe0, 0x00, 0x00, 0x00, 0xff, 
    0xff, 0xff, 0xff, 0x7c, 0x1e, 0x1e, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x7c, 
    0x1e, 0x0f, 0x0f, 0x0f, 0x0f, 0x1f, 0x3f, 0xfe, 0xfe, 0xfc, 0xf0, 0x00, 0x00, 0x00, 0xe0, 0xf0, 
    0xfc, 0xfc, 0xfe, 0x9e, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x9f, 0xbe, 0xfe, 0xfc, 0xf8, 0xf0, 0x00, 
    0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0x03, 0x00, 
    0x00, 0x00, 0x00, 0xc0, 0xe0, 0x00, 0x00, 0x07, 0x3f, 0xff, 0xff, 0xff, 0xf0, 0xc0, 0xc0, 0x80, 
    0x80, 0xc0, 0xc0, 0xe0, 0xf0, 0xf0, 0xf0, 0x70, 0x00, 0x00, 0x0f, 0x7f, 0xff, 0xff, 0xfd, 0xe0, 
    0xc0, 0xc0, 0x80, 0x80, 0xc0, 0xc0, 0xe0, 0xf8, 0xff, 0xff, 0x7f, 0x1f, 0x00, 0x00, 0x00, 0xff, 
    0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x1f, 0x7f, 
    0xff, 0xff, 0xff, 0xe7, 0xc7, 0xc7, 0x87, 0x87, 0xc7, 0xc7, 0xe7, 0xf7, 0xf7, 0xf7, 0x37, 0x03, 
    0x00, 0x00, 0x03, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x0f, 0x1f, 0x3f, 0x3f, 0x3f, 
    0x3f, 0x3f, 0x3f, 0x3f, 0x1f, 0x1f, 0x1f, 0x3f, 0x3f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7e, 0x7e, 
    0x7e, 0x3e, 0x3f, 0x1f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 
    0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 
    0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
    0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00
};

void oled_render_logo(void) {
    static uint32_t anim_timer = 0;
    if (timer_elapsed32(anim_timer) > ANIM_FRAME_TIME) {
        oled_set_cursor(0, 0);
        anim_timer = timer_read32();
        union {
            uint16_t u16;
            uint8_t u8Arr[2];
        } random_val;
        for(int offset = 0; offset < OLED_MATRIX_SIZE; offset++) {
            if (offset % 2 == 0) {
                random_val.u16 = rand();
            }
            oled_write_raw_byte(random_val.u8Arr[offset % 2] & mb_logo[offset], offset);
        }
    }
}

bool oled_task_user(void) {
    oled_render_logo();
    return false;
}

#endif // OLED_ENABLE

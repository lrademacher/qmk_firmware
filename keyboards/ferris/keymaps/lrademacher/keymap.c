#include QMK_KEYBOARD_H
#include "keymap_german.h"

#define LETTERS 0
#define SYMBOLS 1
#define NAV_HOT 2
#define NUM_MSE 3
#define GAMING  4

enum my_keycodes {
  /* Layer mod-tab */
  KC_LCTL_L1 = SAFE_RANGE,
  KC_LCTL_L2,
  KC_LALT_L2,
  KC_LALT_L3,
  KC_LONG_L5,
  KC_LONG_RESET,

  /* Umlaute */
  KC_A_AE,
  KC_O_OE,
  KC_U_UE,
  KC_S_SS,

  /* Alternative symbols */
  KC_COMM_QUES,
  KC_DOT_EXLM,
  KC_ASTR_SLSH,
  KC_PLUS_MINS,
  KC_DOT_COMM,
  KC_0_EQL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LETTERS] = LAYOUT(
  //-----------------------------------------------          -------------------------------------------------
      DE_Q,     DE_W,     DE_E,     DE_R,     DE_T,          DE_Z,     KC_U_UE,  DE_I,     KC_O_OE,  DE_P,
  //-----------------------------------------------          -------------------------------------------------
      KC_A_AE,  KC_S_SS,  DE_D,     DE_F,     DE_G,          DE_H,     DE_J,     DE_K,     DE_L,     KC_BSPC,
  //-----------------------------------------------          -------------------------------------------------
      DE_Y,     DE_X,     DE_C,     DE_V,     DE_B,          DE_N,     DE_M,     KC_COMM_QUES, KC_DOT_EXLM, KC_ENT,
  //-----------------------------------------------          -------------------------------------------------
                KC_LCTL_L2, MT(MOD_LGUI, KC_SPACE),          KC_LSFT,  KC_LALT_L3
  //-----------------------------------------------          -------------------------------------------------
  ),

  [SYMBOLS] = LAYOUT(
  //--------------------------------------------------       -------------------------------------------------
    KC_ESC,     DE_AT,    DE_HASH,  KC_DLR,   DE_PERC,       DE_CIRC,  DE_AMPR,  DE_ASTR,  DE_MINS,  KC_LONG_L5,
  //--------------------------------------------------       -------------------------------------------------
    KC_TAB,     DE_EQL,   DE_TILD,  DE_QUOT,  DE_SLSH,       DE_BSLS,  DE_LCBR,  DE_RCBR,  KC_PIPE,  KC_BSPC,
  //--------------------------------------------------       -------------------------------------------------
    TO(NUM_MSE),DE_EURO,  DE_LABK,  DE_RABK,  DE_DQUO,       DE_LBRC,  DE_LPRN,  DE_RPRN,  DE_RBRC,  KC_ENT,
  //--------------------------------------------------       -------------------------------------------------
                   KC_LCTL_L1, MT(MOD_LGUI, KC_SPACE),       KC_LSFT,  KC_LALT_L3 
  //--------------------------------------------------       -------------------------------------------------
  ),

  [NAV_HOT] = LAYOUT(
  //--------------------------------------------------       -------------------------------------------------
    KC_ESC,     KC_F1,    KC_F2,    KC_F3,    KC_F4,         KC_PAUSE, KC_PGUP,  KC_UP,    KC_PGDN,  KC_LONG_RESET,
  //--------------------------------------------------       -------------------------------------------------
    KC_TAB,     KC_F5,    KC_F6,    KC_F7,    KC_F8,         KC_PSCR,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_BSPC,
  //--------------------------------------------------       -------------------------------------------------
    TO(NUM_MSE),KC_F9,    KC_F10,   KC_F11,   KC_F12,        KC_DEL,   KC_HOME,  KC_INS,   KC_END,   KC_ENT,
  //--------------------------------------------------       -------------------------------------------------
                   KC_LCTL_L1, MT(MOD_LGUI, KC_SPACE),       KC_LSFT,  KC_LALT_L2
  ),

  [NUM_MSE] = LAYOUT(
  //--------------------------------------------------       -----------------------------------------------------
    KC_ESC,     KC_BTN2,  KC_MS_U,  KC_BTN1,  KC_VOLU,       KC_ASTR_SLSH, KC_7, KC_8,     KC_9,     KC_PLUS_MINS,
  //--------------------------------------------------       -----------------------------------------------------
    KC_TAB,     KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_VOLD,       KC_DOT_COMM, KC_4,  KC_5,     KC_6,     KC_BSPC,
  //--------------------------------------------------       -----------------------------------------------------
    TO(NAV_HOT),KC_WH_D,  KC_BTN3,  KC_WH_U,  KC_MUTE,       KC_0_EQL, KC_1,     KC_2,     KC_3,     KC_ENT,
  //--------------------------------------------------       -----------------------------------------------------
                   KC_LCTL_L1, MT(MOD_LGUI, KC_SPACE),       KC_LSFT,  KC_LALT_L2 
  //--------------------------------------------------       -----------------------------------------------------
  ),

  [GAMING] = LAYOUT(
  //--------------------------------------------------       ----------------------------------------------------
      KC_ESCAPE, DE_Q,    DE_W,     DE_E,     DE_R,          KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,
  //--------------------------------------------------       ----------------------------------------------------
      KC_LSFT,  DE_A,     DE_S,     DE_D,     DE_F,          DE_1,      DE_2,     DE_3,     DE_4,     DE_5, 
  //--------------------------------------------------       ----------------------------------------------------
      KC_LCTL,  DE_Y,     DE_X,     DE_C,     DE_V,          KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,
  //--------------------------------------------------       ----------------------------------------------------
	                                  KC_LALT,  KC_SPACE,      KC_NO, TO(LETTERS)
  //--------------------------------------------------       ----------------------------------------------------
  )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t fnx_layer_timer;
  static bool a_pressed = false, o_pressed = false, u_pressed = false, s_pressed = false;;

  switch (keycode) {
    /* Layer mod-tab */
    case KC_LCTL_L1:
      if (record->event.pressed) {
        fnx_layer_timer = timer_read();
        register_mods(MOD_BIT(KC_LCTL));
      } else {
        unregister_mods(MOD_BIT(KC_LCTL));
        
        if (timer_elapsed(fnx_layer_timer) < TAPPING_TERM)
	        layer_move(LETTERS);
      }
      return false; // Skip all further processing of this key
    
    case KC_LCTL_L2:
      if (record->event.pressed) {
        fnx_layer_timer = timer_read();
        register_mods(MOD_BIT(KC_LCTL));
      } else {
        unregister_mods(MOD_BIT(KC_LCTL));
        
        if (timer_elapsed(fnx_layer_timer) < TAPPING_TERM)
	        layer_move(SYMBOLS);
      }
      return false; // Skip all further processing of this key

    case KC_LALT_L2:
      if (record->event.pressed) {
        fnx_layer_timer = timer_read();
		    register_mods(MOD_BIT(KC_LALT));
      } else {
        unregister_mods(MOD_BIT(KC_LALT));

		    if (timer_elapsed(fnx_layer_timer) < TAPPING_TERM)
		      layer_move(SYMBOLS);
      }
      return false; // Skip all further processing of this key

    case KC_LALT_L3:
      if (record->event.pressed) {
        fnx_layer_timer = timer_read();
		    register_mods(MOD_BIT(KC_LALT));
      } else {
        unregister_mods(MOD_BIT(KC_LALT));

		    if (timer_elapsed(fnx_layer_timer) < TAPPING_TERM)
		      layer_move(NAV_HOT);
      }
      return false; // Skip all further processing of this key
   
    case KC_LONG_RESET:
      if (record->event.pressed) {
        fnx_layer_timer = timer_read();
      } else {

		    if (timer_elapsed(fnx_layer_timer) > TAPPING_TERM)
		      reset_keyboard();
      }
      return false; // Skip all further processing of this key


    case KC_LONG_L5:
      if (record->event.pressed) {
        fnx_layer_timer = timer_read();
      } else {

		    if (timer_elapsed(fnx_layer_timer) > TAPPING_TERM)
		      layer_move(GAMING);
      }
      return false; // Skip all further processing of this key

    /* UMLAUTE */    
    case KC_A_AE:
      if (record->event.pressed) {
        fnx_layer_timer = timer_read();
        a_pressed = true;
      } else {
        if (a_pressed) {
		      if (timer_elapsed(fnx_layer_timer) < TAPPING_TERM)
		        tap_code(DE_A);
          else
            tap_code(DE_ADIA);
          a_pressed = false;
        }
      }
      return false; // Skip all further processing of this 

    case KC_O_OE:
      if (record->event.pressed) {
        fnx_layer_timer = timer_read();
        o_pressed = true;
      } else {
        if (o_pressed) {
  		    if (timer_elapsed(fnx_layer_timer) < TAPPING_TERM)
	  	      tap_code(DE_O);
          else
            tap_code(DE_ODIA);
          o_pressed = false;
        }
      }
      return false; // Skip all further processing of this 

    case KC_U_UE:
      if (record->event.pressed) {
        fnx_layer_timer = timer_read();
        u_pressed = true;
      } else {
        if (u_pressed) {
  		    if (timer_elapsed(fnx_layer_timer) < TAPPING_TERM)
	  	      tap_code(DE_U);
          else
            tap_code(DE_UDIA);
          u_pressed = false;
        }
      }
      return false; // Skip all further processing of this 

    case KC_S_SS:
      if (record->event.pressed) {
        fnx_layer_timer = timer_read();
        s_pressed = true;
      } else {
        if (s_pressed) {
  		    if (timer_elapsed(fnx_layer_timer) < TAPPING_TERM)
	  	      tap_code(DE_S);
          else
            tap_code(DE_SS);
          s_pressed = false;
        }
      }
      return false; // Skip all further processing of this 

    /* Alternative symbols */
    case KC_COMM_QUES:
      if (record->event.pressed) {
        fnx_layer_timer = timer_read();
      } else {
		    if (timer_elapsed(fnx_layer_timer) < TAPPING_TERM)
		      tap_code(DE_COMM);
        else
          tap_code16(DE_QUES);
      }
      return false; // Skip all further processing of this 

    case KC_DOT_EXLM:
      if (record->event.pressed) {
        fnx_layer_timer = timer_read();
      } else {
		    if (timer_elapsed(fnx_layer_timer) < TAPPING_TERM)
		      tap_code(DE_DOT);
        else
          tap_code16(DE_EXLM);
      }
      return false; // Skip all further processing of this 

    case KC_ASTR_SLSH:
      if (record->event.pressed) {
        fnx_layer_timer = timer_read();
      } else {
		    if (timer_elapsed(fnx_layer_timer) < TAPPING_TERM)
		      tap_code16(DE_ASTR);
        else
          tap_code16(DE_SLSH);
      }
      return false; // Skip all further processing of this 

    case KC_PLUS_MINS:
      if (record->event.pressed) {
        fnx_layer_timer = timer_read();
      } else {
		    if (timer_elapsed(fnx_layer_timer) < TAPPING_TERM)
		      tap_code(DE_PLUS);
        else
          tap_code(DE_MINS);
      }
      return false; // Skip all further processing of this 

    case KC_DOT_COMM:
      if (record->event.pressed) {
        fnx_layer_timer = timer_read();
      } else {
		    if (timer_elapsed(fnx_layer_timer) < TAPPING_TERM)
		      tap_code(DE_DOT);
        else
          tap_code(DE_COMM);
      }
      return false; // Skip all further processing of this 

    case KC_0_EQL:
      if (record->event.pressed) {
        fnx_layer_timer = timer_read();
      } else {
		    if (timer_elapsed(fnx_layer_timer) < TAPPING_TERM)
		      tap_code(DE_0);
        else
          tap_code16(DE_EQL);
      }
      return false; // Skip all further processing of this 

    default:
      if (a_pressed) {
        tap_code(DE_A);
        a_pressed = false;
      }
      if (o_pressed) {
        tap_code(DE_O);
        o_pressed = false;
      }
      if (u_pressed) {
        tap_code(DE_U);
        u_pressed = false;
      }
      if (s_pressed) {
        tap_code(DE_S);
        s_pressed = false;
     }
      return true; // Process all other keycodes normally
  }
}


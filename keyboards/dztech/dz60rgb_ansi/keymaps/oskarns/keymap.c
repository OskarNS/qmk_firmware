// qmk compile -kb dztech/dz60rgb_ansi/v2_1 -km oskarns

#include <stdbool.h>
#include <stdint.h>
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_60_ansi(
        QK_GRAVE_ESCAPE,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        MO(2), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,                 KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
        KC_LCTL,        KC_LGUI, KC_LALT,                            KC_SPC,                             KC_APPLICATION, KC_RGUI,   MO(3),   MO(2)
    ),
    [1] = LAYOUT_60_ansi(
        _______, _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F15, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F13, KC_F14,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,                            _______,                              KC_RALT, _______, _______, _______
    ),
    [2] = LAYOUT_60_ansi(
        KC_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, KC_MPLY, KC_UP,   _______, KC_PGUP, _______, _______, _______, KC_UP,  _______, RALT(KC_PSCR), KC_F15, KC_HOME, KC_END,
        KC_CAPS,    KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_F13,  KC_F14,          _______,
        _______,          KC_VOLD, KC_VOLU, KC_GRV, _______, _______, _______, HYPR(KC_W), _______, _______,  _______,          _______,
        _______, _______, _______,                            KC_SPC,                              KC_RALT, _______, _______, _______
    ),
    [3] = LAYOUT_60_ansi(
        QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, RGB_TOG, _______, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_MOD, _______, _______, KC_MPRV, KC_MNXT,
        _______, _______, _______, _______, _______, _______, _______, _______, RGB_SPI, RGB_SPD, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, NK_ON,   NK_OFF, _______, _______, _______,          _______,
        _______, _______, _______,                            TG(1),                            _______, _______, _______, _______
    )
};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     bool returnVal = true;
//     switch (keycode) {
//         case UUMLAUT:
//         case EACUTE: {
//             if (record->event.pressed) {
//                 bool flip = false;
//                 if(!bnumlock) {
//                     tap_code(KC_NUM_LOCK);
//                     bnumlock = true;
//                     flip = true;
//                 }
//                 bool lshift = (bool)(get_mods() & (MOD_BIT(KC_LSFT)));
//                 bool rshift = (bool)(get_mods() & (MOD_BIT(KC_RSFT)));
//                 bool shift = lshift || rshift;

//                 if (lshift) unregister_code(KC_LSFT);
//                 if (rshift) unregister_code(KC_RSFT);

//                 // Inline Alt code logic
//                 if (keycode == EACUTE) {
//                     if (shift ^ bcapslock) {
//                         send_string(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_4))); // É
//                     } else {
//                         send_string(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_3) SS_TAP(X_KP_0))); // é
//                     }
//                 } else if (keycode == UUMLAUT) {
//                     if (shift ^ bcapslock) {
//                         send_string(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_4))); // Ü
//                     } else {
//                         send_string(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_2) SS_TAP(X_KP_9))); // ü
//                     }
//                 }

//                 if (lshift) register_code(KC_LSFT);
//                 if (rshift) register_code(KC_RSFT);
//                 if(flip) {
//                     tap_code(KC_NUM_LOCK);
//                     bnumlock = !bnumlock;
//                 }
//                 returnVal = false;
//                 break;
//             }
//         }
//     }

//     return returnVal;
// }

// void led_set_user(uint8_t usb_led) {
//     // Only handle Num Lock and Caps Lock using keycodes
//     if (usb_led & (1 << 0)) { // Num Lock LED
//         bnumlock = true;
//     } else {
//         bnumlock = false;
//     }

//     if (usb_led & (1 << 1)) { // Caps Lock LED
//         bcapslock = true;
//     } else {
//         bcapslock = false;
//     }
//     // Scroll Lock, Compose, Kana LEDs are not handled
// }

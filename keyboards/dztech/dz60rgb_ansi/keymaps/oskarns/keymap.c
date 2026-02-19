#include QMK_KEYBOARD_H


// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//     [0] = LAYOUT_60_ansi(
//         MT(MOD_LSFT, KC_GRV),        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
//         KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
//         MO(2), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
//         LSFT_T(KC_9),            KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          LSFT_T(KC_0),
//         KC_LCTL,        KC_LGUI, KC_LALT,                            KC_SPC,                             KC_APPLICATION, KC_RGUI,   MO(3),   MO(2)
//     ),
//     [1] = LAYOUT_60_ansi(
//         _______, _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F15, _______, _______,
//         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F13, KC_F14,          _______,
//         _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
//         _______, _______, _______,                            _______,                              KC_RALT, _______, _______, _______
//     ),
//     [2] = LAYOUT_60_ansi(
//         KC_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
//         _______, KC_MPLY, KC_UP,   _______, KC_PGUP, _______, _______, _______, KC_UP,  _______, RALT(KC_PSCR), KC_F15, KC_HOME, KC_END,
//         KC_CAPS,    KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_F13,  KC_F14,          _______,
//         _______,          KC_VOLD, KC_VOLU, KC_GRV, _______, _______, _______, HYPR(KC_W), _______, _______,  _______,          _______,
//         _______, _______, _______,                            KC_SPC,                              KC_RALT, _______, _______, _______
//     ),
//     [3] = LAYOUT_60_ansi(
//         _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
//         _______, RGB_TOG, _______, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_MOD, _______, _______, KC_MPRV, KC_MNXT,
//         _______, _______, _______, _______, _______, _______, _______, _______, RGB_SPI, RGB_SPD, _______, _______,          _______,
//         _______,          _______, _______, _______, _______, _______, NK_ON,   NK_OFF, _______, _______, _______,          _______,
//         _______, _______, _______,                            TG(1),                            _______, _______, _______, _______
//     )
// };

bool space_toggle = false;

enum custom_keycodes {
    MYSPACE = SAFE_RANGE,
    MYCLICK
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MYSPACE:
            if (record->event.pressed) {
                space_toggle = !space_toggle; // toggle on/off
                if (space_toggle) {
                    register_code(KC_SPACE);
                } else {
                    unregister_code(KC_SPACE);
                }
            }
            return false;

        case MYCLICK:
            if (record->event.pressed) {
                register_code(KC_MS_BTN1); // press left click
            } else {
                unregister_code(KC_MS_BTN1); // release left click
            }
            return false;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_60_ansi(
        KC_ESC,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,                 KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
        KC_LCTL,        KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, KC_RALT,   MYCLICK,   MO(1)
    ),
    [1] = LAYOUT_60_ansi(
        QK_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, _______, KC_UP,   _______, _______, _______, KC_CALC, _______, KC_INS,  _______, KC_PSCR, KC_SCRL, KC_PAUS, QK_BOOT,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP,          _______,
        KC_MPRV,          KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, NK_TOGG, _______, _______, KC_END,  KC_PGDN,          KC_MNXT,
        _______, _______, _______,                            MYSPACE,                            _______, _______, _______, _______
    )/*,
    [2] = LAYOUT_60_ansi(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, RM_TOGG, _______, RM_HUEU, RM_HUED, RM_SATU, RM_SATD, RM_VALU, RM_VALD, RM_NEXT, _______, _______, _______, QK_BOOT,
        _______, _______, _______, _______, _______, _______, _______, _______, RM_SPDU, RM_SPDD, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    )*/
};

void keyboard_post_init_user(void) {
    rgblight_disable(); // turn RGB off at startup
}
#include QMK_KEYBOARD_H

#define MODS_PRESSED(btn)  (get_mods() & (MOD_BIT(KC_L##btn)|MOD_BIT(KC_R##btn)))

enum custom_keycodes {
  ALT_F4
};

#define SET_WHETHER(mask, btn1, btn2) \
if (record->event.pressed) {          \
    if (mask) {                       \
        add_key(btn2);                \
        send_keyboard_report();       \
    } else {                          \
        add_key(btn1);                \
        send_keyboard_report();       \
    }                                 \
} else {                              \
    if (mask) {                       \
        del_key(btn2);                \
        send_keyboard_report();       \
    } else {                          \
        del_key(btn1);                \
        send_keyboard_report();       \
    }                                 \
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_60_ansi(
        KC_GESC,        KC_1,    KC_2,    KC_3,    ALT_F4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        MO(2), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSPO,                 KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSPC,
        KC_LCTL,        KC_LGUI, KC_LALT,                            KC_SPC,                             KC_APPLICATION, KC_RGUI,   MO(3),   MO(2)
    ),
    [1] = LAYOUT_60_ansi(
        _______, _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F15, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F13, KC_F14,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,                            _______,                              _______, _______, _______, _______
    ),
    [2] = LAYOUT_60_ansi(
        KC_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, _______, HYPR(KC_W),   _______, KC_PGUP, _______, _______, _______, KC_UP,  _______, RALT(KC_PSCR), KC_F15, KC_HOME, KC_END,
        KC_CAPS,    _______, KC_MPLY, _______, KC_PGDN, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_F13,  KC_F14,          _______,
        _______,          KC_VOLD, KC_VOLU, KC_GRV, _______, _______, _______, _______, _______, _______,  _______,          _______,
        _______, _______, _______,                            TG(1),                              _______, _______, _______, _______
    ),
    [3] = LAYOUT_60_ansi(
        RESET, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, RGB_TOG, _______, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_MOD, _______, _______, KC_MPRV, KC_MNXT,
        _______, _______, _______, _______, _______, _______, _______, _______, RGB_SPI, RGB_SPD, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, NK_ON,   NK_OFF, _______, _______, _______,          _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case ALT_F4:
        SET_WHETHER(MODS_PRESSED(ALT), KC_4, KC_F4);
        return false;
        break;
    default:
        return true;
    }
}

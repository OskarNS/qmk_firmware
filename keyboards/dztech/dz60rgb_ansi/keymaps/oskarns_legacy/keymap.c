#include QMK_KEYBOARD_H

bool bnumlock = false;
bool bcapslock = false;

enum custom_keycodes {
  EACUTE = SAFE_RANGE,
  UUMLAUT,
};

char *alt_codes[][2] = {
    {
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_3)SS_TAP(X_KP_0)), // Alt+130 → é
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_4)SS_TAP(X_KP_4)), // Alt+144 → É
    },
    {
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_2)SS_TAP(X_KP_9)), // Alt+129 → ü
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_5)SS_TAP(X_KP_4)), // Alt+154 → Ü
    },
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_60_ansi(
        KC_GESC,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
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
        _______, _______, _______,                            _______,                              KC_RALT, _______, _______, _______
    ),
    [2] = LAYOUT_60_ansi(
        KC_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, KC_MPLY, KC_UP,   EACUTE, KC_PGUP, _______, _______, UUMLAUT, KC_UP,  _______, RALT(KC_PSCR), KC_F15, KC_HOME, KC_END,
        KC_CAPS,    KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_F13,  KC_F14,          _______,
        _______,          KC_VOLD, KC_VOLU, KC_GRV, _______, _______, _______, HYPR(KC_W), _______, _______,  _______,          _______,
        _______, _______, _______,                            KC_SPC,                              KC_RALT, _______, _______, _______
    ),
    [3] = LAYOUT_60_ansi(
        RESET, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, RGB_TOG, _______, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_MOD, _______, _______, KC_MPRV, KC_MNXT,
        _______, _______, _______, _______, _______, _______, _______, _______, RGB_SPI, RGB_SPD, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, NK_ON,   NK_OFF, _______, _______, _______,          _______,
        _______, _______, _______,                            TG(1),                            _______, _______, _______, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool returnVal = true;
    switch (keycode) {
        case UUMLAUT:
        case EACUTE: {
            if (record->event.pressed) {
                bool flip = false;
                if(!bnumlock) {
                    tap_code(KC_NLCK);
                    bnumlock = true;
                    flip = true;
                }
                uint16_t index = keycode - EACUTE;
                bool lshift = (bool)(get_mods() & (MOD_BIT(KC_LSFT)));
                bool rshift = (bool)(get_mods() & (MOD_BIT(KC_RSFT)));
                bool shift = lshift || rshift;

                if (lshift) unregister_code(KC_LSFT);
                if (rshift) unregister_code(KC_RSFT);

                send_string(alt_codes[index][shift ^ bcapslock]);

                if (lshift) register_code(KC_LSFT);
                if (rshift) register_code(KC_RSFT);
                if(flip) {
                    tap_code(KC_NLCK);
                    bnumlock = !bnumlock;
                }
                returnVal = false;
                break;
            }
        }
    }

    return returnVal;
}

void led_set_user(uint8_t usb_led) {
    if (usb_led & (1 << USB_LED_NUM_LOCK)) {
        bnumlock = true;
    } else {
        bnumlock = false;
    }

    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        bcapslock = true;
    } else {
        bcapslock = false;
    }

    if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
    } else {
    }

    if (usb_led & (1 << USB_LED_COMPOSE)) {
    } else {
    }

    if (usb_led & (1 << USB_LED_KANA)) {
    } else {
    }
}

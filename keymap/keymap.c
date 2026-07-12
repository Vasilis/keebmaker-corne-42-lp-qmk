#include QMK_KEYBOARD_H

enum layers {
    COLEMAK,
    NUMBER,
    SYMBOL,
    ADJUST,
};

enum custom_keycodes {
    OLED_TOGGLE = SAFE_RANGE,
};

// Hold = modifier, tap = macOS shortcut (tap keycode overridden in process_record_user).
// Mirrors the Zen's `hld` behavior (180ms term, tap-preferred): QMK mod-taps buffer
// interrupting keys until the hold/tap decision, so fast rolls keep the modifier.
#define GUI_COPY   MT(MOD_LGUI, KC_C)
#define RSFT_PASTE MT(MOD_RSFT, KC_V)

#define LOWER TL_LOWR
#define RAISE TL_UPPR

#define OS_LSFT OSM(MOD_LSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LALT OSM(MOD_LALT)

#define MAC_SCREENSHOT S(G(KC_4))
#define MAC_MISSION C(KC_UP)
#define MAC_EXPOSE C(KC_DOWN)
#define MAC_DESK_L C(KC_LEFT)
#define MAC_DESK_R C(KC_RIGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [COLEMAK] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_Q, KC_W, KC_F, KC_P, KC_B,          KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSLS,
        OS_LCTL, KC_A, KC_R, KC_S, KC_T, KC_G,          KC_M, KC_N, KC_E, KC_I, KC_O,    KC_QUOT,
        OS_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_V,          KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, RSFT_PASTE,
                             LOWER, GUI_COPY, KC_SPC,    KC_ENT, KC_BSPC, RAISE
    ),

    [NUMBER] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,     KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TILD,
        OS_LCTL, KC_1,  KC_2,  KC_3,  KC_4,  KC_5,      KC_6,  KC_7,  KC_8,  KC_9,  KC_0,   KC_GRV,
        OS_LSFT, _______, _______, _______, OS_LALT, _______,   KC_UNDS, KC_PLUS, KC_PIPE, KC_LCBR, KC_RCBR, RSFT_PASTE,
                                  _______, KC_LGUI, KC_SPC,     KC_ENT, KC_DEL, _______
    ),

    [SYMBOL] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,   KC_CIRC, KC_AMPR, KC_PAST, KC_LPRN, KC_RPRN, _______,
        OS_LCTL, _______, _______, KC_MPLY, KC_MPRV, KC_MNXT, _______, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT, KC_GRV,
        OS_LSFT, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MINS, KC_EQL, _______, KC_LBRC, KC_RBRC, RSFT_PASTE,
                                    _______, KC_LGUI, KC_SPC, KC_ENT, KC_BSPC, _______
    ),

    [ADJUST] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_F11, KC_F12, _______, _______, _______,   MAC_SCREENSHOT, KC_HOME, KC_END, _______, _______, _______,
        OS_LCTL, RM_TOGG, RM_NEXT, RM_HUEU, RM_VALU, RM_VALD, MAC_DESK_L, MAC_MISSION, MAC_EXPOSE, _______, _______, _______,
        OS_LSFT, OLED_TOGGLE, _______, _______, _______, _______, MAC_DESK_R, KC_PGDN, KC_PGUP, _______, _______, _______,
                                      _______, KC_LGUI, KC_SPC, KC_ENT, KC_BSPC, _______
    ),
};

enum combo_events {
    COMBO_UNDERSCORE,
    COMBO_MINUS,
    COMBO_COLON,
    COMBO_EQUAL,
    COMBO_PLUS,
    COMBO_ENTER,
    COMBO_SPACE,
    COMBO_BACKSPACE,
    COMBO_ESCAPE,
    COMBO_TAB,
    COMBO_LENGTH,
};

const uint16_t PROGMEM combo_underscore[] = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM combo_minus[]      = {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM combo_colon[]      = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_equal[]      = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM combo_plus[]       = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM combo_enter[]      = {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM combo_space[]      = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM combo_backspace[]  = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_escape[]     = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM combo_tab[]        = {KC_A, KC_R, COMBO_END};

combo_t key_combos[COMBO_LENGTH] = {
    [COMBO_UNDERSCORE] = COMBO(combo_underscore, KC_UNDS),
    [COMBO_MINUS]      = COMBO(combo_minus, KC_MINS),
    [COMBO_COLON]      = COMBO(combo_colon, KC_COLN),
    [COMBO_EQUAL]      = COMBO(combo_equal, KC_EQL),
    [COMBO_PLUS]       = COMBO(combo_plus, KC_PLUS),
    [COMBO_ENTER]      = COMBO(combo_enter, KC_ENT),
    [COMBO_SPACE]      = COMBO(combo_space, KC_SPC),
    [COMBO_BACKSPACE]  = COMBO(combo_backspace, KC_BSPC),
    [COMBO_ESCAPE]     = COMBO(combo_escape, KC_ESC),
    [COMBO_TAB]        = COMBO(combo_tab, KC_TAB),
};

uint16_t get_combo_term(uint16_t combo_index, combo_t *combo) {
    return combo_index == COMBO_ESCAPE ? 30 : 40;
}

#define ROLLBACK_EEPROM_VERSION 0x20260713

void keyboard_post_init_user(void) {
    // One-time cleanup after the experimental RGB build: discard its saved
    // animation/brightness and restore this baseline's solid-color defaults.
    if (eeconfig_read_user() != ROLLBACK_EEPROM_VERSION) {
#ifdef RGB_MATRIX_ENABLE
        eeconfig_update_rgb_matrix_default();
#endif
        eeconfig_update_user(ROLLBACK_EEPROM_VERSION);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Override the mod-taps' tap action to send the macOS shortcut.
        case GUI_COPY:
            if (record->tap.count && record->event.pressed) {
                tap_code16(G(KC_C));
                return false;
            }
            break;

        case RSFT_PASTE:
            if (record->tap.count && record->event.pressed) {
                tap_code16(G(KC_V));
                return false;
            }
            break;

        case OLED_TOGGLE:
            if (record->event.pressed) {
                if (is_oled_on()) {
                    oled_off();
                } else {
                    oled_on();
                }
            }
            return false;
    }
    return true;
}

#ifdef OLED_ENABLE
// Provided by crkbd.c (weak): renders the classic Corne logo glyphs.
void oled_render_logo(void);

// Rotation: crkbd's oled_init_kb already flips the slave half 180°.
// Master (left) shows the layer status; slave (right) shows the Corne logo.
bool oled_task_user(void) {
    if (!is_keyboard_master()) {
        oled_render_logo();
        return false;
    }
    oled_write_P(PSTR("KEEBMAKER\n\n"), false);
    oled_write_P(PSTR("Layer\n"), false);
    switch (get_highest_layer(layer_state)) {
        case COLEMAK:
            oled_write_ln_P(PSTR("COLEMAK"), false);
            break;
        case NUMBER:
            oled_write_ln_P(PSTR("NUMBER"), false);
            break;
        case SYMBOL:
            oled_write_ln_P(PSTR("SYMBOL"), false);
            break;
        case ADJUST:
            oled_write_ln_P(PSTR("ADJUST"), false);
            break;
        default:
            oled_write_ln_P(PSTR("UNKNOWN"), false);
            break;
    }
    return false;
}
#endif

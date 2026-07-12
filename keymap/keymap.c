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

#define LOWER MO(NUMBER)
#define RAISE MO(SYMBOL)

#define GUI_COPY MT(MOD_LGUI, KC_C)
#define RSFT_PASTE MT(MOD_RSFT, KC_V)

#define OS_LSFT OSM(MOD_LSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LALT OSM(MOD_LALT)

#define MAC_SCREENSHOT S(G(KC_4))
#define MAC_MISSION C(KC_UP)
#define MAC_EXPOSE C(KC_DOWN)
#define MAC_DESK_L C(KC_LEFT)
#define MAC_DESK_R C(KC_RIGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // COLEMAK
    // ,-------------------------------------------.     ,-------------------------------------------.
    // | TAB |  Q  |  W  |  F  |  P  |  B  |           |  J  |  L  |  U  |  Y  |  ;  |  \\  |
    // |-----+-----+-----+-----+-----+-----|           |-----+-----+-----+-----+-----+-----|
    // | CTL |  A  |  R  |  S  |  T  |  G  |           |  M  |  N  |  E  |  I  |  O  |  '  |
    // |-----+-----+-----+-----+-----+-----|           |-----+-----+-----+-----+-----+-----|
    // | SFT |  Z  |  X  |  C  |  D  |  V  |           |  K  |  H  |  ,  |  .  |  /  |SFT/V|
    // `-----------------------------------/           \-----------------------------------'
    //                   |LOWER|GUI/C| SPC |           | ENT | BSP |RAISE|
    //                   `-----------------'           `-----------------'
    [COLEMAK] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_Q, KC_W, KC_F, KC_P, KC_B,          KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSLS,
        OS_LCTL, KC_A, KC_R, KC_S, KC_T, KC_G,          KC_M, KC_N, KC_E, KC_I, KC_O,    KC_QUOT,
        OS_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_V,          KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, RSFT_PASTE,
                             LOWER, GUI_COPY, KC_SPC,    KC_ENT, KC_BSPC, RAISE
    ),

    // NUMBER
    // ,-------------------------------------------.     ,-------------------------------------------.
    // | ESC | F1  | F2  | F3  | F4  | F5  |           | F6  | F7  | F8  | F9  | F10 |  ~  |
    // |-----+-----+-----+-----+-----+-----|           |-----+-----+-----+-----+-----+-----|
    // | CTL |  1  |  2  |  3  |  4  |  5  |           |  6  |  7  |  8  |  9  |  0  |  `  |
    // |-----+-----+-----+-----+-----+-----|           |-----+-----+-----+-----+-----+-----|
    // | SFT |     |     |     | OPT |     |           |  _  |  +  |  |  |  {  |  }  |SFT/V|
    // `-----------------------------------/           \-----------------------------------'
    //                   |     | GUI | SPC |           | ENT | DEL |     |
    //                   `-----------------'           `-----------------'
    [NUMBER] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,     KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TILD,
        OS_LCTL, KC_1,  KC_2,  KC_3,  KC_4,  KC_5,      KC_6,  KC_7,  KC_8,  KC_9,  KC_0,   KC_GRV,
        OS_LSFT, _______, _______, _______, OS_LALT, _______,   KC_UNDS, KC_PLUS, KC_PIPE, KC_LCBR, KC_RCBR, RSFT_PASTE,
                                  _______, KC_LGUI, KC_SPC,     KC_ENT, KC_DEL, _______
    ),

    // SYMBOL
    // ,-------------------------------------------.     ,-------------------------------------------.
    // | ESC |  !  |  @  |  #  |  $  |  %  |           |  ^  |  &  |  *  |  (  |  )  |     |
    // |-----+-----+-----+-----+-----+-----|           |-----+-----+-----+-----+-----+-----|
    // | CTL |     |     |PLAY |PREV |NEXT |           |     |LEFT | UP  |DOWN |RIGHT|  `  |
    // |-----+-----+-----+-----+-----+-----|           |-----+-----+-----+-----+-----+-----|
    // | SFT |     |     |MUTE |VOLDN|VOLUP|           |  -  |  =  |     |  [  |  ]  |SFT/V|
    // `-----------------------------------/           \-----------------------------------'
    //                   |     | GUI | SPC |           | ENT | BSP |     |
    //                   `-----------------'           `-----------------'
    [SYMBOL] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,   KC_CIRC, KC_AMPR, KC_PAST, KC_LPRN, KC_RPRN, _______,
        OS_LCTL, _______, _______, KC_MPLY, KC_MPRV, KC_MNXT, _______, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT, KC_GRV,
        OS_LSFT, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MINS, KC_EQL, _______, KC_LBRC, KC_RBRC, RSFT_PASTE,
                                    _______, KC_LGUI, KC_SPC, KC_ENT, KC_BSPC, _______
    ),

    // ADJUST (LOWER + RAISE)
    // ,-------------------------------------------.     ,-------------------------------------------.
    // | ESC | F11 | F12 |     |     |     |           |SHOT |HOME | END |     |     |     |
    // |-----+-----+-----+-----+-----+-----|           |-----+-----+-----+-----+-----+-----|
    // | CTL |RGB T|NEXT |HUE+ |SPD+ |VAL+ |           |DSK L|MCTRL|EXPOS|     |     |     |
    // |-----+-----+-----+-----+-----+-----|           |-----+-----+-----+-----+-----+-----|
    // | SFT |OLED |PREV |HUE- |SPD- |VAL- |           |DSK R|PGDN |PGUP |     |     |     |
    // `-----------------------------------/           \-----------------------------------'
    //                   |     | GUI | SPC |           | ENT | BSP |     |
    //                   `-----------------'           `-----------------'
    [ADJUST] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_F11, KC_F12, _______, _______, _______,   MAC_SCREENSHOT, KC_HOME, KC_END, _______, _______, _______,
        OS_LCTL, RM_TOGG, RM_NEXT, RM_HUEU, RM_SPDU, RM_VALU, MAC_DESK_L, MAC_MISSION, MAC_EXPOSE, _______, _______, _______,
        OS_LSFT, OLED_TOGGLE, RM_PREV, RM_HUED, RM_SPDD, RM_VALD, MAC_DESK_R, KC_PGDN, KC_PGUP, _______, _______, _______,
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

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, NUMBER, SYMBOL, ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
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
bool oled_task_user(void) {
    // Prepend WPM on the master, then let Corne's stock OLED task render the
    // active layer and its proven last-key log. The stock task draws the Corne
    // logo on the slave half.
    if (is_keyboard_master()) {
        oled_write_P(PSTR("WPM: "), false);
        oled_write_ln(get_u8_str(get_current_wpm(), '0'), false);
    }
    return true;
}
#endif

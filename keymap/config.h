#pragma once

// --- Auto-shift: letters only, matching the Zen's `as` hold-tap (220ms) ---
#define AUTO_SHIFT_TIMEOUT 220
#define NO_AUTO_SHIFT_NUMERIC
#define NO_AUTO_SHIFT_SPECIAL
#define NO_AUTO_SHIFT_TAB
#define AUTO_SHIFT_NO_SETUP

// --- Mod-taps (GUI_COPY / RSFT_PASTE): match the Zen's `hld` (180ms, quick-tap 0) ---
#define TAPPING_TERM 180
#define QUICK_TAP_TERM 0

// --- Combos: 40ms (ESC combo 30ms via get_combo_term). Check against base-layer
// keycodes on every layer, like ZMK's position-based combos. ---
#define COMBO_TERM 40
#define COMBO_TERM_PER_COMBO
#define COMBO_ONLY_FROM_LAYER 0

// --- Sticky mods: auto-release after 1s, matching ZMK's release-after-ms ---
#define ONESHOT_TIMEOUT 1000

// --- Split: sync layer state so the slave OLED shows the active layer ---
#define SPLIT_LAYER_STATE_ENABLE

// --- OLED: sleep after 30s idle (wakes on keypress) to avoid burn-in ---
#define OLED_TIMEOUT 30000

// --- RGB Matrix (only when enabled in rules.mk): capped for the USB-A power
// budget. The board was dying from thermal over-current — keep these low.
// crkbd defines a 120 cap at the keyboard level; override it down. ---
#define RGB_MATRIX_SLEEP
#undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 80
#define RGB_MATRIX_DEFAULT_VAL 32
#define RGB_MATRIX_HUE_STEP 8
#define RGB_MATRIX_SAT_STEP 8
#define RGB_MATRIX_VAL_STEP 8
#define RGB_MATRIX_SPD_STEP 10

// --- Animations (cycled with RM_NEXT on ADJUST). QMK effects are opt-in;
// this is a small tasteful set that fits the remaining flash. ---
#define ENABLE_RGB_MATRIX_BREATHING             // slow pulse
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT      // rainbow wave across the board
#define ENABLE_RGB_MATRIX_CYCLE_ALL             // whole board slowly cycles hue
#define RGB_MATRIX_KEYPRESSES                   // enable reactive effects
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE // keys light up as you type

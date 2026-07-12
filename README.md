# KeebMaker Corne 42 LP — Corneish Zen QMK port

QMK keymap porting Vasilis' `corneish_zen.keymap` (ZMK) to the wired KeebMaker
Corne 42 LP (`crkbd/rev1`, ATmega32U4 "Pro Micro C", Caterina bootloader).

Features carried over 1:1: 4 layers (COLEMAK / NUMBER / SYMBOL / ADJUST
tri-layer), auto-shift on letters (220ms), 10 combos (ESC combo 30ms, rest
40ms, active on all layers), sticky Ctrl/Shift/Alt (1s release), GUI-hold /
⌘C-tap and RShift-hold / ⌘V-tap mod-taps (180ms), macOS Mission Control /
Exposé / desktop keys, media keys, OLED layer display on both halves.

## Firmware variants (`firmware/`)

- **`keebmaker_zen_stage1_no_rgb.hex`** — RGB disabled. Flash this FIRST.
  The board was dying (full power-off, revived only by replug) from thermal
  over-current: RGB LED draw through the USB-A adapter path. This build
  removes that load entirely. 22,266/28,672 bytes (77%).
- **`keebmaker_zen_stage2_rgb_capped.hex`** — RGB Matrix on, brightness hard-
  capped at 80/255 (default 32), with brightness up/down keys on ADJUST so it
  can be raised gradually. Only flash after Stage 1 has proven stable. If the
  power-off ever returns, go back to Stage 1. 24,858/28,672 bytes (86%).

Both are built from `keymap/` — the only difference is `RGB_MATRIX_ENABLE`
in `rules.mk`.

## Build

```sh
cp -R keymap ~/qmk_firmware/keyboards/crkbd/keymaps/keebmaker_zen
qmk compile -kb crkbd/rev1 -km keebmaker_zen
```

## Flashing (each half separately, same hex)

1. Disconnect USB power before inserting or removing the TRRS cable — hot-
   plugging TRRS can fry the controllers.
2. Connect USB to only the half being flashed, via a USB-A adapter — the
   board has no USB-C CC resistors, so C-to-C cables do NOT power it.
3. `qmk flash -kb crkbd/rev1 -km keebmaker_zen`, or QMK Toolbox / avrdude:
   ```sh
   avrdude -p atmega32u4 -c avr109 -P <bootloader-port> -U flash:w:<hex>:i
   ```
4. When the tool waits for the bootloader, **press the reset button once**
   (single press = Caterina bootloader, ~8s window).
5. Repeat for the other half. Reconnect TRRS while unpowered, then plug USB
   into the **left** half for normal use (left is master).

## Recovery

- Bad flash: rerun `qmk flash`, single-press reset when prompted.
- Bootmagic (hold while plugging USB in; also clears EEPROM): the top-left
  matrix key of the half — **TAB** on the left half, the outer top key
  (the ⌫\ position) on the right half.
- Factory restore: KeebMaker's stock VIA hex is downloadable from
  https://keebmaker.com/pages/km-corne-build-guide

## Intentional wired substitutions

The Zen's Bluetooth keys (impossible on a wired board) are replaced on
ADJUST with RGB controls (toggle / mode / hue-up / brightness up & down) and
an OLED toggle.

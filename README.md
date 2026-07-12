# KeebMaker Corne 42 LP — Corneish Zen QMK port

This QMK keymap ports the portable behavior of Vasilis' `corneish_zen.keymap`
to the wired KeebMaker Corne 42 LP (`crkbd/rev1`, ATmega32U4/Pro Micro).

The left OLED shows current WPM followed by QMK's stock Corne layer status and
last-key log. The right OLED shows QMK's stock Corne logo. See
[LAYOUTS.md](LAYOUTS.md) for complete ASCII maps of every layer and combo.

RGB Matrix includes Solid Color, Breathing, and Rainbow Cycle modes. The Adjust
layer provides mode, hue, speed, and brightness controls.

## Build

From a QMK firmware checkout:

```sh
cp -R keymap keyboards/crkbd/keymaps/keebmaker_zen
qmk compile -kb crkbd/rev1 -km keebmaker_zen
```

The expected output is `crkbd_rev1_keebmaker_zen.hex`.

The delivered binary was built with QMK commit
`a738fad372c1e72e10c47f560c8d167d233416ad`, AVR GCC 9.5.0, and avrdude 8.2.
Its compiled size is 26,726/28,672 bytes (93%), and its SHA-256 is
`792cb5d218b0d86df8e2e52023144f8115676a2a6bfda9d0d8d61cf7d9316f37`.

## Safe flashing

1. Disconnect USB power before inserting or removing the TRRS cable.
2. Connect the TRRS cable between halves.
3. Connect USB to only the half being flashed.
4. Run `qmk flash -kb crkbd/rev1 -km keebmaker_zen` and press that half's reset button when prompted.
5. Disconnect USB, move USB to the other half, and repeat. Both halves use the same HEX file.
6. Reconnect in normal use with the TRRS cable already seated and USB connected to the left half.

If Caterina is confirmed explicitly, the equivalent direct command is:

```sh
avrdude -p atmega32u4 -c avr109 -P <bootloader-port> -U flash:w:crkbd_rev1_keebmaker_zen.hex:i
```

## Recovery

- Reset-button method: start `qmk flash`, then press the physical reset button once.
- Bootmagic method: with that half unplugged, hold its `Q` position on the left half or `P` position on the right half (matrix `[0,1]` / `[4,1]`), connect USB, then release. This also clears EEPROM.
- Never insert or remove TRRS while either half is powered.

## Intentional wired substitutions

The Zen's four Bluetooth actions are replaced on Adjust with RGB toggle, RGB
mode, RGB hue-up, and OLED toggle. Zen-specific wireless and e-paper behavior
cannot exist on this wired OLED/RGB board.

## License

GPL-2.0-or-later, matching QMK Firmware.

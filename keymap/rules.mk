AUTO_SHIFT_ENABLE = yes
COMBO_ENABLE = yes
TRI_LAYER_ENABLE = yes
OLED_ENABLE = yes
EXTRAKEY_ENABLE = yes    # media keys (play/vol) must not depend on defaults
LTO_ENABLE = yes         # link-time optimization; frees flash on ATmega32U4
RGBLIGHT_ENABLE = no

# STAGE 1: RGB disabled to isolate the 10-20s power-death (thermal over-current
# from LED draw through the USB-A adapter). Re-enable only after the board
# proves stable, with the reduced brightness caps in config.h.
RGB_MATRIX_ENABLE = no

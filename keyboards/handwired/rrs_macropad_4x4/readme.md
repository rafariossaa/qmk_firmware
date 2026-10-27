# rrs_macropad_4x4

![rrs_macropad_4x4](imgur.com image replace me!)

## Install qmk tools
```shell
apt-get install python3-setuptools
python3 -m pip install --user qmk --break-system-packages
export PATH=/home/rafa/.local/bin:$PATH
```

## Setup

```shell
qmk setup
```

The qmk home folder can be specified at setup with qmk setup -H <path>, and modified afterwards using the cli configuration and the variable user.qmk_home. For all available options run qmk setup --help.

If you already know how to use GitHub, we recommend that you follow these instructions and use qmk setup <github_username>/qmk_firmware to clone your personal fork. If you don't know what that means you can safely ignore this message.

## Build
```shell
qmk compile -kb handwired/rrs_macropad_4x4 -km default
```


*A short description of the keyboard/project*

* Keyboard Maintainer: [Rafael Rios Saavedra](https://github.com/Rafael Rios Saavedra)
* Hardware Supported: *The PCBs, controllers supported*
* Hardware Availability: *Links to where you can find this hardware*

Make example for this keyboard (after setting up your build environment):

    make rrs_macropad_4x4:default

Flashing example for this keyboard:

    make rrs_macropad_4x4:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## OLED display

The macropad supports a 1.3" 128x64 I2C OLED display with an SH1106 controller, using the [QMK OLED driver](https://docs.qmk.fm/features/oled_driver).

### Wiring

| Display | RP2040 |
|---------|--------|
| SDA     | GP10   |
| SCL     | GP11   |
| VCC     | 5V (VBUS) |
| GND     | GND    |

GP10/GP11 are the I2C1 peripheral of the RP2040. This display module has an on-board voltage regulator, so it is powered from 5V.

### Configuration

* `rules.mk`: `OLED_ENABLE = yes` and `OLED_DRIVER = ssd1306` (this driver also covers SH1106).
* `config.h`:
  * `I2C_DRIVER I2CD1`, `I2C1_SDA_PIN GP10` and `I2C1_SCL_PIN GP11` select the I2C peripheral and pins.
  * `OLED_IC OLED_IC_SH1106` selects the controller. Most 1.3" modules use the SH1106 even if they are sold as SSD1306.
  * `OLED_COLUMN_OFFSET 2` compensates for the SH1106 having 132 columns of memory while the panel shows 128.
  * `OLED_BRIGHTNESS 128` sets the brightness.
* `halconf.h` and `mcuconf.h` enable the ChibiOS I2C driver (`HAL_USE_I2C`) and the RP2040 I2C1 peripheral (`RP_I2C_USE_I2C1`).

The default keymap draws the QMK logo in `oled_task_user()` in `keymaps/default/keymap.c`.

### Troubleshooting

* **Random dots or garbage on the screen**: the controller type is probably wrong. Try `OLED_IC_SSD1306` (for SSD1306 modules) or `OLED_IC_SH1106`.
* **A few columns of noise at one edge**: adjust `OLED_COLUMN_OFFSET` (try 0, 1, 2 or 3).
* **Blank screen**: check the wiring and the I2C address (default `0x3C`, set `OLED_DISPLAY_ADDRESS 0x3D` if needed).


## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available

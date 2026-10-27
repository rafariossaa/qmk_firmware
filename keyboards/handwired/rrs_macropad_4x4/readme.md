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

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available

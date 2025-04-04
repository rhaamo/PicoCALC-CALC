# PicoCalc Calc Firmware

This has been tested only with a Pico 2W.

Build, flash, and type "help".

<img src="https://raw.githubusercontent.com/rhaamo/PicoCALC-CALC/refs/heads/main/hw.jpg" width="500">

## Notes

Requires keyboard firmware update for battery display.

## Issues

- Scrolling for history is still broken and doesn't work
- "long" inputs with errors doesn't line up properly somehow
- Directional key left/right goes two chars instead of one ???

## Features
- Maths! It does uses the [TinyExpr](https://github.com/codeplea/tinyexpr) library, it isn't super fresh but it does work.

## Current commands

```
flash: reset in flash mode
reset: soft reset
bat: get battery level
mem: show memory usage (broken)
ver: show version
uwu: ???
anything else will be fed to tinyexpr (he's hungry)
```

## TODO
- Fix the history scroll issue
- Implement up/down for the history maybe
- Idk maybe commands history ?
- RTC with a hardware mod https://forum.clockworkpi.com/t/rtc-inside-the-case/16484/2
  - Implement `time set` `time` etc. (Could uses GP0/GP1 to avoid overlapping on the PSRAM pins, plus GP28 for the interrupt pin)
- Enable PSRAM ?

## Build Instructions
```bash
# Clone the repo
git clone --recursive https://github.com/rhaamo/picocalc-calc

# Navigate to the project directory
cd {path_to_this_project}

# Create and enter the build directory
mkdir build
cd build

# Set the PICO SDK path
export PICO_SDK_PATH=/path/to/pico-sdk

# Configure and build the project
cmake ..
make
```

#### Special thanks
[Hsuan Han Lai](https://github.com/adwuard) for initial LVGL porting and demo project for the PicoCalc 

# PicoCalc Calc Firmware

This has been tested only with a Pico 2W.

Build, flash, and type "help".

<img src="https://raw.githubusercontent.com/rhaamo/PicoCALC-CALC/refs/heads/main/hw.jpg" width="400">

## Notes

Requires keyboard firmware update for battery display.

## Issues

- Scrolling for history is still broken and doesn't work
- Need fix in kbd handling to remove workaround code https://github.com/clockworkpi/PicoCalc/issues/10

## Current commands

```
flash: reset in flash mode
reset: soft reset
bat: get battery level
uwu: ???
anything else will be fed to tinyexpr (he's hungry)
```

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
[Hsuan Han Lai](https://github.com/adwuard) for initial porting and demo project for the PicoCalc 

# PicoCalc Calc something

This has been tested only with a Pico 2W.

Build, flash, and type "help".

## Notes

Requires keyboard firmware update for battery display.

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

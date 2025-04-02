cmake_minimum_required(VERSION 3.16)

# Setup board for Pico 1
#set(PICO_BOARD pico)

# Setup board for Pico 2W
set(PICO_BOARD pico2)

# Needs to be before project()
include(pico_sdk_import.cmake)

project(picocalc_calc C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

include_directories(
  ${CMAKE_CURRENT_LIST_DIR}
)

# To get the right files for VSCode at least
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# https://github.com/raspberrypi/pico-sdk/issues/1605 ?
# For some reasons, the stdlib stuff doesn't get included in the compile_commands.json file
# resulting in pretty much anything std to not be totally detected and found, throwing a shitload
# of clangd errors
set(CMAKE_C_STANDARD_INCLUDE_DIRECTORIES /usr/arm-none-eabi/include)


add_subdirectory(i2ckbd)
add_subdirectory(lcdspi)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/lib/lvgl lvgl)


add_executable(picocalc_calc
    main.c
    lib/tinyexpr/tinyexpr.c
    lv_port_indev_picocalc_kb.c
    lv_port_disp_picocalc_ILI9488.c
)

target_compile_options(picocalc_calc PRIVATE -DPICOMITE
										-DPICO_HEAP_SIZE=0x1000 
										-DGUICONTROLS
										-DPICO_CORE0_STACK_SIZE=0x1000
										)

target_include_directories(picocalc_calc PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/lib/lvgl/lvgl
    ${CMAKE_CURRENT_LIST_DIR}/lib/lvgl/lvgl/src
    ${CMAKE_CURRENT_LIST_DIR}/lib/tinyexpr/
)


target_link_libraries(picocalc_calc
  pico_stdlib
  hardware_flash
  hardware_irq
  hardware_adc
  hardware_pwm
  hardware_i2c
  hardware_spi
  hardware_dma
  hardware_exception
  hardware_pio
  pico_multicore
  i2ckbd
  lcdspi
  lvgl
)

pico_enable_stdio_usb(picocalc_calc 0)
pico_enable_stdio_uart(picocalc_calc 1)
pico_add_extra_outputs(picocalc_calc)

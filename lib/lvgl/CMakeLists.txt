file(GLOB_RECURSE LVGL_SOURCES lvgl/src/*.c  lvgl/port/*.c)
add_library(lvgl ${LVGL_SOURCES})

set_property(TARGET lvgl APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

# # Add LVGL demo sources
# file(GLOB_RECURSE LVGL_DEMO_SOURCES lvgl/demos/*.c)
# add_library(lvgl_demos ${LVGL_DEMO_SOURCES})

# set_property(TARGET lvgl_demos APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES
# $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
# )

# # Link lvgl library to lvgl_demos
# target_link_libraries(lvgl_demos PRIVATE lvgl)

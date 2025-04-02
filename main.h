#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include <lv_port_indev_picocalc_kb.h>
#include <lv_port_disp_picocalc_ILI9488.h>

#include <pico/bootrom.h>

#include <i2ckbd.h>

#include <tinyexpr.h>

#define ILI9488 1

#define BYTE_PER_PIXEL (LV_COLOR_FORMAT_GET_SIZE(LV_COLOR_FORMAT_RGB565)) /*will be 2 for RGB565 */

const unsigned int LEDPIN = 25;

lv_obj_t *ui_screen;
lv_obj_t *ui_panel;
lv_obj_t *ui_label_status_left;
lv_obj_t *ui_label_status_right;
lv_obj_t *ui_history;
lv_obj_t *ui_history_container;
lv_obj_t *ui_input;
lv_style_t font_12;
lv_style_t font_14;

#endif
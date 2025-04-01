/**
 * PicoCalc LVGL Graphics Demo
 * 
 * Demo App Uses LVGL to show demos on the PicoCalc.
 * Implements basic keyboard input and display driver. 
 * 
 * Author: HsuahHanLai
 * https://www.hsuanhanlai.com/
 */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "core/lv_obj.h"
#include "misc/lv_palette.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"


#include "lv_conf.h"
#include "lvgl/lvgl.h"
#include "lv_port_indev_picocalc_kb.h"
#include "lv_port_disp_picocalc_ILI9488.h"
#include "themes/default/lv_theme_default.h"
#include "tick/lv_tick.h"
#include "widgets/label/lv_label.h"
#include <string.h>
#include "pico/bootrom.h"
#include "i2ckbd.h"

#include "tinyexpr.h"

#define ILI9488 1

#define BYTE_PER_PIXEL (LV_COLOR_FORMAT_GET_SIZE(LV_COLOR_FORMAT_RGB565)) /*will be 2 for RGB565 */


const unsigned int LEDPIN = 25;

lv_obj_t *screen;
lv_obj_t *panel;
lv_obj_t *label_status_left;
lv_obj_t *label_status_right;
lv_obj_t *history;
lv_obj_t *input;

void handle_textarea_command(const char *command_input) {
    printf("Got command: '%s'", command_input);

    // Reboot into flash mode
    if (strcmp(command_input, "flash") == 0) {
        reset_usb_boot(0, 0);
    } else if (strcmp(command_input, "uwu") == 0) {
        lv_label_ins_text(history, -1, "\n*snuggle you :3*");
    } else if (strcmp(command_input, "reset") == 0) {
        *((volatile uint32_t *)(PPB_BASE + 0x0ED0C)) = 0x5FA0004;
    } else if (strcmp(command_input, "bat") == 0) {
        lv_label_ins_text(history, -1, "\n");
        char bat_buff[10];
        snprintf(bat_buff, sizeof(bat_buff), "%f%%", read_battery());
        lv_label_ins_text(history, -1, bat_buff);
    } else if (strcmp(command_input, "help") == 0) {
        lv_label_ins_text(history, -1, "\nhelp:");
        lv_label_ins_text(history, -1, "\n  flash: reset in flash mode");
        lv_label_ins_text(history, -1, "\n  reset: soft reset");
        lv_label_ins_text(history, -1, "\n  bat: get battery level");
        lv_label_ins_text(history, -1, "\n  uwu: ???");
        lv_label_ins_text(history, -1, "\n  anything else will be fed to tinyexpr (he's hungry)");
    } else {
        // It's probably math, I hope
        // but it doesn´t work because tinyexpr doesn't like me
        double result = te_interp(command_input, 0);
        lv_label_ins_text(history, -1, "\n");
        // if (err != 0) {
        //     lv_label_ins_text(history, -1, ":(");
        // } else {
            char buffer[32];
            snprintf(buffer, sizeof(buffer), "%f", result);
            lv_label_ins_text(history, -1, buffer);
        // }
    }
    // Scroll to bottom
    lv_obj_t *parent = lv_obj_get_parent(history);
    lv_obj_scroll_to_y(parent, lv_obj_get_scroll_bottom(parent), LV_ANIM_ON);
}

static void textarea_event_handler(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target_obj(e);
    printf("Textarea: %s", lv_textarea_get_text(ta));
    // Update history
    //lv_label_set_text_fmt(history, "%s\n> %s", lv_label_get_text(history), lv_textarea_get_text(ta));
    lv_label_ins_text(history, -1, "\n> ");
    lv_label_ins_text(history, -1, lv_textarea_get_text(ta));
    // Handle commands
    handle_textarea_command(lv_textarea_get_text(input));
    // Clear input
    lv_textarea_set_text(input, "");
}

void build_screen() {
    // Screen
    screen = lv_obj_create(NULL);
    lv_obj_clear_flag(screen, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_flex_flow(screen, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(screen, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);

    // Top panel
    panel = lv_obj_create(screen);
    lv_obj_set_width(panel, 320);
    lv_obj_set_height(panel, 20);
    lv_obj_set_align(panel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(panel, LV_OBJ_FLAG_SCROLLABLE);

    // Top panel left element
    label_status_left = lv_label_create(panel);
    lv_obj_set_width(label_status_left, LV_SIZE_CONTENT);   /// 100
    lv_obj_set_height(label_status_left, LV_SIZE_CONTENT);    /// 100
    lv_obj_set_x(label_status_left, -140);
    lv_obj_set_y(label_status_left, 0);
    lv_obj_set_align(label_status_left, LV_ALIGN_CENTER);
    lv_label_set_text(label_status_left, "build: ");
    lv_label_ins_text(label_status_left, -1, __DATE__);
    lv_label_ins_text(label_status_left, -1, " ");
    lv_label_ins_text(label_status_left, -1, __TIME__);

    // Top panel right element
    label_status_right = lv_label_create(panel);
    lv_obj_set_width(label_status_right, LV_SIZE_CONTENT);   /// 100
    lv_obj_set_height(label_status_right, LV_SIZE_CONTENT);    /// 100
    lv_obj_set_x(label_status_right, 135);
    lv_obj_set_y(label_status_right, 0);
    lv_obj_set_align(label_status_right, LV_ALIGN_CENTER);
    lv_label_set_text(label_status_right, "069%");

    // Log
    history = lv_label_create(screen);
    lv_obj_set_height(history, 245);
    lv_obj_set_width(history, lv_pct(99));
    lv_obj_set_x(history, -89);
    lv_obj_set_y(history, -100);
    lv_obj_set_align(history, LV_ALIGN_CENTER);
    lv_label_set_long_mode(history, LV_LABEL_LONG_WRAP);
    lv_label_set_text(history, "");

    // Input
    input = lv_textarea_create(screen);
    lv_obj_set_width(input, 320);
    lv_obj_set_height(input, LV_SIZE_CONTENT);    /// 20
    lv_obj_set_x(input, -10);
    lv_obj_set_y(input, 91);
    lv_obj_set_align(input, LV_ALIGN_CENTER);
    // Enable keyboard input for the text box
    lv_textarea_set_placeholder_text(input, "1+1=69");
    lv_textarea_set_one_line(input, true);
    lv_obj_set_style_anim_time(input, 5000, LV_PART_CURSOR|LV_STATE_FOCUSED);
    // Textarea event handler
    lv_obj_add_event_cb(input, textarea_event_handler, LV_EVENT_READY, input);
}

void update_battery_level() {
    lv_label_set_text_fmt(label_status_right, "%i%%", read_battery());
}

int main() {
    // Initialize standard I/O
    stdio_init_all();

    // Initialize LED
    gpio_init(LEDPIN);
    gpio_set_dir(LEDPIN, GPIO_OUT);

    // Initialize LVGL
    lv_init();

    // Initialize the custom display driver
    lv_port_disp_init();

    // Initialize the keyboard input device (implementation in lv_port_indev_kbd.c)
    lv_port_indev_init();

    // Build the screen
    build_screen();

    // Load the screen
    lv_scr_load(screen);

    // Do it one time
    update_battery_level();

    uint32_t last_ticks = lv_tick_get();

    // Main loop
    while (1) {
        lv_timer_handler();
        lv_tick_inc(5); // Increment LVGL tick by 5 milliseconds
        // Update battery every minutes
        if (lv_tick_get()-last_ticks >= 60000) {
            printf("one minute elapsed");
            //update_battery_level();
            last_ticks = lv_tick_get();
        }

        sleep_ms(1); // Sleep for 5 milliseconds}
    }
}

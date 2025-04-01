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
#include <stdlib.h>
#include <string.h>
#include "core/lv_obj.h"
#include "core/lv_obj_style.h"
#include "core/lv_obj_style_gen.h"
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

lv_obj_t *ui_screen;
lv_obj_t *ui_panel;
lv_obj_t *ui_label_status_left;
lv_obj_t *ui_label_status_right;
lv_obj_t *ui_history;
lv_obj_t *ui_history_container;
lv_obj_t *ui_input;
lv_style_t font_12;
lv_style_t font_14;

bool is_ascii(char c) {
    return (c>=0 && c<=127);
}

char *sanitize_command(const char *in_cmd) {
    // Workaround for now because the LVGL PicoCalc makes shift key in the textarea
    size_t length = 0;
    const char *p = in_cmd;
    while (*p) {
        if (is_ascii(*p)) length++;
        p++;
    }

    char *out = malloc(length+1);
    if (!out) return NULL;

    char *dest = out;
    while (*in_cmd) {
        if (is_ascii(*in_cmd)) {
            *dest++ = *in_cmd;
        }
        in_cmd++;
    }
    *dest = '\0';

    return out;
}

void handle_textarea_command(const char *command_input) {
    printf("Got command: '%s'", command_input);

    // Reboot into flash mode
    if (strcmp(command_input, "flash") == 0) {
        reset_usb_boot(0, 0);
    } else if (strcmp(command_input, "uwu") == 0) {
        lv_label_ins_text(ui_history, -1, "\n*snuggle you :3*");
    } else if (strcmp(command_input, "reset") == 0) {
        *((volatile uint32_t *)(PPB_BASE + 0x0ED0C)) = 0x5FA0004;
    } else if (strcmp(command_input, "bat") == 0) {
        lv_label_ins_text(ui_history, -1, "\n");
        int bat_level = read_battery();
        if (bat_level > 100) {
            lv_label_ins_text(ui_history, -1, "ERR%");
        } else {
            char bat_buff[10];
            snprintf(bat_buff, sizeof(bat_buff), "%i%%", bat_level);
            lv_label_ins_text(ui_history, -1, bat_buff);
        }
    } else if (strcmp(command_input, "help") == 0) {
        lv_label_ins_text(ui_history, -1, "\nhelp:");
        lv_label_ins_text(ui_history, -1, "\n  flash: reset in flash mode");
        lv_label_ins_text(ui_history, -1, "\n  reset: soft reset");
        lv_label_ins_text(ui_history, -1, "\n  bat: get battery level");
        lv_label_ins_text(ui_history, -1, "\n  uwu: ???");
        lv_label_ins_text(ui_history, -1, "\n  anything else will be fed to tinyexpr (he's hungry)");
    } else {
        // It's probably math, I hope
        int err = 0;
        double result = te_interp(sanitize_command(command_input), 0);

        lv_label_ins_text(ui_history, -1, "\n");
        if (err != 0) {
            // It's not :(
            lv_label_ins_text(ui_history, -1, "NaN :(");
        } else {
            // It is :)
            char buffer[32];
            snprintf(buffer, sizeof(buffer), "%f", result);
            lv_label_ins_text(ui_history, -1, buffer);
        }
    }
    // Scroll to bottom
    lv_obj_t *parent = lv_obj_get_parent(ui_history);
    printf("cur scroll: %i", lv_obj_get_scroll_bottom(parent));
    lv_obj_scroll_to_y(parent, lv_obj_get_scroll_bottom(parent), LV_ANIM_OFF);
}

static void textarea_event_handler(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target_obj(e);
    // Update history
    //lv_label_set_text_fmt(history, "%s\n> %s", lv_label_get_text(history), lv_textarea_get_text(ta));
    lv_label_ins_text(ui_history, -1, "\n> ");
    lv_label_ins_text(ui_history, -1, lv_textarea_get_text(ta));
    // Handle commands
    handle_textarea_command(lv_textarea_get_text(ui_input));
    // Clear input
    lv_textarea_set_text(ui_input, "");
}

void build_screen() {
    // Screen
    ui_screen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_screen, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_flex_flow(ui_screen, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_screen, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);

    // Top panel
    ui_panel = lv_obj_create(ui_screen);
    lv_obj_set_width(ui_panel, 320);
    lv_obj_set_height(ui_panel, 20);
    lv_obj_set_align(ui_panel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_panel, LV_OBJ_FLAG_SCROLLABLE);

    // Top panel left element
    ui_label_status_left = lv_label_create(ui_panel);
    lv_obj_set_width(ui_label_status_left, lv_pct(79));   /// 100
    lv_obj_set_height(ui_label_status_left, LV_SIZE_CONTENT);    /// 100
    lv_obj_set_x(ui_label_status_left, -41);
    lv_obj_set_y(ui_label_status_left, 0);
    lv_obj_set_align(ui_label_status_left, LV_ALIGN_CENTER);
    lv_label_set_text(ui_label_status_left, "build: ");
    lv_label_ins_text(ui_label_status_left, -1, __DATE__);
    lv_label_ins_text(ui_label_status_left, -1, " ");
    lv_label_ins_text(ui_label_status_left, -1, __TIME__);

    // Top panel right element
    ui_label_status_right = lv_label_create(ui_panel);
    lv_obj_set_width(ui_label_status_right, LV_SIZE_CONTENT);   /// 100
    lv_obj_set_height(ui_label_status_right, LV_SIZE_CONTENT);    /// 100
    lv_obj_set_x(ui_label_status_right, 135);
    lv_obj_set_y(ui_label_status_right, 0);
    lv_obj_set_align(ui_label_status_right, LV_ALIGN_CENTER);
    lv_label_set_text(ui_label_status_right, "069%");

    // Log
    // The container
    ui_history_container = lv_obj_create(ui_screen);
    lv_obj_set_size(ui_history_container, 320, 245);
    lv_obj_set_flex_flow(ui_history_container, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_scrollbar_mode(ui_history_container, LV_SCROLLBAR_MODE_AUTO);
    lv_obj_set_scroll_dir(ui_history_container, LV_DIR_VER);

    // The label itself
    ui_history = lv_label_create(ui_history_container);
    lv_obj_set_height(ui_history, 245);
    lv_obj_set_width(ui_history, lv_pct(99));
    lv_obj_set_align(ui_history, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_history, LV_LABEL_LONG_WRAP);
    lv_obj_add_style(ui_history, &font_12, 0);
    lv_label_set_text(ui_history, "");

    // Input
    ui_input = lv_textarea_create(ui_screen);
    lv_obj_set_width(ui_input, 320);
    lv_obj_set_height(ui_input, LV_SIZE_CONTENT);    /// 20
    lv_obj_set_x(ui_input, -10);
    lv_obj_set_y(ui_input, 91);
    lv_obj_set_align(ui_input, LV_ALIGN_CENTER);
    // Enable keyboard input for the text box
    lv_textarea_set_placeholder_text(ui_input, "1+1=69");
    lv_textarea_set_one_line(ui_input, true);
    lv_obj_set_style_anim_time(ui_input, 5000, LV_PART_CURSOR|LV_STATE_FOCUSED);
    // Textarea event handler
    lv_obj_add_event_cb(ui_input, textarea_event_handler, LV_EVENT_READY, ui_input);
}

void update_battery_level() {
    int bat_level = read_battery();
    if (bat_level > 100) {
        lv_label_set_text(ui_label_status_right, "ERR%");
    } else {
        lv_label_set_text_fmt(ui_label_status_right, "%i%%", bat_level);
    }
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

    lv_style_init(&font_12);
    lv_style_set_text_font(&font_12, &lv_font_montserrat_12);
    lv_style_init(&font_14);
    lv_style_set_text_font(&font_14, &lv_font_montserrat_14);

    // Build the screen
    build_screen();

    // Load the screen
    lv_scr_load(ui_screen);

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
            update_battery_level();
            last_ticks = lv_tick_get();
        }

        sleep_ms(1); // Sleep for 5 milliseconds}
    }
}

#include <main.h>
#include <utils.h>

void handle_textarea_command(const char *command_input) {
    printf("Got command: '%s'", command_input);

    if (strcmp(command_input, "flash") == 0) {
        // Reboot into flash mode
        reset_usb_boot(0, 0);
    } else if (strcmp(command_input, "uwu") == 0) {
        // UwU
        lv_label_ins_text(ui_history, -1, "\n*snuggle you :3*");
    } else if (strcmp(command_input, "reset") == 0) {
        // Soft reset
        *((volatile uint32_t *)(PPB_BASE + 0x0ED0C)) = 0x5FA0004;
    } else if (strcmp(command_input, "bat") == 0) {
        // Show battery level
        lv_label_ins_text(ui_history, -1, "\n");
        int bat_level = read_battery();
        if (bat_level > 100) {
            lv_label_ins_text(ui_history, -1, "ERR%");
        } else {
            char bat_buff[10];
            lv_snprintf(bat_buff, sizeof(bat_buff), "%i%%", bat_level);
            lv_label_ins_text(ui_history, -1, bat_buff);
        }
    } else if (strcmp(command_input, "help") == 0) {
        // Commands listing
        lv_label_ins_text(ui_history, -1, "\nhelp:");
        lv_label_ins_text(ui_history, -1, "\n  flash: reset in flash mode");
        lv_label_ins_text(ui_history, -1, "\n  reset: soft reset");
        lv_label_ins_text(ui_history, -1, "\n  bat: get battery level");
        lv_label_ins_text(ui_history, -1, "\n  uwu: ???");
        lv_label_ins_text(ui_history, -1, "\n  anything else will be fed to tinyexpr (he's hungry)");
    } else {
        // It's probably math, I hope
        int err = 0;
        double result = te_interp(sanitize_command(command_input), &err);

        lv_label_ins_text(ui_history, -1, "\n");
        // Max input plus 10 to be safe
        char buffer[MAX_INPUT_LENGTH+10];

        if (err != 0) {
            // Implement some visual error thingy with space padding
            lv_snprintf(buffer, sizeof(buffer), "  %*s^ err :(", err-1, " ");
            lv_label_ins_text(ui_history, -1, buffer);
        } else {
            // Now properly print/format the result
            if (round(result) == result) {
                // Print as rounded
                lv_snprintf(buffer, sizeof(buffer), "%i", (int)result);
            } else {
                // Print with all precision
                // TODO: how do I avoid trailing zeroes :(
                    lv_snprintf(buffer, sizeof(buffer), "%.*g", DBL_DECIMAL_DIG, result);
            }
            lv_label_ins_text(ui_history, -1, buffer);
        }
    }

    // Then scroll the history to the bottom
    // (it's borked)
    lv_obj_t *parent = lv_obj_get_parent(ui_history);
    printf("cur scroll: %i", lv_obj_get_scroll_bottom(parent));
    lv_obj_scroll_to_y(parent, lv_obj_get_scroll_bottom(parent), LV_ANIM_OFF);
}

static void textarea_event_handler(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target_obj(e);
    // Update history
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
    lv_obj_add_style(ui_history, &font_monospace, 0);
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
    lv_textarea_set_max_length(ui_input, MAX_INPUT_LENGTH);
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

    // Define font styles
    lv_style_init(&font_monospace);
    lv_style_set_text_font(&font_monospace, &font_terminus);

    // Build the screen
    build_screen();

    // Load the screen
    lv_scr_load(ui_screen);

    // First battery update
    update_battery_level();

    uint32_t last_1min_tick = lv_tick_get();

    // Main loop
    while (1) {
        lv_timer_handler();
        lv_tick_inc(5); // Increment LVGL tick by 5 milliseconds

        // Runs every ~minutes
        if (lv_tick_get()-last_1min_tick >= 60000) {
            printf("Tick: 1min");
            // Update the battery
            update_battery_level();

            // Then update the last 1min tick
            last_1min_tick = lv_tick_get();
        }

        sleep_ms(1); // Sleep for 5 milliseconds
    }
}

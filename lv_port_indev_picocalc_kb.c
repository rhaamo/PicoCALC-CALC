/**
 * @file lv_port_indev_templ.c
 *
 */

/*Copy this file as "lv_port_indev.c" and set this value to "1" to enable content*/

/*********************
 *      INCLUDES
 *********************/
#include "i2ckbd.h"
#include <stdio.h>
#include <string.h>
#include <pico/stdio.h>
#include "lv_port_indev_picocalc_kb.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void keypad_init(void);
static void keypad_read(lv_indev_t * indev, lv_indev_data_t * data);
static int keypad_get_key(void);


/**********************
 *  STATIC VARIABLES
 **********************/
lv_indev_t * indev_keypad;
static lv_group_t *g;  /* Group for keyboard navigation */

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_indev_init(void)
{
    /**
     * Here you will find example implementation of input devices supported by LittelvGL:
     *  - Touchpad
     *  - Mouse (with cursor support)
     *  - Keypad (supports GUI usage only with key)
     *  - Encoder (supports GUI usage only with: left, right, push)
     *  - Button (external buttons to press points on the screen)
     *
     *  The `..._read()` function are only examples.
     *  You should shape them according to your hardware
     */


    /*------------------
     * Keypad
     * -----------------*/

    keypad_init();

    /*Register a keypad input device*/
    indev_keypad = lv_indev_create();
    lv_indev_set_type(indev_keypad, LV_INDEV_TYPE_KEYPAD);
    lv_indev_set_read_cb(indev_keypad, keypad_read);

    /*Create a group for keyboard navigation*/
    g = lv_group_create();
    lv_group_set_default(g);
    lv_group_set_wrap(g, true);
    lv_indev_set_group(indev_keypad, g);

    /*
     * For keyboard navigation to work:
     * 1. Objects must be added to this group either:
     *    - Automatically if they support default grouping
     *    - Manually using lv_group_add_obj(g, obj)
     * 2. The group receives key events from the input device
     * 3. The group navigates focus among objects when arrow keys are pressed
     * 4. Focused objects receive other key events (like Enter)
     */
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void keypad_init(void)
{
    init_i2c_kbd();
}

static void keypad_read(lv_indev_t * indev_drv, lv_indev_data_t * data)
{
    static uint32_t last_key = 0;
    static bool pending_release = false;

    /* Check if we need to send a release event for the previous key */
    if(pending_release) {
        data->state = LV_INDEV_STATE_RELEASED;
        data->key = last_key;
        pending_release = false;
        return;
    }

    /*Get whether the a key is pressed and save the pressed key*/
    int r = keypad_get_key();
    
    if (r > 0) {
        printf("Key event %x\n", r);
        
        uint32_t act_key = 0;
        /*Translate the keys to LVGL control characters according to your key definitions*/
        switch(r) {
            case 0xb5:
                act_key = LV_KEY_NEXT;
                break;
            case 0xb6:
                act_key = LV_KEY_PREV;
                break;
            default:
                act_key = r;
                break;
        }

        data->state = LV_INDEV_STATE_PRESSED;
        data->key = act_key;
        last_key = act_key;
        pending_release = true;
    }
    else {
        data->state = LV_INDEV_STATE_RELEASED;
        data->key = 0;
    }
}

static int keypad_get_key(void)
{   
    int key_code = read_i2c_kbd();
    if (key_code < 0) {
        return 0;
    }
    
    return key_code;
}

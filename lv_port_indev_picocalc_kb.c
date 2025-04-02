/**
 * @file lv_port_indev_templ.c
 *
 */

/*Copy this file as "lv_port_indev.c" and set this value to "1" to enable content*/

/*********************
 *      INCLUDES
 *********************/
#include "lv_port_indev_picocalc_kb.h"
#include "core/lv_group.h"
#include "i2ckbd.h"
#include <pico/stdio.h>
#include <stdio.h>
#include <string.h>

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
static void keypad_read(lv_indev_t *indev, lv_indev_data_t *data);
static int keypad_get_key(void);

/**********************
 *  STATIC VARIABLES
 **********************/
lv_indev_t *indev_keypad;
static lv_group_t *g; /* Group for keyboard navigation */

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_indev_init(void) {
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

static void keypad_init(void) {
  init_i2c_kbd();
}

static void keypad_read(lv_indev_t *indev_drv, lv_indev_data_t *data) {
  static uint32_t last_key = 0;
  static bool pending_release = false;

  /* Check if we need to send a release event for the previous key */
  if (pending_release) {
    data->state = LV_INDEV_STATE_RELEASED;
    data->key = last_key;
    pending_release = false;
    return;
  }

  /*Get whether the a key is pressed and save the pressed key*/
  int r = keypad_get_key();

  uint32_t act_key = 0;
  if (r > 0) {
    printf("Key event %x\n", r);

    /* Translate the keys to LVGL control characters according to your key definitions */
    switch (r) {
      case 0xb5: // Arrow Up
        act_key = LV_KEY_UP;
        break;
      case 0xb6: // Arrow Down
        act_key = LV_KEY_DOWN;
        break;
      case 0xb4: // Arrow Left
        act_key = LV_KEY_LEFT;
        break;
      case 0xb7: // Arrow Right
        // printf("WARN: ARROW Left/Right key not mapped\n");
        act_key = LV_KEY_RIGHT;
        break;

      // Special Keys
      // Row 1
      case 0x81:
      case 0x82:
      case 0x83:
      case 0x84:
      case 0x85:
      case 0x86:
      case 0x87:
      case 0x88:
      case 0x89:
      case 0x90: // F1-F10 Keys
        printf("WARN: Function keys not mapped\n");
        act_key = 0;
        break;

      // Row 2
      case 0xB1: // ESC
        act_key = LV_KEY_ESC;
        break;
      case 0x09: // TAB
        printf("WARN: Tab key not mapped\n");
        act_key = 0;
        break;
      case 0xC1: // Caps Lock
        printf("WARN: CapLock key not mapped\n");
        act_key = 0;
        break;
      case 0xD4: // DEL
        act_key = LV_KEY_DEL;
        break;
      case 0x08: // Backspace
        act_key = LV_KEY_BACKSPACE;
        break;

      // Row 2 Layer2
      case 0xD0: // brk
        printf("WARN: Brk key not mapped\n");
        act_key = 0;
        break;
      case 0xD2: // Home
        act_key = LV_KEY_HOME;
        break;
      case 0xD5: // End
        act_key = LV_KEY_END;
        break;

      // Row 3
      case 0x60:
      case 0x2F:
      case 0x5C:
      case 0x2D:
      case 0x3D:
      case 0x5B:
      case 0x5D: // `/\-=[] Keys
        act_key = r;
        break;

      // Row 3 Layer2
      case 0x7E:
        act_key = '~';
        break;
      case 0x3F:
        act_key = '?';
        break;
      case 0x7C:
        act_key = '|';
        break;
      case 0x5F:
        act_key = '_';
        break;
      case 0x2B:
        act_key = '+';
        break;
      case 0x7B:
        act_key = '{';
        break;
      case 0x7D:
        act_key = '}';
        break;

      // Row 4
      case 0x30:
      case 0x31:
      case 0x32:
      case 0x33:
      case 0x34:
      case 0x35:
      case 0x36:
      case 0x37:
      case 0x38:
      case 0x39: // 0-9 Keys
        act_key = r;
        break;

      // Row 4 Layer2
      case 0x21:
      case 0x40:
      case 0x23:
      case 0x24:
      case 0x25:
      case 0x5E:
      case 0x26:
      case 0x2A:
      case 0x28:
      case 0x29: // !@#$%^&*() Keys
        act_key = r;
        break;

      // Row 5 Layer2
      case 0xD1: // Insert
        printf("WARN: Insert key not mapped\n");
        act_key = 0;
        break;

      // Row 7 Layer 2
      case 0x3C:
        act_key = '<';
        break;
      case 0x3E:
        act_key = '>';
        break;

      // Row 8
      case 0x3B:
      case 0x27:
      case 0x3A:
      case 0x22: // ;:'"" Keys
        act_key = r;
        break;
      case 0xA5: // CTL
        printf("WARN: CTL key not mapped\n");
        act_key = 0;
        break;
      case 0x20: // SPACE
        act_key = r;
        break;
      case 0xA1: // ALT
        printf("WARN: ALT key not mapped\n");
        act_key = 0;
        break;
      case 0xA2:
      case 0xA3: // RIGHT/LEFT SHIFT
        break;

      default:
        act_key = r;
        break;
    }

    data->state = LV_INDEV_STATE_PRESSED;
    data->key = act_key;
    last_key = act_key;
    pending_release = true;
  } else {
    data->state = LV_INDEV_STATE_RELEASED;
    data->key = 0;
  }
}

static int keypad_get_key(void) {
  int key_code = read_i2c_kbd();
  if (key_code < 0) {
    return 0;
  }

  return key_code;
}
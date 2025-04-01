/**
 * @file lv_conf.h
 * Configuration file for LVGL v8.3.0
 * 
 * Author: LVGL, Hsuan Han Lai
 * Date: 2025-03-31
 * Description: LVGL configuration file for the PicoCalc (Raspberry Pi Pico with ILI9488 display)
 * 
 */

 #ifndef LV_CONF_H
 #define LV_CONF_H
 
 #include <stdint.h>
 
 /*====================
    COLOR SETTINGS
  *====================*/
 #define LV_COLOR_DEPTH 16      /*16-bit color depth*/
 #define LV_COLOR_16_SWAP 0
 #define LV_COLOR_MIX_ROUND_OFS (128)
 
 /*====================
    MEMORY SETTINGS
  *====================*/
 #define LV_MEM_SIZE (48 * 1024U)    /*48KB memory pool*/
 #define LV_MEM_CUSTOM 0
 
 /*====================
    HAL SETTINGS
  *====================*/
 #define LV_TICK_CUSTOM 0
 #if LV_TICK_CUSTOM
     #define LV_TICK_CUSTOM_INCLUDE "pico/stdlib.h"
     #define LV_TICK_CUSTOM_SYS_TIME_EXPR (to_ms_since_boot(get_absolute_time()))
 #endif
 
 /*====================
    DISPLAY SETTINGS
  *====================*/
 #define LV_HOR_RES_MAX 320      /*ILI9488 typical width (when oriented vertically)*/
 #define LV_VER_RES_MAX 320      /*ILI9488 typical height*/
 
 /* Use 2 buffers (1/10 screen size) */
 #define LV_DISP_DOUBLE_BUFFER 0
 #define LV_DISP_BUF_SIZE (LV_HOR_RES_MAX * LV_VER_RES_MAX / 10)
 
 /*===================
  * INPUT DEVICE SETTINGS
  *===================*/
 #define LV_INDEV_DEF_READ_PERIOD 30
 
 /*===================
  * FEATURE CONFIGURATION
  *===================*/
 #define LV_USE_ASSERT_NULL 1
 #define LV_USE_ASSERT_MALLOC 1
 #define LV_USE_LOG 1
 #if LV_USE_LOG
     #define LV_LOG_PRINTF 1
 #endif
 
 /*===================
  * FONT USAGE
  *===================*/
 #define LV_FONT_MONTSERRAT_12 1
 #define LV_FONT_MONTSERRAT_14 1
 #define LV_FONT_DEFAULT &lv_font_montserrat_14
 
 /*===================
  * THEME USAGE
  *===================*/
 #define LV_USE_THEME_DEFAULT 1
 
 /*===================
  * WIDGET USAGE
  *===================*/
 #define LV_USE_LABEL 1
 #define LV_USE_BTN 1
 #define LV_USE_SLIDER 1
 #define LV_USE_IMG 1
 #define LV_USE_ARC       1
 #define LV_USE_BAR       1
 #define LV_USE_CHART     1
 #define LV_USE_CHECKBOX  1
 #define LV_USE_DROPDOWN  1
 #define LV_USE_LINE      1
 #define LV_USE_ROLLER    1
 #define LV_USE_SWITCH    1
 #define LV_USE_TABLE     1
 #define LV_USE_TEXTAREA  1
 #define LV_USE_TABVIEW 1
 /* Add other widgets as needed */
 
 /*===================
  * LAYOUT USAGE
  *===================*/
 #define LV_USE_GRID 1
 #define LV_USE_FLEX 1

/*===================
  * ANIMATION SETTINGS
  *===================*/
#define LV_USE_ANIMATION 0
#define LV_USE_ANIM_IMG 0
#define LV_USE_ANIM_SCALE 0
#define LV_USE_ANIM_PATH 0
#define LV_USE_ANIM_TIMELINE 0
#define LV_USE_ANIM_CUSTOM 0
#define LV_USE_ANIM_REPEAT 0
#define LV_USE_ANIM_PAUSE 0
#define LV_USE_ANIM_REVERSE 0
#define LV_USE_ANIM_DELAY 0
#define LV_USE_ANIM_SPEED 0

 /*===================
 * DEMO USAGE
 ====================*/

/* Show some widget. It might be required to increase `LV_MEM_SIZE` */
#define LV_USE_DEMO_WIDGETS        1

/* Demonstrate the usage of encoder and keyboard */
#define LV_USE_DEMO_KEYPAD_AND_ENCODER     0

/* Benchmark your system */
#define LV_USE_DEMO_BENCHMARK   0

/* Stress test for LVGL */
#define LV_USE_DEMO_STRESS      0

/* Music player demo */
#define LV_USE_DEMO_MUSIC       0
#if LV_USE_DEMO_MUSIC
# define LV_DEMO_MUSIC_SQUARE       0
# define LV_DEMO_MUSIC_LANDSCAPE    0
# define LV_DEMO_MUSIC_ROUND        0
# define LV_DEMO_MUSIC_LARGE        0
# define LV_DEMO_MUSIC_AUTO_PLAY    0
#endif

/* Flex layout demo */
#define LV_USE_DEMO_FLEX_LAYOUT     0

/* Smart-phone like multi-language demo */
#define LV_USE_DEMO_MULTILANG       0

/* Widget transformation demo */
#define LV_USE_DEMO_TRANSFORM       0

/* Demonstrate scroll settings */
#define LV_USE_DEMO_SCROLL          0

 
 /*==================
  * COMPILER SETTINGS
  *==================*/
 #ifdef __cplusplus
     #define LV_EXTERN_C extern "C"
 #else
     #define LV_EXTERN_C
 #endif
 
 #endif  /*LV_CONF_H*/

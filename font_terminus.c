/*******************************************************************************
 * Size: 14 px
 * Bpp: 1
 * Opts: --bpp 1 --size 14 --no-compress --font Terminus.ttf --range 32-127,160-255 --font FontAwesome5-Solid+Brands+Regular.woff --symbols 61441,61448,61451,61452,61452,61453,61457,61459,61461,61465,61468,61473,61478,61479,61480,61502,61512,61515,61516,61517,61521,61522,61523,61524,61543,61544,61550,61552,61553,61556,61559,61560,61561,61563,61587,61589,61636,61637,61639,61671,61674,61683,61724,61732,61787,61931,62016,62017,62018,62019,62020,62087,62099,62212,62189,62810,63426,63650 --format lvgl -o font_terminus.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef FONT_TERMINUS
#define FONT_TERMINUS 1
#endif

#if FONT_TERMINUS

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xfe, 0xc0,

    /* U+0022 "\"" */
    0x99, 0x90,

    /* U+0023 "#" */
    0x49, 0x24, 0xbf, 0x49, 0x2f, 0xd2, 0x49, 0x20,

    /* U+0024 "$" */
    0x10, 0x21, 0xf4, 0x99, 0x12, 0x1f, 0x9, 0x13,
    0x25, 0xf0, 0x81, 0x0,

    /* U+0025 "%" */
    0x65, 0x29, 0xa0, 0x41, 0x2, 0x8, 0x16, 0x52,
    0x98,

    /* U+0026 "&" */
    0x31, 0x24, 0x8c, 0x62, 0x58, 0xa2, 0x89, 0xd0,

    /* U+0027 "'" */
    0x58,

    /* U+0028 "(" */
    0x2a, 0x49, 0x24, 0x44,

    /* U+0029 ")" */
    0x88, 0x92, 0x49, 0x50,

    /* U+002A "*" */
    0x48, 0xcf, 0xcc, 0x48,

    /* U+002B "+" */
    0x21, 0x3e, 0x42, 0x0,

    /* U+002D "-" */
    0xfc,

    /* U+002E "." */
    0xc0,

    /* U+002F "/" */
    0x8, 0x44, 0x22, 0x11, 0x8, 0x84, 0x0,

    /* U+0030 "0" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x44,
    0x70,

    /* U+0031 "1" */
    0x27, 0x8, 0x42, 0x10, 0x84, 0x27, 0xc0,

    /* U+0032 "2" */
    0x7a, 0x10, 0x41, 0x8, 0x63, 0x18, 0x43, 0xf0,

    /* U+0033 "3" */
    0x7a, 0x10, 0x41, 0x38, 0x30, 0x41, 0x8d, 0xe0,

    /* U+0034 "4" */
    0x4, 0xc, 0xc, 0x14, 0x24, 0x24, 0x44, 0xff,
    0x4, 0x4,

    /* U+0035 "5" */
    0xfe, 0x8, 0x3e, 0x8c, 0x10, 0x41, 0x89, 0xe0,

    /* U+0036 "6" */
    0x3c, 0x86, 0x5, 0xec, 0x50, 0x60, 0xc1, 0x44,
    0x78,

    /* U+0037 "7" */
    0xfe, 0xc, 0x10, 0x60, 0x83, 0x4, 0x10, 0x20,
    0x80,

    /* U+0038 "8" */
    0x7d, 0x8e, 0xc, 0x14, 0x4f, 0xa0, 0xc1, 0xc6,
    0xf8,

    /* U+0039 "9" */
    0x79, 0x8a, 0xc, 0x1c, 0x6f, 0x40, 0x83, 0x84,
    0xf0,

    /* U+003A ":" */
    0xc6,

    /* U+003B ";" */
    0x50, 0x16,

    /* U+003C "<" */
    0x8, 0x88, 0x88, 0x20, 0x82, 0x8,

    /* U+003D "=" */
    0xfc, 0x0, 0x3f,

    /* U+003E ">" */
    0x82, 0x8, 0x20, 0x88, 0x88, 0x80,

    /* U+003F "?" */
    0x7a, 0x18, 0x61, 0x8, 0x41, 0x0, 0x10, 0x40,

    /* U+0040 "@" */
    0x7d, 0x6, 0x7d, 0x1a, 0x34, 0x69, 0xcd, 0x80,
    0xfc,

    /* U+0041 "A" */
    0x7a, 0x18, 0x61, 0x87, 0xf8, 0x61, 0x86, 0x10,

    /* U+0042 "B" */
    0xfa, 0x18, 0x61, 0xfa, 0x18, 0x61, 0x87, 0xe0,

    /* U+0043 "C" */
    0x7a, 0x18, 0x60, 0x82, 0x8, 0x21, 0x85, 0xe0,

    /* U+0044 "D" */
    0xf2, 0x28, 0x61, 0x86, 0x18, 0x61, 0x8b, 0xc0,

    /* U+0045 "E" */
    0xfe, 0x8, 0x20, 0xf2, 0x8, 0x20, 0x83, 0xf0,

    /* U+0046 "F" */
    0xfe, 0x8, 0x20, 0xf2, 0x8, 0x20, 0x82, 0x0,

    /* U+0047 "G" */
    0x7a, 0x18, 0x60, 0x82, 0x78, 0x61, 0x85, 0xe0,

    /* U+0048 "H" */
    0x86, 0x18, 0x61, 0xfe, 0x18, 0x61, 0x86, 0x10,

    /* U+0049 "I" */
    0xe9, 0x24, 0x92, 0x5c,

    /* U+004A "J" */
    0x1c, 0x20, 0x82, 0x8, 0x20, 0xa2, 0x89, 0xc0,

    /* U+004B "K" */
    0x86, 0x29, 0x28, 0xc3, 0xa, 0x24, 0x8a, 0x10,

    /* U+004C "L" */
    0x82, 0x8, 0x20, 0x82, 0x8, 0x20, 0x83, 0xf0,

    /* U+004D "M" */
    0x83, 0x8e, 0xac, 0x98, 0x30, 0x60, 0xc1, 0x83,
    0x4,

    /* U+004E "N" */
    0x86, 0x18, 0x71, 0xa6, 0x58, 0xe1, 0x86, 0x10,

    /* U+004F "O" */
    0x7a, 0x18, 0x61, 0x86, 0x18, 0x61, 0x85, 0xe0,

    /* U+0050 "P" */
    0xfa, 0x18, 0x61, 0x87, 0xe8, 0x20, 0x82, 0x0,

    /* U+0051 "Q" */
    0x7a, 0x18, 0x61, 0x86, 0x18, 0x61, 0x95, 0xe0,
    0x40,

    /* U+0052 "R" */
    0xfa, 0x18, 0x61, 0x87, 0xea, 0x24, 0x8a, 0x10,

    /* U+0053 "S" */
    0x7a, 0x18, 0x20, 0x78, 0x10, 0x61, 0x85, 0xe0,

    /* U+0054 "T" */
    0xfe, 0x20, 0x40, 0x81, 0x2, 0x4, 0x8, 0x10,
    0x20,

    /* U+0055 "U" */
    0x86, 0x18, 0x61, 0x86, 0x18, 0x61, 0x85, 0xe0,

    /* U+0056 "V" */
    0x86, 0x18, 0x61, 0x85, 0x24, 0x92, 0x30, 0xc0,

    /* U+0057 "W" */
    0x83, 0x6, 0xc, 0x18, 0x30, 0x64, 0xd5, 0xc7,
    0x4,

    /* U+0058 "X" */
    0x86, 0x14, 0x92, 0x30, 0xc4, 0x92, 0x86, 0x10,

    /* U+0059 "Y" */
    0x83, 0x5, 0x12, 0x22, 0x82, 0x4, 0x8, 0x10,
    0x20,

    /* U+005A "Z" */
    0xfc, 0x10, 0x42, 0x10, 0x84, 0x20, 0x83, 0xf0,

    /* U+005B "[" */
    0xf2, 0x49, 0x24, 0x9c,

    /* U+005C "\\" */
    0x84, 0x10, 0x82, 0x10, 0x42, 0x8, 0x40,

    /* U+005D "]" */
    0xe4, 0x92, 0x49, 0x3c,

    /* U+005E "^" */
    0x22, 0xa2,

    /* U+005F "_" */
    0xfc,

    /* U+0060 "`" */
    0xa4,

    /* U+0061 "a" */
    0x78, 0x17, 0xe1, 0x86, 0x17, 0xc0,

    /* U+0062 "b" */
    0x82, 0x8, 0x3e, 0x86, 0x18, 0x61, 0x87, 0xe0,

    /* U+0063 "c" */
    0x7a, 0x18, 0x20, 0x82, 0x17, 0x80,

    /* U+0064 "d" */
    0x4, 0x10, 0x5f, 0x86, 0x18, 0x61, 0x85, 0xf0,

    /* U+0065 "e" */
    0x7a, 0x18, 0x7f, 0x82, 0x7, 0x80,

    /* U+0066 "f" */
    0x1c, 0x82, 0x3e, 0x20, 0x82, 0x8, 0x20, 0x80,

    /* U+0067 "g" */
    0x7e, 0x18, 0x61, 0x86, 0x17, 0xc1, 0x78,

    /* U+0068 "h" */
    0x82, 0x8, 0x3e, 0x86, 0x18, 0x61, 0x86, 0x10,

    /* U+0069 "i" */
    0x48, 0x64, 0x92, 0x5c,

    /* U+006A "j" */
    0x8, 0x40, 0x30, 0x84, 0x21, 0xc, 0x62, 0xe0,

    /* U+006B "k" */
    0x82, 0x8, 0x21, 0x8a, 0x4e, 0x24, 0x8a, 0x10,

    /* U+006C "l" */
    0xc9, 0x24, 0x92, 0x5c,

    /* U+006D "m" */
    0xfd, 0x26, 0x4c, 0x99, 0x32, 0x64, 0x80,

    /* U+006E "n" */
    0xfa, 0x18, 0x61, 0x86, 0x18, 0x40,

    /* U+006F "o" */
    0x7a, 0x18, 0x61, 0x86, 0x17, 0x80,

    /* U+0070 "p" */
    0xfa, 0x18, 0x61, 0x86, 0x1f, 0xa0, 0x80,

    /* U+0071 "q" */
    0x7e, 0x18, 0x61, 0x86, 0x17, 0xc1, 0x4,

    /* U+0072 "r" */
    0xbf, 0x8, 0x20, 0x82, 0x8, 0x0,

    /* U+0073 "s" */
    0x7e, 0x8, 0x1e, 0x4, 0x1f, 0x80,

    /* U+0074 "t" */
    0x20, 0x82, 0x3e, 0x20, 0x82, 0x8, 0x20, 0x70,

    /* U+0075 "u" */
    0x86, 0x18, 0x61, 0x86, 0x17, 0xc0,

    /* U+0076 "v" */
    0x86, 0x18, 0x52, 0x48, 0xc3, 0x0,

    /* U+0077 "w" */
    0x83, 0x6, 0x4c, 0x99, 0x32, 0x5f, 0x0,

    /* U+0078 "x" */
    0x86, 0x14, 0x8c, 0x4a, 0x18, 0x40,

    /* U+0079 "y" */
    0x86, 0x18, 0x61, 0x86, 0x17, 0xc1, 0x78,

    /* U+007A "z" */
    0xfc, 0x21, 0x8, 0x42, 0xf, 0xc0,

    /* U+007B "{" */
    0x34, 0x44, 0x84, 0x44, 0x43,

    /* U+007C "|" */
    0xff, 0xc0,

    /* U+007D "}" */
    0xc2, 0x22, 0x12, 0x22, 0x2c,

    /* U+007E "~" */
    0x63, 0x26, 0x30,

    /* U+00A0 " " */
    0x0,

    /* U+00A1 "¡" */
    0xdf, 0xc0,

    /* U+00A2 "¢" */
    0x10, 0x21, 0xf4, 0x99, 0x12, 0x24, 0x49, 0x7c,
    0x20, 0x40,

    /* U+00A3 "£" */
    0x31, 0x24, 0x10, 0xf1, 0x4, 0x10, 0x47, 0xf0,

    /* U+00A4 "¤" */
    0x8b, 0xa3, 0x18, 0xba, 0x20,

    /* U+00A5 "¥" */
    0x83, 0x5, 0x11, 0x41, 0xf, 0x84, 0x3e, 0x10,
    0x20,

    /* U+00A6 "¦" */
    0xf3, 0xc0,

    /* U+00A7 "§" */
    0x74, 0x60, 0xc9, 0x46, 0x29, 0x30, 0x62, 0xe0,

    /* U+00A8 "¨" */
    0x99,

    /* U+00A9 "©" */
    0x7e, 0x81, 0x99, 0xa5, 0xa1, 0xa5, 0x99, 0x81,
    0x7e,

    /* U+00AA "ª" */
    0x70, 0x5f, 0x17, 0x83, 0xe0,

    /* U+00AB "«" */
    0x12, 0x49, 0x24, 0x84, 0x84, 0x84, 0x80,

    /* U+00AC "¬" */
    0xfc, 0x10, 0x40,

    /* U+00AD "­" */
    0xf0,

    /* U+00AE "®" */
    0x7e, 0x81, 0xb9, 0xa5, 0xb9, 0xa9, 0xa5, 0x81,
    0x7e,

    /* U+00AF "¯" */
    0xf8,

    /* U+00B0 "°" */
    0x69, 0x96,

    /* U+00B1 "±" */
    0x21, 0x3e, 0x42, 0x0, 0x1f,

    /* U+00B2 "²" */
    0x69, 0x24, 0xf0,

    /* U+00B3 "³" */
    0xe1, 0x61, 0xe0,

    /* U+00B4 "´" */
    0x60,

    /* U+00B5 "µ" */
    0x86, 0x18, 0x61, 0x86, 0x3f, 0x60, 0x80,

    /* U+00B6 "¶" */
    0x7f, 0x26, 0x4c, 0x99, 0x2e, 0x44, 0x89, 0x12,
    0x24,

    /* U+00B7 "·" */
    0xc0,

    /* U+00B8 "¸" */
    0x58,

    /* U+00B9 "¹" */
    0x75, 0x40,

    /* U+00BA "º" */
    0x74, 0x63, 0x17, 0x3, 0xe0,

    /* U+00BB "»" */
    0x90, 0x90, 0x90, 0x92, 0x49, 0x24, 0x0,

    /* U+00BC "¼" */
    0x20, 0xc0, 0x81, 0x12, 0x41, 0x4, 0x11, 0x47,
    0x14, 0x78, 0x10, 0x20,

    /* U+00BD "½" */
    0x20, 0xc0, 0x81, 0x12, 0x41, 0x4, 0x10, 0x4d,
    0x24, 0x10, 0x41, 0xe0,

    /* U+00BE "¾" */
    0xe0, 0x21, 0x80, 0x9e, 0x41, 0x4, 0x11, 0x47,
    0x14, 0x78, 0x10, 0x20,

    /* U+00BF "¿" */
    0x20, 0x80, 0x8, 0x21, 0x8, 0x61, 0x85, 0xe0,

    /* U+00C0 "À" */
    0x40, 0x80, 0x1e, 0x86, 0x18, 0x7f, 0x86, 0x18,
    0x61,

    /* U+00C1 "Á" */
    0x8, 0x40, 0x1e, 0x86, 0x18, 0x7f, 0x86, 0x18,
    0x61,

    /* U+00C2 "Â" */
    0x31, 0x20, 0x1e, 0x86, 0x18, 0x7f, 0x86, 0x18,
    0x61,

    /* U+00C3 "Ã" */
    0x66, 0x60, 0x1e, 0x86, 0x18, 0x7f, 0x86, 0x18,
    0x61,

    /* U+00C4 "Ä" */
    0x49, 0x20, 0x1e, 0x86, 0x18, 0x7f, 0x86, 0x18,
    0x61,

    /* U+00C5 "Å" */
    0x31, 0x23, 0x1e, 0x86, 0x18, 0x7f, 0x86, 0x18,
    0x61,

    /* U+00C6 "Æ" */
    0x7f, 0x22, 0x44, 0x8f, 0xd2, 0x24, 0x48, 0x91,
    0x3c,

    /* U+00C7 "Ç" */
    0x7a, 0x18, 0x60, 0x82, 0x8, 0x21, 0x85, 0xe2,
    0x10,

    /* U+00C8 "È" */
    0x40, 0x80, 0x3f, 0x82, 0x8, 0x3c, 0x82, 0x8,
    0x3f,

    /* U+00C9 "É" */
    0x8, 0x40, 0x3f, 0x82, 0x8, 0x3c, 0x82, 0x8,
    0x3f,

    /* U+00CA "Ê" */
    0x31, 0x20, 0x3f, 0x82, 0x8, 0x3c, 0x82, 0x8,
    0x3f,

    /* U+00CB "Ë" */
    0x49, 0x20, 0x3f, 0x82, 0x8, 0x3c, 0x82, 0x8,
    0x3f,

    /* U+00CC "Ì" */
    0x88, 0x74, 0x92, 0x49, 0x70,

    /* U+00CD "Í" */
    0x28, 0x74, 0x92, 0x49, 0x70,

    /* U+00CE "Î" */
    0x69, 0x7, 0x22, 0x22, 0x22, 0x27,

    /* U+00CF "Ï" */
    0x8c, 0x40, 0xe2, 0x10, 0x84, 0x21, 0x8, 0xe0,

    /* U+00D0 "Ð" */
    0x78, 0x89, 0xa, 0x1f, 0x28, 0x50, 0xa1, 0x44,
    0xf0,

    /* U+00D1 "Ñ" */
    0x66, 0x60, 0x21, 0x87, 0x1a, 0x65, 0x8e, 0x18,
    0x61,

    /* U+00D2 "Ò" */
    0x40, 0x80, 0x1e, 0x86, 0x18, 0x61, 0x86, 0x18,
    0x5e,

    /* U+00D3 "Ó" */
    0x8, 0x40, 0x1e, 0x86, 0x18, 0x61, 0x86, 0x18,
    0x5e,

    /* U+00D4 "Ô" */
    0x31, 0x20, 0x1e, 0x86, 0x18, 0x61, 0x86, 0x18,
    0x5e,

    /* U+00D5 "Õ" */
    0x66, 0x60, 0x1e, 0x86, 0x18, 0x61, 0x86, 0x18,
    0x5e,

    /* U+00D6 "Ö" */
    0x49, 0x20, 0x1e, 0x86, 0x18, 0x61, 0x86, 0x18,
    0x5e,

    /* U+00D7 "×" */
    0x85, 0x23, 0x12, 0x84,

    /* U+00D8 "Ø" */
    0x5, 0xd8, 0xa3, 0x96, 0x5a, 0x69, 0xc5, 0x1b,
    0xa0,

    /* U+00D9 "Ù" */
    0x40, 0x88, 0x61, 0x86, 0x18, 0x61, 0x86, 0x18,
    0x5e,

    /* U+00DA "Ú" */
    0x8, 0x48, 0x61, 0x86, 0x18, 0x61, 0x86, 0x18,
    0x5e,

    /* U+00DB "Û" */
    0x31, 0x20, 0x21, 0x86, 0x18, 0x61, 0x86, 0x18,
    0x5e,

    /* U+00DC "Ü" */
    0x49, 0x20, 0x21, 0x86, 0x18, 0x61, 0x86, 0x18,
    0x5e,

    /* U+00DD "Ý" */
    0x8, 0x22, 0xc, 0x14, 0x48, 0x8a, 0x8, 0x10,
    0x20, 0x40, 0x80,

    /* U+00DE "Þ" */
    0x82, 0xf, 0xa1, 0x86, 0x18, 0x7e, 0x82, 0x0,

    /* U+00DF "ß" */
    0x72, 0x28, 0xa4, 0xfa, 0x18, 0x61, 0xc6, 0xe0,

    /* U+00E0 "à" */
    0x40, 0x80, 0x1e, 0x5, 0xf8, 0x61, 0x85, 0xf0,

    /* U+00E1 "á" */
    0x8, 0x40, 0x1e, 0x5, 0xf8, 0x61, 0x85, 0xf0,

    /* U+00E2 "â" */
    0x31, 0x20, 0x1e, 0x5, 0xf8, 0x61, 0x85, 0xf0,

    /* U+00E3 "ã" */
    0x66, 0x60, 0x1e, 0x5, 0xf8, 0x61, 0x85, 0xf0,

    /* U+00E4 "ä" */
    0x49, 0x20, 0x1e, 0x5, 0xf8, 0x61, 0x85, 0xf0,

    /* U+00E5 "å" */
    0x31, 0x23, 0x1e, 0x5, 0xf8, 0x61, 0x85, 0xf0,

    /* U+00E6 "æ" */
    0x6c, 0x25, 0xcc, 0xf9, 0x12, 0x1b, 0x0,

    /* U+00E7 "ç" */
    0x7a, 0x18, 0x20, 0x82, 0x17, 0x88, 0x40,

    /* U+00E8 "è" */
    0x40, 0x80, 0x1e, 0x86, 0x1f, 0xe0, 0x81, 0xe0,

    /* U+00E9 "é" */
    0x8, 0x40, 0x1e, 0x86, 0x1f, 0xe0, 0x81, 0xe0,

    /* U+00EA "ê" */
    0x31, 0x20, 0x1e, 0x86, 0x1f, 0xe0, 0x81, 0xe0,

    /* U+00EB "ë" */
    0x49, 0x20, 0x1e, 0x86, 0x1f, 0xe0, 0x81, 0xe0,

    /* U+00EC "ì" */
    0x88, 0x64, 0x92, 0x5c,

    /* U+00ED "í" */
    0x28, 0x64, 0x92, 0x5c,

    /* U+00EE "î" */
    0x69, 0x6, 0x22, 0x22, 0x27,

    /* U+00EF "ï" */
    0x99, 0x6, 0x22, 0x22, 0x27,

    /* U+00F0 "ð" */
    0x50, 0x85, 0x1e, 0x86, 0x18, 0x61, 0x85, 0xe0,

    /* U+00F1 "ñ" */
    0x66, 0x60, 0x3e, 0x86, 0x18, 0x61, 0x86, 0x10,

    /* U+00F2 "ò" */
    0x40, 0x80, 0x1e, 0x86, 0x18, 0x61, 0x85, 0xe0,

    /* U+00F3 "ó" */
    0x8, 0x40, 0x1e, 0x86, 0x18, 0x61, 0x85, 0xe0,

    /* U+00F4 "ô" */
    0x31, 0x20, 0x1e, 0x86, 0x18, 0x61, 0x85, 0xe0,

    /* U+00F5 "õ" */
    0x66, 0x60, 0x1e, 0x86, 0x18, 0x61, 0x85, 0xe0,

    /* U+00F6 "ö" */
    0x49, 0x20, 0x1e, 0x86, 0x18, 0x61, 0x85, 0xe0,

    /* U+00F7 "÷" */
    0x21, 0x1, 0xf0, 0x10, 0x80,

    /* U+00F8 "ø" */
    0x2, 0x79, 0x1a, 0x55, 0x2c, 0x50, 0xde,

    /* U+00F9 "ù" */
    0x40, 0x80, 0x21, 0x86, 0x18, 0x61, 0x85, 0xf0,

    /* U+00FA "ú" */
    0x8, 0x40, 0x21, 0x86, 0x18, 0x61, 0x85, 0xf0,

    /* U+00FB "û" */
    0x31, 0x20, 0x21, 0x86, 0x18, 0x61, 0x85, 0xf0,

    /* U+00FC "ü" */
    0x49, 0x20, 0x21, 0x86, 0x18, 0x61, 0x85, 0xf0,

    /* U+00FD "ý" */
    0x8, 0x40, 0x21, 0x86, 0x18, 0x61, 0x85, 0xf0,
    0x5e,

    /* U+00FE "þ" */
    0x82, 0x8, 0x3e, 0x86, 0x18, 0x61, 0xfa, 0x8,
    0x20,

    /* U+00FF "ÿ" */
    0x49, 0x20, 0x21, 0x86, 0x18, 0x61, 0x85, 0xf0,
    0x5e
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 112, .box_w = 1, .box_h = 1, .ofs_x = 7, .ofs_y = -2},
    {.bitmap_index = 1, .adv_w = 112, .box_w = 1, .box_h = 10, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 112, .box_w = 4, .box_h = 3, .ofs_x = 2, .ofs_y = 8},
    {.bitmap_index = 5, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 13, .adv_w = 112, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 25, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 34, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 42, .adv_w = 112, .box_w = 2, .box_h = 3, .ofs_x = 2, .ofs_y = 8},
    {.bitmap_index = 43, .adv_w = 112, .box_w = 3, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 47, .adv_w = 112, .box_w = 3, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 51, .adv_w = 112, .box_w = 6, .box_h = 5, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 55, .adv_w = 112, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 59, .adv_w = 112, .box_w = 6, .box_h = 1, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 60, .adv_w = 112, .box_w = 1, .box_h = 2, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 61, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 68, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 77, .adv_w = 147, .box_w = 5, .box_h = 10, .ofs_x = 2, .ofs_y = 2},
    {.bitmap_index = 84, .adv_w = 136, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 92, .adv_w = 130, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 100, .adv_w = 138, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 110, .adv_w = 141, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 118, .adv_w = 136, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 127, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 136, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 145, .adv_w = 133, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 154, .adv_w = 112, .box_w = 1, .box_h = 7, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 155, .adv_w = 112, .box_w = 2, .box_h = 8, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 157, .adv_w = 112, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 163, .adv_w = 112, .box_w = 6, .box_h = 4, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 166, .adv_w = 112, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 172, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 180, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 189, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 197, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 205, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 213, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 221, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 229, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 237, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 245, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 253, .adv_w = 112, .box_w = 3, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 257, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 265, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 273, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 281, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 290, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 298, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 306, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 314, .adv_w = 112, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 323, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 331, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 339, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 348, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 356, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 364, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 373, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 381, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 390, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 398, .adv_w = 112, .box_w = 3, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 402, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 409, .adv_w = 112, .box_w = 3, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 413, .adv_w = 112, .box_w = 5, .box_h = 3, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 415, .adv_w = 112, .box_w = 6, .box_h = 1, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 416, .adv_w = 112, .box_w = 2, .box_h = 3, .ofs_x = 3, .ofs_y = 8},
    {.bitmap_index = 417, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 423, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 431, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 437, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 445, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 451, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 459, .adv_w = 112, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 466, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 474, .adv_w = 112, .box_w = 3, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 478, .adv_w = 112, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 486, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 494, .adv_w = 112, .box_w = 3, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 498, .adv_w = 112, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 505, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 511, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 517, .adv_w = 112, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 524, .adv_w = 112, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 531, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 537, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 543, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 551, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 557, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 563, .adv_w = 112, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 570, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 576, .adv_w = 112, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 583, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 589, .adv_w = 112, .box_w = 4, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 594, .adv_w = 112, .box_w = 1, .box_h = 10, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 596, .adv_w = 112, .box_w = 4, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 601, .adv_w = 112, .box_w = 7, .box_h = 3, .ofs_x = 0, .ofs_y = 8},
    {.bitmap_index = 604, .adv_w = 112, .box_w = 1, .box_h = 1, .ofs_x = 7, .ofs_y = -2},
    {.bitmap_index = 605, .adv_w = 112, .box_w = 1, .box_h = 10, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 607, .adv_w = 112, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 617, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 625, .adv_w = 112, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 630, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 639, .adv_w = 112, .box_w = 1, .box_h = 10, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 641, .adv_w = 112, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 649, .adv_w = 112, .box_w = 4, .box_h = 2, .ofs_x = 2, .ofs_y = 10},
    {.bitmap_index = 650, .adv_w = 112, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 659, .adv_w = 112, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 664, .adv_w = 112, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 671, .adv_w = 112, .box_w = 6, .box_h = 3, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 674, .adv_w = 112, .box_w = 4, .box_h = 1, .ofs_x = 2, .ofs_y = 4},
    {.bitmap_index = 675, .adv_w = 112, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 684, .adv_w = 112, .box_w = 5, .box_h = 1, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 685, .adv_w = 112, .box_w = 4, .box_h = 4, .ofs_x = 2, .ofs_y = 7},
    {.bitmap_index = 687, .adv_w = 112, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 692, .adv_w = 112, .box_w = 4, .box_h = 5, .ofs_x = 2, .ofs_y = 6},
    {.bitmap_index = 695, .adv_w = 112, .box_w = 4, .box_h = 5, .ofs_x = 2, .ofs_y = 6},
    {.bitmap_index = 698, .adv_w = 112, .box_w = 2, .box_h = 2, .ofs_x = 4, .ofs_y = 10},
    {.bitmap_index = 699, .adv_w = 112, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 706, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 715, .adv_w = 112, .box_w = 1, .box_h = 2, .ofs_x = 3, .ofs_y = 4},
    {.bitmap_index = 716, .adv_w = 112, .box_w = 2, .box_h = 3, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 717, .adv_w = 112, .box_w = 2, .box_h = 5, .ofs_x = 2, .ofs_y = 6},
    {.bitmap_index = 719, .adv_w = 112, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 724, .adv_w = 112, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 731, .adv_w = 112, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 743, .adv_w = 112, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 755, .adv_w = 112, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 767, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 775, .adv_w = 112, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 784, .adv_w = 112, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 793, .adv_w = 112, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 802, .adv_w = 112, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 811, .adv_w = 112, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 820, .adv_w = 112, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 829, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 838, .adv_w = 112, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 847, .adv_w = 112, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 856, .adv_w = 112, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 865, .adv_w = 112, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 874, .adv_w = 112, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 883, .adv_w = 112, .box_w = 3, .box_h = 12, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 888, .adv_w = 112, .box_w = 3, .box_h = 12, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 893, .adv_w = 112, .box_w = 4, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 899, .adv_w = 112, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 907, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 916, .adv_w = 112, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 925, .adv_w = 112, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 934, .adv_w = 112, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 943, .adv_w = 112, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 952, .adv_w = 112, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 961, .adv_w = 112, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 970, .adv_w = 112, .box_w = 6, .box_h = 5, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 974, .adv_w = 112, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 983, .adv_w = 112, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 992, .adv_w = 112, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1001, .adv_w = 112, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1010, .adv_w = 112, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1019, .adv_w = 112, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1030, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1038, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1046, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1054, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1062, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1070, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1078, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1086, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1094, .adv_w = 112, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1101, .adv_w = 112, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1108, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1116, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1124, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1132, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1140, .adv_w = 112, .box_w = 3, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1144, .adv_w = 112, .box_w = 3, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1148, .adv_w = 112, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1153, .adv_w = 112, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1158, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1166, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1174, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1182, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1190, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1198, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1206, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1214, .adv_w = 112, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 1219, .adv_w = 112, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1226, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1234, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1242, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1250, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1258, .adv_w = 112, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1267, .adv_w = 112, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1276, .adv_w = 112, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = -2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 12, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 45, .range_length = 82, .glyph_id_start = 13,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 160, .range_length = 96, .glyph_id_start = 95,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 3,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};

extern const lv_font_t lv_font_montserrat_14;


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t font_terminus = {
#else
lv_font_t font_terminus = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 14,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = &lv_font_montserrat_14,
#endif
    .user_data = NULL,
};



#endif /*#if FONT_TERMINUS*/


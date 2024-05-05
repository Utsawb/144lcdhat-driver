#pragma once

#include <stdint.h>

#define LCD_HEIGHT 128
#define LCD_WIDTH 128

#define COLOR_FIX(color) ((color << 8) & 0xff00) | (color >> 8)

#define Rosewater 63194
#define Flamingo 63032
#define Pink 62972
#define Mauve 50462
#define Red 60466
#define Maroon 60628
#define Peach 62799
#define Yellow 61107
#define Green 42706
#define Teal 36537
#define Sky 38588
#define Sapphire 32316
#define Blue 36222
#define Lavender 46591
#define Text 52894
#define Subtext1 48668
#define Subtext0 42361
#define Overlay2 38102
#define Overlay1 33844
#define Overlay0 27537
#define Surface2 23311
#define Surface1 19052
#define Surface0 12745
#define Base 8487
#define Mantle 6406
#define Crust 6340

#define COLOR_SIZE 14
const uint16_t colors[] = {Rosewater, Flamingo, Pink, Mauve, Red,      Maroon, Peach,
                           Yellow,    Green,    Teal, Sky,   Sapphire, Blue,   Lavender};

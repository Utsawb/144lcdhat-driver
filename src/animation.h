#pragma once

#include <stdint.h>

#define FRAME_WIDTH 64
#define FRAME_HEIGHT 64

#define FRAME_COUNT (sizeof(frames) / sizeof(frames[0]))

// for (uint16_t i = 0; i < FRAME_WIDTH; ++i)
// {
//     for (uint16_t j = 0; j < FRAME_HEIGHT; ++j)
//     {
//         image[(i + x_offset) + (j + y_offset) * LCD_WIDTH] =
//             (frames[frame_number][(i + j * FRAME_HEIGHT) / 8] >> ((i + j * FRAME_HEIGHT) % 8)) & 0b1 ? WHITE
//                                                                                                      : BLACK;
//     }
// }


const uint8_t frames[][512] = {
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,127,240,0,0,0,0,3,255,255,240,0,0,0,3,255,255,252,48,0,0,0,7,255,252,0,48,0,0,0,15,0,0,0,112,0,0,0,7,0,0,0,240,0,0,0,7,240,0,3,224,0,255,0,1,255,255,255,192,0,255,192,0,127,255,255,128,0,255,224,0,15,255,227,128,0,96,240,0,14,0,3,128,15,112,112,0,14,0,3,192,15,112,56,0,14,0,3,252,15,112,56,0,14,0,7,255,143,48,28,7,254,0,14,15,231,56,31,255,255,0,126,1,255,56,15,255,231,255,248,0,126,24,7,128,3,255,224,0,30,28,0,0,0,255,0,0,7,28,0,0,0,0,0,0,7,28,0,0,0,0,0,0,7,14,0,0,0,0,0,0,7,15,0,0,0,0,0,0,14,7,192,0,0,0,0,0,30,3,240,0,0,0,0,0,63,0,254,0,0,0,0,0,255,0,63,192,0,0,0,3,239,0,7,254,0,0,0,31,207,0,0,255,248,0,3,255,15,0,0,31,255,255,255,248,15,0,0,0,127,255,255,192,0,0,0,0,0,31,240,0,0,0,0,0,0,0,120,0,0,0,0,0,0,0,63,128,0,0,0,0,0,0,31,192,0,0,0,0,0,0,31,224,0,0,0,0,0,0,56,224,0,0,0,0,0,0,56,224,0,0,0,0,0,0,56,224,0,0,0,0,0,0,31,224,0,0,0,0,0,0,15,192,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,31,224,0,0,0,0,0,31,255,240,0,0,0,3,255,255,255,112,0,0,0,7,255,255,0,48,0,0,0,7,248,0,0,112,0,0,0,7,0,0,0,240,0,0,0,7,224,0,3,224,0,126,0,3,255,193,255,192,0,255,128,0,255,255,255,128,0,255,224,0,15,255,251,128,0,224,224,0,14,0,3,128,0,96,112,0,14,0,3,128,6,112,120,0,14,0,3,252,15,112,56,0,14,0,7,255,143,48,28,0,254,0,14,15,239,56,31,255,254,0,62,1,255,56,15,255,255,131,248,0,126,24,7,240,3,255,240,0,30,28,0,0,1,255,128,0,15,28,0,0,0,0,0,0,7,28,0,0,0,0,0,0,7,14,0,0,0,0,0,0,7,14,0,0,0,0,0,0,14,7,128,0,0,0,0,0,30,3,224,0,0,0,0,0,63,0,252,0,0,0,0,0,255,0,127,128,0,0,0,3,255,0,15,248,0,0,0,15,207,0,1,255,224,0,0,255,15,0,0,63,255,255,255,252,0,0,0,1,255,255,255,192,0,0,0,0,1,255,248,0,0,0,0,0,0,0,120,0,0,0,0,0,0,0,63,128,0,0,0,0,0,0,31,192,0,0,0,0,0,0,31,224,0,0,0,0,0,0,56,224,0,0,0,0,0,0,56,96,0,0,0,0,0,0,56,224,0,0,0,0,0,0,31,224,0,0,0,0,0,0,15,192,0,0,0,0,0,0,7,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,224,0,0,0,0,0,3,255,240,0,0,0,0,63,255,255,240,0,0,0,7,255,255,192,48,0,0,0,7,255,128,0,112,0,0,0,14,0,0,0,112,0,0,0,7,128,0,1,224,0,0,0,3,252,0,31,192,0,255,128,1,255,255,255,128,0,255,192,0,31,255,255,128,0,225,224,0,14,0,3,128,0,96,112,0,14,0,3,128,0,112,112,0,14,0,3,248,0,112,56,0,14,0,7,255,15,48,60,0,30,0,15,63,207,56,28,63,254,0,30,3,255,56,15,255,255,1,252,0,126,56,15,254,7,255,240,0,30,24,0,0,3,255,192,0,14,28,0,0,0,112,0,0,7,28,0,0,0,0,0,0,7,12,0,0,0,0,0,0,7,14,0,0,0,0,0,0,15,7,0,0,0,0,0,0,30,3,192,0,0,0,0,0,63,1,248,0,0,0,0,0,127,0,127,0,0,0,0,1,255,0,31,240,0,0,0,15,198,0,3,255,128,0,0,127,0,0,0,127,255,252,255,252,0,0,0,3,255,255,255,224,0,0,0,0,15,255,252,0,0,0,0,0,0,0,120,0,0,0,0,0,0,0,63,0,0,0,0,0,0,0,31,192,0,0,0,0,0,0,31,224,0,0,0,0,0,0,56,224,0,0,0,0,0,0,56,96,0,0,0,0,0,0,56,224,0,0,0,0,0,0,31,224,0,0,0,0,0,0,31,192,0,0,0,0,0,0,7,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,192,0,0,0,0,0,0,255,240,0,0,0,0,3,255,255,240,0,0,0,3,255,255,240,112,0,0,0,7,255,240,0,112,0,0,0,15,0,0,0,112,0,0,0,7,0,0,1,224,0,0,0,7,240,0,15,224,0,127,0,1,255,255,255,128,0,255,192,0,127,255,255,128,0,255,224,0,15,255,131,128,0,96,240,0,14,0,3,128,0,112,112,0,14,0,3,240,15,112,56,0,14,0,7,254,15,48,56,0,14,0,15,255,207,48,28,7,254,0,30,7,254,56,15,255,255,0,252,0,254,56,15,255,199,255,248,0,62,24,7,128,3,255,192,0,14,28,0,0,0,254,0,0,7,28,0,0,0,0,0,0,7,12,0,0,0,0,0,0,7,14,0,0,0,0,0,0,14,15,0,0,0,0,0,0,14,7,192,0,0,0,0,0,62,1,240,0,0,0,0,0,127,0,254,0,0,0,0,1,255,0,63,224,0,0,0,7,207,0,7,254,0,0,0,127,143,0,0,255,254,0,207,252,0,0,0,15,255,255,255,240,0,0,0,0,63,255,254,0,0,0,0,0,0,0,112,0,0,0,0,0,0,0,60,0,0,0,0,0,0,0,31,192,0,0,0,0,0,0,31,224,0,0,0,0,0,0,28,224,0,0,0,0,0,0,56,96,0,0,0,0,0,0,56,224,0,0,0,0,0,0,28,224,0,0,0,0,0,0,31,192,0,0,0,0,0,0,15,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,112,0,0,0,0,0,0,0,240,0,0,0,0,0,0,0,96,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,127,224,0,0,0,0,0,127,255,240,0,0,0,3,255,255,248,112,0,0,0,7,255,252,0,112,0,0,0,15,224,0,0,112,0,0,0,15,0,0,0,224,0,0,0,7,224,0,7,224,0,0,0,3,255,255,255,192,0,255,128,0,255,255,255,0,0,255,224,0,15,255,227,0,0,96,224,0,14,0,3,0,15,112,112,0,14,0,3,224,15,112,120,0,14,0,7,254,15,112,56,0,14,0,7,255,142,48,28,1,254,0,30,7,238,56,31,255,254,0,124,0,254,56,15,255,255,223,248,0,62,24,7,224,3,255,224,0,14,28,0,0,1,255,0,0,6,28,0,0,0,0,0,0,7,12,0,0,0,0,0,0,7,14,0,0,0,0,0,0,14,15,0,0,0,0,0,0,14,7,128,0,0,0,0,0,30,3,240,0,0,0,0,0,126,0,252,0,0,0,0,1,255,0,63,192,0,0,0,7,239,0,15,252,0,0,0,63,143,0,1,255,248,0,7,254,15,0,0,31,255,255,255,240,6,0,0,0,255,255,255,0,0,0,0,0,0,0,112,0,0,0,0,0,0,0,56,0,0,0,0,0,0,0,31,128,0,0,0,0,0,0,31,192,0,0,0,0,0,0,28,224,0,0,0,0,0,0,56,96,0,0,0,0,0,0,56,96,0,0,0,0,0,0,28,224,0,0,0,0,0,0,31,192,0,0,0,0,0,0,15,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,240,0,0,0,0,0,0,7,240,0,0,0,0,0,0,3,224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,63,224,0,0,0,0,0,31,255,240,0,0,0,1,255,255,252,112,0,0,0,7,255,254,0,112,0,0,0,15,252,0,0,112,0,0,0,14,0,0,0,224,0,0,0,7,192,0,3,224,0,0,0,3,255,131,255,192,0,255,128,0,255,255,255,0,0,255,192,0,15,255,243,0,0,225,224,0,14,0,3,0,0,96,112,0,14,0,3,192,14,112,112,0,14,0,7,252,15,112,56,0,14,0,7,255,142,48,28,0,126,0,30,15,238,56,30,255,254,0,124,1,254,56,15,255,255,135,248,0,62,24,15,248,3,255,224,0,30,28,0,0,1,255,0,0,14,28,0,0,0,0,0,0,7,12,0,0,0,0,0,0,7,14,0,0,0,0,0,0,14,14,0,0,0,0,0,0,14,7,128,0,0,0,0,0,30,3,224,0,0,0,0,0,126,1,252,0,0,0,0,1,255,0,127,128,0,0,0,7,239,0,15,248,0,0,0,63,143,0,1,255,240,0,3,254,4,0,0,63,255,255,255,240,0,0,0,1,255,255,255,128,0,0,0,0,0,63,240,0,0,0,0,0,0,0,56,0,0,0,0,0,0,0,63,128,0,0,0,0,0,0,31,192,0,0,0,0,0,0,28,224,0,0,0,0,0,0,56,96,0,0,0,0,0,0,56,96,0,0,0,0,0,0,28,224,0,0,0,0,0,0,31,224,0,0,0,0,0,0,15,192,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,127,240,0,0,0,0,0,0,127,240,0,0,0,0,0,0,127,224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,31,224,0,0,0,0,0,15,255,240,0,0,0,0,255,255,254,112,0,0,0,7,255,255,0,112,0,0,0,15,254,0,0,112,0,0,0,14,0,0,0,224,0,0,0,7,128,0,3,224,0,0,0,3,255,1,255,192,0,255,128,0,255,255,255,0,0,255,192,0,31,255,243,0,0,241,224,0,14,0,3,0,0,96,112,0,14,0,3,128,0,112,112,0,14,0,7,252,14,112,56,0,14,0,7,255,143,48,28,0,62,0,14,15,238,56,28,127,254,0,60,1,254,56,15,255,255,131,248,0,126,24,15,252,7,255,240,0,30,28,0,0,1,255,0,0,14,28,0,0,0,0,0,0,7,12,0,0,0,0,0,0,7,14,0,0,0,0,0,0,14,14,0,0,0,0,0,0,14,7,128,0,0,0,0,0,30,3,224,0,0,0,0,0,127,1,248,0,0,0,0,0,255,0,127,128,0,0,0,7,239,0,15,248,0,0,0,63,128,0,3,255,224,0,3,254,0,0,0,63,255,255,255,248,0,0,0,1,255,255,255,128,0,0,0,0,0,255,240,0,0,0,0,0,0,0,56,0,0,0,0,0,0,0,63,128,0,0,0,0,0,0,31,192,0,0,0,0,0,0,28,224,0,0,0,0,0,0,56,96,0,0,0,0,0,0,56,96,0,0,0,0,0,0,28,224,0,0,0,0,0,0,31,224,0,0,0,0,0,0,15,192,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,255,240,0,0,0,0,0,15,255,240,0,0,0,0,0,7,255,224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,31,224,0,0,0,0,0,15,255,240,0,0,0,0,255,255,254,112,0,0,0,7,255,255,0,112,0,0,0,15,252,0,0,112,0,0,0,14,0,0,0,224,0,0,0,7,192,0,3,224,0,0,0,3,255,1,255,192,0,255,128,0,255,255,255,0,0,255,192,0,15,255,243,0,0,225,224,0,14,0,3,0,0,96,112,0,14,0,3,192,14,112,112,0,14,0,7,252,15,112,56,0,14,0,7,255,142,48,28,0,126,0,14,15,238,56,28,127,254,0,60,1,254,56,15,255,255,135,248,0,126,24,15,248,7,255,224,0,30,28,0,0,1,255,0,0,14,28,0,0,0,0,0,0,7,12,0,0,0,0,0,0,7,14,0,0,0,0,0,0,14,14,0,0,0,0,0,0,14,7,128,0,0,0,0,0,30,3,224,0,0,0,0,0,126,1,252,0,0,0,0,0,255,0,127,128,0,0,0,7,239,0,15,248,0,0,0,63,143,0,1,255,224,0,3,254,6,0,0,63,255,255,255,240,0,0,0,1,255,255,255,128,0,0,0,0,0,255,240,0,0,0,0,0,0,0,56,0,0,0,0,0,0,0,63,128,0,0,0,0,0,0,31,192,0,0,0,0,0,0,28,224,0,0,0,0,0,0,56,96,0,0,0,0,0,0,56,96,0,0,0,0,0,0,28,224,0,0,0,0,0,0,31,224,0,0,0,0,0,0,15,192,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,127,255,240,0,0,0,0,0,127,255,240,0,0,0,0,0,63,255,224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,63,224,0,0,0,0,0,31,255,240,0,0,0,0,255,255,252,112,0,0,0,7,255,254,0,112,0,0,0,15,252,0,0,112,0,0,0,14,0,0,0,224,0,0,0,7,192,0,3,224,0,0,0,3,255,131,255,192,0,255,128,0,255,255,255,0,0,255,192,0,15,255,243,0,0,225,224,0,14,0,3,0,14,96,112,0,14,0,3,192,15,112,112,0,14,0,7,252,14,112,56,0,14,0,7,255,142,48,28,0,126,0,30,15,238,56,30,255,254,0,124,1,254,56,15,255,255,135,248,0,62,24,15,248,3,255,224,0,30,28,0,0,1,255,0,0,14,28,0,0,0,0,0,0,7,12,0,0,0,0,0,0,7,14,0,0,0,0,0,0,14,14,0,0,0,0,0,0,14,7,128,0,0,0,0,0,30,3,224,0,0,0,0,0,126,1,252,0,0,0,0,1,254,0,127,128,0,0,0,7,239,0,15,248,0,0,0,63,143,0,1,255,240,0,3,254,15,0,0,63,255,255,255,240,6,0,0,1,255,255,255,128,0,0,0,0,0,63,240,0,0,0,0,0,0,0,56,0,0,0,0,0,0,0,31,128,0,0,0,0,0,0,31,192,0,0,0,0,0,0,28,224,0,0,0,0,1,192,56,96,0,0,0,0,1,192,56,96,0,0,0,0,0,0,28,224,0,0,0,0,0,0,31,224,0,0,0,0,0,0,15,192,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,240,0,0,0,0,0,255,255,240,0,0,0,0,0,255,255,224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,63,224,0,0,0,0,0,63,255,240,0,0,0,1,255,255,252,112,0,0,0,7,255,254,0,112,0,0,0,15,248,0,0,112,0,0,0,14,0,0,0,224,0,0,0,7,192,0,7,224,0,0,0,3,255,239,255,192,0,255,128,0,255,255,255,0,0,255,192,0,15,255,227,0,0,96,224,0,14,0,3,0,0,112,112,0,14,0,3,192,14,112,120,0,14,0,7,252,15,112,56,0,14,0,7,255,142,48,28,0,254,0,30,7,238,56,31,255,254,0,124,1,254,56,15,255,255,207,248,0,62,24,7,240,3,255,224,0,30,28,0,0,1,255,0,0,14,28,0,0,0,0,0,0,7,12,0,0,0,0,0,0,7,14,0,0,0,0,0,0,14,14,0,0,0,0,0,0,14,7,128,0,0,0,0,0,30,3,224,0,0,0,0,0,126,0,252,0,0,0,0,1,255,0,127,128,0,0,0,7,239,0,15,252,0,0,0,63,143,0,1,255,240,0,7,254,4,0,0,31,255,255,255,240,0,0,0,0,255,255,255,128,0,0,0,0,0,7,240,0,0,0,0,0,0,0,56,0,0,0,0,0,0,0,31,128,0,0,0,0,0,0,31,192,0,0,0,0,0,0,28,224,0,0,0,0,15,192,56,96,0,0,0,0,7,192,56,96,0,0,0,0,0,0,28,224,0,0,0,0,0,0,31,192,0,0,0,0,0,0,15,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,192,0,0,0,0,0,255,255,224,0,0,0,0,0,255,255,192,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,127,224,0,0,0,0,0,127,255,240,0,0,0,3,255,255,248,112,0,0,0,7,255,252,0,112,0,0,0,15,224,0,0,112,0,0,0,14,0,0,0,224,0,0,0,7,224,0,7,224,0,0,0,3,255,255,255,128,0,255,128,0,255,255,255,0,0,255,224,0,15,255,227,0,0,96,224,0,14,0,3,0,0,112,112,0,14,0,3,224,0,112,56,0,14,0,7,254,14,48,56,0,14,0,7,255,143,48,28,1,254,0,30,7,238,56,31,255,255,0,124,0,254,56,15,255,255,223,248,0,62,24,7,224,3,255,224,0,14,28,0,0,1,254,0,0,6,28,0,0,0,0,0,0,7,12,0,0,0,0,0,0,7,14,0,0,0,0,0,0,14,15,0,0,0,0,0,0,14,7,128,0,0,0,0,0,62,3,240,0,0,0,0,0,127,0,252,0,0,0,0,1,255,0,63,192,0,0,0,7,239,0,15,252,0,0,0,63,128,0,0,255,252,0,7,254,0,0,0,31,255,255,255,240,0,0,0,0,127,255,255,0,0,0,0,0,0,0,112,0,0,0,0,0,0,0,56,0,0,0,0,0,0,0,31,192,0,0,0,0,0,0,31,192,0,0,0,0,0,0,28,224,0,0,0,0,127,192,56,96,0,0,0,0,127,192,56,96,0,0,0,0,0,0,28,224,0,0,0,0,0,0,31,192,0,0,0,0,0,0,15,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,254,0,0,0,0,0,0,255,254,0,0,0,0,0,0,255,254,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,0,0,0,0,0,0,255,224,0,0,0,0,1,255,255,240,0,0,0,3,255,255,248,112,0,0,0,7,255,248,0,112,0,0,0,15,192,0,0,112,0,0,0,7,0,0,1,224,0,0,0,7,224,0,7,224,0,126,0,3,255,255,255,128,0,255,192,0,127,255,255,0,0,255,224,0,15,255,195,0,0,96,224,0,14,0,3,0,0,112,112,0,14,0,3,240,14,112,56,0,14,0,7,254,15,48,56,0,14,0,15,255,206,56,28,3,254,0,30,7,254,56,31,255,255,0,252,0,254,56,15,255,231,255,248,0,62,24,7,192,3,255,192,0,14,28,0,0,0,254,0,0,6,28,0,0,0,0,0,0,7,12,0,0,0,0,0,0,7,14,0,0,0,0,0,0,14,15,0,0,0,0,0,0,14,7,192,0,0,0,0,0,62,1,240,0,0,0,0,0,126,0,254,0,0,0,0,1,255,0,63,192,0,0,0,7,207,0,7,254,0,0,0,127,143,0,0,255,254,0,79,252,0,0,0,15,255,255,255,224,0,0,0,0,63,255,254,0,0,0,0,0,0,0,112,0,0,0,0,0,0,0,62,0,0,0,0,0,0,0,31,192,0,0,0,0,0,0,31,224,0,0,0,0,0,0,28,224,0,0,0,3,255,192,56,96,0,0,0,3,255,192,56,224,0,0,0,0,0,0,29,224,0,0,0,0,0,0,31,192,0,0,0,0,0,0,15,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,224,0,0,0,0,0,0,255,224,0,0,0,0,0,0,255,192,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,192,0,0,0,0,0,1,255,224,0,0,0,0,7,255,255,240,0,0,0,3,255,255,240,112,0,0,0,7,255,240,0,112,0,0,0,14,0,0,0,112,0,0,0,7,0,0,1,224,0,0,0,7,240,0,15,192,0,127,0,1,255,255,255,128,0,255,192,0,63,255,255,0,0,255,224,0,14,255,3,0,14,96,240,0,14,0,3,0,15,112,112,0,14,0,3,240,15,112,56,0,14,0,7,254,14,48,56,0,14,0,15,127,206,56,28,15,254,0,30,7,254,56,15,255,255,0,252,0,254,24,15,255,135,255,240,0,62,28,7,0,3,255,192,0,14,28,0,0,0,252,0,0,6,28,0,0,0,0,0,0,7,12,0,0,0,0,0,0,7,14,0,0,0,0,0,0,14,7,0,0,0,0,0,0,30,7,192,0,0,0,0,0,62,1,248,0,0,0,0,0,126,0,254,0,0,0,0,1,255,0,31,224,0,0,0,15,207,0,7,255,0,0,0,127,15,0,0,127,255,192,255,252,15,0,0,7,255,255,255,224,4,0,0,0,31,255,254,0,0,0,0,0,0,0,112,0,0,0,0,0,0,0,63,0,0,0,0,0,0,0,31,192,0,0,0,0,0,0,31,224,0,0,0,0,0,0,56,224,0,0,0,31,255,192,56,96,0,0,0,31,255,192,56,224,0,0,0,0,0,0,31,224,0,0,0,0,0,0,31,192,0,0,0,0,0,0,7,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,254,0,0,0,0,0,0,0,254,0,0,0,0,0,0,0,252,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,192,0,0,0,0,0,3,255,240,0,0,0,0,31,255,255,240,0,0,0,7,255,255,192,112,0,0,0,7,255,192,0,112,0,0,0,14,0,0,0,112,0,0,0,7,128,0,1,224,0,0,0,3,248,0,31,192,0,127,128,1,255,255,255,128,0,255,192,0,63,255,255,0,0,127,224,0,14,16,3,0,0,96,112,0,14,0,3,128,0,112,112,0,14,0,3,248,15,112,56,0,14,0,7,255,15,48,28,0,14,0,15,63,206,56,28,63,254,0,30,3,254,56,15,255,255,1,252,0,254,24,15,255,7,255,240,0,62,28,0,0,3,255,128,0,14,28,0,0,0,112,0,0,7,12,0,0,0,0,0,0,7,14,0,0,0,0,0,0,6,14,0,0,0,0,0,0,14,7,128,0,0,0,0,0,30,3,192,0,0,0,0,0,62,1,248,0,0,0,0,0,254,0,127,0,0,0,0,3,255,0,31,240,0,0,0,15,207,0,3,255,128,0,0,255,14,0,0,127,255,255,255,252,0,0,0,3,255,255,255,224,0,0,0,0,7,255,252,0,0,0,0,0,0,0,120,0,0,0,0,0,0,0,63,0,0,0,0,0,0,0,31,192,0,0,0,0,0,0,31,224,0,0,0,0,0,0,56,224,0,0,0,63,255,192,56,224,0,0,0,63,255,192,56,224,0,0,0,0,0,0,31,224,0,0,0,0,0,0,15,192,0,0,0,0,0,0,7,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,0,0,0,0,0,0,0,240,0,0,0,0,0,0,0,224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,224,0,0,0,0,0,7,255,240,0,0,0,0,127,255,255,240,0,0,0,7,255,255,128,112,0,0,0,7,255,0,0,112,0,0,0,14,0,0,0,112,0,0,0,7,192,0,1,224,0,0,0,3,252,0,63,192,0,255,128,0,255,255,255,128,0,255,192,0,31,255,255,128,0,112,224,0,14,0,3,128,0,112,112,0,14,0,3,128,0,112,120,0,14,0,3,248,0,48,56,0,14,0,7,255,15,48,28,0,62,0,14,31,207,56,30,255,254,0,62,3,254,56,15,255,255,129,248,0,126,24,7,252,7,255,240,0,30,28,0,0,1,255,128,0,14,28,0,0,0,0,0,0,7,12,0,0,0,0,0,0,7,14,0,0,0,0,0,0,6,14,0,0,0,0,0,0,14,7,128,0,0,0,0,0,30,3,224,0,0,0,0,0,62,1,252,0,0,0,0,0,255,0,127,128,0,0,0,3,239,0,15,248,0,0,0,31,198,0,1,255,192,0,1,255,0,0,0,63,255,255,255,248,0,0,0,1,255,255,255,192,0,0,0,0,1,255,248,0,0,0,0,0,0,0,120,0,0,0,0,0,0,0,63,128,0,0,0,0,0,0,31,192,0,0,0,0,0,0,31,224,0,0,0,0,0,0,56,224,0,0,0,63,255,128,56,224,0,0,0,63,255,128,56,224,0,0,0,0,0,0,31,224,0,0,0,0,0,0,15,192,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,31,224,0,0,0,0,0,31,255,240,0,0,0,1,255,255,255,112,0,0,0,7,255,255,0,48,0,0,0,7,248,0,0,112,0,0,0,7,0,0,0,240,0,0,0,7,192,0,3,224,0,0,0,3,255,193,255,192,0,255,192,0,255,255,255,128,0,255,224,0,15,255,251,128,0,96,224,0,14,0,3,128,0,112,112,0,14,0,3,128,14,112,56,0,14,0,3,252,15,48,56,0,14,0,7,255,143,56,28,0,254,0,14,15,238,56,31,255,254,0,60,1,254,56,15,255,255,199,248,0,126,24,7,224,3,255,240,0,30,28,0,0,1,255,0,0,14,28,0,0,0,0,0,0,7,12,0,0,0,0,0,0,7,14,0,0,0,0,0,0,14,15,0,0,0,0,0,0,14,7,128,0,0,0,0,0,30,3,240,0,0,0,0,0,62,0,252,0,0,0,0,0,254,0,63,192,0,0,0,3,239,0,15,252,0,0,0,31,143,0,0,255,240,0,3,254,14,0,0,31,255,255,255,248,0,0,0,0,255,255,255,128,0,0,0,0,0,63,240,0,0,0,0,0,0,0,120,0,0,0,0,0,0,0,63,128,0,0,0,0,0,0,31,192,0,0,0,0,0,0,29,224,0,0,0,0,0,0,56,224,0,0,0,63,254,0,56,224,0,0,0,63,254,0,56,224,0,0,0,0,0,0,31,192,0,0,0,0,0,0,15,192,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,7,128,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,63,224,0,0,0,0,0,127,255,240,0,0,0,3,255,255,252,112,0,0,0,7,255,254,0,48,0,0,0,7,192,0,0,112,0,0,0,7,0,0,0,240,0,0,0,7,240,0,3,224,0,127,0,1,255,255,255,192,0,255,192,0,127,255,255,128,0,127,224,0,15,255,227,128,0,112,240,0,14,0,3,128,14,112,112,0,14,0,3,192,15,112,56,0,14,0,7,252,15,48,56,0,14,0,7,255,142,56,28,3,254,0,30,15,238,56,15,255,255,0,124,1,254,24,15,255,231,255,248,0,126,28,7,128,3,255,224,0,30,28,0,0,0,255,0,0,14,28,0,0,0,0,0,0,7,12,0,0,0,0,0,0,7,14,0,0,0,0,0,0,14,7,0,0,0,0,0,0,14,7,192,0,0,0,0,0,30,1,240,0,0,0,0,0,126,0,254,0,0,0,0,0,254,0,31,224,0,0,0,7,239,0,7,254,0,0,0,63,143,0,0,255,252,0,7,254,15,0,0,15,255,255,255,240,14,0,0,0,127,255,255,128,0,0,0,0,0,0,240,0,0,0,0,0,0,0,120,0,0,0,0,0,0,0,63,128,0,0,0,0,0,0,31,192,0,0,0,0,0,0,28,224,0,0,0,0,0,0,56,224,0,0,0,63,224,0,56,224,0,0,0,63,224,0,56,224,0,0,0,0,0,0,31,192,0,0,0,0,0,0,15,128,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,15,128,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,127,224,0,0,0,0,3,255,255,240,0,0,0,3,255,255,248,48,0,0,0,7,255,248,0,112,0,0,0,7,0,0,0,112,0,0,0,7,128,0,0,240,0,0,0,3,248,0,7,224,0,127,128,1,255,255,255,192,0,255,192,0,63,255,255,128,0,113,224,0,14,255,195,128,0,112,112,0,14,0,3,128,0,112,112,0,14,0,3,224,14,48,56,0,14,0,7,254,15,48,28,0,14,0,7,255,143,56,28,31,254,0,30,7,238,56,15,255,255,0,252,0,254,24,15,255,135,255,248,0,62,28,0,0,3,255,224,0,30,28,0,0,0,254,0,0,14,12,0,0,0,0,0,0,7,14,0,0,0,0,0,0,7,14,0,0,0,0,0,0,14,7,128,0,0,0,0,0,14,3,192,0,0,0,0,0,30,1,248,0,0,0,0,0,126,0,127,0,0,0,0,1,254,0,31,224,0,0,0,7,239,0,3,255,0,0,0,63,143,0,0,127,255,128,207,254,4,0,0,7,255,255,255,240,0,0,0,0,31,255,255,0,0,0,0,0,0,0,112,0,0,0,0,0,0,0,56,0,0,0,0,0,0,0,31,128,0,0,0,0,0,0,31,192,0,0,0,0,0,0,56,224,0,0,0,0,0,0,56,224,0,0,0,63,0,0,56,224,0,0,0,63,0,0,61,224,0,0,0,0,0,0,31,192,0,0,0,0,0,0,15,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,63,0,0,0,0,0,0,0,63,128,0,0,0,0,0,0,63,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,192,0,0,0,0,0,1,255,240,0,0,0,0,63,255,255,240,0,0,0,7,255,255,240,48,0,0,0,7,255,192,0,112,0,0,0,6,0,0,0,112,0,0,0,7,128,0,0,240,0,0,0,3,252,0,15,224,0,255,192,0,255,255,255,128,0,255,224,0,31,255,255,128,0,96,224,0,14,12,3,128,0,112,112,0,14,0,3,128,0,112,56,0,14,0,3,240,0,48,56,0,14,0,7,254,14,56,28,0,30,0,15,255,143,56,30,255,254,0,30,7,239,56,15,255,255,0,252,0,254,24,7,252,7,255,240,0,62,28,0,0,3,255,192,0,14,28,0,0,0,112,0,0,6,12,0,0,0,0,0,0,7,14,0,0,0,0,0,0,7,15,0,0,0,0,0,0,14,7,128,0,0,0,0,0,14,3,224,0,0,0,0,0,62,0,252,0,0,0,0,0,126,0,127,128,0,0,0,1,255,0,15,240,0,0,0,15,207,0,1,255,192,0,0,127,128,0,0,63,255,252,255,252,0,0,0,1,255,255,255,224,0,0,0,0,7,255,254,0,0,0,0,0,0,0,112,0,0,0,0,0,0,0,63,0,0,0,0,0,0,0,31,192,0,0,0,0,0,0,31,192,0,0,0,0,0,0,56,224,0,0,0,0,0,0,56,224,0,0,0,56,0,0,56,224,0,0,0,56,0,0,61,224,0,0,0,0,0,0,31,192,0,0,0,0,0,0,15,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,0,0,0,0,0,0,1,255,128,0,0,0,0,0,0,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,224,0,0,0,0,0,3,255,240,0,0,0,1,255,255,255,240,0,0,0,7,255,255,192,48,0,0,0,7,254,0,0,112,0,0,0,7,0,0,0,112,0,0,0,7,192,0,1,240,0,127,0,3,254,0,31,224,0,255,192,0,255,255,255,128,0,127,224,0,15,255,255,128,0,112,240,0,14,0,3,128,0,112,112,0,14,0,3,128,0,112,56,0,14,0,3,248,15,48,56,0,14,0,7,254,15,56,28,0,126,0,15,63,207,56,15,255,254,0,30,3,254,24,15,255,255,129,252,0,254,28,7,224,3,255,240,0,62,28,0,0,1,255,128,0,14,28,0,0,0,0,0,0,6,12,0,0,0,0,0,0,7,14,0,0,0,0,0,0,7,7,0,0,0,0,0,0,14,7,192,0,0,0,0,0,30,1,240,0,0,0,0,0,62,0,252,0,0,0,0,0,126,0,63,192,0,0,0,1,254,0,7,252,0,0,0,15,207,0,0,255,224,0,0,255,14,0,0,31,255,255,255,252,0,0,0,0,255,255,255,224,0,0,0,0,1,255,252,0,0,0,0,0,0,0,112,0,0,0,0,0,0,0,63,0,0,0,0,0,0,0,31,192,0,0,0,0,0,0,31,192,0,0,0,0,0,0,56,224,0,0,0,0,0,0,56,224,0,0,0,0,0,0,56,224,0,0,0,0,0,0,63,192,0,0,0,0,0,0,31,192,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,255,0,0,0,0,0,0,3,255,128,0,0,0,0,0,3,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,224,0,0,0,0,0,15,255,240,0,0,0,3,255,255,255,240,0,0,0,7,255,255,128,56,0,0,0,7,240,0,0,112,0,0,0,7,0,0,0,112,0,0,0,7,224,0,1,224,0,127,128,1,255,224,127,192,0,255,192,0,127,255,255,128,0,127,224,0,15,255,255,128,0,112,112,0,14,0,3,128,6,112,112,0,14,0,3,128,15,48,56,0,14,0,3,248,15,56,28,0,14,0,7,255,15,56,28,3,254,0,15,31,206,56,15,255,255,0,62,3,254,24,15,255,247,195,248,0,254,28,7,128,3,255,240,0,62,28,0,0,1,255,128,0,14,12,0,0,0,0,0,0,6,14,0,0,0,0,0,0,7,14,0,0,0,0,0,0,6,7,0,0,0,0,0,0,14,3,192,0,0,0,0,0,30,1,248,0,0,0,0,0,62,0,126,0,0,0,0,0,254,0,31,224,0,0,0,3,254,0,7,254,0,0,0,31,206,0,0,255,248,0,1,255,15,0,0,15,255,255,255,252,14,0,0,0,127,255,255,192,4,0,0,0,0,31,240,0,0,0,0,0,0,0,120,0,0,0,0,0,0,0,63,0,0,0,0,0,0,0,31,192,0,0,0,0,0,0,63,192,0,0,0,0,0,0,56,224,0,0,0,0,0,0,56,224,0,0,0,0,0,0,56,224,0,0,0,0,0,0,31,192,0,0,0,0,0,0,31,128,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,255,0,0,0,0,0,0,7,255,128,0,0,0,0,0,3,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,31,224,0,0,0,0,0,255,255,240,0,0,0,3,255,255,255,176,0,0,0,7,255,254,0,56,0,0,0,7,0,0,0,112,0,0,0,7,128,0,0,112,0,0,0,3,240,0,3,224,0,127,192,1,255,255,255,192,0,127,224,0,63,255,255,128,0,112,224,0,15,255,251,128,0,112,112,0,14,0,3,128,0,112,56,0,14,0,3,128,0,48,56,0,14,0,3,248,15,56,28,0,14,0,7,255,15,56,28,31,254,0,14,15,207,24,15,255,255,0,62,3,254,24,7,255,199,255,248,0,126,28,0,0,3,255,224,0,30,28,0,0,0,255,0,0,14,12,0,0,0,0,0,0,7,14,0,0,0,0,0,0,7,14,0,0,0,0,0,0,6,7,128,0,0,0,0,0,14,3,224,0,0,0,0,0,30,1,248,0,0,0,0,0,62,0,127,0,0,0,0,0,254,0,31,224,0,0,0,3,238,0,3,255,0,0,0,31,207,0,0,127,254,0,3,255,14,0,0,7,255,255,255,248,0,0,0,0,63,255,255,192,0,0,0,0,0,1,240,0,0,0,0,0,0,0,120,0,0,0,0,0,0,0,63,128,0,0,0,0,0,0,31,192,0,0,0,0,0,0,61,192,0,0,0,0,0,0,56,224,0,0,0,0,0,0,56,224,0,0,0,0,0,0,56,224,0,0,0,0,0,0,31,192,0,0,0,0,0,0,31,128,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,254,0,0,0,0,0,0,7,255,0,0,0,0,0,0,3,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,63,224,0,0,0,0,7,255,255,240,0,0,0,3,255,255,254,56,0,0,0,7,255,252,0,56,0,0,0,7,0,0,0,112,0,0,0,7,128,0,0,112,0,126,0,3,248,0,3,224,0,127,192,0,255,255,255,192,0,127,224,0,31,255,255,128,0,112,240,0,14,127,243,128,0,112,112,0,14,0,3,128,0,48,56,0,14,0,3,128,0,48,56,0,14,0,3,252,0,56,28,0,14,0,7,255,15,56,14,255,254,0,30,15,207,24,15,255,255,0,124,1,255,28,7,254,7,255,248,0,126,28,0,0,3,255,224,0,30,28,0,0,0,254,0,0,14,12,0,0,0,0,0,0,7,14,0,0,0,0,0,0,7,15,0,0,0,0,0,0,6,7,128,0,0,0,0,0,14,3,224,0,0,0,0,0,30,0,252,0,0,0,0,0,62,0,63,128,0,0,0,0,254,0,15,240,0,0,0,3,239,0,1,255,128,0,0,63,206,0,0,63,255,128,7,254,0,0,0,3,255,255,255,248,0,0,0,0,15,255,255,128,0,0,0,0,0,0,240,0,0,0,0,0,0,0,120,0,0,0,0,0,0,0,63,128,0,0,0,0,0,0,31,192,0,0,0,0,0,0,57,192,0,0,0,0,0,0,56,224,0,0,0,0,0,0,56,224,0,0,0,0,0,0,57,192,0,0,0,0,0,0,31,192,0,0,0,0,0,0,15,128,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,252,0,0,0,0,0,0,7,252,0,0,0,0,0,0,3,252,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,224,0,0,0,0,0,255,255,240,0,0,0,3,255,255,255,248,0,0,0,7,255,255,0,56,0,0,0,7,0,0,0,48,0,0,0,7,128,0,0,112,0,0,0,3,248,0,1,240,0,127,192,1,255,255,255,224,0,127,224,0,63,255,255,128,0,112,240,0,15,255,251,128,0,112,112,0,14,0,3,128,0,112,56,0,14,0,3,128,0,48,56,0,14,0,3,248,15,56,28,0,14,0,7,255,15,56,28,63,254,0,15,31,207,24,15,255,255,0,62,3,254,24,7,255,135,255,248,0,254,28,0,0,3,255,240,0,62,28,0,0,0,255,0,0,14,12,0,0,0,0,0,0,7,14,0,0,0,0,0,0,7,14,0,0,0,0,0,0,7,7,128,0,0,0,0,0,14,3,224,0,0,0,0,0,30,0,248,0,0,0,0,0,62,0,127,0,0,0,0,0,254,0,15,240,0,0,0,3,254,0,3,255,0,0,0,31,207,0,0,127,254,0,1,255,14,0,0,7,255,255,255,248,0,0,0,0,31,255,255,192,0,0,0,0,0,3,240,0,0,0,0,0,0,0,112,0,0,0,0,0,0,0,63,0,0,0,0,0,0,0,31,192,0,0,0,0,0,0,63,192,0,0,0,0,0,0,56,224,0,0,0,0,0,0,56,224,0,0,0,0,0,0,56,224,0,0,0,0,0,0,63,192,0,0,0,0,0,0,31,128,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,224,0,0,0,0,0,0,7,240,0,0,0,0,0,0,3,240,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,224,0,0,0,0,0,15,255,240,0,0,0,3,255,255,255,248,0,0,0,7,255,255,128,56,0,0,0,7,224,0,0,56,0,0,0,7,0,0,0,112,0,0,0,3,240,0,1,240,0,127,128,1,255,224,63,224,0,127,192,0,127,255,255,128,0,113,224,0,15,255,255,128,0,112,112,0,14,0,3,128,0,112,56,0,14,0,3,128,15,48,56,0,14,0,3,248,15,56,28,0,14,0,7,254,15,56,28,7,254,0,15,63,207,56,15,255,255,0,62,3,254,24,15,255,247,195,252,0,254,28,2,0,3,255,240,0,62,28,0,0,1,255,128,0,14,12,0,0,0,0,0,0,7,14,0,0,0,0,0,0,7,14,0,0,0,0,0,0,7,7,0,0,0,0,0,0,14,3,192,0,0,0,0,0,14,1,248,0,0,0,0,0,62,0,127,0,0,0,0,0,126,0,31,224,0,0,0,1,254,0,3,254,0,0,0,15,206,0,0,127,248,0,0,255,15,0,0,15,255,255,255,252,15,0,0,0,127,255,255,224,14,0,0,0,0,63,248,0,0,0,0,0,0,0,112,0,0,0,0,0,0,0,63,0,0,0,0,0,0,0,31,192,0,0,0,0,0,0,63,192,0,0,0,0,0,0,56,224,0,0,0,0,0,0,56,224,0,0,0,0,0,0,56,224,0,0,0,0,0,0,63,192,0,0,0,0,0,0,31,192,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,128,0,0,0,0,0,0,7,192,0,0,0,0,0,0,3,192,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,224,0,0,0,0,0,3,255,240,0,0,0,1,255,255,255,240,0,0,0,7,255,255,224,56,0,0,0,7,252,0,0,56,0,0,0,7,0,0,0,112,0,0,0,7,224,0,0,240,0,127,0,3,255,0,31,224,0,255,192,0,255,255,255,192,0,127,224,0,15,255,255,128,0,112,112,0,14,0,3,128,0,112,112,0,14,0,3,128,0,112,56,0,14,0,3,240,15,48,60,0,14,0,7,254,15,56,28,0,254,0,15,127,207,56,15,255,254,0,30,7,239,24,15,255,255,129,252,0,254,28,7,192,3,255,240,0,62,28,0,0,1,255,192,0,14,28,0,0,0,0,0,0,7,12,0,0,0,0,0,0,7,14,0,0,0,0,0,0,7,15,0,0,0,0,0,0,14,7,192,0,0,0,0,0,14,1,240,0,0,0,0,0,30,0,254,0,0,0,0,0,126,0,63,192,0,0,0,1,255,0,7,252,0,0,0,7,239,0,0,255,224,0,0,127,143,0,0,31,255,255,255,252,6,0,0,0,255,255,255,224,0,0,0,0,1,255,254,0,0,0,0,0,0,0,112,0,0,0,0,0,0,0,62,0,0,0,0,0,0,0,31,128,0,0,0,0,0,0,31,192,0,0,0,0,0,0,56,224,0,0,0,0,0,0,56,224,0,0,0,0,0,0,56,224,0,0,0,0,0,0,61,192,0,0,0,0,0,0,31,192,0,0,0,0,0,0,15,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,192,0,0,0,0,0,1,255,240,0,0,0,0,255,255,255,240,0,0,0,7,255,255,240,56,0,0,0,7,255,192,0,48,0,0,0,7,0,0,0,112,0,0,0,7,192,0,0,240,0,126,0,3,252,0,15,224,0,255,192,0,255,255,255,192,0,255,224,0,31,255,255,128,0,96,240,0,14,12,3,128,0,112,112,0,14,0,3,128,0,112,56,0,14,0,3,240,0,48,56,0,14,0,7,254,6,56,28,0,30,0,7,255,143,56,31,255,254,0,30,7,239,56,15,255,255,0,252,0,255,24,7,252,7,255,248,0,62,28,0,0,3,255,192,0,30,28,0,0,0,120,0,0,7,28,0,0,0,0,0,0,7,14,0,0,0,0,0,0,7,15,0,0,0,0,0,0,7,7,128,0,0,0,0,0,14,3,224,0,0,0,0,0,30,0,252,0,0,0,0,0,127,0,127,128,0,0,0,1,255,0,15,240,0,0,0,7,239,0,1,255,128,0,0,63,128,0,0,63,255,240,207,254,0,0,0,3,255,255,255,240,0,0,0,0,7,255,255,0,0,0,0,0,0,0,112,0,0,0,0,0,0,0,56,0,0,0,0,0,0,0,63,128,0,0,0,0,0,0,31,192,0,0,0,0,0,0,56,224,0,0,0,0,0,0,56,224,0,0,0,0,0,0,56,224,0,0,0,0,0,0,61,224,0,0,0,0,0,0,31,192,0,0,0,0,0,0,15,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,240,0,0,0,0,15,255,255,240,0,0,0,7,255,255,248,56,0,0,0,7,255,240,0,48,0,0,0,7,0,0,0,112,0,0,0,7,128,0,0,240,0,0,0,3,248,0,7,224,0,255,128,1,255,255,255,192,0,255,192,0,63,255,255,128,0,97,224,0,14,127,195,128,0,96,112,0,14,0,3,128,0,112,112,0,14,0,3,224,7,112,56,0,14,0,3,254,15,48,28,0,14,0,7,255,143,56,28,63,254,0,30,7,239,56,15,255,255,0,124,1,255,56,15,255,7,255,248,0,62,24,0,0,3,255,224,0,30,28,0,0,0,254,0,0,7,28,0,0,0,0,0,0,7,12,0,0,0,0,0,0,7,14,0,0,0,0,0,0,7,7,0,0,0,0,0,0,14,3,192,0,0,0,0,0,30,1,248,0,0,0,0,0,63,0,127,0,0,0,0,0,255,0,31,224,0,0,0,7,239,0,3,255,0,0,0,63,207,0,0,127,255,0,7,254,6,0,0,7,255,255,255,248,0,0,0,0,63,255,255,128,0,0,0,0,0,0,240,0,0,0,0,0,0,0,120,0,0,0,0,0,0,0,63,128,0,0,0,0,0,0,31,192,0,0,0,0,0,0,60,224,0,0,0,0,0,0,56,224,0,0,0,0,0,0,56,224,0,0,0,0,0,0,56,224,0,0,0,0,0,0,31,192,0,0,0,0,0,0,15,128,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};


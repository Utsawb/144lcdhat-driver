#pragma once

#include "lcd.h"
#include <stdint.h>

static inline void image_clear(uint16_t *image, const uint16_t color)
{
    for (uint16_t p = 0; p < LCD_WIDTH * LCD_HEIGHT; ++p)
    {
        image[p] = color;
    }
}

static inline void image_draw_point(uint16_t *image, const uint16_t x, const uint16_t y, const uint16_t color)
{
    if (x < 0 || x > LCD_WIDTH || y < 0 || y > LCD_HEIGHT)
    {
        return;
    }
    image[x + y * LCD_WIDTH] = color;
}

static inline void image_draw_line(uint16_t *image, uint16_t x_start, uint16_t y_start, const uint16_t x_end,
                                   const uint16_t y_end, const uint16_t color)
{
    int16_t dx = abs(x_end - x_start);
    int16_t dy = abs(y_end - y_start);
    int16_t sx, sy;

    if (x_start < x_end)
        sx = 1;
    else
        sx = -1;

    if (y_start < y_end)
        sy = 1;
    else
        sy = -1;

    int16_t err = dx - dy;

    while (1)
    {
        image_draw_point(image, x_start, y_start, color);

        if (x_start == x_end && y_start == y_end)
            break;

        int16_t e2 = 2 * err;

        if (e2 > -dy)
        {
            err -= dy;
            x_start += sx;
        }

        if (x_start == x_end && y_start == y_end)
        {
            image_draw_point(image, x_start, y_start, color);
            break;
        }

        if (e2 < dx)
        {
            err += dx;
            y_start += sy;
        }
    }
}

static inline void image_draw_circle(uint16_t *image, const uint16_t x, const uint16_t y, const uint8_t radius,
                                     const uint8_t fill, const uint16_t color)
{
    int16_t x_pos = radius;
    int16_t y_pos = 0;
    int16_t radius_error = 1 - x_pos;

    while (x_pos >= y_pos)
    {
        if (fill)
        {
            for (int16_t i = y_pos + y; i <= x + x_pos; ++i)
            {
                image_draw_point(image, i, x - x_pos, color);
                image_draw_point(image, i, x + x_pos, color);
            }
            for (int16_t i = x - x_pos; i <= x + x_pos; ++i)
            {
                image_draw_point(image, y + y_pos, i, color);
                image_draw_point(image, y - y_pos, i, color);
            }
        }
        else
        {
            image_draw_point(image, y + y_pos, x - x_pos, color);
            image_draw_point(image, y - y_pos, x - x_pos, color);
            image_draw_point(image, y + y_pos, x + x_pos, color);
            image_draw_point(image, y - y_pos, x + x_pos, color);
            image_draw_point(image, x + x_pos, y + y_pos, color);
            image_draw_point(image, x - x_pos, y + y_pos, color);
            image_draw_point(image, x + x_pos, y - y_pos, color);
            image_draw_point(image, x - x_pos, y - y_pos, color);
        }

        y_pos++;

        if (radius_error < 0)
            radius_error += 2 * y_pos + 1;
        else
        {
            x_pos--;
            radius_error += 2 * (y_pos - x_pos + 1);
        }
    }
}

#define MAX_HEIGHT_FONT 41
#define MAX_WIDTH_FONT 32
#define OFFSET_BITMAP

typedef struct font
{
    const uint8_t *table;
    uint16_t width;
    uint16_t height;
} font;

extern font font24;
extern font font20;
extern font font16;
extern font font12;
extern font font8;

static inline void image_draw_char(uint16_t *image, const uint16_t x, const uint16_t y, const char c,
                                   const uint16_t color, const font *f)
{

    uint32_t char_offset = (c - ' ') * f->height * (f->width / 8 + (f->width % 8 ? 1 : 0));
    const uint8_t *ptr = f->table + char_offset;

    for (uint16_t page = 0; page < f->height; ++page)
    {
        for (uint16_t column = 0; column < f->width; ++column)
        {
            if (*ptr & (0x80 >> (column % 8)))
            {
                image_draw_point(image, x + column, y + page, color);
            }
            if (column % 8 == 7)
            {
                ++ptr;
            }
        }
        if (f->width % 8 != 0)
        {
            ++ptr;
        }
    }
}

static inline void image_draw_string(uint16_t *image, const uint16_t x, const uint16_t y, const char *str,
                                     const uint16_t color, const font *f)
{
    uint16_t x_pt = x;
    uint16_t y_pt = y;

    while (*str != '\0')
    {
        if (x_pt + f->width > LCD_WIDTH)
        {
            x_pt = x;
            y_pt += f->height;
        }

        if (y_pt + f->height > LCD_HEIGHT)
        {
            x_pt = x;
            y_pt = y;
        }

        image_draw_char(image, x_pt, y_pt, *str, color, f);

        ++str;

        x_pt += f->width;
    }
}

#define ARRAY_LEN 255
static inline void image_draw_number(uint16_t *image, const uint16_t x, const uint16_t y, uint32_t number, const uint16_t color, font *f)
{
    int16_t num_bit = 0;
    int16_t str_bit = 0;

    uint8_t str_arr[ARRAY_LEN] = {0};
    uint8_t num_arr[ARRAY_LEN] = {0};
    uint8_t *ptr = str_arr;

    while (number)
    {
        num_arr[num_bit] = number % 10 + '0';
        ++num_bit;
        number /= 10;
    }

    while (num_bit > 0)
    {
        str_arr[str_bit] = num_arr[num_bit - 1];
        ++str_bit;
        --num_bit;
    }

    image_draw_string(image, x, y, (const char *) ptr, color, f);
}

/*****************************************************************************
 * | File      	:   .c
 * | Author      :   Waveshare team
 * | Function    :   Hardware underlying interface
 * | Info        :
 *                Used to shield the underlying layers of each master
 *                and enhance portability
 *----------------
 * |	This version:   V1.0
 * | Date        :   2018-01-11
 * | Info        :   Basic version
 *
 ******************************************************************************/
#include <time.h>

#include "Debug.h"
#include "GUI_Paint.h"
#include "LCD_1in44.h"
#include "bcm2835.h"

typedef struct c
{
    DOT_PIXEL line_width;
    DRAW_FILL draw_fill;
    uint16_t color;
    uint8_t radius;

    uint8_t pos_x;
    uint8_t pos_y;
    uint8_t vel_x;
    uint8_t vel_y;

} Circle;

void draw_circle(const Circle *c)
{
    Paint_DrawCircle(c->pos_x, c->pos_y, c->radius, c->color, c->line_width, c->draw_fill);
    GUI_Partial_Refresh(c->pos_x - c->radius * 1.75, c->pos_y - c->radius * 1.75, c->pos_x + c->radius * 1.75, c->pos_y + c->radius * 1.75);
}

void update_circle(Circle *c)
{
    c->pos_x = c->pos_x + c->vel_x;
    c->pos_y = c->pos_y + c->vel_y;

    if (c->pos_x < c->radius + 1)
    {
        c->pos_x = c->radius + 1;
        c->vel_x = c->vel_x * -1;
    }
    else if (c->pos_x > LCD_WIDTH - c->radius)
    {
        c->pos_x = LCD_WIDTH - c->radius;
        c->vel_x = c->vel_x * -1;
    }

    if (c->pos_y < c->radius + 1)
    {
        c->pos_y = c->radius + 1;
        c->vel_y = c->vel_y * -1;
    }
    else if (c->pos_y > LCD_HEIGHT - c->radius)
    {
        c->pos_y = LCD_HEIGHT - c->radius;
        c->vel_y = c->vel_y * -1;
    }
}

Circle c1;
Circle c2;

clock_t tic;
clock_t toc;
uint16_t bg_color;

void init(UWORD *Image)
{
    c1.line_width = DOT_PIXEL_DFT;
    c1.draw_fill = DRAW_FILL_FULL;
    c1.color = WHITE;
    c1.radius = 5;
    c1.pos_x = LCD_WIDTH / 2;
    c1.pos_y = LCD_HEIGHT / 2;
    c1.vel_x = 2;
    c1.vel_y = 1;

    c2.line_width = DOT_PIXEL_DFT;
    c2.draw_fill = DRAW_FILL_FULL;
    c2.color = WHITE;
    c2.radius = 5;
    c2.pos_x = LCD_WIDTH / 2;
    c2.pos_y = LCD_HEIGHT / 2;
    c2.vel_x = -1;
    c2.vel_y = -2;


    bg_color = BLACK;

    Paint_Clear(BLACK);
    LCD_1in44_Display(Image);
}

void loop(UWORD *Image)
{
    tic = clock();

    Paint_Clear(bg_color);
    update_circle(&c1);
    update_circle(&c2);
    draw_circle(&c1);
    draw_circle(&c2);

    if (GET_KEY1 == 0)
    {
        bg_color = BLACK;
        c1.color = WHITE;
        c2.color = WHITE;
    }
    else if (GET_KEY2 == 0)
    {
        bg_color = WHITE;
        c1.color = BLACK;
        c2.color = BLACK;
    }
    else if (GET_KEY3 == 0)
    {
        bg_color = MAGENTA;
        c1.color = GRAY;
        c2.color = GRAY;
    }
    else if (GET_KEY_PRESS == 0)
    {
        LCD_1in44_Display(Image);
    }

    toc = clock();

    delay((1.0 / 25.0 * 1000) - ((double) (toc - tic) / CLOCKS_PER_SEC * 1000));

    // LCD_1in44_Display(Image);
}

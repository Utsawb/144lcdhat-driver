#include "animation.h"
#include "image.h"
#include "lcd.h"

#include <signal.h>
#include <stdlib.h>

const uint16_t colors[] = {WHITE,   BLACK, BLUE, BRED,   GRED,  GBLUE, RED,
                           MAGENTA, GREEN, CYAN, YELLOW, BROWN, BRRED, GRAY};

uint16_t image[LCD_WIDTH * LCD_HEIGHT] = {BLACK};

uint32_t val = 0;

void exit_handler(int errorno)
{
    digital_write(LCD_BL, 0);
    lcd_deinit();
    gpio_deinit();
    exit(0);
}

int main(void)
{
    signal(SIGINT, exit_handler);

    gpio_init();
    lcd_init();

    lcd_clear(BLACK);

    const uint16_t x_offset = 0;
    const uint16_t y_offset = 0;
    uint8_t frame_number = 0;
    printf("The frame count function says: %d\n", FRAME_COUNT);
    while (1)
    {
        image_clear(image, BLACK);

        for (uint16_t i = 0; i < FRAME_WIDTH; ++i)
        {
            for (uint16_t j = 0; j < FRAME_HEIGHT; ++j)
            {
                image[(i + x_offset) + (j + y_offset) * LCD_WIDTH] =
                    (frames[frame_number][(i + j * FRAME_HEIGHT) / 8] >> ((i + j * FRAME_HEIGHT) % 8)) & 0b1 ? WHITE
                                                                                                             : BLACK;
            }
        }

        frame_number = (frame_number + 1) % 28
        lcd_display(image);
        delay(10);
    }

    lcd_deinit();
    gpio_deinit();
    return 0;
}

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

    while (1)
    {
        if (digital_read(KEY1_PIN) == 0)
        {
            while (digital_read(KEY1_PIN) == 0)
            {
            }
            ++val;
        }
        else if (digital_read(KEY2_PIN) == 0)
        {
            while (digital_read(KEY2_PIN) == 0)
            {
            }
            --val;
        }

        image_clear(image, BLACK);
        image_draw_number(image, LCD_WIDTH / 4, LCD_HEIGHT / 2, val, WHITE, &font16);
        lcd_display(image);
        delay(32);
    }

    lcd_deinit();
    gpio_deinit();
    return 0;
}

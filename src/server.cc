#include "cc-socket-wrappers/udp.hh"
#include "common.h"
#include "lcd.h"

#include <signal.h>

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
    uint16_t image[LCD_WIDTH * LCD_HEIGHT] = {Mantle};
    jj::UDP server("0.0.0.0", "5000", jj::UDP::Side::SERVER);
    uint8_t button_flags = 0; // U D L R P 1 2 3

    gpio_init();
    lcd_init();

    lcd_clear(Mantle);
    while (1)
    {
        button_flags = 0;
        if (digital_read(KEY_UP_PIN) == 0)
        {
            button_flags |= 0b1;
            // std::cout << "U\n";
        }
        if (digital_read(KEY_DOWN_PIN) == 0)
        {
            button_flags |= 0b10;
            // std::cout << "D\n";
        }
        if (digital_read(KEY_LEFT_PIN) == 0)
        {
            button_flags |= 0b100;
            // std::cout << "L\n";
        }
        if (digital_read(KEY_RIGHT_PIN) == 0)
        {
            button_flags |= 0b1000;
            // std::cout << "R\n";
        }
        if (digital_read(KEY_PRESS_PIN) == 0)
        {
            button_flags |= 0b10000;
            // std::cout << "P\n";
        }
        if (digital_read(KEY1_PIN) == 0)
        {
            button_flags |= 0b100000;
            // std::cout << "1\n";
        }
        if (digital_read(KEY2_PIN) == 0)
        {
            button_flags |= 0b1000000;
            // std::cout << "2\n";
        }
        if (digital_read(KEY3_PIN) == 0)
        {
            button_flags |= 0b10000000;
            // std::cout << "3\n";
        }
        server << button_flags;

        server.read(image, LCD_WIDTH * LCD_HEIGHT * sizeof(uint16_t));
        lcd_display(image);
    }

    lcd_deinit();
    gpio_deinit();
    return 0;
}

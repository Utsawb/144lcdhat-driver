#include "cc-socket-wrappers/udp.hh"
#include "common.h"
#include "lcd.h"

#include <signal.h>

uint16_t image[LCD_WIDTH * LCD_HEIGHT] = {Mantle};
jj::UDP server("0.0.0.0", "5000", jj::UDP::Side::SERVER);

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

    lcd_clear(Mantle);
    while (1)
    {
        server.read(image, LCD_WIDTH * LCD_HEIGHT * sizeof(uint16_t));
        lcd_display(image);
    }

    lcd_deinit();
    gpio_deinit();
    return 0;
}

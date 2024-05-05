#include "cc-socket-wrappers/udp.hh"
#include "common.h"
#include "lcd.h"

#include <signal.h>

uint16_t image[LCD_WIDTH * LCD_HEIGHT] = {Lavender};
jj::UDP pc_to_rpi("0.0.0.0", "5000", jj::UDP::Side::SERVER);
jj::UDP rpi_to_pc("192.168.1.3", "6000", jj::UDP::CLIENT);

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

    lcd_clear(CYAN);
    while (1)
    {
        pc_to_rpi.read(image, LCD_WIDTH * LCD_HEIGHT * sizeof(uint16_t));
        lcd_display(image);
        rpi_to_pc << true;
    }

    lcd_deinit();
    gpio_deinit();
    return 0;
}

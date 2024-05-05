#include "cc-socket-wrappers/tcp.hh"
#include "lcd.h"

#include <signal.h>

uint16_t image[LCD_WIDTH * LCD_HEIGHT] = {BLACK};
jj::TCP* server;

void exit_handler(int errorno)
{
    delete server;
    digital_write(LCD_BL, 0);
    lcd_deinit();
    gpio_deinit();
    exit(0);
}

int main(void)
{
    signal(SIGINT, exit_handler);
    server = new jj::TCP("0.0.0.0", "5000", jj::TCP::Side::SERVER);

    gpio_init();
    lcd_init();

    lcd_clear(BLACK);
    auto accepted = server->accept_connection(1);

    while (1)
    {
        accepted.read(image, LCD_WIDTH * LCD_HEIGHT * sizeof(uint16_t));
        lcd_display(image);
    }

    lcd_deinit();
    gpio_deinit();
    return 0;
}

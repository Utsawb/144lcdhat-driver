#include "animation.h"
#include "cc-socket-wrappers/udp.hh"
#include "image.h"

uint16_t image[LCD_WIDTH * LCD_HEIGHT] = {BLACK};

int main(void)
{
    jj::UDP client("192.168.1.7", "5000", jj::UDP::CLIENT);

    const uint16_t x_offset = 0;
    const uint16_t y_offset = 0;
    uint8_t frame_number = 0;

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

        frame_number = (frame_number + 1) % FRAME_COUNT;
        client.write(image, LCD_WIDTH * LCD_HEIGHT * sizeof(uint16_t));
    }
}

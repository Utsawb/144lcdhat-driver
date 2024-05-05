#include "animation.h"
#include "cc-socket-wrappers/udp.hh"
#include "image.h"

#include <chrono>
#include <thread>

uint16_t image[LCD_WIDTH * LCD_HEIGHT] = {Mantle};
jj::UDP client("192.168.1.7", "5000", jj::UDP::CLIENT);

int main(void)
{
    const uint16_t x_offset = 32;
    const uint16_t y_offset = 32;
    uint8_t frame_number = 0;

    while (1)
    {
        image_clear(image, Overlay0);
        for (uint16_t i = 0; i < FRAME_WIDTH; ++i)
        {
            for (uint16_t j = 0; j < FRAME_HEIGHT; ++j)
            {
                image[(i + x_offset) + (j + y_offset) * LCD_WIDTH] =
                    (frames[frame_number][(i + j * FRAME_HEIGHT) / 8] >> ((i + j * FRAME_HEIGHT) % 8)) & 0b1 ? COLOR_FIX(colors[frame_number % COLOR_SIZE])
                                                                                                             : COLOR_FIX(Overlay0);
            }
        }
        client.write(image, LCD_WIDTH * LCD_HEIGHT * sizeof(uint16_t));
        std::this_thread::sleep_for(std::chrono::milliseconds( (int) 1000 / 30));
        frame_number = (frame_number + 1) % FRAME_COUNT;
    }
}

#include "animation.h"
#include "cc-socket-wrappers/tcp.hh"
#include "image.h"

#include <chrono>
#include <thread>
#include <signal.h>

uint16_t image[LCD_WIDTH * LCD_HEIGHT] = {BLACK};
jj::TCP* client;

void exit_handler(int errorno)
{
    delete client;
    exit(0);
}

int main(void)
{
    signal(SIGINT, exit_handler);
    client = new jj::TCP("192.168.1.7", "5000", jj::TCP::CLIENT);
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
        printf("Frame Number: %d\n", frame_number);
        client->write(image, LCD_WIDTH * LCD_HEIGHT * sizeof(uint16_t));
        std::this_thread::sleep_for(std::chrono::milliseconds(66));
    }
}

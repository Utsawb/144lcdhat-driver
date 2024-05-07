#include <chrono>
#include <thread>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

#include "cc-socket-wrappers/udp.hh"
#include "image.h"

#include <X11/Xlib.h>
#include <X11/Xutil.h>

class ScreenShot
{
    private:
        Display *display;
        Window root;
        XImage *img{nullptr};

    public:
        ScreenShot()
        {
            display = XOpenDisplay(nullptr);
            root = DefaultRootWindow(display);
        }

        void operator()(cv::Mat &cvImg, int x, int y, int width, int height)
        {
            if (img != nullptr)
                XDestroyImage(img);
            img = XGetImage(display, root, x, y, width, height, AllPlanes, ZPixmap);
            cvImg = cv::Mat(height, width, CV_8UC4, img->data);
        }

        ~ScreenShot()
        {
            if (img != nullptr)
                XDestroyImage(img);
            XCloseDisplay(display);
        }
};

constexpr int screen_width = 1920;
constexpr int screen_height = 1080;
constexpr int window_width = 256;
constexpr int window_height = 256;

int main(void)
{
    jj::UDP client("192.168.1.7", "5000", jj::UDP::CLIENT);
    uint16_t image[LCD_WIDTH * LCD_HEIGHT] = {Lavender};
    cv::Mat original_frame;
    uint8_t button_flags = 0; // U D L R P 1 2 3
    cv::namedWindow("Video", cv::WINDOW_GUI_NORMAL);

    int x = 0, y = 0;
    int speed = 10;

    ScreenShot screen;
    cv::VideoCapture capture(0);
    if (!capture.isOpened())
    {
        return 1;
    }

    client.write(image, LCD_WIDTH * LCD_HEIGHT * sizeof(uint16_t));
    while (1)
    {
        button_flags = 0;
        client >> button_flags;
        if (button_flags & 0b1)
        {
            y = (y - speed < 0) ? 0 : y - speed;
        }
        if (button_flags & 0b10)
        {
            y = (y + speed > screen_height - window_height) ? screen_height - window_height : y + speed;
        }
        if (button_flags & 0b100)
        {
            x = (x - speed < 0) ? 0 : x - speed;
        }
        if (button_flags & 0b1000)
        {
            x = (x + speed > screen_width - window_width) ? screen_width - window_width : x + speed;
        }

        if (button_flags & 0b10000)
        {
            capture.read(original_frame);
        }
        else
        {
            screen(original_frame, x, y, window_width, window_height);
        }

        if (button_flags & 0b100000)
        {
            speed = 20;
            x = 0;
            y = 0;
        }
        else if (button_flags & 0b1000000)
        {
            speed = 40;
            x = 0;
            y = 0;
        }
        else if (button_flags & 0b10000000)
        {
            speed = 80;
            x = 0;
            y = 0;
        }

        cv::resize(original_frame, original_frame, cv::Size(128, 128), cv::INTER_CUBIC);
        cv::cvtColor(original_frame, original_frame, cv::COLOR_BGR2RGB);

        for (int y = 0; y < original_frame.rows; y++)
        {
            for (int x = 0; x < original_frame.cols; x++)
            {
                cv::Vec3b pixel = original_frame.at<cv::Vec3b>(y, x);
                uint16_t r = (pixel[0] >> 3) & 0x1F;
                uint16_t g = (pixel[1] >> 2) & 0x3F;
                uint16_t b = (pixel[2] >> 3) & 0x1F;
                image[y * LCD_WIDTH + x] = (r << 11) | (g << 5) | b;
                image[y * LCD_WIDTH + x] = SWAP_ENDIAN(image[y * LCD_WIDTH + x]);
            }
        }

        client.write(image, LCD_WIDTH * LCD_HEIGHT * sizeof(uint16_t));
        std::this_thread::sleep_for(std::chrono::milliseconds((int)1000 / 24));
    }
}

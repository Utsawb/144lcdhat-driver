#pragma once

#include "gpio.h"

#define LCD_CS 8
#define LCD_RST 27
#define LCD_DC 25
#define LCD_BL 24

#define KEY_UP_PIN 6
#define KEY_DOWN_PIN 19
#define KEY_LEFT_PIN 5
#define KEY_RIGHT_PIN 26
#define KEY_PRESS_PIN 13
#define KEY1_PIN 21
#define KEY2_PIN 20
#define KEY3_PIN 16

#define LCD_HEIGHT 128
#define LCD_WIDTH 128

#define LCD_X 2
#define LCD_Y 1

#define LCD_WIDTH_Byte 240

#define HORIZONTAL 0
#define VERTICAL 1

#define LCD_X_MAXPIXEL 132 // LCD width maximum memory
#define LCD_Y_MAXPIXEL 162 // LCD height maximum memory

#define WHITE 0xFFFF
#define BLACK 0x0000
#define BLUE 0x001F
#define BRED 0XF81F
#define GRED 0XFFE0
#define GBLUE 0X07FF
#define RED 0xF800
#define MAGENTA 0xF81F
#define GREEN 0x07E0
#define CYAN 0x7FFF
#define YELLOW 0xFFE0
#define BROWN 0XBC40
#define BRRED 0XFC07
#define GRAY 0X8430

typedef enum
{
    L2R_U2D = 0, // The display interface is displayed , left to right, up to down
    L2R_D2U,
    R2L_U2D,
    R2L_D2U,

    U2D_L2R,
    U2D_R2L,
    D2U_L2R,
    D2U_R2L,
} LCD_SCAN_DIR;
#define SCAN_DIR_DFT U2D_R2L // Default scan direction = L2R_U2D

typedef struct
{
        uint16_t LCD_Dis_Column; // COLUMN
        uint16_t LCD_Dis_Page;   // PAGE
        LCD_SCAN_DIR LCD_Scan_Dir;
        uint16_t LCD_X_Adjust; // LCD x actual display position calibration
        uint16_t LCD_Y_Adjust; // LCD y actual display position calibration
} LCD_DIS;

LCD_DIS sLCD_DIS;

static inline void lcd_deinit(void)
{
    bcm2835_spi_end();
}

static inline void lcd_reset(void)
{
    digital_write(LCD_RST, 1);
    delay(100);
    digital_write(LCD_RST, 0);
    delay(100);
    digital_write(LCD_RST, 1);
    delay(100);
}

static inline void lcd_send_command(uint8_t reg)
{
    digital_write(LCD_DC, 0);
    spi_write_byte(reg);
}

static inline void lcd_send_data_8bit(uint8_t data)
{
    digital_write(LCD_DC, 1);
    spi_write_byte(data);
}

static inline void lcd_send_data_16bit(uint16_t data)
{
    digital_write(LCD_DC, 1);
    spi_write_byte((data >> 8) & 0xFF);
    spi_write_byte(data & 0xFF);
}

static inline void lcd_set_gram_scan_way(LCD_SCAN_DIR scan_dir)
{
    // Get the screen scan direction
    sLCD_DIS.LCD_Scan_Dir = scan_dir;

    // Get GRAM and LCD width and height
    if (scan_dir == L2R_U2D || scan_dir == L2R_D2U || scan_dir == R2L_U2D || scan_dir == R2L_D2U)
    {
        sLCD_DIS.LCD_Dis_Column = LCD_HEIGHT;
        sLCD_DIS.LCD_Dis_Page = LCD_WIDTH;
    }
    else
    {
        sLCD_DIS.LCD_Dis_Column = LCD_WIDTH;
        sLCD_DIS.LCD_Dis_Page = LCD_HEIGHT;
    }

    // Gets the scan direction of GRAM
    uint16_t MemoryAccessReg_Data = 0; // 0x36
    switch (scan_dir)
    {
    case L2R_U2D:
        MemoryAccessReg_Data = 0X00 | 0x00; // x Scan direction | y Scan direction
        break;
    case L2R_D2U:
        MemoryAccessReg_Data = 0x00 | 0x80; // 0xC8 | 0X10
        break;
    case R2L_U2D: //	0X4
        MemoryAccessReg_Data = 0x40 | 0x00;
        break;
    case R2L_D2U: //	0XC
        MemoryAccessReg_Data = 0x40 | 0x80;
        break;
    case U2D_L2R: // 0X2
        MemoryAccessReg_Data = 0X00 | 0X00 | 0x20;
        break;
    case U2D_R2L: // 0X6
        MemoryAccessReg_Data = 0x00 | 0X40 | 0x20;
        break;
    case D2U_L2R: // 0XA
        MemoryAccessReg_Data = 0x80 | 0x00 | 0x20;
        break;
    case D2U_R2L: // 0XE
        MemoryAccessReg_Data = 0x40 | 0x80 | 0x20;
        break;
    }

    // please set (MemoryAccessReg_Data & 0x10) != 1
    // come back to this later?? what does this mean??
    if ((MemoryAccessReg_Data & 0x20) != 1)
    {
        sLCD_DIS.LCD_X_Adjust = LCD_X;
        sLCD_DIS.LCD_Y_Adjust = LCD_Y;
    }
    else
    {
        sLCD_DIS.LCD_X_Adjust = LCD_Y;
        sLCD_DIS.LCD_Y_Adjust = LCD_X;
    }

    // Set the read / write scan direction of the frame memory
    lcd_send_command(0x36);                          // MX, MY, RGB mode
    lcd_send_data_8bit(MemoryAccessReg_Data | 0x08); // 0x08 set RGB
}

static inline void lcd_init_reg(void)
{
    // ST7735R Frame Rate
    lcd_send_command(0xB1);
    lcd_send_data_8bit(0x01);
    lcd_send_data_8bit(0x2C);
    lcd_send_data_8bit(0x2D);

    lcd_send_command(0xB2);
    lcd_send_data_8bit(0x01);
    lcd_send_data_8bit(0x2C);
    lcd_send_data_8bit(0x2D);

    lcd_send_command(0xB3);
    lcd_send_data_8bit(0x01);
    lcd_send_data_8bit(0x2C);
    lcd_send_data_8bit(0x2D);
    lcd_send_data_8bit(0x01);
    lcd_send_data_8bit(0x2C);
    lcd_send_data_8bit(0x2D);

    lcd_send_command(0xB4); // Column inversion
    lcd_send_data_8bit(0x07);

    // ST7735R Power Sequence
    lcd_send_command(0xC0);
    lcd_send_data_8bit(0xA2);
    lcd_send_data_8bit(0x02);
    lcd_send_data_8bit(0x84);
    lcd_send_command(0xC1);
    lcd_send_data_8bit(0xC5);

    lcd_send_command(0xC2);
    lcd_send_data_8bit(0x0A);
    lcd_send_data_8bit(0x00);

    lcd_send_command(0xC3);
    lcd_send_data_8bit(0x8A);
    lcd_send_data_8bit(0x2A);
    lcd_send_command(0xC4);
    lcd_send_data_8bit(0x8A);
    lcd_send_data_8bit(0xEE);

    lcd_send_command(0xC5); // VCOM
    lcd_send_data_8bit(0x0E);

    // ST7735R Gamma Sequence
    lcd_send_command(0xe0);
    lcd_send_data_8bit(0x0f);
    lcd_send_data_8bit(0x1a);
    lcd_send_data_8bit(0x0f);
    lcd_send_data_8bit(0x18);
    lcd_send_data_8bit(0x2f);
    lcd_send_data_8bit(0x28);
    lcd_send_data_8bit(0x20);
    lcd_send_data_8bit(0x22);
    lcd_send_data_8bit(0x1f);
    lcd_send_data_8bit(0x1b);
    lcd_send_data_8bit(0x23);
    lcd_send_data_8bit(0x37);
    lcd_send_data_8bit(0x00);
    lcd_send_data_8bit(0x07);
    lcd_send_data_8bit(0x02);
    lcd_send_data_8bit(0x10);

    lcd_send_command(0xe1);
    lcd_send_data_8bit(0x0f);
    lcd_send_data_8bit(0x1b);
    lcd_send_data_8bit(0x0f);
    lcd_send_data_8bit(0x17);
    lcd_send_data_8bit(0x33);
    lcd_send_data_8bit(0x2c);
    lcd_send_data_8bit(0x29);
    lcd_send_data_8bit(0x2e);
    lcd_send_data_8bit(0x30);
    lcd_send_data_8bit(0x30);
    lcd_send_data_8bit(0x39);
    lcd_send_data_8bit(0x3f);
    lcd_send_data_8bit(0x00);
    lcd_send_data_8bit(0x07);
    lcd_send_data_8bit(0x03);
    lcd_send_data_8bit(0x10);

    lcd_send_command(0xF0); // Enable test command
    lcd_send_data_8bit(0x01);

    lcd_send_command(0xF6); // Disable ram power save mode
    lcd_send_data_8bit(0x00);

    lcd_send_command(0x3A); // 65k mode
    lcd_send_data_8bit(0x05);
}

static inline void lcd_init(void)
{
    pin_mode(LCD_CS, 1);
    pin_mode(LCD_RST, 1);
    pin_mode(LCD_DC, 1);
    pin_mode(LCD_BL, 1);

    pin_mode(KEY_UP_PIN, 0);
    pin_mode(KEY_DOWN_PIN, 0);
    pin_mode(KEY_LEFT_PIN, 0);
    pin_mode(KEY_RIGHT_PIN, 0);
    pin_mode(KEY_PRESS_PIN, 0);
    pin_mode(KEY1_PIN, 0);
    pin_mode(KEY2_PIN, 0);
    pin_mode(KEY3_PIN, 0);

    digital_write(LCD_CS, 1);

    bcm2835_spi_begin();
    bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);
    bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);
    bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_8);
    bcm2835_spi_chipSelect(BCM2835_SPI_CS0);
    bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);

    digital_write(LCD_BL, 1);
    lcd_reset();
    lcd_init_reg();
    lcd_set_gram_scan_way(SCAN_DIR_DFT);
    delay(100);
    lcd_send_command(0x11);
    delay(120);
    lcd_send_command(0x29);
}

static inline void lcd_set_windows(uint16_t x_start, uint16_t y_start, uint16_t x_end, uint16_t y_end)
{
    // set the X coordinates
    lcd_send_command(0x2A);
    lcd_send_data_8bit(0x00);                                     // Set the horizontal starting point to the high octet
    lcd_send_data_8bit((x_start & 0xff) + sLCD_DIS.LCD_X_Adjust); // Set the horizontal starting point to the low octet
    lcd_send_data_8bit(0x00);                                     // Set the horizontal end to the high octet
    lcd_send_data_8bit(((x_end - 1) & 0xff) + sLCD_DIS.LCD_X_Adjust); // Set the horizontal end to the low octet

    // set the Y coordinates
    lcd_send_command(0x2B);
    lcd_send_data_8bit(0x00);
    lcd_send_data_8bit((y_start & 0xff) + sLCD_DIS.LCD_Y_Adjust);
    lcd_send_data_8bit(0x00);
    lcd_send_data_8bit(((y_end - 1) & 0xff) + sLCD_DIS.LCD_Y_Adjust);

    lcd_send_command(0x2C);
}

static inline void lcd_display(uint16_t *image)
{
    lcd_set_windows(0, 0, LCD_WIDTH, LCD_HEIGHT);
    digital_write(LCD_DC, 1);
    for (uint16_t j = 0; j < LCD_HEIGHT; ++j)
    {
        spi_write_nbytes((uint8_t *)(image + j * LCD_WIDTH), LCD_WIDTH * 2);
    }
}

static inline void lcd_display_windows(uint16_t x_start, uint16_t y_start, uint16_t x_end, uint16_t y_end,
                                       uint16_t *image)
{
    uint16_t addr = 0;

    lcd_set_windows(x_start, y_start, x_end - 1, y_end - 1);
    for (uint16_t j = y_start; j < y_end - 1; ++j)
    {
        addr = x_start + j * LCD_WIDTH;
        spi_write_nbytes((uint8_t *)(image + addr), (x_end - x_start - 1) * 2);
    }
}

static inline void lcd_display_point(uint16_t x, uint16_t y, uint16_t color)
{
    lcd_set_windows(x, y, x, y);
    lcd_send_data_16bit(color);
}

static inline void lcd_clear(uint16_t color)
{
    uint16_t image[LCD_WIDTH * LCD_HEIGHT];
    color = ((color << 8) & 0xff00) | (color >> 8);
    for (uint16_t j = 0; j < LCD_WIDTH * LCD_HEIGHT; ++j)
    {
        image[j] = color;
    }

    lcd_display(image);
}

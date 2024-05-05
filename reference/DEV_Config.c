/*****************************************************************************
 * | File      	:   DEV_Config.c
 * | Author      :   Waveshare team
 * | Function    :   Hardware underlying interface
 * | Info        :
 *----------------
 * |	This version:   V2.0
 * | Date        :   2019-07-08
 * | Info        :   Basic version
 *
 ******************************************************************************/
#include "DEV_Config.h"

/*****************************************
                GPIO
*****************************************/
void DEV_Digital_Write(UWORD Pin, UBYTE Value)
{
    bcm2835_gpio_write(Pin, Value);
}

UBYTE DEV_Digital_Read(UWORD Pin)
{
    UBYTE Read_value = 0;
    Read_value = bcm2835_gpio_lev(Pin);
    return Read_value;
}

void DEV_GPIO_Mode(UWORD Pin, UWORD Mode)
{
    if (Mode == 0 || Mode == BCM2835_GPIO_FSEL_INPT)
    {
        bcm2835_gpio_fsel(Pin, BCM2835_GPIO_FSEL_INPT);
    }
    else
    {
        bcm2835_gpio_fsel(Pin, BCM2835_GPIO_FSEL_OUTP);
    }
}

/**
 * delay x ms
 **/
void DEV_Delay_ms(UDOUBLE xms)
{
    bcm2835_delay(xms);
}

static void DEV_GPIO_Init(void)
{
    DEV_GPIO_Mode(LCD_CS, 1);
    DEV_GPIO_Mode(LCD_RST, 1);
    DEV_GPIO_Mode(LCD_DC, 1);
    DEV_GPIO_Mode(LCD_BL, 1);

    DEV_GPIO_Mode(KEY_UP_PIN, 0);
    DEV_GPIO_Mode(KEY_DOWN_PIN, 0);
    DEV_GPIO_Mode(KEY_LEFT_PIN, 0);
    DEV_GPIO_Mode(KEY_RIGHT_PIN, 0);
    DEV_GPIO_Mode(KEY_PRESS_PIN, 0);
    DEV_GPIO_Mode(KEY1_PIN, 0);
    DEV_GPIO_Mode(KEY2_PIN, 0);
    DEV_GPIO_Mode(KEY3_PIN, 0);
    LCD_CS_1;
}
/******************************************************************************
function:	Module Initialize, the library and initialize the pins, SPI
protocol parameter: Info:
******************************************************************************/
UBYTE DEV_ModuleInit(void)
{
    if (!bcm2835_init())
    {
        printf("bcm2835 init failed  !!! \r\n");
        return 1;
    }
    else
    {
        printf("bcm2835 init success !!! \r\n");
    }
    DEV_GPIO_Init();
    bcm2835_spi_begin();                                        // Start spi interface, set spi pin for the reuse
                                                                // function
    bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);    // High first transmission
    bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);                 // spi mode 0
    bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_128); // Frequency
    bcm2835_spi_chipSelect(BCM2835_SPI_CS0);                    // set CE0
    bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);    // enable cs0

    return 0;
}

void DEV_SPI_WriteByte(uint8_t Value)
{
    bcm2835_spi_transfer(Value);
}

void DEV_SPI_Write_nByte(uint8_t *pData, uint32_t Len)
{
    uint8_t rData[Len];
    bcm2835_spi_transfernb(pData, rData, Len);
}

/******************************************************************************
function:	Module exits, closes SPI and BCM2835 library
parameter:
Info:
******************************************************************************/
void DEV_ModuleExit(void)
{
    bcm2835_spi_end();
    bcm2835_close();
}

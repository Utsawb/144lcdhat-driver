#pragma once

/*
 *  I will try to emulate the Arduino
 *  style of functions to make my life easier
 */

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "bcm2835.h"

static inline void pin_mode(const uint16_t pin, const uint16_t mode)
{
    if (mode == 0 || mode == BCM2835_GPIO_FSEL_INPT)
    {
        bcm2835_gpio_fsel(pin, BCM2835_GPIO_FSEL_INPT);
    }
    else
    {
        bcm2835_gpio_fsel(pin, BCM2835_GPIO_FSEL_OUTP);
    }
}

// delay already defined in bcm2835 header

static inline void digital_write(const uint16_t pin, const uint8_t value)
{
    bcm2835_gpio_write(pin, value);
}

static inline uint8_t digital_read(const uint16_t pin)
{
    return bcm2835_gpio_lev(pin);
}

static inline void spi_write_byte(const uint8_t value)
{
    bcm2835_spi_transfer(value);
}

static inline void spi_write_nbytes(const uint8_t *data, const uint32_t length)
{
    bcm2835_spi_writenb((const char *) data, length);
}

static inline void gpio_init(void)
{
    if (!bcm2835_init())
    {
        fprintf(stderr, "bcm2835 library failed to initialize\n");
        exit(EXIT_FAILURE);
    }
}

static inline void gpio_deinit(void)
{
    bcm2835_close();
}

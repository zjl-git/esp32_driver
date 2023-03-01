#ifndef _HL_SPI__
#define _HL_SPI__

#ifdef __cplusplus
extern "C"
{
#endif

#include "driver/spi_master.h"
#include "driver/gpio.h"

typedef enum {
    HL_SPI2 = SPI2_HOST,
    HL_SPI3 = SPI3_HOST,
} hl_spi_type;

typedef enum {
    HL_SPI2_DEVICE1,
    HL_SPI2_DEVICE2,
    HL_SPI2_DEVICE3,
    HL_SPI3_DEVICE1,
    HL_SPI3_DEVICE2,
    HL_SPI3_DEVICE3,
} hl_spi_device;

#ifdef __cplusplus
}
#endif

#endif

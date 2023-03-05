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

void hl_spi_master_init(hl_spi_type type);

void hl_spi_master_add_device(hl_spi_device device, int8_t cs_pin);

void hl_spi_master_device_write(hl_spi_device device, uint8_t *data, uint32_t length);

void hl_spi_master_device_read(hl_spi_device device, uint8_t *data);

#ifdef __cplusplus
}
#endif

#endif

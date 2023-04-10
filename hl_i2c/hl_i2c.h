#ifndef _HL_I2C__
#define _HL_I2C__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>

void hl_i2c_init(void);

void hl_i2c_read(uint8_t device_addr, uint8_t reg_addr, uint8_t *data, uint32_t len);

void hl_i2c_write_byte(uint8_t device_addr, uint8_t reg_addr, uint8_t data);

#ifdef __cplusplus
}
#endif

#endif

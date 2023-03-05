#ifndef _HL_SIMULATE_I2C__
#define _HL_SIMULATE_I2C__

#ifdef __cplusplus
extern "C"
{
#endif

void hl_simulate_i2c_start(void);

void hl_simulate_i2c_stop(void);

void hl_simulate_i2c_wait_ack(void);

void hl_simulate_i2c_init(void);

void hl_simulate_write_data(unsigned char data);

unsigned char hl_simulate_read_data(unsigned char ack);


#ifdef __cplusplus
}
#endif

#endif

#include "hl_simulate_i2c.h"

#include "hl_gpio.h"
#include "esp_rom_sys.h"

#include <stdio.h>

#define HL_I2C_SCL_PIN              40
#define HL_I2C_SDA_PIN              41

#define I2C_SCL_SET(st)             hl_gpio_set_level(HL_I2C_SCL_PIN, st)
#define I2C_SDA_SET(st)             hl_gpio_set_level(HL_I2C_SDA_PIN, st)

#define I2C_SDA_OUT                 hl_gpio_init(HL_I2C_SDA_PIN, HL_GPIO_MODE_OUTPUT, HL_GPIO_INTR_DISABLE, false, true)
#define I2C_SDA_IN                  hl_gpio_init(HL_I2C_SDA_PIN, HL_GPIO_MODE_INPUT, HL_GPIO_INTR_DISABLE, false, true)

#define I2C_READ_SDA                hl_gpio_get_level(HL_I2C_SDA_PIN)

static void delay_us(unsigned int us)
{
    esp_rom_delay_us(us);
}

void hl_simulate_i2c_start(void)
{
    I2C_SDA_OUT;

    I2C_SDA_SET(1);
    I2C_SCL_SET(1);
    delay_us(4);
    I2C_SDA_SET(0);
    delay_us(4);
    I2C_SCL_SET(0);
    delay_us(4);
}

void hl_simulate_i2c_stop(void)
{
    I2C_SDA_OUT;

    I2C_SDA_SET(0);
    I2C_SCL_SET(1);
    delay_us(4);
    I2C_SCL_SET(1);
    I2C_SDA_SET(1);
    delay_us(4);
}

void hl_simulate_i2c_wait_ack(void)
{
    unsigned char time = 0;
    I2C_SDA_IN;

    I2C_SDA_SET(1);
    delay_us(1);
    I2C_SCL_SET(1);
    delay_us(1);

    while (I2C_READ_SDA) {
        time++;
        if (time > 250) {
            hl_simulate_i2c_stop();
            return ;
        }
    }

    I2C_SCL_SET(0);
}

static void hl_simulate_i2c_ack(void)
{
    I2C_SDA_OUT;

    I2C_SCL_SET(0);
    I2C_SDA_SET(0);
    delay_us(2);
    I2C_SCL_SET(1);
    delay_us(2);
    I2C_SCL_SET(0);
}

static void hl_simulate_i2c_nack(void)
{
    I2C_SDA_OUT;

    I2C_SCL_SET(0);
    I2C_SDA_SET(1);
    delay_us(2);
    I2C_SCL_SET(1);
    delay_us(2);
    I2C_SCL_SET(0);
}

void hl_simulate_i2c_init(void)
{
    hl_gpio_init(HL_I2C_SCL_PIN, HL_GPIO_MODE_OUTPUT, HL_GPIO_INTR_DISABLE, false, true);
    hl_gpio_init(HL_I2C_SDA_PIN, HL_GPIO_MODE_OUTPUT, HL_GPIO_INTR_DISABLE, false, true);

    I2C_SCL_SET(1);
    I2C_SDA_SET(1);
}

void hl_simulate_write_data(unsigned char data)
{
    unsigned char t;
    I2C_SDA_OUT;

    I2C_SCL_SET(0);
    for (t = 0; t < 8; t++) {
        I2C_SDA_SET((data & 0x80) >> 7);
        data <<= 1;
        delay_us(2);
        I2C_SCL_SET(1);
        delay_us(2);
        I2C_SCL_SET(0);
        delay_us(2);
    }
}

unsigned char hl_simulate_read_data(unsigned char ack)
{
    unsigned char i, receive = 0;
    I2C_SDA_IN;

    for (i = 0; i < 8; i++) {
        I2C_SCL_SET(0);
        delay_us(2);
        I2C_SCL_SET(1);
        receive <<= 1;
        if (I2C_READ_SDA) {
            receive++;
        }
        I2C_SCL_SET(1);
    }

    if (!ack) {
        hl_simulate_i2c_nack();
    } else {
        hl_simulate_i2c_ack();
    }
    return receive;
}



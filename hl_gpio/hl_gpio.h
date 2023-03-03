#ifndef _HL_GPIO__
#define _HL_GPIO__

#ifdef __cplusplus
extern "C"
{
#endif

#include "esp_attr.h"
#include "driver/gpio.h"

typedef enum {
    HL_GPIO_MODE_INPUT = GPIO_MODE_INPUT,
    HL_GPIO_MODE_OUTPUT = GPIO_MODE_OUTPUT,
    HL_GPIO_MODE_OUTPUT_OD = GPIO_MODE_OUTPUT_OD,
    HL_GPIO_MODE_INPUT_OUTPUT_OD = GPIO_MODE_INPUT_OUTPUT_OD,
    HL_GPIO_MODE_INPUT_OUTPUT = GPIO_MODE_INPUT_OUTPUT,
} hl_gpio_mode;

typedef enum {
    HL_GPIO_INTR_DISABLE = GPIO_INTR_DISABLE,
    HL_GPIO_INTR_POSEDGE = GPIO_INTR_POSEDGE,
    HL_GPIO_INTR_NEGEDGE = GPIO_INTR_NEGEDGE,
    HL_GPIO_INTR_ANYEDGE = GPIO_INTR_ANYEDGE,
    HL_GPIO_INTR_LOW_LEVEL = GPIO_INTR_LOW_LEVEL,
    HL_GPIO_INTR_HIGH_LEVEL = GPIO_INTR_HIGH_LEVEL, 
} hl_gpio_int_type;

typedef void (*gpio_isr_callback)(void);

void hl_gpio_init(uint8_t pin, hl_gpio_mode mode, hl_gpio_int_type intr, uint8_t pull_down, uint8_t pull_up);

void hl_gpio_set_level(uint8_t pin, uint8_t level);

uint8_t hl_gpio_get_level(uint8_t pin);

void hl_gpio_register_isr_callback(uint8_t pin, gpio_isr_callback callback);


#ifdef __cplusplus
}
#endif

#endif

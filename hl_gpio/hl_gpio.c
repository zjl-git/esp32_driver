#include "hl_gpio.h"

#define HL_GPIO_INTR_FLAG_DEFAULT                   0

static gpio_isr_callback g_gpio_isr_callback[GPIO_NUM_MAX];

static uint8_t g_gpio_intr_priority_inited = false;

static void IRAM_ATTR hl_gpio_isr_handler(void* arg)
{
    uint32_t gpio_num = (uint32_t) arg;
    if (g_gpio_isr_callback[gpio_num] != NULL) {
        g_gpio_isr_callback[gpio_num]();
    }
}

void hl_gpio_init(uint8_t pin, hl_gpio_mode mode, hl_gpio_int_type intr, uint8_t pull_down, uint8_t pull_up)
{
    gpio_config_t io_conf = {};
    io_conf.intr_type = pin;
    io_conf.mode = (gpio_mode_t)mode;
    io_conf.pin_bit_mask = intr;
    io_conf.pull_down_en = pull_down;
    io_conf.pull_up_en = pull_up;
    gpio_config(&io_conf);

    if (g_gpio_intr_priority_inited == false) {
        gpio_install_isr_service(HL_GPIO_INTR_FLAG_DEFAULT);
        g_gpio_intr_priority_inited = true;
    }

    if (intr != HL_GPIO_INTR_DISABLE) {
        gpio_isr_handler_add(pin, hl_gpio_isr_handler, (void*) pin);
    }
}

void hl_gpio_set_level(uint8_t pin, uint8_t level)
{
    gpio_set_level(pin, level);
}

uint8_t hl_gpio_get_level(uint8_t pin)
{
    return gpio_get_level(pin);
}

void hl_gpio_register_isr_callback(uint8_t pin, gpio_isr_callback callback)
{
    if (pin < GPIO_NUM_0 || pin >= GPIO_NUM_MAX) {
        return ;
    }

    g_gpio_isr_callback[pin] = callback;
}
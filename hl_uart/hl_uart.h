#ifndef _HL_UART__
#define _HL_UART__

#ifdef __cplusplus
extern "C"
{
#endif

#include "driver/uart.h"

typedef enum {
    HL_UART_PORT0 = UART_NUM_0,
    HL_UART_PORT1 = UART_NUM_1,
    HL_UART_PORT2 = UART_NUM_2,
    HL_UART_MAX   = UART_NUM_MAX,
} hl_uart_port;

typedef void (*uart_rx_callback)(uint8_t *buf, uint32_t len);

void hl_uart_init(hl_uart_port port, uint32_t baud_rate);

void hl_uart_write(hl_uart_port port, uint8_t * buf, uint32_t len);

void hl_uart_register_rx_callback(hl_uart_port port, uart_rx_callback callback);

#ifdef __cplusplus
}
#endif

#endif

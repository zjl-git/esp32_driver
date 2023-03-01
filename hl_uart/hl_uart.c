#include <string.h>

#include "hl_uart.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#define UART1_TX_PIN_NUM          1
#define UART1_RX_PIN_NUM          1
#define UART1_TX_BUF_SIZE         512
#define UART1_RX_BUF_SIZE         512

#define UART2_TX_PIN_NUM          1
#define UART2_RX_PIN_NUM          1
#define UART2_TX_BUF_SIZE         512
#define UART2_RX_BUF_SIZE         512

static uart_rx_callback g_uart_rx_cal[HL_UART_MAX];

static QueueHandle_t g_uart1_queue;
static QueueHandle_t g_uart2_queue;

static void hl_uart1_event_task(void *pvParameters)
{
    uart_event_t event;
    uint8_t *buffer = (uint8_t*) malloc(UART1_RX_BUF_SIZE);

    while (1) {
        if (xQueueReceive(g_uart1_queue, (void * )&event, (TickType_t)portMAX_DELAY)) {
            switch (event.type) {
                case UART_DATA:
                    uart_read_bytes(HL_UART_PORT1, buffer, event.size, portMAX_DELAY);
                    g_uart_rx_cal[HL_UART_PORT1](buffer, event.size);
                    break;

                case UART_FIFO_OVF:
                    uart_flush_input(HL_UART_PORT1);
                    xQueueReset(g_uart1_queue);
                    break;

                case UART_BUFFER_FULL:
                    uart_flush_input(HL_UART_PORT1);
                    xQueueReset(g_uart1_queue);
                    break;

                default:
                    break;
            }
        }
    }
}

static void hl_uart2_event_task(void *pvParameters)
{
    uart_event_t event;
    uint8_t *buffer = (uint8_t*) malloc(UART2_RX_BUF_SIZE);

    while (1) {
        if (xQueueReceive(g_uart1_queue, (void * )&event, (TickType_t)portMAX_DELAY)) {
            switch (event.type) {
                case UART_DATA:
                    uart_read_bytes(HL_UART_PORT2, buffer, event.size, portMAX_DELAY);
                    g_uart_rx_cal[HL_UART_PORT2](buffer, event.size);
                    break;

                case UART_FIFO_OVF:
                    uart_flush_input(HL_UART_PORT2);
                    xQueueReset(g_uart1_queue);
                    break;

                case UART_BUFFER_FULL:
                    uart_flush_input(HL_UART_PORT2);
                    xQueueReset(g_uart1_queue);
                    break;

                default:
                    break;
            }
        }
    }
}

void hl_uart_init(hl_uart_port port, uint32_t baud_rate)
{
    if (port < HL_UART_PORT1 || port > HL_UART_PORT2) {
        return ;
    }

    const uart_config_t uart_config = {
        .baud_rate = baud_rate,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_DEFAULT,
    };

    if (port == HL_UART_PORT1) {
        uart_driver_install(HL_UART_PORT1, UART1_RX_BUF_SIZE * 2, UART1_TX_BUF_SIZE * 2, 20, &g_uart1_queue, 0);
        uart_param_config(HL_UART_PORT1, &uart_config);
        uart_set_pin(HL_UART_PORT1, UART1_TX_PIN_NUM, UART1_RX_PIN_NUM, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
        xTaskCreate(hl_uart1_event_task, "uart1_event_task", 2048, NULL, 12, NULL);
    } else if (port == HL_UART_PORT2) {
        uart_driver_install(HL_UART_PORT2, UART2_RX_BUF_SIZE * 2, UART2_TX_BUF_SIZE * 2, 20, &g_uart2_queue, 0);
        uart_param_config(HL_UART_PORT2, &uart_config);
        uart_set_pin(HL_UART_PORT2, UART2_TX_PIN_NUM, UART2_RX_PIN_NUM, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
        xTaskCreate(hl_uart2_event_task, "uart2_event_task", 2048, NULL, 12, NULL);
    }
}

void hl_uart_write(hl_uart_port port, uint8_t * buf, uint32_t len)
{
    if (port < HL_UART_PORT1 || port > HL_UART_PORT2) {
        return ;
    }

    uart_write_bytes(port, buf, len);
}

void hl_uart_register_rx_callback(hl_uart_port port, uart_rx_callback callback)
{
    if (port < HL_UART_PORT1 || port > HL_UART_PORT2) {
        return ;
    }

    g_uart_rx_cal[port] = callback;
}
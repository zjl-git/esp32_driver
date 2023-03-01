#include <string.h>

#include "hl_spi.h"

#define SPI2_MAX_TRANSFER_SIZE      240 * 1
#define SPI2_PIN_NUM_MISO           1
#define SPI2_PIN_NUM_MOSI           1
#define SPI2_PIN_NUM_CLK            1

#define SPI2_PIN_NUM_CS1            1
#define SPI2_PIN_NUM_CS2            1
#define SPI2_PIN_NUM_CS3            1

#define SPI3_MAX_TRANSFER_SIZE      240 * 1
#define SPI3_PIN_NUM_MISO           2
#define SPI3_PIN_NUM_MOSI           2
#define SPI3_PIN_NUM_CLK            2

#define SPI3_PIN_NUM_CS1            2
#define SPI3_PIN_NUM_CS2            2
#define SPI3_PIN_NUM_CS3            2

static void hl_spi2_device1_pre_transfer_callback(spi_transaction_t *t);

static spi_device_handle_t g_spi2_device1;

/** spi_bus_config_t
 * .miso_io_num         MISO信号线，可复用为QSPI的D0
 * .mosi_io_num         MOSI信号线，可复用为QSPI的D1
 * .sclk_io_num         sclk信号线
 * .quadwp_io_num       WP信号线，专用于QSPI的D2
 * .quadhd_io_num       HD信号线，专用于QSPI的D3
 * .max_transfer_sz     最大传输数据大小，默认为4096
 * .intr_flags          中断标志位
 */
static spi_bus_config_t g_spi2_bus_config = {
    .miso_io_num = SPI2_PIN_NUM_MISO,
    .mosi_io_num = SPI2_PIN_NUM_MOSI,
    .sclk_io_num = SPI2_PIN_NUM_CLK,
    .quadwp_io_num = -1,
    .quadhd_io_num = -1,
    .max_transfer_sz = SPI2_MAX_TRANSFER_SIZE
};

static spi_bus_config_t g_spi3_bus_config = {
    .miso_io_num = SPI3_PIN_NUM_MISO,
    .mosi_io_num = SPI3_PIN_NUM_MOSI,
    .sclk_io_num = SPI3_PIN_NUM_CLK,
    .quadwp_io_num = -1,
    .quadhd_io_num = -1,
    .max_transfer_sz = SPI3_MAX_TRANSFER_SIZE
};

/** spi_device_interface_config_t
 *.command_bits,            默认控制位长度，设置为0-16
 *.address_bits,            默认地址位长度，设置为0-64
 *.dummy_bits,              在地址和数据位段之间插入的dummy位长度，用于匹配时序，一般可以保持默认
 *.clock_speed_hz,          时钟频率，设置的是80MHz的分频系数，单位为Hz
 *.mode,                    SPI模式，设置为0-3
 *.duty_cycle_pos,
 *.cs_ena_pretrans,         传输前CS信号的建立时间，只在半双工模式下有用
 *.cs_ena_posttrans,        传输时CS信号的保持时间
 *.input_delay_ns,          从机的最大合法数据传输时间
 *.spics_io_num,            设置GPIO复用为CS引脚
 *.queue_size,              传输队列大小，决定了等待传输数据的数量
 *.flags,                   SPI设备属性设置
 *.pre_cb,                  传输开始时的回调函数
 *.post_cb,                 传输结束时的回调函数
 */
static spi_device_interface_config_t g_spi2_device1_config = {
    .clock_speed_hz = 26 * 1000 * 1000,
    .mode = 0,
    .spics_io_num = SPI2_PIN_NUM_CS1,
    .queue_size = 7,
    .pre_cb = hl_spi2_device1_pre_transfer_callback
};

/** spi_transaction_t
 *.cmd,                     指令数据，其长度在spi_device_interface_config_t中的command_bits设置
 *.addr,                    地址数据，其长度在spi_device_interface_config_t中的address_bits设置
 *.length,                  数据总长度，单位：比特
 *.rxlength,                接收到的数据总长度，应小于length，如果设置为0则默认设置为length
 *.flags,                   SPI传输属性设置
 *.user,                    用户定义变量，可以用来存储传输ID等注释信息
 *.tx_buffer,               发送数据缓存区指针
 *.tx_data,                 发送数据
 *.rx_buffer,               接收数据缓存区指针，如果启用DMA则需要至少4个字节
 *.rx_data                  如果设置了SPI_TRANS_USE_RXDATA，数据会被这个变量直接接收
 */

static void hl_spi2_device1_pre_transfer_callback(spi_transaction_t *t)
{
    
}


void hl_spi_master_init(hl_spi_type type)
{
    esp_err_t ret = ESP_FAIL;
    if (type == HL_SPI2) {
        ret=spi_bus_initialize(SPI2_HOST, &g_spi2_bus_config, SPI_DMA_CH_AUTO);
    } else if (type == HL_SPI3) {
        ret=spi_bus_initialize(SPI3_HOST, &g_spi3_bus_config, SPI_DMA_CH_AUTO);
    }
    ESP_ERROR_CHECK(ret);
}

void hl_spi_master_add_device(hl_spi_device device)
{
    esp_err_t ret = ESP_FAIL;
    if (device == HL_SPI2_DEVICE1 || device == HL_SPI2_DEVICE2 || device == HL_SPI2_DEVICE3) {
        if (device == HL_SPI2_DEVICE1) {
            ret=spi_bus_add_device(SPI2_HOST, &g_spi2_device1_config, &g_spi2_device1);
        } else if (device == HL_SPI2_DEVICE2) {

        } else if (device == HL_SPI2_DEVICE3) {

        }
    } else if (device == HL_SPI3_DEVICE1 || device == HL_SPI3_DEVICE2 || device == HL_SPI3_DEVICE3) {
        if (device == HL_SPI3_DEVICE1) {

        } else if (device == HL_SPI3_DEVICE2) {

        } else if (device == HL_SPI3_DEVICE3) {

        }
    }
    ESP_ERROR_CHECK(ret);
}

void hl_spi_master_device_write(hl_spi_device device, uint8_t *data, uint32_t length)
{
    esp_err_t ret;
    spi_transaction_t device_trans;

    if (length == 0) {
        return ;
    }

    memset(&device_trans, 0, sizeof(device_trans));
    device_trans.length = length * 8;
    device_trans.tx_buffer = data;
    device_trans.user = (void *) 1;

    if (device == HL_SPI2_DEVICE1) {
        ret=spi_device_polling_transmit(g_spi2_device1, &device_trans); 
    }
    assert(ret==ESP_OK);
}

void hl_spi_master_device_read(hl_spi_device device, uint8_t *data)
{
    esp_err_t ret;
    spi_transaction_t device_trans;

    memset(&device_trans, 0, sizeof(device_trans));
    device_trans.length = 8;
    device_trans.flags = SPI_TRANS_USE_RXDATA;
    device_trans.user = (void *) 1;

    if (device == HL_SPI2_DEVICE1) {
        ret=spi_device_polling_transmit(g_spi2_device1, &device_trans); 
    }
    assert(ret==ESP_OK);

    *data = device_trans.tx_data[0];
}
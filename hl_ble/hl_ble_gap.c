#include "hl_ble_gap.h"

#include "esp_bt_defs.h"
#include "esp_bt_main.h"
#include "esp_gap_ble_api.h"

esp_err_t hl_ble_gap_set_device_name(const char *name)
{
    return esp_ble_gap_set_device_name(name);
}

esp_err_t hl_ble_gap_register_callback(esp_gap_ble_cb_t callback)
{
    return esp_ble_gap_register_callback(callback);
}

esp_err_t hl_ble_gap_update_conn_params(esp_ble_conn_update_params_t *params)
{
    return esp_ble_gap_update_conn_params(params);
}

/*adv*/
esp_err_t hl_ble_gap_set_adv_data(uint8_t *raw_data, uint32_t raw_data_len)
{
    return esp_ble_gap_config_adv_data_raw(raw_data, raw_data_len);
}

esp_err_t hl_ble_gap_start_advertising(esp_ble_adv_params_t *adv_params)
{
    return esp_ble_gap_start_advertising(adv_params);
}

esp_err_t hl_ble_gap_stop_advertising(void)
{
    return esp_ble_gap_stop_advertising();
}

/*scan*/
esp_err_t hl_ble_gap_set_scan_rsp_data(uint8_t *raw_data, uint32_t raw_data_len)
{
    return esp_ble_gap_config_scan_rsp_data_raw(raw_data, raw_data_len);
}

esp_err_t hl_ble_gap_start_scanning(uint32_t duration)
{
    return esp_ble_gap_start_scanning(duration);
}

esp_err_t hl_ble_gap_stop_scanning(void)
{
    return esp_ble_gap_stop_scanning();
}

/*ext adv*/
esp_err_t hl_ble_gap_set_ext_adv_rand_addr(uint8_t instance, esp_bd_addr_t rand_addr)
{
    return esp_ble_gap_ext_adv_set_rand_addr(instance, rand_addr);
}

esp_err_t hl_ble_gap_set_ext_adv_params(uint8_t instance, const esp_ble_gap_ext_adv_params_t *params)
{
    return esp_ble_gap_ext_adv_set_params(instance, params);
}

esp_err_t hl_ble_gap_set_ext_adv_data_raw(uint8_t instance, const uint8_t *data, uint16_t length)
{
    return esp_ble_gap_config_ext_adv_data_raw(instance, length, data);
}

esp_err_t hl_ble_gap_start_ext_adv(uint8_t num_adv, const esp_ble_gap_ext_adv_t *ext_adv)
{
    return esp_ble_gap_ext_adv_start(num_adv, ext_adv);
}


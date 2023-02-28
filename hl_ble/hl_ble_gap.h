#ifndef _HL_BLE_GAP__
#define _HL_BLE_GAP__

#ifdef __cplusplus
extern "C"
{
#endif

#include "esp_err.h"
#include "esp_gap_ble_api.h"

/*device name*/
esp_err_t hl_ble_gap_set_device_name(const char *name);

/*register callback*/
esp_err_t hl_ble_gap_register_callback(esp_gap_ble_cb_t callback);

/*update conn params*/
esp_err_t hl_ble_gap_update_conn_params(esp_ble_conn_update_params_t *params);

/*advertising*/
esp_err_t hl_ble_gap_set_adv_data(uint8_t *raw_data, uint32_t raw_data_len);

esp_err_t hl_ble_gap_start_advertising(esp_ble_adv_params_t *adv_params);

esp_err_t hl_ble_gap_stop_advertising(void);

/*scanning*/
esp_err_t hl_ble_gap_set_scan_rsp_data(uint8_t *raw_data, uint32_t raw_data_len);

esp_err_t hl_ble_gap_start_scanning(uint32_t duration);

esp_err_t hl_ble_gap_stop_scanning(void);

/*ext adv*/
esp_err_t hl_ble_gap_set_ext_adv_rand_addr(uint8_t instance, esp_bd_addr_t rand_addr);

esp_err_t hl_ble_gap_set_ext_adv_params(uint8_t instance, const esp_ble_gap_ext_adv_params_t *params);

esp_err_t hl_ble_gap_set_ext_adv_data_raw(uint8_t instance, const uint8_t *data, uint16_t length);

esp_err_t hl_ble_gap_start_ext_adv(uint8_t num_adv, const esp_ble_gap_ext_adv_t *ext_adv);

/*periodic adv*/
esp_err_t hl_ble_gap_set_periodic_adv_params(uint8_t instance, const esp_ble_gap_periodic_adv_params_t *params);

esp_err_t hl_ble_gap_set_periodic_adv_data_raw(uint8_t instance, const uint8_t *data, uint16_t length);

esp_err_t hl_ble_gap_start_periodic_adv(uint8_t instance);

#ifdef __cplusplus
}
#endif

#endif

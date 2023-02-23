#ifndef _HL_BLE_GAP__
#define _HL_BLE_GAP__

#ifdef __cplusplus
extern "C"
{
#endif

#include "esp_err.h"
#include "esp_gap_ble_api.h"

esp_err_t hl_ble_gap_set_device_name(const char *name);

esp_err_t hl_ble_gap_set_adv_data(void);

esp_err_t hl_ble_gap_start_advertising(esp_ble_adv_params_t *adv_params);

esp_err_t hl_ble_gap_stop_advertising(void);

esp_err_t hl_ble_gap_set_scan_rsp_data(void);

esp_err_t hl_ble_gap_start_scanning(uint32_t duration);

esp_err_t hl_ble_gap_stop_scanning(void);

esp_err_t hl_ble_gap_update_conn_params(esp_ble_conn_update_params_t *params);

esp_err_t hl_ble_gap_init(void);

#ifdef __cplusplus
}
#endif

#endif

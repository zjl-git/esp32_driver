#ifndef _HL_BLE_GATT__
#define _HL_BLE_GATT__

#ifdef __cplusplus
extern "C"
{
#endif

#include "esp_gatts_api.h"
#include "esp_gatt_common_api.h"

esp_err_t hl_ble_gatt_set_mtu(uint16_t mtu);

esp_err_t hl_ble_gatt_register_callback(esp_gatts_cb_t callback);

esp_err_t hl_ble_gatt_register_app(uint16_t app_id);

esp_err_t hl_ble_gatt_create_service(esp_gatt_if_t gatts_if, esp_gatt_srvc_id_t *service_id, uint16_t num_handle);

esp_err_t hl_ble_gatt_start_service(uint16_t service_handle);

esp_err_t hl_ble_gatt_add_characteristic(uint16_t service_handle,  esp_bt_uuid_t  *char_uuid, esp_gatt_perm_t perm, 
                                         esp_gatt_char_prop_t property, esp_attr_value_t *char_val, esp_attr_control_t *control);

esp_err_t hl_ble_gatt_add_characteristic_descr(uint16_t service_handle, esp_bt_uuid_t *descr_uuid, esp_gatt_perm_t perm, 
                                               esp_attr_value_t *char_descr_val, esp_attr_control_t *control);

esp_err_t hl_ble_gatt_get_attribute_value(uint16_t attr_handle, uint16_t *length, const uint8_t **value);

esp_err_t hl_ble_gatt_send_response(esp_gatt_if_t gatts_if, uint16_t conn_id, uint32_t trans_id,
                                    esp_gatt_status_t status, esp_gatt_rsp_t *rsp);

esp_err_t hl_ble_gatt_send_indicate(esp_gatt_if_t gatts_if, uint16_t conn_id, uint16_t attr_handle,
                                    uint16_t value_len, uint8_t *value, bool need_confirm);

#ifdef __cplusplus
}
#endif

#endif

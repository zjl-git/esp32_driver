#ifndef _HL_BLE_GATT__
#define _HL_BLE_GATT__

#ifdef __cplusplus
extern "C"
{
#endif

#include "esp_gatts_api.h"
#include "esp_gattc_api.h"
#include "esp_gatt_common_api.h"

/*seriver*/
esp_err_t hl_ble_gatt_set_mtu(uint16_t mtu);

esp_err_t hl_ble_gatts_register_callback(esp_gatts_cb_t callback);

esp_err_t hl_ble_gatts_register_app(uint16_t app_id);

esp_err_t hl_ble_gatts_create_service(esp_gatt_if_t gatts_if, esp_gatt_srvc_id_t *service_id, uint16_t num_handle);

esp_err_t hl_ble_gatts_start_service(uint16_t service_handle);

esp_err_t hl_ble_gatts_add_characteristic(uint16_t service_handle,  esp_bt_uuid_t  *char_uuid, esp_gatt_perm_t perm, 
                                         esp_gatt_char_prop_t property, esp_attr_value_t *char_val, esp_attr_control_t *control);

esp_err_t hl_ble_gatts_add_characteristic_descr(uint16_t service_handle, esp_bt_uuid_t *descr_uuid, esp_gatt_perm_t perm, 
                                               esp_attr_value_t *char_descr_val, esp_attr_control_t *control);

esp_err_t hl_ble_gatts_get_attribute_value(uint16_t attr_handle, uint16_t *length, const uint8_t **value);

esp_err_t hl_ble_gatts_send_response(esp_gatt_if_t gatts_if, uint16_t conn_id, uint32_t trans_id,
                                    esp_gatt_status_t status, esp_gatt_rsp_t *rsp);

esp_err_t hl_ble_gatts_send_indicate(esp_gatt_if_t gatts_if, uint16_t conn_id, uint16_t attr_handle,
                                    uint16_t value_len, uint8_t *value, bool need_confirm);

/*client*/
esp_err_t hl_ble_gattc_open(esp_gatt_if_t gattc_if, esp_bd_addr_t remote_bda, esp_ble_addr_type_t remote_addr_type, bool is_direct);

esp_err_t hl_ble_gattc_register_callback(esp_gattc_cb_t callback);

esp_err_t hl_ble_gattc_register_app(uint16_t app_id);

esp_err_t hl_ble_gattc_send_mtu_req(esp_gatt_if_t gattc_if, uint16_t conn_id);

esp_err_t hl_ble_gattc_search_service(esp_gatt_if_t gattc_if, uint16_t conn_id, esp_bt_uuid_t *filter_uuid);

esp_err_t hl_ble_gattc_get_attr_count(esp_gatt_if_t gattc_if, uint16_t conn_id, esp_gatt_db_attr_type_t type,
                                      uint16_t start_handle, uint16_t end_handle, uint16_t char_handle, uint16_t *count);

esp_err_t hl_ble_gattc_get_characteristic_by_uuid(esp_gatt_if_t gattc_if, uint16_t conn_id, uint16_t start_handle, uint16_t end_handle,
                                                  esp_bt_uuid_t char_uuid, esp_gattc_char_elem_t *result, uint16_t *count);

esp_err_t hl_ble_gattc_get_descriptor_by_char_handle(esp_gatt_if_t gattc_if, uint16_t conn_id, uint16_t char_handle,
                                                     esp_bt_uuid_t descr_uuid, esp_gattc_descr_elem_t *result, uint16_t *count);

esp_err_t hl_ble_gattc_write_characteristic(esp_gatt_if_t gattc_if, uint16_t conn_id, uint16_t handle, uint16_t value_len,
                                            uint8_t *value, esp_gatt_write_type_t write_type, esp_gatt_auth_req_t auth_req);

esp_err_t hl_ble_gattc_write_characteristic_descriptor(esp_gatt_if_t gattc_if, uint16_t conn_id, uint16_t handle, uint16_t value_len,
                                                       uint8_t *value, esp_gatt_write_type_t write_type, esp_gatt_auth_req_t auth_req);
                                        
esp_err_t hl_ble_gattc_register_for_notify (esp_gatt_if_t gattc_if, esp_bd_addr_t server_bda, uint16_t handle);



#ifdef __cplusplus
}
#endif

#endif

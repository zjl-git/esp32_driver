#include "hl_ble_gatt.h"

esp_err_t hl_ble_gatt_set_mtu(uint16_t mtu)
{
    return esp_ble_gatt_set_local_mtu(mtu);
}

esp_err_t hl_ble_gatt_register_callback(esp_gatts_cb_t callback)
{
    return esp_ble_gatts_register_callback(callback);
}

esp_err_t hl_ble_gatt_register_app(uint16_t app_id)
{
    return esp_ble_gatts_app_register(app_id);
}

esp_err_t hl_ble_gatt_create_service(esp_gatt_if_t gatts_if, esp_gatt_srvc_id_t *service_id, uint16_t num_handle)
{
    return esp_ble_gatts_create_service(gatts_if, service_id, num_handle);
}

esp_err_t hl_ble_gatt_start_service(uint16_t service_handle)
{
    return esp_ble_gatts_start_service(service_handle);
}

esp_err_t hl_ble_gatt_add_characteristic(uint16_t service_handle,  esp_bt_uuid_t  *char_uuid, esp_gatt_perm_t perm, 
                                         esp_gatt_char_prop_t property, esp_attr_value_t *char_val, esp_attr_control_t *control)
{
    return esp_ble_gatts_add_char(service_handle, char_uuid, perm, property, char_val, control);
}

esp_err_t hl_ble_gatt_add_characteristic_descr(uint16_t service_handle, esp_bt_uuid_t *descr_uuid, esp_gatt_perm_t perm, 
                                               esp_attr_value_t *char_descr_val, esp_attr_control_t *control)
{
    return esp_ble_gatts_add_char_descr(service_handle, descr_uuid, perm, char_descr_val, control);
}

esp_err_t hl_ble_gatt_get_attribute_value(uint16_t attr_handle, uint16_t *length, const uint8_t **value)
{
    return esp_ble_gatts_get_attr_value(attr_handle, length, value);
}



esp_err_t hl_ble_gatt_send_response(esp_gatt_if_t gatts_if, uint16_t conn_id, uint32_t trans_id,
                                    esp_gatt_status_t status, esp_gatt_rsp_t *rsp)
{
   return esp_ble_gatts_send_response(gatts_if, conn_id, trans_id, status, rsp);
}

esp_err_t hl_ble_gatt_send_indicate(esp_gatt_if_t gatts_if, uint16_t conn_id, uint16_t attr_handle,
                                    uint16_t value_len, uint8_t *value, bool need_confirm)
{
    return esp_ble_gatts_send_indicate(gatts_if, conn_id, attr_handle, value_len, value, need_confirm);
}


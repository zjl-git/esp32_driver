#include "hl_ble_gatt.h"

esp_err_t hl_ble_gatt_set_mtu(uint16_t mtu)
{
    return esp_ble_gatt_set_local_mtu(mtu);
}

/*seriver*/
esp_err_t hl_ble_gatts_register_callback(esp_gatts_cb_t callback)
{
    return esp_ble_gatts_register_callback(callback);
}

esp_err_t hl_ble_gatts_register_app(uint16_t app_id)
{
    return esp_ble_gatts_app_register(app_id);
}

esp_err_t hl_ble_gatts_create_service(esp_gatt_if_t gatts_if, esp_gatt_srvc_id_t *service_id, uint16_t num_handle)
{
    return esp_ble_gatts_create_service(gatts_if, service_id, num_handle);
}

esp_err_t hl_ble_gatts_start_service(uint16_t service_handle)
{
    return esp_ble_gatts_start_service(service_handle);
}

esp_err_t hl_ble_gatts_add_characteristic(uint16_t service_handle,  esp_bt_uuid_t  *char_uuid, esp_gatt_perm_t perm, 
                                         esp_gatt_char_prop_t property, esp_attr_value_t *char_val, esp_attr_control_t *control)
{
    return esp_ble_gatts_add_char(service_handle, char_uuid, perm, property, char_val, control);
}

esp_err_t hl_ble_gatts_add_characteristic_descr(uint16_t service_handle, esp_bt_uuid_t *descr_uuid, esp_gatt_perm_t perm, 
                                               esp_attr_value_t *char_descr_val, esp_attr_control_t *control)
{
    return esp_ble_gatts_add_char_descr(service_handle, descr_uuid, perm, char_descr_val, control);
}

esp_err_t hl_ble_gatts_get_attribute_value(uint16_t attr_handle, uint16_t *length, const uint8_t **value)
{
    return esp_ble_gatts_get_attr_value(attr_handle, length, value);
}



esp_err_t hl_ble_gatts_send_response(esp_gatt_if_t gatts_if, uint16_t conn_id, uint32_t trans_id,
                                    esp_gatt_status_t status, esp_gatt_rsp_t *rsp)
{
   return esp_ble_gatts_send_response(gatts_if, conn_id, trans_id, status, rsp);
}

esp_err_t hl_ble_gatts_send_indicate(esp_gatt_if_t gatts_if, uint16_t conn_id, uint16_t attr_handle,
                                    uint16_t value_len, uint8_t *value, bool need_confirm)
{
    return esp_ble_gatts_send_indicate(gatts_if, conn_id, attr_handle, value_len, value, need_confirm);
}


/*client*/
esp_err_t hl_ble_gattc_open(esp_gatt_if_t gattc_if, esp_bd_addr_t remote_bda, esp_ble_addr_type_t remote_addr_type, bool is_direct)
{
    return esp_ble_gattc_open(gattc_if, remote_bda, remote_addr_type, is_direct);
}

esp_err_t hl_ble_gattc_register_callback(esp_gattc_cb_t callback)
{
    return esp_ble_gattc_register_callback(callback);
}

esp_err_t hl_ble_gattc_register_app(uint16_t app_id)
{
    return esp_ble_gattc_app_register(app_id);
}

esp_err_t hl_ble_gattc_send_mtu_req(esp_gatt_if_t gattc_if, uint16_t conn_id)
{
    return esp_ble_gattc_send_mtu_req(gattc_if, conn_id);
}

esp_err_t hl_ble_gattc_search_service(esp_gatt_if_t gattc_if, uint16_t conn_id, esp_bt_uuid_t *filter_uuid)
{
    return esp_ble_gattc_search_service(gattc_if, conn_id, filter_uuid);
}

esp_err_t hl_ble_gattc_get_attr_count(esp_gatt_if_t gattc_if, uint16_t conn_id, esp_gatt_db_attr_type_t type,
                                      uint16_t start_handle, uint16_t end_handle, uint16_t char_handle, uint16_t *count)
{
    return esp_ble_gattc_get_attr_count(gattc_if, conn_id, type, start_handle, end_handle, char_handle, count);
}

esp_err_t hl_ble_gattc_get_characteristic_by_uuid(esp_gatt_if_t gattc_if, uint16_t conn_id, uint16_t start_handle, uint16_t end_handle,
                                                  esp_bt_uuid_t char_uuid, esp_gattc_char_elem_t *result, uint16_t *count)
{
    return esp_ble_gattc_get_char_by_uuid(gattc_if, conn_id, start_handle, end_handle, char_uuid, result, count);
}

esp_err_t hl_ble_gattc_get_descriptor_by_char_handle(esp_gatt_if_t gattc_if, uint16_t conn_id, uint16_t char_handle,
                                                     esp_bt_uuid_t descr_uuid, esp_gattc_descr_elem_t *result, uint16_t *count)
{
    return esp_ble_gattc_get_descr_by_char_handle(gattc_if, conn_id, char_handle, descr_uuid, result, count);
}

esp_err_t hl_ble_gattc_register_for_notify (esp_gatt_if_t gattc_if, esp_bd_addr_t server_bda, uint16_t handle)
{
    return esp_ble_gattc_register_for_notify(gattc_if, server_bda, handle);
}

esp_err_t hl_ble_gattc_write_characteristic(esp_gatt_if_t gattc_if, uint16_t conn_id, uint16_t handle, uint16_t value_len,
                                            uint8_t *value, esp_gatt_write_type_t write_type, esp_gatt_auth_req_t auth_req)
{
    return esp_ble_gattc_write_char(gattc_if, conn_id, handle, value_len, value, write_type, auth_req);
}

esp_err_t hl_ble_gattc_write_characteristic_descriptor(esp_gatt_if_t gattc_if, uint16_t conn_id, uint16_t handle, uint16_t value_len,
                                                       uint8_t *value, esp_gatt_write_type_t write_type, esp_gatt_auth_req_t auth_req)
{
    return esp_ble_gattc_write_char_descr(gattc_if, conn_id, handle, value_len, value, write_type, auth_req);
}





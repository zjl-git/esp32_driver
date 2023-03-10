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

esp_err_t hl_ble_gap_set_scan_params(esp_ble_scan_params_t *scan_params)
{
    return esp_ble_gap_set_scan_params(scan_params);
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

/*periodic adv*/
esp_err_t hl_ble_gap_set_periodic_adv_params(uint8_t instance, const esp_ble_gap_periodic_adv_params_t *params)
{
    return esp_ble_gap_periodic_adv_set_params(instance, params);
}

esp_err_t hl_ble_gap_set_periodic_adv_data_raw(uint8_t instance, const uint8_t *data, uint16_t length)
{
    return esp_ble_gap_config_periodic_adv_data_raw(instance, length, data);
}

esp_err_t hl_ble_gap_start_periodic_adv(uint8_t instance)
{
    return esp_ble_gap_periodic_adv_start(instance);
}

/*smp*/
esp_err_t hl_ble_gap_set_security_param(esp_ble_sm_param_t param_type, void *value, uint8_t len)
{
    return esp_ble_gap_set_security_param(param_type, value, len);
}

esp_err_t hl_ble_gap_passkey_reply(esp_bd_addr_t bd_addr, bool accept, uint32_t passkey)
{
    return esp_ble_passkey_reply(bd_addr, accept, passkey);
}

esp_err_t hl_ble_gap_set_encryption(esp_bd_addr_t bd_addr, esp_ble_sec_act_t sec_act)
{
    return esp_ble_set_encryption(bd_addr, sec_act);
}

esp_err_t hl_ble_gap_security_rsp(esp_bd_addr_t bd_addr, bool accept)
{
    return esp_ble_gap_security_rsp(bd_addr, accept);
}

esp_err_t hl_ble_confirm_reply(esp_bd_addr_t bd_addr, bool accept)
{
    return esp_ble_confirm_reply(bd_addr, accept);
}


esp_err_t hl_ble_gap_oob_req_reply(esp_bd_addr_t bd_addr, uint8_t *TK, uint8_t len)
{
    return esp_ble_oob_req_reply(bd_addr, TK, len);
}

int hl_ble_gap_get_bond_device_num(void)
{
    return esp_ble_get_bond_device_num();
}

esp_err_t hl_ble_gap_get_bond_device_list(int *dev_num, esp_ble_bond_dev_t *dev_list)
{
    return esp_ble_get_bond_device_list(dev_num, dev_list);
}

#include "hl_ble_gap.h"

#include "esp_bt_defs.h"
#include "esp_bt_main.h"
#include "esp_gap_ble_api.h"

#include "esp_log.h"
#define BLE_TAG                                 " [hl_ble_gap] "


#define DEVICE_NAME                             "ble_demo"
#define CONFIG_SET_RAW_ADV_DATA

#ifdef CONFIG_SET_RAW_ADV_DATA
static uint8_t g_adv_data[] = {
        /* flags */
        0x02, 0x01, 0x06,
        /* tx power*/
        0x02, 0x0a, 0xeb,
        /* service uuid */
        0x03, 0x03, 0x11, 0x22,
        /* device name */
        0x09, 0x09, 'b', 'l', 'e', '_', 'd', 'e', 'm', 'o',
        /*swift pair*/
        //0x0F, 0xFF, 0x06, 0x00, 0x03, 0x01, 0x80, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x18, 0x04, 0x20,

};

static uint8_t g_scan_rsp_data[] = {
        /* flags */
        0x02, 0x01, 0x06,
        /* tx power */
        0x02, 0x0a, 0xeb,
        /* service uuid */
        0x03, 0x03, 0x22, 0x11,
};
#else
static uint8_t g_adv_service_uuid128[32] = {
    /* LSB <--------------------------------------------------------------------------------> MSB */
    //first uuid, 16bit, [12],[13] is the value
    0xfb, 0x34, 0x9b, 0x5f, 0x80, 0x00, 0x00, 0x80, 0x00, 0x10, 0x00, 0x00, 0xEE, 0x00, 0x00, 0x00,
    //second uuid, 32bit, [12], [13], [14], [15] is the value
    0xfb, 0x34, 0x9b, 0x5f, 0x80, 0x00, 0x00, 0x80, 0x00, 0x10, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00,
};

static esp_ble_adv_data_t g_adv_data = {
    .set_scan_rsp           = false,
    .include_name           = true,
    .include_txpower        = false,
    .min_interval           = 0x0006,                   /*slave connection min interval, Time = min_interval * 1.25 msec*/
    .max_interval           = 0x0010,                   /*slave connection max interval, Time = max_interval * 1.25 msec*/
    .appearance             = 0x00,
    .manufacturer_len       = 0,                        /*_MANUFACTURER_DATA_LEN*/
    .p_manufacturer_data    =  NULL,                    /*manufacturer[0]*/
    .service_data_len       = 0,
    .p_service_data         = NULL,
    .service_uuid_len       = sizeof(g_adv_service_uuid128),
    .p_service_uuid         = g_adv_service_uuid128,
    .flag = (ESP_BLE_ADV_FLAG_GEN_DISC | ESP_BLE_ADV_FLAG_BREDR_NOT_SPT),
};
// scan response data
static esp_ble_adv_data_t g_scan_rsp_data = {
    .set_scan_rsp = true,
    .include_name = true,
    .include_txpower = true,
    //.min_interval = 0x0006,
    //.max_interval = 0x0010,
    .appearance = 0x00,
    .manufacturer_len = 0,
    .p_manufacturer_data =  NULL,
    .service_data_len = 0,
    .p_service_data = NULL,
    .service_uuid_len = sizeof(g_adv_service_uuid128),
    .p_service_uuid = g_adv_service_uuid128,
    .flag = (ESP_BLE_ADV_FLAG_GEN_DISC | ESP_BLE_ADV_FLAG_BREDR_NOT_SPT),
};
#endif

static esp_ble_adv_params_t g_adv_params = {
    .adv_int_min        = 0x20,
    .adv_int_max        = 0x40,
    .adv_type           = ADV_TYPE_IND,
    .own_addr_type      = BLE_ADDR_TYPE_PUBLIC,
    .channel_map        = ADV_CHNL_ALL,
    .adv_filter_policy  = ADV_FILTER_ALLOW_SCAN_ANY_CON_ANY,
};


esp_err_t hl_ble_gap_set_device_name(const char *name)
{
    esp_err_t ret = esp_ble_gap_set_device_name(name);
    if (ret) {
        ESP_LOGE(BLE_TAG, "%s set device name failed, error code = %x\n", __func__, ret);
    }

    return ret;
}

esp_err_t hl_ble_gap_set_adv_data(void)
{
    esp_err_t ret;

#ifdef CONFIG_SET_RAW_ADV_DATA
    ret = esp_ble_gap_config_adv_data_raw(g_adv_data, sizeof(g_adv_data));
#else
    ret = esp_ble_gap_config_adv_data(&g_adv_data);
#endif
    if (ret) {
        ESP_LOGE(BLE_TAG, "%s config adv data failed, error code = %x\n", __func__, ret);
    }

    return ret;
}

esp_err_t hl_ble_gap_start_advertising(esp_ble_adv_params_t *adv_params)
{
    esp_err_t ret;
    ret = esp_ble_gap_start_advertising(adv_params);
    if (ret) {
        ESP_LOGE(BLE_TAG, "%s start advertising failed, error code = %x\n", __func__, ret);
    }
    return ret;
}

esp_err_t hl_ble_gap_stop_advertising(void)
{
    esp_err_t ret;
    ret = esp_ble_gap_stop_advertising();
    if (ret) {
        ESP_LOGE(BLE_TAG, "%s stop advertising failed, error code = %x\n", __func__, ret);
    }
    return ret;
}

esp_err_t hl_ble_gap_set_scan_rsp_data(void)
{
     esp_err_t ret;

#ifdef CONFIG_SET_RAW_ADV_DATA
    ret =  esp_ble_gap_config_scan_rsp_data_raw(g_scan_rsp_data, sizeof(g_scan_rsp_data));
#else
    ret = esp_ble_gap_config_adv_data(&g_scan_rsp_data);
#endif
    if (ret) {
        ESP_LOGE(BLE_TAG, "%s config scan response data failed, error code = %x\n", __func__, ret);
    }

    return ret;
}

esp_err_t hl_ble_gap_start_scanning(uint32_t duration)
{
    esp_err_t ret;
    ret = esp_ble_gap_start_scanning(duration);
    if (ret) {
        ESP_LOGE(BLE_TAG, "%s start scanning failed, error code = %x\n", __func__, ret);
    }

    return ret;
}

esp_err_t hl_ble_gap_stop_scanning(void)
{
    esp_err_t ret;
    ret = esp_ble_gap_stop_scanning();
    if (ret) {
        ESP_LOGE(BLE_TAG, "%s stop scanning failed, error code = %x\n", __func__, ret);
    }

    return ret;
}

esp_err_t hl_ble_gap_update_conn_params(esp_ble_conn_update_params_t *params)
{
    esp_err_t ret;
    ret = esp_ble_gap_update_conn_params(params);
    if (ret) {
        ESP_LOGE(BLE_TAG, "%s update conn params failed, error code = %x\n", __func__, ret);
    }
    return ret;
}



static void hal_ble_gap_event_handler(esp_gap_ble_cb_event_t event, esp_ble_gap_cb_param_t *param)
{
    
}

esp_err_t hl_ble_gap_init(void)
{
    esp_err_t ret = esp_ble_gap_register_callback(hal_ble_gap_event_handler);
    if (ret){
        ESP_LOGE(BLE_TAG, "%s gap register error, error code = %x\n", __func__, ret);
    }

    ret = hl_ble_gap_set_device_name(DEVICE_NAME);
    if (ret) {
        return ret;
    }

    ret = hl_ble_gap_set_adv_data();
    if (ret) {
        return ret;
    }

    ret = hl_ble_gap_set_scan_rsp_data();
    if (ret) {
        return ret;
    }

    ret = hl_ble_gap_start_advertising(&g_adv_params);
    if (ret) {
        return ret;
    }

    return ret;
}
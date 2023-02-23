#include "hl_nvs.h"

#include "nvs.h"
#include "nvs_flash.h"

#include "esp_log.h"
#define HL_NVS                          " [hl_nvs] "

void hl_nvs_init(void)
{
    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();
    }
    ESP_ERROR_CHECK(err);
}
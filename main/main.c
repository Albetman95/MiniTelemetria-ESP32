#include "esp_log.h"
#include "app_info.h"
#include <stdio.h>
#include "uart_console.h"

static const char *TAG = "BOOT";

void app_main(void)
{
    ESP_LOGI(TAG,"%s - Boot OK", app_info_get_name());
    ESP_LOGI(TAG, "Version %s", app_info_get_version());
    ESP_LOGI(TAG, "Author: Marcos Albetman");
    uart_console_init();
    
}
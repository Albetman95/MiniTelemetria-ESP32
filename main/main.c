#include "esp_log.h"
#include "app_info.h"
#include <stdio.h>
#include "uart_console.h"
#include "drv_mpu6050.h"

static const char *TAG = "BOOT";

void app_main(void)
{
    ESP_LOGI(TAG,"%s - Boot OK", app_info_get_name());
    ESP_LOGI(TAG, "Version %s", app_info_get_version());
    ESP_LOGI(TAG, "Author: Marcos Albetman");
    uart_console_init();

    i2c_master_bus_handle_t bus_handle;
    i2c_master_dev_handle_t dev_handle;
    mpu6050_init(&bus_handle, &dev_handle);
    drv_imu_read_whoami(dev_handle);

    
}
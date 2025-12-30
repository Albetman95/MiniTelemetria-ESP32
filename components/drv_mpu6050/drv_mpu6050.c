#include <stdio.h>
#include "drv_mpu6050.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "I2C_Protocol";

#define I2C_MASTER_SCL_IO           9                           /*!< GPIO number used for I2C master clock */
#define I2C_MASTER_SDA_IO           8                           /*!< GPIO number used for I2C master data  */
#define I2C_MASTER_NUM              I2C_NUM_0                   /*!< I2C port number for master dev */
#define I2C_MASTER_TX_BUF_DISABLE   0                           /*!< I2C master doesn't need buffer */
#define I2C_MASTER_RX_BUF_DISABLE   0                           /*!< I2C master doesn't need buffer */
#define I2C_MASTER_TIMEOUT_MS       1000

#define MPU6050_SENSOR_ADDR         0x68        /*!< Address of the MPU9250 sensor */
#define MPU6050_WHO_AM_I_REG_ADDR   0x75        /*!< Register addresses of the "who am I" register */
#define MPU6050_RESET_BIT           7
#define MPU6050_scl_speed_hz        100000


/**
 * @brief Initialization of the master configuration and device configuration
 */

void mpu6050_init(i2c_master_bus_handle_t *bus_handle, i2c_master_dev_handle_t *dev_handle)
{
    ESP_LOGI(TAG,"init Start");    
    i2c_master_bus_config_t bus_config = {
        .i2c_port = I2C_MASTER_NUM,
        .sda_io_num = I2C_MASTER_SDA_IO,
        .scl_io_num = I2C_MASTER_SCL_IO,
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .glitch_ignore_cnt = 7,
        .flags.enable_internal_pullup = true,
    };
    ESP_ERROR_CHECK(i2c_new_master_bus(&bus_config, bus_handle));

    i2c_device_config_t dev_config = {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,
        .device_address = MPU6050_SENSOR_ADDR,
        .scl_speed_hz = MPU6050_scl_speed_hz,
    };
    ESP_ERROR_CHECK(i2c_master_bus_add_device(*bus_handle, &dev_config, dev_handle));
    ESP_LOGI(TAG,"init finish");  
}

bool drv_imu_read_whoami(i2c_master_dev_handle_t dev_handle){
    uint8_t whoami = 0;
    uint8_t reg = MPU6050_WHO_AM_I_REG_ADDR;

    esp_err_t esp_ret = i2c_master_transmit_receive(dev_handle, &reg , 1, &whoami, 1, -1);
    if(esp_ret != ESP_OK){
        printf("Error: Failed to read register\r\n");
        return false;
    }
    ESP_LOGI(TAG, "WHO_AM_I = %X", whoami);
    return true;
}

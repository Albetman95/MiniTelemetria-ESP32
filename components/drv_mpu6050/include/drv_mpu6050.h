#ifndef MPU6050_H
#define MPU6050_H
#include <stdbool.h>
#include "driver/i2c_master.h"


void mpu6050_init(i2c_master_bus_handle_t *bus_handle, i2c_master_dev_handle_t *dev_handle);
bool drv_imu_read_whoami(i2c_master_dev_handle_t dev_handle);

#endif
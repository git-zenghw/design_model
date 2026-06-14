/*
 * @Author: zenghw
 * @Date: 2026-04-23 19:30:26
 * @Description: 
 * @LastEditTime: 2026-04-23 20:06:46
 */

#include <stdio.h>
#include "sensor_factory.h"
static void ds18b20_init(void);
static void ds18b20_read(float *, float *); 

static sensor_ops_t ds18b20_ops = {
    .name = "DS18B20",
    .init = ds18b20_init,
    .read = ds18b20_read,
};

void ds18b20_init(void)
{
    // 初始化DS18B20传感器
    fprintf(stderr, "DS18B20传感器已初始化\n");
}

void ds18b20_read(float *temperature, float *humidity)
{
    // 读取DS18B20传感器数据，并将温度值存储在对应的变量中
    fprintf(stderr, "正在读取DS18B20传感器数据...\n");
}

void ds18b20_register(void)
{
    sensor_drv_register(&ds18b20_ops);
}

static void __attribute__((constructor)) ds18b20_auto_register(void)
{
    sensor_drv_register(&ds18b20_ops);
}




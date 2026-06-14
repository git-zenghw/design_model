/*
 * @Author: zenghw
 * @Date: 2026-04-23 14:54:40
 * @Description: 
 * @LastEditTime: 2026-04-23 19:32:14
 */

#include <stdio.h>
#include <string.h>
#include "sensor_factory.h"
#include "dht11.h"
#include "ds18b20.h"

static sensor_ops_t *gs_sensor_list = NULL;

void sensor_drv_register(sensor_ops_t *drv)
{
    if (!drv) {
        return;
    }   
    drv->next = gs_sensor_list;
    gs_sensor_list = drv;
}

void sensor_factory_init(void)
{
    // 注册传感器驱动
    printf("正在初始化传感器工厂...\n");
    dht11_register();
    ds18b20_register();
}

sensor_ops_t* sensor_factory_find(const char *name)
{
    sensor_ops_t *current = gs_sensor_list;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }

    return NULL; // 未找到匹配的传感器驱动
}

void sensor_get_count(void)
{
    int count = 0;
    sensor_ops_t *current = gs_sensor_list;
    while (current) {
        count++;
        current = current->next;
    }
    fprintf(stderr, "当前注册的传感器驱动数量: %d\n", count);
}

void sensor_dump(void)
{
    sensor_ops_t *current = gs_sensor_list;
    fprintf(stderr, "已注册的传感器驱动列表:\n");
    while (current) {
        fprintf(stderr, " - %s\n", current->name);
        current = current->next;
    }
}

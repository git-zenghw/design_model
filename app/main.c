/*
 * @Author: zenghw
 * @Date: 2026-04-23 14:12:32
 * @Description: 
 * 
 * Copyright (c) 2023 by 汇创智控科技有限公司, All Rights Reserved
 */
#include <stdio.h>
#include "sensor_factory.h"

int main(int argc, char *argv[])
{
    // sensor_factory_init();    
    sensor_get_count();
    sensor_dump();
    sensor_ops_t *sensor = sensor_factory_find("DHT11"); 

    if (sensor) {
        sensor->init();
    }

    return 0;
}



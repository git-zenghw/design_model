/*
 * @Author: zenghw
 * @Date: 2026-04-23 14:12:32
 * @Description: 
 * 
 * Copyright (c) 2023 by 汇创智控科技有限公司, All Rights Reserved
 */
#include <stdio.h>
#include <unistd.h>
#include "sensor_factory.h"
#include "key.h"
#include "prt_led.h"
#include "key_subject.h"


void observer_pattern_test(void)
{
    set_key_state(KEY_PRESSED);
    key_scan();
    set_key_state(KEY_RELEASED);
    key_scan();
    sleep(3);

    set_key_state(KEY_PRESSED);
    key_scan();
    key_scan();
    key_scan();
    key_scan();
    set_key_state(KEY_RELEASED);
    key_scan();
    sleep(3);
}

void factory_test(void)
{
    // sensor_factory_init(); // 手动注册
    sensor_dump();
    sensor_ops_t *sensor = sensor_factory_find("DHT11");
    if (sensor != NULL) {
        // 找到传感器
        sensor->init();
    }
}


int main(int argc, char *argv[])
{
    key_init();
    led_init();
    factory_test();

    key_subject_register(led_handle_for_key_event);
    
    while (1) {
        observer_pattern_test();
    }

    return 0;
}



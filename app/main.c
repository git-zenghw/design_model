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
#include "key_event.h"
#include "queue_test.h"


#if OBSERVER_PATTERN_MODEL
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
#endif

#if FACTORY_PATTERN_MODEL
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
#endif

#if PUBLISH_SUBSCRIBE_MODEL
void publish_subscribe_test(void)
{
    set_key_state(KEY_PRESSED);
    key_scan();
    set_key_state(KEY_RELEASED);
    key_scan();
    key_event_loop();
    sleep(3);

    set_key_state(KEY_PRESSED);
    key_scan();
    key_scan();
    key_scan();
    key_scan();
    set_key_state(KEY_RELEASED);
    key_scan();
    key_event_loop();
    sleep(3);

}
#endif


int main(int argc, char *argv[])
{
    #if FACTORY_PATTERN_MODEL
    factory_test();
    #endif

    #if OBSERVER_PATTERN_MODEL
    key_subject_register(led_handle_for_key_event);
    #endif

    #if QUEUE_TEST
    queue_test();
    #endif

    #if PUBLISH_SUBSCRIBE_MODEL
    key_event_init();
    key_event_subscribe(led_handle_for_key_event);
    #endif


    while (1) {
        #if OBSERVER_PATTERN_MODEL
        observer_pattern_test();
        #endif
        #if PUBLISH_SUBSCRIBE_MODEL
        publish_subscribe_test();
        #endif
    }

    return 0;
}



/*
 * @Author: git-zenghw zhw15159517501@163.com
 * @Date: 2026-04-25 20:48:41
 * @LastEditTime: 2026-04-26 20:16:52
 * @Description: 
 */

#include <stdio.h>
#include "prt_led.h"

 void led_handle_for_key_event(key_event_t event)
 {
    event_id_t id = event.event_id;
    if (id == KEY_EVENT_PRESSED) {
        fprintf(stderr, "LED ON\n");
    } else if (id == KEY_EVENT_LONG_PRESSED) {
        fprintf(stderr, "LED BLINK\n");
    }
 }
 
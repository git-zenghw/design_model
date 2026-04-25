/*
 * @Author: git-zenghw zhw15159517501@163.com
 * @Date: 2026-04-25 20:48:41
 * @LastEditTime: 2026-04-25 21:17:11
 * @Description: 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */

#include <stdio.h>
#include "prt_led.h"
#include "key_subject.h"


 void led_init(void)
 {
    fprintf(stderr, "LED hardware initialized.\n");
 }

 void led_handle_for_key_event(key_event_t event)
 {
    if (event == KEY_EVENT_PRESSED) {
        fprintf(stderr, "LED ON\n");
    } else if (event == KEY_EVENT_LONG_PRESSED) {
        fprintf(stderr, "LED BLINK\n");
    }
 }
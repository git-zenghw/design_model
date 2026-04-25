/*
 * @Author: git-zenghw zhw15159517501@163.com
 * @Date: 2026-04-25 17:36:08
 * @LastEditTime: 2026-04-25 21:16:01
 * @Description: 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "key.h"
#include "key_subject.h"

static key_subject_t gs_key_subject = {0};

void key_subject_notify(key_event_t event)
{
    for (int i = 0; i < gs_key_subject.subject_num; i++) {
        if (gs_key_subject.callback[i] == NULL) {
            continue;
        }
        gs_key_subject.callback[i](event);
    }
}

void key_subject_register(key_subject_callback callback)
{
    if (callback && gs_key_subject.subject_num < KEY_MAX_NUM)
    {
        gs_key_subject.callback[gs_key_subject.subject_num++] = callback;
    }
}


void key_scan(void)
{
    key_event_t event = 0;
    key_type_t key_state;
    static int long_press_count = 0;

    // 模拟按键状态变化
    key_state = get_key_state(); 

    if (key_state == KEY_PRESSED) {
        long_press_count ++;
    } else {
        if (long_press_count > 3) {
            event = KEY_EVENT_LONG_PRESSED;
            fprintf(stderr, "key long press\n");
        } else {
            event = KEY_EVENT_PRESSED;
            fprintf(stderr, "key short press\n");
        }

        if (long_press_count > 0) {
            key_subject_notify(event);
        }
        long_press_count = 0; // 重置长按计数
    }
}

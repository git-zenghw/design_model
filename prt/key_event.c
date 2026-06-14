/*
 * @Author: git-zenghw zhw15159517501@163.com
 * @Date: 2026-04-26 10:51:31
 * @LastEditTime: 2026-04-26 20:26:33
 * @Description: 
 */

#include <stdio.h>
#include "key_event.h"
#include "key.h"
#include "queue.h"

#if PUBLISH_SUBSCRIBE_MODEL
#define MAX_SUBSRIBE 5
#define MAX_QUEUE_SIZE 10
#define QUEUE_BUF_SIZE (MAX_QUEUE_SIZE * sizeof(key_event_t))

static queue_t gs_key_event_queue;
static char queue_buf[QUEUE_BUF_SIZE] = {0};
static void (*callback[MAX_SUBSRIBE])(key_event_t event);
static int cb_cnt = 0;

void key_event_init(void)
{
    queue_init(&gs_key_event_queue, queue_buf, MAX_QUEUE_SIZE, sizeof(key_event_t));
}

void key_publish(key_event_t *event)
{
    if (event == NULL) {
        return;
    }
    queue_enqueue(&gs_key_event_queue, event);
}

void key_event_subscribe(void (*cb)(key_event_t event))
{
    if (cb_cnt < MAX_SUBSRIBE) {
        callback[cb_cnt++] = cb;
    }
}

void key_event_loop(void)
{
    key_event_t event;
    if (queue_dequeue(&gs_key_event_queue, &event) == 0) {
        for (int i = 0; i < cb_cnt; i++) {
            if (callback[i]) {
                callback[i](event);
            }
        }
    }
    
}
#endif
#if OBSERVER_PATTERN_MODEL

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

#endif

void key_scan(void)
{
    key_event_t event = {0};
    key_type_t key_state;
    static int long_press_count = 0;

    // 模拟按键状态变化
    key_state = get_key_state(); 

    if (key_state == KEY_PRESSED) {
        long_press_count ++;
    } else {
        if (long_press_count > 3) {
            event.event_id = KEY_EVENT_LONG_PRESSED;
            fprintf(stderr, "key long press\n");
        } else {
            event.event_id = KEY_EVENT_PRESSED;
            fprintf(stderr, "key short press\n");
        }

        if (long_press_count > 0) {
            #if OBSERVER_PATTERN_MODEL
            key_subject_notify(event);
            #endif
            #if PUBLISH_SUBSCRIBE_MODEL
            fprintf(stderr, "publish key event: %d\n", event.event_id);
            key_publish(&event);
            #endif
        }
        long_press_count = 0; // 重置长按计数
    }
}

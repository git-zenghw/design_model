/*
 * @Author: git-zenghw zhw15159517501@163.com
 * @Date: 2026-04-26 10:51:39
 * @LastEditTime: 2026-04-26 20:08:47
 * @Description: 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */

#ifndef KEY_EVENT_H
#define KEY_EVENT_H
#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

 typedef enum
 {
    KEY_EVENT_PRESSED = 0,
    KEY_EVENT_LONG_PRESSED,
 } event_id_t;

 typedef struct {
      event_id_t event_id; // 按键事件
      int key_id;  // 按键编号   
 }key_event_t;


#if OBSERVER_PATTERN_MODEL

typedef void (*key_subject_callback)(key_event_t event);
#define KEY_MAX_NUM 4
typedef struct
 {
    key_subject_callback callback[KEY_MAX_NUM];
    int subject_num;
 } key_subject_t;

 void key_subject_register(key_subject_callback cb);
 #endif
 void key_scan(void);


#if PUBLISH_SUBSCRIBE_MODEL

void key_event_init(void);
void key_publish(key_event_t *event);
void key_event_subscribe(void (*cb)(key_event_t event));
void key_event_loop(void);

#endif

#ifdef __cplusplus
}
#endif
#endif

/*
 * @Author: git-zenghw zhw15159517501@163.com
 * @Date: 2026-04-25 17:36:14
 * @LastEditTime: 2026-04-25 21:13:49
 * @Description: 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */

 #ifndef KEY_SUBJECT_H
 #define KEY_SUBJECT_H

 #ifdef __cplusplus
 extern "C" {
 #endif


 typedef enum
 {
    KEY_EVENT_PRESSED = 0,
    KEY_EVENT_LONG_PRESSED,
 } key_event_t;

typedef void (*key_subject_callback)(key_event_t event);

#define KEY_MAX_NUM 4
typedef struct
 {
    key_subject_callback callback[KEY_MAX_NUM];
    int subject_num;
 } key_subject_t;

 void key_subject_register(key_subject_callback cb);
 void key_scan(void);



 #ifdef __cplusplus
 }
 #endif

 #endif
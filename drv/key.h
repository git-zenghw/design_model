/*
 * @Author: git-zenghw zhw15159517501@163.com
 * @Date: 2026-04-25 19:03:51
 * @LastEditTime: 2026-04-25 21:09:58
 * @Description: 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */

#ifndef KEY_H
#define KEY_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    KEY_RELEASED = 0,
    KEY_PRESSED,
}key_type_t;

void key_init(void);
key_type_t get_key_state(void);
void set_key_state(key_type_t new_state);


#ifdef __cplusplus
}
#endif

#endif
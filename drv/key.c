/*
 * @Author: git-zenghw zhw15159517501@163.com
 * @Date: 2026-04-25 19:03:45
 * @LastEditTime: 2026-04-25 21:16:43
 * @Description: 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */

#include "key.h"
#include <stdio.h>
#include <stdint.h>

static int gs_key_state = 0;

void key_init(void)
{
    // 初始化按键硬件
    printf("Key hardware initialized.\n");
}

key_type_t get_key_state(void)
{
    return gs_key_state;
}

void set_key_state(key_type_t new_state)
{
    gs_key_state = new_state;
}


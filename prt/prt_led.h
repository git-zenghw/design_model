/*
 * @Author: git-zenghw zhw15159517501@163.com
 * @Date: 2026-04-25 21:03:13
 * @LastEditTime: 2026-04-26 20:17:46
 * @Description: 
 */

#ifndef PRT_LED_H
#define PRT_LED_H

#ifdef __cplusplus
extern "C" {
#endif
#include "key_event.h"


void led_handle_for_key_event(key_event_t event);

#ifdef __cplusplus
}
#endif
#endif
/*
 * @Author: git-zenghw zhw15159517501@163.com
 * @Date: 2026-04-26 11:09:24
 * @LastEditTime: 2026-04-26 11:37:50
 * @Description: 队列自测接口
 */

#include <stdio.h>
#include "queue.h"

#if QUEUE_TEST
#define QUEUE_CAPACITY  5
#define ELEM_SIZE       sizeof(int)

static int g_buffer[QUEUE_CAPACITY];

void queue_test(void)
{
    queue_t q;

    queue_init(&q, g_buffer, QUEUE_CAPACITY, ELEM_SIZE);

    /* 入队测试 */
    for (int i = 1; i <= 3; i++) {
        queue_enqueue(&q, &i);
        printf("enqueue: %d, count=%d\n", i, queue_count(&q));
    }

    /* 出队测试 */
    int val;
    while (!queue_is_empty(&q)) {
        queue_dequeue(&q, &val);
        printf("dequeue: %d, count=%d\n", val, queue_count(&q));
    }

    printf("is_empty=%d\n", queue_is_empty(&q));
}
#endif


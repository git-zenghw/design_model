/*
 * @Author: zenghw
 * @Date: 2026-04-23 16:00:21
 * @Description: 
 * @LastEditTime: 2026-04-23 19:27:55
 */

#ifndef SENSOR_FACTORY_H
#define SENSOR_FACTORY_H

#ifdef __cplusplus
extern "C" {
#endif    

typedef struct sensor_ops {
    const char *name;
    void (*init)(void);
    void (*read)(float *temperature, float *humidity);
    struct sensor_ops *next;
} sensor_ops_t;

typedef enum {
    SENSOR_DS18B20 = 0,
    SENSOR_DHT11,
    SENSOR_MAX,
}sensor_type_t;


void sensor_drv_register(sensor_ops_t *drv);

void sensor_factory_init(void);
sensor_ops_t* sensor_factory_find(const char *name);
void sensor_get_count(void);
void sensor_dump(void);

#ifdef __cplusplus
};
#endif

#endif

#ifndef HTTP_TASK_H
#define HTTP_TASK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "esp_camera.h"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

#ifdef __cplusplus
}
#endif

void httpTask(void* pvParameters);

#endif

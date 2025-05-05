#ifndef CAMERA_TASK_H
#define CAMERA_TASK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "esp_mac.h"
#include "esp_camera.h"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

#ifdef __cplusplus
}
#endif

void cameraTask(void* pvParameters);

#endif

#include <Arduino.h>
#include <WiFi.h>
#include "http_task.h"
#include <HTTPClient.h>

const char* serverUrl = "http://<RPI_IP>:8080/upload";

void httpTask(void* pvParameters) {
  QueueHandle_t queue = static_cast<QueueHandle_t>(pvParameters);

  while (true) {
    camera_fb_t* fb;
    if (xQueueReceive(queue, &fb, portMAX_DELAY) == pdTRUE) {
      if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        http.begin(serverUrl);
        http.addHeader("Content-Type", "image/jpeg");

        int response = http.POST(fb->buf, fb->len);
        if (response <= 0) {
          Serial.println("HTTP POST failed");
        } else {
          Serial.printf("POST response: %d\n", response);
        }
        http.end();
      }
      esp_camera_fb_return(fb);
    }
  }
}

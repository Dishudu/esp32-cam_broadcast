#include <Arduino.h>
#include "esp_mac.h"
#include "wifi_setup.h"
#include "camera_task.h"
#include "http_task.h"

QueueHandle_t frameQueue;

void setup() {
  Serial.begin(115200);
  wifi_connect("YOUR_SSID", "YOUR_PASSWORD");

  frameQueue = xQueueCreate(2, sizeof(camera_fb_t*));
  if (frameQueue == nullptr) {
    Serial.println("Failed to create frame queue");
    return;
  }

  xTaskCreatePinnedToCore(cameraTask, "Camera Task", 8192, frameQueue, 1, nullptr, 0);
  xTaskCreatePinnedToCore(httpTask, "HTTP Task", 8192, frameQueue, 1, nullptr, 1);
}

void loop() {
  // Пусто, всё работает в задачах
}

extern "C" void app_main(void)
{
    setup();
    while (true) {
        loop();
        vTaskDelay(1);  // Маленькая задержка, чтобы не забивать CPU
    }
}
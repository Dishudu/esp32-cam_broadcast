#include <Arduino.h>
#include <WiFi.h>
#include "wifi_setup.h"

void wifi_connect(const char* ssid, const char* password) {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected. IP: " + WiFi.localIP().toString());
}

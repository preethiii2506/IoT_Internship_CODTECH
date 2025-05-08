#include "esp_camera.h"
#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "vivo Y56 5G";
const char* password = "PreeHath0925";
String botToken = "8052426037:AAFghdRbaQbmnqC_akIw6hmhCZ0R23ogPBk";
String chatId = "YOUR_CHAT_ID"; // Replace with your actual chat ID

#define PIR_PIN 13
bool motionDetected = false;

void startCamera() {
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = 5;
  config.pin_d1 = 18;
  config.pin_d2 = 19;
  config.pin_d3 = 21;
  config.pin_d4 = 36;
  config.pin_d5 = 39;
  config.pin_d6 = 34;
  config.pin_d7 = 35;
  config.pin_xclk = 0;
  config.pin_pclk = 22;
  config.pin_vsync = 25;
  config.pin_href = 23;
  config.pin_sscb_sda = 26;
  config.pin_sscb_scl = 27;
  config.pin_pwdn = 32;
  config.pin_reset = -1;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  config.frame_size = FRAMESIZE_SVGA;
  config.jpeg_quality = 10;
  config.fb_count = 1;
  esp_camera_init(&config);
}

void setup() {
  Serial.begin(115200);
  pinMode(PIR_PIN, INPUT);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  startCamera();
}

void sendTelegramAlert(String msg) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = "https://api.telegram.org/bot" + botToken + "/sendMessage?chat_id=" + chatId + "&text=" + msg;
    http.begin(url);
    int httpCode = http.GET();
    http.end();
  }
}

void loop() {
  if (digitalRead(PIR_PIN) == HIGH && !motionDetected) {
    motionDetected = true;
    Serial.println("Motion Detected!");
    sendTelegramAlert("⚠️ Motion detected from ESP32-CAM!");
    camera_fb_t* fb = esp_camera_fb_get();
    if (fb) {
      Serial.println("Image captured!");
      // You can add code to send the image via Telegram here
      esp_camera_fb_return(fb);
    }
    delay(10000);
    motionDetected = false;
  }
}

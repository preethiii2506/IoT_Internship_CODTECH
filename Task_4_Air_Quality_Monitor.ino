#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

const char* ssid = "vivo Y56 5G";
const char* password = "PreeHath0925";
WiFiClient client;

unsigned long channelID = 2954132; 
const char* writeAPI = "TCYTF64UHKLZ5QI2"; 

int airQualityPin = A0;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  ThingSpeak.begin(client);
}

void loop() {
  int airValue = analogRead(airQualityPin);
  float voltage = airValue * (3.3 / 1023.0);
  ThingSpeak.writeField(channelID, 1, voltage, writeAPI);
  Serial.print("Air quality voltage: ");
  Serial.println(voltage);
  delay(15000); 
}

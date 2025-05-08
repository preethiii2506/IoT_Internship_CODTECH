#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Replace with your actual Wi-Fi and MQTT details
const char* ssid = "vivo Y56 5G";
const char* password = "PreeHath0925";
const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
}

void callback(char* topic, byte* payload, unsigned int length) {
  String msg;
  for (unsigned int i = 0; i < length; i++) {
    msg += (char)payload[i];
  }

  if (String(topic) == "iot/light") {
    digitalWrite(D1, msg == "on" ? HIGH : LOW);
  }
  if (String(topic) == "iot/fan") {
    digitalWrite(D2, msg == "on" ? HIGH : LOW);
  }
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect("PreethiNodeMCUClient")) {
      client.subscribe("iot/light");
      client.subscribe("iot/fan");
    } else {
      delay(5000);
    }
  }
}

void setup() {
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}

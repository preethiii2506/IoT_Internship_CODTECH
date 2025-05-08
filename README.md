<<<<<<< HEAD
# Task 1 – Smart Light Control

## Overview
Control an LED using Bluetooth module (HC-05) and Arduino UNO, via a mobile app.

## Hardware Used
- Arduino UNO
- HC-05 Bluetooth Module
- LED + Resistor
- Breadboard, Jumper wires
- Android Phone

## How It Works
- Mobile app sends '1' or '0' via Bluetooth
- HC-05 receives and forwards to Arduino
- Arduino turns LED ON/OFF

## Demo App
Used: **Bluetooth Terminal App** (Play Store)

## Circuit
![circuit_diagram](circuit_diagram.png)

## Code
See `smart_light.ino` file.
=======
# Task 2 – Home Automation using MQTT

## Objective
Control multiple devices (Light and Fan represented by LEDs) using NodeMCU and MQTT protocol.

## Components Used
- NodeMCU ESP8266
- 2x LEDs
- 2x 220 Ohm Resistors
- Breadboard and jumper wires
- MQTT Broker: broker.hivemq.com
- MQTT Dashboard App (Android) or HiveMQ Web Client

## MQTT Topics
- `iot/light` → controls Light LED
- `iot/fan` → controls Fan LED
- Message should be either "on" or "off"

## How to Use
1. Upload the `mqtt_home_automation.ino` code to NodeMCU using Arduino IDE.
2. Open MQTT Dashboard app and connect to broker.hivemq.com
3. Publish messages to topics:
   - `iot/light` → "on" / "off"
   - `iot/fan` → "on" / "off"

## Folder Contents
- mqtt_home_automation.ino – Arduino code
- README.md – documentation
- Add your screenshots and circuit diagram here

## Output
LED1 (Light) and LED2 (Fan) will turn ON or OFF based on MQTT messages.
>>>>>>> 8dc2dd6 (Initial commit)

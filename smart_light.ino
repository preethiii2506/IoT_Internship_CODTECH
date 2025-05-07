char data = 0; // store received character

void setup() {
  pinMode(13, OUTPUT);   // Set LED pin as output
  Serial.begin(9600);    // Start serial communication
}

void loop() {
  if (Serial.available()) {
    data = Serial.read(); // Read data from Bluetooth
    if (data == '1') {
      digitalWrite(13, HIGH);  // Turn ON LED
    }
    else if (data == '0') {
      digitalWrite(13, LOW);   // Turn OFF LED
    }
  }
}

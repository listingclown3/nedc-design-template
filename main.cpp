const int relayPin = 7;    // Relay control (D7)
const int wallLED = 8;     // Red LED (D8 = Wall Power)
const int batteryLED = 9;  // Green LED (D9 = Battery Power)
const int timePin = A0;    // Potentiometer (A0)

void setup() {
  pinMode(relayPin, OUTPUT);
  pinMode(wallLED, OUTPUT);
  pinMode(batteryLED, OUTPUT);
  digitalWrite(relayPin, HIGH); // Start in wall power mode (relay OFF)
}

void loop() {
  int rawTime = analogRead(timePin);
  float hour = map(rawTime, 0, 1023, 0, 6); // Simulated shorter time range (0–6)

  // First half (0 to 3): Use Battery
  if (hour >= 0 && hour < 3) {
    digitalWrite(relayPin, LOW);  // Relay ON → Battery
    digitalWrite(batteryLED, HIGH);
    digitalWrite(wallLED, LOW);
  } 
  // Second half (3 to 6): Use Wall
  else {
    digitalWrite(relayPin, HIGH); // Relay OFF → Wall
    digitalWrite(wallLED, HIGH);
    digitalWrite(batteryLED, LOW);
  }
  delay(500); // Faster transition feedback
}

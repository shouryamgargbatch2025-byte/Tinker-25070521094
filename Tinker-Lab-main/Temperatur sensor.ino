// C++ code
//
// Simple Temperature Alarm using LM35 and an Active Buzzer
const int LM35_PIN = A0;
const int BUZZER_PIN = 8;      // active buzzer (digital HIGH to sound)
const int LED_PIN = 13;        // optional on-board LED

const float thresholdC = 30.0; // temperature threshold in °C (change as needed)
unsigned long readInterval = 1000; // ms between readings
unsigned long lastRead = 0;

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED_PIN, LOW);
  Serial.println("LM35 Temperature Alarm starting...");
}

void loop() {
  unsigned long now = millis();
  if (now - lastRead >= readInterval) {
    lastRead = now;
    int raw = analogRead(LM35_PIN);
    float voltage = raw * (5.0 / 1023.0); // volts
    float tempC = voltage / 0.01;         // LM35: 10 mV per °C

    if (tempC >= thresholdC) {
      // Alarm ON
      digitalWrite(BUZZER_PIN, HIGH); // for active buzzer
      digitalWrite(LED_PIN, HIGH);
    } else {
      // Alarm OFF
      digitalWrite(BUZZER_PIN, LOW);
      digitalWrite(LED_PIN, LOW);
    }
  }
}
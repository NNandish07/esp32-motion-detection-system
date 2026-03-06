int pirPin = 13;     // PIR sensor output pin
int buzzerPin = 12;  // Buzzer pin
int ledPin = 14;     // LED pin

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int motion = digitalRead(pirPin);  // Read PIR sensor

  if (motion == HIGH) {
    Serial.println("🚨 Intruder Detected!");
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000);   // Continuous buzzer sound at 1kHz
  } 
  else {
    Serial.println("✅ No Motion");
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);   // Turn OFF buzzer immediately
  }

  delay(200); // Small delay for stability
}

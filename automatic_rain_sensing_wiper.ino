// ========== Automatic Rain Sensing Car Wiper Project ==========


// Automatic Rain Sensing Car Wiper - Relay/DC Motor Version

const int rainSensorPin = A0;   // Analog pin connected to rain sensor
const int wiperPin = 9;         // Digital pin to control relay/motor

void setup() {
  pinMode(wiperPin, OUTPUT);
  Serial.begin(9600);           // For debugging
}

void loop() {
  int rainValue = analogRead(rainSensorPin);
  Serial.print("Rain Sensor Value: ");
  Serial.println(rainValue);

  // Threshold: Lower value = More rain
  if (rainValue < 500) {
    digitalWrite(wiperPin, HIGH);  // Turn ON wiper
    Serial.println("Wiper ON");
  } else {
    digitalWrite(wiperPin, LOW);   // Turn OFF wiper
    Serial.println("Wiper OFF");
  }

  delay(1000);  // 1-second delay between readings
}


// -------------------------------------------------------------


// Automatic Rain Sensing Car Wiper - Servo Motor Version

#include <Servo.h>

const int rainSensorPin = A0;
Servo wiperServo;

void setup() {
  wiperServo.attach(9);        // Connect Servo to D9
  Serial.begin(9600);
}

void loop() {
  int rainValue = analogRead(rainSensorPin);
  Serial.print("Rain Sensor Value: ");
  Serial.println(rainValue);

  if (rainValue < 500) {
    // Simulate wiper sweep
    for (int pos = 0; pos <= 180; pos += 10) {
      wiperServo.write(pos);
      delay(20);
    }
    for (int pos = 180; pos >= 0; pos -= 10) {
      wiperServo.write(pos);
      delay(20);
    }
    Serial.println("Wiper Moving");
  } else {
    wiperServo.write(0);  // Keep wiper at rest
    Serial.println("Wiper at Rest");
  }

  delay(1000);
}

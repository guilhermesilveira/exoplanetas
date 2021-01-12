#include "Stepper.h"

const int STEPS = 32;
Stepper planet = Stepper(STEPS, 8, 10, 9, 11);

const int PIN_SENSOR = 0;
unsigned long startingTime;

void setup() {
  Serial.begin(9600);
  startingTime = millis();
}

void loop() {
  planet.setSpeed(100);
  planet.step(STEPS / 4);

  unsigned long currentMillis = millis();

  int reading = analogRead(PIN_SENSOR);
  unsigned long delta = currentMillis - startingTime;
  
  Serial.print(delta);
  Serial.print(",");
  Serial.println(reading);
}

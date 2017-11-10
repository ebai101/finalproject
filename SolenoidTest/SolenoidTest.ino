#include "Solenoid.h"

Solenoid s1(13);
Solenoid s2(14);
unsigned long lastTick;

void setup() {
  Serial.begin(9600);
}

void loop() {
  timer();
  s2.process();
}

void timer() {
  if (millis() > lastTick + 1000) {
    s2.hit();
    lastTick = millis();
  }
}


#include "Arduino.h"
#include "Solenoid.h"

Solenoid::Solenoid(int _pin) {
  pin = _pin;
  pinMode(pin, OUTPUT);
 
  state = 0;
  lastCheck = 0;
  checkInt = 25;
}

void Solenoid::process() {
  if (millis() < lastCheck + checkInt) return;
  lastCheck = millis();

  if(state) {
    digitalWrite(pin, 1);
    state = 0;
  } else {
    digitalWrite(pin, 0);
  }
}

void Solenoid::hit() {
  state = 1;
}


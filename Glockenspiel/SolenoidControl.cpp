#include "Arduino.h"
#include "SolenoidControl.h"

SolenoidControl::SolenoidControl(int _latchPin, int _clockPin, int _dataPin) {
  latchPin = _latchPin;
  clockPin = _clockPin;
  dataPin = _dataPin;

  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void SolenoidControl::hitNote(int note) {
  uint16_t noteBin = 0b0000000000000001 << note; // shifts bit to the right position given note value

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, noteBin);
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 0);
  digitalWrite(latchPin, HIGH);
}

void SolenoidControl::checkNote(int note) {
  for (int i = 0; i < 15; i++) {
    // checks if input note is at an index in the array MIDINotes
    // if so, passes the index to the hitNote function
    if (note == MIDINotes[i]) {
      hitNote(i);
      break;
    }
  }
}

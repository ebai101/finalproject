#include "Arduino.h"
#include "SolenoidControl.h"

SolenoidControl::SolenoidControl() {
  checkInterval = 20;
  lastCheck = 0;
  lastNote = 0;

  for (int i = 0; i < 15; i++)
    pinMode(pins[i], OUTPUT);
}

void SolenoidControl::process() {
  if (millis() < lastCheck + checkInterval) return;

  if (noteOnTime && millis() > noteOnTime) {
    releaseNote(lastNote);
  }
}

void SolenoidControl::hitNote(int note) {
  Serial.println(note);
  digitalWrite(pins[note], HIGH);
  noteOnTime = millis() + 60;
  lastNoteTime = millis();
}

void SolenoidControl::releaseNote(int note) {
  for (int i = 0; i < 15; i++)
    digitalWrite(pins[i], 0);
  noteOnTime = 0;
}

void SolenoidControl::checkNote(int note) {
  for (int i = 0; i < 15; i++) {
    // checks if input note is at an index in the array MIDINotes
    // if so, passes the index to the hitNote function
    if (note == MIDINotes[i] && note != lastNote) {
      hitNote(i);
      lastNote = note;
      break;
    }
  }
}

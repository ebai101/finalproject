#include "Arduino.h"
#include "Notes.h"
#include "Solenoid.h"

Notes::Notes(Solenoid _solenoids[15]) {
  solenoids = _solenoids;
  MIDINotes = {
    43, 45, 47, 48, 50, 52, 53, 55, 57, 59, 60, 62, 64, 65, 67
  } // G3 to G5
}

Notes::playNote(int note) {
  for (int i = 0; i < 15; i++) {
    if (note == MIDINotes[i]) {
      solenoids[MIDINotes[note]].hit();
      break;
    }
  }
}

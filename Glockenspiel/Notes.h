#ifndef Notes_h
#define Notes_h

#include "Arduino.h"
#include "Solenoid.h"

class Notes {
  public:
    Notes(Solenoid _solenoids[15]);

    void playNote(int);

    Solenoid solenoids[15];
    int MIDINotes[15];
};

#endif

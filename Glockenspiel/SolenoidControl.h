#ifndef SolenoidControl_h
#define SolenoidControl_h

#include "Arduino.h"

class SolenoidControl
{
  public:
    SolenoidControl();

    void process();
    void hitNote(int);
    void releaseNote(int);
    void checkNote(int);

    int lastNote;

    int checkInterval;
    unsigned long lastCheck;
    unsigned long noteOnTime;
    unsigned long lastNoteTime;

    int pins[15] = {32, 31, 30, 29, 28, 27, 26, 25, 24, 33, 34, 35, 36, 37};
    int MIDINotes[15] = {55, 57, 59, 60, 62, 64, 65, 67, 69, 71, 72, 74, 76, 77, 79};
  private:
};

#endif


#ifndef SolenoidControl_h
#define SolenoidControl_h

#include "Arduino.h"

class SolenoidControl
{
  public:
    SolenoidControl(int, int, int);

    void hitNote(int);
    void checkNote(int);

    int latchPin;
    int clockPin;
    int dataPin;
    int MIDINotes[15] = {43, 45, 47, 48, 50, 52, 53, 55, 57, 59, 60, 62, 64, 65, 67};
  private:
};

#endif


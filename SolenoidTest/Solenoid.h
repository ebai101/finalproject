#ifndef Solenoid_h
#define Solenoid_h

#include "Arduino.h"

class Solenoid
{
  public:
    Solenoid(int _pin);
    
    void process();
    void hit();

    int pin;
    bool state;
    unsigned long lastCheck;
    int checkInt;
  private:
};

#endif


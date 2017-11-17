#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button
{
  public:
    Button(int _buttonPin, int _buttonNum);
    
    void process();
    void pressHandler(void (*f)(int));
    void releaseHandler(void (*f)(int));
    void (*pressCallback)(int);
    void (*releaseCallback)(int);

    int buttonNum;
    int buttonPin;
    bool firstCheck;
    bool buttonState;
    bool lastButtonState;
    unsigned long lastCheck;
    int checkInt;

  private:
};

#endif

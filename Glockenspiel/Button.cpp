#include "Arduino.h"
#include "Button.h"

Button::Button(int _buttonPin, int _buttonNum)
{
  buttonPin = _buttonPin;
  buttonNum = _buttonNum;
  buttonState = 0;
  lastButtonState = 0;

  pinMode(buttonPin, INPUT);

  lastCheck = 0;
  checkInt = 100;
}

void Button::process()
{
  if (millis() < lastCheck + checkInt) return;

  lastCheck = millis();

  lastButtonState = buttonState;
  buttonState = digitalRead(buttonPin);

  if (lastButtonState == LOW && buttonState == HIGH) {
    pressCallback(buttonNum);
  }
  if (lastButtonState == HIGH && buttonState == LOW) {
    releaseCallback(buttonNum);
  }
}

void Button::pressHandler(void (*f)(int))    //button down
{
  pressCallback = *f;
}

void Button::releaseHandler(void (*f)(int))  //button release
{
  releaseCallback = *f;
}

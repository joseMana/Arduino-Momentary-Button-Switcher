#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {
public:
  Button(int pin, int ledPin, bool momentaryMode = false);

  void setup();
  void check();

private:
  int buttonPin;
  int ledPin;
  int buttonState;
  int lastButtonState;
  bool ledOn;
  bool momentary;
  bool ledState;
  unsigned long lastDebounceTime;
  unsigned long debounceDelay;
};

#endif

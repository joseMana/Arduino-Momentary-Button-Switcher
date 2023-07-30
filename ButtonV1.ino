#include <Arduino.h>
#include "Button.h"

const int button1Pin = 2;
const int button1LedPin = 13;

Button button1(button1Pin, button1LedPin);

void setup() {
  button1.setup();
}

void loop() {
  button1.check();
}
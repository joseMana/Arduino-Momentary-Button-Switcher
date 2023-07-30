#include "Button.h"

Button::Button(int pin, int ledPin, bool momentaryMode) : buttonPin(pin), ledPin(ledPin),
                                              buttonState(HIGH), lastButtonState(HIGH),
                                              ledOn(false), momentary(momentaryMode),
                                              ledState(LOW), lastDebounceTime(0),
                                              debounceDelay(50) {}

void Button::setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void Button::check() {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (momentary) {
        if (buttonState == LOW) {
          ledOn = true;
          digitalWrite(ledPin, HIGH);
        } else {
          ledOn = false;
          digitalWrite(ledPin, LOW);
        }
      } else {
        // Toggle LED state when the button is pressed
        if (buttonState == LOW) {
          ledState = !ledState;
          digitalWrite(ledPin, ledState ? HIGH : LOW);
        }
      }
    }
  }

  lastButtonState = reading;
}

#include "Button.h"

Devices::Button::Button(uint8_t buttonPin) : _buttonPin(buttonPin) {}

void Devices::Button::begin() {
    pinMode(_buttonPin, INPUT);
}

void Devices::Button::startLoop() {
    BaseArduinoDevice::startLoop();

    short buttonState = digitalRead(_buttonPin);
    _stateChanged = buttonState == HIGH;
}


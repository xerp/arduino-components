#include "button.h"

using Devices::Button;

Button::Button(uint8_t buttonPin) : _buttonPin(buttonPin) {
}

void Button::begin() const {
    pinMode(_buttonPin, INPUT);
}

void Button::startLoop() {
    BaseArduinoDevice::startLoop();

    const int32_t buttonState = digitalRead(_buttonPin);
    _stateChanged = buttonState == HIGH;
}

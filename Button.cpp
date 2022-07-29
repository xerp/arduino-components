//
// Created by Santiago de Pedro on 29/7/22.
//

#include "Button.h"

Devices::Button::Button(uint8_t buttonPin) : _buttonPin(buttonPin) {}

void Devices::Button::begin() {
    pinMode(_buttonPin, INPUT);
}

void Devices::Button::startLoop() {
    short buttonState = digitalRead(_buttonPin);
    _stateChanged = buttonState == HIGH;
}
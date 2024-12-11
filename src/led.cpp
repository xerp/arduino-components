#include "led.h"

using Devices::Led;

Led::Led(uint8_t ledPin) : _ledPin(ledPin) {
}

void Led::begin() const {
    pinMode(_ledPin, OUTPUT);
}

void Led::off() {
    digitalWrite(_ledPin, LOW);
    _stateChanged = true;
}

void Led::on() {
    digitalWrite(_ledPin, HIGH);
    _stateChanged = true;
}

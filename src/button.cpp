#include "button.h"
#include "arch/base-internal.h"

Devices::Button::Button(uint8_t buttonPin) : _buttonPin(buttonPin) {
}

void Devices::Button::begin() const {
    board_set_pin_mode(_buttonPin, INPUT);
}

void Devices::Button::startLoop() {
    BaseArduinoDevice::startLoop();

    const int32_t buttonState = board_get_digital_read(_buttonPin);
    _stateChanged = buttonState == HIGH;
}

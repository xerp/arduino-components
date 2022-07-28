//
// Created by Santiago de Pedro on 28/7/22.
//

#include "RotaryEncoder.h"

Devices::RotaryEncoderDevice::RotaryEncoderDevice(uint8_t DTPin, uint8_t CLKPin) : _DTPin(DTPin),
                                                                                   _CLKPin(CLKPin) {}

void Devices::RotaryEncoderDevice::begin() {
    pinMode(_DTPin, INPUT);
    pinMode(_CLKPin, INPUT);

    // Read the initial state of CLK
    _lastCounter = digitalRead(_CLKPin);
}

void Devices::RotaryEncoderDevice::startLoop() {
    short currentCounterState = digitalRead(_CLKPin);

    if (currentCounterState != _lastCounter && currentCounterState == HIGH) {

        // Encoder is rotating CW so increment
        if (digitalRead(_DTPin) != currentCounterState) {
            _direction = RotaryDirection::RIGHT;
            if (_currentCounter < 100)
                _currentCounter++;
        } else {
            // If the DT state is different from the CLK state then the encoder is rotating CCW so decrement
            _direction = RotaryDirection::LEFT;
            if (_currentCounter > 0)
                _currentCounter--;
        }
        _stateChanged = true;
    }
    _lastCounter = currentCounterState;
    delay(1);
}

unsigned short Devices::RotaryEncoderDevice::getCurrentCounter() const {
    return _currentCounter;
}

Devices::RotaryDirection Devices::RotaryEncoderDevice::getDirection() {
    return _direction;
}

Devices::RotaryEncoderDevice::~RotaryEncoderDevice() {
    _direction = UNDEFINED;
}

Devices::PushRotaryEncoderDevice::PushRotaryEncoderDevice(uint8_t DTPin, uint8_t CLKPin, uint8_t pushButtonPin)
        : RotaryEncoderDevice(DTPin, CLKPin), _pushButtonPin(pushButtonPin) {}

void Devices::PushRotaryEncoderDevice::begin() {
    RotaryEncoderDevice::begin();
    pinMode(_pushButtonPin, INPUT_PULLUP);
}

void Devices::PushRotaryEncoderDevice::startLoop() {
    RotaryEncoderDevice::startLoop();
    int btnState = digitalRead(_pushButtonPin);

    // If we detect LOW signal, button is pressed
    if (btnState == LOW) {
        // if 50ms have passed since last LOW pulse, it means that the
        // button has been pressed, released and pressed again
        if (millis() - _lastButtonPress > 50) {
            _buttonPressed = true;
        }

        // Remember last button press event
        _lastButtonPress = millis();
    }
}

void Devices::PushRotaryEncoderDevice::endLoop() {
    BaseArduinoDevice::endLoop();
    _buttonPressed = false;
}

bool Devices::PushRotaryEncoderDevice::buttonPressed() const {
    return _buttonPressed;
}

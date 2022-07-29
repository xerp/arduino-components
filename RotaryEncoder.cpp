//
// Created by Santiago de Pedro on 28/7/22.
//

#include "RotaryEncoder.h"

Devices::RotaryEncoder::RotaryEncoder(uint8_t DTPin, uint8_t CLKPin) : _DTPin(DTPin),
                                                                       _CLKPin(CLKPin) {}

void Devices::RotaryEncoder::begin() {
    pinMode(_DTPin, INPUT);
    pinMode(_CLKPin, INPUT);

    // Read the initial state of CLK
    _lastCounter = digitalRead(_CLKPin);
}

void Devices::RotaryEncoder::startLoop() {
    BaseArduinoDevice::startLoop();

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

unsigned short Devices::RotaryEncoder::getCurrentCounter() const {
    return _currentCounter;
}

Devices::RotaryDirection Devices::RotaryEncoder::getDirection() {
    return _direction;
}

Devices::RotaryEncoder::~RotaryEncoder() {
    _direction = UNDEFINED;
}

Devices::PushRotaryEncoder::PushRotaryEncoder(uint8_t DTPin, uint8_t CLKPin, uint8_t pushButtonPin)
        : RotaryEncoder(DTPin, CLKPin), _pushButtonPin(pushButtonPin) {}

void Devices::PushRotaryEncoder::begin() {
    RotaryEncoder::begin();
    pinMode(_pushButtonPin, INPUT_PULLUP);
}

void Devices::PushRotaryEncoder::startLoop() {
    RotaryEncoder::startLoop();
    _buttonPressed = false;

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

bool Devices::PushRotaryEncoder::buttonPressed() const {
    return _buttonPressed;
}

#include "rotary-encoder.h"

using Devices::RotaryEncoder;
using Devices::PushRotaryEncoder;
using Devices::RotaryDirection;

RotaryEncoder::RotaryEncoder(uint8_t dtPin, uint8_t clkPin) : _dtPin(dtPin), _clkPin(clkPin) {
}

void RotaryEncoder::begin() {
    pinMode(_dtPin, INPUT);
    pinMode(_clkPin, INPUT);

    // Read the initial state of CLK
    _lastCounter = digitalRead(_clkPin);
}

void RotaryEncoder::startLoop() {
    BaseArduinoDevice::startLoop();

    int32_t currentCounterState = digitalRead(_clkPin);

    if (currentCounterState != _lastCounter && currentCounterState == HIGH) {
        // Encoder is rotating CW so increment
        if (digitalRead(_dtPin) != currentCounterState) {
            _direction = RIGHT;
            if (_currentCounter < 100)
                _currentCounter++;
        } else {
            // If the DT state is different from the CLK state then the encoder is rotating CCW so decrement
            _direction = LEFT;
            if (_currentCounter > 0)
                _currentCounter--;
        }
        _stateChanged = true;
    }
    _lastCounter = currentCounterState;
    delay(1000);
}

unsigned short RotaryEncoder::getCurrentCounter() const {
    return _currentCounter;
}

RotaryDirection RotaryEncoder::getDirection() const {
    return _direction;
}

RotaryEncoder::~RotaryEncoder() {
    _direction = UNDEFINED;
}

PushRotaryEncoder::PushRotaryEncoder(uint8_t DTPin, uint8_t CLKPin, uint8_t pushButtonPin)
    : RotaryEncoder(DTPin, CLKPin), _pushButtonPin(pushButtonPin) {
}

void PushRotaryEncoder::begin() {
    RotaryEncoder::begin();
    pinMode(_pushButtonPin, INPUT_PULLUP);
}

void PushRotaryEncoder::startLoop() {
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

boolean PushRotaryEncoder::buttonPressed() const {
    return _buttonPressed;
}

#include "rotary-encoder.h"

Devices::RotaryEncoder::RotaryEncoder(uint8_t dtPin, uint8_t clkPin) : _dtPin(dtPin), _clkPin(clkPin) {
}

void Devices::RotaryEncoder::begin() {
    machine_set_pin_mode(_dtPin, INPUT);
    machine_set_pin_mode(_clkPin, INPUT);

    // Read the initial state of CLK
    _lastCounter = machine_get_digital_read(_clkPin);
}

void Devices::RotaryEncoder::startLoop() {
    BaseArduinoDevice::startLoop();

    int32_t currentCounterState = machine_get_digital_read(_clkPin);

    if (currentCounterState != _lastCounter && currentCounterState == HIGH) {
        // Encoder is rotating CW so increment
        if (machine_get_digital_read(_dtPin) != currentCounterState) {
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
    machine_delay(1);
}

unsigned short Devices::RotaryEncoder::getCurrentCounter() const {
    return _currentCounter;
}

Devices::RotaryDirection Devices::RotaryEncoder::getDirection() const {
    return _direction;
}

Devices::RotaryEncoder::~RotaryEncoder() {
    _direction = UNDEFINED;
}

Devices::PushRotaryEncoder::PushRotaryEncoder(uint8_t DTPin, uint8_t CLKPin, uint8_t pushButtonPin)
    : RotaryEncoder(DTPin, CLKPin), _pushButtonPin(pushButtonPin) {
}

void Devices::PushRotaryEncoder::begin() {
    RotaryEncoder::begin();
    machine_set_pin_mode(_pushButtonPin, INPUT_PULLUP);
}

void Devices::PushRotaryEncoder::startLoop() {
    RotaryEncoder::startLoop();
    _buttonPressed = false;

    int btnState = machine_get_digital_read(_pushButtonPin);

    // If we detect LOW signal, button is pressed
    if (btnState == LOW) {
        // if 50ms have passed since last LOW pulse, it means that the
        // button has been pressed, released and pressed again
        if (machine_get_millis() - _lastButtonPress > 50) {
            _buttonPressed = true;
        }

        // Remember last button press event
        _lastButtonPress = machine_get_millis();
    }
}

boolean Devices::PushRotaryEncoder::buttonPressed() const {
    return _buttonPressed;
}

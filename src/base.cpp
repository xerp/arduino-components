#include "base.h"

using Devices::BaseArduinoDevice;

bool BaseArduinoDevice::statusChanged() const {
    return _stateChanged;
}

void BaseArduinoDevice::end() {
    this->~BaseArduinoDevice();
}

void BaseArduinoDevice::startLoop() {
    reset();
}

void BaseArduinoDevice::reset() {
    _stateChanged = false;
}

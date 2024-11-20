#include "Base.h"

bool Devices::BaseArduinoDevice::statusChanged() const {
    return _stateChanged;
}

void Devices::BaseArduinoDevice::end() {
    this->~BaseArduinoDevice();
}

void Devices::BaseArduinoDevice::startLoop() {
    reset();
}

void Devices::BaseArduinoDevice::reset() {
    _stateChanged = false;
}

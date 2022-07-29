//
// Created by Santiago de Pedro on 28/7/22.
//

#include "Base.h"

bool Devices::BaseArduinoDevice::statusChanged() const {
    return _stateChanged;
}

void Devices::BaseArduinoDevice::end() {
    this->BaseArduinoDevice::~BaseArduinoDevice();
}

void Devices::BaseArduinoDevice::startLoop() {
    BaseArduinoDevice::reset();
}

void Devices::BaseArduinoDevice::reset() {
    _stateChanged = false;
}

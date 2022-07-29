//
// Created by Santiago de Pedro on 28/7/22.
//

#include "Base.h"

void Devices::BaseArduinoDevice::endLoop() {
    _stateChanged = false;
}

bool Devices::BaseArduinoDevice::statusChanged() const {
    return _stateChanged;
}

void Devices::BaseArduinoDevice::end() {
    BaseArduinoDevice::~BaseArduinoDevice();
}

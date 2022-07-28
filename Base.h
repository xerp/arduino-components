//
// Created by Santiago de Pedro on 28/7/22.
//

#ifndef COMPONENTS_BASE_H
#define COMPONENTS_BASE_H

#include "Arduino.h"

namespace Devices {

    class BaseArduinoDevice {
    public:
        virtual void begin() = 0;

        virtual void startLoop() = 0;

        virtual void endLoop();

        bool statusChanged() const;

    protected:
        bool _stateChanged = false;
    };
}

#endif //COMPONENTS_BASE_H

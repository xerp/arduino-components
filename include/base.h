#ifndef BASE_H
#define BASE_H

#include "arch/base.h"

namespace Devices {
    class BaseArduinoDevice {
    public:
        ~BaseArduinoDevice() = default;

        void begin();

        void end();

        void startLoop();

        boolean statusChanged() const;

    protected:
        boolean _stateChanged = false;

        void reset();
    };
}

#endif //BASE_H

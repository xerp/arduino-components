#ifndef BASE_H
#define BASE_H

#include "Arch.h"

namespace Devices {
    class BaseArduinoDevice {
    public:
        ~BaseArduinoDevice() = default;

        virtual void begin() = 0;

        void end();

        virtual void startLoop();

        bool statusChanged() const;

    protected:
        bool _stateChanged = false;

        void reset();
    };
}

#endif //BASE_H

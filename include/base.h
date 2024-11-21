#ifndef BASE_H
#define BASE_H

#include "arch/base.h"

namespace Devices {
    class BaseArduinoDevice {
    public:
        virtual ~BaseArduinoDevice() = default;

        virtual void begin();

        void end();

        virtual void startLoop();

        boolean statusChanged() const;

    protected:
        boolean _stateChanged = false;

        void reset();
    };
}

#endif //BASE_H

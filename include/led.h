#ifndef LED_H
#define LED_H

#include "base.h"

namespace Devices {
    class Led : public BaseArduinoDevice {
    public:
        explicit Led(uint8_t ledPin);

        void begin() const;

        void on();
        void off();

    protected:
        uint8_t _ledPin{};
    };
}

#endif //LED_H

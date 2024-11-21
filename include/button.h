#ifndef BUTTON_H
#define BUTTON_H

#include "base.h"

namespace Devices {
    class Button : public BaseArduinoDevice {
    public:
        explicit Button(uint8_t buttonPin);

        void begin() override;

        void startLoop() override;

    protected:
        uint8_t _buttonPin{};
    };
}


#endif //BUTTON_H

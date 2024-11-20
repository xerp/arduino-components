//
// Created by Santiago de Pedro on 29/7/22.
//

#ifndef BUTTON_H
#define BUTTON_H

#include "Base.h"

namespace Devices {
    class Button : public BaseArduinoDevice {
    public:
        Button(uint8_t buttonPin);

        void begin() override;

        void startLoop() override;

    protected:
        uint8_t _buttonPin{};
    };
}


#endif //BUTTON_H

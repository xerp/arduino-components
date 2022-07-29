//
// Created by Santiago de Pedro on 29/7/22.
//

#ifndef COMPONENTS_BUTTON_H
#define COMPONENTS_BUTTON_H

#include "Base.h"

namespace Devices {
    class Button : public BaseArduinoDevice {
    public:
        explicit Button(uint8_t buttonPin);

        void begin() override;

        void startLoop() override;

    protected:
        uint8_t _buttonPin;
    };
}


#endif //COMPONENTS_BUTTON_H

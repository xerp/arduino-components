//
// Created by Santiago de Pedro on 28/7/22.
//

#ifndef COMPONENTS_ROTARYENCODER_H
#define COMPONENTS_ROTARYENCODER_H

#include "Base.h"

namespace Devices {

    typedef enum {
        UNDEFINED = 0,
        LEFT = 'L',
        RIGHT = 'R'
    } RotaryDirection;

    class RotaryEncoder : public BaseArduinoDevice {
    public:
        RotaryEncoder(uint8_t DTPin, uint8_t CLKPin);

        virtual ~RotaryEncoder();

        void begin() override;

        void startLoop() override;

        unsigned short getCurrentCounter() const;

        RotaryDirection getDirection();

    protected:
        uint8_t _DTPin;
        uint8_t _CLKPin;

    private:
        unsigned short _currentCounter = 0;
        RotaryDirection _direction = UNDEFINED;
        short _lastCounter = 0;
    };

    class PushRotaryEncoder : public RotaryEncoder {
    public:
        PushRotaryEncoder(uint8_t DTPin, uint8_t CLKPin, uint8_t pushButtonPin);

        void begin() override;

        void startLoop() override;

        void endLoop() override;

        bool buttonPressed() const;

    protected:
        uint8_t _pushButtonPin;

    private:
        bool _buttonPressed;
        unsigned long _lastButtonPress = 0;
    };
}

#endif //COMPONENTS_ROTARYENCODER_H

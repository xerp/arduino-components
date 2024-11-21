#ifndef ROTARY_ENCODER_H
#define ROTARY_ENCODER_H

#include "base.h"

namespace Devices {
    typedef enum {
        UNDEFINED = 0,
        LEFT = 'L',
        RIGHT = 'R'
    } RotaryDirection;

    class RotaryEncoder : public BaseArduinoDevice {
    public:
        RotaryEncoder(uint8_t dtPin, uint8_t clkPin);

        ~RotaryEncoder() override;

        void begin() override;

        void startLoop() override;

        uint16_t getCurrentCounter() const;

        RotaryDirection getDirection() const;

    protected:
        uint8_t _dtPin{};
        uint8_t _clkPin{};

    private:
        uint16_t _currentCounter = 0;
        RotaryDirection _direction = UNDEFINED;
        int32_t _lastCounter = 0;
    };

    class PushRotaryEncoder : public RotaryEncoder {
    public:
        PushRotaryEncoder(uint8_t DTPin, uint8_t CLKPin, uint8_t pushButtonPin);

        void begin() override;

        void startLoop() override;

        boolean buttonPressed() const;

    protected:
        uint8_t _pushButtonPin{};

    private:
        boolean _buttonPressed{};
        ulong_t _lastButtonPress = 0;
    };
}

#endif //ROTARY_ENCODER_H

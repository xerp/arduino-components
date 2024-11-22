#ifndef ARCH_BASE_H
#define ARCH_BASE_H

#include "arch/types.h"
#include "arch/macros.h"

typedef struct Board {
    const char *name;

    void (*pinMode)(uint8_t, uint8_t);

    void (*digitalWrite)(uint8_t, uint8_t);

    int32_t (*digitalRead)(uint8_t);

    void (*delay)(ulong_t);

    ulong_t (*millis)();

    ulong_t (*micros)();
} Board;

void board_init(const char *name);

const char *board_get_name();

void board_set_pin_mode_function(void (*pinModeFunction)(uint8_t, uint8_t));

void board_set_digital_write_function(void (*digitalWriteFunction)(uint8_t, uint8_t));

void board_set_digital_read_function(int32_t (*digitalReadFunction)(uint8_t));

void board_set_millis_function(ulong_t (*millisFunction)());

void board_set_micros_function(ulong_t (*microsFunction)());

void board_set_delay_function(void (*delayFunction)(ulong_t));

#ifdef ARDUINO
#include <Arduino.h>

#endif

#ifdef UNIX
#include <cstdint>
#endif

#endif //ARCH_BASE_H

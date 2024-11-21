#ifndef ARCH_BASE_INTERNAL_H
#define ARCH_BASE_INTERNAL_H

#include "arch/base.h"

void board_set_pin_mode(uint8_t, uint8_t);

void board_set_digital_write(uint8_t, uint8_t);

int32_t board_get_digital_read(uint8_t);

ulong_t board_get_millis();

ulong_t board_get_micros();

void board_delay(ulong_t);

#endif //ARCH_BASE_INTERNAL_H

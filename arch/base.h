#ifndef ARCH_BASE_H
#define ARCH_BASE_H

#include <Arduino.h>
#include "macros.h"

typedef struct Board {
    const char *name;
} Board;

void board_init(const char *name);

const char *board_get_name();

#endif //ARCH_BASE_H

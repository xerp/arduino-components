#ifndef ARCH_H
#define ARCH_H

#ifdef Arduino_h
#define ARDUINO
#else
#define UNIX
#endif

#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

#define None ((void*) 0)
#define NoValue (-1)

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;

typedef unsigned long ulong_t;

typedef int int32_t;
typedef short int16_t;

typedef bool boolean;
typedef uint8_t byte;


typedef struct Machine {
    char *name;

    void (*pinMode)(uint8_t, uint8_t);

    void (*digitalWrite)(uint8_t, uint8_t);

    int32_t (*digitalRead)(uint8_t);

    void (*delay)(ulong_t);

    ulong_t (*millis)();

    ulong_t (*micros)();
} Machine;

Machine *machine;

void machine_init(char name[]);

void machine_set_pin_mode_function(void (*pinModeFunction)(uint8_t, uint8_t));

void machine_set_pin_mode(uint8_t, uint8_t);


void machine_set_digital_write_function(void (*digitalWriteFunction)(uint8_t, uint8_t));

void machine_set_digital_write(uint8_t, uint8_t);


void machine_set_digital_read_function(int32_t (*digitalReadFunction)(uint8_t));

int32_t machine_get_digital_read(uint8_t);


void machine_set_millis_function(ulong_t (*millisFunction)());

ulong_t machine_get_millis();


void machine_set_micros_function(ulong_t (*microsFunction)());

ulong_t machine_get_micros();


void machine_set_delay_function(void (*delayFunction)(ulong_t));

void machine_delay(ulong_t);

#ifdef ARDUINO
#include <Arduino.h>

#endif

#ifdef UNIX
#include <cstdint>
#endif

#endif //ARCH_H

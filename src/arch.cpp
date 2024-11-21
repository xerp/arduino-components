#include "arch.h"


void machine_init(char name[]) {
    machine->name = name;
}

void machine_set_pin_mode_function(void (*pinModeFunction)(uint8_t, uint8_t)) {
    machine->pinMode = pinModeFunction;
}

void machine_set_pin_mode(uint8_t pin, uint8_t mode) {
    if (machine->pinMode != None) {
        machine->pinMode(pin, mode);
    }
}

void machine_set_digital_write_function(void (*digitalWriteFunction)(uint8_t, uint8_t)) {
    machine->digitalWrite = digitalWriteFunction;
}

void machine_set_digital_write(uint8_t pin, uint8_t value) {
    if (machine->digitalWrite != None) {
        machine->digitalWrite(pin, value);
    }
}

void machine_set_digital_read_function(int32_t (*digitalReadFunction)(uint8_t)) {
    machine->digitalRead = digitalReadFunction;
}


int32_t machine_get_digital_read(uint8_t pin) {
    if (machine->digitalRead != None) {
        return machine->digitalRead(pin);
    }

    return NoValue;
}

void machine_set_millis_function(ulong_t (*millisFunction)()) {
    machine->millis = millisFunction;
}

ulong_t machine_get_millis() {
    if (machine->millis != None) {
        return machine->millis();
    }

    return NoValue;
}

void machine_set_micros_function(ulong_t (*microsFunction)()) {
    machine->micros = microsFunction;
}

ulong_t machine_get_micros() {
    if (machine->micros != None) {
        return machine->micros();
    }

    return NoValue;
}

void machine_set_delay_function(void (*delayFunction)(ulong_t)) {
    machine->delay = delayFunction;
}

void machine_delay(ulong_t value) {
    if (machine->delay != None) {
        machine->delay(value);
    }
}

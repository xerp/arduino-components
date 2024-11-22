#include "arch/base.h"
#include "arch/base-internal.h"

Board *board;

void board_init(const char *name) {
    board = new Board();
    board->name = name;
}

const char *board_get_name() {
    if (board != None && board->name != None) {
        return board->name;
    }

    return "";
}

void board_set_pin_mode_function(void (*pinModeFunction)(uint8_t, uint8_t)) {
    board->pinMode = pinModeFunction;
}

void board_set_digital_write_function(void (*digitalWriteFunction)(uint8_t, uint8_t)) {
    board->digitalWrite = digitalWriteFunction;
}

void board_set_digital_read_function(int32_t (*digitalReadFunction)(uint8_t)) {
    board->digitalRead = digitalReadFunction;
}

void board_set_millis_function(ulong_t (*millisFunction)()) {
    board->millis = millisFunction;
}

void board_set_micros_function(ulong_t (*microsFunction)()) {
    board->micros = microsFunction;
}

void board_set_delay_function(void (*delayFunction)(ulong_t)) {
    board->delay = delayFunction;
}

// Internal Functions

void board_set_pin_mode(uint8_t pin, uint8_t mode) {
    if (board != None && board->pinMode != None) {
        board->pinMode(pin, mode);
    }
}

void board_set_digital_write(uint8_t pin, uint8_t value) {
    if (board != None && board->digitalWrite != None) {
        board->digitalWrite(pin, value);
    }
}

int32_t board_get_digital_read(uint8_t pin) {
    if (board != None && board->digitalRead != None) {
        return board->digitalRead(pin);
    }

    return NoValue;
}

ulong_t board_get_millis() {
    if (board != None && board->millis != None) {
        return board->millis();
    }

    return NoValue;
}

ulong_t board_get_micros() {
    if (board != None && board->micros != None) {
        return board->micros();
    }

    return NoValue;
}

void board_delay(ulong_t value) {
    if (board != None && board->delay != None) {
        board->delay(value);
    }
}

#include <cstdio>
#include <unistd.h>
#include "button.h"

using Devices::Button;

Button button(1);

void pin_mode_callback(uint8_t pin, uint8_t mode) {
    printf("Pin :%d mode :%d\n", pin, mode);
}

int32_t get_digital_read_callback(uint8_t pin) {
    printf("Pin :%d\n", pin);

    return 0;
}

int main(int argc, char **argv) {
    board_init("MacOS X");
    board_set_pin_mode_function(pin_mode_callback);
    board_set_digital_read_function(get_digital_read_callback);

    button.begin();
    printf("%s\n", board_get_name());

    while (true) {
        button.startLoop();
        printf("status :%d\n", button.statusChanged());
        sleep(2);
    }

    return 0;
}

#include <cstdio>
#include <unistd.h>
#include "button.h"

using Devices::Button;

Button button(13);

int main(int argc, char **argv) {
    board_init("MacOS X");

    printf("Board name: %s\n", board_get_name());
    button.begin();

    button.startLoop();
    printf("status: %d\n", button.statusChanged());
    sleep(2);

    return 0;
}

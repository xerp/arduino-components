#include "arch/base.h"

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

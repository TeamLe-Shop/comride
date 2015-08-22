#include "util.h"

void fill_row(WINDOW* window, int row, char ch)
{
    int y, x;
    getmaxyx(stdscr, y, x);

    for (int i = 0; i < x; i++) {
        mvwinsch(window, row, i, ch);
    }
}

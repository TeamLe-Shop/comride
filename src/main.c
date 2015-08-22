#include <stdio.h>
#include <curses.h>

#include <clean/clean.h>

#include <clean/elements/label.h>

int main()
{
    initscr();
    start_color();
    //noecho();
    keypad(stdscr, TRUE);
    ui_init();


    while (true) {
        ui_draw();
        int key = getch();
        if (key == KEY_F(1)) {
            break;
        }
        ui_pass_input(key);
    }

    ui_destroy();
    endwin();
}

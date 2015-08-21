#include <stdio.h>
#include <curses.h>

#include <clean/clean.h>

#include <clean/elements/label.h>

int main()
{
    initscr();

    Surface* s = Surface_New(80, 24);
    Label* label = Label_New("Hello world!", 0, 0);
    Surface_AddElement(s, label);
    Surface_DrawToWindow(s, stdscr);
    getch();

    endwin();
}

#include "ui.h"

#include <curses.h>

#include <clean/clean.h>

#include <clean/elements/header.h>

/* UI structure */
struct UI {
    Surface* main_surface;
    Header* main_header;
} ui;

void ui_init()
{
    // Initialise color pairs
    init_pair(1, COLOR_WHITE, COLOR_BLUE);

    // Clean Surface and elements
    int max_x, max_y;
    getmaxyx(stdscr, max_y, max_x);
    ui.main_surface = Surface_New(max_x, max_y);
    ui.main_header = Header_New("ComrIDE", COLOR_WINDOW_HEADER, true);

    Surface_AddElement(ui.main_surface, ui.main_header);
}

void ui_destroy()
{
    Surface_Destroy(ui.main_surface);
}

void ui_draw()
{
    Surface_DrawToWindow(ui.main_surface, stdscr);
    mvwprintw(stdscr, 1, 0, "Can't type stuff yet! Press F1 to quit!");
}

void ui_pass_input()
{

}

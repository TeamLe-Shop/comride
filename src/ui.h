#ifndef UI_H
#define UI_H

/* Color Pairs */

#define COLOR_WINDOW_HEADER COLOR_PAIR(1)
#define COLOR_DEFAULT COLOR_PAIR(0)

/* Initialises color pairs and other UI-related things. */
void ui_init();

/* Draws the UI. */
void ui_draw();

/* Pass a keypress (usually from getch) to the system. */
void ui_pass_input();

#endif /* UI_H */

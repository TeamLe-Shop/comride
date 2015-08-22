#include "header.h"

Header* Header_New(char* text, int color, bool centered)
{
    Header* header = malloc(sizeof(Header));

    header->draw = Header_Draw;
    header->destroy = Header_Destroy;

    header->text = strdup(text);
    header->x = 0;
    header->y = 0;

    header->color = color;
    header->centered = centered;

    return header;
}

void Header_Draw(void* self, Surface* surface, WINDOW* window)
{
    Header* header = (Header*)self;

    int max_y, max_x;
    getmaxyx(window, max_y, max_x);
    int text_x = 0;

    if (header->centered) {
        text_x = (max_x / 2) - (strlen(header->text) / 2);
    }

    attron(header->color);
        fill_row(window, header->y, ' ');
        mvwprintw(window, header->y, text_x, header->text);
    attroff(header->color);
}

void Header_Destroy(void* self, Surface* surface)
{
    Header* header = (Header*) self;
    free(header->text);
    free(header);
}

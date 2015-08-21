#include "label.h"

Label* Label_New(char* text, int y, int x)
{
    Label* label = malloc(sizeof(Label));

    label->draw = Label_Draw;
    label->destroy = Label_Destroy;

    label->text = strdup(text);
    label->x = x;
    label->y = y;

    return label;
}

void Label_Draw(void* self, Surface* surface, WINDOW* window)
{
    Label* label = (Label*)self;

    mvwprintw(window, label->y, label->x, label->text);
}

void Label_Destroy(void* self, Surface* surface)
{
    Label* label = (Label*) self;
    free(label->text);
    free(label);
}

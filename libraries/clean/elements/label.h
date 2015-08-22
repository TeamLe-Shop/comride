#ifndef CLEAN_LABEL_H
#define CLEAN_LABEL_H

#include "../clean.h"

struct Label {
    ELEMENT_BASE_MEMBERS

    char* text;
};

typedef struct Label Label;

Label* Label_New(char* text, int y, int x);

void Label_Draw(void* self, Surface* surface, WINDOW* window);

void Label_Destroy(void* self, Surface* surface);

#endif /* LABEL_H */

#ifndef CLEAN_HEADER_H
#define CLEAN_HEADER_H

#include "../clean.h"

#include <stdbool.h>

struct Header {
    ELEMENT_BASE_MEMBERS

    char* text;
    ColorPair color;
    bool centered;
};

typedef struct Header Header;

Header* Header_New(char* text, ColorPair color, bool centered);

void Header_Draw(void* self, Surface* surface, WINDOW* window);

void Header_Destroy(void* self, Surface* surface);

#endif /* LABEL_H */

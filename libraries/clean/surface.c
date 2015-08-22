#include "clean.h"

#include <stdlib.h>

Surface* Surface_New(size_t width, size_t height)
{
    Surface* surface = malloc(sizeof(Surface));

    ListInit(surface->elements, NULL, NULL);

    surface->width = width;
    surface->height = height;

    return surface;
}

void Surface_Destroy(Surface* surface)
{
    for (size_t i = 0; i < surface->elements->size; i++) {
        Element* e = surface->elements->list[i];
        e->destroy(e, surface);
    }

    List_Destroy(surface->elements);
    free(surface);
}

void Surface_AddElement(Surface* surface, void* element)
{
    List_Append(surface->elements, element);
}

void Surface_DrawToWindow(Surface* surface, WINDOW* window)
{
    werase(window);
    for (size_t i = 0; i < surface->elements->size; i++) {
        Element* e = surface->elements->list[i];
        e->draw(e, surface, window);
    }
    wrefresh(window);
}

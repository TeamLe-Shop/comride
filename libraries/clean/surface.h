#ifndef SURFACE_H
#define SURFACE_H

#include <curses.h>

#include <types/list.h>

/* A surface onto which elements are added.
 *
 * Elements drawn onto a Surface object can then be drawn to a curses WINDOW.
 */
struct Surface {
    ListStruct(Element*)* elements;
    size_t width;
    size_t height;
};

/* Allocates memory for and returns a new Surface. */
Surface* Surface_New(size_t width, size_t height);

/* Deallocates memory used by a Surface object. */
void Surface_Destroy(Surface* surface);

/* Adds an Element to the Surface. */
void Surface_AddElement(Surface* surface, Element* element);


#endif /* SURFACE_H */

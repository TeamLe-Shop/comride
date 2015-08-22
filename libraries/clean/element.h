#ifndef CLEAN_ELEMENT_H
#define CLEAN_ELEMENT_H

#define ELEMENT_BASE_MEMBERS \
    void (*draw)(void* self, Surface* surface, WINDOW* window); \
    void (*destroy)(void* self, Surface* surface); \
    int x; \
    int y;

#define ELEMENT_FIELD_MEMORY 128

/* The base structure for an element of an interface. */
struct Element {
    ELEMENT_BASE_MEMBERS
    /* Memory for additional fields of derived structures. */
    char data[ELEMENT_FIELD_MEMORY];
};

#endif /* ELEMENT_H */

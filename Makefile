CC=clang
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=src/*c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=comride
LIBRARIES_DIR=libraries

# Clean Library
LIB_CLEAN=lib_clean
LIB_CLEAN_SRC=$(shell find $(LIBRARIES_DIR) | grep "\.c")
LIB_CLEAN_OBJ=$(LIB_CLEAN_SRC:.c=.o)

LIB_OBJECTS=$(LIB_CLEAN_OBJ)
LIB_SOURCES=$(LIB_CLEAN_SRC)

all:  $(LIB_SOURCES) $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(LIB_OBJECTS) $(OBJECTS)
	$(CC) $(LDFLAGS) $(LIB_OBJECTS) $(OBJECTS) -lncurses \
		-I$(LIBRARIES_DIR) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	rm `find . | grep "\.o"`

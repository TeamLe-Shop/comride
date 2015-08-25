CC=clang
LIBTOOL=libtool
CFLAGS=-c -Wall
LDFLAGS=-lncurses
LIBTOOL_FLAGS=-dynamic
SOURCES=src/*c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=comride
LIBRARIES_DIR=libraries

# Clean Library
LIB_CLEAN=lib_clean
LIB_CLEAN_SRC=$(shell find $(LIBRARIES_DIR) | grep "\.c")
LIB_CLEAN_OBJ=$(shell basename $(LIB_CLEAN_SRC:.c=.o))

LIB_OBJECTS=$(LIB_CLEAN_OBJ)
LIB_SOURCES=$(LIB_CLEAN_SRC)
LIBS=$(LIB_CLEAN)

all:  $(LIB_SOURCES) $(SOURCES) $(EXECUTABLE)

$(LIB_CLEAN): $(LIB_CLEAN_SRC)
	$(LIBTOOL) $(AR_FLAGS) $(LIB_CLEAN_OBJ) -o $@

$(EXECUTABLE): $(LIBS) $(OBJECTS)
	$(CC) $(LIBS) $(LDFLAGS) $(OBJECTS) \
		-I$(LIBRARIES_DIR) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	rm `find . | grep "\.o"`

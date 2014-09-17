UNAME := $(shell uname)
LIB = libes.dylib

ifeq ($(UNAME), Linux)
LIB = libes.so
endif

ifeq ($(UNAME), Darwin)
# link libraries for Mac OS X like:
# -F /Library/Frameworks -framework SDL2 -framework SDL2_gfx
# Snippet: https://github.com/L3K0V/fmi-course-game/blob/master/Makefile
endif

prefix = /usr/local
libdir = $(prefix)/lib
headerdir = $(prefix)/include

all: es_main.o

# Workaround for Mac OS X
ifeq ($(UNAME), Linux)
	gcc -shared -o $(LIB) src/es_main.o -lSDL2 -lSDL2_gfx
endif

ifeq ($(UNAME), Darwin)
	gcc -shared -o $(LIB) src/es_main.o -F /Library/Frameworks -framework SDL2 -framework SDL2_gfx
endif

es_main.o:
	gcc src/es_main.c -c -I include/ -fpic -o src/es_main.o

install: $(LIB)
	cp $(LIB) $(libdir)
	cp src/es_main.h $(headerdir)

uninstall:
	rm $(libdir)/$(LIB)
	rm $(headerdir)/es_main.h
	
clean:
	rm src/*.o
	rm $(LIB)


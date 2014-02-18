UNAME := $(shell uname)
LIB = libes.dylib

ifeq ($(UNAME), Linux)
LIB = libes.so
endif

prefix = /usr/local
libdir = $(prefix)/lib
headerdir = $(prefix)/include

all: es_main.o
	gcc -shared -o $(LIB) src/es_main.o -lSDL2 -lSDL2_gfx

es_main.o:
	gcc src/es_main.c -c -I include/ -fpic -o src/es_main.o

install: all 
	cp $(LIB) $(libdir)
	cp src/es_main.h $(headerdir)

uninstall:
	rm $(libdir)/$(LIB)
	rm $(headerdir)/es_main.h
	
clean:
	rm src/*.o
	rm $(LIB)


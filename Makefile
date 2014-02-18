all:
	gcc src/es_main.c -c -I include/ -fpic -o src/es_main.o
	gcc -shared -o libes.dylib src/es_main.o -lSDL2 -lSDL2_gfx

clean:
	rm src/*.o
	rm libes.dylib


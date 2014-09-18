es_framework
============

SDL based framework for education purposes

Build instructions:

In order to build the framework itself invoke following commands:

```
make
make install
```

This will compile the library, create a library file and will copy it into usr/local/lib.
Also it will copy headers into usr/local/include.

__Note:__ For this step to complete SDL2 is needed to be installed on the system.

The project contains simple build script and source in usage folder which make the task of compiling single file and linking it with this framework easy.
After you have written your source file(for example main.c) which uses this framework use the following command:

```
{path to root build scrip}/build main
```

This will compile and link the given source file with the given name. 

__Note:__ Don't add the extension of the file which you need to compile!

__Note:__ For this to work es_framework must be compiled and installed.

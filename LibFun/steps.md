# Steps to creating a static library

1. Compile c source file(s) to objects
    * Example: `gcc -c add.c subtract.c`
2. Link objects
    * Example: `ar rs libdemo.a add.o subtract.o`
3. Create header file 
    * Example: 
        (demo.h)
        ```
        int add(int, int);
        int subtract(int, int);
        ```
4. Optional: remove the source files and object files
5. In the consumer of the static library add an include to the library header
    * Example: `#include "demo.h"`
6. Compile consumer source c file
    * Example: `gcc -c main.c` 
7. Build the consumer executable with the object(s) and static library
    * Example: `gcc -o demo.app main.o libdemo.a`
8. Run the executable
    * Example: `./demo.app`

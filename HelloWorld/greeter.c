#include <stdio.h>

void greet()
{
    char c = 'H';
    char * p = &c;
    
    printf("%cello world!\n", *p);
}

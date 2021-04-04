// g++ -o FamilyFortunesSounds main.c

#include <cstdlib>
#include <stdio.h>

int main()
{
    char c;
    printf("Found / Not Found / Quit [f/n/q]\n");
    while (1)
    {
        scanf("%c", &c);
        if (c == 'f')
        {
            std::system("mpv ~/Audio/Family\\ Fortunes\\ Sounds/Found.mp3");
        }
        else if (c == 'n')
        {
            std::system("mpv ~/Audio/Family\\ Fortunes\\ Sounds/NotFound.mp3");
        }
        else if (c == 'q')
        {
            break;
        }
    }
    return 0;
}

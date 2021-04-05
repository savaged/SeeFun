// g++ -o FamilyFortunesSounds main.c -lncurses

#include <cstdlib>
#include <ncurses.h>
#include <unistd.h>

int kbhit(void)
{
    int ch = getch();

    if (ch != ERR)
    {
        ungetch(ch);
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);

    printw("\nFound / Not Found / Top Answer / Quit [f/n/t/q]\n");

    int c;
    while (1)
    {
        if (kbhit())
        {
            c = getch();
            refresh();

            if (c == 'f')
            {
                std::system("mpv ~/Audio/Family\\ Fortunes\\ Sounds/Found.mp3");
            }
            else if (c == 'n')
            {
                std::system("mpv ~/Audio/Family\\ Fortunes\\ Sounds/NotFound.mp3");
            }
            else if (c == 't')
            {
                std::system("mpv ~/Audio/Family\\ Fortunes\\ Sounds/TopAnswer.mp3");
            }
            else if (c == 'q')
            {
                endwin();
                break;
            }
        }
        else
        {
            refresh();
            sleep(1);
        }
    }
    return 0;
}

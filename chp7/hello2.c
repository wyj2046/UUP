#include <stdio.h>
#include <curses.h>

int main(int argc, char* argv[])
{
    initscr();
    clear();
    for (int i = 0; i < LINES; ++i)
    {
	move(i, i+i);
	if (i%2 == 1 )
	{
	    standout();
	}
	addstr("hello,world!");
	if (i%2 == 1 )
	{
	    standend();
	}
    }
    refresh();
    getch();
    endwin();
    return 0;
}

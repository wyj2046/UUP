#include <stdio.h>
#include <curses.h>

int main(int argc, char* argv[])
{
    initscr();
    clear();
    for (int i = 0; i < LINES; ++i)
    {
	move(i, i+1);
	if (i%2 == 1 )
	{
	    standout();
	}
	addstr("hello,world!");
	if (i%2 == 1 )
	{
	    standend();
	}
	refresh();
	sleep(1);
	move(i, i+i);
	addstr("            ");
    }
    endwin();
    return 0;
}

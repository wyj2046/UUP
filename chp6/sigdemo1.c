#include <stdio.h>
#include <signal.h>

int main(void)
{
    void f(int);
    signal(SIGINT, f);
    for (int i = 0; i < 5; ++i)
    {
	printf ("hello\n");
	sleep(1);
    }
    return 0;
}

void f(int signum)
{
    printf ("OUCH! \n");
}

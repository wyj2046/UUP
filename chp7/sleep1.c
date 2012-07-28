#include <stdio.h>
#include <signal.h>
// #define SHHHH
// 
int main(int argc, char* argv[])
{
    void wakeup(int);

    printf ("about to sleep for 4 seconds\n");
    signal(SIGALRM, wakeup);
    alarm(4);
    pause();
    printf ("Morning so soon?\n");
    return 0;
}

void wakeup(int signum)
{
    #ifndef SHHHH
    printf ("Alarm reveived from kernel\n");
    #endif
}

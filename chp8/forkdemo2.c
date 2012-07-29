#include <stdio.h>

int main(int argc, char* argv[])
{
    printf ("my pid is %d\n",getpid());
    fork();
    fork();
    fork();
    printf ("my pid is %d\n",getpid());
    return 0;
}

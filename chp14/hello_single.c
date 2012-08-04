#include <stdio.h>
#define NUM 5

int main(int argc, char *argv[])
{
    void print_msg(char*);

    print_msg("hello");
    print_msg("world\n");
    return 0;
}

void print_msg(char* m)
{
    for (int i = 0; i < NUM; ++i)
    {
	printf ("%s", m);
	fflush(stdout);
	sleep(1);
    }
}

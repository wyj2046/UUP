#include <stdio.h>
#include <signal.h>

#define INPUTLEN 100

void inthandler(int s)
{
    printf ("Received signal %d..waiting\n",s);
    sleep(2);
    printf ("Leaving inthandler\n");
}

void quithandler(int s)
{
    printf ("Received signal %d..waiting\n",s);
    sleep(3);
    printf ("Leaving quithandler\n");
}

int main(int argc, char* argv[])
{
    char input[INPUTLEN];
    int nchars;

    signal(SIGINT, inthandler);
    signal(SIGQUIT, quithandler);

    do
    {
	printf ("\nType a message\n");
	nchars = read(0, input, (INPUTLEN-1));
	if (nchars == -1)
	{
	    perror("read returned an error");
	}
	else
	{
	    input[nchars] = '\0';
	    printf ("You typed: %s\n", input);
	}
    } while (strncmp(input, "quit", 4) != 0);
    return 0;
}

#include <stdio.h>

#define DELAY 2

void child_code(int delay)
{
    printf ("child %d here. will sleep for %d seconds\n",getpid(), delay);
    sleep(delay);
    printf ("child done. about to exit\n");
    exit(17);
}

void parent_mode(int childpid)
{
    int wait_rv = wait(NULL);
    printf ("done waiting for %d. Wait returned: %d\n",childpid, wait_rv);
}

int main(int argc, char* argv[])
{
    int newpid;
    printf ("before: mypid is %d\n",getpid());
    if ((newpid = fork()) == -1)
    {
	perror("fork");
    }
    else if (newpid == 0)
    {
	child_code(DELAY);
    }
    else
    {
	parent_mode(newpid);
    }
    return 0;
}

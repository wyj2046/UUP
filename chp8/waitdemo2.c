#include <stdio.h>

#define DELAY 5

void child_code(int delay)
{
    printf ("child %d here. will sleep for %d seconds\n",getpid(), delay);
    sleep(delay);
    printf ("child done. about to exit\n");
    exit(17);
}

void parent_mode(int childpid)
{
    int wait_rv;
    int child_status;
    int high_8, low_7, bit_7;
    wait_rv = wait(&child_status);
    printf ("done waiting for %d. Wait returned: %d\n",childpid, wait_rv);
    high_8 = child_status >> 8;
    low_7 = child_status & 0x7F;
    bit_7 = child_status & 0x80;
    printf ("status: exit=%d, sig=%d, core=%d\n",high_8, low_7, bit_7);
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

#include <stdio.h>
#include <termios.h>

int main(void){
struct termios info;
int rv;

rv = tcgetattr(0, &info);
if (rv == -1)
{
perror("tcgetattr");
exit(1);
}

if (info.c_lflag & ECHO)
{
printf ("echo is on, since its bit is 1\n");
}
else
    printf ("echo is off, since its bit is 0\n");
  return 0;
}

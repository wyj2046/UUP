#include <stdio.h>

int main(int argc, char* argv[])
{
    char* arglist[0];
    arglist[0] = 0;
    printf ("*** About to exec emacs\n");
    execvp("emacs", arglist);
    printf ("*** emacs is done. bye\n");
    return 0;
}

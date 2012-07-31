#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE* fp = popen("who|sort", "r");
    char buf[100];
    int i = 0;
    while (fgets(buf, 100, fp) != NULL)
    {
	printf("%3d %s", i++, buf);
    }

    pclose(fp);

    return 0;
}

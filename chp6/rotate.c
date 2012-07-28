#include <stdio.h>
#include <ctype.h>


int main(void){
    int c;
    while ((c = getchar()) != EOF)
    {
	if (c == 'z')
	{
	    c = 'a';
	}
	else if (islower(c))
	{
	    c++;
	}
	putchar(c);
    }
  return 0;
}

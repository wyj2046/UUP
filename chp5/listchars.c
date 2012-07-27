#include <stdio.h>

int main(void){
    int c, n = 0;
    while ((c = getchar()) != 'Q')
	printf ("char %3d is %c code %d\n", n++, c, c);
  return 0;
}

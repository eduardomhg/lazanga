#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	for (i = 0; i < 10 && i != 5; i++)
		printf("%d", i);
	return 0;
}
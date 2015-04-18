#include <stdio.h>
int main()
{
	int c;
	long nc,nl,nb;
	nc = 0;
	nl = 0;
	nb = 0;
	for (nc = 0; (c = getchar()) != EOF; nc++)
	{
		if (c == '\n')
			nl++;
		if (c == ' ')
			nb++;
	}
	printf("%ld\n%ld\n%ld\n",nc,nl,nb);
	return 0;
}


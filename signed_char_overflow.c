#include <stdio.h>
#include <string.h>
int main()
{
	char a[1000];
	int i; 
	for (i = 0; i < 1000; i++)
	{
		a[i] = -1 - i;
	}
	printf("%lu\n", strlen(a));
	double f = 10000000000.00 + 0.00000000001;
	printf("%f\n",f); 
	return 0;
}


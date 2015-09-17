#include <stdio.h>
void fun(int b[100]);

int main()
{
	int *p = NULL;
	printf("sizeof(p) = %lu\n", sizeof(p));
	printf("sizeof(*p) = %lu\n", sizeof(*p));

	int a[100];
	printf("sizeof(a) = %lu\n", sizeof(a));
	printf("sizeof(a[100]) = %lu\n", sizeof(a[100]));
	
	printf("sizeof(&a) = %lu\n", sizeof(&a));
	printf("sizeof(&a[0]) = %lu\n", sizeof(&a[0]));

	int b[100];
	fun(b);
	return 0;
}

void fun(int b[100])
{
	printf("sizeof(b) = %lu\n", sizeof(b));
}



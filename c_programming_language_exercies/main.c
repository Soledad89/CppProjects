#include <stdio.h>
#include "utilities.h"

int main()
{
	char c = 'w';
	char s[] = "wangbobobobobob bobobob";
	squeese(s, c);
	printf("the string of s : %s\n", s);

	return 0;
}


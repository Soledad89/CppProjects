#include <stdio.h>
#include "utilities.h"

int main()
{
	char c = 'w';
	char s[] = "wangbo";
//	squeese(s, c);
//	printf("the squeesed string of s : %s\n", s);
	
	char t[] = "zhangrujing";
	my_strcat(s,t);
	printf("the strcated string of s: %s\n", s);

	int a;
	a = -1;
	printf(" 1s: %d\n", bitcount(a));

	return 0;
}


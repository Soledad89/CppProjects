#include <stdio.h>
#include "utilities.h"
#define MAXSIZE 30

int main(int argc, char * argv[])
{
	double cint = my_atof(argv[1]);
	printf("%f\n", cint);
		
	//squeese(s, c);
	//printf("the squeesed string of s : %s\n", s);	/* to test something */
	/* something that test */	
	//char t[] = "zhangrujing";
	//my_strcat(s,t);
	//printf("the strcated string of s: %s\n", s);

	//int a;
	//a = -1;
	//printf(" 1s: %d\n", bitcount(a));
	/*	
	int num[] = {1,2,3,4,5,7,9,10,13,17};
	int b = 5;
	int index;
	int n = (sizeof num)/(sizeof (int));
	printf("%d\n", n);
	index = binsearch_1(b, num, 10);
	printf("the index of searched number is : %d\n", index);
*/
	return 0;
}

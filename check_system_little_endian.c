#include <stdio.h>
int checkSystem()
{
	union check 
	{
		int i;
		char ch;
	} c; 
	c.i = 1;
	return (c.ch == 1);
}


int main()
{
	int a = checkSystem();
	printf("a:%d \n", a);

}


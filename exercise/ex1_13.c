#include <stdio.h>
#define IN  1
#define OUT 0
#define MAXWORD 15

int main()
{
	int c, state, nw, nc;
	int ovflow;						// Number of overflow numbers //
	int w[MAXWORD];					// Word len couter //
	for(int i = 0; i < MAXWORD; i++)
		w[i] = 0;
	state = OUT;
	nw = nc = ovflow = 0;

	while((c = getchar()) != EOF)
	{
		if( c == ' ' || c == '\n' || c == '\t')
		{
			if ( nc > 0)
			{
				if (nc < MAXWORD)
				{
					nw++;
					w[nc]++;
				}
				else
					ovflow++;
			}
			state = OUT;
			nc = 0;
		}else if ( state == IN)
			nc++;
		else
		{
			state = IN;
			nc = 1;
		}
	}

	int maxvalue = 0;
	for (int i = 0; i < MAXWORD; i++)
		if ( w[i] > maxvalue)
			maxvalue = w[i];

	printf("number of words: %d\nmax num of wordlen: %d\noverflow number: %d\n", nw, maxvalue, ovflow);
	return 0;
}


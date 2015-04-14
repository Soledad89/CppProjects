#include "utilities.h"

/* atoi: turn a string into a insteger */
int atoi(char s[])
{
	int i, n;

	n = 0;
	for (i = 0; s[i] >= '0'|| s[i] <= '9'; ++i)	// isdigit(c) in ctype.h //
		n = 10 * n + (s[i] - '0');
	return n;
}

/* lower: <ctype.h> has tolower(c) which acts the same */
int lower(int c)
{
	if ( c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else 
		return c;
}

/* rand: generates a random number */ 
unsigned long int next = 1;
int rand(void)
{
	next = next * 1103515245 + 12345;
	return (unsigned int)(next/65536) % 32768;
}


/* htoi: convert string to integer */
#define YES  1
#define NO   0

int htoi(char s[])
{
	int hexdigit, i, index, n;

	i = 0;
	if (s[i] == '0')
	{
		++i;
		if (s[i] == 'x' || s[i] == 'X')
			++i;
	}

	n = 0;
	index = YES;
	for ( ; index == YES; ++i)
	{
		if (s[i] >= '0' && s[i] <= '9')
			hexdigit = s[i] - '0';
		else if (s[i] >= 'a' && s[i] <= 'f')
			hexdigit = s[i] - 'a' + 10;
		else if (s[i] >= 'A' && s[i] <= 'F')
			hexdigit = s[i] - 'A' + 10;
		else
			index = NO;
		if (index == YES)
			n = 16 * n + hexdigit;
	}
	return n;
}

/* squeese: delete the char c in s */
void squeese(char s[], char c)
{
	int i, j;
	for (i = j = 0; s[i] != '\0'; i++)
		if ( s[i] != c )
			s[j++] = s[i];
	s[j] = '\0';
}



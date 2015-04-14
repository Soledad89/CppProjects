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
	return c >= 'A' && c <= 'F' ? c - 'A' + 'a' : c;
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

/* squeese: delete the string c in s */
void squeese(char s[], char c[])
{
	int i, j, k;

	for ( i = k = 0; s[i] != '\0'; i++)
	{
		for ( j = 0; c[j] != '\0' && s[i] != c[j]; j++)
			;
		if ( c[j] == '\0')
			s[k++] = s[i];
	}
	s[k] = '\0';
	
}

/* any: */
int any(char s1[], char s2[])
{
	return 0;

}

/* strcat: strcat the string t to the string s */
void my_strcat(char s[], char t[])
{
	int i, j;
	i = j = 0;
	while ( s[i] != '\0')
		i ++;						// goes to the end of the string s //
	while ((s[i++] = t[j++]) != '\0')
		;
}

/* getbits: get the unsigned x's bits from p to n */
unsigned getbits( unsigned x, int p, int n)
{
	return (x >> (p+1-n) & ~(~0 << n));
}

/* bitcount: cout the 1s of the integer x */
int bitcount(unsigned x)
{
	int b = 0;
	for (; x != 0; x >>= 1)
		if (x & 01)
			b ++;
	return b;
}



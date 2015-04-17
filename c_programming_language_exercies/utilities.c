#include "utilities.h"

/* trim: */

/* atof: */
double my_atof(char s[])
{
	double val, power;
	int i, sign;

	for ( i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-' ? -1 : 1);
	if ( s[i] == '-' || s[i] == '+')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if ( s[i] == '.')
		i++;
	for ( power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	return sign * val / power;
}


/* itob(int n, char s[], int b */
void itob(int n, char s[], int b)
{
	int i, j, sign;
	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do{	
		j = n % b;
		s[i++] = (j <= 9)? j + '0' : j + 'a' - 10;
	}while ((n /= b) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}


/* reverse: reverse a string */
void reverse(char s[])
{
	int c, i, j;
	for( i = 0, j = strlen(s)-1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

/* itoa: convert a interger to a string */
/* when the maxmin negtive number enters it craches */
void itoa(int n , char s[])
{
	int i, sign;

	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		s[i++] = n%10 + '0';
	}while((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

/* itoa2: convert a interger into a string */
#define abs(x) ((x) < 0 ? -(x) : (x))
void itoa2(int n, char s[])
{
	int i, sign;
	sign = n;
	i = 0;
	do{
		s[i++] = abs(n % 10) + '0';
	}while((n /= 10) != 0);

	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

/* atoi: turn a string into a insteger */
int atoi(char s[])
{
	int i, n;

	n = 0;
	for (i = 0; s[i] >= '0'|| s[i] <= '9'; ++i)	// isdigit(c) in ctype.h //
		n = 10 * n + (s[i] - '0');
	return n;
}

/* atoi2: turn a string into a integer, has + or -  */
int atoi2(char s[])
{
	int i, n, sign;

	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (; isspace(s[i]); i++)
		;
	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');
	return sign * n;
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

/* binsearch: search x in a ordered list */
int binsearch_1(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while ( low <= high)
	{
		mid = (low + high)/2;
		if ( x < v[mid])
			high = mid - 1;
		else if ( x > v[mid])
			low = mid + 1;
		else 
			return mid;
	}

	return -1;
}


/* binsearch: search x in a ordered list */
/* no effiency improved actually */
int binsearch_2(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	mid = (low + high)/2;
	while ( low <= high && x != v[mid])
	{
		if ( x < v[mid])
			high = mid - 1;
		else 
			low = mid + 1;
	}
	if ( x == v[mid])
		return mid;
	else
		return -1;
}



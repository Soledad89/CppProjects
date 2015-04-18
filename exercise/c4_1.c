#include <stdio.h>
#define MAXLINE 1000

int my_getline( char line[], int max);
int strindex( char source[], char searchfor[]);

int main(int argc, char *argv[])
{
	char *pattern;
	pattern = argv[1];
	char line[MAXLINE];
	int found = 0;

	while (my_getline(line, MAXLINE) > 0)
		if (strindex(line, pattern) >= 0)
		{
			printf("%s\n",line);
			found++;
		}
	return found;
}

/* my_getline: store a line in char[], return ints length */
int my_getline(char s[], int lim)
{
	int c, i;

	i = 0;
	while(--lim > 0 && (c=getchar()) != EOF &&c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

/* strindex: return the position in s of t */
int strindex(char s[], char t[])
{
	int i,j,k;
	for (i = 0; s[i] != '\0'; i++)
	{
		for (j=i, k=0; t[k] != '\0' && s[j]  == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}



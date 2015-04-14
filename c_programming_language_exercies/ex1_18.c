#include <stdio.h>
#define MAXLINE 1000

int mygetline(char line[], int maxline);
int myremove(char str[]);

/* print the longest line imputted */ 
int main()
{
	char line[MAXLINE];			// the current line //

	while (mygetline(line, MAXLINE) > 0)
		if (myremove(line) > 0)
		{
			printf("%s\n",line);
		}
	return 0;
}

/* mygetline function: write a line into line[] and return its length */
int mygetline(char s[], int lim)
{
	int c, i;
	for (i = 0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if ( c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* myremove: myremove trailing blanks and tabs from the current line */
int myremove(char s[])
{
	int i;
	
	i = 0;
	while (s[i] != '\n')						// find the newline character //
		++i;
	--i;										// back off from '\n' //
	while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
		--i;
	
	if (i > 0)
	{
		s[++i] = '\n';
		s[++i] = '\0';
	}

	return i;
}




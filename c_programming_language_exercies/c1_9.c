#include <stdio.h>
#define MAXLINE 1000

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest line imputted */ 
int main()
{
	int len;					// the current len of line //
	int max;					// the longest line right now //
	char line[MAXLINE];			// the current line //
	char longest[MAXLINE];		// store the longest line //

	max = 0;
	while ((len = mygetline(line, MAXLINE)) > 0)
		if (len > max)
		{
			max = len;
			copy(longest, line);
		}
	if (max > 0)
		printf("%s", longest);
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

/* copy function: suppose to[] is surfficient large */ 
void copy(char to[], char from[])
{
	int i;
	i = 0;
	while((to[i] = from[i]) != '\0')
		i++;
}


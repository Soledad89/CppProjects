#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000
#define ALLOCSIZE 10000
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp - n;
    }
    else
        return 0;
}

void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}


int my_getline(char *line, int max)
{
    int c, i;
    
    char *t = line;
    for ( i = 0; i < max-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        *line++ = c;

    if ( c == '\n')
    {
        *line++ = c;
        ++i;
    }
    *line = '\0';
    return line - t;
}


int readlines(char *lineptr[], int maxlines)
{
    int len , nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = my_getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else
        {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines ++] = p;
        }
    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i ++)
        printf("%s\n", lineptr[i]);
}



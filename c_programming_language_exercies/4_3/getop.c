#include <ctype.h>
#include <stdio.h>
#include "calculator.h"

int getop(char s[])
{
    int i, c;
    while ((s[0]  = c = my_getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = my_getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = my_getch()))
            ;
    s[i] = '\0';
    if ( c != EOF)
        my_ungetch(c);
    return NUMBER;
}



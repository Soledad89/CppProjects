#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int my_getch(void);
void my_ungetch(int c);

int getword(char *word, int lim)
{
    int c;
    char *w = word;

    while (isspace(c = my_getch()))
        ;
    if ( c != EOF)
        *w++ = c;
    if (!isalpha(c))
    {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = my_getch()))
        {
            my_ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}



#include <stdio.h>

#define BUFFERSIZ 100

static char buf[BUFFERSIZ];
static int bufp = 0;

int my_getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void my_ungetch(int c)
{
    if (bufp >= BUFFERSIZ)
        printf("ungetch: too many characters \n");
    else
        buf[bufp++] = c;
}



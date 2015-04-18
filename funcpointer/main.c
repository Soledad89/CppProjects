#include <stdio.h>
#include <string.h>
#include "funcpointer.h"

#define MAXLINES 5000
char *lineptr[MAXLINES];

int main(int argc, char * argv[])
{
    int nlines;
    int numeric = 0;

    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        my_qsort((void *) lineptr, 0, nlines - 1,
                (int (*)(void *, void *))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("imput too big to sort\n");
        return 1;
    }

}



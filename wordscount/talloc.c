#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "wordscount.h"

struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *my_strdup(char *s)
{
    char *p;

    p = (char *) malloc (strlen(s) + 1);
    if ( p != NULL)
        strcpy(p, s);
    return p;
}



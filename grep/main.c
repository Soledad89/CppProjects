#include <stdio.h>
#include <string.h>
#define MAXLINE 1000
int my_getline(char *line, int max);

int main(int argc, char * argv[])
{
    char line[MAXLINE];
    int found = 0;

    if (argc != 2)
        printf("Usage: find pattern\n");
    else
        while ( my_getline(line, MAXLINE) > 0)
            if (strstr(line, argv[1]) != NULL)
            {
                printf("%s", line);
                found++;
            }
    return found;
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



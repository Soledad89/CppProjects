
int readlines(char *lineptr[], int nlines);

void writelines(char *lineptr[], int nlines);

void my_qsort(void *lineptr[], int left, int right, 
        int (*comp)(void *, void *));

int numcmp(char *, char *);

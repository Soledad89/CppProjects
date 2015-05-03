#include <stdio.h>
#include <string.h>
void fun(int *);
void fun3(char *);

int main()
{
    int ar[] = {1,2,3,4};
    printf("int original: sizeof %d\n", sizeof(ar)/ sizeof(int));
    fun(ar);
    
    char ir[] = "wangbobo";
    printf("char original: sizeof %d\n", sizeof(ir)/sizeof(char));
    fun3(ir);

    return 0;
}

void fun(int pi[4])
{
    int i, n;
    n = sizeof(pi) / sizeof(int); /* always 1 */
    printf("int passed: sizeof %d\n",n);
    
    int m;
    m = 4;
    for (i = 0; i < m; i++)
    {
        pi[i] = 0;
    }
}

void fun2(int pi[], int n) /* so n dedicates how many intergers will be done */
{}

void fun3( char * s)
{
    int i, n;
    n = strlen(s) / sizeof(char);
    printf("char passed: sizeof %d\n", n);

    while( *s != '\0')
        printf("%c\n", *s++);

}


    

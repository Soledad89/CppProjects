#include <stdio.h>

int main()
{
    char *p;
    p = NULL;
    printf("Location 0 contains %d\n", *p);
    /* core dump: 访问内存失败*/
    return 0;
}

#include <stdio.h>
int main()
{
    int *p1 = NULL;
    char *p2 = NULL;

    printf("%p %p\n", p1, p2);

    p1++;
    p2++;

    printf("%p %p\n", p1, p2);

    return 0;
}
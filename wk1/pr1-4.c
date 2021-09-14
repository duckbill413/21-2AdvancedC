#include <stdio.h>
int main()
{
    int x[3] = {0};
    int mid;
    int *pmid = &mid, *a, *b, *c;

    scanf("%d %d %d", x, x + 1, x + 2);
    a = x;
    b = x + 1;
    c = x + 2;

    if (*a > *b && *a > *c)
    {
        *pmid = (*b > *c) ? *b : *c;
    }
    if (*b > *a && *b > *c)
    {
        *pmid = (*a > *c) ? *a : *c;
    }
    if (*c > *a && *c > *b)
    {
        *pmid = (*a > *b) ? *a : *b;
    }
    printf("%d", *pmid);
    return 0;
}
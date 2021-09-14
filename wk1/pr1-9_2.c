#include <stdio.h>
int fmid(int *);
int main()
{
    int x[3] = {0};
    int mid;
    int *px;

    for (px = x; px < x + 3; px++)
        scanf("%d", px);

    px = x;
    printf("%d", *(px + fmid(x)));

    return 0;
}

int fmid(int *arr)
{
    int *a, *b, *c;
    a = arr;
    b = arr + 1;
    c = arr + 2;

    int mid;
    int *pmid = &mid;

    if (*a >= *b && *a >= *c)
    {
        *pmid = (*b > *c) ? 1 : 2;
    }
    if (*b >= *a && *b >= *c)
    {
        *pmid = (*a > *c) ? 0 : 2;
    }
    if (*c >= *a && *c >= *b)
    {
        *pmid = (*a > *b) ? 0 : 1;
    }
    return *pmid; //중앙값의 위치 반환
}
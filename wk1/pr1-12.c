#include <stdio.h>

void addArray(int *, int *, int *, int);

int main()
{
    int a[20], b[20], re[20];
    int *pa, *pb, *pre;
    int n; //배열의 크기

    scanf("%d", &n);

    for (pa = a; pa < a + n; pa++)
        scanf("%d", pa);
    for (pb = b; pb < b + n; pb++)
        scanf("%d", pb);

    addArray(a, b, re, n);

    for (pre = re; pre < re + n; pre++)
        printf(" %d", *pre);

    return 0;
}

void addArray(int *a, int *b, int *result, int num)
{
    int *end = b;
    for (b = b + num - 1; b >= end; a++, b--, result++)
    {
        *result = *a + *b;
    }
}
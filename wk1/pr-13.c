#include <stdio.h>

int arrsum(int *, int *);

int main()
{
    int n, s, e;
    scanf("%d %d %d", &n, &s, &e);

    int num[100] = {0};
    int *pnum;

    for (pnum = num; pnum < num + n; pnum++)
    {
        scanf("%d", pnum);
    }
    pnum = num;
    printf("%d", arrsum(pnum + s, pnum + e));

    return 0;
}

int arrsum(int *start, int *end)
{
    int sum = 0;
    for (; start <= end; start++)
    {
        sum += *start;
    }
    return sum;
}
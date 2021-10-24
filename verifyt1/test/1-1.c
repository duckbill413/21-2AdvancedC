#include <stdio.h>

int input(int *p);
int *sel_next(int *p);
int number(int *p, int *q);

int main()
{
    int x[100];
    input(x);

    int *before = x;
    while (1)
    {
        int *end = sel_next(before);
        int result = number(before, end);
        printf("%d*\n", result);
        before = end + 1;
        if (*(end + 1) == -1)
            break;
    }

    return 0;
}

int input(int *p)
{
    int cnt = 0;
    while (1)
    {
        scanf("%d", p);
        if (*p == -1)
            break;
        cnt++;
        p++;
    }
    return cnt;
}

int *sel_next(int *p)
{
    int sum = 0;
    int *point = p;
    for (int *pp = p;; pp++)
    {
        if (*pp == -1)
        {
            point = pp - 1;
            break;
        }
        sum += *pp;
        if (sum > 10)
        {
            point = pp - 1;
            break;
        }
    }
    return point;
}

int number(int *p, int *q)
{
    int num = 0;
    for (int *i = p; i <= q; i++)
        num = num * 10 + *i;

    return num;
}
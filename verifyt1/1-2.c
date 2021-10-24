#include <stdio.h>

int input(int *p);
int *sel_next(int *p);
int number(int *p, int *q);

int main()
{
    int x[100];
    int num = input(x);

    int *before = x;
    while (1)
    {
        int *p = sel_next(before);
        int result = number(before, p);

        printf("%d\n", result);
        before = p;
        if (*(p + 1) == -1)
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
    int *pEnd;
    int flag;
    if (*p < *(p + 1))
        flag = 0;
    else if (*p > *(p + 1))
        flag = 1;
    else if (*p == -1)
        return p;

    if (flag == 0)
    {
        for (int *pp = p;; pp++)
        {
            if (*pp >= *(pp + 1))
            {
                pEnd = pp;
                break;
            }
        }
    }
    if (flag == 1)
    {
        for (int *pp = p;; pp++)
        {
            if (*pp == -1)
            {
                pEnd = pp - 1;
                break;
            }
            if (*pp <= *(pp + 1))
            {
                pEnd = pp;
                break;
            }
        }
    }

    return pEnd;
}

int number(int *p, int *q)
{
    int num = 0;
    for (int *pp = p; pp <= q; pp++)
    {
        num = num * 10 + *pp;
    }
    return num;
}
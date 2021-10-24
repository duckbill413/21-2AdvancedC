#include <stdio.h>

int input(int *p);
int *sel_next(int *p, int N, int M);
int number(int *p, int *q);

int main()
{
    int x[100];
    int num = input(x);
    int M;
    scanf("%d", &M);

    int result = number(&x[M], sel_next(x, num, M));
    printf("%d", result);
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

int *sel_next(int *p, int N, int M)
{
    int *pEnd;
    for (int *pp = p + M; pp < p + N; pp++)
    {
        if (*pp + 1 != *(pp + 1))
        {
            pEnd = pp;
            break;
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
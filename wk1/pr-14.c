#include <stdio.h>

int add_to_k(int *, int *);

int main()
{
    int n;
    int d[100] = {0};

    scanf("%d", &n);
    int *pd;
    for (pd = d; pd < d + n; pd++)
    {
        scanf("%d", pd);
    }

    int sum = 0;

    for (int *end = d; end < d + n; end++)
    {
        sum += add_to_k(d, end);
    }

    printf("%d", sum);
    return 0;
}

int add_to_k(int *start, int *end)
{
    int sum = 0;
    for (; start <= end; start++)
    {
        sum += *start;
    }
    return sum;
}
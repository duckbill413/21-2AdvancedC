#include <stdio.h>

void ABC(int *, int);

int main()
{
    int array[10] = {0};
    int *parray;

    for (parray = array; parray < array + 10; parray++)
        scanf("%d", parray);

    for (parray = array; parray < array + 9; parray++)
    {
        ABC(parray, 10 - (parray - array));
    }

    for (parray = array; parray < array + 10; parray++)
        printf("%d ", *parray);

    return 0;
}

void ABC(int *start, int k)
{
    int *big = start;
    int *p_start;
    for (p_start = start; p_start < start + k; p_start++)
    {
        if (*big < *p_start)
            big = p_start;
    }

    int tmp = *big;
    *big = *start;
    *start = tmp;
}
#include <stdio.h>

int main()
{
    int arr[5];
    int rank[5] = {0};

    int *p, *q, *r;
    for (p = arr; p < arr + 5; p++)
        scanf("%d", p);

    r = rank;

    for (p = arr; p < arr + 5; p++)
    {
        for (q = arr; q < arr + 5; q++)
        {
            if (*p < *q)
                (*r)++;
        }
        r++;
    }

    for (p = arr, r = rank; r < rank + 5; p++, r++)
        printf("%d=r%d ", *p, *r + 1);

    return 0;
}
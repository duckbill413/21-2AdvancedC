#include <stdio.h>

void swap(int *, int *);

int main()
{
    int N;
    int arr[50] = {0};
    int *parr;

    scanf("%d", &N);
    for (parr = arr; parr < arr + N; parr++)
        scanf("%d", parr);

    int a, b;
    scanf("%d %d", &a, &b);

    parr = arr;
    swap((parr + a), (parr + b));

    for (parr = arr; parr < arr + N; parr++)
        printf(" %d", *parr);

    return 0;
}

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
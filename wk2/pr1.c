#include <stdio.h>
void input(int *, int);
int *diff(int *, int);

int main()
{
    int n;
    int arr[100];
    scanf("%d", &n);
    input(arr, n);

    int *max = diff(arr, n);

    printf("%d %d", *(max - 1), *max);
    return 0;
}

void input(int *arr, int n)
{
    for (int *p = arr; p < arr + n; p++)
        scanf("%d", p);
}

int *diff(int *arr, int n)
{
    int max = 0;
    int *pmax;
    int abs;
    for (int *p = arr + 1; p < arr + n; p++)
    {
        abs = *(p - 1) - *p;
        if (abs < 0)
            abs = (-1) * abs;

        if (abs > max)
        {
            max = abs;
            pmax = p;
        }
    }
    return pmax;
}
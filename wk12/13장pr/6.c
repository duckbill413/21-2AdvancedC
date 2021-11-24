#include <stdio.h>

void ABC(int (*p)[20], int k1, int k2);

int main()
{
    int n;
    scanf("%d", &n);

    int arr[20][20] = {0};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ABC(arr, i, j);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf(" %d", arr[i][j]);
        printf("\n");
    }
}

void ABC(int (*p)[20], int k1, int k2)
{
    (*(p + k1))[k2] = k1 + k2;
}
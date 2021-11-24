#include <stdio.h>

void pswap(int **ppx, int **ppy);

int main()
{
    int x, y;
    int *px = &x, *py = &y;
    scanf("%d %d", px, py);
    pswap(&px, &py);

    printf("%d %d", *px, *py);
}

void pswap(int **ppx, int **ppy)
{
    int *tmp = *ppx;
    *ppx = *ppy;
    *ppy = tmp;
}
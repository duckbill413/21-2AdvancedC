#include <stdio.h>

int main()
{
    int N = 10;
    double K = 0.6;
    printf("%d\n", (int)(N * 0.6));
    printf("%.100lf\n", N * 0.6);

    printf("%d", (int)(10 * 0.6));
}
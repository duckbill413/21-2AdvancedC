#include <stdio.h>

int factorial(int);

int main()
{
    int num;
    scanf("%d", &num);

    double result = 0.0;
    for (int i = 0; i <= num; i++)
    {
        if (i == 0)
        {
            result += 1;
            continue;
        }
        result += 1 / (double)factorial(i);
    }
    printf("%.6lf", result);
}

int factorial(int n)
{
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}
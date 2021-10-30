#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int *num1 = NULL;
    num1 = (int *)malloc(sizeof(int) * n);
    if (num1 == NULL)
        return -1;
    int *num2 = NULL;
    num2 = (int *)malloc(sizeof(int) * (n - 1));
    if (num2 == NULL)
        return -1;

    for (int *p = num1; p < num1 + n; p++)
    {
        *p = p - num1;
    }

    int *q = num2;
    for (int *p = num1; p < num1 + n; p++)
    {
        if (p != num1 + n / 2)
        {
            *q = *p;
            q++;
        }
    }

    for (int *p = num2; p < num2 + n - 1; p++)
        printf(" %d", *p);

    free(num1);
    free(num2);
    return 0;
}
#include <stdio.h>

int recursive(int, int);

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    int result = recursive(a, b);
    printf("%d", result);
    return 0;
}

int recursive(int a, int b)
{
    int r = a % b;
    if (r == 0)
        return b;
    else
        return recursive(b, r);
}
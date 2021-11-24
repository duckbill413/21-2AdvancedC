#include <stdio.h>

int add(int, int);
int sub(int, int);
int multiply(int, int);

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);

    int (*handle[3])(int, int) = {add, sub, multiply};

    printf("%d %d %d", handle[0](x, y), handle[1](x, y), handle[2](x, y));
}

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
#include <stdio.h>
int add(int, int);
int main()
{
    int A;
    scanf("%d", &A);
    void *p = &A;
    printf("%d\n", *(int *)p);
    int x, y;
    scanf("%d %d", &x, &y);
    int (*fp)(int x, int y) = add;
    int result = fp(x, y);
    printf("%d", result);
}

int add(int a, int b) { return a + b; }
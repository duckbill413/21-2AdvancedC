#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *num = (int *)malloc(sizeof(int) * n);
    int *p;
    for (p = num; p < num + n; p++)
        scanf("%d", p);

    

    return 0;
}
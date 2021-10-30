#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d", &n);
    int *num = NULL;
    num = (int *)malloc(sizeof(int) * n);
    if (num == NULL)
        return -1;

    for (int *pnum = num; pnum < num + n; pnum++)
        scanf("%d", pnum);

    int sum = 0;
    for (int *pnum = num; pnum < num + n; pnum++)
        sum += *pnum;

    printf("%d", sum);
    free(num);
    return 0;
}
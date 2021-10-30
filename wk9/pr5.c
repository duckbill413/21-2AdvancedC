#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *num = NULL;
    num = (int *)malloc(sizeof(int) * n);
    if(num==NULL) return -1;
    for (int *p = num; p < num + n; p++)
        scanf("%d", p);

    for (int *p = num; p < num + n - 1; p++)
        if (*p > *(p + 1))
        {
            int tmp = *p;
            *p = *(p + 1);
            *(p + 1) = tmp;
        }

    for (int *p = num; p < num + n; p++)
        printf("%d\n", *p);

    free(num);
    return 0;
}
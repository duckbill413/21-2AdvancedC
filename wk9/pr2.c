#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    float *num = NULL;
    num = (float *)malloc(sizeof(float) * n);
    if (num == NULL)
        return -1;

    for (float *pnum = num; pnum < num + n; pnum++)
        scanf("%f", pnum);

    float max = *num;
    for (float *p = num; p < num + n; p++)
    {
        if (max < *p)
            max = *p;
    }
    printf("%.2f", max);
    free(num);
    return 0;
}
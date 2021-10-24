#include <stdio.h>
#include <stdlib.h>

int *center(int *p, int N);

int main()
{
    int n;
    scanf("%d", &n);

    int *num = (int *)malloc(sizeof(int) * n);

    for (int *p = num; p < num + n; p++)
        scanf("%d", p);

    int *close = center(num, n);

    printf("%d\n", *close);
    printf("%d", close - num);

    free(num);
    return 0;
}

int *center(int *p, int N)
{
    double avg = 0.0;
    for (int *pp = p; pp < p + N; pp++)
        avg += *pp;
    avg /= N;
    printf("%.1lf\n", avg);

    double far_diff = avg - *p;
    if(far_diff<0) far_diff*=(-1);
    
    int *far = p;
    double diff;
    for (int *pp = p; pp < p + N; pp++)
    {
        diff = *pp - avg;
        if (diff < 0)
            diff *= (-1);

        if (far_diff > diff)
        {
            far = pp;
            far_diff = diff;
        }
    }

    return far;
}
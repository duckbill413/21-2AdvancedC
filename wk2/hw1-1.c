#include <stdio.h>

int *MAX(int *);
int *MIN(int *);

int main()
{
    int n;
    scanf("%d", &n);
    int *par;
    for (int i = 0; i < n; i++)
    {
        int ar[100] = {0};
        for (par = ar; par < ar + 100; par++)
        {
            scanf("%d", par);
            if (*par == 0)
                break;
        }
        printf("%d %d\n", *MAX(ar), *MIN(ar));
    }
    return 0;
}

int *MAX(int *ar)
{
    int *par;
    int max;
    int *pmax;
    for (par = ar; par < ar + 100; par++)
    {
        if (*par == 0)
            break;
        if (max < *par || par == ar)
        {
            max = *par;
            pmax = par;
        }
    }
    return pmax;
}

int *MIN(int *ar)
{
    int *par;
    int min;
    int *pmin;
    for (par = ar; par < ar + 100; par++)
    {
        if (*par == 0)
            break;
        if (min > *par || par == ar)
        {
            min = *par;
            pmin = par;
        }
    }
    return pmin;
}
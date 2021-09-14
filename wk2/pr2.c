#include <stdio.h>
void sort(int, int *, double *);

int main()
{
    int n;
    int arr1[100], arr2[100], arr3[100];
    double avg[100];

    scanf("%d", &n);
    int *parr[3];
    for (parr[0] = arr1, parr[1] = arr2, parr[2] = arr3; parr[0] < arr1 + n; parr[0]++, parr[1]++, parr[2]++)
        scanf("%d %d %d", parr[0], parr[1], parr[2]);

    double *pavg;
    parr[0] = arr1, parr[1] = arr2, parr[2] = arr3;

    for (pavg = avg; pavg < avg + n; pavg++, parr[1]++, parr[2]++)
    {
        *pavg = (*parr[1] + *parr[2]) / 2;
    }
    sort(n, arr1, avg);

    for (parr[0] = arr1, pavg = avg; pavg < avg + n; parr[0]++, pavg++)
        printf("%d %.1lf\n", *parr[0], *pavg);

    return 0;
}
void sort(int n, int *id, double *avg)
{
    int *p = id, *q;
    for (double *i = avg; i < avg + n; i++)
    {
        q = id;
        for (double *j = avg; j < avg + n; j++)
        {
            if (*j < *(j + 1))
            {
                double atmp = *(j + 1);
                *(j + 1) = *j;
                *j = atmp;

                int dtmp = *(q + 1);
                *(q + 1) = *q;
                *q = dtmp;
            }
            q++;
        }
        p++;
    }
}
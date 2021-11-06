#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct car
{
    char num[5];
    int hour, min, payment;
} Car;

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    Car *pe = NULL;
    pe = (Car *)malloc(sizeof(Car) * n);
    if (pe == NULL)
        return -1;

    for (Car *p = pe; p < pe + n; p++)
    {
        int time;
        scanf("%s %d", p->num, &time);
        p->hour = time / 100;
        p->min = time % 100;
    }

    for (Car *p = pe; p < pe + n; p++)
    {
        for (Car *q = p + 1; q < pe + n; q++)
        {
            if (!strcmp(p->num, q->num))
            {
                int min = (q->hour - p->hour) * 60 + (q->min - p->min);
                p->payment = min * 100;
                printf("%s %d\n", p->num, p->payment);
            }
        }
    }
    free(pe);
    return 0;
}

/*
5
1234 1030
9000 1040
0800 1045
1234 1130
9000 1150
*/
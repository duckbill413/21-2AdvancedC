#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point
{
    int x, y;
} Point;

double distance(Point *, Point *);

int main()
{
    int n;
    scanf("%d", &n);

    Point *pt = (Point *)(malloc(n * sizeof(Point)));

    for (int i = 0; i < n; i++)
        scanf("%d %d", &(pt + i)->x, &(pt + i)->y);

    double far_distance = 0.0;
    Point *a, *b;
    for (Point *p = pt; p < pt + n; p++)
    {
        for (Point *q = p + 1; q < pt + n; q++)
        {
            if (far_distance < distance(p, q))
            {
                a = p;
                b = q;
                far_distance = distance(p, q);
            }
        }
    }
    printf("%d %d\n", a->x, a->y);
    printf("%d %d", b->x, b->y);

    free(pt);

    return 0;
}

double distance(Point *a, Point *b)
{
    return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
}
#include <stdio.h>
#include <stdlib.h>

typedef struct point
{
    double x, y;
} Point;

Point center(Point a, Point b);

int main()
{
    Point a, b;
    scanf("%lf %lf", &a.x, &a.y);
    scanf("%lf %lf", &b.x, &b.y);
    Point result = center(a, b);
    printf("%.2lf %.2lf", result.x, result.y);
    return 0;
}

Point center(Point a, Point b)
{
    Point re;
    re.x = (a.x + b.x) / 2;
    re.y = (a.y + b.y) / 2;
    return re;
}
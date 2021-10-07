#include <stdio.h>
#include <string.h>

typedef struct date
{
    int year, month, day;
} Date;

Date *select_min(Date *, Date *);

int main()
{
    Date a, b;

    scanf("%d/%d/%d", &a.year, &a.month, &a.day);
    scanf("%d/%d/%d", &b.year, &b.month, &b.day);

    Date *result = select_min(&a, &b);
    printf("%d/%d/%d", result->year, result->month, result->day);
    return 0;
}

Date *select_min(Date *a, Date *b)
{
    if (a->year < b->year)
        return a;
    else if (a->year > b->year)
        return b;
    else if (a->month < b->month)
        return a;
    else if (a->month > b->month)
        return b;
    else if (a->day < b->day)
        return a;
    else if (a->day > b->day)
        return b;
}
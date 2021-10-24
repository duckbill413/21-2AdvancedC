#include <stdio.h>

typedef struct person
{
    char name[11];
    int year;
    int month;
    int day;
    int t1, t2;
    double score;
} Person;

void swap(struct person *p, struct person *q);

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    getchar();

    Person pr[100];
    for (Person *p = pr; p < pr + n; p++)
    {
        scanf("%s %d-%d-%d %d %d", p->name, &p->year, &p->month, &p->day, &p->t1, &p->t2);
        getchar();
        p->score = 0.8 * p->t1 + 0.2 * p->t2;
    }

    for (Person *p = pr; p < pr + n; p++)
    {
        for (Person *q = p + 1; q < pr + n; q++)
        {
            if (p->score < q->score)
            {
                swap(p, q);
            }
            else if (p->score == q->score && p->t1 < q->t1)
            {
                swap(p, q);
            }
            else if (p->score == q->score && p->t1 == q->t1)
            {
                if (p->year < q->year)
                {
                    swap(p, q);
                }
                else if (p->year == q->year && p->month < q->month)
                    swap(p, q);
                else if (p->year == q->year && p->month == q->month && p->day < q->day)
                    swap(p, q);
            }
        }
    }

    for (Person *p = pr; p < pr + m; p++)
        printf("%s %.1lf\n", p->name, p->score);

    return 0;
}

void swap(struct person *p, struct person *q)
{
    Person tmp = *p;
    *p = *q;
    *q = tmp;
}
/*
7 3
Aaaaa 75 85
Bbbbb 86 77
Ccccc 94 82
Ddddd 78 70
Eeeee 65 85
Fffff 83 90
Ggggg 90 70
*/
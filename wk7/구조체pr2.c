#include <stdio.h>

typedef struct student
{
    int id;
    int t1, t2, t3;
    double avg;
} Student;

void average(Student *);

int main()
{
    Student st[10];
    int n;
    scanf("%d", &n);

    for (Student *pst = st; pst < st + n; pst++)
    {
        scanf("%d %d %d %d", &pst->id, &pst->t1, &pst->t2, &pst->t3);
        average(pst);
    }

    for (Student *i = st; i < st + n - 1; i++)
    {
        for (Student *j = st; j < st + n - (i - st) - 1; j++)
        {
            if (j->id > (j + 1)->id)
            {
                Student tmp = *j;
                *j = *(j + 1);
                *(j + 1) = tmp;
            }
        }
    }
    for (Student *pst = st; pst < st + n; pst++)
        printf("%04d %.1lf\n", pst->id, pst->avg);

    return 0;
}

void average(Student *f)
{
    f->avg = (f->t1 + f->t2 + f->t3) / 3.0;
}
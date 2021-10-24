#include <stdio.h>

typedef struct student
{
    char name[21];
    int kor, eng, math;
    double avg;
} Student;

void read_data(Student *st, int N);
void sort_score(Student *st, int N);
Student *select_out(Student *st1, Student *st2, int N);

int main()
{
    Student st1[50];
    Student st2[50];

    int n;
    scanf("%d", &n);
    getchar();

    read_data(st1, n);
    read_data(st2, n);

    sort_score(st1, n);
    sort_score(st2, n);

    Student *select = select_out(st1, st2, n);

    for (Student *p = select; p < select + n; p++)
    {
        printf("%s %d %d %d %.1lf\n", p->name, p->kor, p->eng, p->math, p->avg);
    }
}

void read_data(Student *st, int N)
{
    for (Student *p = st; p < st + N; p++)
    {
        scanf("%s %d %d %d", p->name, &p->kor, &p->eng, &p->math);
        getchar();
        p->avg = (p->kor + p->eng + p->math) / 3.0;
    }
}

void sort_score(Student *st, int N)
{
    for (Student *p = st; p < st + N; p++)
    {
        for (Student *q = p + 1; q < st + N; q++)
        {
            if (p->avg < q->avg)
            {
                Student tmp = *q;
                *q = *p;
                *p = tmp;
            }
            else if (p->avg == q->avg)
            {
                if (p->kor < q->kor)
                {
                    Student tmp = *q;
                    *q = *p;
                    *p = tmp;
                }
                else if ((p->kor == q->kor) && (p->eng < q->eng))
                {
                    Student tmp = *q;
                    *q = *p;
                    *p = tmp;
                }
                else if ((p->kor == q->kor) && (p->eng == q->eng) && (p->math < q->math))
                {
                    Student tmp = *q;
                    *q = *p;
                    *p = tmp;
                }
            }
        }
    }
}
Student *select_out(Student *st1, Student *st2, int N)
{
    int mid = N / 2;
    if ((st1 + mid)->avg > (st2 + mid)->avg)
        return st1;
    else
        return st2;
}
/*
5
Kim 100 85 80
Lee 88 94 92
Park 92 100 100
Hong 84 82 85
Nam 80 84 72
Song 100 90 97
Lee 92 82 93
Park 80 84 72
Choi 97 80 90
Chung 100 94 93
*/
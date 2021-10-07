#include <stdio.h>

typedef struct student
{
    char name[10];
    int t1, t2, t3;
    double avg;
} Student;

void read_data(Student *);
void cal_avg(Student *);
void sort(Student *);
void print_score(Student *);

int main()
{
    Student st[10];

    read_data(st);
    cal_avg(st);
    sort(st);
    print_score(st);

    return 0;
}

void read_data(Student *st)
{
    for (int i = 0; i < 10; i++)
    {
        scanf("%s %d %d %d", (st + i)->name, &(st + i)->t1, &(st + i)->t2, &(st + i)->t3);
        getchar();
    }
}

void cal_avg(Student *st)
{
    for (int i = 0; i < 10; i++)
        (st + i)->avg = ((st + i)->t1 + (st + i)->t2 + (st + i)->t3) / 3.0;
}

void sort(Student *st)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9 - i; j++)
        {
            if ((st + j)->avg < (st + j + 1)->avg)
            {
                Student tmp = *(st + j);
                *(st + j) = *(st + j + 1);
                *(st + j + 1) = tmp;
            }
        }
    }
}
void print_score(Student *st)
{
    printf("%s %.2lf\n", st->name, st->avg);
    printf("%s %.2lf\n", (st + 9)->name, (st + 9)->avg);
    for (int i = 7; i <= 9; i++)
        printf("%s %.2lf\n", (st + i)->name, (st + i)->avg);
}
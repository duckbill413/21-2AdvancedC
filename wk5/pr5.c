#include <stdio.h>

struct student
{
    char name[8];
    int test1, test2, test3;
    double avg;
    char score;
};

int main()
{
    struct student st[50];
    int n;
    scanf("%d", &n);
    double avg;
    for (struct student *p = st; p < st + n; p++)
    {
        scanf("%s %d %d %d", p->name, &p->test1, &p->test2, &p->test3);
        avg = (p->test1 + p->test2 + p->test3) / 3.0;
        p->avg = avg;
        if (avg >= 90)
            p->score = 'A';
        else if (avg >= 80)
            p->score = 'B';
        else if (avg >= 70)
            p->score = 'C';
        else
            p->score = 'D';
    }

    for (struct student *p = st; p < st + n; p++)
        printf("%s %.1lf %c\n", p->name, p->avg, p->score);

    return 0;
}
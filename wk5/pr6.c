#include <stdio.h>

typedef struct student
{
    int gender;
    int weight;
    int height;
} Student;

void input(Student *, int);
int score(Student *);

int main()
{
    Student st[10];
    int n;
    int level[3] = {0};

    scanf("%d", &n);
    input(st, n);

    for (Student *p = st; p < st + n; p++)
        level[score(p) - 1]++;

    printf("%d %d %d", level[0], level[1], level[2]);
    return 0;
}
typedef struct inscent
{
    int c_language;
    int fucking;
    int complication;
};
void input(Student *st, int n)
{
    for (Student *p = st; p < st + n; p++)
        scanf("%d %d %d", &p->gender, &p->weight, &p->height);
}

int score(Student *p)
{
    int sd;
    if (p->gender == 1)
        sd = 70;
    else if (p->gender == 2)
        sd = 60;

    if (p->weight >= sd)
        if (p->height >= 175)
            return 1;
        else if (p->height >= 165)
            return 3;
        else
            return 2;
    if (p->weight >= sd - 10)
        if (p->height >= 175)
            return 2;
        else if (p->height >= 165)
            return 1;
        else
            return 3;
    else
    {
        if (p->height >= 175)
            return 3;
        else if (p->height >= 165)
            return 2;
        else
            return 1;
    }
}
#include <stdio.h>
#include <string.h>
typedef struct student
{
    char name[10];
    int t1, t2, t3;
} Student;

typedef struct subject
{
    double koravg, engavg, mathavg;
    char top[10];
} Subject;

struct subject average(struct student *pst, int size);

int main()
{
    int n;
    scanf("%d", &n);

    Student st[10];
    for (Student *pst = st; pst < st + n; pst++)
    {
        getchar();
        scanf("%s %d %d %d", pst->name, &pst->t1, &pst->t2, &pst->t3);
    }

    Subject sub = average(st, n);

    printf("kor=%.1lf\n", sub.koravg);
    printf("eng=%.1lf\n", sub.engavg);
    printf("math=%.1lf\n", sub.mathavg);
    printf("top=%s\n", sub.top);

    return 0;
}

struct subject average(struct student *pst, int size)
{
    int max = 0;
    Subject result;
    result.koravg = 0;
    result.engavg = 0;
    result.mathavg = 0;
    for (Student *p = pst; p < pst + size; p++)
    {
        result.koravg += p->t1;
        result.engavg += p->t2;
        result.mathavg += p->t3;
        int total = p->t1 + p->t2 + p->t3;
        if (p == pst || max < total)
        {
            max = total;
            strcpy(result.top, p->name);
            result.top[strlen(p->name)] = '\0';
        }
    }
    result.koravg /= size;
    result.engavg /= size;
    result.mathavg /= size;
    return result;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    char name[8];
    int t1, t2, t3;
    double avg;
} Student;

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    Student *st = NULL;
    st = (Student *)malloc(sizeof(Student) * n);
    if (st == NULL)
        return -1;
    for (Student *pst = st; pst < st + n; pst++)
    {
        scanf("%s %d %d %d", pst->name, &pst->t1, &pst->t2, &pst->t3);
        pst->avg = (pst->t1 + pst->t2 + pst->t3) / 3.0;
        getchar();
    }

    for (Student *pst = st; pst < st + n; pst++)
    {
        printf("%s %.1lf ", pst->name, pst->avg);
        if (pst->t1 >= 90 || pst->t2 >= 90 || pst->t3 >= 90)
            printf("GREAT ");
        if (pst->t1 < 70 || pst->t2 < 70 || pst->t3 < 70)
            printf("BAD");
        printf("\n");
    }
    free(st);
    return 0;
}
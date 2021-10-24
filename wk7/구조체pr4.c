#include <stdio.h>
#include <string.h>

typedef struct student
{
    char name1[21];
    char name2[21];
    int score;
    int flag;
} Student;

int main()
{
    int num;
    scanf("%d", &num);

    Student st[10];
    for (Student *pst = st; pst < st + num; pst++)
    {
        getchar();
        scanf("%s %s %d", pst->name1, pst->name2, &pst->score);
    }
    getchar();
    char fname[21];
    scanf("%s", fname);

    double avg;
    int cnt = 0;
    for (Student *pst = st; pst < st + num; pst++)
    {
        if (!strcmp(pst->name1, fname) || !strcmp(pst->name2, fname))
        {
            pst->flag = 1;
            avg += pst->score;
            cnt++;
        }
        else
            pst->flag = 0;
    }
    avg /= cnt;

    Student *found;
    double diff = avg;
    double ca;
    for (Student *pst = st; pst < st + num; pst++)
    {
        if (pst->flag == 1)
        {
            if (pst->score > avg)
            {
                ca = pst->score - avg;
            }
            else
                ca = avg - pst->score;
            if (ca <= diff)
            {
                found = pst;
                diff = ca;
            }
        }
    }

    printf("average = %.2lf\n", avg);
    printf("%s %s %d", found->name1, found->name2, found->score);

    return 0;
}

/*
6
gildong hong 70
gildong kim 82
kim jack 65
gill kim 93
elvis kim 94
park lena 89
kim
*/
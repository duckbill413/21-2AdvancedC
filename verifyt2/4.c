#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

typedef struct student
{
    int id;
    int t1, t2;
    double score;
} Student;

int main()
{
    int N;
    scanf("%d", &N);
    Student *st = NULL;
    if ((st = (Student *)malloc(sizeof(Student) * N)) == NULL)
        return -1;

    Student *re = NULL;
    if ((re = (Student *)malloc(sizeof(Student) * N)) == NULL)
        return -1;

    for (Student *pst = st; pst < st + N; pst++)
    {
        scanf("%d %d %d", &pst->id, &pst->t1, &pst->t2);
        pst->score = pst->t1 * 0.4 + pst->t2 * 0.6;
    }

    for (Student *pst = st; pst < st + N - 1; pst++)
    {
        for (Student *qst = st; qst < st + N - (pst - st) - 1; qst++)
        {
            if (qst->score < (qst + 1)->score)
            {
                Student tmp = *qst;
                *qst = *(qst + 1);
                *(qst + 1) = tmp;
            }
        }
    }

    int size = N * 6 / 10;
    Student *pre = re;
    int cnt = 0;
    // printf("size %d\n mid %lf\n", size, st[size-1].score);
    for (Student *pst = st; pst < st + N; pst++)
    {
        if (pst->score >= st[size - 1].score)
        {
            *pre++ = *pst;
            cnt++;
        }
    }

    size = N * 8 / 10;
    if (cnt < size)
    {
        for (Student *pst = st; pst < st + N - 1; pst++)
        {
            for (Student *qst = st; qst < st + N - (pst - st) - 1; qst++)
            {
                if (qst->t2 < (qst + 1)->t2)
                {
                    Student tmp = *qst;
                    *qst = *(qst + 1);
                    *(qst + 1) = tmp;
                }
            }
        }

        // for (Student *pst = st; pst < st + N; pst++)
        //   printf("st: %d %d %d %.2lf\n", pst->id, pst->t1, pst->t2, pst->score);
        for (Student *pst = st; pst < st + N; pst++)
        {
            int found = 0;
            for (Student *pre = re; pre < re + cnt; pre++)
            {
                if (pre->id == pst->id)
                    found = 1;
            }
            if (!found)
            {
                if (pst->t2 >= st[size - 1].t2)
                {
                    *pre++ = *pst;
                    cnt++;
                }
            }
        }
    }
    //ÇÐ¹ø

    for (Student *pre = re; pre < re + cnt - 1; pre++)
    {
        for (Student *qre = re; qre < re + cnt - (pre - re) - 1; qre++)
        {
            if (qre->id > (qre + 1)->id)
            {
                Student tmp = *qre;
                *qre = *(qre + 1);
                *(qre + 1) = tmp;
            }
        }
    }

    for (Student *pre = re; pre < re + cnt; pre++)
        printf("%d\n", pre->id);

    free(st);
    free(re);
    return 0;
}

/*
10
12345 15 86
12346 52 68
12347 55 90
12348 32 88
12349 22 12
12350 65 9
12351 1 100
12352 2 10
12353 50 90
12354 90 100

6
12345 80 100
12121 80 100
12358 80 100
12364 80 100
13548 80 100
13154 80 100

7
11325 78 12
11215 45 65
13125 55 50
11111 12 87
12233 1 100
13158 70 90
14589 67 78
*/
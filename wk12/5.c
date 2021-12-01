#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char *name;
    int kor, eng, math, diff;
} Student;

Student *difference(Student *st, int N);

int main()
{
    int N;
    scanf("%d", &N);
    getchar();

    Student *st = NULL;
    if ((st = (Student *)malloc(sizeof(Student) * N)) == NULL)
        return -1;

    for (Student *pst = st; pst < st + N; pst++)
    {
        char tmp[21] = {0};
        scanf("%s %d %d %d", tmp, &pst->kor, &pst->eng, &pst->math);
        getchar();
        pst->name = NULL;
        if ((pst->name = (char *)malloc(sizeof(char) * (strlen(tmp) + 1))) == NULL)
            return -1;
        strcpy(pst->name, tmp);
    }

    Student *result = difference(st, N);
    printf("%s %d", result->name, result->diff);

    for (Student *pst = st; pst < st + N; pst++)
        free(pst->name);
    free(st);

    return 0;
}

Student *difference(Student *st, int N)
{
    for (Student *pst = st; pst < st + N; pst++)
    {
        int min, max;
        if (pst->kor < pst->eng && pst->kor < pst->math)
            min = pst->kor;
        if (pst->eng < pst->kor && pst->eng < pst->math)
            min = pst->eng;
        if (pst->math < pst->eng && pst->math < pst->kor)
            min = pst->math;
        if (pst->kor > pst->eng && pst->kor > pst->math)
            max = pst->kor;
        if (pst->eng > pst->kor && pst->eng > pst->math)
            max = pst->eng;
        if (pst->math > pst->eng && pst->math > pst->kor)
            max = pst->math;

        pst->diff = max - min;
    }

    Student *pmax = st;
    int max = st->diff;
    for (Student *pst = st; pst < st + N; pst++)
    {
        if (max < pst->diff)
        {
            max = pst->diff;
            pmax = pst;
        }
    }
    return pmax;
}

/*
4
jacob 31 32 41
cathy 41 51 52
park 61 51 41
jane 71 81 31
*/
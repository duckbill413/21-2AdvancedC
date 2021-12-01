#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char name[21];
    int score;
} Student;

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
        scanf("%s %d", pst->name, &pst->score);
        getchar();
    }
    int sA, sB;
    scanf("%d %d", &sA, &sB);
    getchar();
    char nA[21], nB[21];
    scanf("%s %s", nA, nB);
    getchar();

    for (Student *pst = st; pst < st + N; pst++)
    {
        if (pst->score >= sA && pst->score <= sB)
            printf("%s %d\n", pst->name, pst->score);
    }
    printf("*****\n");
    for (Student *pst = st; pst < st + N; pst++)
    {
        if (strcmp(pst->name, nA) > 0 && strcmp(pst->name, nB) < 0)
            printf("%s %d\n", pst->name, pst->score);
    }

    free(st);
    return 0;
}

/*
test case)
5
jacob 31
kim 41
lee 51
park 61
jane 71
60 75
ja lz

result)
park 61
jane 71
*****
jacob 31
kim 41
lee 51
jane 71
*/
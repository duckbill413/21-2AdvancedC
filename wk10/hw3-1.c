#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student
{
    char *studentName;   //학생 이름
    char id[5];          //학생 학번
    char *subjectName;   //과목 이름
    double subjectScore; //과목 점수
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
        char tmp[101];
        gets(tmp);

        int size = 0;
        int chap = 0;
        for (char *ptmp = tmp; ptmp <= tmp + strlen(tmp); ptmp++)
        {
            if (*ptmp == ' ' || *ptmp == 0)
            {
                if (chap == 0)
                {
                    pst->studentName = NULL;
                    if ((pst->studentName = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
                        return -1;
                    strncpy(pst->studentName, ptmp - size, size);
                    pst->studentName[size] = 0;
                    chap++;
                }
                else if (chap == 1)
                {
                    strncpy(pst->id, ptmp - size, size);
                    pst->id[4] = 0;
                    chap++;
                }
                else if (chap == 2)
                {
                    pst->subjectName = NULL;
                    if ((pst->subjectName = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
                        return -1;

                    strncpy(pst->subjectName, ptmp - size, size);
                    pst->subjectName[size] = 0;
                    chap++;
                }
                else if (chap == 3)
                {
                    pst->subjectScore = atoi(ptmp - size);
                    chap++;
                }
                size = -1;
            }
            size++;
        }
    }

    int find;
    scanf("%d", &find);
    find -= 1;

    for (Student *p = st; p < st + N - 1; p++)
    {
        for (Student *q = st; q < st + N - (p - st) - 1; q++)
        {
            if (q->subjectScore < (q + 1)->subjectScore)
            {
                Student tmp = *q;
                *q = *(q + 1);
                *(q + 1) = tmp;
            }
        }
    }

    printf("%s %s %s %.2lf\n", (st + find)->studentName, (st + find)->id, (st + find)->subjectName, (st + find)->subjectScore);

    for (int i = 0; i < N; i++)
    {
        free((st + i)->studentName);
        free((st + i)->subjectName);
    }
    free(st);
    return 0;
}

/*
test case)
5
HongGilDong 1003 Math 78
JeonWooChi 1001 English 60
HeungBoo 1002 Economics 80
NolBoo 1004 Ethics 50
Euler 1005 Math 100
2

result)
HeungBoo 1002 Economics 80.00
*/
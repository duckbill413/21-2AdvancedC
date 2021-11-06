#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char *name;
    int kor, prime;
} Student;

int prime(Student *);

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
        char tmp[100];
        scanf("%s %d", tmp, &pst->kor);
        getchar();
        int size = strlen(tmp);
        pst->name = NULL;
        pst->name = (char *)malloc(sizeof(char) * (size + 1));
        if (pst->name == NULL)
            return -1;

        strcpy(pst->name, tmp);
        pst->prime = prime(pst);
    }

    for (Student *pst = st; pst < st + n; pst++)
        if (pst->prime)
            printf("%s %d\n", pst->name, pst->kor);

    for (int i = 0; i < n; i++)
        free((st + i)->name);

    free(st);
    return 0;
}

int prime(Student *st)
{
    for (int i = 2; i < st->kor; i++)
    {
        if (st->kor % i == 0)
            return 0;
    }
    return 1;
}

/*
5
jacob 31
kim 41
lee 51
park 61
jane 71
*/
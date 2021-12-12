#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student
{
    char name[20];
    char id[11];
    char grade;
} Student;

int main()
{
    Student st[5];
    for (int i = 0; i < 5; i++)
    {
        scanf("%s %s %c", st[i].name, st[i].id, &st[i].grade);
        getchar();
    }

    char find[20];
    scanf("%s", find);

    int found = 0;

    int p = 0;
    for (int i = 0; i < 5; i++)
    {
        if (!strcmp(st[i].name, find))
        {
            p = i;
            break;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        if (i == p)
            continue;
        if (!strncmp(st[i].id, st[p].id, 4) && st[i].grade == st[p].grade)
        {
            printf(" %s", st[i].name);
            found = 1;
        }
    }

    if (!found)
        printf("0");
}

/*
lee1 2017102656 A
lee2 2018111823 A
park 2018059961 A
choi 2018010101 F
lee3 2019565656 B
park
*/
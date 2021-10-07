#include <stdio.h>

typedef struct student
{
    char name[10];
    int test;
} Student;

Student *select_min(Student *);

int main()
{
    Student st[5];
    for (int i = 0; i < 5; i++)
    {
        scanf("%s %d", st[i].name, &st[i].test);
        getchar();
    }

    Student *min = select_min(st);

    printf("%s %d", min->name, min->test);
    return 0;
}

Student *select_min(Student *st)
{
    Student *result = st;
    for (int i = 1; i < 5; i++)
    {
        if (result->test > (st + i)->test)
            result = st + i;
    }
    return result;
}
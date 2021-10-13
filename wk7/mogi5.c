#include <stdio.h>
#include <string.h>

typedef struct student
{
    int id;
    char class[51];
} Student;

void sort(Student *, int);
void print(Student *, int);

int main()
{
    int n;
    scanf("%d", &n);
    Student st[100];

    getchar();
    for (int i = 0; i < n; i++)
    {
        gets(st[i].class);
        scanf("%d", &st[i].id);
        getchar();
    }

    sort(st, n);
    print(st, n);

    return 0;
}

void sort(Student *pst, int n)
{
    for (Student *i = pst; i < pst + n; i++)
    {
        for (Student *j = i + 1; j < pst + n; j++)
        {
            if (strcmp(i->class, j->class) > 0)
            {
                Student tmp = *i;
                *i = *j;
                *j = tmp;
            }
            else if (strcmp(i->class, j->class) == 0)
            {
                if (i->id > j->id)
                {
                    Student tmp = *i;
                    *i = *j;
                    *j = tmp;
                }
            }
        }
    }
}

void print(Student *pst, int n)
{
    for (Student *p = pst; p < pst + n; p++)
    {
        printf("%s %d\n", p->class, p->id);
    }
}
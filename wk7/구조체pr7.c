#include <stdio.h>
#include <string.h>

typedef struct student
{
    char name[21];
    char r_name[21];
} Student;

struct student *change(struct student *st, int);

int main()
{
    int n;
    scanf("%d", &n);

    Student st[10];
    for (Student *pst = st; pst < st + n; pst++)
    {
        getchar();
        scanf("%s %s", pst->name, pst->r_name);
    }
    Student *result = change(st, n);

    for (Student *pst = st; pst < st + n; pst++)
    {
        printf("%s %s\n", pst->name, pst->r_name);
    }
    printf("longest=%s %s", result->name, result->r_name);
    return 0;
}

struct student *change(struct student *st, int size)
{
    Student *longest = st;
    int max = 0;

    for (Student *p = st; p < st + size; p++)
    {
        int s1 = strlen(p->name);
        int s2 = strlen(p->r_name);
        char tmp[21];
        strcpy(tmp, p->r_name);
        strcpy(p->r_name, p->name);
        strcpy(p->name, tmp);
        p->name[s2] = '\0';
        p->r_name[s1] = '\0';

        int total = s1 + s2;
        if (max < total)
        {
            max = total;
            longest = p;
        }
    }

    return longest;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    char *name;
    int kor;
} Student;

Student *center(Student *p, int N);

int main()
{
    int n;
    scanf("%d", &n);

    Student st[100];

    for (int i = 0; i < n; i++)
    {
        char *tmp = (char *)malloc(sizeof(char) * 31);
        scanf("%s %d", tmp, &st[i].kor);
        getchar();
        st[i].name = tmp;
    }

    Student *close = center(st, n);
    printf("%s %d", close->name, close->kor);
    return 0;
}

Student *center(Student *p, int N)
{
    double avg = 0.0;
    for (Student *pp = p; pp < p + N; pp++)
        avg += pp->kor;
    avg /= N;

    double far_diff = avg - p->kor;
    if (far_diff < 0)
        far_diff *= (-1);

    Student *far = p;
    double diff;
    for (Student *pp = p; pp < p + N; pp++)
    {
        diff = pp->kor - avg;
        if (diff < 0)
            diff *= (-1);

        if (far_diff > diff)
        {
            far = pp;
            far_diff = diff;
        }
    }

    return far;
}
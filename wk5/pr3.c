#include <stdio.h>

typedef struct student
{
    char name[10];
    int score;
} Student;

void input(Student *s)
{
    for (int i = 0; i < 5; i++)
        scanf("%s %d", (s + i)->name, &(s + i)->score);
}

int main()
{
    Student s[5];
    input(s);

    double avg = 0.0;
    for (int i = 0; i < 5; i++)
        avg += s[i].score;
    avg /= 5.0;

    for (int i = 0; i < 5; i++)
    {
        if (s[i].score < avg)
            printf("%s\n", s[i].name);
    }
    return 0;
}
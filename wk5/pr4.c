#include <stdio.h>
typedef struct student
{
    char name[21];
    int test1, test2, test3;
    double avg;
    char score;
} Student;

void input(Student *, int);

int main()
{
    int n;
    scanf("%d", &n);
    Student s[20];
    input(s, n);

    for (int i = 0; i < n; i++)
        printf("%s %.1lf %c\n", s[i].name, s[i].avg, s[i].score);

    return 0;
}

void input(Student *s, int n)
{
    double avg = 0.0;
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d %d", (s + i)->name, &(s + i)->test1, &(s + i)->test2, &(s + i)->test3);
        avg = ((s + i)->test1 + (s + i)->test2 + (s + i)->test3) / 3.0;
        (s + i)->avg = avg;
        if (avg >= 90)
            (s + i)->score = 'A';
        else if (avg >= 80)
            (s + i)->score = 'B';
        else if (avg >= 70)
            (s + i)->score = 'C';
        else
            (s + i)->score = 'F';
    }
}
#include <stdio.h>

typedef struct student
{
    char name[11];
    int score;
} ST;

int main()
{
    FILE *fp;
    fp = fopen("student.dat", "rb");
    if (fp == NULL)
        return -1;

    ST st[3];
    for (int i = 0; i < 3; i++)
    {
        fread(&st[i], sizeof(ST), 1, fp);
    }
    fclose(fp);
    for (int i = 0; i < 3; i++)
    {
        printf("%s %d\n", st[i].name, st[i].score);
    }
}
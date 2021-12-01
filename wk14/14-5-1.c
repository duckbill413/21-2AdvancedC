#include <stdio.h>
#include <string.h>

typedef struct student
{
    char name[11];
    int score;
} ST;

int main()
{
    FILE *fp;
    fp = fopen("student.dat", "wb");
    if (fp == NULL)
        return -1;

    ST st[3];
    for (int i = 0; i < 3; i++)
    {
        scanf("%s %d", st[i].name, &st[i].score);
        getchar();
    }

    for (int i = 0; i < 3; i++)
    {
        fwrite(&st[i], sizeof(ST), 1, fp);
    }

    fclose(fp);
}
/*
Lee 90
Kim 80
Park 50
*/
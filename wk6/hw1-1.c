#include <stdio.h>
#include <string.h>

struct student
{
    char name[10];
    char id[11];
    char score;
};

int main()
{
    struct student st[5];

    for (int i = 0; i < 5; i++)
    {
        scanf("%s %s %c", st[i].name, st[i].id, &st[i].score);
    }
    getchar();
    char name[10];
    gets(name);
    
    for (int i = 0; i < 5; i++)
    {
        if (!strcmp(name, st[i].name))
        {
            printf(" %s %c", st[i].id, st[i].score);
            return 0;
        }
    }

    return 0;
}
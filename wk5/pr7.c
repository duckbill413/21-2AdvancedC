#include <stdio.h>

typedef struct number
{
    int num, rank;
} Number;

int main()
{
    Number n[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &n[i].num);
        n[i].rank = 1;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (n[i].num < n[j].num)
            {
                n[i].rank++;
            }
        }
    }

    for (int i = 0; i < 10; i++)
        if (n[i].rank == 3)
            printf("%d ", n[i].num);
    for (int i = 0; i < 10; i++)
        if (n[i].rank == 7)
            printf("%d ", n[i].num);

    return 0;
}
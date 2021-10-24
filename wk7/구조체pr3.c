#include <stdio.h>

typedef struct rest
{
    char name[100];
    int breakfast, lunch, dinner;
} Rest;

int main()
{
    Rest re[10];
    int num;
    scanf("%d", &num);

    for (Rest *pre = re; pre < re + num; pre++)
    {
        getchar();
        scanf("%s %d %d %d", pre->name, &pre->breakfast, &pre->lunch, &pre->dinner);
    }
    int cost;
    scanf("%d", &cost);

    int fcost = 0;
    int close = cost;
    Rest rest[3];

    for (Rest *i = re; i < re + num; i++)
    {
        for (Rest *j = re; j < re + num; j++)
        {
            for (Rest *k = re; k < re + num; k++)
            {
                int ca = 0;
                if (i == j || i == k || j == k)
                    continue;
                int total = i->breakfast + j->lunch + k->dinner;
                if (total > cost)
                    ca = total - cost;
                else if (total < cost)
                    ca = cost - total;
                else
                {
                    int result = i->breakfast + j->lunch + k->dinner;
                    printf("%s\n%s\n%s\n%d", i->name, j->name, k->name, result);
                    return 0;
                }
                if (ca < close)
                {
                    rest[0] = *i;
                    rest[1] = *j;
                    rest[2] = *k;
                    close = ca;
                }
            }
        }
    }
    int result = rest[0].breakfast + rest[1].lunch + rest[2].dinner;
    printf("%s\n%s\n%s\n%d", rest[0].name, rest[1].name, rest[2].name, result);
    return 0;
}
/*
4
korean 1500 1200 1500
japanese 1000 1500 1500
chinese 1000 1200 2500
italy 1000 1200 3500
6000
*/
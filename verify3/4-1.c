#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct reserve
{
    int id;
    char grade[4];
    int price;
} Reserve;

void input(struct reserve *p, int N);
int cal_sum(struct reserve *p, int N, int id);

int main()
{
    int N;
    scanf("%d", &N);
    getchar();
    Reserve *re = NULL;
    if ((re = (Reserve *)malloc(sizeof(Reserve) * N)) == NULL)
        return -1;

    input(re, N);
    int id;
    scanf("%d", &id);
    int total = cal_sum(re, N, id);

    for (Reserve *pre = re; pre < re + N; pre++)
    {
        if (pre->id == id)
            printf("%s %d\n", pre->grade, pre->price);
    }
    printf("%d", total);

    free(re);
    return 0;
}

void input(struct reserve *p, int N)
{
    for (Reserve *pre = p; pre < p + N; pre++)
    {
        scanf("%d %s", &pre->id, pre->grade);
        getchar();
        if (!strcmp(pre->grade, "VIP"))
            pre->price = 140000;
        else if (!strcmp(pre->grade, "R"))
            pre->price = 110000;
        else if (!strcmp(pre->grade, "S"))
            pre->price = 85000;
        else
            pre->price = 55000;
    }
}

int cal_sum(struct reserve *p, int N, int id)
{
    int sum = 0;
    for (Reserve *pre = p; pre < p + N; pre++)
    {
        if (pre->id == id)
            sum += pre->price;
    }
    return sum;
}

/*
10
123 A
210 VIP
123 A
123 R
210 S
210 VIP
123 A
523 A
123 R
523 VIP
123
*/
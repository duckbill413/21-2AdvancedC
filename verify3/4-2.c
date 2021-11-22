#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct reserve
{
    int id;
    char grade[4];
    int price;
} Reserve;

typedef struct tot_price
{
    int id;
    int total_price;
} TOT;

void input(struct reserve *p, int N);
void cal_sum(struct reserve *p, int N, struct tot_price *q);
int cal_num(struct reserve *p, int N);

int main()
{
    int N;
    scanf("%d", &N);
    getchar();
    Reserve *re = NULL;
    if ((re = (Reserve *)malloc(sizeof(Reserve) * N)) == NULL)
        return -1;

    input(re, N);
    int cnt = cal_num(re, N);
    TOT *tot = NULL;
    if ((tot = (TOT *)malloc(sizeof(TOT) * cnt)) == NULL)
        return -1;

    cal_sum(re, N, tot);

    for (TOT *pre = tot; pre < tot + cnt; pre++)
    {
        printf("%d %d\n", pre->id, pre->total_price);
    }

    free(re);
    free(tot);
    return 0;
}

int cal_num(struct reserve *p, int N)
{
    int cnt = 0;
    int found = 0;
    for (Reserve *pp = p; pp < p + N; pp++)
    {
        found = 0;
        for (Reserve *qp = p; qp < pp; qp++)
        {
            if (pp->id == qp->id)
            {
                found = 1;
                break;
            }
        }
        if (!found)
            cnt++;
    }

    return cnt;
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

void cal_sum(struct reserve *p, int N, struct tot_price *q)
{
    int found = 0;
    int cnt = 0;

    TOT *qp = q;
    for (Reserve *pp = p; pp < p + N; pp++)
    {
        found = 0;
        for (TOT *qq = q; qq < q + cnt; qq++)
        {
            if (pp->id == qq->id)
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            int sum = 0;
            for (Reserve *pq = p; pq < p + N; pq++)
            {
                if (pp->id == pq->id)
                {
                    sum += pq->price;
                }
            }
            qp->id = pp->id;
            qp->total_price = sum;
            qp++;
            cnt++;
        }
    }
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
*/
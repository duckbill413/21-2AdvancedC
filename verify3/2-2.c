#include <stdio.h>
#include <string.h>

typedef struct taxi_info
{
    char start[11];
    char target[11];
    double distance;
    int t_time;
    char late_tonight;
    int tot;
} TAXI;

TAXI *sel_max(TAXI *p, int N, char *s, char *d);

int main()
{
    int N;
    scanf("%d", &N);

    TAXI taxi[20];

    for (int i = 0; i < N; i++)
    {
        scanf("%s %s %lf %d %c", taxi[i].start, taxi[i].target, &taxi[i].distance, &taxi[i].t_time, &taxi[i].late_tonight);
        getchar();
        if (taxi[i].late_tonight == 'N')
        {
            if (taxi[i].distance > 2)
            {
                int tmp1 = (taxi[i].distance - 2) * 1000 / 100;
                tmp1 *= 100;
                int tmp2 = taxi[i].t_time / 30;
                tmp2 *= 100;
                taxi[i].tot = 3800 + tmp1 + tmp2;
            }
            else
                taxi[i].tot = 3800;
        }
        else if (taxi[i].late_tonight == 'Y')
        {
            if (taxi[i].distance > 2)
            {
                int tmp1 = (taxi[i].distance - 2) * 1000 / 100;
                tmp1 *= 120;
                int tmp2 = taxi[i].t_time / 30;
                tmp2 *= 120;
                taxi[i].tot = 4800 + tmp1 + tmp2;
            }
            else
                taxi[i].tot = 4800;
        }
    }

    char A[11], B[11];
    scanf("%s %s", A, B);
    getchar();

    TAXI *max = sel_max(taxi, N, A, B);
    printf("%.2lf %d %c %d", max->distance, max->t_time, max->late_tonight, max->tot);

    return 0;
}

TAXI *sel_max(TAXI *p, int N, char *s, char *d)
{
    int max = p->tot;
    TAXI *pmax = p;
    for (TAXI *pp = p; pp < p + N; pp++)
    {
        if (!strcmp(pp->start, s) && !strcmp(pp->target, d))
        {
            if (max < pp->tot)
            {
                max = pp->tot;
                pmax = pp;
            }
        }
    }
    return pmax;
}

/*
8
aaa bbb 2.25 480 N
ccc ddd 10 300 Y
eee fff 10 180 Y
aaa bbb 3 180 N
ccc ddd 12 180 Y
ggg hhh 13 60 Y
aaa bbb 4 0 N
aaa bbb 3.2 60 N
aaa bbb
*/
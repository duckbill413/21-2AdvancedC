#include <stdio.h>

void input(int *p, int M);
int *sel_max(int *p, int M);
void output(int *p, int N);

int main()
{
    int in[100], out[100], *max, i, N, M;
    scanf("%d %d", &N, &M);
    for (i = 0; i < N; i++)
    {
        input(in, M);
        max = sel_max(in, M);
        out[i] = *max;
    }
    output(out, N);
    return 0;
}

void input(int *p, int M)
{
    for (int *pp = p; pp < p + M; pp++)
        scanf("%d", pp);
}

int *sel_max(int *p, int M)
{
    int max = 0;
    int *pmax = p;
    for (int *i = p; i < p + M; i++)
    {
        int cnt = 0;
        for (int *j = p; j < p + M; j++)
        {
            if (*i == *j)
                cnt++;
        }
        if (max < cnt)
        {
            max = cnt;
            pmax = i;
        }
    }

    return pmax;
}

void output(int *p, int N)
{
    for (int *pp = p; pp < p + N; pp++)
        printf(" %d", *pp);
}

/*
3 5
1 2 2 1 3
2 4 2 4 3
1 2 3 4 5
*/
// 8Ка 30УЪ
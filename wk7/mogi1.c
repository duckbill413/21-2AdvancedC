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
    for (int *i = p; i < p + M; i++)
        scanf("%d", i);
}

int *sel_max(int *p, int M)
{
    int *pmax;
    int max = 0;
    int cnt = 0;
    for (int *i = p; i < p + M; i++)
    {
        cnt = 0;
        for (int *j = p; j < p + M; j++)
        {
            if (*i == *j & i != j)
                cnt++;
        }
        if (cnt > max)
        {
            max = cnt;
            pmax = i;
        }
    }

    return pmax;
}

void output(int *p, int N)
{
    for (int *i = p; i < p + N; i++)
        printf(" %d", *i);
}
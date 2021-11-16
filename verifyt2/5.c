#include <stdio.h>
#include <stdlib.h>

int check_row(int **p, int M, int N);
int check_col(int **P, int M, int N);

int main()
{
    int M, N;
    scanf("%d %d", &M, &N);

    int **num = NULL;
    if ((num = (int **)malloc(sizeof(int *) * M)) == NULL)
        return -1;

    // for (int i = 0; i < M; i++)
    // {
    //     num[i] = (int *)calloc(sizeof(int), N);
    // }
    for (int **pnum = num; pnum < num + M; pnum++)
    {
        *pnum = NULL;
        if ((*pnum = (int *)malloc(sizeof(int) * N)) == NULL)
            return -1;
        for (int *qnum = *pnum; qnum < *pnum + N; qnum++)
            *qnum = 0;
    }

    int a, b, c;
    while (1)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0)
            break;

        num[a][b] = c;
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d", num[i][j]);
        printf("\n");
    }

    int row = check_row(num, M, N);
    int col = check_col(num, M, N);
    if (row > col)
        printf("%d", row);
    else
        printf("%d", col);

    for (int i = 0; i < M; i++)
        free(num[i]);
    free(num);
}

int check_row(int **p, int M, int N)
{
    int max = 0;
    int cnt = 0;
    for (int i = 0; i < M; i++)
    {
        cnt = 0;
        for (int j = 0; j < N; j++)
        {
            if (p[i][j] == 0)
                cnt++;
            else
            {
                if (cnt > max)
                    max = cnt;
                cnt = 0;
            }
        }
        if (cnt > max)
            max = cnt;
    }
    return max;
}
int check_col(int **p, int M, int N)
{
    int max = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        cnt = 0;
        for (int j = 0; j < M; j++)
        {
            if (p[j][i] == 0)
                cnt++;
            else
            {
                if (cnt > max)
                    max = cnt;
                cnt = 0;
            }
        }
        if (cnt > max)
            max = cnt;
    }
    return max;
}
/*
3 5
0 0 5
0 1 15
0 3 25
1 2 35
2 1 45
2 3 55
0 0 0


4 4
0 1 1
0 3 3
1 0 1
1 2 3
2 2 0
2 3 6
3 1 2
0 0 0

3 8
1 0 3
2 1 4
1 4 8
1 6 10
1 2 14
2 6 7
2 7 9
0 3 6
2 1 1
2 3 6
0 7 1
0 0 0
*/
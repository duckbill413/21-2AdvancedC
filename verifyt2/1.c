#include <stdio.h>

void input(int *p, int N);
void output(int *p, int N);

int main()
{
    int N, M;
    scanf("%d %d", &M, &N);

    int num1[100];
    int num2[100];
    input(num1, M);
    input(num2, N);

    int K;
    scanf("%d", &K);

    int *point1 = num1;
    int *point2 = num2;

    int flag = 0;
    while (1)
    {
        if (flag == 0)
        {
            output(point1, K);
            flag = 1;
            point1 += K;
            if (point2 == num2 + N)
                flag = 0;
        }
        else if (flag == 1)
        {
            output(point2, K);
            flag = 0;
            point2 += K;
            if (point1 == num1 + M)
                flag = 1;
        }
        if (point1 == num1 + M && point2 == num2 + N)
            break;
    }

    return 0;
}

void input(int *p, int N)
{
    for (int *q = p; q < p + N; q++)
        scanf("%d", q);
}

void output(int *p, int N)
{
    for (int *q = p; q < p + N; q++)
        printf("%d ", *q);
}

/*
6 3
1 2 3 4 5 6
7 8 9
3

4 8
1 2 3 4
5 6 7 8 9 10 11 12
2
*/
#include <stdio.h>

int main()
{
    int x[100];
    int N;
    scanf("%d", &N);

    for (int *px = x; px < x + N; px++)
        scanf("%d", px);

    for (int *px = x; px < x + N; px++)
    {
        int cnt = 0;

        int found = 0;
        for (int *qx = x; qx < px; qx++)
        {
            if (*px == *qx)
                found = 1;
        }
        if (found)
            continue;

        for (int *qx = x; qx < x + N; qx++)
        {
            if (*px == *qx)
                cnt++;
        }
        printf("%d %d\n", *px, cnt);
    }

    return 0;
}

/*
7
2 3 8 2 3 4 2
*/
#include <stdio.h>

int main()
{
    int ar[50] = {0}, N;
    int *p;
    int cnt = 0;

    scanf("%d", &N);

    for (p = ar; p < ar + N; p++)
        scanf("%d", p);

    for (p = ar; p < ar + N; p++)
    {
        if (*p == 0)
            break;
        cnt++;
    }

    printf("%d", cnt);

    return 0;
}
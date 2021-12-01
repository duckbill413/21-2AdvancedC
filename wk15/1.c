#include <stdio.h>
#define ABS(a) a < 0 ? ((-1) * a) : a
#define MAX(a, b) ((ABS(a)) < (ABS(b))) ? b : a
#define N 6

int main()
{
    int num[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &num[i]);

    int max = num[0];
    for (int i = 0; i < N; i++)
        max = MAX(max, num[i]);

    printf("%d %d", max, ABS(max));
}

//-3 2 4 -5 1 7
//-9 4 3 8 7 -1
#include <stdio.h>
#include <string.h>

int main()
{
    int N, M1, M2;
    scanf("%d %d %d", &N, &M1, &M2);
    getchar();

    char ch[20][101];
    for (int i = 0; i < N; i++)
    {
        gets(ch[i]);
    }

    int min = 101, max = 0;
    char *pmin = ch[0], *pmax = ch[0];
    for (int i = 0; i < N; i++)
    {
        if (min > strlen(ch[i]))
        {
            min = strlen(ch[i]);
            pmin = ch[i];
        }
        if (max < strlen(ch[i]))
        {
            max = strlen(ch[i]);
            pmax = ch[i];
        }
    }

    char A[20][101], B[20][101];

    int size = 0;
    int cntA = 0, cntB = 0;

    for (char *pA = pmin; pA <= pmin + strlen(pmin); pA++)
    {
        if (*pA == ' ' || *pA == 0)
        {
            strncpy(A[cntA], pA - size, size);
            A[cntA][size] = 0;
            cntA++;
            size = -1;
        }
        size++;
    }
    for (char *pB = pmax; pB <= pmax + strlen(pmax); pB++)
    {
        if (*pB == ' ' || *pB == 0)
        {
            strncpy(B[cntB], pB - size, size);
            B[cntB][size] = 0;
            cntB++;
            size = -1;
        }
        size++;
    }

    char merge[101] = {0};
    if (strcmp(A[M2], B[M1]) > 0)
    {
        strcpy(merge, B[M1]);
        strcat(merge, A[M2]);
    }
    else
    {
        strcpy(merge, A[M2]);
        strcat(merge, B[M1]);
    }

    printf("%s\n", pmax);
    printf("%s\n", pmin);
    printf("%s", merge);
    return 0;
}

/*
5 4 2
book desk pencil paper
orange apple banana lemon grape
red yellow green orange blue white black
candy cake icecream
july august september october november december
*/
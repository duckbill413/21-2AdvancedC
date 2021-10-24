#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

int main()
{
    char A[101];
    char B[11], C[11];
    gets(A);
    gets(B);
    gets(C);
    char re[251] = "";

    char *start = A;
    char *point = C;
    int size = 0;
    int t_size = 0;
    for (char *p = A; p <= A + strlen(A); p++)
    {
        if (p == A + strlen(A))
        {
            // size++;
            strncat(re, start, size);
        }
        if (!strncmp(p, B, strlen(B)))
        {
            strncat(re, start, size);
            strcat(re, C);
            start = p + strlen(B);
            size = 0;
            p += strlen(B);
        }
        size++;
    }

    printf("%s", re);
    return 0;
}
/*
I have a pen. I have an applepen. PPAP.
pen
mouse

Sequence GTCGTCG
GTCG
CAGC
*/
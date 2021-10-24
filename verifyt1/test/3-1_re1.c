#include <string.h>
#include <stdio.h>

int main()
{
    char A[101];
    char B[11];
    char C[11];
    gets(A);
    gets(B);
    gets(C);

    char re[251];
    char *st = A;
    for (char *pa = A; pa <= A + strlen(A); pa++)
    {
        if (pa == A + strlen(A))
        {
            strncat(re, st, pa - st);
            break;
        }
        if (!strncmp(pa, B, strlen(B)))
        {
            strncat(re, st, pa - st);
            strncat(re, C, strlen(C));
            st = pa + strlen(B);
            pa += strlen(B);
        }
    }

    printf("%s", re);

    return 0;
}
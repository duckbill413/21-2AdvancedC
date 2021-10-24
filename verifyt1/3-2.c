#include <stdio.h>
#include <string.h>

int main()
{
    char A[101] = {0};
    char B[101] = {0};
    char re[251] = {0};

    gets(A);
    gets(B);

    char *stb = B;
    for (char *pa = A; pa <= A + strlen(A); pa++)
    {
        int size = 0;
        for (char *pp = pa; pp <= A + strlen(A); pp++)
        {
            if (*pp == ' ' || *pp == 0)
                break;
            size++;
        }
        int found = 0;
        for (char *pre = re; pre < re + strlen(re); pre++)
        {
            if (!strncmp(pre, pa, size))
                found = 1;
        }
        if (!found)
        {
            strncat(re, pa, size + 1);
            pa += size;
        }
        else
        {
            int sizeb = 0;
            for (char *pb = stb; pb < B + strlen(B); pb++)
            {
                if (*pb == ' ' || *pb == '\0')
                    break;
                sizeb++;
            }
            strncat(re, stb, sizeb + 1);
            pa += size;
            stb += (sizeb + 1);
        }
    }

    printf("%s", re);

    return 0;
}

/*
red orange red yellow green red blue purple yellow
white black gray pink brown blush crimson garnet vermilion indigo

result
red orange white yellow green black blue purple gray
*/
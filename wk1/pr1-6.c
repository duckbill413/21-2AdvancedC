#include <stdio.h>

int main()
{
    char ch[10];
    char *pch, *qch;
    for (pch = ch; pch < ch + 10; pch++)
        scanf("%c", pch);

    int cnt = 0;
    int max = 0;
    char mch;
    for (pch = ch; pch < ch + 10; pch++)
    {
        cnt = 0;
        for (qch = ch; qch < ch + 10; qch++)
        {
            if (*pch == *qch)
                cnt++;
        }

        if (cnt > max)
        {
            max = cnt;
            mch = *pch;
        }
    }

    printf("%c %d", mch, max);

    return 0;
}
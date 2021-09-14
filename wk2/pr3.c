#include <stdio.h>

void eliminate(char *);

int main()
{
    char ch[100] = "";
    char *pch;
    for (pch = ch; pch < ch + 100; pch++)
    {
        scanf("%c", pch);
        if (*pch == '*')
            break;
    }
    eliminate(ch);

    for (pch = ch; pch < ch + 100; pch++)
    {
        printf("%c", *pch);
        if (*pch == '*')
            break;
    }
    return 0;
}

void eliminate(char *ar)
{
    int cnt = 0;
    char *pcnt = ar;

    while (1)
    {
        cnt++;
        if (*pcnt == '*')
            break;
        pcnt++;
    }

    //printf("cnt: %d\n", cnt);

    int found = 0;
    for (char *i = ar; i < ar + cnt; i++)
    {
        found = 0;
        for (char *j = ar; j < i; j++)
        {
            if (*i == *j)
            {
                found = 1;
                break;
            }
        }
        if (found)
        {
            for (char *d = i; d < ar + cnt; d++)
            {
                *d = *(d + 1);
                //printf("%c ", *d);
            }
            //printf("\n");
            i--;
            cnt--;
        }
    }
}
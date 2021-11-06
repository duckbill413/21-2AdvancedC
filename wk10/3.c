#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verb(char *ch);

int main()
{
    char tmp[100];
    gets(tmp);

    int total = 0;
    char **ch = NULL;
    ch = (char **)malloc(sizeof(char *) * 100);
    if (ch == NULL)
        return -1;
    char **pch = ch;
    int *ver = NULL;
    ver = (int *)malloc(sizeof(int) * 100);
    if (ver == NULL)
        return -1;

    int *pver = ver;
    int size = 0;
    for (char *ptmp = tmp; ptmp <= tmp + strlen(tmp); ptmp++)
    {
        if (*ptmp == ' ' || *ptmp == '\0')
        {
            char *new = NULL;
            new = (char *)malloc(sizeof(char) * (size + 1));
            if (new == NULL)
                return -1;
            strncpy(new, ptmp - size, size);
            *(new + size) = '\0';
            *pch = new;
            total++;
            *pver++ = verb(*pch);
            // printf("%d\n", *pver++);
            pch++;
            size = -1;
        }
        size++;
    }

    for (char **p = ch; p < ch + total; p++)
    {
        for (char **q = p + 1; q < ch + total; q++)
        {
            if (*(ver + (p - ch)) < *(ver + (q - ch)))
            {
                char *ctmp = *p;
                *p = *q;
                *q = ctmp;

                int ntmp = *(ver + (p - ch));
                *(ver + (p - ch)) = *(ver + (q - ch));
                *(ver + (q - ch)) = ntmp;
            }
        }
    }

    for (int i = 0; i < total; i++)
    {
        printf("%s %d\n", *(ch + i), *(ver + i));
    }

    for (int i = 0; i < total; i++)
    {
        free(ch[i]);
    }
    free(ch);
    free(ver);
    return 0;
}

int verb(char *ch)
{
    int cnt = 0;
    for (char *p = ch; p < ch + strlen(ch); p++)
    {
        if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'u' || *p == 'o')
            cnt++;
    }
    return cnt;
}

// happy good onion
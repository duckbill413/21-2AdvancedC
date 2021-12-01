#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char x[101] = {0};
    gets(x);

    int cnt = 0;
    for (char *px = x; px <= x + strlen(x); px++)
    {
        if (*px == ' ' || *px == 0)
            cnt++;
    }
    char **ch = NULL;
    if ((ch = (char **)malloc(sizeof(char *) * cnt)) == NULL)
        return -1;

    int size = 0;
    char **pch = ch;
    for (char *px = x; px <= x + strlen(x); px++)
    {
        if (*px == ' ' || *px == 0)
        {
            *pch = NULL;
            if ((*pch = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
                return -1;
            strncpy(*pch, px - size, size);
            (*pch++)[size] = 0;
            size = -1;
        }
        size++;
    }

    for (char **pch = ch; pch < ch + cnt - 1; pch++)
    {
        for (char **qch = ch; qch < ch + cnt - (pch - ch) - 1; qch++)
        {
            if (strcmp(*qch, *(qch + 1)) > 0)
            {
                char *tmp = *qch;
                *qch = *(qch + 1);
                *(qch + 1) = tmp;
            }
        }
    }

    for (char **pch = ch; pch < ch + cnt; pch++)
        printf("%s\n", *pch);

    for (char **pch = ch; pch < ch + cnt; pch++)
        free(*pch);
    free(ch);
    return 0;
}
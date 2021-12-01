#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char tmp[101];
    gets(tmp);

    char findA[101], findB[101];
    scanf("%s %s", findA, findB);

    int size = 0;
    for (char *ptmp = tmp; ptmp <= tmp + strlen(tmp); ptmp++)
    {
        if (*ptmp == ' ' || *ptmp == 0)
            size++;
    }
    int cnt = size;
    char **ch = NULL;
    if ((ch = (char **)malloc(sizeof(char *) * cnt)) == NULL)
        return -1;

    size = 0;
    char **pch = ch;
    for (char *ptmp = tmp; ptmp <= tmp + strlen(tmp); ptmp++)
    {
        if (*ptmp == ' ' || *ptmp == 0)
        {
            *pch = NULL;
            if ((*pch = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
                return -1;
            strncpy(*pch, ptmp - size, size);
            (*pch)[size] = '\0';
            pch++;
            size = -1;
        }
        size++;
    }

    for (pch = ch; pch < ch + cnt; pch++)
    {
        if (strcmp(*pch, findA) >= 0 && strcmp(*pch, findB) <= 0)
            printf("%s\n", *pch);
    }

    for (int i = 0; i < cnt; i++)
        free(ch[i]);
    free(ch);
    return 0;
}

/*
lion cat tiger snake bear
caa szz
*/
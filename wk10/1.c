#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    char **ch = NULL;
    ch = (char **)malloc(sizeof(char *) * n);
    if (ch == NULL)
        return -1;
    for (char **pch = ch; pch < ch + n; pch++)
    {
        char tmp[100];
        gets(tmp);
        int size = strlen(tmp);
        char *new = NULL;
        new = (char *)malloc(sizeof(char *) * size);
        if (new == NULL)
            return -1;

        strcpy(new, tmp);
        *pch = new;
    }
    int *number = NULL;
    number = (int *)malloc(sizeof(int) * n);
    if (number == NULL)
        return -1;
    int *pnum = number;

    for (char **pch = ch; pch < ch + n; pch++)
    {
        *pnum = 0;
        int found = 1;
        for (char **qch = ch; qch < pch; qch++)
        {
            if (!strcmp(*pch, *qch))
            {
                found = 0;
            }
        }
        if (found)
            for (char **qch = ch; qch < ch + n; qch++)
            {
                if (!strcmp(*pch, *qch))
                    (*pnum)++;
            }
        pnum++;
    }
    pnum = number;
    for (char **pch = ch; pch < ch + n; pch++)
    {
        if (*(pnum + (pch - ch)) > 1)
        {
            printf("%s %d\n", *pch, *(pnum + (pch - ch)));
        }
    }

    for (int i = 0; i < n; i++)
        free(ch[i]);
    free(ch);
    free(number);
    return 0;
}
/*
6
lion
cat
tiger
lion
cat
lion
*/
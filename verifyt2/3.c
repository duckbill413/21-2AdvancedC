#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int N;
    char find[101];

    scanf("%d %s", &N, find);
    getchar();

    char **ch = NULL;
    if ((ch = (char **)malloc(sizeof(char *) * N)) == NULL)
        return -1;
    int *num = NULL;
    if ((num = (int *)malloc(sizeof(int) * N)) == NULL)
        return -1;
    int *pnum = num;

    for (char **pch = ch; pch < ch + N; pch++)
    {
        char tmp[101];
        gets(tmp);

        *pch = NULL;
        if ((*pch = (char *)malloc(sizeof(char) * (strlen(tmp) + 1))) == NULL)
            return -1;
        strcpy(*pch, tmp);

        int size = strlen(find);
        int cnt = 0;
        for (char *ptmp = tmp; ptmp < tmp + strlen(tmp); ptmp++)
        {
            if (!strncmp(ptmp, find, size))
            {
                cnt++;
                ptmp += (size - 1);
            }
        }
        *pnum = cnt;
        pnum++;
    }

    int max = 0;
    int pmax = 0;
    for (pnum = num; pnum < num + N; pnum++)
    {
        if (*pnum > max)
        {
            max = *pnum;
            pmax = pnum - num;
        }
    }
    if (max == 0)
        printf("NONE");
    else
        printf("%s", ch[pmax]);

    for (int i = 0; i < N; i++)
        free(ch[i]);
    free(ch);
    free(num);
}

/*
3 abc
abcabc abcabc
ABCabc ABCabc
abc abc abc abcd
*/
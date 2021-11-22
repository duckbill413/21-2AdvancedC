#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string
{
    char *str;
    int words;
} String;

int main()
{
    int N;
    scanf("%d", &N);
    getchar();

    String *st = NULL;
    if ((st = (String *)malloc(sizeof(String) * N)) == NULL)
        return -1;

    int size = 0;
    String *pst = st;
    for (int i = 0; i < N; i++)
    {
        char tmp[101] = {0};
        gets(tmp);
        int word = 0;
        size = 0;
        pst->str = NULL;
        pst->str = (char *)malloc(sizeof(char) * (strlen(tmp) + 1));
        if (pst->str == NULL)
            return -1;
        strcpy(pst->str, tmp);

        for (char *p = tmp; p <= tmp + strlen(tmp); p++)
        {
            if (*p == ' ' || *p == '\0')
            {
                word++;
                size = -1;
            }
            size++;
        }
        pst->words = word;
        pst++;
    }

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (st[j].words < st[j + 1].words)
            {
                String tmp = st[j];
                st[j] = st[j + 1];
                st[j + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        printf("%s %d\n", st[i].str, st[i].words);
    }

    for (int i = 0; i < N; i++)
    {
        free(st[i].str);
    }
    free(st);
}
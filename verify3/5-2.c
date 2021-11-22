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
                word++;
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
        printf("%s %d", st[i].str, st[i].words);
        char **ch = NULL;
        if ((ch = (char **)malloc(sizeof(char *) * st[i].words)) == NULL)
            return -1;

        size = 0;

        int cnt_ch = 0;
        char **pch = ch;
        for (char *p = st[i].str; p <= st[i].str + strlen(st[i].str); p++)
        {
            if (*p == 0 || *p == ' ')
            {
                *pch = NULL;
                *pch = (char *)malloc(sizeof(char) * (size + 1));
                if (*pch == NULL)
                    return -1;

                strncpy(*pch, p - size, size);
                (*pch++)[size] = 0;

                cnt_ch++;
                size = -1;
            }
            size++;
        }

        int max = 0, cnt_word = 0;
        char temp[101];
        for (int i = 0; i < cnt_ch; i++)
        {
            cnt_word = 0;
            for (int j = i; j < cnt_ch; j++)
            {
                if (!strcmp(ch[i], ch[j]))
                    cnt_word++;
            }
            if (max < cnt_word)
            {
                max = cnt_word;
                strcpy(temp, ch[i]);
            }
            else if (max == cnt_word && strcmp(temp, ch[i]) > 0)
                strcpy(temp, ch[i]);
        }

        printf(" %s %d\n", temp, max);

        for (int i = 0; i < st[i].words; i++)
            free(ch[i]);
        free(ch);
    }

    for (int i = 0; i < N; i++)
        free(st[i].str);
    free(st);
}

/*
5
why why why so so so serious
icecream makes everything better and better
you make me smile
c language exam and exam and exam and exam
see you later later later later
*/
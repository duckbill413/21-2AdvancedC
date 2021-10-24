#include <stdio.h>
#include <string.h>

int main()
{
    char ch[101];
    char *tch[10];
    int num = 0;

    gets(ch);

    int size = 0;
    int size_ch = strlen(ch);

    char *start = ch;
    for (char *pch = ch; pch <= ch + size_ch; pch++)
    {
        if (*pch == ' ' || *pch == '\0')
        {
            tch[num] = start;
            *(tch[num] + size) = '\0';
            num++;
            start = pch + 1;
            size = -1;
        }
        size++;
    }

    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if (strlen(tch[j]) < strlen(tch[j + 1]))
            {
                char *tmp = tch[j];
                tch[j] = tch[j + 1];
                tch[j + 1] = tmp;
            }
            else if (strcmp(tch[j], tch[j + 1]) > 0)
            {
                char *tmp = tch[j];
                tch[j] = tch[j + 1];
                tch[j + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < num; i++)
        printf("%s\n", tch[i]);

    return 0;
}
#include <stdio.h>
#include <string.h>
//#pragma warning(disable:4996)
int main()
{
    char ch[101];
    gets(ch);
    int N;
    scanf("%d", &N);

    char *re[100];
    int num = 0;

    char *start = ch;
    int size = 0;

    int ch_size = strlen(ch);
    for (char *pch = ch; pch <= ch + ch_size; pch++)
    {
        if (*pch == ' ' || *pch == '\0')
        {
            re[num] = start;
            *(re[num] + size) = '\0';
            size = -1;
            start = pch + 1;
            num++;
        }
        size++;
    }

    printf("%s\n", re[N - 1]);
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - 1 - i; j++)
        {
            if (strcmp(re[j], re[j + 1]) > 0)
            {
                char *tmp = re[j];
                re[j] = re[j + 1];
                re[j + 1] = tmp;
            }
        }
    }

    printf("%s", re[0]);
    return 0;
}
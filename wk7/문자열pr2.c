#include <stdio.h>
#include <string.h>

int main()
{
    char ch[101];
    char tch[10][11];
    int num = 0;

    gets(ch);

    int size = 0;
    int size_ch = strlen(ch);

    char *start = ch;
    for (char *pch = ch; pch <= ch + size_ch; pch++)
    {
        if (*pch == ' ' || *pch == '\0')
        {
            strncpy(tch[num], start, size);
            tch[num][size] = '\0';
            num++;
            start = pch + 1;
            size = 0;
        }
        size++;
    }

    for (int i = 0; i < num; i++)
        printf("%s\n", tch[i]);

    return 0;
}
#include <stdio.h>
#include <string.h>

int font(char *, int);
int back(char *, int);

int main()
{
    char ch[101];
    gets(ch);

    for (char *pch = ch; pch < ch + strlen(ch); pch++)
    {
        if ((font(ch, pch - ch) == 0 && back(ch, pch - ch == 1)) ||
            (font(ch, pch - ch) == 1 && back(ch, pch - ch) == 0))
            printf("%c", *pch + 28);
        else
            printf("%c", *pch);
    }
}

int font(char *ch, int idx)
{
    for (char *pch = ch; pch < ch + idx - 1; pch++)
    {
        if (*pch == *(ch + idx - 1))
            return 1;
    }
    return 0;
}

int back(char *ch, int idx)
{
    for (char *pch = ch + strlen(ch) - 1; pch > ch + idx - 1; pch--)
    {
        if (*pch == *(ch + idx - 1))
            return 1;
    }
    return 0;
}
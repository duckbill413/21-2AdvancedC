#include <stdio.h>

int main()
{
    char ch[20];
    char *pch;
    int cnt = 0;
    for (pch = ch; pch < ch + 20; pch++)
    {
        scanf("%c", pch);
        if (*pch == '#')
            break;
        cnt++;
    }

    for (pch; pch > ch; pch--)
    {
        printf("%c", *(pch - 1));
    }
    return 0;
}
#include <stdio.h>
#define size 100

void repeat(char *, int);

int main()
{
    char ch[size] = "";
    char *pch;

    for (pch = ch; pch < ch + size; pch++)
    {
        scanf("%c", pch);
        if (*pch == '*')
            break;
    }

    int re;
    scanf("%d", &re);

    repeat(ch, re);

    for (pch = ch; pch < ch + size; pch++)
    {
        printf("%c", *pch);
        if (*pch == '*')
            break;
    }

    return 0;
}

void repeat(char *ch, int re)
{
    int size_ch = 0;
    char *p;
    for (p = ch; p < ch + 100; p++)
    {
        if (*p == '*')
            break;
        size_ch++;
    }

    //printf("size_ch: %d\n", size_ch);
    int cnt = 0;
    for (p = ch + size_ch; p < ch + re * size_ch; p++)
    {
        *p = *(ch + cnt % size_ch);
        cnt++;
    }
    *p = '*';
}
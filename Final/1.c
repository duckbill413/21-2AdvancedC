#include <stdio.h>
#include <string.h>

int main()
{
    char ch[101];
    int result;

    gets(ch);
    char select[4];
    strncpy(select, ch, 3);

    int size = 0;
    for (char *pch = ch + 4; pch <= ch + strlen(ch); pch++)
    {
        if (*pch == ' ')
            break;
        size++;
    }
    int a = 0, b = 0;
    int minus = 0;
    for (char *p = ch + 4; p < (ch + 4) + size; p++)
    {
        if (*p == '-')
        {
            minus = 1;
            continue;
        }
        a = a * 10 + (*p - '0');
    }
    if (minus)
        a *= -1;

    minus = 0;
    for (char *p = ch + size + 5; p < ch + strlen(ch); p++)
    {
        if (*p == '-')
        {
            minus = 1;
            continue;
        }
        b = b * 10 + (*p - '0');
    }
    if (minus)
        b *= -1;

    // printf("c: %s %d %d\n", select, a, b);

    if (!strcmp(select, "add"))
        result = a + b;
    else if (!strcmp(select, "mul"))
        result = a * b;
    else if (!strcmp(select, "sub"))
        result = a - b;
    else if (!strcmp(select, "div"))
        result = a / b;
    printf("%s %d", select, result);
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    char *ch = NULL;
    ch = (char *)malloc(sizeof(char) * n + 1);
    if (ch == NULL)
        return -1;
    gets(ch);
    char a, b;
    scanf("%c %c", &a, &b);

    int cnta = 0, cntb = 0;
    for (char *pch = ch; pch < ch + n; pch++)
    {
        if (*pch == a)
            cnta++;
        if (*pch == b)
            cntb++;
    }

    printf("%d %d", cnta, cntb);
    free(ch);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    int cnt = 0;
    for (char *p = ch; p < ch + n; p++)
        if (!strncmp(p, "cat", 3))
            cnt++;

    printf("%d", cnt);
    free(ch);
    return 0;
}
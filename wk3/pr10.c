#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);

    char ch[100][101];
    getchar();
    for (int i = 0; i < n; i++)
    {
        gets(ch[i]);
    }

    int min;
    char *pmin;
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || min > strlen(ch[i]))
        {
            min = strlen(ch[i]);
            pmin = ch[i];
        }
    }
    printf("%s", pmin);

    return 0;
}
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main()
{
    int n;
    scanf("%d", &n);
    getchar();

    char ch[10][101];
    for (int i = 0; i < n; i++)
        gets(ch[i]);

    int s_size = strlen(ch[0]);
    int l_size = strlen(ch[0]);
    char* sch = ch[0];
    char* lch = ch[0];

    for (int i = 0; i < n; i++)
    {
        if (s_size > strlen(ch[i]))
        {
            s_size = strlen(ch[i]);
            sch = ch[i];
        }
        if (l_size < strlen(ch[i]))
        {
            l_size = strlen(ch[i]);
            lch = ch[i];
        }
    }

    char* sp = sch;
    int size = 0;

    for (char* p = sch; p <= sch + strlen(sch); p++)
    {
        if (*p == ' ' || *p == '\0')
        {
            if (strcmp(p-size, sp) < 0)
            {
                sp = p -size;
            }
            size = -1;
        }
        size++;
    }

    size = 0;
    char* lp = lch;
    for (char* p = lch; p <= lch + strlen(lch); p++)
    {
        if (*p == ' ' || *p == '\0')
        {
            if (strcmp(p-size, lp) > 0)
            {
                lp = p-size;
            }
            size = -1;
        }
        size++;
    }

    size = 0;
    for (char* p = sp; p <= sp + strlen(sp); p++)
    {
        if (*p == ' ' || *p == '\0')
        {
            *p = '\0';
        }
        size++;
    }
    size = 0;
    for (char* p = lp; p <= lp + strlen(lp); p++)
    {
        if (*p == ' ' || *p == '\0')
        {
            *p = '\0';
        }
        size++;
    }

    printf("%s\n", sp);
    printf("%s", lp);
    return 0;
}
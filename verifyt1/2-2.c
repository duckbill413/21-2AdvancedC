#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
int main()
{
    char ch[10][101] = { 0 };
    int n;
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++)
        gets(ch[i]);

    int small = strlen(ch[0]), longest = strlen(ch[0]);
    char* psmall = ch[0], * plongest = ch[0];

    for (int i = 0; i < n; i++)
    {
        if (strlen(ch[i]) < small)
        {
            small = strlen(ch[i]);
            psmall = ch[i];
        }
        if (strlen(ch[i]) > longest)
        {
            longest = strlen(ch[i]);
            plongest = ch[i];
        }
    }

    char* spoint = psmall;
    int min = 101;
    int size = 0;

    for (char* p = psmall; p < psmall + strlen(psmall); p++)
    {
        if (*p == ' ' || *p == '\0')
        {
            if (min > size)
            {
                spoint = p - size;
                min = size;
            }
            size = -1;
        }
        size++;
    }

    char* lpoint = plongest;
    int lsize = 0;
    size = 0;
    for (char* p = plongest; p < plongest + strlen(plongest); p++)
    {
        if (*p == ' ' || *p == '\0')
        {
            if (lsize < size)
            {
                lpoint = p - size;
                lsize = size;
            }
            size = -1;
        }
        size++;
    }

    for (char* p = spoint; p <= spoint + strlen(spoint); p++)
    {
        if (*p == ' ' || *p == '\0')
            *p = '\0';
    }
    for (char* p = lpoint; p <= lpoint + strlen(lpoint); p++)
    {
        if (*p == ' ' || *p == '\0')
            *p = '\0';
    }

    printf("%s\n", spoint);
    printf("%s", lpoint);

    return 0;
}

/*
2
why so serious
icecream makes everything better

3
you make me smile
c language midterm exam
i see you
*/
#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++)
    {
        char ch[101] = "";
        gets(ch);

        int size = 0;
        char *p = ch;
        for (char *pch = ch; pch <= ch + strlen(ch); pch++)
        {
            if (pch == ch + strlen(ch))
                printf("none\n");

            if (*pch >= '0' && *pch <= '9')
            {
                size++;
            }
            else
                size = 0;

            if (size == 4)
            {
                if (*(pch + 1) == ' ' || *(pch + 1) == '\0')
                {
                    p = pch - 3;
                    *(pch + 1) = '\0';
                    break;
                }
                else
                    size = 0;
            }
        }
        if (size == 4)
            printf("%s\n", p);
    }
}

/*
4
1234 the 12345
12345 phone 2345
12345 my 12345 mobile
his number is 5555 12345
*/
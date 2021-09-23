#include <stdio.h>
#include <string.h>

int main()
{
    char ch[100] = "";
    int n;

    gets(ch);
    scanf("%d", &n);

    for (char *pch = ch; pch < ch + strlen(ch); pch++)
    {
        if (*pch >= 'A' && *pch <= 'Z')
            *pch = *pch + n;
        else if (*pch >= 'a' && *pch <= 'z')
            *pch = *pch - n;
        else if (*pch >= '0' && *pch <= '9')
        {
            int flag = 1;
            int num = (int)(*pch) - '0';
            if (*(pch + 1) >= '0' && *(pch + 1) <= '9')
            {
                num = num * 10 + (int)(*(pch + 1)) - '0';
                flag = 2;
            }

            char plus[11];
            for (char *p = plus; p < plus + n; p++)
                *p = 'A' + num - 1;
            plus[n] = '\0';

            char tmp[100] = "";
            strncpy(tmp, ch, pch - ch);
            strcat(tmp, plus);
            strcat(tmp, pch + flag);
            tmp[strlen(ch) + n - 1] = '\0';
            strcpy(ch, tmp);

            pch += n - 1;
        }
        else
            *pch = ' ';
    }
    printf("%s", ch);

    return 0;
}
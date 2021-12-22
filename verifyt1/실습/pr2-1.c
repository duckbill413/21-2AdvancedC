#include <stdio.h>
#include <string.h>

int main()
{
    char ch[101] = "";
    gets(ch);
    int find;
    scanf("%d", &find);

    int cnt = 0, size = 0;
    char *point = ch;
    for (char *pch = ch; pch <= ch + strlen(ch); pch++)
    {
        if (*pch == ' ' || *pch == '\0')
        {
            cnt++;
            if (cnt == find)
            {
                point = pch - size;
                *(pch + 1) = '\0';
                break;
            }
            size = -1;
        }
        size++;
    }
    printf("%s", point);
}
/*
tomorrow is a mystery
1
*/
//6Ка
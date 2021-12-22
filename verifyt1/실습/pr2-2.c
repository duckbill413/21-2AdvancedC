#include <stdio.h>
#include <string.h>

int main()
{
    char ch[101] = "";
    gets(ch);
    int find;
    scanf("%d", &find);

    int cnt = 0, size = 0;
    char *point[100];

    int ch_size = strlen(ch);
    for (char *pch = ch; pch <= ch + ch_size; pch++)
    {
        if (*pch == ' ' || *pch == '\0')
        {
            point[cnt] = pch - size;
            *(point[cnt++] + size) = '\0';
            size = -1;
        }
        size++;
    }
    printf("%s\n", point[find - 1]);

    for (int i = 0; i < cnt - 1; i++)
    {
        for (int j = 0; j < cnt - i - 1; j++)
        {
            if (strcmp(point[j], point[j + 1]) > 0)
            {
                char *tmp = point[j];
                point[j] = point[j + 1];
                point[j + 1] = tmp;
            }
        }
    }
    printf("%s\n", point[0]);
    return 0;
}

/*
tomorrow is a mystery
1

physically keep apart
1
*/
// 6Ка
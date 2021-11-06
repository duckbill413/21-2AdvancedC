#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char tmp[100];
    gets(tmp);

    int total = 0;
    char **ch = NULL;
    ch = (char **)malloc(sizeof(char *) * 100);
    if (ch == NULL)
        return -1;
    char **pch = ch;
    int size = 0;
    for (char *ptmp = tmp; ptmp <= tmp + strlen(tmp); ptmp++)
    {
        if (*ptmp == ' ' || *ptmp == '\0')
        {
            char *new = NULL;
            new = (char *)malloc(sizeof(char) * (size + 1));
            if (new == NULL)
                return -1;
            strncpy(new, ptmp - size, size);
            *(new + size) = '\0';
            *pch = new;
            total++;
            // printf("%s\n", *pch);
            pch++;
            size = -1;
        }
        size++;
    }

    int flag = 0;
    int end = total - 1;
    int start = 0;
    for (int i = 0; i < total; i++)
    {
        if (flag == 0)
        {
            printf("%s\n", *(ch + start));
            start++;
            if (i % 2 == 1)
                flag = 1;
        }
        else if (flag == 1)
        {
            printf("%s\n", *(ch + end));
            end--;
            if (i % 2 == 1)
                flag = 0;
        }
    }

    for (int i = 0; i < total; i++)
        free(ch[i]);
    free(ch);

    return 0;
}
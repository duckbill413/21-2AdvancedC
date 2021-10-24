#include <stdio.h>
#include <string.h>

int main()
{
    char x[101] = {0}, y[50][101] = {0}, tmp[101] = {0}, *p, *q;
    gets(x);

    int size = 0;
    q = x;
    for (p = x;; p++)
    {
        if (*p == ' ')
        {
            *p = '\0';
            strcpy(y[size++], q);
            q = p + 1;
        }
        else if (*p == '\0')
        {
            strcpy(y[size++], q);
            q = p + 1;
            break;
        }
    }

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (strcmp(y[j], y[j + 1]) > 0)
            {
                char tmp[101];
                strcpy(tmp, y[j]);
                strcpy(y[j], y[j + 1]);
                strcpy(y[j + 1], tmp);
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        printf("%s\n", y[i]);
    }

    return 0;
}
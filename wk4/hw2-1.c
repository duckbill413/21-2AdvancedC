#include <stdio.h>
#include <string.h>

int main()
{
    char ch[100] = "";
    gets(ch);

    for (int i = 0; i < strlen(ch) - 1; i++)
    {
        for (int j = 0; j < strlen(ch) - i - 1; j++)
        {
            if (ch[j] > ch[j + 1])
            {
                char tmp = ch[j];
                ch[j] = ch[j + 1];
                ch[j + 1] = tmp;
            }
        }
    }

    printf("%s", ch);

    return 0;
}
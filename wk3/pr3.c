#include <stdio.h>
#include <string.h>

int main()
{
    char ch[100] = "";

    scanf("%s", ch);

    int size = 0;
    while (ch[size] != '\0')
    {
        ++size;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%s\n", ch);
        char tmp = ch[0];
        for (char *q = ch; q < ch + size; q++)
        {
            *q = *(q + 1);
        }
        ch[size - 1] = tmp;
    }
    return 0;
}
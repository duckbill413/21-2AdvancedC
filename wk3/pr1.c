#include <stdio.h>
#include <string.h>

int main()
{
    char ch[21] = "";
    scanf("%s", ch);

    char cch[21] = "";
    int size = 0;
    for (char *p = ch; *p != '\0'; p++)
    {
        if (*p >= 'a' && *p <= 'z')
        {
            cch[size] = *p;
            size++;
            //ch[size] = '\0';
        }
    }
    printf("%s", cch);

    return 0;
}
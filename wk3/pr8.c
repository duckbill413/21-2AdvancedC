#include <stdio.h>
#include <string.h>

int main()
{
    char str1[101] = "", str2[101] = "";
    scanf("%s %s", str1, str2);

    if (strcmp(str1, str2) != 0)
    {
        if (strcmp(str1, str2) > 0)
        {
            strcat(str1, str2);
            printf("%s", str1);
            return 0;
        }
        else
        {
            strcat(str2, str1);
            printf("%s", str2);
            return 0;
        }
    }
}
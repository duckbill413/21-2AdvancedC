#include <stdio.h>
#include <string.h>

int main()
{
    char ch1[100] = "", ch2[100] = "";
    scanf("%s", ch1);
    scanf("%s", ch2);

    char *pch1, *pch2;

    int size = 0;
    int found = 1;
    for (pch1 = ch1, pch2 = ch2; *pch1 != '\0'; pch1++, pch2++)
    {
        //printf("%c %c\n", *pch1, *pch2);
        size++;
        if (*pch1 != *pch2)
            found = 0;
    }

    printf("%d %d", size, found);

    return 0;
}
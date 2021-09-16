#include <string.h>
#include <stdio.h>

int main()
{
    char str1[81] = "";
    char str2[11] = "";

    scanf("%s %s", str1, str2);

    int cnt = 0;
    for (char *ps1 = str1, *ps2 = str2; ps1 <= str1 + strlen(str1); ps1++)
    {
        if (*ps1 != *ps2)
        {
            cnt = 0;
            ps2 = str2;
        }
        if (*ps1 == *ps2)
        {
            cnt++;
            if (cnt == (strlen(str2)))
            {
                printf("%d 1", strlen(str1));
                return 0;
            }
            ps2++;
        }
    }
    printf("%d 0", strlen(str1));

    return 0;
}
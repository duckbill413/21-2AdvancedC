#include <string.h>
#include <stdio.h>

int main()
{
    char str1[101] = "";
    char str2[11] = "";

    gets(str1);
    scanf("%s", str2);

    int cnt = 0;
    int mcnt = 0;
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
                mcnt++;
                cnt = 0;
                ps2 = str2;
                continue;
            }
            ps2++;
        }
    }
    printf("%d", mcnt);

    return 0;
}
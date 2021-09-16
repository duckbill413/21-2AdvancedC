#include <stdio.h>
#include <string.h>

int main()
{
    char str1[42] = "", str2[21] = "";
    scanf("%s", str1);
    scanf("%s", str2);
    int insert;
    scanf("%d", &insert);

    int size2 = 0;
    while (str2[size2] != '\0')
        ++size2;

    int i = 0;
    for (char *ps = str1; ps != '\0'; ps++)
    {
        if (ps == str1 + insert)
        {
            for (i = 0; i < size2; i++)
            {
                *(ps + size2 + i) = *(ps + i);
            }
            *(ps + size2 + i) = '\0';
            for (i = 0; i < size2; i++)
            {
                *(ps + i) = str2[i];
            }

            break;
        }
    }

    printf("%s", str1);

    return 0;
}
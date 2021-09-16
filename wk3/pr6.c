#include <stdio.h>
#include <string.h>

int main()
{
    char str1[41], str2[21];
    scanf("%s", str1);
    scanf("%s", str2);

    int point;
    scanf("%d", &point);
    int inverse;
    scanf("%d", &inverse);

    int size1 = 0;
    while (str1[size1] != '\0')
        ++size1;

    int size2 = 0;
    while (str2[size2] != '\0')
        ++size2;

    for (int i = size1 - 1; i >= point; i--)
        str1[i + size2] = str1[i];

    if (inverse == 0)
        for (int i = point; i < size2 + point; i++)
        {
            str1[i] = str2[i - point];
        }
    else
        for (int i = point; i < size2 + point; i++)
        {
            str1[i] = str2[size2 - (i - point + 1)];
        }
    str1[size1 + size2] = '\0';

    printf("%s", str1);
    return 0;
}
#include <stdio.h>
#include <string.h>
//#pragma warning(disable:4996)
int vowel(char *);

int main()
{
    char ch1[101];
    char ch2[101];
    scanf("%s", ch1);
    getchar();
    scanf("%s", ch2);
    getchar();

    char *i = ch1;
    char *j = ch2;

    int select = 0;
    while (1)
    {
        if (select == 0)
        {
            if (*i == '\0')
            {
                select = 1;
                continue;
            }
            if (vowel(i))
                select = 1;

            printf("%c", *i++);
        }
        if (select == 1)
        {
            if (*j == '\0')
            {
                select = 0;
                continue;
            }
            if (vowel(j))
                select = 0;

            printf("%c", *j++);
        }

        if (*i == '\0' && *j == '\0')
            break;
    }
}

int vowel(char *ch)
{
    if (*ch == 'A' || *ch == 'a' || *ch == 'E' || *ch == 'e' ||
        *ch == 'I' || *ch == 'O' || *ch == 'o' || *ch == 'U' || *ch == 'u')
    {
        return 1;
    }
    return 0;
}

#include <stdio.h>
#include <string.h>

int check(char *);

int main()
{
    char ch[31] = "";
    scanf("%s", ch);

    printf("%d %d", strlen(ch), check(ch));

    return 0;
}

int check(char *ch)
{
    char check[31] = "";
    for (int i = 0; i < strlen(ch); i++)
        check[i] = *(ch + strlen(ch) - i - 1);
    check[strlen(ch)] = '\0';
    if (strcmp(ch, check) == 0)
        return 1;
    else
        return 0;
}
#include <stdio.h>
#include <string.h>
int main()
{
    int num;
    scanf("%d", &num);

    int size = 0;
    char ch[10] = "";
    while (num != 0)
    {
        ch[size++] = num % 10 + 48;
        num /= 10;
    }

    printf("%s", ch);
    return 0;
}
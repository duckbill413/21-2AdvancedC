#include <stdio.h>
#include <string.h>

void StringAdd(char arr[], char ch, int index);
int Convertor(char x);

int main()
{
    char str[20] = "";
    gets(str);

    for (char *pstr = str; pstr < str + strlen(str) - 1; pstr++)
    {
        int x = Convertor(*pstr);
        int y = Convertor(*(pstr + 1));
        if (x % 2 == y % 2)
        {
            if (x % 2 == 0)
            {
                StringAdd(str, '*', pstr + 1 - str);
                pstr++;
            }
            else
            {
                StringAdd(str, '+', pstr + 1 - str);
                pstr++;
            }
        }
    }

    printf("%s", str);
    return 0;
}

int Convertor(char x)
{
    return x - 48;
}

void StringAdd(char arr[20], char ch, int index)
{
    for (char *p = arr + strlen(arr) - 1; p >= arr + index; p--)
    {
        *(p + 1) = *p;
    }
    *(arr + index) = ch;
}
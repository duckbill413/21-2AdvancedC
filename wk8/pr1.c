#include <stdio.h>

void Read(char *, int);
void check(char *, char *, char);
void Write(char *, int);

int main()
{
    char x[100] = "", y[100] = "";
    for (char *p = y; p < y + 100; p++)
        *p = '_';

    int m, n;
    scanf("%d %d", &n, &m);
    getchar();

    Read(x, n);

    for (int i = 0; i < m; i++)
    {
        char tmp;
        scanf("%c", &tmp);
        getchar();
        check(x, y, tmp);
        Write(y, n);
    }

    return 0;
}

void Read(char *ch, int n)
{
    char *p;
    for (p = ch; p < ch + n; p++)
        scanf("%c", p);
    getchar();
    *(p + n) = '\0';
}

void check(char *x, char *y, char ch)
{
    
    for (char *p = x;*p!='\0'; p++)
    {
        if (*p == ch)
        {
            *(y + (p - x)) = *p;
        }
    }
    /*
    char *p = x;
    while (1)
    {
        if (*p == '\0')
        {
            break;
        }
        if (*p == ch)
        {
            *(y + (p - x)) = *p;
        }
        p++;
    }
    */
}

void Write(char *ch, int n)
{
    for (char *p = ch; p < ch + n; p++)
        printf(" %c", *p);
    printf("\n");
}
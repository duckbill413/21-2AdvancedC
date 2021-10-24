#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    char ch[101] = "";
    char tch[10][11];
    int sort[10];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        getchar();
        scanf("%s", tch[i]);
    }
    for (int i = 0; i < n; i++)
        scanf("%d", &sort[i]);

    for (int i = 0; i < n; i++)
    {
        strcat(ch, tch[sort[i] - 1]);
        strcat(ch, " ");
    }
    ch[strlen(ch)] = '\0';

    printf("%s", ch);
    return 0;
}
#include <stdio.h>
#include <string.h>

int check_w(char *p, char *q);

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    getchar();
    M--;
    char ch[10][101];
    int num[10] = {0};

    for (int i = 0; i < N; i++)
    {
        gets(ch[i]);
        char *point = ch[i];
        num[i] = check_w(point, (point + M));
    }

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (num[j] < num[j + 1])
            {
                char tmp[101];
                strcpy(tmp, ch[j]);
                strcpy(ch[j], ch[j + 1]);
                strcpy(ch[j + 1], tmp);

                int tmpnum = num[j];
                num[j] = num[j + 1];
                num[j + 1] = tmpnum;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (num[i] > 0)
            printf("%s\n", ch[i]);
    }

    return 0;
}
int check_w(char *p, char *q)
{
    if (q > p + strlen(p) - 1)
        q = p + strlen(p) - 1;

    int cnt = 0;
    for (char *check = p; check <= q; check++)
    {
        if ((*check > 'z' || *check < 'a') && (*check > 'Z' || *check < 'A') && *check != ' ')
            cnt++;
    }
    return cnt;
}

/*
5 15
1 year is 365 days.
How are you doing?
**Notice**
Winter is coming
1+1=2
*/

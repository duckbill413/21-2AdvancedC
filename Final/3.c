#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct st
{
    char *str;
    int cnt;
};
int nonVerb(char *tmp); //자음의 수
int main()
{
    int N;
    scanf("%d", &N);
    getchar();

    struct st *class = NULL;
    class = (struct st *)malloc(sizeof(struct st) * N);
    if (class == NULL)
        return -1;

    for (struct st *p = class; p < class + N; p++)
    {
        char tmp[101];
        gets(tmp);
        int cnt = strlen(tmp);

        p->str = NULL;
        p->str = (char *)malloc(sizeof(char) * (cnt + 1));
        if (p->str == NULL)
            return -1;

        strcpy(p->str, tmp);
        p->cnt = nonVerb(tmp);
    }

    for (struct st *p = class; p < class + N - 1; p++)
    {
        for (struct st *q = class; q < class + N - (p - class) - 1; q++)
        {
            if (q->cnt < (q + 1)->cnt)
            {
                struct st temp = *q;
                *q = *(q + 1);
                *(q + 1) = temp;
            }
        }
    }

    for (struct st *p = class; p < class + N; p++)
        printf("%s\n", p->str);

    for (int i = 0; i < N; i++)
        free(class[i].str);
    free(class);
}

int nonVerb(char *tmp)
{
    int cnt = 0;
    for (char *ptmp = tmp; ptmp < tmp + strlen(tmp); ptmp++)
    {
        if (*ptmp == 'a' || *ptmp == 'e' || *ptmp == 'i' || *ptmp == 'o' || *ptmp == 'u' || *ptmp == 'A' || *ptmp == 'E' || *ptmp == 'I' || *ptmp == 'O' || *ptmp == 'U')
            cnt++; //모음의 수
    }
    return strlen(tmp) - cnt;
}

/*
5
History
Politics
DonQuixote
LaPeste
Chaos


*/
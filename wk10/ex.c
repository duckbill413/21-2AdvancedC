#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)
typedef struct tourcity
{
    char name[21];
    int fee;
    char inout;
    char date[9];
} Tourcity;

int main()
{
    int N;
    scanf("%d", &N);
    getchar();

    char **place = NULL;
    if ((place = (char **)malloc(sizeof(char *) * N)) == NULL)
    {
        printf("Not Enough Memory.");
        return -1;
    }
    char **pplace = place;

    char tmp[100];
    gets(tmp);

    int size = 0;
    for (char *ptmp = tmp; ptmp <= tmp + strlen(tmp); ptmp++)
    {
        if (*ptmp == ' ' || *ptmp == '\0')
        {
            *pplace = NULL;
            *pplace = (char *)malloc(sizeof(char) * (size + 1));
            if (*pplace == NULL)
                return -1;
            strncpy(*pplace, ptmp - size, size);
            *(*pplace + size) = '\0';
            pplace++;
            size = -1;
        }
        size++;
    }

    int *num = NULL;
    if ((num = (int *)malloc(sizeof(int) * N)) == NULL)
    {
        printf("Not Enough Memory.");
        return -1;
    }

    int cnt = 0;
    for (int *pnum = num; pnum < num + N; pnum++)
    {
        scanf("%d", pnum);
        cnt += *pnum;
    }
    getchar();

    Tourcity **ptr = NULL;
    if ((ptr = (Tourcity **)malloc(sizeof(Tourcity *) * N)) == NULL)
    {
        printf("Not Enough Memory.");
        return -1;
    }

    for (Tourcity **pptr = ptr; pptr < ptr + N; pptr++)
    {
        *pptr = NULL;
        if ((*pptr = (Tourcity *)malloc(sizeof(Tourcity) * num[pptr - ptr])) == NULL)
        {
            printf("Not Enough Memory.");
            return -1;
        }
        for (Tourcity *qptr = *pptr; qptr < *pptr + num[pptr - ptr]; qptr++)
        {
            gets(tmp);
            int size = 0, chap = 0;
            for (char *ptmp = tmp; ptmp <= tmp + strlen(tmp); ptmp++)
            {
                if (*ptmp == ' ' || *ptmp == 0)
                {
                    if (chap == 0)
                    {
                        strncpy(qptr->name, ptmp - size, size);
                        qptr->name[size] = 0;
                        size = -1;
                        chap++;
                    }
                    else if (chap == 1)
                    {
                        int sum = 0;
                        for (char *p = ptmp - size; p < ptmp; p++)
                        {
                            sum = sum * 10 + (*p - '0');
                        }
                        qptr->fee = sum;
                        chap++;

                        size = -1;
                    }
                    else if (chap == 2)
                    {
                        qptr->inout = *(ptmp - 1);
                        chap++;
                        size = -1;
                    }
                    else if (chap == 3)
                    {
                        strncpy(qptr->date, ptmp - size, size);
                        qptr->date[8] = 0;
                        size = -1;
                    }
                }
                size++;
            }
        }
    }

    Tourcity *ex = *ptr;
    ex->fee = 0;
    int ex_place = 0;
    for (Tourcity **pptr = ptr; pptr < ptr + N; pptr++)
    {
        for (Tourcity *qptr = *pptr; qptr < *pptr + *(num + (pptr - ptr)); qptr++)
        {
            if (qptr->fee > ex->fee)
            {
                *ex = *qptr;
                ex_place = pptr - ptr;
            }
            else if (qptr->fee == ex->fee && strcmp(qptr->date, ex->date) < 0)
            {
                *ex = *qptr;
                ex_place = pptr - ptr;
            }
        }
    }

    printf("%s %s %d %s %c", place[ex_place], ex->name, ex->fee, ex->date, ex->inout);

    for (int i = 0; i < N; i++)
    {
        free(place[i]);
    }
    free(place);
    for (int i = 0; i < N; i++)
    {
        free(ptr[i]);
    }
    free(ptr);
    free(num);
    return 0;
}

/*
test case)
3
Seoul Busan Yeosu
3 1 2
Coex 0 I 19970513
Duksugung 2000 O 20000101
Museum 1500 I 19950323
Haewoondae 0 O 19940830
Haetul 2500 B 20010305
SeaHouse 5500 O 19851201

result)
Yeosu SeaHouse 5500 19851201 0
*/
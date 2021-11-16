#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct customer
{
    char id[5];
    char *name;
    char *phone;
} Customer;

int main()
{
    int N;
    scanf("%d", &N);
    getchar();

    Customer *cs = NULL;
    if ((cs = (Customer *)malloc(sizeof(Customer) * N)) == NULL)
        return -1;

    for (Customer *pcs = cs; pcs < cs + N; pcs++)
    {
        char tmp[101];
        gets(tmp);

        int size = 0, chap = 0;
        for (char *ptmp = tmp; ptmp <= tmp + strlen(tmp); ptmp++)
        {
            if (*ptmp == ' ' || *ptmp == 0)
            {
                if (chap == 0)
                {
                    pcs->name = NULL;
                    if ((pcs->name = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
                        return -1;
                    strncpy(pcs->name, ptmp - size, size);
                    pcs->name[size] = 0;
                    size = -1;
                    chap++;
                }
                else if (chap == 1)
                {
                    pcs->phone = NULL;
                    if ((pcs->phone = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
                        return -1;
                    strncpy(pcs->phone, ptmp - size, size);
                    pcs->phone[size] = 0;

                    strcpy(pcs->id, ptmp - 4);
                    size = -1;
                    chap++;
                }
            }
            size++;
        }
    }

    char id[5];
    scanf("%s", id);

    for (Customer *pcs = cs; pcs < cs + N; pcs++)
    {
        if (!strcmp(pcs->id, id))
        {
            printf("%s %s %d", pcs->name, pcs->phone, pcs - cs + 1);
        }
    }

    for(int i=0; i<N; i++)
    {
        free(cs[i].name);
        free(cs[i].phone);
    }
    free(cs);
    return 0;
}

/*
test case)
5
KimSooJin 010-1234-5678
ParkGilDong 010-2468-1357
ChungSangChul 010-1230-4567
LeeYoungHee 010-1357-2468
ChoiMyungHee 010-3458-1267
2468

result)
LeeYoungHee 010-1357-2468 4
*/
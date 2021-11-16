#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tourcity //������ ����ü ����
{
    char name[21]; //��������
    int fee;       //�����
    char inout;    //�߿�/�ǳ� ����
    char date[9];  //������ ���� ��
} Tourcity;

int main()
{
    int N;
    scanf("%d", &N); //������ ����
    getchar();       //���� ����

    char **place = NULL;
    if ((place = (char **)malloc(sizeof(char *) * N)) == NULL) //���� �̸� �Է��� ���� ���� �迭 ����
    {
        printf("Not Enough Memory."); //���н� ������ ��� �� ����
        return -1;
    }
    char **pplace = place;

    char tmp[100];
    gets(tmp); //���ø� ���ڿ� �Է�

    int size = 0;
    for (char *ptmp = tmp; ptmp <= tmp + strlen(tmp); ptmp++)
    {
        if (*ptmp == ' ' || *ptmp == '\0') //����, ���� ���ڰ� ������
        {
            *pplace = NULL;
            if ((*pplace = (char *)malloc(sizeof(char) * (size + 1))) == NULL) //�����̸� �迭 �����Ҵ�
            {
                printf("Not Enough Memory."); //���н� �������� ����
                return -1;
            }

            strncpy(*pplace, ptmp - size, size); // tmp���ڿ��� size��ŭ ����
            *(*pplace + size) = '\0';            //�������� ���� ���� ����
            pplace++;                            //���� �ּ� �̵�
            size = -1;
        }
        size++;
    }

    int *num = NULL;                                    //�� ���ÿ� ���� ������ ���� �Է�
    if ((num = (int *)malloc(sizeof(int) * N)) == NULL) // N�� ��ŭ ���� �Ҵ�
    {
        printf("Not Enough Memory."); //���н� ���� ��� �� ����
        return -1;
    }

    for (int *pnum = num; pnum < num + N; pnum++)
    {
        scanf("%d", pnum); //�� ���ÿ� ���� ������ ���� �Է�
    }
    getchar(); //���� ����

    Tourcity **ptr = NULL;
    if ((ptr = (Tourcity **)malloc(sizeof(Tourcity *) * N)) == NULL) //�������� ���������� ����Ͽ� ���� �Ҵ�
    {
        printf("Not Enough Memory."); //�����Ҵ� ���н� ������ ����
        return -1;
    }

    for (Tourcity **pptr = ptr; pptr < ptr + N; pptr++) // N�� ���ÿ� ���� ������ Ž��
    {
        *pptr = NULL;
        if ((*pptr = (Tourcity *)malloc(sizeof(Tourcity) * num[pptr - ptr])) == NULL) // N�� ���ÿ� ���Ͽ� ������ ������ ������ŭ �����Ҵ�
        {
            printf("Not Enough Memory."); //���н� ����, ����
            return -1;
        }
        for (Tourcity *qptr = *pptr; qptr < *pptr + num[pptr - ptr]; qptr++) //������ ���� ��ŭ Ž��
        {
            gets(tmp);              //���ڿ� �Է�
            int size = 0, chap = 0; // chap�� �ܰ踦 ���� ����
            for (char *ptmp = tmp; ptmp <= tmp + strlen(tmp); ptmp++)
            {
                if (*ptmp == ' ' || *ptmp == 0) //���ڿ��� ����, ���� ����
                {
                    if (chap == 0) //�������� �Է�
                    {
                        strncpy(qptr->name, ptmp - size, size); // size��ŭ ����
                        qptr->name[size] = 0;                   //�������� ���Ṯ��
                        size = -1;
                        chap++; //���� �ܰ�
                    }
                    else if (chap == 1) //��� ���� �Է�
                    {
                        int sum = 0;
                        for (char *p = ptmp - size; p < ptmp; p++) //���ڸ� �Է� �޾� ������ �ٲ��ش�.
                        {
                            sum = sum * 10 + (*p - '0');
                        }
                        qptr->fee = sum; //��ݿ� �ٲ� ���� �Է�
                        chap++;          //���� �ܰ�

                        size = -1;
                    }
                    else if (chap == 2) //�߿�/�ǳ� ���� �Է�
                    {
                        qptr->inout = *(ptmp - 1); //���� �� ���ڿ� ������ �ԷµǹǷ� �ش� ���ڸ� �Է�
                        chap++;                    //���� �ܰ�
                        size = -1;
                    }
                    else if (chap == 3) // 8�� ������ ������ �Է�
                    {
                        strncpy(qptr->date, ptmp - size, size); //������==8 ��ŭ ���� �Է�
                        qptr->date[8] = 0;                      //������ ���� ����
                        size = -1;
                    }
                }
                size++;
            }
        }
    }

    Tourcity *ex = *ptr;                                //ã�� ������ ���� �ʱⰪ���� ó�� ������ �Է�
    int ex_place = 0;                                   //���� ��ġ ����
    for (Tourcity **pptr = ptr; pptr < ptr + N; pptr++) // N�� ���ÿ� ���Ͽ� Ž��
    {
        for (Tourcity *qptr = *pptr; qptr < *pptr + *(num + (pptr - ptr)); qptr++) // num�� �������� ���Ͽ� Ž��
        {
            if (qptr->fee > ex->fee) //����� ex���� Ŭ��
            {
                *ex = *qptr;           //����ü ���� ����
                ex_place = pptr - ptr; //���� ���� �Է�
            }
            else if (qptr->fee == ex->fee && strcmp(qptr->date, ex->date) < 0) //����� ������ ������ �����Ͽ� ���Ͽ� �����Ȱ��� ã�´�.
            {
                *ex = *qptr;           //����ü ���� ����
                ex_place = pptr - ptr; //���� ���� �Է�
            }
        }
    }

    printf("%s %s %d %s %c", place[ex_place], ex->name, ex->fee, ex->date, ex->inout);
    //ã�� ���� ������ �Է�, ex����ü ���� �Է�

    //���� ���� �޸� ����
    for (int i = 0; i < N; i++)
        free(place[i]);
    free(place);
    //������ ���� �޸� ����
    for (int i = 0; i < N; i++)
        free(ptr[i]);
    free(ptr);
    free(num); //���ú� ������ ���� ���� �޸� ����

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
Yeosu SeaHouse 5500 19851201 O
*/
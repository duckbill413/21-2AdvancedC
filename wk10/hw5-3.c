//!!�����Ҵ�, �ڱ����� ����ü
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct customer
{
    char id[5];            //�� ���̵�
    char *name;            //�� �̸�
    char *phone;           //�� ��ȭ��ȣ
    struct customer *next; //������ ���ڰ� ���� �� �ּ�
} Customer;

int main()
{
    int N;
    scanf("%d", &N); //�Է��� Ƚ�� N�� �Է¹޴´�
    getchar();       //���� ����

    Customer *cs = NULL;
    if ((cs = (Customer *)malloc(sizeof(Customer) * N)) == NULL)
        return -1; //�� ���� ����ü�� N�� ��ŭ �Ҵ��ϰ� ���н� ����

    for (Customer *pcs = cs; pcs < cs + N; pcs++) //�� ���� �Է�
    {
        char tmp[101]; //�ӽ� ���ڿ� �Է�
        gets(tmp);

        int size = 0, chap = 0;                                   // chap�� �ܰ� ����
        for (char *ptmp = tmp; ptmp <= tmp + strlen(tmp); ptmp++) //���ڿ� Ž��
        {
            if (*ptmp == ' ' || *ptmp == 0) //���ڰ� ����, ���� ���� �Ͻ�
            {
                if (chap == 0) //�� �̸� �Է�
                {
                    pcs->name = NULL;
                    if ((pcs->name = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
                        return -1;                         //�� �̸��� ���Ͽ� size��ŭ �����Ҵ� �ϰ� ���н� ����
                    strncpy(pcs->name, ptmp - size, size); //���̸� size��ŭ �Է�
                    pcs->name[size] = 0;                   //�������� ���Ṯ��
                    size = -1;
                    chap++; //���� �ܰ�
                }
                else if (chap == 1) //����ȭ��ȣ �Է�
                {
                    pcs->phone = NULL;
                    if ((pcs->phone = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
                        return -1;                          //����� ���Ͽ� �� ��ȭ��ȣ�� �Ҵ��ϰ� ���н� ����
                    strncpy(pcs->phone, ptmp - size, size); //�� ��ȭ��ȣ �Է�
                    pcs->phone[size] = 0;                   //�������� ���� ���� �Է�

                    strcpy(pcs->id, ptmp - 4); // id�� ���Ṯ�ڷ� ���� ������ 4�� ��ȣ �Է�
                    size = -1;
                    chap++;
                }
                if (*ptmp == 0) //���� ���ڰ� ���ð�� next�ּ� �Է�
                {
                    pcs->next = NULL;                               //�ƹ��� ���� ��츦 ���� NULL�� �ʱ�ȭ
                    for (Customer *qcs = pcs - 1; qcs >= cs; qcs--) //������� �� Ž��
                    {
                        if (qcs->id[3] == pcs->id[3]) //������ ���ڰ� ������
                        {
                            qcs->next = pcs; //���� ���� next�� ���� �Է¹��� �� ����ü �ּ� �Ҵ�
                            break;
                        }
                    }
                }
            }
            size++;
        }
    }

    char find[5]; //ã�����ϴ� �� ��ȣ �Է�
    scanf("%s", &find);
    int cnt = 1;                                  //�� ��° ���� ��Ÿ���ֱ� ���� ����
    for (Customer *pcs = cs; pcs < cs + N; pcs++) //���� ���Ͽ� Ž��
    {
        if (find[3] == pcs->id[3]) //ã�� �� ��ȣ�� ������ ���ڰ� ������ ���� next�� Ž���Ͽ� �˻� Ƚ�ָ� ���δ�.
        {
            while (1)
            {
                if (!strcmp(pcs->id, find)) // id�� find�� ������ �O�� ���� ���
                {
                    printf("%s %s %d", pcs->name, pcs->phone, cnt);
                }
                if (pcs->next == NULL) // next���� NULL�̸� ���İ� �����Ƿ� ����
                    break;
                pcs = pcs->next; //ã�� ���� ��� next �ּҸ� �Ű��ش�.
                cnt++;           //ī��Ʈ ����
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        free(cs[i].name);  //�� �̸� �޸� ����
        free(cs[i].phone); //�� ��ȭ��ȣ �޸� ����
    }
    free(cs); //�� ����ü �޸� ����
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
LeeYoungHee 010-1357-2468 2
*/
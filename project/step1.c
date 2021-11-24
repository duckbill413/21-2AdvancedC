#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NUM 100

typedef struct people
{                   //����ó ����ü
    char name[21];  //�̸�
    char phone[16]; //��ȭ��ȣ
    char birth[9];  //�������
} TEL;

void insert(TEL *pe, int *cnt, int max_num);
void sort(TEL *pe, int *cnt);
void delete (TEL *pe, int *cnt);
void searchBirth(TEL *pe, int *cnt);
void show(TEL *pe, int *cnt);

int main()
{
    TEL pe[MAX_NUM]; // MAX_NUM���� ���� ���� ����
    //�ȳ� �������̽�
    int select;
    int cnt = 0;      //��ü �ο��� ����
    int maintain = 1; // while�� �ݺ��� ���� ����
    while (maintain)
    {
        printf("*****Menu*****\n");
        printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
        printf("Enter_the_menu_number:");
        scanf("%d", &select);
        getchar();

        switch (select)
        {
        case 1:
            insert(pe, &cnt, MAX_NUM);
            break;
        case 2:
            show(pe, &cnt);
            break;
        case 3:
            delete (pe, &cnt);
            break;
        case 4:
            searchBirth(pe, &cnt);
            break;
        case 5:
            maintain = 0;
            break;
        }
    }
}

void insert(TEL *pe, int *cnt, int max_num)
{
    if (*cnt >= max_num) //�ִ����尳�� �ʰ�
        printf("OVERFLOW\n");
    else
    {
        printf("Name:");            // ����
        scanf("%s", pe[*cnt].name); // name �Է�
        getchar();
        printf("Phone_number:");     // ����
        scanf("%s", pe[*cnt].phone); // phone �Է�
        getchar();
        printf("Birth:");            //����
        scanf("%s", pe[*cnt].birth); // birth�Է�
        getchar();
        (*cnt)++;                   //�ο��� ����
        printf("<< %d >>\n", *cnt); //�Էµ� �ο���
        sort(pe, cnt);              //�������� ����
    }
}

void sort(TEL *pe, int *cnt)
{
    for (int i = 0; i < *cnt - 1; i++) //���� ����
    {
        for (int j = 0; j < *cnt - i - 1; j++)
        {
            if (strcmp(pe[j].name, pe[j + 1].name) > 0) //�̸������� ����
            {
                TEL tmp = pe[j];
                pe[j] = pe[j + 1];
                pe[j + 1] = tmp;
            }
        }
    }
}

void show(TEL *pe, int *cnt) //��ü ��� ����
{
    for (int i = 0; i < *cnt; i++)
    {
        printf("%s %s %s\n", pe[i].name, pe[i].phone, pe[i].birth); //��ü ��� ���
    }
}
void delete (TEL *pe, int *cnt) //��� ����
{
    if (*cnt == 0) //����� ������ ������
    {
        printf("NO MEMBER\n");
    }
    else
    {
        printf("Name:"); // ����
        char tmp[21];
        scanf("%s", tmp); //�̸� �Է� �ޱ�
        getchar();

        int found = 0;
        for (int i = 0; i < *cnt; i++)
        {
            if (!strcmp(pe[i].name, tmp)) //��ġ�� �̸� ���� �ҽ�
            {
                found = 1;
            }
            if (found)
            {
                pe[i] = pe[i + 1]; //���� ���� ������ ����� �ϳ��� ��ܿ´�.
            }
        }
        if (found)
            (*cnt)--; //���� �ϳ� ����
    }
}

void searchBirth(TEL *pe, int *cnt) //���� �� ã��
{
    printf("Birth:"); // ����
    int tmp;
    scanf("%d", &tmp); //���� �� �Է�
    getchar();

    for (int i = 0; i < *cnt; i++)
    {
        int month = 0;
        for (char *search = pe[i].birth + 4; search < pe[i].birth + 6; search++) //����ü ���Ͽ� ���Ͽ� �� ���� ������ �ٲپ��ش�.
            month = month * 10 + (*search - '0');
        if (month == tmp) //������ �ٲ� ���� ã�� ���� ��ġ�� ���
            printf("%s %s %s\n", pe[i].name, pe[i].phone, pe[i].birth);
    }
}
/*
case1 �Է�)
2
3
1
KimEunJoo
0001112222
19960101
1
LeeEunJoo
0103332222
19960202
1
HanEunJoo
0114445555
20000101

case2 �Է�)
1
Kim
0112223333
19950101
1
Han
01011112222
19960302
1
Lee
0101234567
19970903

*/
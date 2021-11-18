#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct people
{                   //����ó ����ü
    char name[21];  //�̸�
    char phone[16]; //��ȭ��ȣ
    char birth[9];  //�������
} People;

void insert(People *pe, int *cnt);
void sort(People *pe, int *cnt);
void delete (People *pe, int *cnt);
void searchBirth(People *pe, int *cnt);
void show(People *pe, int *cnt);

int main()
{
    People pe[100]; // 100���� ���� ���� ����
    //�ȳ� �������̽�
    int select;
    int cnt = 0;
    while (1)
    {
        printf("*****Menu*****\n");
        printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
        printf("Enter_the_menu_number:");
        scanf("%d", &select);
        getchar();
        if (select == 1) // Registration
        {
            if (cnt > 100) //�ִ� ���� ���� �ʰ�
            {
                printf("OVERFLOW\n");
                continue;
            }
            insert(pe, &cnt); //�ڷ� �Է� �� ���� ����
        }
        else if (select == 2) // ShowAll
        {
            show(pe, &cnt);
        }
        else if (select == 3) // delete
        {
            if (cnt == 0) //����� ������ ������
            {
                printf("NO MEMBER\n");
                continue; //ó�� �޴��� �̵�
            }
            delete (pe, &cnt);
        }
        else if (select == 4) //���Ͽ� ã��
        {
            searchBirth(pe, &cnt);
        }
        else if (select == 5) //����
            break;
    }
}

void insert(People *pe, int *cnt)
{
    printf("Name:"); // ����
    scanf("%s", pe[*cnt].name);
    getchar();
    printf("Phone_number:"); // ����
    scanf("%s", pe[*cnt].phone);
    getchar();
    printf("Birth:"); //����
    scanf("%s", pe[*cnt].birth);
    getchar();
    (*cnt)++;                   //�ο��� ����
    printf("<< %d >>\n", *cnt); //�Էµ� �ο���
    sort(pe, cnt);              //�������� ����
}

void sort(People *pe, int *cnt)
{
    for (int i = 0; i < *cnt - 1; i++) //���� ����
    {
        for (int j = 0; j < *cnt - i - 1; j++)
        {
            if (strcmp(pe[j].name, pe[j + 1].name) > 0) //�̸������� ����
            {
                People tmp = pe[j];
                pe[j] = pe[j + 1];
                pe[j + 1] = tmp;
            }
        }
    }
}

void show(People *pe, int *cnt) //��ü ��� ����
{
    for (int i = 0; i < *cnt; i++)
    {
        printf("%s %s %s\n", pe[i].name, pe[i].phone, pe[i].birth); //��ü ��� ���
    }
}
void delete (People *pe, int *cnt) //��� ����
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

void searchBirth(People *pe, int *cnt) //���� �� ã��
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
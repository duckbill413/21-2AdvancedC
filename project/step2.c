#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct people
{                //����ó ����ü
    char *name;  //�̸�
    char *phone; //��ȭ��ȣ
    char *birth; //�������
} People;

void insert(People *pe, int *cnt);
void sort(People **pe, int *cnt);
void show(People **pe, int *cnt);
void delete (People **pe, int *cnt);
void searchBirth(People **pe, int *cnt);

int main()
{
    int max_num;
    printf("Max_num:"); // ����
    scanf("%d", &max_num);

    People **pe = NULL;                                 // ���� ������ ����ü
    pe = (People **)malloc(sizeof(People *) * max_num); // max_num�� ������ŭ �����Ҵ�
    if (pe == NULL)
        return -1;

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
            if (cnt >= max_num) //�Է°��� �ʰ��� �Է� �Ұ�
            {
                printf("OVERFLOW\n");
                continue;
            }
            *(pe + cnt) = NULL;
            *(pe + cnt) = (People *)malloc(sizeof(People)); //�Է��� ���� �Ǿ����Ƿ� �����Ҵ� ���ش�.
            //��������� �Էµ� ������ŭ �����Ҵ��� �̷�� ����. �Է°���<=max_num
            if (*(pe + cnt) == NULL) //���н� ����
                return -1;

            insert(*(pe + cnt), &cnt); //�ڷ� �Է�
            sort(pe, &cnt);
        }
        else if (select == 2) // ShowAll
        {
            show(pe, &cnt);
        }
        else if (select == 3) // Delete
        {
            if (cnt == 0) //����� ������ ������
            {
                printf("NO MEMBER\n");
                continue;
            }
            delete (pe, &cnt);
        }
        else if (select == 4) //���� �� �˻�
        {
            searchBirth(pe, &cnt);
        }
        else if (select == 5) // Exit
            break;
    }

    for (int i = 0; i < cnt; i++) //�� ������ ���Ͽ� �����Ҵ� ����
    {
        free(pe[i]->name);
        free(pe[i]->birth);
        free(pe[i]->phone);
        free(pe[i]);
    }
    free(pe); // max_num ������ŭ �Ҵ��� �Ϳ� ���Ͽ� �����Ҵ� ����
}

void insert(People *pe, int *cnt)
{
    char name[101] = {0}, phone[101] = {0}, birth[101] = {0};
    printf("Name:"); // ����
    scanf("%s", name);
    getchar();
    printf("Phone_number:"); // ����
    scanf("%s", phone);
    getchar();
    printf("Birth:"); //����
    scanf("%s", birth);
    getchar();

    pe->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
    pe->phone = (char *)malloc(sizeof(char) * (strlen(phone) + 1));
    pe->birth = (char *)malloc(sizeof(char) * (strlen(birth) + 1));
    strcpy(pe->name, name);
    strcpy(pe->phone, phone);
    strcpy(pe->birth, birth);

    (*cnt)++;                   //�ο��� ����
    printf("<< %d >>\n", *cnt); //�Էµ� �ο���
}

void sort(People **pe, int *cnt)
{
    for (int i = 0; i < *cnt - 1; i++) //���� ����
    {
        for (int j = 0; j < *cnt - i - 1; j++)
        {
            if (strcmp(pe[j]->name, pe[j + 1]->name) > 0) //�̸������� ����
            {
                People *tmp = pe[j];
                pe[j] = pe[j + 1];
                pe[j + 1] = tmp;
            }
        }
    }
}

void show(People **pe, int *cnt)
{
    for (People **p = pe; p < pe + *cnt; p++)
        printf("%s %s %s\n", (*p)->name, (*p)->phone, (*p)->birth);
}

void delete (People **pe, int *cnt)
{
    printf("Name:"); // ����
    char tmp[21];
    scanf("%s", tmp);
    getchar();

    int found = 0;
    People **p;
    for (p = pe; p < pe + *cnt; p++)
    {
        if (!strcmp((*p)->name, tmp))
        {
            found = 1;
            break;
        }
    }

    if (found)
    {
        for (People **q = p; q < pe + *cnt - 1; q++)
        {
            (*q)->name = (char *)realloc((*q)->name, sizeof(char) * (strlen((*(q + 1))->name) + 1));
            (*q)->phone = (char *)realloc((*q)->phone, sizeof(char) * (strlen((*(q + 1))->phone) + 1));
            (*q)->birth = (char *)realloc((*q)->birth, sizeof(char) * (strlen((*(q + 1))->birth) + 1));

            strcpy((*q)->name, (*(q + 1))->name);
            strcpy((*q)->phone, (*(q + 1))->phone);
            strcpy((*q)->birth, (*(q + 1))->birth);
        }
        (*cnt)--;
        free(pe[*cnt]->name);
        free(pe[*cnt]->phone);
        free(pe[*cnt]->birth);
        free(pe[*cnt]);
    }
}

void searchBirth(People **pe, int *cnt)
{
    printf("Birth:"); // ����
    int tmp;
    scanf("%d", &tmp);
    getchar();

    for (int i = 0; i < *cnt; i++)
    {
        int month = 0;
        for (char *search = pe[i]->birth + 4; search < pe[i]->birth + 6; search++)
            month = month * 10 + (*search - '0');
        if (month == tmp)
            printf("%s %s %s\n", pe[i]->name, pe[i]->phone, pe[i]->birth);
    }
}
/*
case1 �Է�)
3
1
Hong
01111112222
20000101
1
KimEunJoo
222111333
19960303
1
HanGeul
010222333
19980101

5
1
Hong
01111112222
20000101
1
KimEunJoo
222111333
19960303
1
HanGeul
010222333
19980101
1
Galma
010019310931305
19970703
1
Mahima
010023982087
20030103

3
1
HongGilDong
01111112222
20000101
1
KimJoo
222111333
19960303
1
Han
010222333
19980101
1
5

5
1
Hong
01111112222
20000101
1
KimEunJoo
222111333
19960303
1
HanGeul
010222333
19980101
1
Galma
010019310931305
19970703
1
Mahima
010023982087
20030103
2
4
3
4
1
2
1
2
4
7
2
3
Hangeul
2
3
Mahima
2
3
Galma
2
1
naheun
010389292838
19900430
2
1
Anna
01092833394
19990903
*/
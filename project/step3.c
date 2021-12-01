#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct people
{                //����ó ����ü
    char *name;  //�̸�
    char *phone; //��ȭ��ȣ
    char *birth; //�������
} TEL;

void insert(TEL **pe, int *cnt, int max_num);
void sort(TEL **pe, int *cnt);
void show(TEL **pe, int *cnt);
void delete (TEL **pe, int *cnt);
void searchBirth(TEL **pe, int *cnt);
void ReqFromFile(TEL **pe, int *cnt, int max_num);
void saveFile(TEL **pe, int *cnt);

int main()
{
    int max_num;
    printf("Max_num:"); // ����
    scanf("%d", &max_num);

    TEL **pe = NULL;                              // ���� ������ ����ü
    pe = (TEL **)malloc(sizeof(TEL *) * max_num); // max_num�� ������ŭ �����Ҵ�
    if (pe == NULL)
        return -1;
    //�ȳ� �������̽�

    int select;
    int cnt = 0;      //��ü �ο��� ����
    int maintain = 1; // while�� �ݺ��� ���� ����
    while (maintain)
    {
        printf("*****Menu*****\n");
        printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.ReqFromFile><6.Exit>\n");
        printf("Enter_the_menu_number:");
        scanf("%d", &select);
        getchar();

        switch (select)
        {
        case 1:
            insert(pe, &cnt, max_num); //�ڷ� �Է�
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
            ReqFromFile(pe, &cnt, max_num);
            break;
        case 6:
            saveFile(pe, &cnt);
            maintain = 0;
            break;
        }
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

void insert(TEL **pe, int *cnt, int max_num)
{
    if (*cnt >= max_num) //�ִ����尳�� �ʰ�
        printf("OVERFLOW\n");
    else
    {
        *(pe + *cnt) = NULL;
        *(pe + *cnt) = (TEL *)malloc(sizeof(TEL)); //�Է��� ���� �Ǿ����Ƿ� �����Ҵ� ���ش�.
        //��������� �Էµ� ������ŭ �����Ҵ��� �̷�� ����. �Է°���<=max_num
        TEL *put = *(pe + *cnt);

        char name[101] = {0}, phone[101] = {0}, birth[101] = {0}; //�ӽ÷� �Է� ���� �迭
        printf("Name:");                                          // ����
        scanf("%s", name);
        getchar();
        printf("Phone_number:"); // ����
        scanf("%s", phone);
        getchar();
        printf("Birth:"); //����
        scanf("%s", birth);
        getchar();

        put->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
        put->phone = (char *)malloc(sizeof(char) * (strlen(phone) + 1));
        put->birth = (char *)malloc(sizeof(char) * (strlen(birth) + 1));
        //�� �迭�� ũ�⸦ ���ϰ� �ش�ũ��+1��ŭ �����Ҵ� �Ѵ�.
        strcpy(put->name, name);
        strcpy(put->phone, phone);
        strcpy(put->birth, birth);

        (*cnt)++;                   //�ο��� ����
        printf("<< %d >>\n", *cnt); //�Էµ� �ο���
        sort(pe, cnt);              //�Էµ� �� ��ŭ �����Ͽ� �ش�.
    }
}

void sort(TEL **pe, int *cnt)
{
    for (int i = 0; i < *cnt - 1; i++) //���� ����
    {
        for (int j = 0; j < *cnt - i - 1; j++)
        {
            if (strcmp(pe[j]->name, pe[j + 1]->name) > 0) //�̸������� ����
            {
                TEL *tmp = pe[j];
                pe[j] = pe[j + 1];
                pe[j + 1] = tmp;
            }
        }
    }
}

void show(TEL **pe, int *cnt)
{
    for (TEL **p = pe; p < pe + *cnt; p++)
        printf("%s %s %s\n", (*p)->name, (*p)->phone, (*p)->birth);
}

void delete (TEL **pe, int *cnt)
{
    if (*cnt == 0) //����� ������ ������
        printf("NO MEMBER\n");
    else
    {
        printf("Name:"); // ����
        char tmp[21];
        scanf("%s", tmp);
        getchar();

        int found = 0;
        TEL **p;
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
            for (TEL **q = p; q < pe + *cnt - 1; q++)
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
}

void searchBirth(TEL **pe, int *cnt)
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

void ReqFromFile(TEL **pe, int *cnt, int max_num)
{
    FILE *fp = NULL;
    fp = fopen("PHONE_BOOK.txt", "r");
    if (fp != NULL)
    {
        while (1)
        {
            if (*cnt >= max_num)
            {
                printf("OVERFLOW\n");
                break;
            }
            char name[101] = {0}, phone[101] = {0}, birth[101] = {0};
            fscanf(fp, "%s %s %s", name, phone, birth);
            if (feof(fp))
                break;

            *(pe + *cnt) = NULL;
            *(pe + *cnt) = (TEL *)malloc(sizeof(TEL)); //�Է��� ���� �Ǿ����Ƿ� �����Ҵ� ���ش�.
            //��������� �Էµ� ������ŭ �����Ҵ��� �̷�� ����. �Է°���<=max_num
            TEL *put = *(pe + *cnt);
            put->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
            put->phone = (char *)malloc(sizeof(char) * (strlen(phone) + 1));
            put->birth = (char *)malloc(sizeof(char) * (strlen(birth) + 1));
            //�� �迭�� ũ�⸦ ���ϰ� �ش�ũ��+1��ŭ �����Ҵ� �Ѵ�.
            strcpy(put->name, name);
            strcpy(put->phone, phone);
            strcpy(put->birth, birth);

            (*cnt)++;
        }
        sort(pe, cnt);
        fclose(fp);
    }
}

void saveFile(TEL **pe, int *cnt)
{
    FILE *fp = NULL;
    fp = fopen("PHONE_BOOK.txt", "w");
    if (fp != NULL)
    {
        for (TEL **p = pe; p < pe + *cnt; p++)
            fprintf(fp, "%s %s %s\n", (*p)->name, (*p)->phone, (*p)->birth);
    }
    fclose(fp);
}
/*case1 �Է�)
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

case2 �Է�)
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

case3 �Է�)
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

case4�Է�)
//step3
5
1
Kim
00000000000
19980101
1
Gang
11101010101
19940101
1
Park
222333330101
20000101
2
6

-->case5(case4 ������ ���)
5
5
2
6
*/
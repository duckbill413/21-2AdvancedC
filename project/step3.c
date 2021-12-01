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
            insert(pe, &cnt, max_num); // 1. Registration
            break;
        case 2:
            show(pe, &cnt); // 2. ShowAll
            break;
        case 3:
            del(pe, &cnt); // 3. Delete
            break;
        case 4:
            searchBirth(pe, &cnt); // 4. FindByBirth
            break;
        case 5:
            ReqFromFile(pe, &cnt, max_num); // 5. ReqFromFile
            break;
        case 6:
            saveFile(pe, &cnt); // 6. Exit
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
        printf("Name:");
        scanf("%s", name);
        getchar();
        printf("Phone_number:");
        scanf("%s", phone);
        getchar();
        printf("Birth:");
        scanf("%s", birth);
        getchar();
        //�ڷḦ �Է�
        put->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
        put->phone = (char *)malloc(sizeof(char) * (strlen(phone) + 1));
        put->birth = (char *)malloc(sizeof(char) * (strlen(birth) + 1));
        //�� �迭�� ũ�⸦ ���ϰ� �ش�ũ��+1��ŭ �����Ҵ� �Ѵ�.
        strcpy(put->name, name);
        strcpy(put->phone, phone);
        strcpy(put->birth, birth);
        //����ü�� �ڷᰪ ����
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
    for (TEL **p = pe; p < pe + *cnt; p++) //��� ����ü�� �� ���
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
        scanf("%s", tmp); //������ �̸� �Է�
        getchar();

        int found = 0;
        TEL **p;
        for (p = pe; p < pe + *cnt; p++)
        {
            if (!strcmp((*p)->name, tmp)) //������ �̸��� ���� �ι� �߰�
            {
                found = 1; //�����ι� �߽߰� found = 1
                break;
            }
        }

        if (found) //�����ι� �߽߰� ����
        {
            for (TEL **q = p; q < pe + *cnt - 1; q++) //������ ���� �ױ��� ����
            {
                (*q)->name = (char *)realloc((*q)->name, sizeof(char) * (strlen((*(q + 1))->name) + 1));
                (*q)->phone = (char *)realloc((*q)->phone, sizeof(char) * (strlen((*(q + 1))->phone) + 1));
                (*q)->birth = (char *)realloc((*q)->birth, sizeof(char) * (strlen((*(q + 1))->birth) + 1));
                //�ڷ� �Է��� ���Ͽ� ���� ���� ũ�⸸ŭ ũ�⸦ ���Ҵ� ���ش�.
                strcpy((*q)->name, (*(q + 1))->name);
                strcpy((*q)->phone, (*(q + 1))->phone);
                strcpy((*q)->birth, (*(q + 1))->birth);
                //�������� �ڷḦ ������ �´�.
            }
            (*cnt)--;
            free(pe[*cnt]->name);
            free(pe[*cnt]->phone);
            free(pe[*cnt]->birth);
            free(pe[*cnt]);
            //������ ���� ����ü�� �� ����� �����Ҵ� �����Ͽ� �ش�.
        }
    }
}

void searchBirth(TEL **pe, int *cnt)
{
    printf("Birth:");
    int tmp;
    scanf("%d", &tmp); //ã�� ������ �Է�
    getchar();

    for (int i = 0; i < *cnt; i++)
    {
        int month = 0;
        for (char *search = pe[i]->birth + 4; search < pe[i]->birth + 6; search++)
            month = month * 10 + (*search - '0'); //������ ���� �ִ� 5,6�� ���ڸ� �̿��Ͽ� �� ���
        if (month == tmp)                         //������ ���� ���� ��� ���
            printf("%s %s %s\n", pe[i]->name, pe[i]->phone, pe[i]->birth);
    }
}

void ReqFromFile(TEL **pe, int *cnt, int max_num)
{
    FILE *fp = NULL;
    fp = fopen("PHONE_BOOK.txt", "r"); // PHONE_BOOK.txt�� read�Ѵ�.
    if (fp != NULL)                    // PHONE_BOOK.txt�� ������ ��� ����
    {
        while (1)
        {
            if (*cnt >= max_num) //�Է� ���� > max_num�� �Ƿ��ϸ� OVERFLOW ��°� �Բ� ����
            {
                printf("OVERFLOW\n");
                break;
            }
            char name[101] = {0}, phone[101] = {0}, birth[101] = {0};
            //�ڷḦ �ӽ÷� �Է� ���� �迭 ����
            fscanf(fp, "%s %s %s", name, phone, birth); //���Ϸ� ���� �ڷᰪ�� �о� �´�.
            if (feof(fp))                               //�Է� ���� �ڷᰡ ���� ��� ����
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
            //�ڷḦ ����ü�� �����Ѵ�.
            (*cnt)++; //�Է� ���� +1
        }
        sort(pe, cnt); //�Է¹��� ��� �ڷḦ ����
        fclose(fp);    //��������� ����
    }
}

void saveFile(TEL **pe, int *cnt)
{
    FILE *fp = NULL;
    fp = fopen("PHONE_BOOK.txt", "w"); // PHONE_BOOK.txt������ write���� ����
    if (fp != NULL)                    //���� ���� ������ ����
    {
        for (TEL **p = pe; p < pe + *cnt; p++) //����ü ������ ���Ͽ� �Է�
            fprintf(fp, "%s %s %s\n", (*p)->name, (*p)->phone, (*p)->birth);
    }
    fclose(fp); //��������� ����
}
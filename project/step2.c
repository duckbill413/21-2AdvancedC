#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct people
{                //연락처 구조체
    char *name;  //이름
    char *phone; //전화번호
    char *birth; //생년월일
} People;

void insert(People *pe, int *cnt);
void sort(People **pe, int *cnt);
void show(People **pe, int *cnt);
void delete (People **pe, int *cnt);
void searchBirth(People **pe, int *cnt);

int main()
{
    int max_num;
    printf("Max_num:"); // 고정
    scanf("%d", &max_num);

    People **pe = NULL;                                 // 이중 포인터 구조체
    pe = (People **)malloc(sizeof(People *) * max_num); // max_num의 개수만큼 동적할당
    if (pe == NULL)
        return -1;

    //안내 인터페이스
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
            if (cnt >= max_num) //입력개수 초과시 입력 불가
            {
                printf("OVERFLOW\n");
                continue;
            }
            *(pe + cnt) = NULL;
            *(pe + cnt) = (People *)malloc(sizeof(People)); //입력이 예정 되었으므로 동적할당 해준다.
            //결과적으로 입력된 개수만큼 동적할당이 이루어 진다. 입력개수<=max_num
            if (*(pe + cnt) == NULL) //실패시 종료
                return -1;

            insert(*(pe + cnt), &cnt); //자료 입력
            sort(pe, &cnt);
        }
        else if (select == 2) // ShowAll
        {
            show(pe, &cnt);
        }
        else if (select == 3) // Delete
        {
            if (cnt == 0) //저장된 정보가 없을때
            {
                printf("NO MEMBER\n");
                continue;
            }
            delete (pe, &cnt);
        }
        else if (select == 4) //생일 월 검색
        {
            searchBirth(pe, &cnt);
        }
        else if (select == 5) // Exit
            break;
    }

    for (int i = 0; i < cnt; i++) //각 정보에 대하여 동적할당 해제
    {
        free(pe[i]->name);
        free(pe[i]->birth);
        free(pe[i]->phone);
        free(pe[i]);
    }
    free(pe); // max_num 개수만큼 할당한 것에 대하여 동적할당 해제
}

void insert(People *pe, int *cnt)
{
    char name[101] = {0}, phone[101] = {0}, birth[101] = {0};
    printf("Name:"); // 고정
    scanf("%s", name);
    getchar();
    printf("Phone_number:"); // 고정
    scanf("%s", phone);
    getchar();
    printf("Birth:"); //고정
    scanf("%s", birth);
    getchar();

    pe->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
    pe->phone = (char *)malloc(sizeof(char) * (strlen(phone) + 1));
    pe->birth = (char *)malloc(sizeof(char) * (strlen(birth) + 1));
    strcpy(pe->name, name);
    strcpy(pe->phone, phone);
    strcpy(pe->birth, birth);

    (*cnt)++;                   //인원수 증가
    printf("<< %d >>\n", *cnt); //입력된 인원수
}

void sort(People **pe, int *cnt)
{
    for (int i = 0; i < *cnt - 1; i++) //버블 정렬
    {
        for (int j = 0; j < *cnt - i - 1; j++)
        {
            if (strcmp(pe[j]->name, pe[j + 1]->name) > 0) //이름순으로 정렬
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
    printf("Name:"); // 고정
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
    printf("Birth:"); // 고정
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
case1 입력)
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
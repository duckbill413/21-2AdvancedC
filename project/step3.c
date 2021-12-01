#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct people
{                //연락처 구조체
    char *name;  //이름
    char *phone; //전화번호
    char *birth; //생년월일
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
    printf("Max_num:"); // 고정
    scanf("%d", &max_num);

    TEL **pe = NULL;                              // 이중 포인터 구조체
    pe = (TEL **)malloc(sizeof(TEL *) * max_num); // max_num의 개수만큼 동적할당
    if (pe == NULL)
        return -1;
    //안내 인터페이스

    int select;
    int cnt = 0;      //전체 인원수 변수
    int maintain = 1; // while문 반복을 위한 변수
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

    for (int i = 0; i < cnt; i++) //각 정보에 대하여 동적할당 해제
    {
        free(pe[i]->name);
        free(pe[i]->birth);
        free(pe[i]->phone);
        free(pe[i]);
    }
    free(pe); // max_num 개수만큼 할당한 것에 대하여 동적할당 해제
}

void insert(TEL **pe, int *cnt, int max_num)
{
    if (*cnt >= max_num) //최대저장개수 초과
        printf("OVERFLOW\n");
    else
    {
        *(pe + *cnt) = NULL;
        *(pe + *cnt) = (TEL *)malloc(sizeof(TEL)); //입력이 예정 되었으므로 동적할당 해준다.
        //결과적으로 입력된 개수만큼 동적할당이 이루어 진다. 입력개수<=max_num
        TEL *put = *(pe + *cnt);

        char name[101] = {0}, phone[101] = {0}, birth[101] = {0}; //임시로 입력 받을 배열
        printf("Name:");
        scanf("%s", name);
        getchar();
        printf("Phone_number:");
        scanf("%s", phone);
        getchar();
        printf("Birth:");
        scanf("%s", birth);
        getchar();
        //자료를 입력
        put->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
        put->phone = (char *)malloc(sizeof(char) * (strlen(phone) + 1));
        put->birth = (char *)malloc(sizeof(char) * (strlen(birth) + 1));
        //각 배열의 크기를 구하고 해당크기+1만큼 동적할당 한다.
        strcpy(put->name, name);
        strcpy(put->phone, phone);
        strcpy(put->birth, birth);
        //구조체에 자료값 복사
        (*cnt)++;                   //인원수 증가
        printf("<< %d >>\n", *cnt); //입력된 인원수
        sort(pe, cnt);              //입력된 수 만큼 정렬하여 준다.
    }
}

void sort(TEL **pe, int *cnt)
{
    for (int i = 0; i < *cnt - 1; i++) //버블 정렬
    {
        for (int j = 0; j < *cnt - i - 1; j++)
        {
            if (strcmp(pe[j]->name, pe[j + 1]->name) > 0) //이름순으로 정렬
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
    for (TEL **p = pe; p < pe + *cnt; p++) //모든 구조체의 항 출력
        printf("%s %s %s\n", (*p)->name, (*p)->phone, (*p)->birth);
}

void delete (TEL **pe, int *cnt)
{
    if (*cnt == 0) //저장된 정보가 없을때
        printf("NO MEMBER\n");
    else
    {
        printf("Name:"); // 고정
        char tmp[21];
        scanf("%s", tmp); //삭제할 이름 입력
        getchar();

        int found = 0;
        TEL **p;
        for (p = pe; p < pe + *cnt; p++)
        {
            if (!strcmp((*p)->name, tmp)) //삭제할 이름과 동일 인물 발견
            {
                found = 1; //동일인물 발견시 found = 1
                break;
            }
        }

        if (found) //동일인물 발견시 실행
        {
            for (TEL **q = p; q < pe + *cnt - 1; q++) //마지막 전의 항까지 실행
            {
                (*q)->name = (char *)realloc((*q)->name, sizeof(char) * (strlen((*(q + 1))->name) + 1));
                (*q)->phone = (char *)realloc((*q)->phone, sizeof(char) * (strlen((*(q + 1))->phone) + 1));
                (*q)->birth = (char *)realloc((*q)->birth, sizeof(char) * (strlen((*(q + 1))->birth) + 1));
                //자료 입력을 위하여 다음 항의 크기만큼 크기를 재할당 해준다.
                strcpy((*q)->name, (*(q + 1))->name);
                strcpy((*q)->phone, (*(q + 1))->phone);
                strcpy((*q)->birth, (*(q + 1))->birth);
                //다음항의 자료를 복사해 온다.
            }
            (*cnt)--;
            free(pe[*cnt]->name);
            free(pe[*cnt]->phone);
            free(pe[*cnt]->birth);
            free(pe[*cnt]);
            //마지막 항의 구조체와 그 멤버를 동적할당 해제하여 준다.
        }
    }
}

void searchBirth(TEL **pe, int *cnt)
{
    printf("Birth:");
    int tmp;
    scanf("%d", &tmp); //찾을 생일을 입력
    getchar();

    for (int i = 0; i < *cnt; i++)
    {
        int month = 0;
        for (char *search = pe[i]->birth + 4; search < pe[i]->birth + 6; search++)
            month = month * 10 + (*search - '0'); //생일의 월이 있는 5,6번 문자를 이용하여 월 계산
        if (month == tmp)                         //생일인 월이 같을 경우 출력
            printf("%s %s %s\n", pe[i]->name, pe[i]->phone, pe[i]->birth);
    }
}

void ReqFromFile(TEL **pe, int *cnt, int max_num)
{
    FILE *fp = NULL;
    fp = fopen("PHONE_BOOK.txt", "r"); // PHONE_BOOK.txt를 read한다.
    if (fp != NULL)                    // PHONE_BOOK.txt가 존재할 경우 실행
    {
        while (1)
        {
            if (*cnt >= max_num) //입력 개수 > max_num이 되려하면 OVERFLOW 출력과 함께 종료
            {
                printf("OVERFLOW\n");
                break;
            }
            char name[101] = {0}, phone[101] = {0}, birth[101] = {0};
            //자료를 임시로 입력 받을 배열 선언
            fscanf(fp, "%s %s %s", name, phone, birth); //파일로 부터 자료값을 읽어 온다.
            if (feof(fp))                               //입력 받은 자료가 없을 경우 종료
                break;

            *(pe + *cnt) = NULL;
            *(pe + *cnt) = (TEL *)malloc(sizeof(TEL)); //입력이 예정 되었으므로 동적할당 해준다.
            //결과적으로 입력된 개수만큼 동적할당이 이루어 진다. 입력개수<=max_num
            TEL *put = *(pe + *cnt);
            put->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
            put->phone = (char *)malloc(sizeof(char) * (strlen(phone) + 1));
            put->birth = (char *)malloc(sizeof(char) * (strlen(birth) + 1));
            //각 배열의 크기를 구하고 해당크기+1만큼 동적할당 한다.
            strcpy(put->name, name);
            strcpy(put->phone, phone);
            strcpy(put->birth, birth);
            //자료를 구조체에 복사한다.
            (*cnt)++; //입력 개수 +1
        }
        sort(pe, cnt); //입력받은 모든 자료를 정렬
        fclose(fp);    //파일입출력 종료
    }
}

void saveFile(TEL **pe, int *cnt)
{
    FILE *fp = NULL;
    fp = fopen("PHONE_BOOK.txt", "w"); // PHONE_BOOK.txt파일을 write모드로 연다
    if (fp != NULL)                    //파일 열시 성공시 실행
    {
        for (TEL **p = pe; p < pe + *cnt; p++) //구조체 정보를 파일에 입력
            fprintf(fp, "%s %s %s\n", (*p)->name, (*p)->phone, (*p)->birth);
    }
    fclose(fp); //파일입출력 종료
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct people
{                   //연락처 구조체
    char name[21];  //이름
    char phone[16]; //전화번호
    char birth[9];  //생년월일
} People;

void insert(People *pe, int *cnt);
void sort(People *pe, int *cnt);
void delete (People *pe, int *cnt);
void searchBirth(People *pe, int *cnt);
void show(People *pe, int *cnt);

int main()
{
    People pe[100]; // 100명의 정보 저장 가능
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
            if (cnt > 100) //최대 저장 개수 초과
            {
                printf("OVERFLOW\n");
                continue;
            }
            insert(pe, &cnt); //자료 입력 및 정렬 수행
        }
        else if (select == 2) // ShowAll
        {
            show(pe, &cnt);
        }
        else if (select == 3) // delete
        {
            if (cnt == 0) //저장된 정보가 없을때
            {
                printf("NO MEMBER\n");
                continue; //처음 메뉴로 이동
            }
            delete (pe, &cnt);
        }
        else if (select == 4) //생일월 찾기
        {
            searchBirth(pe, &cnt);
        }
        else if (select == 5) //종료
            break;
    }
}

void insert(People *pe, int *cnt)
{
    printf("Name:"); // 고정
    scanf("%s", pe[*cnt].name);
    getchar();
    printf("Phone_number:"); // 고정
    scanf("%s", pe[*cnt].phone);
    getchar();
    printf("Birth:"); //고정
    scanf("%s", pe[*cnt].birth);
    getchar();
    (*cnt)++;                   //인원수 증가
    printf("<< %d >>\n", *cnt); //입력된 인원수
    sort(pe, cnt);              //오름차순 정렬
}

void sort(People *pe, int *cnt)
{
    for (int i = 0; i < *cnt - 1; i++) //버블 정렬
    {
        for (int j = 0; j < *cnt - i - 1; j++)
        {
            if (strcmp(pe[j].name, pe[j + 1].name) > 0) //이름순으로 정렬
            {
                People tmp = pe[j];
                pe[j] = pe[j + 1];
                pe[j + 1] = tmp;
            }
        }
    }
}

void show(People *pe, int *cnt) //전체 멤버 보기
{
    for (int i = 0; i < *cnt; i++)
    {
        printf("%s %s %s\n", pe[i].name, pe[i].phone, pe[i].birth); //전체 멤버 출력
    }
}
void delete (People *pe, int *cnt) //멤버 삭제
{
    printf("Name:"); // 고정
    char tmp[21];
    scanf("%s", tmp); //이름 입력 받기
    getchar();

    int found = 0;
    for (int i = 0; i < *cnt; i++)
    {
        if (!strcmp(pe[i].name, tmp)) //일치한 이름 존재 할시
        {
            found = 1;
        }
        if (found)
        {
            pe[i] = pe[i + 1]; //존재 부터 끝까지 멤버를 하나씩 당겨온다.
        }
    }
    if (found)
        (*cnt)--; //개수 하나 감소
}

void searchBirth(People *pe, int *cnt) //생일 월 찾기
{
    printf("Birth:"); // 고정
    int tmp;
    scanf("%d", &tmp); //생일 값 입력
    getchar();

    for (int i = 0; i < *cnt; i++)
    {
        int month = 0;
        for (char *search = pe[i].birth + 4; search < pe[i].birth + 6; search++) //구조체 생일에 대하여 월 값을 정수로 바꾸어준다.
            month = month * 10 + (*search - '0');
        if (month == tmp) //정수로 바꾼 값이 찾는 월과 일치시 출력
            printf("%s %s %s\n", pe[i].name, pe[i].phone, pe[i].birth);
    }
}
/*
case1 입력)
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

case2 입력)
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
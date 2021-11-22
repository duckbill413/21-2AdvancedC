//!!동적할당, 자기참조 구조체
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct customer
{
    char id[5];            //고객 아이디
    char *name;            //고객 이름
    char *phone;           //고객 전화번호
    struct customer *next; //마지막 숫자가 같은 고객 주소
} Customer;

int main()
{
    int N;
    scanf("%d", &N); //입력할 횟수 N을 입력받는다
    getchar();       //버퍼 삭제

    Customer *cs = NULL;
    if ((cs = (Customer *)malloc(sizeof(Customer) * N)) == NULL)
        return -1; //고객 정보 구조체를 N개 만큼 할당하고 실패시 종료

    for (Customer *pcs = cs; pcs < cs + N; pcs++) //고객 정보 입력
    {
        char tmp[101]; //임시 문자열 입력
        gets(tmp);

        int size = 0, chap = 0;                                   // chap은 단계 변수
        for (char *ptmp = tmp; ptmp <= tmp + strlen(tmp); ptmp++) //문자열 탐색
        {
            if (*ptmp == ' ' || *ptmp == 0) //문자가 공백, 종료 문자 일시
            {
                if (chap == 0) //고객 이름 입력
                {
                    pcs->name = NULL;
                    if ((pcs->name = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
                        return -1;                         //고객 이름에 대하여 size만큼 동적할당 하고 실패시 종료
                    strncpy(pcs->name, ptmp - size, size); //고객이름 size만큼 입력
                    pcs->name[size] = 0;                   //마지막에 종료문자
                    size = -1;
                    chap++; //다음 단계
                }
                else if (chap == 1) //고객전화번호 입력
                {
                    pcs->phone = NULL;
                    if ((pcs->phone = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
                        return -1;                          //사이즈에 대하여 고객 전화번호를 할당하고 실패시 종료
                    strncpy(pcs->phone, ptmp - size, size); //고객 전화번호 입력
                    pcs->phone[size] = 0;                   //마지막에 종료 문자 입력

                    strcpy(pcs->id, ptmp - 4); // id에 종료문자로 부터 마지막 4개 번호 입력
                    size = -1;
                    chap++;
                }
                if (*ptmp == 0) //종료 문자가 나올경우 next주소 입력
                {
                    pcs->next = NULL;                               //아무도 없을 경우를 위해 NULL로 초기화
                    for (Customer *qcs = pcs - 1; qcs >= cs; qcs--) //현재부터 역 탐색
                    {
                        if (qcs->id[3] == pcs->id[3]) //마지막 숫자가 같을때
                        {
                            qcs->next = pcs; //이전 고객의 next에 현재 입력받은 고객 구조체 주소 할당
                            break;
                        }
                    }
                }
            }
            size++;
        }
    }

    char find[5]; //찾고자하는 고객 번호 입력
    scanf("%s", &find);
    int cnt = 1;                                  //몇 번째 인지 나타내주기 위한 변수
    for (Customer *pcs = cs; pcs < cs + N; pcs++) //고객에 대하여 탐색
    {
        if (find[3] == pcs->id[3]) //찾는 고객 번호의 마지막 숫자가 같을때 부터 next로 탐색하여 검색 횟주를 줄인다.
        {
            while (1)
            {
                if (!strcmp(pcs->id, find)) // id와 find가 같으면 찿은 정보 출력
                {
                    printf("%s %s %d", pcs->name, pcs->phone, cnt);
                }
                if (pcs->next == NULL) // next값이 NULL이면 이후가 없으므로 종료
                    break;
                pcs = pcs->next; //찾지 못한 경우 next 주소를 옮겨준다.
                cnt++;           //카운트 증가
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        free(cs[i].name);  //고객 이름 메모리 해제
        free(cs[i].phone); //고객 전화번호 메모리 해제
    }
    free(cs); //고객 구조체 메모리 해제
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tourcity //여행지 구조체 생성
{
    char name[21]; //관광지명
    int fee;       //입장료
    char inout;    //야외/실내 구분
    char date[9];  //관광지 시작 일
} Tourcity;

int main()
{
    int N;
    scanf("%d", &N); //도시의 개수
    getchar();       //버퍼 제거

    char **place = NULL;
    if ((place = (char **)malloc(sizeof(char *) * N)) == NULL) //도시 이름 입력을 위한 이중 배열 선언
    {
        printf("Not Enough Memory."); //실패시 에러문 출력 후 종료
        return -1;
    }
    char **pplace = place;

    char tmp[100];
    gets(tmp); //도시명 문자열 입력

    int size = 0;
    for (char *ptmp = tmp; ptmp <= tmp + strlen(tmp); ptmp++)
    {
        if (*ptmp == ' ' || *ptmp == '\0') //공백, 종료 문자가 나오면
        {
            *pplace = NULL;
            if ((*pplace = (char *)malloc(sizeof(char) * (size + 1))) == NULL) //도시이름 배열 동적할당
            {
                printf("Not Enough Memory."); //실패시 에러문과 종료
                return -1;
            }

            strncpy(*pplace, ptmp - size, size); // tmp문자열을 size만큼 복사
            *(*pplace + size) = '\0';            //마지막에 종료 문자 삽입
            pplace++;                            //도시 주소 이동
            size = -1;
        }
        size++;
    }

    int *num = NULL;                                    //각 도시에 대한 관광지 개수 입력
    if ((num = (int *)malloc(sizeof(int) * N)) == NULL) // N개 만큼 동적 할당
    {
        printf("Not Enough Memory."); //실패시 에러 출력 후 종료
        return -1;
    }

    for (int *pnum = num; pnum < num + N; pnum++)
    {
        scanf("%d", pnum); //각 도시에 대한 관광지 개수 입력
    }
    getchar(); //버퍼 제거

    Tourcity **ptr = NULL;
    if ((ptr = (Tourcity **)malloc(sizeof(Tourcity *) * N)) == NULL) //관광지를 이중포인터 사용하여 동적 할당
    {
        printf("Not Enough Memory."); //동적할당 실패시 에러후 종료
        return -1;
    }

    for (Tourcity **pptr = ptr; pptr < ptr + N; pptr++) // N개 도시에 대한 관광지 탐색
    {
        *pptr = NULL;
        if ((*pptr = (Tourcity *)malloc(sizeof(Tourcity) * num[pptr - ptr])) == NULL) // N개 도시에 대하여 각각의 관광지 개수만큼 동적할당
        {
            printf("Not Enough Memory."); //실패시 에러, 종료
            return -1;
        }
        for (Tourcity *qptr = *pptr; qptr < *pptr + num[pptr - ptr]; qptr++) //관광지 개수 만큼 탐색
        {
            gets(tmp);              //문자열 입력
            int size = 0, chap = 0; // chap은 단계를 위한 변수
            for (char *ptmp = tmp; ptmp <= tmp + strlen(tmp); ptmp++)
            {
                if (*ptmp == ' ' || *ptmp == 0) //문자열에 공백, 종료 문자
                {
                    if (chap == 0) //관광지명 입력
                    {
                        strncpy(qptr->name, ptmp - size, size); // size만큼 복사
                        qptr->name[size] = 0;                   //마지막에 종료문자
                        size = -1;
                        chap++; //다음 단계
                    }
                    else if (chap == 1) //요금 정보 입력
                    {
                        int sum = 0;
                        for (char *p = ptmp - size; p < ptmp; p++) //문자를 입력 받아 정수로 바꿔준다.
                        {
                            sum = sum * 10 + (*p - '0');
                        }
                        qptr->fee = sum; //요금에 바꾼 정수 입력
                        chap++;          //다음 단계

                        size = -1;
                    }
                    else if (chap == 2) //야외/실내 정보 입력
                    {
                        qptr->inout = *(ptmp - 1); //공백 전 문자에 구분이 입력되므로 해당 문자를 입력
                        chap++;                    //다음 단계
                        size = -1;
                    }
                    else if (chap == 3) // 8개 관광지 시작일 입력
                    {
                        strncpy(qptr->date, ptmp - size, size); //사이즈==8 만큼 정보 입력
                        qptr->date[8] = 0;                      //마지막 종료 문자
                        size = -1;
                    }
                }
                size++;
            }
        }
    }

    Tourcity *ex = *ptr;                                //찾는 관광지 변수 초기값으로 처음 관광지 입력
    int ex_place = 0;                                   //도시 위치 변수
    for (Tourcity **pptr = ptr; pptr < ptr + N; pptr++) // N개 도시에 대하여 탐색
    {
        for (Tourcity *qptr = *pptr; qptr < *pptr + *(num + (pptr - ptr)); qptr++) // num개 관광지에 대하여 탐색
        {
            if (qptr->fee > ex->fee) //요금이 ex보다 클때
            {
                *ex = *qptr;           //구조체 정보 복사
                ex_place = pptr - ptr; //도시 정보 입력
            }
            else if (qptr->fee == ex->fee && strcmp(qptr->date, ex->date) < 0) //요금이 같을때 관광지 시작일에 대하여 오래된것을 찾는다.
            {
                *ex = *qptr;           //구조체 정보 복사
                ex_place = pptr - ptr; //도시 정보 입력
            }
        }
    }

    printf("%s %s %d %s %c", place[ex_place], ex->name, ex->fee, ex->date, ex->inout);
    //찾은 도시 정보를 입력, ex구조체 정보 입력

    //도시 정보 메모리 해제
    for (int i = 0; i < N; i++)
        free(place[i]);
    free(place);
    //관광지 정보 메모리 해제
    for (int i = 0; i < N; i++)
        free(ptr[i]);
    free(ptr);
    free(num); //도시별 관광지 정보 개수 메모리 해제

    return 0;
}

/*
test case)
3
Seoul Busan Yeosu
3 1 2
Coex 0 I 19970513
Duksugung 2000 O 20000101
Museum 1500 I 19950323
Haewoondae 0 O 19940830
Haetul 2500 B 20010305
SeaHouse 5500 O 19851201

result)
Yeosu SeaHouse 5500 19851201 O
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st
{
    //구조체 st 선언
    char *str; //문자열 저장
    int cnt;   //자음 수 저장
    int cnt2;  //모음 수 저장
} ST;          //구조체st를 ST로 재정의

void numOfComponent(ST *); //자음수, 모음수를 저장할 함수

int main()
{
    int N;
    scanf("%d", &N);
    getchar();
    // N번 실행을 위한 변수 선언 및 입력

    ST *st = NULL;
    st = (ST *)malloc(sizeof(ST) * N); // N개 만큼 ST구조체 동적할당
    if (st == NULL)
        return -1; //동적할당 실패시 종료

    for (ST *pst = st; pst < st + N; pst++) // N번 만큼 실행
    {
        char tmp[101];
        scanf("%s", tmp);
        getchar();
        //임시 배열을 통해 문자열을 입력 받고 버퍼 삭제
        int size = strlen(tmp);
        pst->str = NULL;
        pst->str = (char *)malloc(sizeof(char) * (size + 1)); //구조체 문자열에 문자개수+1개만큼 동적할당
        if (pst->str == NULL)
            return -1; //동적할당 실패시 종료

        strcpy(pst->str, tmp); //구조체 문자열에 tmp문자열을 복사
        numOfComponent(pst);   //자음수, 모음수를 저장할 함수
    }

    for (ST *pst = st; pst < st + N - 1; pst++) //버블 정렬 사용
    {
        for (ST *qst = st; qst < st + N - (pst - st) - 1; qst++)
        {
            if (qst->cnt < (qst + 1)->cnt) //자음의 개수 비교
            {                              //내림차순으로 swap하여 정렬
                ST tmp = *qst;
                *qst = *(qst + 1);
                *(qst + 1) = tmp;
            }
            else if (qst->cnt == (qst + 1)->cnt && qst->cnt2 < (qst + 1)->cnt2)
            { //자음의 개수가 같으면 모음의 개수로 비교 내림차순 정렬
                ST tmp = *qst;
                *qst = *(qst + 1);
                *(qst + 1) = tmp;
            }
        }
    }

    for (ST *pst = st; pst < st + N; pst++)
        printf("%s\n", pst->str); //구조체 문자열의 결과값을 출력

    for (int i = 0; i < N; i++)
        free((st + i)->str); //구조체 문자열을 free해준다
    free(st);                // st구조체를 free해준다.
    return 0;
}

void numOfComponent(ST *st)
{
    int cnt_vowel = 0; //모음의 개수 카운트

    for (char *p = st->str; p < st->str + strlen(st->str); p++) //구조체의 문자열을 검색
    {
        if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'u' || *p == 'o' ||
            *p == 'A' || *p == 'E' || *p == 'I' || *p == 'U' || *p == 'O') //모음일 경우
            cnt_vowel++;                                                   //모음 개수++
    }
    st->cnt2 = cnt_vowel;                  //모음 수를 저장 한다
    st->cnt = strlen(st->str) - cnt_vowel; //자음의 수는 전체 문자수 - 모음수;
}

/*
5
History
Politics
DonQuixote
LaPeste
Chaos

DonQuixote // 자음의 수가 같으면
Politics // 모음의 수 기준으로 출력
History
LaPeste
Chaos
*/
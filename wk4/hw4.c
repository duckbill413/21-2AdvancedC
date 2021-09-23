#include <stdio.h>
#include <string.h>

int s_check(char *p, char *q); //s_check 함수 원형 선언

int main()
{
    int m, k1, k2;                   //정수m, k1, k2 선언
    scanf("%d %d %d", &m, &k1, &k2); //m, k1, k2입력
    getchar();                       //enter문자 삭제
    for (int i = 0; i < m; i++)      //m번 만큼 반복
    {
        char ch[201] = "";                             //문자열 ch[201]선언
        gets(ch);                                      //문자열에 문자 입력
        if (s_check(ch + k1, ch + k2) != 0)            //소문자의 개수가 0개가 아닐때
            printf("%d\n", s_check(ch + k1, ch + k2)); //s_check함수를 이용하여 소문자의 개수 출력
    }

    return 0;
}

int s_check(char *p, char *q) //s_check함수 선언
{
    char cnt[201] = "";                  //소문자를 입력할 배열 선언
    int i = 0;                           //위치 변수
    for (char *pch = p; pch <= q; pch++) //포인터 주소 p부터 시작하여 q까지의 문자 탐색
    {
        if (*pch >= 'a' && *pch <= 'z') //문자가 소문자일 경우
        {
            cnt[i++] = *pch; //cnt배열에 소문자를 입력하고 위치 이동
        }
    }
    return strlen(cnt); //입력된 소문자의 개수 출력을 위해 strlen으로 cnt배열의 크기 반환
}
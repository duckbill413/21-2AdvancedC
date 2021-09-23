#include <stdio.h>
#include <string.h>

int main()
{
    char ch[1001] = "";
    char *pch[100];                            //배열 ch와 포인트 배열 선언
    int k;                                     //조건 k변수 선언
    gets(ch);                                  //문자열 입력
    scanf("%d", &k);                           //조건 변수 입력
    int size = 0;                              //단어의 크기
    int word = 0;                              //단어의 개수
    int ch_size = strlen(ch);                  //초기 문자 배열의 크기
    for (char *p = ch; p <= ch + ch_size; p++) //포인터를 사용 문자열 확인
    {
        if (*p == ' ' || *p == '\0') //공백혹은 종료 문자인 경우
        {
            pch[word] = p - size;       //포인터 배열에 단어 시작 주소 저장
            *(pch[word] + size) = '\0'; //마지막에 종료문자 저장
            word++;                     //단어 개수 증가
            size = -1;                  //사이즈 초기화
        }
        size++;
    }

    for (int i = 0; i < word - 1; i++) //버블 정렬
    {
        for (int j = 0; j < word - i - 1; j++)
        {
            if (strlen(pch[j]) < strlen(pch[j + 1])) //뒤의 단어가 더 길경우
            {
                char *tmp = pch[j];
                pch[j] = pch[j + 1];
                pch[j + 1] = tmp; //뒤의 단어가 더 기면 순서를 바꿔서 앞으로 보냄
            }
            if (strlen(pch[j]) == strlen(pch[j + 1])) //단어의 길이가 같을 경우
            {
                if (strcmp(pch[j], pch[j + 1]) > 0) //문자열을 확인하여 앞이 더 뒤의 문자인 경우
                {
                    char *tmp = pch[j]; //포인터 사용
                    pch[j] = pch[j + 1];
                    pch[j + 1] = tmp; //문자열 주소 교환
                }
            }
        }
    }

    puts(pch[k - 1]); //k번쨰 주소의 문자열 출력

    return 0;
}
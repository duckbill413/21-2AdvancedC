#include <stdio.h>
#include <string.h>

int main()
{
    char ch1[100] = "";
    char ch2[100] = "";
    //문자열 A, B선언
    gets(ch1);
    gets(ch2); //A,B문자열 입력

    int cnt = 0;                                              //같은 문자의 개수 카운팅 변수
    int size = 0;                                             //단어의 문자수 카운팅
    for (char *pch1 = ch1; pch1 <= ch1 + strlen(ch1); pch1++) //포인터를 이용하여 ch1의 처음부터 끝까지 살핌
    {
        if (*pch1 == ' ' || *pch1 == '.' || *pch1 == '\0') //공백, 마침표, 종료 문자일 경우 확인
        {
            if (size == strlen(ch2)) //사이즈가 B문자의 크기와 같을 경우
            {
                if (!strncmp(pch1 - strlen(ch2), ch2, strlen(ch2))) //ch2와 ch2문자의 개수만큼 비교하여 완전히 일치할 경우
                                                                    //이떄 확인 시작 주소는 pch1-ch2의길이 부터 체크해야 함
                    cnt++;                                          //완전히 일치시 카운트 해준다
            }
            size = -1; //뒤에 size++이 있으므로 -1로 저장
        }
        size++; //공백, 마침표 종료문자가 아닐경우 size증가
    }
    printf("%d", cnt); //카운트한 값 출력

    return 0;
}
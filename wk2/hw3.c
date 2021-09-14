#include <stdio.h>

int main()
{
    char ch[101] = ""; //문자를 입력받을 ch배열
    int size = 0;      //실제 사용할 크기
    for (char *pch = ch; pch < ch + 101; pch++)
    {
        scanf("%c", pch); //포인터를 이용하여 ch배열에 값 입력
        if (*pch == '#')  //#이 입력되면 종료
            break;
        size++; //#이 입력되기 전 까지의 크기를 구한다.
    }
    int max = 0;
    //문자의 크기와 최대 크기를 위한 정수 선언 및 0으로 초기화
    int cnt = 0;
    char word[101] = "";
    char *pword = word;

    for (char *pch = ch; pch <= ch + size; pch++)
    {
        if (*pch >= 'a' && *pch <= 'z')
        { //문자가 소문자일 경우
            // if (cnt == 0 && pch != ch) //cnt가 0이며 처음이 아닐 경우
            //     printf("\n");          //새로운 문자의 시작이므로 개행 해준다.
            // printf("%c", *pch);        //소문자일 경우 출력
            // cnt++;                     //문자의 개수 카운트
            *pword++ = *pch;
            cnt++;
        }
        else //소문자가 아닐 경우
        {
            if (pword != word)
            {
                for (pword = word; pword < word + cnt; pword++)
                {
                    printf("%c", *pword);
                }
                printf("\n");
                if (max < cnt) //max보다 cnt가 크면 max = cnt
                    max = cnt;
                cnt = 0;
                pword = word;
            }
        }
    }
    printf("%d", max); //최대 문자길이 출력
    return 0;
}
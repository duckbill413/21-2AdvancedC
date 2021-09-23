#include <stdio.h>
#include <string.h>
int change(char[], char[]); //문자열을 변환 시켜주는 함수 선언
int main()
{
    char ch1[100] = "";
    char ch2[100] = "";
    //문자열을 입력받기위한 문자열 배열 ch1, ch2선언
    gets(ch1);
    gets(ch2);
    //gets를 이용하여 공백이 있는 문자열을 입력받는다.
    if (change(ch1, ch2)) //A->B가 가능한 경우
        printf("1");
    else if (change(ch2, ch1)) //B->A가 가능한 경우
        printf("2");
    else
        printf("0"); //A->B, B->A 모두 불가능한 경우

    return 0;
}

int change(char ch1[], char ch2[]) //ch1을 변환하고 ch2와 일치할 경우 1아닐경우 0 반환 함수 생성
{
    int n, i = 0; //n:이동 문자 수, i: while문 실행을 위함
    while (1)
    {
        if (ch1[i] >= 'A' && ch1[i] <= 'Z') //찾은 문자가 대문자인 경우
        {
            n = ch2[i] - ch1[i]; //동일한 위치의 ch2-ch1을 하여 n을 구함
            break;               //n을 구하고 중지
        }
        if (ch1[i] >= 'a' && ch1[i] <= 'z') //찾은 문자가 소문자인 경우
        {
            n = ch1[i] - ch2[i]; //동일한 위치의 ch1-ch2을 하여 n을 구함
            break;               //n을 구하고 중지
        }
        i++; //찾은 문자가 소문자, 대문자가 아닌경우 다음 문자를 찾는다.
    }
    if (n < 0) //n이 음수가 나올경우 ch2의 문자가 ch1보다 앞에 있으므로 0을 리턴하고 함수 종료
        return 0;

    for (char *pch = ch1; pch < ch1 + strlen(ch1); pch++) //ch1 배열을 이용하며 크기가 유동적이므로 strlen(ch1) 사용
    {
        if (*pch >= 'A' && *pch <= 'Z') //문자가 대문자인 경우 n번째 뒤 문자로 변환
            *pch = *pch + n;
        else if (*pch >= 'a' && *pch <= 'z') //문자가 소문자인 경우 n번째 앞 문자로 변환
            *pch = *pch - n;
        else if (*pch >= '0' && *pch <= '9') //문자가 숫자인 경우
        {
            int flag = 1;                               //숫자가 한자리 인경우
            int num = (int)(*pch) - '0';                //찾는 문자을 정수화 함
            if (*(pch + 1) >= '0' && *(pch + 1) <= '9') //그 다음 문자를 확인해서 문자가 숫자인 경우
            {
                num = num * 10 + (int)(*(pch + 1)) - '0'; //이전 찾은 숫자*10을 하여 자릿수를 높이고 찾은 문자를 정수화
                flag = 2;                                 //숫자가 두자리 인경우
            }

            char plus[11];                          //n은 최대 10이므로 11 크기 할당
            for (char *p = plus; p < plus + n; p++) //plus배열에 문자 할당 n번 반복
                *p = 'A' + num - 1;                 //A문자로 부터 num번째 떨어진 문자를 찾아 입력한다.
            plus[n] = '\0';                         //plus의 마지막에 문자열 종료 문자를 넣어준다.

            char tmp[100] = "";              //문자열을 합칠 입시 배열 선언
            strncpy(tmp, ch1, pch - ch1);    //tmp에 ch1의 숫자 이전까지 문자들을 넣어줌
            strcat(tmp, plus);               //tmp에 plus 문자열을 합쳐준다.
            strcat(tmp, pch + flag);         //tmp에 이미 합쳐진 문자 다음 문자들을 넣어준다.
            tmp[strlen(ch1) + n - 1] = '\0'; //ch1의 개수는 n-1개만 큼 늘어나므로 마지막에 종료 문자를 넣는다.
            strcpy(ch1, tmp);                //ch1에 tmp를 넣는다.

            pch += n - 1; //n개 만큼 뒤부터 문자를 확인해주면 된다.
        }
        else //그 외의 문자일 경우 공백으로 변경
            *pch = ' ';
    }
    if (!strcmp(ch1, ch2)) //ch1과 ch2가 같으면 1반환
        return 1;
    else
        return 0; //다르면 0반환
}
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
    puts(pch[k - 1]); //k번째 문자열 출력
    char *sort[100];  //조건에 맞는 문자 포인터 배열
    int size2 = 0;    //조건에 문는 문자의 개수

    int found = 0;
    for (char *p = ch; p <= ch + ch_size;) //초기 문자열 부터 확인하기 위함
    {
        int cnt = 0; //일치하는 문자의 개수
        int no = 0;  //불일치하는 문자의 개수

        if (p == pch[k - 1])       //찾는 주소가 k번째 문자열의 주소와 일치하는 경우
            p = p + strlen(p) + 1; //찾을 필요가 없으므로 다음 단어 위치로 주소 변경

        for (char *q = p; q < p + strlen(p); q++) //일치하는 단어를 찾기 위함
        {
            found = 0;                                                                    //단어를 찾는 다면 1로 변환
            for (char *p_ch = pch[k - 1]; p_ch < pch[k - 1] + strlen(pch[k - 1]); p_ch++) //k문자를 확인 한다.
            {
                if (*q == *p_ch) //k문자열에 찾는 문자가 존재 할시
                {
                    cnt++;     //조건에 맞는 문자 개수 상승
                    found = 1; //찾았으므로 found 1로 변경
                }
            }
            if (found == 0) //찾지 못하였을 경우
                no++;       //불일치 변수 상승
        }
        //printf("cnt no strlen:%d %d %d\n", cnt, no, strlen(pch[k - 1]));
        if ((cnt >= strlen(pch[k - 1]) - 1 && cnt <= strlen(pch[k - 1]) + 1) && no < 2)
        {                      //cnt의 개수가 k문자열의수 +-1일때 와 no가 2개 이하일때 조건 1, 2가 성립
            sort[size2++] = p; //sort포인터 배열에 p문자열의 첫주소를 저장하고 개수 증가
        }
        p = p + strlen(p) + 1; //공백 다음의 문자열로 찾는 주소를 이동
    }

    for (int i = 0; i < size2 - 1; i++) //버블 정렬
    {
        for (int j = 0; j < size2 - i - 1; j++)
        {
            if (strlen(sort[j]) < strlen(sort[j + 1])) //뒤의 단어가 더 길경우
            {
                char *tmp = sort[j];
                sort[j] = sort[j + 1];
                sort[j + 1] = tmp; //뒤의 단어가 더 기면 순서를 바꿔서 앞으로 보냄
            }
            if (strlen(sort[j]) == strlen(sort[j + 1])) //단어의 길이가 같을 경우
            {
                if (strcmp(sort[j], sort[j + 1]) > 0) //문자열을 확인하여 앞이 더 뒤의 문자인 경우
                {
                    char *tmp = sort[j]; //포인터 사용
                    sort[j] = sort[j + 1];
                    sort[j + 1] = tmp; //문자열 주소 교환
                }
            }
        }
    }

    for (int i = 0; i < size2; i++) //정렬된 sort주소 탐색
        puts(sort[i]);              //탐색한 sort문자열을 출력

    return 0;
}
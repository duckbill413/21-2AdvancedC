#include <stdio.h>
#include <string.h>

int main()
{
    char ch[100] = "";
    gets(ch);
    //문장을 입력받기위한 배열 ch선언 및 gets로 문장 입력
    char word[10][11];
    //문장에서 단어를 분리하고 저장하기 위한 이중 배열 선언
    int size = 0;  //단어 크기 저장
    int point = 0; //단어 위치 저장
    char *p = ch;  //단어의 처음 주소 저장
    //시작이 처음 단어 이므로 처음에 ch를 할당
    for (char *pch = ch; pch <= ch + strlen(ch); pch++) //문장의 처음부터 끝까지 포인터로 살펴본다
    {
        if (*pch == ' ' || *pch == '\0') //공백 혹은 종료문자 일때
        {
            strncpy(word[point], p, size); //word에 단어의 첫주소 p와 단어의 크기를 보내 복사
            word[point][size] = '\0';      //단어의 마지막에 종료 문자를 삽입
            size = -1;                     //사이즈 초기화 이때 뒤에 size++가 있으므로 -1로 저장
            p = pch + 1;                   //종료 문자 다음이 새로운 단어이므로 p에 pch+1을 저장
            point++;                       //새로운 단어가 생겼으므로 point를 늘림
        }
        size++; //공백 혹은 종료가 없을 경우 단어의 크기가 늘어남
    }
    for (int i = 0; i < point; i++)
        puts(word[i]); //word에 저장된 단어를 순서대로 출력

    int rank[10] = {0}; //알파벳 순서대로 출력하기 위한 rank 변수 선언 및 0초기화

    for (int i = 0; i < point; i++)
    {
        for (int j = 0; j < point; j++)
        {
            if (strcmp(word[i], word[j]) > 0) //i의 단어와 j의 단어를 비교해서 strcmp가 크면 i가 더 뒤의 문자
                rank[i]++;                    //rank를 증가 시킨다
        }
    }

    for (int i = 0; i < point; i++) //rank의 처음부터 끝까지 살펴보기 위함
    {
        if (rank[i] == 0)  //rank가 0일경우 맨처음 문자
            puts(word[i]); //해당 i의 word를 출력
    }
    return 0;
}
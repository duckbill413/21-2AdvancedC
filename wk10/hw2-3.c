#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char tmp[101]; //문자열을 입력 받을 임시 배열을 선언
    gets(tmp);     //문자열1 입력

    int size1 = 0, size2 = 0;                                 //문자열1, 2의 사이즈 변수
    for (char *ptmp = tmp; ptmp <= tmp + strlen(tmp); ptmp++) //문자열 참조
        if (*ptmp == ' ' || *ptmp == 0)                       //문자열1에서 공백, 종료문자시 사이즈 증가
            size1++;

    char **arr1 = NULL;                                           //문자열1을 이중포인터로 생성
    if ((arr1 = (char **)malloc(sizeof(char *) * size1)) == NULL) //주소를 동적할당
        return -1;                                                // NULL로 실패시 종료
    char **parr1 = arr1;                                          // arr1의 주소 참조
    int size = 0;                                                 //사이즈 변수
    for (char *ptmp = tmp; ptmp <= tmp + strlen(tmp); ptmp++)     //문자열 참조
    {
        if (*ptmp == ' ' || *ptmp == 0) //공백 혹은 종료 문자일 경우
        {
            char *new = NULL; //임시 문자열 주소 생성
            if ((new = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
                return -1;                   //문자열 주소에 size만큼 동적할당하고 실패시 종료
            strncpy(new, ptmp - size, size); //임시 문자열 주소에 문자 입력
            *(new + size) = 0;               //마지막 주소에 종료문자 삽입

            *parr1++ = new; //문자열1에 임시 문자열 주소를 넣고 주소값 증가
            size = -1;      //다음 문자 입력을 위한 사이즈 조정
        }
        size++;
    }

    gets(tmp);                                                //새로운 문자열2 입력
    for (char *ptmp = tmp; ptmp <= tmp + strlen(tmp); ptmp++) //문자열 참조
        if (*ptmp == ' ' || *ptmp == 0)                       //문자열2에서 공백, 종료문자시 사이즈 증가
            size2++;

    char **arr2 = NULL;                                           //문자열2를 이중포인터로 생성
    if ((arr2 = (char **)malloc(sizeof(char *) * size2)) == NULL) //주소에 사이즈만큼 동적할당
        return -1;                                                //실패시 종료
    char **parr2 = arr2;                                          // arr2의 주소 참조
    size = 0;                                                     //사이즈 초기화
    for (char *ptmp = tmp; ptmp <= tmp + strlen(tmp); ptmp++)     //문자열 참조
    {
        if (*ptmp == ' ' || *ptmp == 0) //공백, 종료문자일 경우
        {
            char *new = NULL; //임시 문자열 주소 생성
            if ((new = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
                return -1;                   //문자열 주소에 size만큼 동적할당하고 실패시 종료
            strncpy(new, ptmp - size, size); //임시 문자열 주소에 문자 입력
            *(new + size) = 0;               //마지막 주소에 종료문자 삽입

            *parr2++ = new; //문자열2에 임시 문자열 주소를 넣고 주소값 증가
            size = -1;      //다음 문자 입력을 위한 사이즈 조정
        }
        size++;
    }

    char **arr3 = NULL;                                           //일치하는 문자를 저장할 arr3선언
    int size3 = size2;                                            // size3의 초기값을 최대 개수인 size2로 잡는다.
    if ((arr3 = (char **)malloc(sizeof(char *) * size3)) == NULL) //사이즈만큼 동적할당
        return -1;                                                //실패시 종료
    size = 0;                                                     //사이즈 초기화
    for (char **p = arr1; p < arr1 + size1; p++)                  //문자열1 참조
    {
        for (char **q = arr1; q < arr1 + size1; q++)
        {
            if (p == q) // p와 q가 같으면 동일 문자이므로 continue
                continue;

            char merge[101];   //합치기 위한 문자열 선언
            strcpy(merge, *p); // p주소의 문자열 복사
            strcat(merge, *q); // q주소의 문자열 잇기

            for (char **find = arr2; find < arr2 + size2; find++) //문자열2 참조
            {
                if (!strcmp(merge, *find)) //합쳐진 문자열과 문자열2의 문자가 같을 경우
                {
                    int found = 0;                                          //중복 문자 방지를 위한 변수
                    for (char **parr3 = arr3; parr3 < arr3 + size; parr3++) //문자열3 참조
                    {
                        if (!strcmp(*parr3, merge)) //문자열3에서 merge문자을 찾는다.
                        {
                            found = 1; //찾을 경우 found=1로 하고 종료
                            break;
                        }
                    }
                    if (!found) //문자열이 없을 경우
                    {
                        *(arr3 + size) = (char *)malloc(sizeof(char) * (strlen(merge) + 1)); //문자열3에 merge문자열의 크기 만큼 동적 할당
                        strcpy(*(arr3 + size), merge);                                       //문자열3에 복사
                        size++;                                                              //문자열3의 크기 증가
                    }
                }
            }
        }
    }
    size3 = size;                                          //문자열3의 크기가 정해졌으므로 사이즈 입력
    arr3 = (char **)realloc(arr3, sizeof(char *) * size3); // size3의 크기만큼 문자열3의 크기를 재조정 해준다.

    for (char **p = arr3; p < arr3 + size3 - 1; p++) //문자열3을 버블 정렬로 참조
    {
        for (char **q = arr3; q < arr3 + size3 - (p - arr3) - 1; q++)
        {
            if (strlen(*q) < strlen(*(q + 1))) //뒤의 문자가 더 길경우 순서 변경
            {
                char *tmp = *q;
                *q = *(q + 1);
                *(q + 1) = tmp;
            }
            else if (strlen(*q) == strlen(*(q + 1)) && strcmp(*q, *(q + 1)) > 0)
            { //뒤의 문자와 길이가 같을때 사전식 배열로 순서 변경
                char *tmp = *q;
                *q = *(q + 1);
                *(q + 1) = tmp;
            }
        }
    }
    for (char **parr3 = arr3; parr3 < arr3 + size3; parr3++) //정렬된 문자열3 출력
        printf("%s\n", *parr3);

    for (int i = 0; i < size1; i++)
        free(arr1[i]); //문자열1의 문자들을 free
    free(arr1);        //문자열1 free
    for (int i = 0; i < size2; i++)
        free(arr2[i]); //문자열2 문자들을 free
    free(arr2);        //문자열2 free
    for (int i = 0; i < size3; i++)
        free(arr3[i]); //문자열3 문자들을 free
    free(arr3);        //문자열3 free

    return 0;
}

/*
red orange yellow green blue purple
pink red redorange orangered yellow black bluegreen white purple
*/
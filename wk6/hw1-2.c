#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student//학생 구조체 생성
{
    char name[10];//학생 이름
    char id[11];//학번
    char score;//평균학점
};

int main()
{
    struct student st[5];//학생 구조체

    for (int i = 0; i < 5; i++)//5명의 학생 정보를 입력 받는다.
    {
        scanf("%s %s %c", st[i].name, st[i].id, &st[i].score);//이름, 학번, 학점 입력
    }
    getchar();//scanf버퍼 지우기
    char name[10];//찾고자 하는 이름 입력
    gets(name);//gets로 이름 입력

    char year[5];//입학년도를 입력할 변수
    char score;//찾은 학생의 학점
    for (int i = 0; i < 5; i++)
    {
        if (!strcmp(name, st[i].name))//5명의 학생에 대하여 찾은 이름이 있다면
        {
            strncpy(year, st[i].id, 4);//year에 학번중 앞 4자리를 복사
            score = st[i].score;//score에 학점 입력
        }
    }
    int found = 0;
    for (int i = 0; i < 5; i++)
    {
        if (!strncmp(year, st[i].id, 4) && st[i].score == score && strcmp(name, st[i].name))
        {//입학년도와 학점이 같은 학생을 찾고 본인은 제외한다.
            printf(" %s", st[i].name);//찾은 학생의 이름 출력
            found = 1;//찾은 학생이 존재 하므로 found =1
        }
    }
    if (!found)//입학년도, 학점이 같은 학생이 존재 하지 않으면
        printf("0");//0출력

    printf("\n%d %d", atoi(year), atoi(year) % 131);//year을 정수화 하여 출력하고, 정수화한 year에 131의 나머지 출력
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student
{
    char *name;           //학생 이름
    char id[5];           //학생 학번
    int numSubject;       //과목 개수
    struct subject *psub; //과목 구조체 포인터
    double avg;           //모든 과목의 평균
} Student;

typedef struct subject
{
    char *name;   //과목 이름
    double score; //과목 점수
} Subject;

int main()
{
    int N;
    scanf("%d", &N); //입력 받을 학생 수 입력
    getchar();       //버퍼 삭제

    Student *st = NULL;
    if ((st = (Student *)malloc(sizeof(Student) * N)) == NULL)
        return -1; //학생 구조체를 선언하고 N개 만큼 동적 배열해준다 실패시 종료

    for (Student *pst = st; pst < st + N; pst++) //학생 구조체에 대해서 살펴 본다.
    {
        char tmp[101];
        gets(tmp);            // tmp를 통해 문자열을 입력
        int chap = 0;         //작업 선택용 변수
        int numOfSubject = 0; //과목 개수 카운트 변수

        pst->psub = NULL;
        if ((pst->psub = (Subject *)malloc(sizeof(Subject) * 100)) == NULL)
            return -1; //과목을 100개 만큼 동적 할당하고 실패시 종료
        //추후 realloc으로 크기 조절 예정

        int size = 0;                                             //공백 문자등의 크기를 카운트하기 위한 변수
        for (char *ptmp = tmp; ptmp <= tmp + strlen(tmp); ptmp++) //문자열 탐색
        {
            if (*ptmp == ' ' || *ptmp == 0) //공백, 종료 문자일 경우
            {
                if (chap == 0) //학생 이름 입력
                {
                    pst->name = NULL;
                    if ((pst->name = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
                        return -1;                         //학생 이름을 사이즈+1 만큼 동적 할당 실패시 종료
                    strncpy(pst->name, ptmp - size, size); //학생이름 입력
                    pst->name[size] = 0;                   //마지막에 종료 문자 삽입
                    chap++;                                //다음 작업
                }
                else if (chap == 1) //학생 학번 입력
                {
                    strncpy(pst->id, ptmp - size, size); //사이즈(4)만큼 입력
                    pst->id[4] = 0;                      //종료 문자 삽입
                    chap++;                              //다음 작업
                }
                else if (chap == 2) //과목명 입력
                {
                    pst->psub[numOfSubject].name = NULL;
                    if ((pst->psub[numOfSubject].name = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
                        return -1;                                            // 0부터 시작하는 numOfSubject에 대하여 size+1만큼 동적 할당 실패시 종료
                    strncpy(pst->psub[numOfSubject].name, ptmp - size, size); //과목 이름 입력
                    pst->psub[numOfSubject].name[size] = 0;                   //마지막 종료 문자 삽입
                    chap++;                                                   //과목 점수 입력 모드
                }
                else if (chap == 3) //과목 점수 입력
                {
                    int sum = 0; //문자를 정수로 변환하기 위한 변수
                    for (char *num = ptmp - size; num < ptmp; num++)
                        sum = sum * 10 + (*num - '0');           //사이즈 크기만큼 문자열을 정수형으로 변환해 준다.
                    pst->psub[numOfSubject].score = (double)sum; //변환 종료후 구조체에 삽입

                    chap = 2;                       //과목명 입력 모드로 전환
                    numOfSubject++;                 //과목 개수 증가
                    pst->numSubject = numOfSubject; //과목 개수를 구조체에 입력
                }
                size = -1;
            }
            size++;
        }

        pst->psub = (Subject *)realloc(pst->psub, sizeof(Subject) * numOfSubject);
        //확정된 과목 개수만큼 구조체를 재할당 해준다.
        double sum = 0.0; //평균을 위한 변수
        for (int i = 0; i < numOfSubject; i++)
            sum += pst->psub[i].score;      //과목 개수 만큼 해당하는 점수를 합한다.
        pst->avg = sum / (pst->numSubject); //점수합/과목 개수를 평균 값에 삽입
    }

    int find;
    scanf("%d", &find); //찾고 싶은 번호 입력
    find -= 1;          //주소에 해당하므로 -1해준다.

    for (Student *p = st; p < st + N - 1; p++) //구조체에 대하여 버블정렬로 탐색
    {
        for (Student *q = st; q < st + N - (p - st) - 1; q++)
        {
            if (q->avg < (q + 1)->avg) //평균에 대하여 내림차순 정렬
            {
                Student tmp = *q;
                *q = *(q + 1);
                *(q + 1) = tmp; //구조체 swap
            }
            else if (q->avg == (q + 1)->avg && strcmp(q->id, (q + 1)->id) > 0)
            { //평균이 같을 경우 학번에 대하여 정렬
                Student tmp = *q;
                *q = *(q + 1);
                *(q + 1) = tmp; //구조체 swap
            }
        }
    }

    double big = st[find].psub->score; //첫번째 인자에 대하여 big 변수에 삽입
    int pointBig = 0;                  //가장 큰 값이 들어 가있는 위치
    for (int i = 0; i < st[find].numSubject; i++)
    {                                     //찾고 싶은 학생에 대하여 탐색
        if (st[find].psub[i].score > big) //과목 점수가 더 크면
        {
            big = st[find].psub[i].score; // big에 점수를 넣고
            pointBig = i;                 // pointBig에 해당 위치를 입력
        }
    }

    printf("%s %s %.2lf %s %.2lf", st[find].name, st[find].id, st[find].avg, st[find].psub[pointBig].name, st[find].psub[pointBig].score);
    //학생 이름, 학번, 평균 점수, 찾은 위치에 따른 과목 이름, 찾은 위치에 따른 과목 점수
    for (int i = 0; i < N; i++)
    {
        free(st[i].name);                          //학생 구조체의 이름 메모리 반환
        for (int j = 0; j < st[i].numSubject; j++) //모든 과목에 대하여 탐색
            free(st[i].psub[j].name);              //과목의 이름 메모리 반환
        free(st[i].psub);                          //학생의 과목 구조체 메모리 반환
    }
    free(st); //학생 구조체 메모리 반환
    return 0;
}

/*
test case)
5
HongGilDong 1003 Math 85 C 80 AdvC 90
JeonWooChi 1001 English 60 C 75 Physics 80 Math 70
HeungBoo 1002 Economics 80 AdvC 90 Math 80 C 90
NolBoo 1004 Ethics 50 C 62
Euler 1005 Math 100 Physics 90 AdvC 85
2

result)
HeungBoo 1002 85.00 AdvC 90.00
? 학생 이름, 학번, 평균 점수, 가장 점수가 높은 과목 이름, 가장 높은 과목 점수
*/
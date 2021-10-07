#include <stdio.h>
#include <string.h>
typedef struct student //학생 구조체 생성
{
    char name[31];      //이름
    int id;             //학번
    int class_num;      //과목 숫자
    char class[10][31]; //과목의 이름
    double score[10];   //과목에 대한 학점
} Stud;                 //학생 구조체를 Stud로 재정의

void sort_s(Stud S[], int cnt);      //오름차순 정렬을 위한 함수
void input(Stud *);                  //학생정보 입력 함수
void output(Stud *, int);            //학생정보 출력 함수
void delete (Stud *, int *, char[]); //학생 정보 삭제 함수

int main()
{
    Stud st[100];      //100명 까지의 학생 변수 저장 가능
    int num = 0;       //학생 인원수
    char order;        //지시사항 입력
    char del_name[31]; //삭제할 이름

    while (1)
    {
        scanf("%c", &order); //지시사항 입력
        if (order == 'Q')    //Q입력시 종료
            return 0;

        if (order == 'I')      //I입력시 input 함수 실행
            input(&st[num++]); //함수에 입력할 구조체 위치 입력후 학생수 증가
        else if (order == 'P') //P입력시 output함수 실행
            output(st, num);
        else if (order == 'D') //D입력시 delete함수 실행
        {
            getchar();                   //지시사항 입력시의 enter버퍼 삭제
            gets(del_name);              //삭제할 이름 입력
            delete (st, &num, del_name); //삭제할 이름과 학생수 변수도 같이 전송
            //num--;
        }
        else if (order == 'S') //S일경우 sort_s함수로 정렬 후 출력
            sort_s(st, num);
    }

    return 0;
}

void input(Stud *s)
{
    int num = 0;                                       //과목수 입력을 위함
    scanf("%s %d %d", s->name, &s->id, &s->class_num); //이름, 학번, 과목수 입력
    for (int i = 0; i < s->class_num; i++)             //과목수 만큼 과목명과 학점 입력
    {
        getchar();                                        //앞의 scanf로부터의 버퍼 삭제
        scanf("%s %lf", s->class[num], &s -> score[num]); //class명, 학점 입력
        num++;                                            //다음 입력을 위한 증가
    }
}

void output(Stud *s, int n)
{
    double score = 0.0; //전체 평점을 위한 score 변수
    for (Stud *p = s; p < s + n; p++)
    {
        score = 0.0; //score 초기화
        for (int i = 0; i < p->class_num; i++)
        {
            score += p->score[i]; //모든 과목에 대하여 과목 평점을 더한다.
        }
        score /= p->class_num;                                           //더한 과목 평점을 과목수로 나누어 평점을 계산
        printf("%s %d %d %.2lf\n", p->name, p->id, p->class_num, score); //이름, 학번, 과목수, 전체평점 출력
    }
}

void delete (Stud *s, int *n, char del[31])
{
    int found = 0;                     //찾을 경우 확인을 위한 변수
    for (Stud *p = s; p < s + *n; p++) //주소를 이용한 구조체 확인
    {
        if (!strcmp(p->name, del) || found == 1) //같은 이름을 찾거나 found=1일경우
        {
            if (!found) //found가 0이면 1로 바꾸고 전체 인원수 1감소
            {
                found = 1;
                (*n)--;
            }
            *p = *(p + 1); //한칸씩 구조체를 당긴다.
        }
        else if (found == 0 && !strcmp(p->name, del) && p == s + *n - 1)
            (*n)--;
        //마지막 구조체가 찾는 구조체인경우 전체 인원수만 감소시킨다
    }
}

void sort_s(Stud s[100], int cnt)
{
    Stud S_sort[100]; //원래 구조체 변경 방지
    for (int i = 0; i < cnt; i++)
        S_sort[i] = s[i]; //전체 구조체에 대하여 복사

    for (Stud *i = S_sort; i < S_sort + cnt; i++) //선택정렬
    {
        for (Stud *j = i + 1; j < S_sort + cnt; j++)
        {
            if (strcmp(i->name, j->name) > 0) //오름차순 정렬
            {
                Stud tmp = *i;
                *i = *j;
                *j = tmp; //구조체 순서변경
            }
        }
    }
    output(S_sort, cnt); //오름차순 정렬된 S_sort구조체를 출력
}
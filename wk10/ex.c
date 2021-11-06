#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
typedef struct subject
{
    char *name;   // 과목 이름
    double score; // 과목 점수
} sub;

typedef struct student
{
    char *name;           // 학생 이름
    char id[5];           // 학생 학번
    int numSubject;       // 과목 개수
    struct subject *psub; // 과목 구조체 포인터
    double avg;           // 모든 과목의 평균 점수
} st;

int main()
{
    int N, M;             //할당받을 구조체 크기
    st *p = NULL, tmp;    //메모리 할당받을 구조체 포인터 선언, 임의의 변수 tmp
    char c[101] = {NULL}; //입력받을 문자열 변수 선언
    scanf("%d", &N);
    getchar();
    p = (st *)calloc(N, sizeof(st)); //구조체에 동적할당
    for (int i = 0; i < N; i++)
    {
        gets(c);                                   //문자열 전체를 입력받기
        int cnt = 0, j = 0, k = 0, q = 0, sum = 0; //각각의 변수 선언 후 초기화
        int CNT = 0;                               //과목 갯수 저장할 변수
        p[i].avg = 0;                              //평균 0으로 초기화

        for (j = 0; c[j] != ' '; j++)
            cnt++;                                         //학생이름의 크기 측정(공백 전까지 cnt증가)
        p[i].name = (char *)calloc(cnt + 1, sizeof(char)); //해당 크기만큼 메모리 할당
        for (j = 0; j < cnt; j++)
        {
            p[i].name[q] = c[j];
            q++;
            p[i].name[q] = '\0';
        }
        //구조체 안의 name문자열에 c에있는 정보 넣어주기(문자를 일일히 넣어줌)
        q = 0;
        for (k = j + 1; k < j + 5; k++)
        {
            p[i].id[q] = c[k];
            q++; //공백 다음부터 4자리인 학번 넣어주기
        }
        p[i].id[4] = '\0'; // NULL문자 넣어주기
        for (int w = j + 5; c[w] != '\0'; w++)
        {
            if (c[w] == ' ')
                CNT++; // 공백 개수 세어서
        }
        p[i].numSubject = CNT / 2;                               //공백 개수 /2 가 과목 갯수가 됨
        p[i].psub = (sub *)calloc(p[i].numSubject, sizeof(sub)); //과목 갯수만큼 과목 구조체에 메모리 할당

        int w = k; // k를 변수에 저장
        cnt = 0;
        for (int h = 0; h < p[i].numSubject; h++)
        {
            cnt = 0;
            sum = 0;
            q = 0; //각각 변수 초기화
            for (int r = w + 1; c[r] != ' '; r++)
                cnt++;                                                 //과목이름 크기 측정(공백과 공백 사이)
            p[i].psub[h].name = (char *)calloc(cnt + 1, sizeof(char)); //동적할당 (구조체안에 구조체가있음, (구조체.구조체.멤버))
            q = 0;
            for (w = w + 1; c[w] != ' '; w++)
            {
                p[i].psub[h].name[q] = c[w];
                q++;
                p[i].psub[h].name[q] = '\0';
            }
            //과목 구조체에 과목 이름 넣어주기
            if (c[w + 1] >= '0' && c[w + 1] <= '9') //그다음 공백부터는 과목의 점수임
            {
                sum *= 10;
                sum += c[w + 1] - '0';
                if (c[w + 2] >= '0' && c[w + 2] <= '9') //문자인 숫자를 정수로 변환
                {
                    sum *= 10;
                    sum += c[w + 2] - '0';
                    if (c[w + 3] >= '0' && c[w + 3] <= '9') // 100점일경우 (3자리이므로)
                    {
                        sum *= 10;
                        sum += c[w + 3] - '0';
                        w++; //숫자 갯수만큼 w증가시켜줘야함
                    }
                    w++;
                }
                w++;
            }
            w++;
            p[i].psub[h].score = (double)sum; //형 변환 후 대입
            p[i].avg += p[i].psub[h].score;   //평균에 각 점수 더해주고
        }
        p[i].avg /= (double)p[i].numSubject; //갯수만큼 나눠주고
    }

    scanf("%d", &M); //값 입력받기
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if (p[j].avg < p[j + 1].avg) //
            {
                tmp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tmp; //평균 크기에 따라 구조체를 내림차순 정렬
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if (p[j].avg == p[j + 1].avg)
            {
                if (strcmp(p[j].id, p[j + 1].id) > 0)
                {
                    tmp = p[j];
                    p[j] = p[j + 1];
                    p[j + 1] = tmp;
                } //평균 크기에 따라 구조체를 내림차순 정렬
            }
        }
    }

    double maxscore = 0;                          //최고점수 저장할 변수
    char maxsub[100] = {NULL};                    //최고 점수에 해당하는 과목이름을 저장할 변수
    strcpy(maxsub, p[M - 1].psub[0].name);        //첫번째 과목으로 초기화
    for (int i = 0; i < p[M - 1].numSubject; i++) //입력받은 인덱스 안에서 최대점수 찾기
    {
        if (maxscore < p[M - 1].psub[i].score)
        {
            maxscore = p[M - 1].psub[i].score;
            strcpy(maxsub, p[M - 1].psub[i].name);
        } //최고점수의 값과 그 과목이름을 찾는다.
    }
    printf("%s %s %.2lf %s %.2lf", p[M - 1].name, p[M - 1].id, p[M - 1].avg, maxsub, maxscore);
    //해당 인덱스의 값들 출력(M번째 이면 인덱스는 M-1)

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < p[i].numSubject; j++)
        {
            free(p[i].psub[j].name);
        }
        free(p[i].name);
        free(p[i].psub);
    }
    free(p);
    return 0;
}
// by 19011851
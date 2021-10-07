#include <stdio.h>

struct _bank//은행 구조체
{
    int id;//대기자 id
    int arrival_time;//도착 시간
    int service_time;//서비스 시간
    int waiting_time;//대기 시간
};

void waitingtime(struct _bank guest[], int N);
double avgtime(struct _bank guest[], int N);
//waitingtime, avgtime 함수 원형 선언

int main()
{
    int N;
    scanf("%d", &N);//인원수를 입력 받는다.
    struct _bank guest[100];//최대 100명의 고객 수용

    for (int i = 0; i < N; i++)
        scanf("%d %d %d", &guest[i].id, &guest[i].arrival_time, &guest[i].service_time);//N명의 고객 정보를 입력

    waitingtime(guest, N);//N명의 고객에 대하여 대기 시간 계산

    printf("%.2lf", avgtime(guest, N));//평균 대기시간 출력
    return 0;
}

void waitingtime(struct _bank guest[100], int N)//고객 대기시간을 구하는 함수
{
    int wait = 0;
    for (int i = 0; i < N; i++)
    {
        guest[i].waiting_time = wait - guest[i].arrival_time;//wait시간의 합에 도착시간을 뺴서 대기시간 계산
        wait += guest[i].service_time;//wait time에 서비스 시간을 더한다.
    }
}

double avgtime(struct _bank guest[100], int N)//고객 대기시간의 평균을 구하는 함수
{
    double avg = 0.0;
    for (int i = 0; i < N; i++)
    {
        avg += guest[i].waiting_time;//모든 고객에 대하여 대기 시간을 더한다.
    }
    avg /= N;//더한 대기시간에 고객인원수N을 나누어 평균 대기시간을 구한다.
    return avg;
}
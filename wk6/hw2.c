#include <stdio.h>

struct _bank//���� ����ü
{
    int id;//����� id
    int arrival_time;//���� �ð�
    int service_time;//���� �ð�
    int waiting_time;//��� �ð�
};

void waitingtime(struct _bank guest[], int N);
double avgtime(struct _bank guest[], int N);
//waitingtime, avgtime �Լ� ���� ����

int main()
{
    int N;
    scanf("%d", &N);//�ο����� �Է� �޴´�.
    struct _bank guest[100];//�ִ� 100���� �� ����

    for (int i = 0; i < N; i++)
        scanf("%d %d %d", &guest[i].id, &guest[i].arrival_time, &guest[i].service_time);//N���� �� ������ �Է�

    waitingtime(guest, N);//N���� ���� ���Ͽ� ��� �ð� ���

    printf("%.2lf", avgtime(guest, N));//��� ���ð� ���
    return 0;
}

void waitingtime(struct _bank guest[100], int N)//�� ���ð��� ���ϴ� �Լ�
{
    int wait = 0;
    for (int i = 0; i < N; i++)
    {
        guest[i].waiting_time = wait - guest[i].arrival_time;//wait�ð��� �տ� �����ð��� ���� ���ð� ���
        wait += guest[i].service_time;//wait time�� ���� �ð��� ���Ѵ�.
    }
}

double avgtime(struct _bank guest[100], int N)//�� ���ð��� ����� ���ϴ� �Լ�
{
    double avg = 0.0;
    for (int i = 0; i < N; i++)
    {
        avg += guest[i].waiting_time;//��� ���� ���Ͽ� ��� �ð��� ���Ѵ�.
    }
    avg /= N;//���� ���ð��� ���ο���N�� ������ ��� ���ð��� ���Ѵ�.
    return avg;
}
#include <stdio.h>

int passengerN(int);
void rebooking(int *);
int changeseat(int *);
//passengerN, rebooking, changeseat�Լ� ����
int main()
{
    int n;
    scanf("%d", &n);
    //�°��� �Է�
    int seat[21]; //�¼� �迭 ����
    for (int *ps = seat; ps < seat + n; ps++)
        scanf("%d", ps);
    //seat�� �������� �̿��Ͽ� seat�� ���� �Է�

    printf("%d\n", passengerN(n));
    //�°���n�� 5�̸��̸� -1, �̻��̸� 0 ���
    if (passengerN(n) == -1)
        return 0;
    //�°���n�� 5�̸��� ��� -1�� ȣ���ϸ� ���α׷� ����

    rebooking(seat);
    //rebooking�Լ� ����
    for (int *ps = seat; ps < seat + n; ps++)
        printf("%d ", *ps);
    //�¼� �迭�� �°�����ŭ ���
    return 0;
}
void rebooking(int *ar)
{
    int found = 0; //���� ã�� �ߺ��� ��
    for (int *p = ar; p < ar + 21; p++)
    {                   //�¼��� �ִ� 21��
        if (found == 0) //���� ã�� �� �߰�X
        {
            for (int *q = ar; q < p; q++)
            {                 //ó������ p���������� ��
                if (*q == *p) //p�� q�� ���� ���ٸ� �ߺ�
                {
                    found = *p; //�ߺ��� �Ϳ� ���� ���� ��ȯ�� �־�� �ϹǷ� ���� ã�� �� ����
                    *p = changeseat(ar);
                    break;
                    //�ߺ��϶� p�� ���� changeseat�� �̿��Ͽ� �ּҰ����� ��ȯ �ϰ� ���� p�� ��
                }
            }
        }
        if (found != 0) //���� ã�� ���� �ִٸ�
        {
            for (int *z = p + 1; z < ar + 21; z++) //������ ã�� �� �������� ������
            {
                if (*z == found) //���� ������ ���� �ߺ��� �Ϳ� ���Ͽ� ���� ��ȯ���ش�.
                {
                    *z = changeseat(ar); //�ߺ��ȼ��� changeseat�� ���ο� �� �Է�
                }
            }
            found = 0; //ã�� ���� ���Ͽ� ��� �Է��Ͽ����Ƿ� found(ã�¼�)�� �ٽ� 0���� ����
        }
    }
}

int passengerN(int n)
{
    if (n < 5 || n > 21)
        return -1; //�°����� 5�̸� 21�ʰ�
    else
        return 0; //�°��� 5�̻�
}

int changeseat(int *ar)
{
    int seat = 1;                 //��ġ�� �¼� seat���� �� �ʱ�ȭ
    for (int i = 1; i <= 21; i++) //�¼��� 1~21������ �¼� ���� ���� �� ���� Ȯ��
    {
        int found = 0;
        for (int *p = ar; p < ar + 21; p++)
        { //seat�迭�� ���� i��
            if (i == *p)
            {
                found = 1;
                break;
                //i==*p�̸� i���� �����ϹǷ� ���Ұ� break�ϰ� ������ Ȯ��
            }
        }
        if (!found) //seat�迭�� i���� ���� ���� �ʴ´�. ��, ��� ����
        {
            seat = i;
            break;
            //seat�� i�� �Ҵ��ϰ� ���ϴ� ���� ã�����Ƿ� for�� ����
        }
    }
    return seat; //ã�� seat�� ����
}
#include <stdio.h>

int passengerN(int); //�°��� Ȯ��
int checking(int *, int *);
//�ߺ� ���� �ִ��� Ȯ���ϱ� ���� �Լ�
int main()
{
    int n;
    scanf("%d", &n);
    //�°��� �Է�
    int seat[21] = {0};
    //�¼� �迭 ���� �� �ʱ�ȭ
    for (int *ps = seat; ps < seat + n; ps++)
        scanf("%d", ps);
    //seat�� �����͸� �̿��Ͽ� seat�迭�� ���Է�

    if (passengerN(n) == -1) //�°����� 5�̸��� ���
    {
        printf("%d\n", passengerN(n)); //-1����ϰ� ���α׷� ����
        return 0;
    }
    int found = 0; //�ߺ��� ���� Ȯ��

    int fseat[21] = {0};
    int *pfseat = fseat;
    //�ߺ��Ǵ� ���� �ѹ� ����ϸ� ����� �ʿ䰡 ���� ������ ������ ���� ���� �迭

    for (int *ps = seat; ps < seat + n; ps++)
    {
        if (checking(fseat, ps) >= 1)
            continue;
        //�տ��� Ȯ���� ������ üũ�Ѵ� 1�̻��̸� �տ��� Ȯ��
        if (checking(seat, ps) > 1) //seat�迭�� ���ؼ� *ps�� ���� 2�� �̻��̸� �ߺ���
        {
            found = 1;                                  //�ߺ����� ���� �����Ƿ� found = 1
            printf("%d %d\n", *ps, checking(seat, ps)); //�ߺ��� ���� Ƚ���� ���
            *pfseat++ = *ps;                            //Ȯ���� �� �迭�� *ps���� �Է½�Ŵ
        }
    }

    if (!found) //�ߺ��� ���� ���ٸ� 0���
        printf("0");

    return 0;
}
int checking(int *s, int *check) //Ȯ���� �迭�� ���� ���ڷ� ���
{
    int cnt = 0;
    for (int *p = s; p < s + 21; p++)
    {
        if (*p == *check) //Ȯ���� ���� �迭���� ��� ���Ǿ����� Ȯ��
            cnt++;        //�ߺ��Ǹ� cnt���� �ø�
    }
    return cnt; //�ߺ�Ƚ�� ��ȯ
}
int passengerN(int n)
{
    if (n < 5 || n > 21) //�°����� 5�̸� 21�ʰ� �̸� -1��ȯ
        return -1;
    else //�ܴ̿� 0��ȯ
        return 0;
}
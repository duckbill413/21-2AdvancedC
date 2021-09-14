#include <stdio.h>

int *MAX(int *);
int *MIN(int *);
//�ּҰ��� ��ȯ�ϴ� int�� �Լ� MAX, MIN ����

int main()
{
    int n;
    scanf("%d", &n);
    //n�� �ݺ��� ������ �����ϰ� �Է�
    int *par;
    //ar�� �迭 ������ ����
    for (int i = 0; i < n; i++) //n�� �ݺ�
    {
        int ar[100] = {0}; //ũ�Ⱑ 100�� �迭 ar���� �� �ʱ�ȭ
        for (par = ar; par < ar + 100; par++)
        {                     //�迭 �����͸� �迭 �ּ� ar�� �ʱ�ȭ ���ָ� ar�� ũ�Ⱑ 100�̹Ƿ� ar+100
            scanf("%d", par); //�迭 ������ par�� �̿��Ͽ� ar�迭�� ���� �Է�
            if (*par == 0)
                break;
            //���� 0�� ������ ����
        }
        int *big, *small;
        //�߰� �ּ� ũ�⸦ Ȯ���ϱ� ���� ������ big, small ����
        if (MIN(ar) < MAX(ar)) //MAX�� �ּҰ� MIN���� Ŭ��
        {
            small = MIN(ar);
            big = MAX(ar);
            //small�� MIN�ּ� big�� MAX�ּ�
        }
        else //MIN�� �ּҰ� MAX���� ũ�ų� ������
        {
            small = MAX(ar);
            big = MIN(ar);
            //small�� MAX�ּ� big�� MIN�ּ�
        }
        int found = 0;
        //ȭ�鿡 ��µ� ������ �ִ��� Ȯ�ο�
        for (int *p = small + 1; p < big; p++)
        {                      //MIN�� MAX������ ������ ����ؾ� �ϹǷ� small+1�� big���� �ϳ� ���� �ּ�
            found = 1;         //����� ������ �����Ƿ� found=1�� ��ȯ
            printf("%d ", *p); //������ ���� ���
        }
        if (!found) //found=0�̸� ��µ� ������ ����
            printf("none\n");
        printf("\n");
    }
    return 0;
}

int *MAX(int *ar) //MAX ������ �Լ�
{
    int max, *pmax; //�ִ밪�� ũ��� �ּҸ� �Է� �ޱ� ���� ���� �� ������ ����
    for (int *par = ar; par < ar + 100; par++)
    { //�迭 ar�� �ּҸ� �Է� �ް� �� ũ�⸦ ������ ��
        if (*par == 0)
            break;
        //*par�� 0�̸� ���̹Ƿ� ����
        if (max < *par || par == ar) //max���� *par�� ũ�ų� ó���� ���
        {
            max = *par;
            pmax = par;
            //max�� *par, pmax�� par �ּ� �Է�
        }
    }
    return pmax; //�ִ��� �ּ� ����
}

int *MIN(int *ar) //MIN ������ �Լ�
{
    int min, *pmin; //�ּڰ��� ũ��� �ּҸ� �Է� �ޱ� ���� ���� �� ������ ����
    for (int *par = ar; par < ar + 100; par++)
    { //�迭 ar�� �ּҸ� �Է� �ް� �� ũ�⸦ ������ ��
        if (*par == 0)
            break;
        //*par�� 0�̸� ���̹Ƿ� ����
        if (min > *par || par == ar) //min���� *par�� �۰ų� ó���� ���
        {
            min = *par;
            pmin = par;
            //min�� *par, pmin�� par �ּ� �Է�
        }
    }
    return pmin; //�ּڰ��� �ּ� ����
}
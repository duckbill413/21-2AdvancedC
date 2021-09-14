#include <stdio.h>

void sort(int *, int *, int, int);
void uppsort(int *, int);
void downsort(int *, int);
//������ ���� �Լ� ���� ����

int main()
{
    int arr1[11], arr2[11];
    int size1 = 0, size2 = 0;
    //������ �Է��� �迭 �ΰ� �� �迭 ũ�⸦ ���� ���� �ΰ� ����
    for (int *parr = arr1; parr < arr1 + 11; parr++)
    {
        scanf("%d", parr); //�����͸� �̿��Ͽ� arr1�� �� �Է�
        if (*parr == 0)
            break; //0�� �ԷµǸ� �Է� ����
        size1++;   //0�Է� �Ǳ� �������� �迭 ũ��
    }
    for (int *parr = arr2; parr < arr2 + 11; parr++)
    {
        scanf("%d", parr); //�����͸� �̿��Ͽ� arr1�� �� �Է�
        if (*parr == 0)
            break; //0�� �ԷµǸ� �Է� ����
        size2++;   //0�Է� �Ǳ� �������� �迭 ũ��
    }
    sort(arr1, arr2, size1, size2);
    downsort(arr1, size1);
    uppsort(arr2, size2);
    //������ ���� �Լ� ����

    for (int *parr = arr1; parr < arr1 + size1; parr++)
        printf("%d ", *parr);
    //�����͸� �̿��Ͽ� arr1�迭�� �� ���
    printf("\n");
    for (int *parr = arr2; parr < arr2 + size2; parr++)
        printf("%d ", *parr);
    //�����͸� �̿��Ͽ� arr2�迭�� �� ���

    return 0;
}

void sort(int *a, int *b, int n, int m)
{ //ū���� arr1, �������� arr2�� �Է��ϱ� ���� �Լ�

    for (int *p = a; p < a + n; p++) //a�� ũ�⸦ ������
    {
        for (int *q = b; q < b + m; q++) //b�� ũ�⸦ ������
        {
            if (*p < *q) //���� ��ġ�� arr1�� arr2�� ��
            {
                int tmp = *q;
                *q = *p;
                *p = tmp;
                //arr2�� ���� ũ�� arr1�� �ְ� arr2���� arr1�� ���� ���� �ִ´�.
            }
        }
    }
}

void downsort(int *a, int n)
{                                    //�������� ������ ���� �Լ�
    for (int *p = a; p < a + n; p++) //�������� ���
    {
        for (int *q = a; q < a + n; q++)
        {
            if (*p > *q) //���� ���� �� ũ��
            {
                int tmp = *q;
                *q = *p;
                *p = tmp;
                //tmp�� �̿��Ͽ� �ڿ� ���� ���� �ٲپ��ش�.
            }
        }
    }
}

void uppsort(int *a, int n)
{                                    //�������� ������ ���� �Լ�
    for (int *p = a; p < a + n; p++) //�������� ���
    {
        for (int *q = a; q < a + n; q++)
        {
            if (*p < *q) //���� ���� �� ũ��
            {
                int tmp = *q;
                *q = *p;
                *p = tmp;
                //tmp�� �̿��Ͽ� �ڿ� ���� ���� �ٲپ��ش�.
            }
        }
    }
}
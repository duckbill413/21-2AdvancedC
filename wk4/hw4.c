#include <stdio.h>
#include <string.h>

int s_check(char *p, char *q); //s_check �Լ� ���� ����

int main()
{
    int m, k1, k2;                   //����m, k1, k2 ����
    scanf("%d %d %d", &m, &k1, &k2); //m, k1, k2�Է�
    getchar();                       //enter���� ����
    for (int i = 0; i < m; i++)      //m�� ��ŭ �ݺ�
    {
        char ch[201] = "";                             //���ڿ� ch[201]����
        gets(ch);                                      //���ڿ��� ���� �Է�
        if (s_check(ch + k1, ch + k2) != 0)            //�ҹ����� ������ 0���� �ƴҶ�
            printf("%d\n", s_check(ch + k1, ch + k2)); //s_check�Լ��� �̿��Ͽ� �ҹ����� ���� ���
    }

    return 0;
}

int s_check(char *p, char *q) //s_check�Լ� ����
{
    char cnt[201] = "";                  //�ҹ��ڸ� �Է��� �迭 ����
    int i = 0;                           //��ġ ����
    for (char *pch = p; pch <= q; pch++) //������ �ּ� p���� �����Ͽ� q������ ���� Ž��
    {
        if (*pch >= 'a' && *pch <= 'z') //���ڰ� �ҹ����� ���
        {
            cnt[i++] = *pch; //cnt�迭�� �ҹ��ڸ� �Է��ϰ� ��ġ �̵�
        }
    }
    return strlen(cnt); //�Էµ� �ҹ����� ���� ����� ���� strlen���� cnt�迭�� ũ�� ��ȯ
}
#include <stdio.h>
#include <string.h>

int main()
{
    char ch[1001] = "";
    char *pch[100];                            //�迭 ch�� ����Ʈ �迭 ����
    int k;                                     //���� k���� ����
    gets(ch);                                  //���ڿ� �Է�
    scanf("%d", &k);                           //���� ���� �Է�
    int size = 0;                              //�ܾ��� ũ��
    int word = 0;                              //�ܾ��� ����
    int ch_size = strlen(ch);                  //�ʱ� ���� �迭�� ũ��
    for (char *p = ch; p <= ch + ch_size; p++) //�����͸� ��� ���ڿ� Ȯ��
    {
        if (*p == ' ' || *p == '\0') //����Ȥ�� ���� ������ ���
        {
            pch[word] = p - size;       //������ �迭�� �ܾ� ���� �ּ� ����
            *(pch[word] + size) = '\0'; //�������� ���Ṯ�� ����
            word++;                     //�ܾ� ���� ����
            size = -1;                  //������ �ʱ�ȭ
        }
        size++;
    }

    for (int i = 0; i < word - 1; i++) //���� ����
    {
        for (int j = 0; j < word - i - 1; j++)
        {
            if (strlen(pch[j]) < strlen(pch[j + 1])) //���� �ܾ �� ����
            {
                char *tmp = pch[j];
                pch[j] = pch[j + 1];
                pch[j + 1] = tmp; //���� �ܾ �� ��� ������ �ٲ㼭 ������ ����
            }
            if (strlen(pch[j]) == strlen(pch[j + 1])) //�ܾ��� ���̰� ���� ���
            {
                if (strcmp(pch[j], pch[j + 1]) > 0) //���ڿ��� Ȯ���Ͽ� ���� �� ���� ������ ���
                {
                    char *tmp = pch[j]; //������ ���
                    pch[j] = pch[j + 1];
                    pch[j + 1] = tmp; //���ڿ� �ּ� ��ȯ
                }
            }
        }
    }

    puts(pch[k - 1]); //k���� �ּ��� ���ڿ� ���

    return 0;
}
#include <stdio.h>
#include <string.h>

int main()
{
    char ch1[100] = "";
    char ch2[100] = "";
    //���ڿ� A, B����
    gets(ch1);
    gets(ch2); //A,B���ڿ� �Է�

    int cnt = 0;                                              //���� ������ ���� ī���� ����
    int size = 0;                                             //�ܾ��� ���ڼ� ī����
    for (char *pch1 = ch1; pch1 <= ch1 + strlen(ch1); pch1++) //�����͸� �̿��Ͽ� ch1�� ó������ ������ ����
    {
        if (*pch1 == ' ' || *pch1 == '.' || *pch1 == '\0') //����, ��ħǥ, ���� ������ ��� Ȯ��
        {
            if (size == strlen(ch2)) //����� B������ ũ��� ���� ���
            {
                if (!strncmp(pch1 - strlen(ch2), ch2, strlen(ch2))) //ch2�� ch2������ ������ŭ ���Ͽ� ������ ��ġ�� ���
                                                                    //�̋� Ȯ�� ���� �ּҴ� pch1-ch2�Ǳ��� ���� üũ�ؾ� ��
                    cnt++;                                          //������ ��ġ�� ī��Ʈ ���ش�
            }
            size = -1; //�ڿ� size++�� �����Ƿ� -1�� ����
        }
        size++; //����, ��ħǥ ���Ṯ�ڰ� �ƴҰ�� size����
    }
    printf("%d", cnt); //ī��Ʈ�� �� ���

    return 0;
}
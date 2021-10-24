#include <stdio.h>
#include <string.h>
int change(char[], char[]); //���ڿ��� ��ȯ �����ִ� �Լ� ����
int main()
{
    char ch1[100] = "";
    char ch2[100] = "";
    //���ڿ��� �Է¹ޱ����� ���ڿ� �迭 ch1, ch2����
    gets(ch1);
    gets(ch2);
    //gets�� �̿��Ͽ� ������ �ִ� ���ڿ��� �Է¹޴´�.
    if (change(ch1, ch2)) //A->B�� ������ ���
        printf("1");
    else if (change(ch2, ch1)) //B->A�� ������ ���
        printf("2");
    else
        printf("0"); //A->B, B->A ��� �Ұ����� ���

    return 0;
}

int change(char ch1[], char ch2[]) //ch1�� ��ȯ�ϰ� ch2�� ��ġ�� ��� 1�ƴҰ�� 0 ��ȯ �Լ� ����
{
    int n, i = 0; //n:�̵� ���� ��, i: while�� ������ ����
    while (1)
    {
        if (ch1[i] >= 'A' && ch1[i] <= 'Z') //ã�� ���ڰ� �빮���� ���
        {
            n = ch2[i] - ch1[i]; //������ ��ġ�� ch2-ch1�� �Ͽ� n�� ����
            break;               //n�� ���ϰ� ����
        }
        if (ch1[i] >= 'a' && ch1[i] <= 'z') //ã�� ���ڰ� �ҹ����� ���
        {
            n = ch1[i] - ch2[i]; //������ ��ġ�� ch1-ch2�� �Ͽ� n�� ����
            break;               //n�� ���ϰ� ����
        }
        i++; //ã�� ���ڰ� �ҹ���, �빮�ڰ� �ƴѰ�� ���� ���ڸ� ã�´�.
    }
    if (n < 0) //n�� ������ ���ð�� ch2�� ���ڰ� ch1���� �տ� �����Ƿ� 0�� �����ϰ� �Լ� ����
        return 0;

    for (char *pch = ch1; pch < ch1 + strlen(ch1); pch++) //ch1 �迭�� �̿��ϸ� ũ�Ⱑ �������̹Ƿ� strlen(ch1) ���
    {
        if (*pch >= 'A' && *pch <= 'Z') //���ڰ� �빮���� ��� n��° �� ���ڷ� ��ȯ
            *pch = *pch + n;
        else if (*pch >= 'a' && *pch <= 'z') //���ڰ� �ҹ����� ��� n��° �� ���ڷ� ��ȯ
            *pch = *pch - n;
        else if (*pch >= '0' && *pch <= '9') //���ڰ� ������ ���
        {
            int flag = 1;                               //���ڰ� ���ڸ� �ΰ��
            int num = (int)(*pch) - '0';                //ã�� ������ ����ȭ ��
            if (*(pch + 1) >= '0' && *(pch + 1) <= '9') //�� ���� ���ڸ� Ȯ���ؼ� ���ڰ� ������ ���
            {
                num = num * 10 + (int)(*(pch + 1)) - '0'; //���� ã�� ����*10�� �Ͽ� �ڸ����� ���̰� ã�� ���ڸ� ����ȭ
                flag = 2;                                 //���ڰ� ���ڸ� �ΰ��
            }

            char plus[11];                          //n�� �ִ� 10�̹Ƿ� 11 ũ�� �Ҵ�
            for (char *p = plus; p < plus + n; p++) //plus�迭�� ���� �Ҵ� n�� �ݺ�
                *p = 'A' + num - 1;                 //A���ڷ� ���� num��° ������ ���ڸ� ã�� �Է��Ѵ�.
            plus[n] = '\0';                         //plus�� �������� ���ڿ� ���� ���ڸ� �־��ش�.

            char tmp[100] = "";              //���ڿ��� ��ĥ �Խ� �迭 ����
            strncpy(tmp, ch1, pch - ch1);    //tmp�� ch1�� ���� �������� ���ڵ��� �־���
            strcat(tmp, plus);               //tmp�� plus ���ڿ��� �����ش�.
            strcat(tmp, pch + flag);         //tmp�� �̹� ������ ���� ���� ���ڵ��� �־��ش�.
            tmp[strlen(ch1) + n - 1] = '\0'; //ch1�� ������ n-1���� ŭ �þ�Ƿ� �������� ���� ���ڸ� �ִ´�.
            strcpy(ch1, tmp);                //ch1�� tmp�� �ִ´�.

            pch += n - 1; //n�� ��ŭ �ں��� ���ڸ� Ȯ�����ָ� �ȴ�.
        }
        else //�� ���� ������ ��� �������� ����
            *pch = ' ';
    }
    if (!strcmp(ch1, ch2)) //ch1�� ch2�� ������ 1��ȯ
        return 1;
    else
        return 0; //�ٸ��� 0��ȯ
}
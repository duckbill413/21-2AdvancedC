#include <stdio.h>
#include <string.h>

int main()
{
    char ch[100] = "";
    gets(ch);
    //������ �Է¹ޱ����� �迭 ch���� �� gets�� ���� �Է�
    char word[10][11];
    //���忡�� �ܾ �и��ϰ� �����ϱ� ���� ���� �迭 ����
    int size = 0;  //�ܾ� ũ�� ����
    int point = 0; //�ܾ� ��ġ ����
    char *p = ch;  //�ܾ��� ó�� �ּ� ����
    //������ ó�� �ܾ� �̹Ƿ� ó���� ch�� �Ҵ�
    for (char *pch = ch; pch <= ch + strlen(ch); pch++) //������ ó������ ������ �����ͷ� ���캻��
    {
        if (*pch == ' ' || *pch == '\0') //���� Ȥ�� ���Ṯ�� �϶�
        {
            strncpy(word[point], p, size); //word�� �ܾ��� ù�ּ� p�� �ܾ��� ũ�⸦ ���� ����
            word[point][size] = '\0';      //�ܾ��� �������� ���� ���ڸ� ����
            size = -1;                     //������ �ʱ�ȭ �̶� �ڿ� size++�� �����Ƿ� -1�� ����
            p = pch + 1;                   //���� ���� ������ ���ο� �ܾ��̹Ƿ� p�� pch+1�� ����
            point++;                       //���ο� �ܾ �������Ƿ� point�� �ø�
        }
        size++; //���� Ȥ�� ���ᰡ ���� ��� �ܾ��� ũ�Ⱑ �þ
    }
    for (int i = 0; i < point; i++)
        puts(word[i]); //word�� ����� �ܾ ������� ���

    int rank[10] = {0}; //���ĺ� ������� ����ϱ� ���� rank ���� ���� �� 0�ʱ�ȭ

    for (int i = 0; i < point; i++)
    {
        for (int j = 0; j < point; j++)
        {
            if (strcmp(word[i], word[j]) > 0) //i�� �ܾ�� j�� �ܾ ���ؼ� strcmp�� ũ�� i�� �� ���� ����
                rank[i]++;                    //rank�� ���� ��Ų��
        }
    }

    for (int i = 0; i < point; i++) //rank�� ó������ ������ ���캸�� ����
    {
        if (rank[i] == 0)  //rank�� 0�ϰ�� ��ó�� ����
            puts(word[i]); //�ش� i�� word�� ���
    }
    return 0;
}
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
    puts(pch[k - 1]); //k��° ���ڿ� ���
    char *sort[100];  //���ǿ� �´� ���� ������ �迭
    int size2 = 0;    //���ǿ� ���� ������ ����

    int found = 0;
    for (char *p = ch; p <= ch + ch_size;) //�ʱ� ���ڿ� ���� Ȯ���ϱ� ����
    {
        int cnt = 0; //��ġ�ϴ� ������ ����
        int no = 0;  //����ġ�ϴ� ������ ����

        if (p == pch[k - 1])       //ã�� �ּҰ� k��° ���ڿ��� �ּҿ� ��ġ�ϴ� ���
            p = p + strlen(p) + 1; //ã�� �ʿ䰡 �����Ƿ� ���� �ܾ� ��ġ�� �ּ� ����

        for (char *q = p; q < p + strlen(p); q++) //��ġ�ϴ� �ܾ ã�� ����
        {
            found = 0;                                                                    //�ܾ ã�� �ٸ� 1�� ��ȯ
            for (char *p_ch = pch[k - 1]; p_ch < pch[k - 1] + strlen(pch[k - 1]); p_ch++) //k���ڸ� Ȯ�� �Ѵ�.
            {
                if (*q == *p_ch) //k���ڿ��� ã�� ���ڰ� ���� �ҽ�
                {
                    cnt++;     //���ǿ� �´� ���� ���� ���
                    found = 1; //ã�����Ƿ� found 1�� ����
                }
            }
            if (found == 0) //ã�� ���Ͽ��� ���
                no++;       //����ġ ���� ���
        }
        //printf("cnt no strlen:%d %d %d\n", cnt, no, strlen(pch[k - 1]));
        if ((cnt >= strlen(pch[k - 1]) - 1 && cnt <= strlen(pch[k - 1]) + 1) && no < 2)
        {                      //cnt�� ������ k���ڿ��Ǽ� +-1�϶� �� no�� 2�� �����϶� ���� 1, 2�� ����
            sort[size2++] = p; //sort������ �迭�� p���ڿ��� ù�ּҸ� �����ϰ� ���� ����
        }
        p = p + strlen(p) + 1; //���� ������ ���ڿ��� ã�� �ּҸ� �̵�
    }

    for (int i = 0; i < size2 - 1; i++) //���� ����
    {
        for (int j = 0; j < size2 - i - 1; j++)
        {
            if (strlen(sort[j]) < strlen(sort[j + 1])) //���� �ܾ �� ����
            {
                char *tmp = sort[j];
                sort[j] = sort[j + 1];
                sort[j + 1] = tmp; //���� �ܾ �� ��� ������ �ٲ㼭 ������ ����
            }
            if (strlen(sort[j]) == strlen(sort[j + 1])) //�ܾ��� ���̰� ���� ���
            {
                if (strcmp(sort[j], sort[j + 1]) > 0) //���ڿ��� Ȯ���Ͽ� ���� �� ���� ������ ���
                {
                    char *tmp = sort[j]; //������ ���
                    sort[j] = sort[j + 1];
                    sort[j + 1] = tmp; //���ڿ� �ּ� ��ȯ
                }
            }
        }
    }

    for (int i = 0; i < size2; i++) //���ĵ� sort�ּ� Ž��
        puts(sort[i]);              //Ž���� sort���ڿ��� ���

    return 0;
}
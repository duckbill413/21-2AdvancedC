#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st
{
    //����ü st ����
    char *str;   //���ڿ� ����
    int cnt;     //���� �� ����
    int cnt2;    //���� �� ����
    int num;     //���� ����
    int result1; //�������1����
    int result2; //�������2����
} ST;            //����üst�� ST�� ������

void numOfComponent(ST *);     //������, ������, ���ڸ� ������ �Լ�
void complexOfComponent(ST *); //�������1, �������2�� ������ �Լ�

int main()
{
    int N;
    scanf("%d", &N);
    getchar();
    // N�� ������ ���� ���� ���� �� �Է�

    ST *st = NULL;
    st = (ST *)malloc(sizeof(ST) * N); // N�� ��ŭ ST����ü �����Ҵ�
    if (st == NULL)
        return -1; //�����Ҵ� ���н� ����

    for (ST *pst = st; pst < st + N; pst++) // N�� ��ŭ ����
    {
        char tmp[101];
        scanf("%s", tmp);
        getchar();
        //�ӽ� �迭�� ���� ���ڿ��� �Է� �ް� ���� ����
        int size = strlen(tmp);
        pst->str = NULL;
        pst->str = (char *)malloc(sizeof(char) * (size + 1)); //����ü ���ڿ��� ���ڰ���+1����ŭ �����Ҵ�
        if (pst->str == NULL)
            return -1; //�����Ҵ� ���н� ����

        strcpy(pst->str, tmp);   //����ü ���ڿ��� tmp���ڿ��� ����
        numOfComponent(pst);     //������, ������, ���ڸ� ������ �Լ�
        complexOfComponent(pst); //�������1, �������2�� ������ �Լ�
    }

    for (ST *pst = st; pst < st + N - 1; pst++) //���� ���� ���
    {
        for (ST *qst = st; qst < st + N - (pst - st) - 1; qst++)
        {
            if (qst->result1 < (qst + 1)->result1) //�������1 ��
            {                                      //������������ swap�Ͽ� ����
                ST tmp = *qst;
                *qst = *(qst + 1);
                *(qst + 1) = tmp;
            }
            else if (qst->result1 == (qst + 1)->result1 && qst->result2 < (qst + 1)->result2)
            { //�������1�� ������ �������2�� �� �������� ����
                ST tmp = *qst;
                *qst = *(qst + 1);
                *(qst + 1) = tmp;
            }
        }
    }

    for (ST *pst = st; pst < st + N; pst++)
        printf("%s\n", pst->str); //����ü ���ڿ��� ������� ���

    for (int i = 0; i < N; i++)
        free(st[i].str); //����ü ���ڿ��� free���ش�
    free(st);            // st����ü�� free���ش�.
    return 0;
}

void numOfComponent(ST *st)
{
    int cnt_vowel = 0; //������ ���� ī��Ʈ

    for (char *p = st->str; p < st->str + strlen(st->str); p++) //����ü�� ���ڿ��� �˻�
    {
        if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'u' || *p == 'o' ||
            *p == 'A' || *p == 'E' || *p == 'I' || *p == 'U' || *p == 'O') //������ ���
            cnt_vowel++;                                                   //���� ����++
        else if (*p >= '0' && *p <= '9')                                   //����ü ���ڿ� �� ���� �߰�
        {
            st->num = *p - '0'; //����ü�� ���� ��ҿ� ���� ����
        }
    }
    st->cnt2 = cnt_vowel;                      //���� ���� ���� �Ѵ�
    st->cnt = strlen(st->str) - cnt_vowel - 1; //������ ���� ��ü ���ڼ� - (������+����1��);
}

void complexOfComponent(ST *st)
{
    int big, small;                                              //������ ���� �� ū �Ͱ� ���� ���� ����
    st->cnt > st->cnt2 ? (big = st->cnt) : (big = st->cnt2);     //ū ���� big�� ����
    st->cnt > st->cnt2 ? (small = st->cnt2) : (small = st->cnt); //���� ���� small�� ����

    st->result1 = big * st->num;   //������� 1�� ����*big ����
    st->result2 = small * st->num; //������� 2�� ����*small ����
}

/*
5
His0tory
3Politics
2DonQuixote
LaPest9e
Chaos5

result)
LaPest9e
Chaos5
3Politics
2DonQuixote
His0tory
*/
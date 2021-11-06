#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
typedef struct subject
{
    char *name;   // ���� �̸�
    double score; // ���� ����
} sub;

typedef struct student
{
    char *name;           // �л� �̸�
    char id[5];           // �л� �й�
    int numSubject;       // ���� ����
    struct subject *psub; // ���� ����ü ������
    double avg;           // ��� ������ ��� ����
} st;

int main()
{
    int N, M;             //�Ҵ���� ����ü ũ��
    st *p = NULL, tmp;    //�޸� �Ҵ���� ����ü ������ ����, ������ ���� tmp
    char c[101] = {NULL}; //�Է¹��� ���ڿ� ���� ����
    scanf("%d", &N);
    getchar();
    p = (st *)calloc(N, sizeof(st)); //����ü�� �����Ҵ�
    for (int i = 0; i < N; i++)
    {
        gets(c);                                   //���ڿ� ��ü�� �Է¹ޱ�
        int cnt = 0, j = 0, k = 0, q = 0, sum = 0; //������ ���� ���� �� �ʱ�ȭ
        int CNT = 0;                               //���� ���� ������ ����
        p[i].avg = 0;                              //��� 0���� �ʱ�ȭ

        for (j = 0; c[j] != ' '; j++)
            cnt++;                                         //�л��̸��� ũ�� ����(���� ������ cnt����)
        p[i].name = (char *)calloc(cnt + 1, sizeof(char)); //�ش� ũ�⸸ŭ �޸� �Ҵ�
        for (j = 0; j < cnt; j++)
        {
            p[i].name[q] = c[j];
            q++;
            p[i].name[q] = '\0';
        }
        //����ü ���� name���ڿ��� c���ִ� ���� �־��ֱ�(���ڸ� ������ �־���)
        q = 0;
        for (k = j + 1; k < j + 5; k++)
        {
            p[i].id[q] = c[k];
            q++; //���� �������� 4�ڸ��� �й� �־��ֱ�
        }
        p[i].id[4] = '\0'; // NULL���� �־��ֱ�
        for (int w = j + 5; c[w] != '\0'; w++)
        {
            if (c[w] == ' ')
                CNT++; // ���� ���� ���
        }
        p[i].numSubject = CNT / 2;                               //���� ���� /2 �� ���� ������ ��
        p[i].psub = (sub *)calloc(p[i].numSubject, sizeof(sub)); //���� ������ŭ ���� ����ü�� �޸� �Ҵ�

        int w = k; // k�� ������ ����
        cnt = 0;
        for (int h = 0; h < p[i].numSubject; h++)
        {
            cnt = 0;
            sum = 0;
            q = 0; //���� ���� �ʱ�ȭ
            for (int r = w + 1; c[r] != ' '; r++)
                cnt++;                                                 //�����̸� ũ�� ����(����� ���� ����)
            p[i].psub[h].name = (char *)calloc(cnt + 1, sizeof(char)); //�����Ҵ� (����ü�ȿ� ����ü������, (����ü.����ü.���))
            q = 0;
            for (w = w + 1; c[w] != ' '; w++)
            {
                p[i].psub[h].name[q] = c[w];
                q++;
                p[i].psub[h].name[q] = '\0';
            }
            //���� ����ü�� ���� �̸� �־��ֱ�
            if (c[w + 1] >= '0' && c[w + 1] <= '9') //�״��� ������ʹ� ������ ������
            {
                sum *= 10;
                sum += c[w + 1] - '0';
                if (c[w + 2] >= '0' && c[w + 2] <= '9') //������ ���ڸ� ������ ��ȯ
                {
                    sum *= 10;
                    sum += c[w + 2] - '0';
                    if (c[w + 3] >= '0' && c[w + 3] <= '9') // 100���ϰ�� (3�ڸ��̹Ƿ�)
                    {
                        sum *= 10;
                        sum += c[w + 3] - '0';
                        w++; //���� ������ŭ w�������������
                    }
                    w++;
                }
                w++;
            }
            w++;
            p[i].psub[h].score = (double)sum; //�� ��ȯ �� ����
            p[i].avg += p[i].psub[h].score;   //��տ� �� ���� �����ְ�
        }
        p[i].avg /= (double)p[i].numSubject; //������ŭ �����ְ�
    }

    scanf("%d", &M); //�� �Է¹ޱ�
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if (p[j].avg < p[j + 1].avg) //
            {
                tmp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tmp; //��� ũ�⿡ ���� ����ü�� �������� ����
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if (p[j].avg == p[j + 1].avg)
            {
                if (strcmp(p[j].id, p[j + 1].id) > 0)
                {
                    tmp = p[j];
                    p[j] = p[j + 1];
                    p[j + 1] = tmp;
                } //��� ũ�⿡ ���� ����ü�� �������� ����
            }
        }
    }

    double maxscore = 0;                          //�ְ����� ������ ����
    char maxsub[100] = {NULL};                    //�ְ� ������ �ش��ϴ� �����̸��� ������ ����
    strcpy(maxsub, p[M - 1].psub[0].name);        //ù��° �������� �ʱ�ȭ
    for (int i = 0; i < p[M - 1].numSubject; i++) //�Է¹��� �ε��� �ȿ��� �ִ����� ã��
    {
        if (maxscore < p[M - 1].psub[i].score)
        {
            maxscore = p[M - 1].psub[i].score;
            strcpy(maxsub, p[M - 1].psub[i].name);
        } //�ְ������� ���� �� �����̸��� ã�´�.
    }
    printf("%s %s %.2lf %s %.2lf", p[M - 1].name, p[M - 1].id, p[M - 1].avg, maxsub, maxscore);
    //�ش� �ε����� ���� ���(M��° �̸� �ε����� M-1)

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < p[i].numSubject; j++)
        {
            free(p[i].psub[j].name);
        }
        free(p[i].name);
        free(p[i].psub);
    }
    free(p);
    return 0;
}
// by 19011851
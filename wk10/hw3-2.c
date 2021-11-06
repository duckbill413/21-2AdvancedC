#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student
{
    char *name;           //�л� �̸�
    char id[5];           //�л� �й�
    int numSubject;       //���� ����
    struct subject *psub; //���� ����ü ������
    double avg;           //��� ������ ���
} Student;

typedef struct subject
{
    char *name;   //���� �̸�
    double score; //���� ����
} Subject;

int main()
{
    int N;
    scanf("%d", &N); //�Է� ���� �л� �� �Է�
    getchar();       //���� ����

    Student *st = NULL;
    if ((st = (Student *)malloc(sizeof(Student) * N)) == NULL)
        return -1; //�л� ����ü�� �����ϰ� N�� ��ŭ ���� �迭���ش� ���н� ����

    for (Student *pst = st; pst < st + N; pst++) //�л� ����ü�� ���ؼ� ���� ����.
    {
        char tmp[101];
        gets(tmp);            // tmp�� ���� ���ڿ��� �Է�
        int chap = 0;         //�۾� ���ÿ� ����
        int numOfSubject = 0; //���� ���� ī��Ʈ ����

        pst->psub = NULL;
        if ((pst->psub = (Subject *)malloc(sizeof(Subject) * 100)) == NULL)
            return -1; //������ 100�� ��ŭ ���� �Ҵ��ϰ� ���н� ����
        //���� realloc���� ũ�� ���� ����

        int size = 0;                                             //���� ���ڵ��� ũ�⸦ ī��Ʈ�ϱ� ���� ����
        for (char *ptmp = tmp; ptmp <= tmp + strlen(tmp); ptmp++) //���ڿ� Ž��
        {
            if (*ptmp == ' ' || *ptmp == 0) //����, ���� ������ ���
            {
                if (chap == 0) //�л� �̸� �Է�
                {
                    pst->name = NULL;
                    if ((pst->name = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
                        return -1;                         //�л� �̸��� ������+1 ��ŭ ���� �Ҵ� ���н� ����
                    strncpy(pst->name, ptmp - size, size); //�л��̸� �Է�
                    pst->name[size] = 0;                   //�������� ���� ���� ����
                    chap++;                                //���� �۾�
                }
                else if (chap == 1) //�л� �й� �Է�
                {
                    strncpy(pst->id, ptmp - size, size); //������(4)��ŭ �Է�
                    pst->id[4] = 0;                      //���� ���� ����
                    chap++;                              //���� �۾�
                }
                else if (chap == 2) //����� �Է�
                {
                    pst->psub[numOfSubject].name = NULL;
                    if ((pst->psub[numOfSubject].name = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
                        return -1;                                            // 0���� �����ϴ� numOfSubject�� ���Ͽ� size+1��ŭ ���� �Ҵ� ���н� ����
                    strncpy(pst->psub[numOfSubject].name, ptmp - size, size); //���� �̸� �Է�
                    pst->psub[numOfSubject].name[size] = 0;                   //������ ���� ���� ����
                    chap++;                                                   //���� ���� �Է� ���
                }
                else if (chap == 3) //���� ���� �Է�
                {
                    int sum = 0; //���ڸ� ������ ��ȯ�ϱ� ���� ����
                    for (char *num = ptmp - size; num < ptmp; num++)
                        sum = sum * 10 + (*num - '0');           //������ ũ�⸸ŭ ���ڿ��� ���������� ��ȯ�� �ش�.
                    pst->psub[numOfSubject].score = (double)sum; //��ȯ ������ ����ü�� ����

                    chap = 2;                       //����� �Է� ���� ��ȯ
                    numOfSubject++;                 //���� ���� ����
                    pst->numSubject = numOfSubject; //���� ������ ����ü�� �Է�
                }
                size = -1;
            }
            size++;
        }

        pst->psub = (Subject *)realloc(pst->psub, sizeof(Subject) * numOfSubject);
        //Ȯ���� ���� ������ŭ ����ü�� ���Ҵ� ���ش�.
        double sum = 0.0; //����� ���� ����
        for (int i = 0; i < numOfSubject; i++)
            sum += pst->psub[i].score;      //���� ���� ��ŭ �ش��ϴ� ������ ���Ѵ�.
        pst->avg = sum / (pst->numSubject); //������/���� ������ ��� ���� ����
    }

    int find;
    scanf("%d", &find); //ã�� ���� ��ȣ �Է�
    find -= 1;          //�ּҿ� �ش��ϹǷ� -1���ش�.

    for (Student *p = st; p < st + N - 1; p++) //����ü�� ���Ͽ� �������ķ� Ž��
    {
        for (Student *q = st; q < st + N - (p - st) - 1; q++)
        {
            if (q->avg < (q + 1)->avg) //��տ� ���Ͽ� �������� ����
            {
                Student tmp = *q;
                *q = *(q + 1);
                *(q + 1) = tmp; //����ü swap
            }
            else if (q->avg == (q + 1)->avg && strcmp(q->id, (q + 1)->id) > 0)
            { //����� ���� ��� �й��� ���Ͽ� ����
                Student tmp = *q;
                *q = *(q + 1);
                *(q + 1) = tmp; //����ü swap
            }
        }
    }

    double big = st[find].psub->score; //ù��° ���ڿ� ���Ͽ� big ������ ����
    int pointBig = 0;                  //���� ū ���� ��� ���ִ� ��ġ
    for (int i = 0; i < st[find].numSubject; i++)
    {                                     //ã�� ���� �л��� ���Ͽ� Ž��
        if (st[find].psub[i].score > big) //���� ������ �� ũ��
        {
            big = st[find].psub[i].score; // big�� ������ �ְ�
            pointBig = i;                 // pointBig�� �ش� ��ġ�� �Է�
        }
    }

    printf("%s %s %.2lf %s %.2lf", st[find].name, st[find].id, st[find].avg, st[find].psub[pointBig].name, st[find].psub[pointBig].score);
    //�л� �̸�, �й�, ��� ����, ã�� ��ġ�� ���� ���� �̸�, ã�� ��ġ�� ���� ���� ����
    for (int i = 0; i < N; i++)
    {
        free(st[i].name);                          //�л� ����ü�� �̸� �޸� ��ȯ
        for (int j = 0; j < st[i].numSubject; j++) //��� ���� ���Ͽ� Ž��
            free(st[i].psub[j].name);              //������ �̸� �޸� ��ȯ
        free(st[i].psub);                          //�л��� ���� ����ü �޸� ��ȯ
    }
    free(st); //�л� ����ü �޸� ��ȯ
    return 0;
}

/*
test case)
5
HongGilDong 1003 Math 85 C 80 AdvC 90
JeonWooChi 1001 English 60 C 75 Physics 80 Math 70
HeungBoo 1002 Economics 80 AdvC 90 Math 80 C 90
NolBoo 1004 Ethics 50 C 62
Euler 1005 Math 100 Physics 90 AdvC 85
2

result)
HeungBoo 1002 85.00 AdvC 90.00
? �л� �̸�, �й�, ��� ����, ���� ������ ���� ���� �̸�, ���� ���� ���� ����
*/
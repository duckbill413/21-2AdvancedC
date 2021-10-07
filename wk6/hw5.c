#include <stdio.h>
#include <string.h>
typedef struct student //�л� ����ü ����
{
    char name[31];      //�̸�
    int id;             //�й�
    int class_num;      //���� ����
    char class[10][31]; //������ �̸�
    double score[10];   //���� ���� ����
} Stud;                 //�л� ����ü�� Stud�� ������

void sort_s(Stud S[], int cnt);      //�������� ������ ���� �Լ�
void input(Stud *);                  //�л����� �Է� �Լ�
void output(Stud *, int);            //�л����� ��� �Լ�
void delete (Stud *, int *, char[]); //�л� ���� ���� �Լ�

int main()
{
    Stud st[100];      //100�� ������ �л� ���� ���� ����
    int num = 0;       //�л� �ο���
    char order;        //���û��� �Է�
    char del_name[31]; //������ �̸�

    while (1)
    {
        scanf("%c", &order); //���û��� �Է�
        if (order == 'Q')    //Q�Է½� ����
            return 0;

        if (order == 'I')      //I�Է½� input �Լ� ����
            input(&st[num++]); //�Լ��� �Է��� ����ü ��ġ �Է��� �л��� ����
        else if (order == 'P') //P�Է½� output�Լ� ����
            output(st, num);
        else if (order == 'D') //D�Է½� delete�Լ� ����
        {
            getchar();                   //���û��� �Է½��� enter���� ����
            gets(del_name);              //������ �̸� �Է�
            delete (st, &num, del_name); //������ �̸��� �л��� ������ ���� ����
            //num--;
        }
        else if (order == 'S') //S�ϰ�� sort_s�Լ��� ���� �� ���
            sort_s(st, num);
    }

    return 0;
}

void input(Stud *s)
{
    int num = 0;                                       //����� �Է��� ����
    scanf("%s %d %d", s->name, &s->id, &s->class_num); //�̸�, �й�, ����� �Է�
    for (int i = 0; i < s->class_num; i++)             //����� ��ŭ ������ ���� �Է�
    {
        getchar();                                        //���� scanf�κ����� ���� ����
        scanf("%s %lf", s->class[num], &s -> score[num]); //class��, ���� �Է�
        num++;                                            //���� �Է��� ���� ����
    }
}

void output(Stud *s, int n)
{
    double score = 0.0; //��ü ������ ���� score ����
    for (Stud *p = s; p < s + n; p++)
    {
        score = 0.0; //score �ʱ�ȭ
        for (int i = 0; i < p->class_num; i++)
        {
            score += p->score[i]; //��� ���� ���Ͽ� ���� ������ ���Ѵ�.
        }
        score /= p->class_num;                                           //���� ���� ������ ������� ������ ������ ���
        printf("%s %d %d %.2lf\n", p->name, p->id, p->class_num, score); //�̸�, �й�, �����, ��ü���� ���
    }
}

void delete (Stud *s, int *n, char del[31])
{
    int found = 0;                     //ã�� ��� Ȯ���� ���� ����
    for (Stud *p = s; p < s + *n; p++) //�ּҸ� �̿��� ����ü Ȯ��
    {
        if (!strcmp(p->name, del) || found == 1) //���� �̸��� ã�ų� found=1�ϰ��
        {
            if (!found) //found�� 0�̸� 1�� �ٲٰ� ��ü �ο��� 1����
            {
                found = 1;
                (*n)--;
            }
            *p = *(p + 1); //��ĭ�� ����ü�� ����.
        }
        else if (found == 0 && !strcmp(p->name, del) && p == s + *n - 1)
            (*n)--;
        //������ ����ü�� ã�� ����ü�ΰ�� ��ü �ο����� ���ҽ�Ų��
    }
}

void sort_s(Stud s[100], int cnt)
{
    Stud S_sort[100]; //���� ����ü ���� ����
    for (int i = 0; i < cnt; i++)
        S_sort[i] = s[i]; //��ü ����ü�� ���Ͽ� ����

    for (Stud *i = S_sort; i < S_sort + cnt; i++) //��������
    {
        for (Stud *j = i + 1; j < S_sort + cnt; j++)
        {
            if (strcmp(i->name, j->name) > 0) //�������� ����
            {
                Stud tmp = *i;
                *i = *j;
                *j = tmp; //����ü ��������
            }
        }
    }
    output(S_sort, cnt); //�������� ���ĵ� S_sort����ü�� ���
}
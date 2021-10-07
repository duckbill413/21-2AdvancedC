#include <stdio.h>
#include <string.h>

struct hotel_info
{
    char name[31];//ȣ�� �̸�
    int grade;//���
    double score;//���ǵ�
    double range;//�Ÿ�
    char food;//���Ŀ���
};

int in_hotel_info(struct hotel_info *p);
//ȣ���� �̸�, ���, ���ǵ�, �Ÿ�, �������Կ��θ� ����ڷκ��� �Է� �޾� �迭�� ����
void out_hotel_info(struct hotel_info *p, int N, int G, double D);
//�迭�� ����� ȣ�� �� G �̻��� ��ް� D ������ �Ÿ��� ���� ȣ���� �˻��Ͽ�, �� �� ���ǵ��� ���� ���� ȣ���� ������ ȭ�鿡 ���

int main()
{
    struct hotel_info hi[100];//�ʴ� 100���� ȣ��
    int num = in_hotel_info(hi);//ȣ�� ������ �Է� �ް� num�� ȣ���� �� �Է�
    int G;
    double D;
    scanf("%d %lf", &G, &D);//����ڷκ��� ��ް� �Ÿ��� �Է� �޴´�.

    out_hotel_info(hi, num, G, D);//���ǿ� �´� ȣ���� �˻��ϰ� ���

    return 0;
}

int in_hotel_info(struct hotel_info *p)
{
    struct hotel_info *hi;
    for (hi = p;; hi++)
    {
        scanf("%s", hi->name);//hi�� ���� ȣ�� �̸� �Է�
        if (!strncmp(hi->name, "0", 1))//ȣ���̸��� 0�̸� ����
            break;
        scanf("%d %lf %lf %c", &hi->grade, &hi->score, &hi->range, &hi->food);//�� ���� ������ �Է�
    }
    return hi - p;//hi������ �ּҿ� p�ּ� ������ �Ÿ��� ȣ���� ���̴�.
}

void out_hotel_info(struct hotel_info *p, int N, int G, double D)
{
    struct hotel_info *hi;
    struct hotel_info sort[100];//������ ���� sort����ü ���� ����
    int found = 0;

    for (hi = p; hi < p + N; hi++)
    {
        if (hi->grade >= G && hi->range <= D)//ȣ���� �˻��Ͽ� ���ǿ� �´� ���
        {
            sort[found++] = *hi;//sort��ü�� ȣ���� �ְ� ã�� ȣ�� ������ ����
        }
    }

    //����
    struct hotel_info tmp;//swap�� ���� �ӽ� ����
    for (struct hotel_info *i = sort; i < sort + found; i++)
    {
        for (struct hotel_info *j = i + 1; j < sort + found; j++)
        {
            if (i->score < j->score)//���� ������ �̿��Ͽ� ������ ������ ������ ������ ������ ���� �ð���.
            {//score�� �� ���ǵ� ������ ����
                tmp = *i;
                *i = *j;
                *j = tmp;//����ü ���� ����
            }
            else if (i->score == j->score && strcmp(i->name, j->name) > 0)
            {//���ǵ��� ���� ��� strcmp�� �̿��Ͽ� ��Ī�� �̿��� ���� ����
                tmp = *i;
                *i = *j;
                *j = tmp;//����ü ���� ����
            }
        }
    }

    for (struct hotel_info *p = sort; p < sort + found; p++)//���ĵ� ����ü�� ����Ѵ�.
        printf("%s %d %.1lf %.1lf %c\n", p->name, p->grade, p->score, p->range, p->food);
}
#include <stdio.h>

struct bike_info //������ �뿩 ����ü ����
{
    int num;       //������ ��ȣ
    int phone;     //�� ��ȭ��ȣ
    char product;  //��ǰ S, D
    char sign;     //����� ���Կ��� Y, N
    int sign_kind; //����� ���� 7/30/180��
    int time;      //�뿩�ð�
    double won;    //���
};

void input(struct bike_info *p, int N);          //bike �뿩 ���� ����
void compute(struct bike_info *p, int N);        //bike �뿩 ��� ����
void display(struct bike_info *p, int N);        //������ �뿩 ��� ���
void bike_info_sort(struct bike_info *p, int N); //��ǰ �� ������ ��ȣ�� ���Ͽ� ���� ���� ����

int main()
{
    struct bike_info bi[100]; //100���� ������ ����ü ���� ����
    int n;
    scanf("%d", &n);       //������ ���� �Է�
    input(bi, n);          //n���� ������ ���� �Է�
    compute(bi, n);        //n���� ������ �뿩 ��� ����
    bike_info_sort(bi, n); //������ �����͸� ����
    display(bi, n);        //������ ���� ���
    return 0;
}

void input(struct bike_info *p, int N)
{
    for (struct bike_info *pp = p; pp < p + N; pp++)
    {                                                          //�ּҸ� �̿��Ͽ� ������ ������ ���� ����.
        scanf("%d %d %c", &pp->num, &pp->phone, &pp->product); //�̸�, ��ȭ��ȣ, ��ǰ ���� �Է�
        if (pp->product == 'S')                                //��ǰ�� S�� ���
        {
            getchar();                                               //���� �����
            scanf("%c %d %d", &pp->sign, &pp->sign_kind, &pp->time); //����� ����, ����� ����, �뿩 �ð� �Է�
        }
        else                        //��ǰ�� D�� ���
            scanf("%d", &pp->time); //�뿩 �ð��� �Է�
    }
}

void compute(struct bike_info *p, int N)
{
    double total = 0.0;
    for (struct bike_info *pp = p; pp < p + N; pp++)
    {
        total = 0.0;                               //�뿩��� �ʱ�ȭ
        if (pp->product == 'S' && pp->sign == 'N') //��ǰ�� S�̸鼭 ������� ������
        {
            if (pp->sign_kind == 7)        //7�ϱ�
                total += 3000;             //3000�� �߰�
            else if (pp->sign_kind == 30)  //30�ϱ�
                total += 5000;             //5000�� �߰�
            else if (pp->sign_kind == 180) //180�� ��
                total += 15000;            //15000�� �߰�
        }
        else if (pp->product == 'D') //��ǰ�� D�ϰ�� 1000�� �߰�
            total += 1000;

        if (pp->time > 60) //�뿩�ð��� 60�� �ʰ�
        {
            total += (pp->time - 60) / 5 * 200; //�ʰ��Ƚð� /5�� 200���� ���Ͽ� ���
        }

        pp->won = total; //����ü�� �뿩��뿡 ����� �� ����
    }
}
void display(struct bike_info *p, int N)
{
    for (struct bike_info *pp = p; pp < p + N; pp++)
        printf("%d %d %c %.lf\n", pp->num, pp->phone, pp->product, pp->won);
    //N���� ����ü ������ ���Ͽ� ���� ���

    int total = 0, totalD = 0, totalS = 0; //S��ǰ �Ѿ�, D��ǰ �Ѿ�, ��ü �Ѿ� ���� ����
    for (struct bike_info *pp = p; pp < p + N; pp++)
    {
        if (pp->product == 'S')
        {                      //��ǰ�� S�ΰ��
            total += pp->won;  //��ü �Ѿ׿� �߰�
            totalS += pp->won; //S�Ѿ׿� �߰�
        }
        else
        {                      //��ǰ�� D�� ���
            total += pp->won;  //��ü �Ѿ׿� �߰�
            totalD += pp->won; //D�Ѿ׿� �߰�
        }
    }

    printf("%d %d %d", totalD, totalS, total); //D, S, ��ü �Ѿ��� ���
}
void bike_info_sort(struct bike_info *p, int N)
{
    for (struct bike_info *i = p; i < p + N; i++) //��������
    {
        for (struct bike_info *j = i + 1; j < p + N; j++)
        {
            if (i->product == 'S' && j->product == 'D') //���� ��ǰ�� S�̰� ���� ��ǰ�� D�ϰ��
            {                                           //D��ǰ���� ������ ������ �;��Ѵ�.
                struct bike_info tmp = *i;
                *i = *j;
                *j = tmp; //D��ǰ ������ �ڿ� ������ ���� ����
            }
        }
    }
    for (struct bike_info *i = p; i < p + N; i++) //��������
    {
        for (struct bike_info *j = i + 1; j < p + N; j++)
        {                                                    //��ǰ ������ ���ĵ� ����
            if (i->num > j->num && i->product == j->product) //��ǰ ���� ������ ���ϸ� �ȵ�
            {                                                //������ ��ȣ�� ���Ͽ� �����ϵ� ��ǰ�� �������� ����
                struct bike_info tmp = *i;
                *i = *j;
                *j = tmp; //����ü ���� ����
            }
        }
    }
}
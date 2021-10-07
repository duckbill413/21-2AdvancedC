#include <stdio.h>

struct bike_info
{
    int num;       //자전거 번호
    int phone;     //고객 전화번호
    char product;  //상품 S, D
    char sign;     //정기권 가입여부 Y, N
    int sign_kind; //정기권 종류 7/30/180일
    int time;      //대여시간
    double won;    //요금
};

void input(struct bike_info *p, int N);
void compute(struct bike_info *p, int N);
void display(struct bike_info *p, int N);
void bike_info_sort(struct bike_info *p, int N);

int main()
{
    struct bike_info bi[100];
    int n;
    scanf("%d", &n);
    input(bi, n);
    compute(bi, n);
    bike_info_sort(bi, n);
    display(bi, n);
    return 0;
}

void input(struct bike_info *p, int N)
{
    for (struct bike_info *pp = p; pp < p + N; pp++)
    {
        scanf("%d %d %c", &pp->num, &pp->phone, &pp->product);
        if (pp->product == 'S')
        {
            getchar();
            scanf("%c %d %d", &pp->sign, &pp->sign_kind, &pp->time);
        }
        else
            scanf("%d", &pp->time);
    }
}

void compute(struct bike_info *p, int N)
{
    double total = 0.0;
    for (struct bike_info *pp = p; pp < p + N; pp++)
    {
        total = 0;
        if (pp->product == 'S' && pp->sign == 'N')
        {
            if (pp->sign_kind == 7)
                total += 3000;
            else if (pp->sign_kind == 30)
                total += 5000;
            else if (pp->sign_kind == 180)
                total += 15000;
        }
        else if (pp->product == 'D')
            total += 1000;

        if (pp->time >= 60)
        {
            total += (pp->time - 60) / 5 * 200;
        }

        pp->won = total;
    }
}
void display(struct bike_info *p, int N)
{
    for (struct bike_info *pp = p; pp < p + N; pp++)
        printf("%d %d %c %.lf\n", pp->num, pp->phone, pp->product, pp->won);
}
void bike_info_sort(struct bike_info *p, int N)
{
    for (struct bike_info *i = p; i < p + N; i++)
    {
        for (struct bike_info *j = i + 1; j < p + N; j++)
        {
            if (i->product == 'S' && j->product == 'D')
            {
                struct bike_info tmp = *i;
                *i = *j;
                *j = tmp;
            }
        }
    }
    for (struct bike_info *i = p; i < p + N; i++)
    {
        for (struct bike_info *j = i + 1; j < p + N; j++)
        {
            if (i->num > j->num && i->product == j->product)
            {
                struct bike_info tmp = *i;
                *i = *j;
                *j = tmp;
            }
        }
    }

    for (struct bike_info *i = p; i < p + N; i++)
    {
        for (struct bike_info *j = i + 1; j < p + N; j++)
        {
            if (i->product == 'S' && j->product == 'D')
            {
                struct bike_info tmp = *i;
                *i = *j;
                *j = tmp;
            }
        }
    }
}
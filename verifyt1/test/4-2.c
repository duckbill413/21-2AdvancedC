#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)
typedef struct stock
{
    char sid[7];
    int qty;
    double cost;
    double total;
    /*
    ? sid : 주식 종목 코드를 저장할 문자 배열. 공백을 포함하지 않고, 최대길이는 6이다.
    ? qty : 주식 종목의 구매 수량을 나타내는 int형 변수
    ? cost : 주식 종목의 1주당 구매 가격을 나타내는 double형 변수
    ? total : 주식 종목을 구매한 총금액을 나타내는 double형 변수
    */
} Stock;

int input(struct stock *p, int N);
void put_stock_list(struct stock *p, char *stock_id, int qty, double cost);
void display(struct stock *p, int N);

int main()
{
    Stock st[20];
    int n;
    scanf("%d", &n);
    getchar();

    int size = input(st, n);
    display(st, size);

    return 0;
}
/*
4
005930 10 70
005930 20 72
005935 10 69
005930 10 73
*/

int input(struct stock *p, int N)
{
    int num[20] = {0};
    int size = 0;
    for (int i = 0; i < N; i++)
    {
        Stock new;
        scanf("%s %d %lf", new.sid, &new.qty, &new.cost);
        getchar();
        int found = 0;
        for (Stock *pp = p; pp < p + size; pp++)
        {
            if (!strcmp(new.sid, pp->sid))
            {
                // p->qty += new.qty;
                // p->total += new.cost *new.qty;
                // num[p - p]++;
                // found = 1;
                // break;
                found = 1;
                put_stock_list(pp, new.sid, new.qty, new.cost);
                break;
            }
        }
        if (!found)
        {
            put_stock_list(p + size, new.sid, new.qty, new.cost);
            size++;
        }
    }

    return size;
}

void put_stock_list(struct stock *p, char *stock_id, int qty, double cost)
{
    if (!strcmp(p->sid, stock_id))
    {
        p->cost = ((p->cost * p->qty) + (qty * cost)) / (p->qty + qty);
        p->qty += qty;
        p->total += qty * cost;
    }
    else
    {
        strcpy(p->sid, stock_id);
        p->qty = qty;
        p->cost = cost;
        p->total = qty * cost;
    }
}

void display(struct stock *p, int N)
{
    for (Stock *pp = p; pp < p + N; pp++)
    {
        printf("%s %d %.2lf %.2lf\n", pp->sid, pp->qty, pp->cost, pp->total);
    }
}

/*
ex1)
4
005930 10 70
005930 20 72
005935 10 69
005930 10 73
re->
005930 40 71.75 2870.00
005935 10 69.00 690.00

ex2)
6
005930 10 70
035720 10 117.5
005930 20 72
323410 30 80
035720 20 119.5
323410 20 57
re->
005930 30 71.33 2140.00
035720 30 118.83 3565.00
323410 50 70.80 3540.00
*/
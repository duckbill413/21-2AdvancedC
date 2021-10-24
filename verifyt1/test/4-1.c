#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
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

int input(struct stock* p, int N);
void put_stock_list(struct stock* p, char* stock_id, int qty, double cost);
void display(struct stock* p, int N);

int main()
{
    Stock st[20];
    int n;
    scanf("%d", &n);
    getchar();

    int num[20] = { 0 };
    int size = 0;
    for (int i = 0; i < n; i++)
    {
        Stock new;
        scanf("%s %d %lf", new.sid, &new.qty, &new.cost);
        getchar();
        int found = 0;
        for (Stock* p = st; p < st + size; p++)
        {
            if (!strcmp(new.sid, p->sid))
            {
                p->qty += new.qty;
                p->total += new.cost * new.qty;
                num[p-st]++;
                found = 1;
                break;
            }
        }
        if (!found)
        {
            *(st + size) = new;
            (st + size)->total = new.qty * new.cost;
            num[size]++;
            size++;
        }
    }
    for (Stock* p = st; p < st + size; p++)
    {
        p->cost = p->total / p->qty;
        printf("%s %d %.2lf %.2lf\n", p->sid, p->qty, p->cost, p->total);
    }

    return 0;
}
/*
4
005930 10 70
005930 20 72
005935 10 69
005930 10 73
*/
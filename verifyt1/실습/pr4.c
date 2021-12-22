#include <stdio.h>
#include <string.h>

typedef struct st
{
    char name[10];    //�л��̸�
    char book[5][20]; //�������� �� å �̸� (��) History Politics
    int score[5];     //�� å�� ���� �������� ���� (��) 60 40
    int cnt, pcnt;    //�������� �� å�� �Ǽ�, ����� å�� �Ǽ�
} St;

void input(St *pst, int n);

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    St st[100];

    input(st, n);

    for (St *p = st; p < st + n; p++)
    {
        printf("%s %d%%\n", p->name, p->pcnt * 20);
    }

    return 0;
}

void input(St *pst, int n)
{
    int num_book = 0;
    int pass = 0;
    for (St *p = pst; p < pst + n; p++)
    {
        num_book = 0;
        pass = 0;
        gets(p->name);
        while (1) //å, ����
        {
            scanf("%s", p->book[num_book]);
            getchar();
            if (strncmp(p->book[num_book], "0", 1) == 0)
                break;
            scanf("%d", &p->score[num_book]);
            getchar();
            if (p->score[num_book] >= 50)
                pass++;
            num_book++;
        }
        p->cnt = num_book;
        p->pcnt = pass;
    }
}
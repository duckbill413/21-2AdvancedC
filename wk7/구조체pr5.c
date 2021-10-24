#include <stdio.h>
#include <string.h>

typedef struct player
{
    char name[11];
    int health;
    int attack;
} Player;

int main()
{
    int n;
    scanf("%d", &n);

    Player py[10];
    for (Player *p = py; p < py + n; p++)
    {
        getchar();
        scanf("%s %d %d", p->name, &p->attack, &p->health);
    }
    getchar();

    int flag = 0;
    for (int i = 0; i < 5; i++)
    {
        char a[11], b[11];
        scanf("%s %s", a, b);
        getchar();
        for (Player *p = py; p < py + n; p++)
        {
            for (Player *q = py; q < py + n; q++)
            {
                if (!strcmp(p->name, a) && !strcmp(q->name, b))
                {
                    p->health -= q->attack;
                    q->health -= p->attack;

                    if (p->health <= 0)
                    {
                        p->health = 0;
                        flag = 1;
                    }
                    if (q->health <= 0)
                    {
                        q->health = 0;
                        flag = 1;
                    }
                }
            }
        }
        if (flag == 1)
            break;
    }
    for (Player *p = py; p < py + n - 1; p++)
    {
        for (Player *q = py; q < py + n - (p - py) - 1; q++)
        {
            if (q->health < (q + 1)->health)
            {
                Player tmp = *q;
                *q = *(q + 1);
                *(q + 1) = tmp;
            }
        }
    }
    for (Player *p = py; p < py + n; p++)
        printf("%s %d\n", p->name, p->health);

    return 0;
}

/*
5
Harry 50 100
Ron 5 40
Hermione 10 50
Voldemort 40 80
Hagrid 30 70
Harry Voldemort
Ron Hagrid
Hagrid Voldemort
*/
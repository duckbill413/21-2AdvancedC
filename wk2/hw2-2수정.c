#include <stdio.h>

int passengerN(int);
void rebooking(int *);
int changeseat(int *);

int main()
{
    int n;
    scanf("%d", &n);

    int seat[21] = {0};
    for (int *pseat = seat; pseat < seat + n; pseat++)
        scanf("%d", pseat);

    printf("%d\n", passengerN(n));
    if (passengerN(n) == -1)
        return 0;

    rebooking(seat);

    for (int *pseat = seat; pseat < seat + n; pseat++)
        printf("%d ", *pseat);

    return 0;
}
int changeseat(int *seat)
{
    int found = 0;
    for (int i = 1; i <= 21; i++)
    {
        found = 0;
        for (int *p = seat; p < seat + 21; p++)
        {
            if (i == *p)
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            return i;
            break;
        }
    }
}
void rebooking(int *seat)
{
    for (int *p = seat; p < seat + 21; p++)
    {
        for (int *q = seat; q < p; q++)
        {
            if (*p == *q)
            {
                *p = changeseat(seat);
                break;
            }
        }
    }
}
int passengerN(int n)
{
    if (n <= 5)
        return -1;
    else
        return 0;
}
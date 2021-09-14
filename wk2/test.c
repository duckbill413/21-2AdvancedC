#include <stdio.h>

int changeseat(int *arr)
{
    int m = 1;
    for (int i = 1; i <= 21; i++)
    {
        int found = 0;

        for (int *p = arr; p < arr + 21; p++)
        {
            if (i == *p)
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            m = i;
            break;
        }
    }
    return m;
}
int passengerN(int n)
{
    if (n < 5)
        return -1;
    else
        return 0;
}
void rebooking(int *arr)
{
    int *p, *q;
    for (p = arr; p < arr + 21; p++)
    {
        for (q = arr; q < p; q++)
        {
            if (*p == *q)
            {
                *p = changeseat(arr);
                break;
            }
        }
    }
}

int main() // main함수 선언
{
    int n;
    scanf("%d", &n);
    //승객수 입력
    int num[21] = {0}, *p, *q; //배열 n 과 매개포인터 선언
    for (int *ps = num; ps < num + n; ps++)
        scanf("%d", ps);

    printf("%d\n", passengerN(n));
    if (passengerN(n) == -1)
        return 0;

    rebooking(num);

    for (int *ps = num; ps < num + n; ps++)
        printf("%d ", *ps);
    return 0;
}
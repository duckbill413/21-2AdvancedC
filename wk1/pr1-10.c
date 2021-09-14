#include <stdio.h>

void gcdlcm(int, int, int *, int *);

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    int gcd, lcm;
    int *pgcd = &gcd, *plcm = &lcm; //최대공약수, 최소공배수

    gcdlcm(a, b, pgcd, plcm);

    printf("%d %d", *pgcd, *plcm);

    return 0;
}

void gcdlcm(int x, int y, int *gcd, int *lcm)
{
    int cnt = 1;
    while (x >= cnt && y >= cnt)
    {
        if (x % cnt == 0 && y % cnt == 0)
            *gcd = cnt;
        cnt++;
    }
    *lcm = *gcd * (x / *gcd) * (y / *gcd);
}
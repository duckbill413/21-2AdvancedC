#include <stdio.h>

typedef struct Time
{
    int hour, min, sec;
} time;

time time_minus(time a, time b);

int main()
{
    time t1, t2;
    scanf("%d %d %d", &t1.hour, &t1.min, &t1.sec);
    scanf("%d %d %d", &t2.hour, &t2.min, &t2.sec);

    time result = time_minus(t1, t2);
    printf("%d %d %d", result.hour, result.min, result.sec);
    return 0;
}

time time_minus(time a, time b)
{
    int time1 = a.hour * 3600 + a.min * 60 + a.sec;
    int time2 = b.hour * 3600 + b.min * 60 + b.sec;

    int result = time2 - time1;

    time r;
    r.hour = result / 3600;
    r.min = (result % 3600) / 60;
    r.sec = result % 60;
    return r;
}
#include <stdio.h>

typedef struct record
{
    int month, day, sale[20];
} Record;

int main()
{
    int n;
    scanf("%d", &n);

    Record re[10];

    for (Record *pre = re; pre < re + n; pre++)
    {
        int date;
        scanf("%d", &date);
        pre->month = date / 100;
        pre->day = date % 100;
        for (int i = 0; i < 20; i++)
        {
            scanf("%d", &pre->sale[i]);
            if (pre->sale[i] == 0)
                break;
        }
    }
    int fmonth, fday, fpr;
    scanf("%d %d %d", &fmonth, &fday, &fpr);

    int cnt = 0;
    for (Record *pre = re; pre < re + n; pre++)
    {
        if (pre->month == fmonth && pre->day == fday)
        {
            for (int i = 0; i < 20; i++)
            {
                if (pre->sale[i] == 0)
                    break;
                if (pre->sale[i] == fpr)
                    cnt++;
            }
        }
    }

    printf("%d", cnt);
    return 0;
}
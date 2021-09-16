#include <stdio.h>
#include <string.h>

int main()
{
    int num;
    scanf("%d", &num);

    char nch[9][6] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char tch[4][4] = {"THO", "HUN", "TEN", ""};

    int div = 1000;
    int nd = 0;
    while (div != 0)
    {
        if (num / div > 0)
        {
            printf("%s %s ", nch[num / div - 1], tch[nd]);
        }
        num %= div;
        div /= 10;
        nd++;
        //printf("r:%d %d %d\n", num, div, nd);
    }
    return 0;
}
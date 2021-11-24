#include <stdio.h>

int main()
{
    unsigned int result = 0x00000000;
    for (int i = 0; i < 4; i++)
    {
        int num;
        scanf("%d", &num);
        if (i != 0)
        {
            result = result << 8;
        }
        result = result | num;
        // printf("%08x\n", result);
    }
    printf("%d\n", result);
}
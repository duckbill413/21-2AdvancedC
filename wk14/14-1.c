#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fpout = NULL;
    FILE *fpin = NULL;

    fpin = fopen("data.txt", "w");
    if (fpin == NULL)
        return -1;

    char str[10];
    while (scanf("%s", str) != EOF)
        fprintf(fpin, "%s\n", str);

    fclose(fpin);
    fpout = fopen("data.txt", "r");
    if (fpout == NULL)
        return -1;

    int sum = 0, cnt = 0;
    while (1)
    {
        fscanf(fpout, "%s", str);
        if (feof(fpout))
            break;
        cnt++;
        int num = 0;
        for (int i = 0; i < strlen(str); i++)
            num = num * 10 + (str[i] - '0');
        sum += num;
    }
    fclose(fpout);
    printf("%d\n%d\n%.2lf", cnt, sum, sum / (double)cnt);
}
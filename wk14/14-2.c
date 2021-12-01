#include <stdio.h>
#include <string.h>
int main()
{
    FILE *fp;
    fp = fopen("test1.txt", "r");
    if (fp == NULL)
        return -1;

    FILE *fpout;
    fpout = fopen("test2.txt", "w");
    if (fpout == NULL)
        return -1;

    char ch[10];
    while (1)
    {
        fgets(ch, sizeof(ch), fp);
        if (feof(fp))
            break;
    }
    for (int i = 0; i < strlen(ch); i++)
    {
        if (ch[i] <= 'z' && ch[i] >= 'a')
            ch[i] -= 32;
        else
            ch[i] += 32;
    }
    fputs(ch, fpout);
    fclose(fp);
    fclose(fpout);
}
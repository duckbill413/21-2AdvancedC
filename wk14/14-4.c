#include <stdio.h>

int main()
{
    FILE *fpin1, *fpin2, *fpout;
    fpin1 = fopen("test4-1.txt", "r");
    if (fpin1 == NULL)
        return -1;
    fpin2 = fopen("test4-2.txt", "r");
    if (fpin1 == NULL)
        return -1;
    fpout = fopen("test4-3.txt", "w");
    if (fpin1 == NULL)
        return -1;

    char ch[50];
    while (fgets(ch, sizeof(ch), fpin1))
    {
        fputs(ch, fpout);
    }
    while (fgets(ch, sizeof(ch), fpin2))
    {
        fputs(ch, fpout);
    }

    fclose(fpin1);
    fclose(fpin2);
    fclose(fpout);
}
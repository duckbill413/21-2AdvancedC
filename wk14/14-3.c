#include <stdio.h>

int main()
{
    FILE *fpin, *fpout;
    fpin = fopen("test3.txt", "r");
    if (fpin == NULL)
        return -1;
    fpout = fopen("test4.txt", "w");
    if (fpout == NULL)
        return -1;

    while (1)
    {
        char ch = fgetc(fpin);
        if (feof(fpin))
            break;
        fputc(ch, fpout);
    }
    fclose(fpin);
    fclose(fpout);
}
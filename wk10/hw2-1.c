#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char tmp[101];
    gets(tmp);

    int size1 = 0, size2 = 0;
    for (char *ptmp = tmp; ptmp <= tmp + strlen(tmp); ptmp++)
        if (*ptmp == ' ' || *ptmp == 0)
            size1++;

    char **arr1 = NULL;
    if ((arr1 = (char **)malloc(sizeof(char *) * size1)) == NULL)
        return -1;
    char **parr1 = arr1;
    int size = 0;
    for (char *ptmp = tmp; ptmp <= tmp + strlen(tmp); ptmp++)
    {
        if (*ptmp == ' ' || *ptmp == 0)
        {
            char *new = NULL;
            if ((new = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
                return -1;
            strncpy(new, ptmp - size, size);
            *(new + size) = 0;

            *parr1++ = new;
            size = -1;
        }
        size++;
    }

    for (char **p = arr1; p < arr1 + size1 - 1; p++)
    {
        for (char **q = arr1; q < arr1 + size1 - (p - arr1) - 1; q++)
        {
            if (strlen(*q) < strlen(*(q + 1)))
            {
                char *tmp = *q;
                *q = *(q + 1);
                *(q + 1) = tmp;
            }
            else if (strlen(*q) == strlen(*(q + 1)) && strcmp(*q, *(q + 1)) > 0)
            {
                char *tmp = *q;
                *q = *(q + 1);
                *(q + 1) = tmp;
            }
        }
    }
    for (parr1 = arr1; parr1 < arr1 + size1; parr1++)
        printf("%s\n", *parr1);

    for (int i = 0; i < size1; i++)
        free(arr1[i]);
    free(arr1);

    return 0;
}

// red orange yellow green blue purple
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

    gets(tmp);
    for (char *ptmp = tmp; ptmp <= tmp + strlen(tmp); ptmp++)
        if (*ptmp == ' ' || *ptmp == 0)
            size2++;

    char **arr2 = NULL;
    if ((arr2 = (char **)malloc(sizeof(char *) * size2)) == NULL)
        return -1;
    char **parr2 = arr2;
    size = 0;
    for (char *ptmp = tmp; ptmp <= tmp + strlen(tmp); ptmp++)
    {
        if (*ptmp == ' ' || *ptmp == 0)
        {
            char *new = NULL;
            if ((new = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
                return -1;
            strncpy(new, ptmp - size, size);
            *(new + size) = 0;

            *parr2++ = new;
            size = -1;
        }
        size++;
    }

    char **arr3 = NULL;
    int size3 = size1 > size2 ? size2 : size1;
    if ((arr3 = (char **)malloc(sizeof(char *) * size3)) == NULL)
        return -1;

    size = 0;
    for (char **p = arr1; p < arr1 + size1; p++)
    {
        for (char **q = arr2; q < arr2 + size2; q++)
        {
            if (!strcmp(*p, *q))
                *(arr3 + size++) = *p;
        }
    }
    size3 = size;
    arr3 = (char **)realloc(arr3, sizeof(char *) * size3);

    for (char **p = arr3; p < arr3 + size3 - 1; p++)
    {
        for (char **q = arr3; q < arr3 + size3 - (p - arr3) - 1; q++)
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
    for (char **parr3 = arr3; parr3 < arr3 + size3; parr3++)
        printf("%s\n", *parr3);

    for (int i = 0; i < size1; i++)
        free(arr1[i]);
    free(arr1);
    for (int i = 0; i < size2; i++)
        free(arr2[i]);
    free(arr2);
    for (int i = 0; i < size3; i++)
        free(arr3[i]);
    free(arr3);

    return 0;
}

/*
red orange yellow green blue purple
pink red yellow black white purple
*/
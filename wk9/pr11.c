#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
void add_array(int **array, int *size);

int main()
{
    int size = 5;
    int *array = NULL;
    array = (int *)malloc(sizeof(int) * size);

    int i = 0;
    while (1)
    {
        scanf("%d", &array[i]);

        if (array[i] == -1)
            break;

        if (i + 1 == size)
            add_array(&array, &size);

        i++;
    }

    for (int j = 0; j < i + 1; j++)
        printf(" %d", array[j]);

    free(array);
    return 0;
}

void add_array(int **array, int *size)
{
    int s = *size + 3;
    int *tmp = NULL;
    tmp = (int *)malloc(sizeof(int) * s);

    for (int *p = tmp; p < tmp + *size; p++)
        *p = (*array)[p - tmp];

    free(*array);
    *array = tmp;
    *size = s;
}

/*
3 4 5 6 7 8 9 -1
*/
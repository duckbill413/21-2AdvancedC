#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, column;
    scanf("%d %d", &column, &row);

    char **array = NULL;
    array = (char **)malloc(row * sizeof(char *));
    if (array == NULL)
        return -1;
    for (int i = 0; i < row; i++)
    {
        array[i] = (char *)malloc(column * sizeof(char) + 1);
        if (array[i] == NULL)
            return -1;
    }

    char point = 'a';
    for (char **p = array; p < array + row; p++)
    {
        for (char *q = array[p - array]; q < array[p - array] + column; q++)
        {
            *q = point++;
            if (point == 'z' + 1)
                point = 'A';
            else if (point == 'Z' + 1)
                point = 'a';
        }
    }

    for (char **p = array; p < array + row; p++)
    {
        for (char *q = array[p - array]; q < array[p - array] + column; q++)
        {
            printf("%c ", *q);
        }
        printf("\n");
    }

    for (int i = 0; i < row; i++)
        free(array[i]);
    free(array);
    return 0;
}
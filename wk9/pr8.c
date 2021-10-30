#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    getchar();

    char **array = NULL;
    array = (char **)malloc(sizeof(char *) * n);
    if (array == NULL)
        return -1;

    for (char **p = array; p < array + n; p++)
    {
        char tmp[100] = {0};
        gets(tmp);
        int size = strlen(tmp);

        char *new = NULL;
        new = (char *)malloc(sizeof(char) * size + 1);
        if (new == NULL)
            return -1;

        strcpy(new, tmp);
        *p = new;
    }

    int min = strlen(*array);
    char *pmin = *array;
    for (char **p = array; p < array + n; p++)
    {
        if (min > strlen(*p))
        {
            min = strlen(*p);
            pmin = *p;
        }
    }

    printf("%s", pmin);
    for (int i = 0; i < n; i++)
        free(array[i]);
    free(array);

    return 0;
}

/*
4
Program
Good
This is string
language
*/
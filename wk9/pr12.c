#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    for (char **p = array; p < array + n - 1; p++)
    {
        for (char **q = array; q < array + n - (p - array) - 1; q++)
        {
            if (strcmp(*q, *(q + 1)) > 0)
            {
                char *tmp = *q;
                *q = *(q + 1);
                *(q + 1) = tmp;
            }
        }
    }

    for (char **p = array; p < array + n; p++)
        printf("%s\n", *p);

    for (int i = 0; i < n; i++)
        free(array[i]);
    free(array);
    return 0;
}
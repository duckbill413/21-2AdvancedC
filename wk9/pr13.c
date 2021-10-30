#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int *id = NULL;
    id = (int *)malloc(sizeof(int) * n);
    if (id == NULL)
        return -1;

    for (int *p = id; p < id + n; p++)
        scanf("%d", p);

    int delete;
    scanf("%d", &delete);

    realloc(id, sizeof(int) * (n - delete));

    for (int *p = id; p < id + n - delete; p++)
        printf("%d\n", *p);

    free(id);
    return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
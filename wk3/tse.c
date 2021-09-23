#include <stdio.h>
#include <string.h>

int main(void)
{
    int i;
    char c1[30] = "";
    char c2[30] = "go";

    strncpy(c1, c2, 2);
    printf("%s", c1);

    return 0;
}

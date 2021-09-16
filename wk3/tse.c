#include <stdio.h>
#include <string.h>

int main(void)
{
    int i;
    char c1[3] = "hi";
    char c2[3] = "hi";

    printf("%d", strcmp(c1, c2));
}

#include <stdio.h>

void main()
{

    int a = 1, b = 2, c = 3, i;

    int *pi[3];

    pi[0] = &a;

    pi[1] = &b;
    pi[2] = &c;

    for (i = 0; i < 3; ++i)
    {

        *pi[i] = *pi[i] * (-1);

        printf("%d\n", *pi[i]);
    }
}

#include <stdio.h>
void main()
{

    int a[3] = {1, 2, 3}, i;

    int b[3] = {4, 5, 6}, c[3] = {7, 8, 9};

    int *pi[3];

    pi[1] = b;

    printf("%d\n", *pi[1]);

    printf("%d\n", *(pi[1] + 1));

    printf("%d\n", pi[1][2]);
}

#include <stdio.h>

void main()
{

    char arr[6] = "Hello";

    char *str = arr;

    str[2] = 'L';

    scanf("%s", str);

    str = "Hi"; //------------1

    str[1] = 'e'; // ------------2

    scanf("%s", str); // ------------3

    str = arr; //------------4

    scanf("%s", str); // ------------5
}

#include <stdio.h>
void main()
{

    char str[20] = "HelloWorld";

    printf("%s!!\n", str + 6);
}
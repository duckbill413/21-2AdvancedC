#include <stdio.h>

typedef struct result
{
    int max, min;
    char char_pass;
    int int_pass;
    int diff;
} Result;
void passorfail(Result *);
int main()
{
    Result n;
    scanf("%d %d %d", &n.max, &n.min, &n.int_pass);
    passorfail(&n);
    printf("%d %c", n.diff, n.char_pass);
    return 0;
}

void passorfail(Result *test)
{
    test->diff = test->max - test->min;
    if (test->diff <= test->int_pass)
        test->char_pass = 'P';
    else
        test->char_pass = 'F';
}
#include <stdio.h>

void main()
{
    int word[5] = {'a', 'b', 'c', 'd', 'e'};
    int *pword;
    for (pword = word; pword < word + 5; pword++)
    {
        printf("%p %p\n", pword, word);
    }
}
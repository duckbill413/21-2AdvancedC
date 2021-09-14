#include <stdio.h>

void print(char *, int);

int main()
{
    char ch[100] = "";
    char *pch;
    int ch_size = 0;
    for (pch = ch; pch < ch + 100; pch++)
    {
        scanf("%c", pch);
        ch_size++;
        if (*pch == '*')
            break;
    }

    int size[3] = {0};
    int m_size = 0;
    int p = 0;
    char *mch;

    for (pch = ch; pch < ch + ch_size; pch++)
    {
        if (*pch == ' ' || *pch == '*')
        {
            if (size[p] > m_size || m_size == 0)
            {
                m_size = size[p];
                mch = pch - m_size;
                //printf("m_size: %d, size: %d %d %d\n", m_size, size[0], size[1], size[2]);
            }
            p++;
        }
        else if (pch < ch + ch_size - 1)
            size[p]++;
    }
    printf("%d\n%d\n%d\n", size[0], size[1], size[2]);
    print(mch, m_size);
}

void print(char *ch, int size)
{
    for (char *p = ch; p < ch + size; p++)
    {
        if (*p >= 'a')
            printf("%c", *p - 32);
        else
            printf("%c", *p);
    }
}
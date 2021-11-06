#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char tmp[101]; //���ڿ��� �Է� ���� �ӽ� �迭�� ����
    gets(tmp);     //���ڿ�1 �Է�

    int size1 = 0, size2 = 0;                                 //���ڿ�1, 2�� ������ ����
    for (char *ptmp = tmp; ptmp <= tmp + strlen(tmp); ptmp++) //���ڿ� ����
        if (*ptmp == ' ' || *ptmp == 0)                       //���ڿ�1���� ����, ���Ṯ�ڽ� ������ ����
            size1++;

    char **arr1 = NULL;                                           //���ڿ�1�� ���������ͷ� ����
    if ((arr1 = (char **)malloc(sizeof(char *) * size1)) == NULL) //�ּҸ� �����Ҵ�
        return -1;                                                // NULL�� ���н� ����
    char **parr1 = arr1;                                          // arr1�� �ּ� ����
    int size = 0;                                                 //������ ����
    for (char *ptmp = tmp; ptmp <= tmp + strlen(tmp); ptmp++)     //���ڿ� ����
    {
        if (*ptmp == ' ' || *ptmp == 0) //���� Ȥ�� ���� ������ ���
        {
            char *new = NULL; //�ӽ� ���ڿ� �ּ� ����
            if ((new = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
                return -1;                   //���ڿ� �ּҿ� size��ŭ �����Ҵ��ϰ� ���н� ����
            strncpy(new, ptmp - size, size); //�ӽ� ���ڿ� �ּҿ� ���� �Է�
            *(new + size) = 0;               //������ �ּҿ� ���Ṯ�� ����

            *parr1++ = new; //���ڿ�1�� �ӽ� ���ڿ� �ּҸ� �ְ� �ּҰ� ����
            size = -1;      //���� ���� �Է��� ���� ������ ����
        }
        size++;
    }

    gets(tmp);                                                //���ο� ���ڿ�2 �Է�
    for (char *ptmp = tmp; ptmp <= tmp + strlen(tmp); ptmp++) //���ڿ� ����
        if (*ptmp == ' ' || *ptmp == 0)                       //���ڿ�2���� ����, ���Ṯ�ڽ� ������ ����
            size2++;

    char **arr2 = NULL;                                           //���ڿ�2�� ���������ͷ� ����
    if ((arr2 = (char **)malloc(sizeof(char *) * size2)) == NULL) //�ּҿ� �����ŭ �����Ҵ�
        return -1;                                                //���н� ����
    char **parr2 = arr2;                                          // arr2�� �ּ� ����
    size = 0;                                                     //������ �ʱ�ȭ
    for (char *ptmp = tmp; ptmp <= tmp + strlen(tmp); ptmp++)     //���ڿ� ����
    {
        if (*ptmp == ' ' || *ptmp == 0) //����, ���Ṯ���� ���
        {
            char *new = NULL; //�ӽ� ���ڿ� �ּ� ����
            if ((new = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
                return -1;                   //���ڿ� �ּҿ� size��ŭ �����Ҵ��ϰ� ���н� ����
            strncpy(new, ptmp - size, size); //�ӽ� ���ڿ� �ּҿ� ���� �Է�
            *(new + size) = 0;               //������ �ּҿ� ���Ṯ�� ����

            *parr2++ = new; //���ڿ�2�� �ӽ� ���ڿ� �ּҸ� �ְ� �ּҰ� ����
            size = -1;      //���� ���� �Է��� ���� ������ ����
        }
        size++;
    }

    char **arr3 = NULL;                                           //��ġ�ϴ� ���ڸ� ������ arr3����
    int size3 = size2;                                            // size3�� �ʱⰪ�� �ִ� ������ size2�� ��´�.
    if ((arr3 = (char **)malloc(sizeof(char *) * size3)) == NULL) //�����ŭ �����Ҵ�
        return -1;                                                //���н� ����
    size = 0;                                                     //������ �ʱ�ȭ
    for (char **p = arr1; p < arr1 + size1; p++)                  //���ڿ�1 ����
    {
        for (char **q = arr1; q < arr1 + size1; q++)
        {
            if (p == q) // p�� q�� ������ ���� �����̹Ƿ� continue
                continue;

            char merge[101];   //��ġ�� ���� ���ڿ� ����
            strcpy(merge, *p); // p�ּ��� ���ڿ� ����
            strcat(merge, *q); // q�ּ��� ���ڿ� �ձ�

            for (char **find = arr2; find < arr2 + size2; find++) //���ڿ�2 ����
            {
                if (!strcmp(merge, *find)) //������ ���ڿ��� ���ڿ�2�� ���ڰ� ���� ���
                {
                    int found = 0;                                          //�ߺ� ���� ������ ���� ����
                    for (char **parr3 = arr3; parr3 < arr3 + size; parr3++) //���ڿ�3 ����
                    {
                        if (!strcmp(*parr3, merge)) //���ڿ�3���� merge������ ã�´�.
                        {
                            found = 1; //ã�� ��� found=1�� �ϰ� ����
                            break;
                        }
                    }
                    if (!found) //���ڿ��� ���� ���
                    {
                        *(arr3 + size) = (char *)malloc(sizeof(char) * (strlen(merge) + 1)); //���ڿ�3�� merge���ڿ��� ũ�� ��ŭ ���� �Ҵ�
                        strcpy(*(arr3 + size), merge);                                       //���ڿ�3�� ����
                        size++;                                                              //���ڿ�3�� ũ�� ����
                    }
                }
            }
        }
    }
    size3 = size;                                          //���ڿ�3�� ũ�Ⱑ ���������Ƿ� ������ �Է�
    arr3 = (char **)realloc(arr3, sizeof(char *) * size3); // size3�� ũ�⸸ŭ ���ڿ�3�� ũ�⸦ ������ ���ش�.

    for (char **p = arr3; p < arr3 + size3 - 1; p++) //���ڿ�3�� ���� ���ķ� ����
    {
        for (char **q = arr3; q < arr3 + size3 - (p - arr3) - 1; q++)
        {
            if (strlen(*q) < strlen(*(q + 1))) //���� ���ڰ� �� ���� ���� ����
            {
                char *tmp = *q;
                *q = *(q + 1);
                *(q + 1) = tmp;
            }
            else if (strlen(*q) == strlen(*(q + 1)) && strcmp(*q, *(q + 1)) > 0)
            { //���� ���ڿ� ���̰� ������ ������ �迭�� ���� ����
                char *tmp = *q;
                *q = *(q + 1);
                *(q + 1) = tmp;
            }
        }
    }
    for (char **parr3 = arr3; parr3 < arr3 + size3; parr3++) //���ĵ� ���ڿ�3 ���
        printf("%s\n", *parr3);

    for (int i = 0; i < size1; i++)
        free(arr1[i]); //���ڿ�1�� ���ڵ��� free
    free(arr1);        //���ڿ�1 free
    for (int i = 0; i < size2; i++)
        free(arr2[i]); //���ڿ�2 ���ڵ��� free
    free(arr2);        //���ڿ�2 free
    for (int i = 0; i < size3; i++)
        free(arr3[i]); //���ڿ�3 ���ڵ��� free
    free(arr3);        //���ڿ�3 free

    return 0;
}

/*
red orange yellow green blue purple
pink red redorange orangered yellow black bluegreen white purple
*/
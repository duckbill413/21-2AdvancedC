#include <stdio.h>

int main()
{
    char ch[101] = ""; //���ڸ� �Է¹��� ch�迭
    int size = 0;      //���� ����� ũ��
    for (char *pch = ch; pch < ch + 101; pch++)
    {
        scanf("%c", pch); //�����͸� �̿��Ͽ� ch�迭�� �� �Է�
        if (*pch == '#')  //#�� �ԷµǸ� ����
            break;
        size++; //#�� �ԷµǱ� �� ������ ũ�⸦ ���Ѵ�.
    }
    int max = 0;
    //������ ũ��� �ִ� ũ�⸦ ���� ���� ���� �� 0���� �ʱ�ȭ
    int cnt = 0;
    char word[101] = "";
    char *pword = word;

    for (char *pch = ch; pch <= ch + size; pch++)
    {
        if (*pch >= 'a' && *pch <= 'z')
        { //���ڰ� �ҹ����� ���
            // if (cnt == 0 && pch != ch) //cnt�� 0�̸� ó���� �ƴ� ���
            //     printf("\n");          //���ο� ������ �����̹Ƿ� ���� ���ش�.
            // printf("%c", *pch);        //�ҹ����� ��� ���
            // cnt++;                     //������ ���� ī��Ʈ
            *pword++ = *pch;
            cnt++;
        }
        else //�ҹ��ڰ� �ƴ� ���
        {
            if (pword != word)
            {
                for (pword = word; pword < word + cnt; pword++)
                {
                    printf("%c", *pword);
                }
                printf("\n");
                if (max < cnt) //max���� cnt�� ũ�� max = cnt
                    max = cnt;
                cnt = 0;
                pword = word;
            }
        }
    }
    printf("%d", max); //�ִ� ���ڱ��� ���
    return 0;
}
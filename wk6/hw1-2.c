#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student//�л� ����ü ����
{
    char name[10];//�л� �̸�
    char id[11];//�й�
    char score;//�������
};

int main()
{
    struct student st[5];//�л� ����ü

    for (int i = 0; i < 5; i++)//5���� �л� ������ �Է� �޴´�.
    {
        scanf("%s %s %c", st[i].name, st[i].id, &st[i].score);//�̸�, �й�, ���� �Է�
    }
    getchar();//scanf���� �����
    char name[10];//ã���� �ϴ� �̸� �Է�
    gets(name);//gets�� �̸� �Է�

    char year[5];//���г⵵�� �Է��� ����
    char score;//ã�� �л��� ����
    for (int i = 0; i < 5; i++)
    {
        if (!strcmp(name, st[i].name))//5���� �л��� ���Ͽ� ã�� �̸��� �ִٸ�
        {
            strncpy(year, st[i].id, 4);//year�� �й��� �� 4�ڸ��� ����
            score = st[i].score;//score�� ���� �Է�
        }
    }
    int found = 0;
    for (int i = 0; i < 5; i++)
    {
        if (!strncmp(year, st[i].id, 4) && st[i].score == score && strcmp(name, st[i].name))
        {//���г⵵�� ������ ���� �л��� ã�� ������ �����Ѵ�.
            printf(" %s", st[i].name);//ã�� �л��� �̸� ���
            found = 1;//ã�� �л��� ���� �ϹǷ� found =1
        }
    }
    if (!found)//���г⵵, ������ ���� �л��� ���� ���� ������
        printf("0");//0���

    printf("\n%d %d", atoi(year), atoi(year) % 131);//year�� ����ȭ �Ͽ� ����ϰ�, ����ȭ�� year�� 131�� ������ ���
    return 0;
}